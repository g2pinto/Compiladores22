/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "l22_parser.y"

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

#line 85 "l22_parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_L22_PARSER_TAB_H_INCLUDED
# define YY_YY_L22_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tINTEGER = 258,
    tIDENTIFIER = 259,
    tSTRING = 260,
    tREAL = 261,
    tNULLPTR = 262,
    tIF = 263,
    tTHEN = 264,
    tWHILE = 265,
    tDO = 266,
    tARROW = 267,
    tWRITELN = 268,
    tWRITE = 269,
    tINPUT = 270,
    tOR = 271,
    tAND = 272,
    tRETURN = 273,
    tAGAIN = 274,
    tSTOP = 275,
    tSIZEOF = 276,
    tDEFAULT = 277,
    tNOT = 278,
    tVOID_TYPE = 279,
    tINT_TYPE = 280,
    tDOUBLE_TYPE = 281,
    tTEXT_TYPE = 282,
    tPRINT = 283,
    tREAD = 284,
    tBEGIN = 285,
    tEND = 286,
    tPUBLIC = 287,
    tFOREIGN = 288,
    tUSE = 289,
    tVAR = 290,
    tIFX = 291,
    tELIF = 292,
    tELSE = 293,
    tEQ = 294,
    tNE = 295,
    tGE = 296,
    tLE = 297,
    tUNARY = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "l22_parser.y"

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

#line 202 "l22_parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::shared_ptr<cdk::compiler> compiler);

#endif /* !YY_YY_L22_PARSER_TAB_H_INCLUDED  */

/* Second part of user prologue.  */
#line 81 "l22_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 222 "l22_parser.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   523

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

#define YYUNDEFTOK  2
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      55,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    50,     2,     2,
      53,    54,    48,    46,    60,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,     2,
      45,    39,    44,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    52,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    40,    41,    42,    43,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    85,    85,    86,    87,    90,    91,    94,    99,   100,
     101,   102,   104,   105,   106,   107,   109,   110,   111,   112,
     115,   116,   119,   120,   123,   124,   125,   126,   128,   134,
     155,   158,   159,   160,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   177,   178,   181,   182,
     188,   189,   190,   191,   193,   195,   196,   197,   198,   199,
     201,   202,   203,   206,   209,   210,   211,   212,   213,   214,
     215,   216,   218,   220,   222,   223,   226,   227,   228,   231,
     233,   234,   242,   243,   246
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tINTEGER", "tIDENTIFIER", "tSTRING",
  "tREAL", "tNULLPTR", "tIF", "tTHEN", "tWHILE", "tDO", "tARROW",
  "tWRITELN", "tWRITE", "tINPUT", "tOR", "tAND", "tRETURN", "tAGAIN",
  "tSTOP", "tSIZEOF", "tDEFAULT", "tNOT", "tVOID_TYPE", "tINT_TYPE",
  "tDOUBLE_TYPE", "tTEXT_TYPE", "tPRINT", "tREAD", "tBEGIN", "tEND",
  "tPUBLIC", "tFOREIGN", "tUSE", "tVAR", "tIFX", "tELIF", "tELSE", "'='",
  "tEQ", "tNE", "tGE", "tLE", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "tUNARY", "'~'", "'('", "')'", "'\\n'", "'['", "']'", "'?'",
  "':'", "','", "$accept", "file", "decls", "decl", "variableDec",
  "variableDecs", "optVariableDec", "data_type", "program", "block",
  "iffalse", "instruction", "instructions", "optionalInstruc", "expr",
  "args", "arg", "exprs", "string", "lval", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    61,
     294,   295,   296,   297,    62,    60,    43,    45,    42,    47,
      37,   298,   126,    40,    41,    10,    91,    93,    63,    58,
      44
};
# endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-23)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      48,  -127,  -127,  -127,   106,   152,   180,     7,     6,    63,
     467,  -127,   148,  -127,    35,    -3,    80,    -1,    82,     0,
     109,     1,    76,    50,  -127,  -127,    68,  -127,   467,  -127,
      83,  -127,   -18,     6,    95,   -16,    96,    33,    98,    66,
     165,  -127,   467,   124,   165,  -127,    74,   165,   165,  -127,
     165,   165,  -127,   165,   165,  -127,  -127,  -127,  -127,  -127,
    -127,   108,   165,   165,   165,    64,   197,   158,   -22,   121,
    -127,   214,  -127,   232,   249,   267,   284,   302,   319,   165,
    -127,  -127,  -127,     3,   337,   -25,  -127,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
    -127,  -127,   165,  -127,   146,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,   354,  -127,  -127,   172,     6,   441,   463,   472,
     472,    79,    79,    79,    79,   140,   140,  -127,  -127,  -127,
     424,   132,   138,   165,   165,   139,   142,   145,   147,  -127,
     146,  -127,   179,  -127,     6,  -127,   165,   165,   424,   -17,
      46,  -127,  -127,  -127,  -127,  -127,    93,  -127,   -31,   372,
     389,  -127,   165,  -127,  -127,   -20,    83,   200,   199,   424,
     161,  -127,    83,    83,  -127,    39,   178,   182,    83,  -127,
     195,  -127,   165,  -127,  -127,   407,   242,    83,    55,  -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    25,    26,    24,     0,     0,     0,     0,     0,     0,
       3,     5,    20,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     6,     0,     7,    20,    21,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    22,     0,     0,    11,     0,     0,     0,     8,
       0,     0,    10,     0,     0,     9,    50,    84,    82,    51,
      53,     0,     0,     0,     0,    76,     0,    52,    54,     0,
      29,     0,    27,     0,     0,     0,     0,     0,     0,     0,
      61,    60,    62,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    83,     0,    74,    48,    15,    16,    12,    18,    14,
      17,    13,     0,    79,    73,     0,     0,    71,    70,    69,
      68,    66,    67,    65,    64,    55,    56,    57,    58,    59,
      72,     0,     0,     0,     0,     0,     0,     0,     0,    46,
      49,    30,     0,    63,     0,    78,     0,     0,    80,     0,
       0,    42,    41,    40,    43,    47,     0,    37,     0,     0,
       0,    39,     0,    38,    45,     0,     0,     0,     0,    81,
       0,    75,     0,     0,    44,     0,     0,     0,     0,    34,
       0,    36,     0,    31,    35,     0,     0,     0,    32,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,   243,   112,    75,   225,    14,  -127,   -30,
      97,   128,  -127,  -127,   -38,  -127,   154,  -126,  -127,  -127
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    28,    13,    14,    15,    31,   138,
     180,   139,   140,   141,   148,    85,    86,   149,    67,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    32,    66,    35,    37,    39,    71,   113,   150,    73,
      74,    22,    75,    76,    33,    77,    78,   102,    17,    19,
      21,    44,    23,    48,    80,    81,    82,    84,   166,   115,
     165,     1,     2,     3,   170,   116,   103,    45,   161,    49,
     162,   112,    33,   162,    33,    33,    33,    46,    33,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     8,    24,   130,    30,   142,    56,    57,    58,
      59,    60,    51,     1,     2,     3,   177,   178,   -22,    83,
       4,     5,     6,     7,    34,    61,    36,    29,    52,     1,
       2,     3,   177,   178,   179,    33,    56,    57,    58,    59,
      60,   163,   142,    29,     8,    54,   162,    41,   159,   160,
      62,    63,    12,    38,    61,    40,    64,    65,    72,    33,
       8,    55,    26,    27,   169,    95,    96,    97,    98,    99,
      83,     1,     2,     3,    47,    50,   171,    53,    42,    62,
      63,    16,   175,   176,   185,    64,    65,   164,   183,    56,
      57,    58,    59,    60,   131,    70,   132,   188,   158,   133,
     134,    79,     8,   101,   135,   136,   137,    61,    56,    57,
      58,    59,    60,     1,     2,     3,   104,     1,     2,     3,
       4,     5,     6,     7,   144,   146,    61,    18,    97,    98,
      99,   147,    62,    63,   151,    87,    88,   152,    64,    65,
     153,    42,   154,    27,     8,     1,     2,     3,     8,   172,
     173,    62,    63,    87,    88,    20,   174,    64,    65,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      87,    88,   156,   181,   157,   182,     8,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    87,    88,
     184,   187,   100,    25,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    87,    88,    69,   155,   105,
     145,     0,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    87,    88,   189,     0,   106,     0,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      87,    88,     0,     0,   107,     0,     0,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    87,    88,
       0,     0,   108,     0,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    87,    88,     0,     0,   109,
       0,     0,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    87,    88,     0,     0,   110,     0,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      87,    88,     0,     0,   111,     0,     0,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    87,    88,
       0,   114,     0,     0,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    87,    88,     0,   143,     0,
       0,     0,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    87,    88,     0,   167,     0,     0,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      87,    88,     0,   168,     0,     0,     0,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    88,     0,
       0,   186,     0,     0,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,     1,     2,     3,     0,     0,     0,     0,     4,
       5,     6,     7,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     8
};

static const yytype_int16 yycheck[] =
{
      30,     4,    40,     4,     4,     4,    44,     4,   134,    47,
      48,     4,    50,    51,    45,    53,    54,    39,     4,     5,
       6,    39,     8,    39,    62,    63,    64,    65,    59,    54,
     156,    25,    26,    27,    54,    60,    58,    55,    55,    55,
      60,    79,    45,    60,    45,    45,    45,    33,    45,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,    56,     0,   102,    30,   104,     3,     4,     5,
       6,     7,    39,    25,    26,    27,    37,    38,    30,    65,
      32,    33,    34,    35,     4,    21,     4,    12,    55,    25,
      26,    27,    37,    38,    55,    45,     3,     4,     5,     6,
       7,    55,   140,    28,    56,    39,    60,    57,   146,   147,
      46,    47,     0,     4,    21,    39,    52,    53,    44,    45,
      56,    55,    10,    55,   162,    46,    47,    48,    49,    50,
     116,    25,    26,    27,    39,    39,   166,    39,    55,    46,
      47,    35,   172,   173,   182,    52,    53,    54,   178,     3,
       4,     5,     6,     7,     8,    31,    10,   187,   144,    13,
      14,    53,    56,     5,    18,    19,    20,    21,     3,     4,
       5,     6,     7,    25,    26,    27,    55,    25,    26,    27,
      32,    33,    34,    35,    12,    53,    21,    35,    48,    49,
      50,    53,    46,    47,    55,    16,    17,    55,    52,    53,
      55,    55,    55,    55,    56,    25,    26,    27,    56,     9,
      11,    46,    47,    16,    17,    35,    55,    52,    53,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      16,    17,    53,    55,    55,    53,    56,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    16,    17,
      55,     9,    55,    10,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    16,    17,    42,   140,    55,
     116,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    16,    17,   188,    -1,    55,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      16,    17,    -1,    -1,    55,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    16,    17,
      -1,    -1,    55,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    16,    17,    -1,    -1,    55,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    16,    17,    -1,    -1,    55,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      16,    17,    -1,    -1,    55,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    16,    17,
      -1,    54,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    16,    17,    -1,    54,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    16,    17,    -1,    54,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      16,    17,    -1,    54,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    17,    -1,
      -1,    54,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    25,    26,    27,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    26,    27,    32,    33,    34,    35,    56,    62,
      63,    64,    65,    66,    67,    68,    35,    68,    35,    68,
      35,    68,     4,    68,     0,    64,    65,    55,    65,    66,
      30,    69,     4,    45,     4,     4,     4,     4,     4,     4,
      39,    57,    55,    70,    39,    55,    68,    39,    39,    55,
      39,    39,    55,    39,    39,    55,     3,     4,     5,     6,
       7,    21,    46,    47,    52,    53,    75,    79,    80,    67,
      31,    75,    44,    75,    75,    75,    75,    75,    75,    53,
      75,    75,    75,    68,    75,    76,    77,    16,    17,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      55,     5,    39,    58,    55,    55,    55,    55,    55,    55,
      55,    55,    75,     4,    54,    54,    60,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,     8,    10,    13,    14,    18,    19,    20,    70,    72,
      73,    74,    75,    54,    12,    77,    53,    53,    75,    78,
      78,    55,    55,    55,    55,    72,    53,    55,    68,    75,
      75,    55,    60,    55,    54,    78,    59,    54,    54,    75,
      54,    70,     9,    11,    55,    70,    70,    37,    38,    55,
      71,    55,    53,    70,    55,    75,    54,     9,    70,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    62,    63,    63,    64,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      66,    66,    67,    67,    68,    68,    68,    68,    68,    69,
      70,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    77,
      78,    78,    79,    79,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     2,     1,     2,     2,     4,     4,
       4,     3,     6,     6,     6,     5,     6,     6,     6,     5,
       1,     2,     0,     1,     1,     1,     1,     4,     3,     3,
       4,     2,     6,     7,     7,     8,     7,     2,     3,     3,
       2,     2,     2,     2,     5,     3,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       2,     2,     2,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     7,     0,     1,     3,     2,
       1,     3,     1,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (compiler, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (compiler);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, compiler);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, std::shared_ptr<cdk::compiler> compiler)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYUSE (yyvaluep);
  YYUSE (compiler);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (std::shared_ptr<cdk::compiler> compiler)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 85 "l22_parser.y"
                                          { compiler->ast((yyval.node) = new cdk::sequence_node(LINE)); }
#line 1576 "l22_parser.tab.c"
    break;

  case 3:
#line 86 "l22_parser.y"
                                          { compiler->ast((yyval.node) = (yyvsp[0].sequence)); }
#line 1582 "l22_parser.tab.c"
    break;

  case 4:
#line 87 "l22_parser.y"
                                           { compiler->ast((yyval.node) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence))); }
#line 1588 "l22_parser.tab.c"
    break;

  case 5:
#line 90 "l22_parser.y"
                                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1594 "l22_parser.tab.c"
    break;

  case 6:
#line 91 "l22_parser.y"
                                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1600 "l22_parser.tab.c"
    break;

  case 7:
#line 94 "l22_parser.y"
                                                             { (yyval.node) = (yyvsp[-1].node); }
#line 1606 "l22_parser.tab.c"
    break;

  case 8:
#line 99 "l22_parser.y"
                                                         { (yyval.node) = new l22::variable_declaration_node(LINE, 1,  (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); }
#line 1612 "l22_parser.tab.c"
    break;

  case 9:
#line 100 "l22_parser.y"
                                                          { (yyval.node) = new l22::variable_declaration_node(LINE, 2,  (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); }
#line 1618 "l22_parser.tab.c"
    break;

  case 10:
#line 101 "l22_parser.y"
                                                          { (yyval.node) = new l22::variable_declaration_node(LINE, 3,  (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); }
#line 1624 "l22_parser.tab.c"
    break;

  case 11:
#line 102 "l22_parser.y"
                                                           { (yyval.node) = new l22::variable_declaration_node(LINE, 0, (yyvsp[-2].type), *(yyvsp[-1].s), nullptr); }
#line 1630 "l22_parser.tab.c"
    break;

  case 12:
#line 104 "l22_parser.y"
                                                                   { (yyval.node) = new l22::variable_declaration_node(LINE, 1, (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].expression)); }
#line 1636 "l22_parser.tab.c"
    break;

  case 13:
#line 105 "l22_parser.y"
                                                                   { (yyval.node) = new l22::variable_declaration_node(LINE, 2,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].expression)); }
#line 1642 "l22_parser.tab.c"
    break;

  case 14:
#line 106 "l22_parser.y"
                                                                   { (yyval.node) = new l22::variable_declaration_node(LINE, 3,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].expression)); }
#line 1648 "l22_parser.tab.c"
    break;

  case 15:
#line 107 "l22_parser.y"
                                                                   { (yyval.node) = new l22::variable_declaration_node(LINE, 0, (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].expression)); }
#line 1654 "l22_parser.tab.c"
    break;

  case 16:
#line 109 "l22_parser.y"
                                                              { (yyval.node) = new l22::variable_declaration_node(LINE, 1, (yyvsp[-1].expression)->type(), *(yyvsp[-3].s), (yyvsp[-1].expression)); }
#line 1660 "l22_parser.tab.c"
    break;

  case 17:
#line 110 "l22_parser.y"
                                                              { (yyval.node) = new l22::variable_declaration_node(LINE, 2,  (yyvsp[-1].expression)->type(), *(yyvsp[-3].s), (yyvsp[-1].expression)); }
#line 1666 "l22_parser.tab.c"
    break;

  case 18:
#line 111 "l22_parser.y"
                                                              { (yyval.node) = new l22::variable_declaration_node(LINE, 3,  (yyvsp[-1].expression)->type(), *(yyvsp[-3].s), (yyvsp[-1].expression)); }
#line 1672 "l22_parser.tab.c"
    break;

  case 19:
#line 112 "l22_parser.y"
                                                              { (yyval.node) = new l22::variable_declaration_node(LINE, 0, (yyvsp[-1].expression)->type(), *(yyvsp[-3].s), (yyvsp[-1].expression)); }
#line 1678 "l22_parser.tab.c"
    break;

  case 20:
#line 115 "l22_parser.y"
                                                           { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1684 "l22_parser.tab.c"
    break;

  case 21:
#line 116 "l22_parser.y"
                                                           { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[0].sequence)); }
#line 1690 "l22_parser.tab.c"
    break;

  case 22:
#line 119 "l22_parser.y"
                                                               { (yyval.sequence) = nullptr; }
#line 1696 "l22_parser.tab.c"
    break;

  case 23:
#line 120 "l22_parser.y"
                                                               { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1702 "l22_parser.tab.c"
    break;

  case 24:
#line 123 "l22_parser.y"
                                                             { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
#line 1708 "l22_parser.tab.c"
    break;

  case 25:
#line 124 "l22_parser.y"
                                                               { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT);     }
#line 1714 "l22_parser.tab.c"
    break;

  case 26:
#line 125 "l22_parser.y"
                                                                { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
#line 1720 "l22_parser.tab.c"
    break;

  case 27:
#line 126 "l22_parser.y"
                                                                   { std::vector<std::shared_ptr<cdk::basic_type>> vec(1, (yyvsp[-3].type));
                                                                 (yyval.type) = cdk::functional_type::create(vec, (yyvsp[-1].type));   }
#line 1727 "l22_parser.tab.c"
    break;

  case 28:
#line 128 "l22_parser.y"
                                                             { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1733 "l22_parser.tab.c"
    break;

  case 29:
#line 134 "l22_parser.y"
                            { new l22::program_node(LINE, (yyvsp[-1].block)); }
#line 1739 "l22_parser.tab.c"
    break;

  case 30:
#line 155 "l22_parser.y"
                                                                             { (yyval.block) = new l22::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[0].sequence)); }
#line 1745 "l22_parser.tab.c"
    break;

  case 31:
#line 158 "l22_parser.y"
                                                            { (yyval.node) = (yyvsp[0].block); }
#line 1751 "l22_parser.tab.c"
    break;

  case 32:
#line 159 "l22_parser.y"
                                                            { (yyval.node) = new l22::if_node(LINE, (yyvsp[-3].expression), (yyvsp[0].block)); }
#line 1757 "l22_parser.tab.c"
    break;

  case 33:
#line 160 "l22_parser.y"
                                                            { (yyval.node) = new l22::if_else_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].block), (yyvsp[0].node)); }
#line 1763 "l22_parser.tab.c"
    break;

  case 34:
#line 163 "l22_parser.y"
                                                                                     { (yyval.node) = new l22::if_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].block)); }
#line 1769 "l22_parser.tab.c"
    break;

  case 35:
#line 164 "l22_parser.y"
                                                                           { (yyval.node) = new l22::if_else_node(LINE, (yyvsp[-5].expression), (yyvsp[-2].block), (yyvsp[-1].node)); }
#line 1775 "l22_parser.tab.c"
    break;

  case 36:
#line 165 "l22_parser.y"
                                                                { (yyval.node) = new l22::while_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].block)); }
#line 1781 "l22_parser.tab.c"
    break;

  case 37:
#line 166 "l22_parser.y"
                                                                                { (yyval.node) = new l22::evaluation_node(LINE, (yyvsp[-1].expression)); }
#line 1787 "l22_parser.tab.c"
    break;

  case 38:
#line 167 "l22_parser.y"
                                                                                { (yyval.node) = new l22::write_node(LINE, (yyvsp[-1].sequence), false); }
#line 1793 "l22_parser.tab.c"
    break;

  case 39:
#line 168 "l22_parser.y"
                                                                                { (yyval.node) = new l22::write_node(LINE, (yyvsp[-1].sequence), true); }
#line 1799 "l22_parser.tab.c"
    break;

  case 40:
#line 169 "l22_parser.y"
                                                                { (yyval.node) = new l22::stop_node(LINE);  }
#line 1805 "l22_parser.tab.c"
    break;

  case 41:
#line 170 "l22_parser.y"
                                                                { (yyval.node) = new l22::again_node(LINE); }
#line 1811 "l22_parser.tab.c"
    break;

  case 42:
#line 171 "l22_parser.y"
                                                                                   { (yyval.node) = new l22::return_node(LINE); }
#line 1817 "l22_parser.tab.c"
    break;

  case 43:
#line 172 "l22_parser.y"
                                                                                   { (yyval.node) = (yyvsp[-1].block); }
#line 1823 "l22_parser.tab.c"
    break;

  case 44:
#line 173 "l22_parser.y"
                                                                    { (yyval.node) = new l22::function_call_node(LINE, (yyvsp[-4].expression), (yyvsp[-2].sequence));}
#line 1829 "l22_parser.tab.c"
    break;

  case 45:
#line 174 "l22_parser.y"
                                                                    { (yyval.node) = new l22::function_call_node(LINE, (yyvsp[-2].expression));}
#line 1835 "l22_parser.tab.c"
    break;

  case 46:
#line 177 "l22_parser.y"
                                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1841 "l22_parser.tab.c"
    break;

  case 47:
#line 178 "l22_parser.y"
                                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1847 "l22_parser.tab.c"
    break;

  case 48:
#line 181 "l22_parser.y"
                                                     { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1853 "l22_parser.tab.c"
    break;

  case 49:
#line 182 "l22_parser.y"
                                                      { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1859 "l22_parser.tab.c"
    break;

  case 50:
#line 188 "l22_parser.y"
                                                      { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i));}
#line 1865 "l22_parser.tab.c"
    break;

  case 51:
#line 189 "l22_parser.y"
                                                      { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 1871 "l22_parser.tab.c"
    break;

  case 52:
#line 190 "l22_parser.y"
                                                      { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 1877 "l22_parser.tab.c"
    break;

  case 53:
#line 191 "l22_parser.y"
                                                      { (yyval.expression) = new l22::null_pointer_node(LINE); }
#line 1883 "l22_parser.tab.c"
    break;

  case 54:
#line 193 "l22_parser.y"
                                                      { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 1889 "l22_parser.tab.c"
    break;

  case 55:
#line 195 "l22_parser.y"
                                                          { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1895 "l22_parser.tab.c"
    break;

  case 56:
#line 196 "l22_parser.y"
                                                          { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1901 "l22_parser.tab.c"
    break;

  case 57:
#line 197 "l22_parser.y"
                                                          { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1907 "l22_parser.tab.c"
    break;

  case 58:
#line 198 "l22_parser.y"
                                                          { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1913 "l22_parser.tab.c"
    break;

  case 59:
#line 199 "l22_parser.y"
                                                          { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1919 "l22_parser.tab.c"
    break;

  case 60:
#line 201 "l22_parser.y"
                                                      { (yyval.expression) = new cdk::neg_node(LINE, (yyvsp[0].expression)); }
#line 1925 "l22_parser.tab.c"
    break;

  case 61:
#line 202 "l22_parser.y"
                                                      { (yyval.expression) = (yyvsp[0].expression); }
#line 1931 "l22_parser.tab.c"
    break;

  case 62:
#line 203 "l22_parser.y"
                                                      { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression)); }
#line 1937 "l22_parser.tab.c"
    break;

  case 63:
#line 206 "l22_parser.y"
                                                      { (yyval.expression) = new l22::size_of_node(LINE, (yyvsp[-1].expression)); }
#line 1943 "l22_parser.tab.c"
    break;

  case 64:
#line 209 "l22_parser.y"
                                                          { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1949 "l22_parser.tab.c"
    break;

  case 65:
#line 210 "l22_parser.y"
                                                          { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1955 "l22_parser.tab.c"
    break;

  case 66:
#line 211 "l22_parser.y"
                                                          { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1961 "l22_parser.tab.c"
    break;

  case 67:
#line 212 "l22_parser.y"
                                                      { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1967 "l22_parser.tab.c"
    break;

  case 68:
#line 213 "l22_parser.y"
                                                          { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1973 "l22_parser.tab.c"
    break;

  case 69:
#line 214 "l22_parser.y"
                                                          { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1979 "l22_parser.tab.c"
    break;

  case 70:
#line 215 "l22_parser.y"
                                                          { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1985 "l22_parser.tab.c"
    break;

  case 71:
#line 216 "l22_parser.y"
                                                          { (yyval.expression) = new cdk::or_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1991 "l22_parser.tab.c"
    break;

  case 72:
#line 218 "l22_parser.y"
                                                      { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression)); }
#line 1997 "l22_parser.tab.c"
    break;

  case 73:
#line 220 "l22_parser.y"
                                                      { (yyval.expression) = (yyvsp[-1].expression); }
#line 2003 "l22_parser.tab.c"
    break;

  case 74:
#line 222 "l22_parser.y"
                                                      { (yyval.expression) = new l22::address_of_node(LINE, (yyvsp[-1].lvalue));}
#line 2009 "l22_parser.tab.c"
    break;

  case 75:
#line 223 "l22_parser.y"
                                                              { (yyval.expression) = new l22::fundef_expression_node(LINE, (yyvsp[-5].sequence), (yyvsp[0].block), (yyvsp[-2].type));}
#line 2015 "l22_parser.tab.c"
    break;

  case 76:
#line 226 "l22_parser.y"
                                                   { (yyval.sequence) = new cdk::sequence_node(LINE);  }
#line 2021 "l22_parser.tab.c"
    break;

  case 77:
#line 227 "l22_parser.y"
                                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 2027 "l22_parser.tab.c"
    break;

  case 78:
#line 228 "l22_parser.y"
                                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 2033 "l22_parser.tab.c"
    break;

  case 79:
#line 231 "l22_parser.y"
                                                      { (yyval.node) = new l22::variable_declaration_node(LINE, 0, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 2039 "l22_parser.tab.c"
    break;

  case 80:
#line 233 "l22_parser.y"
                                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression));     }
#line 2045 "l22_parser.tab.c"
    break;

  case 81:
#line 234 "l22_parser.y"
                                                      { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 2051 "l22_parser.tab.c"
    break;

  case 82:
#line 242 "l22_parser.y"
                                                      { (yyval.s) = (yyvsp[0].s); }
#line 2057 "l22_parser.tab.c"
    break;

  case 83:
#line 243 "l22_parser.y"
                                                      { (yyval.s) = new std::string(*(yyvsp[-1].s) + *(yyvsp[0].s)); delete (yyvsp[-1].s); delete (yyvsp[0].s); }
#line 2063 "l22_parser.tab.c"
    break;

  case 84:
#line 246 "l22_parser.y"
                                                                  { (yyval.lvalue) = new cdk::variable_node(LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2069 "l22_parser.tab.c"
    break;


#line 2073 "l22_parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (compiler, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (compiler, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, compiler);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, compiler);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (compiler, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, compiler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 252 "l22_parser.y"

