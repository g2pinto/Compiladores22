%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include <vector>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                  i;	/* integer value */
  double               d;    /* float values */
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;

  l22::block_node      *block;
};

%token <i> tINTEGER
%token <s> tIDENTIFIER tSTRING
%token <d> tREAL
%token<expression> tNULLPTR;


//------------------------
%token tIF tTHEN tWHILE tDO tARROW
%token tWRITELN tWRITE tINPUT 
%token tOR  tAND tRETURN tAGAIN tSTOP tSIZEOF tDEFAULT tNOT
%token tVOID_TYPE tINT_TYPE tDOUBLE_TYPE tTEXT_TYPE
%token tPRINT tREAD tBEGIN tEND
%token tPUBLIC tFOREIGN tUSE tVAR

%nonassoc tIFX
%nonassoc tIF
%nonassoc tTHEN
%nonassoc tELIF 
%nonassoc tELSE

%right '='
%left tOR
%left tAND
%left tEQ tNE
%left tGE tLE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%right tUNARY
%nonassoc '~' 
%nonassoc '(' ')'




%type <lvalue> lval
%type <node> decl variableDec arg instruction iffalse file program 
%type <sequence> decls variableDecs instructions optionalInstruc optVariableDec args exprs 
%type <expression> expr
%type <type> data_type //types
%type <block> block
%type <s> string

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%
file       : /* empty */                  { compiler->ast($$ = new cdk::sequence_node(LINE)); }
          | decls                         { compiler->ast($$ = $1); }
          | optVariableDec program         { compiler->ast($$ = new cdk::sequence_node(LINE, $2, $1)); }
          ;

decls     : decl                                      { $$ = new cdk::sequence_node(LINE, $1); }
          | decls decl                                { $$ = new cdk::sequence_node(LINE, $2, $1); }
          ;

decl      : variableDec '\n'    	                     { $$ = $1; }
          //| funcDec     			                         { $$ = $1; }
          //| funcDef     			                         { $$ = $1; }
          ;

variableDec    : tPUBLIC data_type tIDENTIFIER  '\n'     { $$ = new l22::variable_declaration_node(LINE, 1,  $2, *$3, nullptr); }
               | tUSE data_type tIDENTIFIER '\n'          { $$ = new l22::variable_declaration_node(LINE, 2,  $2, *$3, nullptr); }
               | tFOREIGN data_type tIDENTIFIER '\n'      { $$ = new l22::variable_declaration_node(LINE, 3,  $2, *$3, nullptr); }
               | data_type  tIDENTIFIER '\n'               { $$ = new l22::variable_declaration_node(LINE, 0, $1, *$2, nullptr); }
               // with initial value
               | tPUBLIC data_type  tIDENTIFIER '=' expr '\n'      { $$ = new l22::variable_declaration_node(LINE, 1, $2, *$3, $5); }
               | tUSE data_type tIDENTIFIER '=' expr '\n'          { $$ = new l22::variable_declaration_node(LINE, 2,  $2, *$3, $5); }
               | tFOREIGN data_type tIDENTIFIER '=' expr '\n'      { $$ = new l22::variable_declaration_node(LINE, 3,  $2, *$3, $5); }
               | data_type  tIDENTIFIER  '=' expr '\n'             { $$ = new l22::variable_declaration_node(LINE, 0, $1, *$2, $4); }
               // with initial value and var
               | tPUBLIC tVAR  tIDENTIFIER '=' expr '\n'      { $$ = new l22::variable_declaration_node(LINE, 1, $5->type(), *$3, $5); }
               | tUSE tVAR tIDENTIFIER '=' expr '\n'          { $$ = new l22::variable_declaration_node(LINE, 2,  $5->type(), *$3, $5); }
               | tFOREIGN tVAR tIDENTIFIER '=' expr '\n'      { $$ = new l22::variable_declaration_node(LINE, 3,  $5->type(), *$3, $5); }
               | tVAR  tIDENTIFIER  '=' expr  '\n'            { $$ = new l22::variable_declaration_node(LINE, 0, $4->type(), *$2, $4); }
               ;

variableDecs       : variableDec                           { $$ = new cdk::sequence_node(LINE, $1);     }
                   | variableDec variableDecs              { $$ = new cdk::sequence_node(LINE, $1, $2); }
                   ;

optVariableDec     : /* empty */                               { $$ = nullptr; }
                   | variableDecs                              { $$ = $1; }
                   ;

data_type          : tTEXT_TYPE                              { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
                   | tINT_TYPE                                 { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT);     }
                   | tDOUBLE_TYPE                               { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
                   | data_type '<' data_type '>'                   { std::vector<std::shared_ptr<cdk::basic_type>> vec(1, $1);
                                                                 $$ = cdk::functional_type::create(vec, $3);   }
                   | '[' data_type ']'                       { $$ = cdk::reference_type::create(4, $2); }
                   ;
/*
void_type          : tVOID_TYPE                                { $$ = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
                    ;
*/
program	: tBEGIN block tEND { new l22::program_node(LINE, $2); }
		;


/*                   
funcDec            :     data_type  tIDENTIFIER '(' args ')'                  { $$ = new l22::function_declaration_node(LINE, 0,  $1, *$2, $4); delete $2; }
                   | data_type '*'  tIDENTIFIER '(' args ')'                  { $$ = new l22::function_declaration_node(LINE, 1,  $1, *$3, $5); delete $3; }
                   | data_type '?'  tIDENTIFIER '(' args ')'                  { $$ = new l22::function_declaration_node(LINE, 2,  $1, *$3, $5); delete $3; }
                   |     void_type  tIDENTIFIER '(' args ')'                  { $$ = new l22::function_declaration_node(LINE, 0, *$2, $4); delete $2; }
                   | void_type '*'  tIDENTIFIER '(' args ')'                  { $$ = new l22::function_declaration_node(LINE, 1, *$3, $5); delete $3; }
                   | void_type '?'  tIDENTIFIER '(' args ')'                  { $$ = new l22::function_declaration_node(LINE, 2, *$3, $5); delete $3; }
                   ;
*/
/*
funcDef            :     data_type  tIDENTIFIER '(' args ')' optDefault body       { $$ = new l22::function_definition_node(LINE, 0,  $1, *$2, $4, $6, $7); delete $2; }
                   | data_type '*'  tIDENTIFIER '(' args ')' optDefault body       { $$ = new l22::function_definition_node(LINE, 1,  $1, *$3, $5, $7, $8); delete $3; }
                   |     void_type  tIDENTIFIER '(' args ')' optDefault body       { $$ = new l22::function_definition_node(LINE, 0, *$2, $4, $6, $7); delete $2; }
                   | void_type '*'  tIDENTIFIER '(' args ')' optDefault body       { $$ = new l22::function_definition_node(LINE, 1, *$3, $5, $7, $8); delete $3; }
                   ;
*/                   

block             : '\n' optVariableDec '\n' optionalInstruc                 { $$ = new l22::block_node(LINE, $2, $4); }             
                  ;

iffalse        : tELSE block                                { $$ = $2; }
               | tELIF '(' expr ')' tTHEN block             { $$ = new l22::if_node(LINE, $3, $6); }
               | tELIF '(' expr ')' tTHEN block iffalse     { $$ = new l22::if_else_node(LINE, $3, $6, $7); }
               ;    

instruction         : tIF '(' expr ')' tTHEN block  '\n'                             { $$ = new l22::if_node(LINE, $3, $6); }
                    | tIF '(' expr ')' tTHEN block iffalse '\n'            { $$ = new l22::if_else_node(LINE, $3, $6, $7); }
                    | tWHILE '(' expr ')' tDO block '\n'        { $$ = new l22::while_node(LINE, $3, $6); }                
                    | expr '\n'                                                 { $$ = new l22::evaluation_node(LINE, $1); }
                    | tWRITE   exprs '\n'                                       { $$ = new l22::write_node(LINE, $2, false); }
                    | tWRITELN exprs '\n'                                       { $$ = new l22::write_node(LINE, $2, true); }
                    | tSTOP '\n'                                { $$ = new l22::stop_node(LINE);  }
                    | tAGAIN '\n'                               { $$ = new l22::again_node(LINE); }
                    | tRETURN '\n'                                                 { $$ = new l22::return_node(LINE); }
                    | block '\n'                                                   { $$ = $1; }
                    | expr '(' exprs ')'  '\n'                      { $$ = new l22::function_call_node(LINE, $1, $3);}
                    | expr '(' ')'                                  { $$ = new l22::function_call_node(LINE, $1);}
                    ;

instructions       : instruction                      { $$ = new cdk::sequence_node(LINE, $1);     }
                   | instructions instruction         { $$ = new cdk::sequence_node(LINE, $2, $1); }
                   ;

optionalInstruc    : /* empty */                     { $$ = new cdk::sequence_node(LINE); }
                   | instructions                     { $$ = $1; }
                   ;



  /*nao se tem que fazer uma */
expr               : tINTEGER                         { $$ = new cdk::integer_node(LINE, $1);}
                   | tREAL                            { $$ = new cdk::double_node(LINE, $1); }
                   | string                           { $$ = new cdk::string_node(LINE, $1); }
                   | tNULLPTR                         { $$ = new l22::null_pointer_node(LINE); }
                   /* LEFT VALUES */
                   | lval                             { $$ = new cdk::rvalue_node(LINE, $1); }
                   /* ARITHMETIC EXPRESSIONS */
                   | expr '+' expr	                  { $$ = new cdk::add_node(LINE, $1, $3); }
                   | expr '-' expr	                  { $$ = new cdk::sub_node(LINE, $1, $3); }
                   | expr '*' expr	                  { $$ = new cdk::mul_node(LINE, $1, $3); }
                   | expr '/' expr	                  { $$ = new cdk::div_node(LINE, $1, $3); }
                   | expr '%' expr	                  { $$ = new cdk::mod_node(LINE, $1, $3); }
                   /* UNARY EXPRESSION */
                   | '-' expr %prec tUNARY            { $$ = new cdk::neg_node(LINE, $2); }
                   | '+' expr %prec tUNARY            { $$ = $2; }
                   | '~' expr %prec tUNARY            { $$ = new cdk::not_node(LINE, $2); }
                   /* OTHER EXPRESSION */
                   //| tINPUT                              { $$ = new l22::read_node(LINE); }
                   | tSIZEOF '(' expr ')'             { $$ = new l22::size_of_node(LINE, $3); }
                   //| tIDENTIFIER '(' opt_exprs ')'    { $$ = new l22::function_call_node(LINE, *$1 , $3); delete $1; }
                   /* LOGICAL EXPRESSIONS */
                   | expr '<' expr	                  { $$ = new cdk::lt_node(LINE, $1, $3); }
                   | expr '>' expr	                  { $$ = new cdk::gt_node(LINE, $1, $3); }
                   | expr tGE expr	                  { $$ = new cdk::ge_node(LINE, $1, $3); }
                   | expr tLE expr                    { $$ = new cdk::le_node(LINE, $1, $3); }
                   | expr tNE expr	                  { $$ = new cdk::ne_node(LINE, $1, $3); }
                   | expr tEQ expr	                  { $$ = new cdk::eq_node(LINE, $1, $3); }
                   | expr tAND expr	                  { $$ = new cdk::and_node(LINE, $1, $3);}
                   | expr tOR expr	                  { $$ = new cdk::or_node(LINE, $1, $3); }
                   /* ASSIGNMENTS */
                   | lval '=' expr                    { $$ = new cdk::assignment_node(LINE, $1, $3); }
                   /* OTHER EXPRESSION */
                   | '(' expr ')'                     { $$ = $2; }
                   //| '[' expr ']'                     { $$ = new l22::alloc_node(LINE, $2); }
                   | lval '?'                         { $$ = new l22::address_of_node(LINE, $1);}
                   | '(' args ')' tARROW data_type ':' block  { $$ = new l22::fundef_expression_node(LINE, $2, $7, $5);}
                    ;
                   
args      : /* empty */        	                   { $$ = new cdk::sequence_node(LINE);  } 
          | arg                                       { $$ = new cdk::sequence_node(LINE, $1);     }
          | args ',' arg                              { $$ = new cdk::sequence_node(LINE, $3, $1); }
          ;

arg       : data_type tIDENTIFIER                     { $$ = new l22::variable_declaration_node(LINE, 0, $1, *$2, nullptr); }
          ;
exprs              : expr                             { $$ = new cdk::sequence_node(LINE, $1);     }
                   | exprs ',' expr                   { $$ = new cdk::sequence_node(LINE, $3, $1); }
                   ;
/*
opt_exprs          : /* empty                      { $$ = new cdk::sequence_node(LINE); }
                   | exprs                            { $$ = $1; }
                   ;
*/

string             : tSTRING                          { $$ = $1; }
                   | string tSTRING                   { $$ = new std::string(*$1 + *$2); delete $1; delete $2; }
                   ;
                   
lval               : tIDENTIFIER                                  { $$ = new cdk::variable_node(LINE, *$1); delete $1; }
                   //| lval '[' expr ']'                            { $$ = new l22::pointer_node(LINE, new cdk::rvalue_node(LINE, $1), $3); }
                   //| '(' expr ')' '[' expr ']'                    { $$ = new l22::pointer_node(LINE, $2, $5); }
                   //| tIDENTIFIER '(' opt_exprs ')' '[' expr ']'   { $$ = new l22::pointer_node(LINE, new l22::function_call_node(LINE, *$1, $3), $6); }
                   ;

%%
