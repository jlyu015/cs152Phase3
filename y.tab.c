/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "miniL.y" /* yacc.c:339  */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <map>
 #include <set>
 #include <vector>


 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;


 std::map<std::string, std::string> varTemps;
 std::map<std::string, int> arrSize;

 std::set<std::string> reserveWords {"IDENT" , "NUMBER" , "FUNCTION" , "BEGIN_PARAMS" , "END_PARAMS" , "BEGIN_LOCALS" , "END_LOCALS" , "BEGIN_BODY" , "END_BODY" , "INTEGER" , "ARRAY" , "ENUM" , "OF" , "IF" , "THEN" , "ENDIF" , "ELSE" , "FOR" , "WHILE" , "DO" , "BEGINLOOP" , "ENDLOOP" , "CONTINUE" , "READ" , "WRITE" , "AND" , "OR" , "NOT" , "TRUE" , "FALSE" , "RETURN" , "SUB" , "ADD" , "MULT" , "DIV" , "MOD" , "EQ" , "NEQ" , "LT" , "GT" , "LTE" , "GTE" , "SEMICOLON" , "COLON" , "COMMA" , "L_PAREN" , "R_PAREN" , "L_SQUARE_BRACKET" , "R_SQUARE_BRACKET" , "ASSIGN" ,
  "prog_start" , "ident" , "idents_plus" , "declaration" , "declarations" , "function" , "functions" , "var" , "vars_plus" , "expression" , "bool_expr" , "mult_expr" , "relation_and_expr" , "term" , "relation_expr" , "comp" , "prog_start" , "statement" , "statements_plus"};
 std::set<std::string> func;
 bool mainFunc = false;
 int tempCount = 0;
 int labelCount = 0;
 int yylex();
 std::string new_temp();
 std::string new_label();

 FILE * yyin;

#line 96 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNCTION = 258,
    BEGIN_PARAMS = 259,
    END_PARAMS = 260,
    BEGIN_LOCALS = 261,
    END_LOCALS = 262,
    BEGIN_BODY = 263,
    END_BODY = 264,
    INTEGER = 265,
    ARRAY = 266,
    ENUM = 267,
    OF = 268,
    IF = 269,
    THEN = 270,
    ENDIF = 271,
    ELSE = 272,
    FOR = 273,
    WHILE = 274,
    DO = 275,
    BEGINLOOP = 276,
    ENDLOOP = 277,
    CONTINUE = 278,
    READ = 279,
    WRITE = 280,
    AND = 281,
    OR = 282,
    NOT = 283,
    TRUE = 284,
    FALSE = 285,
    RETURN = 286,
    SUB = 287,
    ADD = 288,
    MULT = 289,
    DIV = 290,
    MOD = 291,
    EQ = 292,
    NEQ = 293,
    LT = 294,
    GT = 295,
    LTE = 296,
    GTE = 297,
    SEMICOLON = 298,
    COLON = 299,
    COMMA = 300,
    L_PAREN = 301,
    R_PAREN = 302,
    L_SQUARE_BRACKET = 303,
    R_SQUARE_BRACKET = 304,
    ASSIGN = 305,
    IDENT = 306,
    NUMBER = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "miniL.y" /* yacc.c:355  */

  /* put your types here */
  char* strVal;
  int iVal;

  // structs
  struct Stmnt {
      char* code;
  }statement;


  struct Exprsn {
      char* place;
      char* code;
      bool arr;
  }expression;

#line 207 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 238 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   190

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    83,    87,    88,    91,   102,   108,   109,
     112,   116,   117,   120,   123,   128,   135,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   157,   171,   190,
     195,   218,   242,   243,   246,   262,   281,   286,   310,   332,
     357,   362,   389,   390,   391,   392,   393,   394,   395,   398,
     418,   420,   426,   431,   437,   442,   447,   451,   456,   461,
     466,   471,   476
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
  "ARRAY", "ENUM", "OF", "IF", "THEN", "ENDIF", "ELSE", "FOR", "WHILE",
  "DO", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR",
  "NOT", "TRUE", "FALSE", "RETURN", "SUB", "ADD", "MULT", "DIV", "MOD",
  "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "SEMICOLON", "COLON", "COMMA",
  "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ASSIGN",
  "IDENT", "NUMBER", "$accept", "prog_start", "functions", "function",
  "ident", "declarations", "declaration", "idents_plus", "statements_plus",
  "statement", "var", "expression", "bool_expr", "vars_plus", "mult_expr",
  "relation_and_expr", "term", "relation_expr", "comp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -31,    33,   -48,     2,   -48,     4,   -48,   -48,    78,
     -31,    17,    69,    55,    62,   -31,   107,   -31,   132,   -48,
     -31,   -48,   -48,    72,    90,   125,   105,   -31,   130,   115,
     122,    61,   157,   -48,    26,   -31,    26,   150,   -48,   -31,
     -31,   -11,   124,   164,   131,   126,   165,    58,   -48,   -48,
     104,    26,   -48,    48,   -48,   121,    16,   -48,   -48,   112,
     152,   134,   127,    87,    61,   -48,   -48,   -11,   133,   -11,
     -48,    61,   -11,   -48,   -48,   -48,    26,   121,   -48,   -48,
      86,     1,    70,   -11,   -11,   -48,   -48,   -48,   -48,   -48,
     -48,   -11,    61,    26,   -11,   -11,   -11,    26,   -31,   128,
      61,   159,    98,    27,   -48,   133,    19,   -11,   -48,   -48,
     -48,   102,   -48,   -48,   133,   151,   -48,   -48,   -48,   -48,
     -48,   -48,   139,   161,   166,   -48,   -48,   133,   -48,   -48,
      61,    26,   -48,    26,   168,   -21,   160,   -48,   -31,   136,
     -11,    36,    61,   167,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     3,     4,     7,     0,     1,     5,     0,
       8,    13,     0,     0,     0,     0,     0,     8,     0,    14,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,     0,     0,    25,     0,
       0,     0,    27,     0,     0,     0,     0,     0,    51,    53,
       0,     0,    44,    27,    42,     0,     0,    29,    32,    36,
      40,    35,     0,     0,     0,    23,    24,     0,    26,     0,
       6,    15,     0,    12,    52,    54,     0,     0,    45,    43,
       0,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,    46,    55,
      48,     0,    31,    30,    49,     0,    33,    37,    38,    39,
      41,    34,     0,     0,     0,    28,    56,    50,    47,    18,
       0,     0,    20,     0,     0,     0,    21,    19,     0,     0,
       0,     0,     0,     0,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -48,   -48,   184,   -48,    -1,    -2,   -48,    37,   -47,   -48,
     -27,   -40,   -26,   -37,    56,    -4,   -48,   -48,   113
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    53,    12,    13,    14,    43,    44,
      54,    55,    56,    62,    57,    58,    59,    60,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       6,    68,    65,    66,    45,     1,    93,    77,    61,    11,
      63,    80,    61,    61,    11,    21,    11,   101,    25,    11,
       5,    50,   138,    79,   104,    81,    11,   102,    93,   103,
      42,    92,   105,     7,    42,    67,    80,    45,    42,    42,
       5,    52,   111,    93,    45,   115,    93,     9,   109,    42,
     106,   114,    19,   123,    47,    48,    49,   142,    50,    83,
      84,   121,    15,    42,    30,    45,   126,   127,    83,    84,
      42,    61,    51,    45,    16,    34,   125,     5,    52,    35,
      36,    37,    10,   134,    38,    39,    40,    74,    75,   116,
      50,    42,    41,   120,    82,   143,    69,    42,    17,    42,
     141,   139,    50,    45,    76,   135,    18,   136,   100,     5,
      52,    61,     5,    20,    93,    45,    67,   110,    83,    84,
      26,     5,    52,    85,    86,    87,    88,    89,    90,    42,
      83,    84,    28,   108,    83,    84,    27,    42,    31,   112,
     113,    42,    22,    23,    24,   108,    94,    95,    96,   128,
     117,   118,   119,    83,    84,     5,    78,    29,    85,    86,
      87,    88,    89,    90,    32,    83,    84,   129,   130,    33,
      46,    64,    69,    70,    71,    73,    72,    99,    97,    98,
     122,   124,   131,   132,   137,   133,   140,    93,     8,   144,
     107
};

static const yytype_uint8 yycheck[] =
{
       1,    41,    39,    40,    31,     3,    27,    47,    35,    10,
      36,    51,    39,    40,    15,    17,    17,    64,    20,    20,
      51,    32,    43,    50,    71,    51,    27,    67,    27,    69,
      31,    15,    72,     0,    35,    46,    76,    64,    39,    40,
      51,    52,    82,    27,    71,    92,    27,    43,    47,    50,
      76,    91,    15,   100,    28,    29,    30,    21,    32,    32,
      33,    98,    45,    64,    27,    92,    47,   107,    32,    33,
      71,    98,    46,   100,     5,    14,    49,    51,    52,    18,
      19,    20,     4,   130,    23,    24,    25,    29,    30,    93,
      32,    92,    31,    97,    46,   142,    48,    98,    43,   100,
     140,   138,    32,   130,    46,   131,    44,   133,    21,    51,
      52,   138,    51,     6,    27,   142,    46,    47,    32,    33,
      48,    51,    52,    37,    38,    39,    40,    41,    42,   130,
      32,    33,     7,    47,    32,    33,    46,   138,     8,    83,
      84,   142,    10,    11,    12,    47,    34,    35,    36,    47,
      94,    95,    96,    32,    33,    51,    52,    52,    37,    38,
      39,    40,    41,    42,    49,    32,    33,    16,    17,    47,
      13,    21,    48,     9,    43,    10,    50,    50,    26,    45,
      52,    22,    43,    22,    16,    19,    50,    27,     4,    22,
      77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,    55,    56,    51,    57,     0,    55,    43,
       4,    57,    58,    59,    60,    45,     5,    43,    44,    60,
       6,    58,    10,    11,    12,    58,    48,    46,     7,    52,
      60,     8,    49,    47,    14,    18,    19,    20,    23,    24,
      25,    31,    57,    61,    62,    63,    13,    28,    29,    30,
      32,    46,    52,    57,    63,    64,    65,    67,    68,    69,
      70,    63,    66,    65,    21,    66,    66,    46,    64,    48,
       9,    43,    50,    10,    29,    30,    46,    64,    52,    63,
      64,    65,    46,    32,    33,    37,    38,    39,    40,    41,
      42,    71,    15,    27,    34,    35,    36,    26,    45,    50,
      21,    61,    64,    64,    61,    64,    65,    71,    47,    47,
      47,    64,    67,    67,    64,    61,    68,    67,    67,    67,
      68,    66,    52,    61,    22,    49,    47,    64,    47,    16,
      17,    43,    22,    19,    61,    65,    65,    16,    43,    66,
      50,    64,    21,    61,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    56,    57,    58,    58,
      59,    59,    59,    60,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      71,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     0,     2,    12,     1,     0,     3,
       3,     6,     8,     1,     3,     2,     3,     3,     5,     7,
       5,     6,    13,     2,     2,     1,     2,     1,     4,     1,
       3,     3,     1,     3,     3,     1,     1,     3,     3,     3,
       1,     3,     1,     2,     1,     2,     3,     4,     3,     3,
       4,     1,     2,     1,     2,     3,     4,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 79 "miniL.y" /* yacc.c:1646  */
    {
               printf("Main function is not delcared\n");
               exit(1);
            }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 83 "miniL.y" /* yacc.c:1646  */
    {printf("prog_start -> functions\n");}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "miniL.y" /* yacc.c:1646  */
    {printf("functions -> epsilon\n");}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 88 "miniL.y" /* yacc.c:1646  */
    {printf("functions -> function functions\n");}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 91 "miniL.y" /* yacc.c:1646  */
    {
      std::string temp = "func ";
      temp.append((yyvsp[-10].expression).place);
      temp.append("\n");
      temp.append((yyvsp[-10].expression).code);
      temp.append((yyvsp[-7].expression).code);


      }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 103 "miniL.y" /* yacc.c:1646  */
    {
      
   }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 108 "miniL.y" /* yacc.c:1646  */
    {printf("declarations -> epsilon\n");}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 109 "miniL.y" /* yacc.c:1646  */
    {printf("declarations -> declaration SEMICOLON declarations\n");}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "miniL.y" /* yacc.c:1646  */
    {

            }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 116 "miniL.y" /* yacc.c:1646  */
    {printf("declaration -> idents_plus COLON ENUM L_PAREN idents_plus R_PAREN\n");}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 117 "miniL.y" /* yacc.c:1646  */
    {printf("declaration -> idents_plus COLON ARRAY L_SQUARE_BRACKET %d R_SQUARE_BRACKET OF INTEGER\n", (yyvsp[-3].iVal));}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 120 "miniL.y" /* yacc.c:1646  */
    {

            }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 124 "miniL.y" /* yacc.c:1646  */
    {

            }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 129 "miniL.y" /* yacc.c:1646  */
    {
               std::string temp;
               temp.append((yyvsp[-1].statement).code);

               (yyval.statement).code = strdup(temp.c_str());
            }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 136 "miniL.y" /* yacc.c:1646  */
    {
               std::string temp;
               // temp += $1.code + $3.code;
               temp.append((yyvsp[-2].statement).code);
               temp.append((yyvsp[0].statement).code);

               (yyval.statement).code = strdup(temp.c_str());
            }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 145 "miniL.y" /* yacc.c:1646  */
    {printf("statement -> var ASSIGN expression\n");}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 146 "miniL.y" /* yacc.c:1646  */
    {printf("statement -> IF bool_expr THEN statements_plus ENDIF\n");}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 147 "miniL.y" /* yacc.c:1646  */
    {printf("statement -> IF bool_expr THEN statements_plus ELSE statements_plus ENDIF\n");}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 148 "miniL.y" /* yacc.c:1646  */
    {printf("statement -> WHILE bool_expr BEGINLOOP statements_plus ENDLOOP\n");}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 149 "miniL.y" /* yacc.c:1646  */
    {printf("statement -> DO BEGINLOOP statements_plus ENDLOOP\n");}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "miniL.y" /* yacc.c:1646  */
    {printf("statement -> FOR vars_plus ASSIGN %d SEMICOLON bool_expr SEMICOLON vars_plus ASSIGN expression BEGINLOOP statements_plus ENDLOOP\n", (yyvsp[-9].iVal));}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 151 "miniL.y" /* yacc.c:1646  */
    {printf("statement -> READ vars_plus\n");}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 152 "miniL.y" /* yacc.c:1646  */
    {printf("statement -> WRITE vars_plus\n");}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 153 "miniL.y" /* yacc.c:1646  */
    {printf("statement -> CONTINUE\n");}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 154 "miniL.y" /* yacc.c:1646  */
    {printf("statement -> RETURN expression\n");}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 158 "miniL.y" /* yacc.c:1646  */
    {
      std::string temp;
      std::string idnt = (yyvsp[0].expression).place;
      if(func.find(idnt) == func.end() && varTemps.find(idnt) == varTemps.end()){
         printf("Identifier %s not yet declared.\n",idnt.c_str());
      }
      else if (arrSize[idnt] > 1) {
         printf("Index was not provided for array identifier %s.\n", idnt.c_str());
      }
      (yyval.expression).place = strdup(idnt.c_str());
      (yyval.expression).arr = false;

   }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 172 "miniL.y" /* yacc.c:1646  */
    {
      std::string temp;
      std::string idnt = (yyvsp[-3].expression).place;
      if(func.find(idnt) == func.end() && varTemps.find(idnt) == varTemps.end()){
         printf("Identifier %s not yet declared.\n",idnt.c_str());
      }
      else if (arrSize[idnt] == 1) {
         printf("Index was provided for non-array identifier %s.\n", idnt.c_str());
      }
      temp.append((yyvsp[-3].expression).place);
      temp.append(", ");
      temp.append((yyvsp[-1].expression).place);
      (yyval.expression).code = strdup((yyvsp[-1].expression).code);
      (yyval.expression).place = strdup(temp.c_str());
      (yyval.expression).arr = true;
   }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 191 "miniL.y" /* yacc.c:1646  */
    {
      (yyval.expression).code = strdup((yyvsp[0].expression).code);
      (yyval.expression).place = strdup((yyvsp[0].expression).place);
   }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 196 "miniL.y" /* yacc.c:1646  */
    {
      std::string temp;
      std::string dst = new_temp();
      // temp += $1.code + $3.code + ". " + dst + "\n";
      temp.append((yyvsp[-2].expression).code);
      temp.append((yyvsp[0].expression).code);
      temp.append(". ");
      temp.append(dst);
      temp.append("\n");

      // temp += "+ " + dst + ", " + $1.place + ", " + $3.place + "\n";
      temp.append("+ ");
      temp.append(dst);
      temp.append(", ");
      temp.append((yyvsp[-2].expression).place);
      temp.append(", ");
      temp.append((yyvsp[0].expression).place);
      temp.append("\n");

      (yyval.expression).code = strdup(temp.c_str());
      (yyval.expression).place = strdup(dst.c_str());
   }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 219 "miniL.y" /* yacc.c:1646  */
    {
      std::string temp;
      std::string dst = new_temp();
      // temp += $1.code + $3.code + ". " + dst + "\n";
      temp.append((yyvsp[-2].expression).code);
      temp.append((yyvsp[0].expression).code);
      temp.append(". ");
      temp.append(dst);
      temp.append("\n");
      //temp += "- " + dst + ", " + $1.place + ", " + $3.place + "\n";
      temp.append("- ");
      temp.append(dst);
      temp.append(", ");
      temp.append((yyvsp[-2].expression).place);
      temp.append(", ");
      temp.append((yyvsp[0].expression).place);
      temp.append("\n");
      (yyval.expression).code = strdup(temp.c_str());
      (yyval.expression).place = strdup(dst.c_str());
   }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 242 "miniL.y" /* yacc.c:1646  */
    {printf("bool_expr -> relation_and_expr\n");}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 243 "miniL.y" /* yacc.c:1646  */
    {printf("bool_expr -> bool_expr OR relation_and_expr\n");}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 247 "miniL.y" /* yacc.c:1646  */
    {
         std::string temp;
         temp.append((yyvsp[-2].expression).code);
         if((yyvsp[-2].expression).arr) {
            temp.append(".[]| ");
         }
         else {
            temp.append(".| ");
         }
         temp.append((yyvsp[-2].expression).place);
         temp.append("\n");
         temp.append((yyvsp[0].expression).code);
         (yyval.expression).code = strdup(temp.c_str());
         (yyval.expression).place = strdup("");
      }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 263 "miniL.y" /* yacc.c:1646  */
    {
         std::string temp;
         temp.append((yyvsp[0].expression).code);
         if((yyvsp[0].expression).arr) {
            temp.append(".[]| ");
         }
         else {
            temp.append(".| ");
         }
         temp.append((yyvsp[0].expression).place);
         temp.append("\n");

         (yyval.expression).code = strdup(temp.c_str());
         (yyval.expression).place = strdup("");

      }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 282 "miniL.y" /* yacc.c:1646  */
    {
      (yyval.expression).code = strdup((yyvsp[0].expression).code);
      (yyval.expression).place = strdup((yyvsp[0].expression).place);
   }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 287 "miniL.y" /* yacc.c:1646  */
    {
      std::string temp;
      std::string dst = new_temp();
      // temp += $1.code + $3.code + ". " + dst + "\n";
      temp.append((yyvsp[-2].expression).code);
      temp.append((yyvsp[0].expression).code);
      temp.append(". ");
      temp.append(dst);
      temp.append("\n");


      //temp += "* " + dst + ", " + $1.place + ", " + $3.place + "\n";
      temp.append("* ");
      temp.append(dst);
      temp.append(", ");
      temp.append((yyvsp[-2].expression).place);
      temp.append(", ");
      temp.append((yyvsp[0].expression).place);
      temp.append("\n");

      (yyval.expression).code = strdup(temp.c_str());
      (yyval.expression).place = strdup(dst.c_str());
   }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 311 "miniL.y" /* yacc.c:1646  */
    {
      std::string temp;
      std::string dst = new_temp();
      //temp += $1.code + $3.code + ". " + dst + "\n";
      temp.append((yyvsp[-2].expression).code);
      temp.append((yyvsp[0].expression).code);
      temp.append(". ");
      temp.append(dst);
      temp.append("\n");

      // temp += "/ " + dst + ", " + $1.place + ", " + $3.place + "\n";
      temp.append("/ ");
      temp.append(dst);
      temp.append(", ");
      temp.append((yyvsp[-2].expression).place);
      temp.append(", ");
      temp.append((yyvsp[0].expression).place);
      temp.append("\n");
      (yyval.expression).code = strdup(temp.c_str());
      (yyval.expression).place = strdup(dst.c_str());
   }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 333 "miniL.y" /* yacc.c:1646  */
    {
      std::string temp;
      std::string dst = new_temp();
      // temp += $1.code + $3.code + ". " + dst + "\n";
      temp.append((yyvsp[-2].expression).code);
      temp.append((yyvsp[0].expression).code);
      temp.append(". ");
      temp.append(dst);
      temp.append("\n");

      // temp += "% " + dst + ", " + $1.place + ", " + $3.place + "\n";
      temp.append("% ");
      temp.append(dst);
      temp.append(", ");
      temp.append((yyvsp[-2].expression).place);
      temp.append(", ");
      temp.append((yyvsp[0].expression).place);
      temp.append("\n");
      (yyval.expression).code = strdup(temp.c_str());
      (yyval.expression).place = strdup(dst.c_str());
   }
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 358 "miniL.y" /* yacc.c:1646  */
    {
      (yyval.expression).code = strdup((yyvsp[0].expression).code);
      (yyval.expression).place = strdup((yyvsp[0].expression).place);
   }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 363 "miniL.y" /* yacc.c:1646  */
    {
      std::string temp;
      std::string dst = new_temp();
      // temp += $1.code + $3.code + ". " + dst + "\n";
      temp.append((yyvsp[-2].expression).code);
      temp.append((yyvsp[0].expression).code);
      temp.append(". ");
      temp.append(dst);
      temp.append("\n");


      // temp += "&& " + dst + ", " + $1.place + ", " + $3.place + "\n";
      temp.append("&& ");
      temp.append(dst);
      temp.append(", ");
      temp.append((yyvsp[-2].expression).place);
      temp.append(", ");
      temp.append((yyvsp[0].expression).place);
      temp.append("\n");

      (yyval.expression).code = strdup(temp.c_str());
      (yyval.expression).place = strdup(dst.c_str());
   }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 389 "miniL.y" /* yacc.c:1646  */
    {printf("term -> var\n");}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 390 "miniL.y" /* yacc.c:1646  */
    {printf("term -> SUB var\n");}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 391 "miniL.y" /* yacc.c:1646  */
    {printf("term -> NUMBER %d\n", (yyvsp[0].iVal));}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 392 "miniL.y" /* yacc.c:1646  */
    {printf("term -> SUB NUMBER %d\n", (yyvsp[0].iVal));}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 393 "miniL.y" /* yacc.c:1646  */
    {printf("term -> L_PAREN expression R_PAREN\n");}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 394 "miniL.y" /* yacc.c:1646  */
    {printf("term -> ident L_PAREN expression R_PAREN\n");}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 395 "miniL.y" /* yacc.c:1646  */
    {printf("term -> ident L_PAREN R_PAREN\n");}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 399 "miniL.y" /* yacc.c:1646  */
    {
                  std::string dst = new_temp();
                  std::string temp;
                  // temp += $1.code + $2.code + ", " + dst + "\n";
                  temp.append((yyvsp[-2].expression).code);
                  temp.append((yyvsp[-1].expression).code);
                  temp.append(", ");
                  temp.append(dst);
                  temp.append("\n");

                  // temp += $2.place + dst + ", " $3.place + "\n";
                  temp.append((yyvsp[-1].expression).place);
                  temp.append(dst);
                  temp.append(", ");
                  temp.append((yyvsp[0].expression).place);
                  temp.append("\n");
                  (yyval.expression).code = strdup(temp.c_str());
                  (yyval.expression).place = strdup(temp.c_str());
               }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 419 "miniL.y" /* yacc.c:1646  */
    {printf("relation_expr -> NOT expression comp expression\n");}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 421 "miniL.y" /* yacc.c:1646  */
    {
                  std::string temp = "1";
                  (yyval.expression).code = strdup("");
                  (yyval.expression).place = strdup(temp.c_str());
               }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 427 "miniL.y" /* yacc.c:1646  */
    {  
                  std::string temp = "0";
                  (yyval.expression).code = strdup("");
                  (yyval.expression).place = strdup(temp.c_str());}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 432 "miniL.y" /* yacc.c:1646  */
    {
                  std::string temp = "0";
                  (yyval.expression).code = strdup("");
                  (yyval.expression).place = strdup(temp.c_str());
               }
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 438 "miniL.y" /* yacc.c:1646  */
    {  
                  std::string temp = "1";
                  (yyval.expression).code = strdup("");
                  (yyval.expression).place = strdup(temp.c_str());}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 443 "miniL.y" /* yacc.c:1646  */
    {
                  (yyval.expression).code = (yyvsp[-1].expression).code;
                  (yyval.expression).place = (yyvsp[-1].expression).place;
               }
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 448 "miniL.y" /* yacc.c:1646  */
    {printf("relation_expr -> NOT L_PAREN bool_expr R_PAREN\n");}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 452 "miniL.y" /* yacc.c:1646  */
    {
         (yyval.expression).code = strdup("");
         (yyval.expression).place =strdup("== ");
      }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 457 "miniL.y" /* yacc.c:1646  */
    {
         (yyval.expression).code = strdup("");
         (yyval.expression).place =strdup("!= ");
      }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 462 "miniL.y" /* yacc.c:1646  */
    {
         (yyval.expression).code = strdup("");
         (yyval.expression).place =strdup("< ");
      }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 467 "miniL.y" /* yacc.c:1646  */
    {
         (yyval.expression).code = strdup("");
         (yyval.expression).place =strdup("> ");
      }
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 472 "miniL.y" /* yacc.c:1646  */
    {
         (yyval.expression).code = strdup("");
         (yyval.expression).place =strdup("<= ");
      }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 477 "miniL.y" /* yacc.c:1646  */
    {
         (yyval.expression).code = strdup("");
         (yyval.expression).place =strdup(">= ");
      }
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2154 "y.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
      yyerror (YY_("syntax error"));
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 484 "miniL.y" /* yacc.c:1906  */
 

int main(int argc, char ** argv)
{
   if(argc >= 2) {
      yyin = fopen(argv[1], "r");
      if(yyin == NULL) {
         yyin = stdin;
      }
   }
   else{
      yyin = stdin;
   }
   yyparse();
   
   return 0;
}

void yyerror(const char *msg) {
   printf("Syntax error: Line %d, position %d: %s \n", currLine, currPos, msg);

   
    /* implement your error handling */
}


std::string new_temp() {
   std::string tempString = "T" + std::to_string(tempCount);
   tempCount++;

   return tempString;
}

std::string new_label() {
   std::string labelString = "L" + std::to_string(labelCount);
   labelCount++;

   return labelString;
}
