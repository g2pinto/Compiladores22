%option c++ prefix="l22_scanner_" outfile="l22_scanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <sstream>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "l22_parser.tab.h"

static bool restart_functions = false;

static int lLevelsToPop = 0, lIndex = 0;
static std::vector<int> indents;   // known indentation levels
static std::vector<int> deferred;  // deferred tokens

// output stream for building string literals
static std::ostringstream strlit;

inline bool valid(int indent) {
    lLevelsToPop = lIndex = -1;
    bool indentOk = false;
    for (size_t ix = 0; ix < indents.size(); ix++) {
        if (indent == indents[ix]) {
            lLevelsToPop = indents.size() - ix - 1;
            lIndex = ix;
            indentOk = true;
        }
    }
    return indentOk;
}

// don't change this
#define yyerror LexerError
%}
SPACE        [ \t\r\n]

%x X_STRING X_NEWLINE X_COMMENT X_WHILE X_IF
%%
  yydebug=1; set_debug(1);

">="                   return tGE; 
"<="                   return tLE; 
"=="                   return tEQ; 
"!="                   return tNE; 

"and"                  return tAND;
"or"                   return tOR;
"not"                  return tNOT;

"while"                {yy_push_state(X_WHILE); return tWHILE;}
<X_WHILE>"do:"         {yy_pop_state(); return tDO;} 



"if"                   {yy_push_state(X_IF); return tIF;} 
<X_IF>"then:"          return tTHEN;
<X_IF>"elif"           return tELIF;
<X_IF>"else:"          {yy_pop_state(); return tELSE;}

"begin"                return tBEGIN; 
"end"                  return tEND; 

"stop"                 return tSTOP;
"again"                return tAGAIN;
"return"               return tRETURN;

"write"                return tWRITE;
"writeln"              return tWRITELN;

"void"                 return tVOID_TYPE;
"int"                  return tINT_TYPE;
"double"               return tDOUBLE_TYPE;
"text"                 return tTEXT_TYPE;

"sizeof"               return tSIZEOF;

"input"                return tINPUT;
"null"                 return tNULLPTR;

"use"                  return tUSE;
"foreign"              return tFOREIGN;
"public"               return tPUBLIC;
"var"                  return tVAR;

"->"                   return tARROW;

  /* ====================================================================== */
  /* ====[                      2.2 - INDENTATION                     ]==== */
  /* ====================================================================== */

\n                   yy_push_state(X_NEWLINE); /* delay decision */

<X_NEWLINE>^{SPACE}+  {
    yy_pop_state();

    if (valid(yyleng)) {
          std::cerr << "CASE 1" << std::endl;
          if (lLevelsToPop == 0) {
            // at the same level: ignore index
            // do not return tINDENT;
            std::cerr << "CASE 1a (levels to pop = 0)" << std::endl;
            return '\n';
          }
          else {
            // nothing is done here: the scanner will ignore the input while levels > 0
            // and send block-end tokens to the parser
            std::cerr << "CASE 1b (levels to pop = " << lLevelsToPop << ")" << std::endl;
            // at least one has to be returned here...
            if (lLevelsToPop > 0) {
              std::cerr << "POPPING LEVELS (" << lLevelsToPop << ")" << std::endl;
              lLevelsToPop--;
              indents.pop_back();
              return '\n';
            }
          }
    }
    else if (indents.size() == 0) {
          // first block to open
          std::cerr << "CASE 2" << std::endl;
          indents.push_back(yyleng);
          return '\n';
    }
    else if (yyleng > indents.back()) {
          // this is like the one before, but not the first
          std::cerr << "CASE 3" << std::endl;
          indents.push_back(yyleng);
          return '\n'; 
    }
    else {
          // something wrong: bad indent: communicate to user
          std::cerr << "CASE 4" << std::endl;
          std::cerr << "bad indent at line " << yylineno;
    }

}

<X_NEWLINE>\n      ; /* ignore successive newline chars */
<X_NEWLINE>.       {
                      // in this case, we have a new function starting
                      // first, return whatever we are seeing to the input
                      yyless(0);
                      yy_pop_state();
                      if (indents.size() > 0) {
                        std::cerr << "should restart " << indents.size() << " functions at " << yylineno << std::endl;
                        indents.pop_back();
                        if (indents.size() > 0) { restart_functions = true; }
                        return '\n';
                      }
                      else return '\n'; // top-level declarations
                    }


";".*\n                 ; /* ignore comments */

"(*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"(*"        yy_push_state(X_COMMENT);
<X_COMMENT>"*)"        yy_pop_state();
<X_COMMENT>.|\n        ; /* ignore content */



0[0-6]+              yylval.i = strtoul(yytext, NULL, 7); return tINTEGER;
0[0-9]+              yyerror("Invalid base 7 number.");

0|[1-9][0-9]*        yylval.i = strtoul(yytext, NULL, 10); return tINTEGER;


"."[0-9]+                             { try {
                                          double d = std::stod(yytext, NULL);
                                          if(int(d) == d){
                                            yylval.i = int(d); return tINTEGER;
                                          }
                                          yylval.d = d; return tREAL;
                                        } catch (std::out_of_range& e) { yyerror("Real out of range.");}
                                      }

[0-9]+"."                             { try { 
                                          double d = std::stod(yytext, NULL);
                                          if(int(d) == d){
                                            yylval.i = int(d); return tINTEGER;
                                          }
                                          yylval.d = d; return tREAL;
                                        } catch (std::out_of_range& e) { yyerror("Real out of range."); }
                                      } 

[0-9]+"."[0-9]+                       { try{
                                          double d = std::stod(yytext, NULL);
                                          if(int(d) == d){
                                            yylval.i = int(d); return tINTEGER;
                                          }
                                          yylval.d = d; return tREAL;
                                        } catch (std::out_of_range& e) { yyerror("Real out range."); }
                                      }

[0-9]+("."[0-9]+)?[Ee][-+]?[0-9]+     { try { 
                                          double d = std::stod(yytext, NULL);
                                          if(int(d) == d){
                                            yylval.i = int(d); return tINTEGER;
                                          }
                                          yylval.d = d; return tREAL;
                                        } catch(std::out_of_range& e) { yyerror("Real out of range.");}
                                      }


[A-Za-z][A-Za-z0-9_]*  yylval.s = new std::string(yytext); return tIDENTIFIER;

\"                      yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\"            yy_pop_state(); return tSTRING;
<X_STRING>\\\"          *yylval.s += yytext + 1;
<X_STRING>.             *yylval.s += yytext;
<X_STRING>\0            yy_pop_state(); return tSTRING;
<X_STRING>\\n           yyerror("newline in string");


[-()<>=+*/%]       return *yytext;

[ \t\n]+               ; /* ignore whitespace */

.                      yyerror("Unknown character");

%%
