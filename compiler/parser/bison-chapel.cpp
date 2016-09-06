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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 1

/* Pull parsers.  */
#define YYPULL 0




/* Copy the first part of user declarations.  */

#line 67 "bison-chapel.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison-chapel.h".  */
#ifndef YY_YY_INCLUDE_BISON_CHAPEL_H_INCLUDED
# define YY_YY_INCLUDE_BISON_CHAPEL_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 33 "chapel.ypp" /* yacc.c:355  */

  extern int  captureTokens;
  extern char captureString[1024];
#line 44 "chapel.ypp" /* yacc.c:355  */

  #ifndef _BISON_CHAPEL_DEFINES_0_
  #define _BISON_CHAPEL_DEFINES_0_

  #define YYLEX_NEWLINE                  -1
  #define YYLEX_SINGLE_LINE_COMMENT      -2
  #define YYLEX_BLOCK_COMMENT            -3

  typedef void* yyscan_t;

  int processNewline(yyscan_t scanner);
  void stringBufferInit();

  #endif
#line 64 "chapel.ypp" /* yacc.c:355  */

  #ifndef _BISON_CHAPEL_DEFINES_1_
  #define _BISON_CHAPEL_DEFINES_1_

  #include "symbol.h"

  #include <cstdio>
  #include <utility>
  #include <vector>

  class ArgSymbol;
  class BlockStmt;
  class CallExpr;
  class DefExpr;
  class EnumType;
  class Expr;
  class FnSymbol;
  class Type;

  enum   ProcIter {
    ProcIter_PROC,
    ProcIter_ITER
  };

  struct IntentExpr {
    Expr*  first;
    Expr*  second;
  };

  struct OnlyRename {
    enum{SINGLE, DOUBLE} tag;

    union {
      Expr*  elem;
      std::pair<Expr*, Expr*>* renamed;
    };
  };

  // The lexer only uses pch.
  // The remaining types are for parser productions
  union  YYSTYPE {
    const char*       pch;

    Vec<const char*>* vpch;
    RetTag            retTag;
    bool              b;
    IntentTag         pt;
    Expr*             pexpr;
    DefExpr*          pdefexpr;
    CallExpr*         pcallexpr;
    BlockStmt*        pblockstmt;
    Type*             ptype;
    EnumType*         penumtype;
    FnSymbol*         pfnsymbol;
    Flag              flag;
    ProcIter          procIter;
    FlagSet*          flagSet;
    IntentExpr        pIntentExpr;
    std::vector<OnlyRename*>* ponlylist;
  };

  #endif
#line 132 "chapel.ypp" /* yacc.c:355  */

  #ifndef _BISON_CHAPEL_DEFINES_2_
  #define _BISON_CHAPEL_DEFINES_2_

  struct YYLTYPE {
    int         first_line;
    int         first_column;
    int         last_line;
    int         last_column;
    const char* comment;
  };

  #define YYLTYPE_IS_DECLARED 1
  #define YYLTYPE_IS_TRIVIAL  1

  #endif
#line 154 "chapel.ypp" /* yacc.c:355  */

  #ifndef _BISON_CHAPEL_DEFINES_3_
  #define _BISON_CHAPEL_DEFINES_3_

  class ParserContext {
  public:
    ParserContext()
    {
      scanner       = 0;
      latestComment = 0;
      generatedStmt = 0;
    }

    ParserContext(yyscan_t scannerIn)
    {
      scanner       = scannerIn;
      latestComment = 0;
      generatedStmt = 0;
    }

    yyscan_t    scanner;
    const char* latestComment;
    BaseAST*    generatedStmt;
  };

  #endif

#line 224 "bison-chapel.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TIDENT = 258,
    INTLITERAL = 259,
    REALLITERAL = 260,
    IMAGLITERAL = 261,
    STRINGLITERAL = 262,
    CSTRINGLITERAL = 263,
    EXTERNCODE = 264,
    TALIGN = 265,
    TAS = 266,
    TATOMIC = 267,
    TBEGIN = 268,
    TBREAK = 269,
    TBY = 270,
    TCLASS = 271,
    TCOBEGIN = 272,
    TCOFORALL = 273,
    TCONFIG = 274,
    TCONST = 275,
    TCONTINUE = 276,
    TDELETE = 277,
    TDMAPPED = 278,
    TDO = 279,
    TDOMAIN = 280,
    TELSE = 281,
    TENUM = 282,
    TEXCEPT = 283,
    TEXPORT = 284,
    TEXTERN = 285,
    TFOR = 286,
    TFORALL = 287,
    TIF = 288,
    TIN = 289,
    TINDEX = 290,
    TINLINE = 291,
    TINOUT = 292,
    TITER = 293,
    TLABEL = 294,
    TLAMBDA = 295,
    TLET = 296,
    TLOCAL = 297,
    TMINUSMINUS = 298,
    TMODULE = 299,
    TNEW = 300,
    TNIL = 301,
    TNOINIT = 302,
    TON = 303,
    TONLY = 304,
    TOTHERWISE = 305,
    TOUT = 306,
    TPARAM = 307,
    TPLUSPLUS = 308,
    TPRAGMA = 309,
    TPRIMITIVE = 310,
    TPRIVATE = 311,
    TPROC = 312,
    TPUBLIC = 313,
    TRECORD = 314,
    TREDUCE = 315,
    TREF = 316,
    TREQUIRE = 317,
    TRETURN = 318,
    TSCAN = 319,
    TSELECT = 320,
    TSERIAL = 321,
    TSINGLE = 322,
    TSPARSE = 323,
    TSUBDOMAIN = 324,
    TSYNC = 325,
    TTHEN = 326,
    TTYPE = 327,
    TUNDERSCORE = 328,
    TUNION = 329,
    TUSE = 330,
    TVAR = 331,
    TWHEN = 332,
    TWHERE = 333,
    TWHILE = 334,
    TWITH = 335,
    TYIELD = 336,
    TZIP = 337,
    TALIAS = 338,
    TAND = 339,
    TASSIGN = 340,
    TASSIGNBAND = 341,
    TASSIGNBOR = 342,
    TASSIGNBXOR = 343,
    TASSIGNDIVIDE = 344,
    TASSIGNEXP = 345,
    TASSIGNLAND = 346,
    TASSIGNLOR = 347,
    TASSIGNMINUS = 348,
    TASSIGNMOD = 349,
    TASSIGNMULTIPLY = 350,
    TASSIGNPLUS = 351,
    TASSIGNSL = 352,
    TASSIGNSR = 353,
    TBAND = 354,
    TBNOT = 355,
    TBOR = 356,
    TBXOR = 357,
    TCOLON = 358,
    TCOMMA = 359,
    TDIVIDE = 360,
    TDOT = 361,
    TDOTDOT = 362,
    TDOTDOTDOT = 363,
    TEQUAL = 364,
    TEXP = 365,
    TGREATER = 366,
    TGREATEREQUAL = 367,
    THASH = 368,
    TLESS = 369,
    TLESSEQUAL = 370,
    TMINUS = 371,
    TMOD = 372,
    TNOT = 373,
    TNOTEQUAL = 374,
    TOR = 375,
    TPLUS = 376,
    TQUESTION = 377,
    TSEMI = 378,
    TSHIFTLEFT = 379,
    TSHIFTRIGHT = 380,
    TSTAR = 381,
    TSWAP = 382,
    TIO = 383,
    TLCBR = 384,
    TRCBR = 385,
    TLP = 386,
    TRP = 387,
    TLSBR = 388,
    TRSBR = 389,
    TNOELSE = 390,
    TUPLUS = 391,
    TUMINUS = 392
  };
#endif

/* Value type.  */

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



#ifndef YYPUSH_MORE_DEFINED
# define YYPUSH_MORE_DEFINED
enum { YYPUSH_MORE = 4 };
#endif

typedef struct yypstate yypstate;

int yypush_parse (yypstate *ps, int pushed_char, YYSTYPE const *pushed_val, YYLTYPE *pushed_loc, ParserContext* context);

yypstate * yypstate_new (void);
void yypstate_delete (yypstate *ps);
/* "%code provides" blocks.  */
#line 185 "chapel.ypp" /* yacc.c:355  */

  extern int yydebug;

  void yyerror(YYLTYPE*       ignored,
               ParserContext* context,
               const char*    str);

#line 407 "bison-chapel.cpp" /* yacc.c:355  */

#endif /* !YY_YY_INCLUDE_BISON_CHAPEL_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 413 "bison-chapel.cpp" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 38 "chapel.ypp" /* yacc.c:359  */

  int         captureTokens;
  char        captureString[1024];
#line 193 "chapel.ypp" /* yacc.c:359  */

  #include "build.h"
  #include "DoWhileStmt.h"
  #include "driver.h"
  #include "flex-chapel.h"
  #include "ForLoop.h"
  #include "parser.h"
  #include "stmt.h"
  #include "stringutil.h"
  #include "vec.h"
  #include "WhileDoStmt.h"

  #include <cstdio>
  #include <cstdlib>
  #include <cstring>
  #include <stdint.h>

  static int query_uid = 1;

  #define YYLLOC_DEFAULT(Current, Rhs, N)                                 \
    if (N) {                                                              \
      (Current).first_line   = (Rhs)[1].first_line;                       \
      (Current).first_column = (Rhs)[1].first_column;                     \
      (Current).last_line    = (Rhs)[N].last_line;                        \
      (Current).last_column  = (Rhs)[N].last_column;                      \
      (Current).comment      = NULL;                                      \
                                                                          \
      if ((Current).first_line)                                           \
        yystartlineno = (Current).first_line;                             \
                                                                          \
    } else  {                                                             \
      (Current) = yylloc;                                                 \
    }

  void yyerror(YYLTYPE*       ignored,
               ParserContext* context,
               const char*    str) {
    // TODO -- should this begin with error:
    if (!chplParseString) {
      const char* yyText = yyget_text(context->scanner);

      fprintf(stderr, "%s:%d: %s", yyfilename, chplLineno, str);

      if (strlen(yyText) > 0) {
        fprintf(stderr, ": near '%s'", yyText);
      }
    } else {
      fprintf(stderr, "%s: %s", yyfilename, str);

      if (chplParseStringMsg && (strlen(chplParseStringMsg) > 0)) {
        fprintf(stderr, " %s", chplParseStringMsg);
      }
    }

    fprintf(stderr, "\n");

    clean_exit(1);
  }

#line 479 "bison-chapel.cpp" /* yacc.c:359  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   11368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  138
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  436
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  831

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   392

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   416,   416,   421,   422,   428,   429,   434,   435,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   469,   471,   476,   477,   478,
     493,   494,   499,   500,   505,   510,   515,   519,   525,   526,
     527,   531,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   553,   554,   558,
     562,   563,   567,   568,   572,   573,   577,   578,   579,   580,
     581,   582,   583,   587,   588,   592,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   629,   635,   641,   647,   654,   664,   668,
     669,   670,   671,   675,   680,   681,   685,   687,   689,   696,
     701,   709,   714,   719,   727,   728,   733,   734,   736,   741,
     751,   760,   764,   772,   773,   778,   783,   777,   808,   814,
     821,   829,   840,   846,   839,   874,   878,   883,   887,   895,
     896,   897,   898,   899,   900,   901,   902,   903,   904,   905,
     906,   907,   908,   909,   910,   911,   912,   913,   914,   915,
     916,   917,   918,   919,   920,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,   934,   935,   939,   940,   944,
     948,   949,   950,   954,   956,   958,   960,   965,   966,   970,
     971,   972,   973,   974,   975,   976,   977,   978,   982,   983,
     984,   985,   989,   990,   994,   995,   996,   997,   998,   999,
    1003,  1004,  1008,  1009,  1013,  1015,  1020,  1021,  1025,  1026,
    1030,  1031,  1035,  1037,  1039,  1044,  1057,  1074,  1075,  1077,
    1082,  1090,  1098,  1106,  1115,  1125,  1126,  1127,  1131,  1132,
    1140,  1142,  1147,  1149,  1151,  1156,  1158,  1160,  1167,  1168,
    1169,  1173,  1174,  1175,  1176,  1196,  1200,  1204,  1212,  1216,
    1217,  1218,  1222,  1224,  1230,  1232,  1234,  1239,  1240,  1241,
    1242,  1243,  1244,  1245,  1251,  1252,  1253,  1254,  1258,  1259,
    1260,  1264,  1265,  1269,  1270,  1274,  1275,  1279,  1280,  1281,
    1282,  1283,  1287,  1298,  1299,  1300,  1301,  1302,  1303,  1305,
    1307,  1309,  1311,  1313,  1315,  1320,  1322,  1324,  1326,  1328,
    1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,  1351,  1357,
    1363,  1369,  1378,  1383,  1391,  1392,  1393,  1394,  1395,  1396,
    1397,  1398,  1403,  1404,  1408,  1412,  1414,  1422,  1433,  1434,
    1438,  1439,  1444,  1449,  1457,  1458,  1459,  1460,  1461,  1462,
    1463,  1464,  1465,  1467,  1469,  1471,  1473,  1475,  1480,  1481,
    1482,  1483,  1494,  1495,  1499,  1500,  1501,  1505,  1506,  1507,
    1515,  1516,  1517,  1521,  1522,  1523,  1524,  1525,  1526,  1527,
    1528,  1535,  1536,  1540,  1541,  1542,  1543,  1544,  1545,  1546,
    1547,  1548,  1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,
    1557,  1558,  1559,  1560,  1561,  1562,  1566,  1567,  1568,  1569,
    1570,  1571,  1575,  1576,  1577,  1578,  1582,  1583,  1584,  1585,
    1590,  1591,  1592,  1593,  1594,  1595,  1596
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENT", "INTLITERAL", "REALLITERAL",
  "IMAGLITERAL", "STRINGLITERAL", "CSTRINGLITERAL", "EXTERNCODE", "TALIGN",
  "TAS", "TATOMIC", "TBEGIN", "TBREAK", "TBY", "TCLASS", "TCOBEGIN",
  "TCOFORALL", "TCONFIG", "TCONST", "TCONTINUE", "TDELETE", "TDMAPPED",
  "TDO", "TDOMAIN", "TELSE", "TENUM", "TEXCEPT", "TEXPORT", "TEXTERN",
  "TFOR", "TFORALL", "TIF", "TIN", "TINDEX", "TINLINE", "TINOUT", "TITER",
  "TLABEL", "TLAMBDA", "TLET", "TLOCAL", "TMINUSMINUS", "TMODULE", "TNEW",
  "TNIL", "TNOINIT", "TON", "TONLY", "TOTHERWISE", "TOUT", "TPARAM",
  "TPLUSPLUS", "TPRAGMA", "TPRIMITIVE", "TPRIVATE", "TPROC", "TPUBLIC",
  "TRECORD", "TREDUCE", "TREF", "TREQUIRE", "TRETURN", "TSCAN", "TSELECT",
  "TSERIAL", "TSINGLE", "TSPARSE", "TSUBDOMAIN", "TSYNC", "TTHEN", "TTYPE",
  "TUNDERSCORE", "TUNION", "TUSE", "TVAR", "TWHEN", "TWHERE", "TWHILE",
  "TWITH", "TYIELD", "TZIP", "TALIAS", "TAND", "TASSIGN", "TASSIGNBAND",
  "TASSIGNBOR", "TASSIGNBXOR", "TASSIGNDIVIDE", "TASSIGNEXP",
  "TASSIGNLAND", "TASSIGNLOR", "TASSIGNMINUS", "TASSIGNMOD",
  "TASSIGNMULTIPLY", "TASSIGNPLUS", "TASSIGNSL", "TASSIGNSR", "TBAND",
  "TBNOT", "TBOR", "TBXOR", "TCOLON", "TCOMMA", "TDIVIDE", "TDOT",
  "TDOTDOT", "TDOTDOTDOT", "TEQUAL", "TEXP", "TGREATER", "TGREATEREQUAL",
  "THASH", "TLESS", "TLESSEQUAL", "TMINUS", "TMOD", "TNOT", "TNOTEQUAL",
  "TOR", "TPLUS", "TQUESTION", "TSEMI", "TSHIFTLEFT", "TSHIFTRIGHT",
  "TSTAR", "TSWAP", "TIO", "TLCBR", "TRCBR", "TLP", "TRP", "TLSBR",
  "TRSBR", "TNOELSE", "TUPLUS", "TUMINUS", "$accept", "program",
  "toplevel_stmt_ls", "toplevel_stmt", "pragma_ls", "stmt",
  "module_decl_stmt", "access_control", "block_stmt", "stmt_ls", "only_ls",
  "use_stmt", "require_stmt", "assignment_stmt", "opt_ident", "ident",
  "opt_ident_or_string", "do_stmt", "return_stmt", "class_level_stmt",
  "private_decl", "extern_block_stmt", "loop_stmt", "zippered_iterator",
  "if_stmt", "select_stmt", "when_stmt_ls", "when_stmt", "class_decl_stmt",
  "class_tag", "opt_inherit", "class_level_stmt_ls", "enum_decl_stmt",
  "enum_ls", "enum_item", "lambda_decl_expr", "$@1", "$@2", "linkage_spec",
  "fn_decl_stmt", "$@3", "$@4", "fn_decl_stmt_inner", "fn_ident",
  "assignop_ident", "opt_formal_ls", "req_formal_ls", "formal_ls",
  "formal", "opt_intent_tag", "required_intent_tag", "opt_this_intent_tag",
  "proc_or_iter", "opt_ret_tag", "opt_function_body_stmt",
  "function_body_stmt", "query_expr", "opt_query_expr", "var_arg_expr",
  "opt_where_part", "type_alias_decl_stmt", "type_alias_decl_stmt_inner",
  "opt_init_type", "var_decl_stmt", "opt_config", "var_decl_stmt_inner_ls",
  "var_decl_stmt_inner", "tuple_var_decl_component",
  "tuple_var_decl_stmt_inner_ls", "opt_init_expr", "opt_type",
  "array_type", "opt_formal_array_elt_type", "formal_array_type",
  "opt_formal_type", "expr_ls", "tuple_component", "tuple_expr_ls",
  "opt_actual_ls", "actual_ls", "actual_expr", "ident_expr",
  "type_level_expr", "for_expr", "cond_expr", "nil_expr",
  "stmt_level_expr", "opt_task_intent_ls", "task_intent_clause",
  "task_intent_ls", "intent_expr", "io_expr", "new_expr", "let_expr",
  "expr", "lhs_expr", "fun_expr", "call_expr", "dot_expr",
  "parenthesized_expr", "literal_expr", "assoc_expr_ls", "binary_op_expr",
  "unary_op_expr", "reduce_expr", "scan_expr", "reduce_scan_op_expr", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392
};
# endif

#define YYPACT_NINF -725

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-725)))

#define YYTABLE_NINF -390

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -725,    21,  2455,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  3503,     5,    93,  -725,     5,  6285,    30,    93,  6285,
    3503,    80,    93,   384,   407,  5209,  6285,  6285,    87,  -725,
      93,  -725,    36,  3503,  6285,  6285,  -725,  6285,  6285,   127,
     158,   607,  1027,  -725,  5419,  5524,  6285,  5655,  6285,   129,
     166,  3503,    93,  -725,  5419,  6285,  6285,  -725,  -725,  6285,
    -725,  -725,  7230,  6285,  6285,  -725,  6285,  -725,  -725,  2717,
    4997,  5419,  -725,  3372,  -725,  -725,   274,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
      93,  -725,    72,   237,  -725,  -725,  -725,   256,   186,  -725,
    -725,  -725,   207,   218,   223,   259,   266, 11184,  8849,    49,
     281,   282,  -725,  -725,  -725,  -725,  -725,  -725,   336,  -725,
   11184,   288,  3503,  -725,   290,  -725,   231,  6285,  6285,  6285,
    6285,  6285,  5419,  5419,    79,  -725,  -725,  -725,  -725,  8797,
     321,  -725,  -725,    93,   297,  9091,   344,  5419,   295,  -725,
    -725,  -725,  -725,    93,   116,    93,   305,    45,  7872,  7809,
    7993,  5419,  3503,   311,    17,    41,    64,  -725,  -725,   536,
     339,  8051,   536,  -725,  5419,  -725,   267,  -725,  -725,    93,
    -725,   181, 11184,  -725,  9125,  8676,  3503,  -725,  -725,  8051,
   11184,   315,  5419,  -725, 11184,   385,   337,   197,  8905,  8051,
    9210,   265,  1334,   536,   265,   536,  -725,  -725,  2848,   -25,
    -725,  6285,  -725,    82,    83, 11184,    67,  9254,     3,   464,
    -725,    93,   369,  -725,  -725,  -725,    22,    36,    36,    36,
    -725,  6285,  6285,  6285,  6285,  5760,  5760,  6285,  6285,  6285,
    6285,  6285,  6285,    74,  7230,  6285,  6285,  6285,  6285,  6285,
    6285,  6285,  6285,  6285,  6285,  6285,  6285,  6285,  6285,  6285,
    6285,  6285,  6285,  6285,  6285,  6285,  6285,  6285,  6285,  6285,
    6285,  6285,  6285,  6285,  6285,  5419,  5419,  5760,  5760,  4892,
    -725,  -725,  2979,  -725,  8949,  9057,  9329,   -22,  5760,    45,
     351,  -725,  -725,  6285,   378,  -725,   346,   373,  -725, 11184,
      93,   357,    93,   447,  5419,  -725,  3634,  5760,  -725,  3765,
    5760,  -725,    45,  3503,   456,   352,  -725,    77,  -725,  -725,
      17,  -725,   386,   360,  -725,  2292,   404,  6285,    36,  -725,
     361,  -725,  -725,  5419,  -725,  -725,  -725,  -725,  -725,  5419,
     362,  2292,   391,  -725,  -725,  6285,  6285,  -725,  -725,  -725,
    -725,  -725,  7751,  5104,  -725,  5314,  -725,  5760,  2586,   364,
    6285,  6285,  -725,  -725,   367,  5419,   370,   141,    36,   203,
     249,   258,   276,  8739,  1593,  1593,   347,  -725,   347,  -725,
     347,  2005,   807,  1459,  1731,   339,   265,  -725,  -725,  -725,
    1334,  7366,   347,   859,   859,  1593,   859,   859,   402,   265,
    7366,  1110,   402,   536,   536,   265,  9373,  9441,  9485,  9553,
    9597,  9665,  9709,  9777,  9821,  9889,  9933, 10001, 10045, 10113,
   10157,   374,   368,  -725,   347,  -725,   347,   145,  -725,  -725,
    -725,  -725,  -725,  -725,    93,   100,  -725, 11242,   358,  6390,
    5760,  6495,  5760,  6285,  5760,  7379,     5, 10225,  -725,  -725,
   10269,  6285,  5419,  -725,  5419,   424,    69,  -725,  -725,   369,
    6285,   168,  6285, 11184,    47,  8114,  6285, 11184,    33,  7930,
    -725,   488, 10337,  3503,  -725,   183,  -725,    46,  -725,   251,
     383,    17,    41,  -725,  5419,  -725,   500,  5865,  -725, 11184,
    -725,  -725,  -725, 11184,    31,   390,  -725,  -725,   279,    93,
     280, 10395,   286,  -725,  -725,  -725,  -725,   -10,  7509,  -725,
   11184,  3503, 11184, 10458,  3110,   412,  -725,  -725,  -725,  -725,
    -725,  7440,   289,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  4892,  -725,  5760,
    5760,  6285,   493, 10516,  6285,   505, 10579,   397,  7567,    45,
      45,  -725, 11184,  -725, 11184,  -725,  6285,    93,  -725,   413,
    8051,  -725,  8177,  3896,  -725,  4027,  -725,  8240,  4158,  -725,
      45,  4289,  -725,    45,  3503,  6285,  -725,   561,  -725,    17,
     438,   483,  -725,  -725,  -725,    28,  -725,  -725,   404,    50,
    -725, 11184,  4420,  5419,  -725,  -725,  -725,  -725,  6285,  -725,
    6285,  -725,  4551,   411,  4682,   415,  -725,  6285,  -725,  3241,
     494,   251,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,    93,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,   440,   416,
     416,  -725,  -725,   187,   206, 10637,  6600,  6705, 10700,  6810,
    6915,  7020,  7125,  -725,  -725, 11184,  -725,  -725,  -725,  3503,
    6285, 11184,  6285, 11184,  3503,  6285, 11184,  -725,  6285, 11184,
    -725,  -725, 11184,  -725,   422,  5970,    25,  -725,   478,  -725,
    5760,  2155,  3503,  -725,    54, 10758, 11184,  6285,  -725, 11184,
    3503,  6285,  -725, 11184,  3503, 11184,  -725,   345,   254,   254,
    -725,  1124,  -725,    37,  -725,  7440,    77,  -725,  -725,  6285,
    6285,  6285,  6285,  6285,  6285,  6285,  6285,   805, 10337,  8303,
    8366, 10337,  8429,  8492,   438,    80,  6285,  6285,  4787,  -725,
    -725,    84,  5419,  -725,  -725,  6285,    23,  7630,  -725,   677,
     344,  -725,  6285,  8555,  -725,  8618,  -725,  -725,   478,  -725,
     416,   416,   229, 10821, 10879, 10942, 11000, 11063, 11121,  -725,
    3503,  3503,  3503,  3503,    25,  6075,    55,  -725,  -725, 11184,
   11184,  -725,  -725,  -725,  7125, 11184,  3503,  3503,    62,  -725,
    -725,  -725,  6285,  6285,  6285,  6285,  6285,  6285, 10337, 10337,
   10337, 10337,  -725,  -725,  -725,  -725,  -725,   307,  5760,  7309,
     680, 10337, 10337,  -725,  -725,  -725,  7688,  -725,  -725,  6180,
    -725
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,     1,    34,    69,   383,   384,   385,   386,
     387,     0,   342,    67,   121,   342,     0,   246,    67,     0,
       0,     0,     0,    67,    67,     0,     0,     0,     0,   139,
       0,   135,     0,     0,     0,     0,   333,     0,     0,     0,
       0,   245,   245,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,     0,     0,   432,   434,     0,
     435,   436,   367,     0,     0,   433,   430,    76,   431,     0,
       0,     0,     4,     0,     5,     9,     0,    10,    11,    12,
      14,   302,    19,    13,    77,    15,    17,    16,    18,    82,
       0,    80,   359,     0,    83,    81,    84,     0,   368,   355,
     356,   305,   303,     0,     0,   360,   361,     0,   304,     0,
     369,   370,   371,   354,   307,   306,   357,   358,     0,    21,
     313,     0,     0,   343,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   368,   303,   360,   361,   342,
     304,   369,   370,     0,     0,     0,     0,   293,     0,    71,
      70,   140,    85,     0,   141,     0,     0,     0,     0,     0,
       0,   293,     0,     0,     0,     0,     0,   248,    28,   418,
     352,     0,   419,     7,   293,   246,   247,    79,    78,   225,
     285,     0,   284,    74,     0,     0,     0,    73,    31,     0,
     308,     0,   293,    32,   314,   237,     0,     0,   284,     0,
       0,   421,   366,   417,   420,   416,    40,    42,     0,     0,
     288,     0,   290,     0,     0,   289,     0,   284,     0,     0,
       6,     0,   124,   213,   212,   142,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   293,   293,     0,     0,     0,
      22,    23,     0,    24,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,   302,   300,     0,   294,   295,   301,
       0,     0,     0,     0,     0,    94,     0,     0,    93,     0,
       0,   100,     0,     0,   110,     0,    27,   190,   136,   252,
       0,   253,   255,     0,   264,     0,   258,     0,     0,    29,
       0,   141,   224,     0,    51,    75,   114,    72,    30,   293,
       0,     0,   235,   232,    48,     0,     0,    87,    33,    41,
      43,   388,     0,     0,   380,     0,   382,     0,     0,     0,
       0,     0,   390,     8,     0,     0,     0,   208,     0,     0,
       0,     0,     0,   341,   413,   412,   415,   423,   422,   427,
     426,   409,   406,   407,   408,   363,   396,   379,   378,   377,
     364,   400,   411,   405,   403,   414,   404,   402,   394,   399,
     401,   410,   393,   397,   398,   395,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   425,   424,   429,   428,   202,   199,   200,
     201,   205,   206,   207,     0,     0,   345,     0,     0,     0,
       0,     0,     0,     0,     0,   389,   342,   342,    90,   233,
       0,     0,     0,   310,     0,   133,     0,   130,   234,   124,
       0,     0,     0,   317,     0,     0,     0,   323,     0,     0,
     101,   109,     0,     0,   309,     0,   191,     0,   198,   214,
       0,   256,     0,   268,     0,   263,   355,     0,   250,   353,
     249,   376,   287,   286,     0,     0,   311,   239,   355,     0,
       0,    44,     0,   362,   381,   291,   292,     0,     0,   106,
     327,     0,   391,     0,     0,   125,   126,   209,   210,   211,
     143,     0,     0,   241,   240,   242,   244,    52,    59,    60,
      61,    56,    58,    65,    66,    54,    57,    55,    53,    63,
      62,    64,   374,   375,   203,   204,   347,     0,   344,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,   299,   297,   298,   296,     0,   131,   129,     0,
       0,   108,     0,     0,    92,     0,    91,     0,     0,    98,
       0,     0,    96,     0,     0,     0,   112,   197,   189,     0,
     277,   215,   218,   217,   219,     0,   254,   257,   258,     0,
     259,   260,     0,     0,   113,   115,   312,   236,     0,    49,
       0,    50,     0,     0,     0,     0,   107,     0,    35,     0,
     245,   214,   172,   170,   175,   182,   183,   184,   179,   181,
     177,   180,   178,   176,   186,   185,   151,   154,   152,   153,
     164,   155,   168,   160,   158,   171,   159,   157,   162,   167,
     169,   156,   161,   165,   166,   163,   173,   174,   149,   187,
     187,   243,   346,   368,   368,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    88,   134,   132,   126,    95,     0,
       0,   316,     0,   315,     0,     0,   322,    99,     0,   321,
      97,   111,   332,   192,     0,     0,   258,   216,   230,   251,
       0,     0,     0,   117,     0,    46,    45,     0,   104,   329,
       0,     0,   102,   328,     0,   392,    36,    67,   245,   245,
     119,   245,   127,     0,   150,     0,   190,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   320,     0,
       0,   326,     0,     0,   277,   280,   281,   282,     0,   279,
     283,   355,   226,   194,   193,     0,     0,     0,   266,   355,
     118,   116,     0,     0,   105,     0,   103,   128,   230,   149,
     187,   187,     0,     0,     0,     0,     0,     0,     0,   120,
       0,     0,     0,     0,   258,   269,     0,   227,   229,   228,
     231,   222,   223,   137,     0,    47,     0,     0,     0,   147,
     148,   188,     0,     0,     0,     0,     0,     0,   319,   318,
     325,   324,   196,   195,   271,   272,   274,   355,     0,   389,
     355,   331,   330,   220,   144,   221,     0,   273,   275,   269,
     276
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -725,  -725,  -725,     1,  -610,  1738,  -725,  -725,  1315,    43,
     212,  -725,  -725,  -725,    75,  1764,    -4,   -95,  -706,  -598,
     -40,  -725,  -725,    78,  -725,  -725,  -725,  -725,  -725,   406,
     106,  -108,  -725,  -725,     6,   375,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -154,  -153,  -628,  -725,  -151,    -8,  -725,
    -266,  -725,  -725,   -45,  -725,  -221,     4,  -725,  -204,  -186,
    -725,  -136,  -725,  -725,  -725,  -161,   260,  -725,  -311,  -587,
    -454,  -337,  -498,  -724,  -160,     2,   114,  -725,  -120,  -725,
     132,   325,  -294,  -725,  -725,   665,  -725,    -9,  -129,  -725,
      40,  -725,   728,   979,   -11,  1022,  -725,  1042,  1358,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -261
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   207,    73,   471,    75,    76,    77,   208,
     500,    78,    79,    80,   150,    81,   154,   188,    82,    83,
      84,    85,    86,   557,    87,    88,   494,   605,    89,    90,
     366,   620,    91,   456,   457,   134,   163,   479,    93,    94,
     367,   621,   520,   659,   660,   727,   318,   475,   476,   477,
     478,   521,   225,   595,   824,   793,   180,   788,   753,   756,
      95,   196,   342,    96,    97,   166,   167,   322,   323,   488,
     326,   485,   815,   750,   696,   209,   213,   214,   296,   297,
     298,   135,    99,   100,   101,   136,   103,   122,   123,   435,
     436,   104,   137,   138,   107,   140,   109,   141,   142,   112,
     113,   218,   114,   115,   116,   117,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     120,   177,   178,    72,   497,   139,   126,   290,   145,   480,
     721,   699,   444,   434,   158,   159,   160,   301,   438,   151,
       5,     3,   722,   169,   170,     5,   171,   172,   598,   324,
     312,   486,   728,   182,   184,   185,   189,   190,   324,     5,
     194,   315,   324,   198,   199,   200,   181,   498,   201,     5,
     792,   202,   203,   204,   330,   205,   197,   578,   182,   215,
     217,   816,   305,   308,   311,   369,   370,   371,   372,   186,
     121,   573,   340,   216,   212,  -261,   329,     5,   186,   333,
    -197,   602,   333,   368,   700,   121,    45,   359,   124,   818,
     319,  -261,   792,   144,   338,   828,     5,   427,   327,   387,
    -261,   357,   143,   157,   347,   351,  -261,   361,   603,   754,
     487,   428,   445,   121,   429,  -261,   120,   284,   285,   286,
     194,   182,   217,   767,   612,    45,  -261,   721,   430,   431,
     289,   325,    14,   752,   173,   287,   299,   362,   432,   722,
     325,   698,   799,   800,   325,  -261,   388,   121,   320,   433,
     299,   295,   282,   164,   333,   421,   422,  -261,   333,   333,
    -261,   604,   282,   299,  -261,   295,  -261,   164,   328,  -278,
     597,   333,   331,   567,   282,    43,   282,   589,   295,   544,
     275,   299,   276,   282,   701,   823,   353,   355,  -278,   819,
      53,   282,  -278,   517,   448,  -338,   295,   813,   191,   568,
     352,   358,   518,  -373,   547,  -373,   545,   522,  -197,   350,
    -373,   147,  -373,   519,   354,   356,  -278,   470,   161,   495,
     373,   374,   375,   376,   378,   380,   381,   382,   383,   384,
     385,   386,   548,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   299,   299,   424,   426,   437,   768,
       5,   591,   333,   175,   149,   223,   226,   447,   694,   295,
     295,   434,   450,    23,   176,   333,   438,   587,   234,   174,
      29,  -348,  -138,   182,   224,   463,   465,   192,   467,   469,
     571,   333,   472,   592,   334,   -67,   461,   328,   227,  -335,
    -349,  -138,   593,   377,   379,   588,   489,   228,   221,  -348,
     344,   827,   493,   594,   -67,   235,   523,    98,   299,   236,
    -334,   830,   229,   587,   501,   501,    98,   492,  -349,   580,
     583,   230,   215,   295,   215,    98,   508,   510,     5,   512,
     513,   231,   149,   328,   182,   423,   425,   212,    98,   212,
     282,   801,   328,   607,   758,  -247,   446,   515,   241,   574,
     576,   243,   524,   579,   582,   246,    98,    92,   613,   615,
     328,   525,  -339,  -238,   608,   464,    92,     5,   468,  -340,
     608,   149,  -270,   328,    98,    92,   277,  -247,    98,   526,
     278,   751,  -238,   609,  -337,  -336,  -247,   759,    92,   611,
       5,  -270,   661,   281,   149,  -270,   152,   153,   550,   279,
     291,  -247,   278,   293,   300,   234,    92,  -247,   463,   553,
     467,   556,   472,   558,   510,   507,   304,   559,   560,  -270,
     562,   564,   317,   299,    92,   243,   339,    98,    92,   570,
     241,   572,  -372,   243,  -372,   577,   563,   246,   295,  -247,
     343,   451,   235,   452,   673,   674,   236,   505,  -247,   506,
     341,   363,   365,   217,   449,   678,   601,   454,   453,   153,
     458,   460,   473,  -247,   474,   687,   599,    98,   690,   487,
     481,   817,   482,   491,   496,   499,   514,    92,   511,   516,
     820,   238,   543,   239,   240,   241,   542,   242,   243,   566,
      14,    98,   246,    17,   584,   596,   333,   666,   552,   253,
     555,    22,   606,    23,   717,   817,   257,   258,   259,   669,
      29,   671,  -138,    98,  -262,   817,   437,    92,   378,   424,
     665,   695,   677,   668,   697,   710,   725,   726,    39,   714,
     718,  -138,   719,    43,   744,   675,   755,   619,   502,   234,
     302,    92,   681,  -262,   683,   569,    52,   686,    53,   737,
     689,   770,   771,   676,   692,   772,   723,   825,  -262,   693,
     812,   427,   798,    92,   784,  -262,   565,   662,   490,     0,
       0,     0,   182,     0,     0,   428,   235,   705,   429,   706,
     236,   709,     0,   713,  -262,   704,   715,    98,     0,   761,
       0,     0,   430,   431,     0,     0,     0,    67,     0,     0,
     350,     0,   432,  -262,   720,     0,   175,   377,   423,  -262,
       0,    98,     0,   433,    98,     0,    23,   176,    98,   241,
       0,   242,   243,    29,     0,  -138,   246,     0,     0,     0,
       0,   -39,     0,   253,     0,   681,   683,    92,   686,   689,
     709,   713,   259,     0,  -138,     0,     0,   102,   738,   739,
       0,   740,     0,   741,   742,     0,   102,   743,   177,   178,
       0,    92,     0,    98,    92,   102,     0,     0,    92,   757,
     510,     0,     0,     0,     0,     0,   763,     0,   102,   749,
     765,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -265,     0,     0,  -267,     0,   102,     0,   738,   773,
     774,   741,   775,   776,   777,   778,     0,     0,     0,     0,
     105,     0,     0,    92,   102,   190,   194,   217,   102,   105,
    -265,   789,     0,  -267,   790,     0,     0,     0,   105,     0,
     786,   795,     0,     0,     0,  -265,   787,     0,  -267,   546,
       0,   105,  -265,     0,     0,  -267,     0,     0,     0,   808,
     809,   810,   811,     0,     0,     0,     0,     0,     0,   105,
       0,  -265,     0,   713,  -267,   821,   822,   102,     0,   814,
       0,   808,   809,   810,   811,   821,   822,   105,    98,     0,
    -265,   105,     0,  -267,     0,     0,  -265,   826,   510,  -267,
       0,     0,     0,     0,     0,     0,     0,     0,   713,     0,
       0,    14,     0,   814,    17,     0,     0,   102,     0,     0,
     234,     0,    22,   814,    23,   717,    98,     0,     0,    98,
       0,    29,     0,  -138,     0,     0,     0,     0,    92,     0,
     105,   102,     0,     0,     0,     0,     0,     0,     0,    39,
       0,   718,  -138,   719,    43,     0,     0,   235,     0,     0,
       0,   236,     0,   102,   663,   664,     0,    52,     0,    53,
       0,     0,   234,     0,     0,     0,    92,     0,     0,    92,
     105,     0,     0,     0,     0,     0,     0,     0,    98,     0,
      98,     0,     0,    98,     0,     0,    98,     0,     0,    98,
     241,     0,   242,   243,   105,     0,     0,   246,     0,   235,
       0,     0,     0,   236,   253,     0,     0,    98,    67,     0,
       0,   257,   258,   259,     0,   779,   105,    98,     0,    98,
       0,     0,     0,     0,    98,     0,     0,   102,    92,     0,
      92,     0,     0,    92,     0,     0,    92,     0,   238,    92,
     239,   240,   241,     0,   242,   243,   244,     0,     0,   246,
       0,   102,     0,     0,   102,   252,   253,    92,   102,     0,
     256,   106,     0,   257,   258,   259,     0,    92,     0,    92,
     106,     0,     0,     0,    92,     0,     0,     0,     0,   106,
       0,     0,     0,     0,    98,     0,     0,     0,     0,    98,
     105,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   108,     0,     0,    98,     0,     0,
     106,     0,     0,   108,   105,    98,     0,   105,     0,    98,
       0,   105,   108,     0,   110,     0,   175,     0,   106,     0,
       0,     0,   106,   110,    92,   108,    23,   176,     0,    92,
       0,     0,   110,    29,     0,  -138,     0,     0,     0,     0,
       0,   -38,     0,   108,     0,   110,     0,    92,     0,     0,
       0,     0,     0,     0,  -138,    92,   105,     0,     0,    92,
       0,   108,     0,   110,     0,   108,     0,     0,     0,     0,
       0,   106,     0,     0,     0,    98,    98,    98,    98,     0,
       0,   110,     0,     0,     0,   110,     0,     0,     0,     0,
       0,    98,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,     0,     0,     0,     0,   102,     0,
      14,   106,     0,    17,   108,     0,     0,     0,     0,     0,
       0,    22,     0,    23,   717,    92,    92,    92,    92,     0,
      29,     0,  -138,     0,   110,   106,     0,     0,     0,     0,
     235,    92,    92,     0,   236,     0,   102,     0,   219,   102,
     718,  -138,   719,    43,   108,     0,     0,   106,     0,     0,
       0,     0,     0,     0,   237,     0,    52,     0,    53,     0,
       0,   105,     0,     0,   110,     0,     0,     0,   108,   238,
       0,   239,   240,   241,     0,   242,   243,   244,     0,   245,
     246,   247,   248,     0,   250,   251,   252,   253,   110,   254,
     108,   256,     0,     0,   257,   258,   259,     0,   102,   105,
     102,     0,   105,   102,     0,     0,   102,    67,     0,   102,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,     0,     0,     0,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,     0,   102,
       0,     0,     0,     0,   102,   106,     0,     0,   106,     0,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     0,   105,   108,     0,   105,     0,     0,   105,
       0,     0,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,   108,     0,
     105,   108,     0,     0,     0,   108,     0,   106,     0,     0,
     105,     0,   105,     0,   102,     0,     0,   105,   110,   102,
       0,   110,     0,     0,     0,   110,     0,   234,     0,     0,
     111,     0,   187,     0,     0,     0,     0,   102,     0,   111,
       0,     0,     0,     0,     0,   102,     0,     0,   111,   102,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,     0,   235,     0,     0,     0,   236,     0,
     110,     0,     0,     0,     0,     0,     0,   105,     0,   111,
       0,     0,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   111,     0,     0,
     105,   111,     0,   238,     0,   239,   240,   241,   105,   242,
     243,   283,   105,     0,   246,   102,   102,   102,   102,     0,
     252,   253,   106,     0,     0,   256,     0,     0,   257,   258,
     259,   102,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,   187,   187,   314,     0,     0,     0,     0,
     111,     0,   234,     0,     0,     0,   187,     0,     0,     0,
     106,     0,     0,   106,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,     0,   105,   105,
     105,   105,     0,     0,   187,   110,     0,     0,     0,   235,
     111,     0,     0,   236,   105,   105,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,   111,     0,     0,     0,     0,     0,
       0,     0,   106,   110,   106,     0,   110,   106,   238,     0,
     106,   240,   241,   106,   242,   243,   111,     0,     0,   246,
       0,     0,     0,     0,     0,     0,   253,     0,     0,     0,
       0,   106,     0,   257,   258,   259,     0,     0,     0,     0,
       0,   106,     0,   106,     0,   108,     0,   108,   106,     0,
     108,     0,     0,   108,   187,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   234,   110,     0,     0,
     110,     0,     0,   110,   108,     0,   110,   187,     0,     0,
       0,     0,     0,     0,   108,     0,   108,     0,     0,     0,
     111,   108,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,   235,   110,     0,   110,   236,   106,     0,
       0,   110,     0,   106,   111,     0,     0,   111,     0,     0,
       0,   111,     0,     0,     0,     0,     0,   237,     0,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     0,   106,
       0,     0,   238,   106,   239,   240,   241,     0,   242,   243,
     244,   108,   245,   246,   247,   248,   108,   250,   251,   252,
     253,     0,   254,   255,   256,     0,   111,   257,   258,   259,
       0,   110,     0,     0,   108,     0,   110,     0,     0,     0,
       0,     0,   108,     0,     0,     0,   108,     0,     0,     0,
      74,     0,     0,     0,   110,     0,     0,     0,     0,   119,
       0,     0,   110,     0,   234,     0,   110,     0,   146,   106,
     106,   106,   106,     0,     0,     0,     0,     0,     0,     0,
       0,   168,     0,     0,     0,   106,   106,   125,     0,   187,
     187,     0,   125,   187,   187,     0,   148,   125,   125,   193,
       0,   235,     0,     0,   162,   236,   165,     0,     0,     0,
       0,     0,   108,   108,   108,   108,     0,    74,     0,     0,
       0,   220,     0,     0,     0,     0,   195,     0,   108,   108,
       0,     0,   110,   110,   110,   110,     0,     0,     0,     0,
     238,   111,     0,     0,   241,     0,   242,   243,   110,   110,
       0,   246,     0,     0,     0,     0,     0,     0,   253,     0,
       0,     0,     0,     0,   222,   257,   258,   259,     0,     0,
     280,     0,     0,     0,     0,     0,     0,     0,     0,   111,
       0,     0,   111,     0,   187,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,   314,     0,     0,
       0,     0,   314,     0,     0,   187,     0,     0,   187,     0,
     316,     0,     0,     0,     0,     0,     0,   195,     0,     0,
       0,   294,     0,     0,     0,     0,     0,   195,     0,   303,
       0,     0,     0,     0,   337,   294,     0,     0,   321,     0,
       0,   111,     0,   111,     0,     0,   111,     0,   294,   111,
     125,     0,   111,   332,     0,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,   111,     0,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,   364,     0,     0,     0,     0,
     165,   165,   165,   165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   389,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
      74,     0,     0,     0,     0,     0,     0,     0,   234,     0,
       0,     0,     0,     0,     0,     0,     0,   111,     0,   294,
     294,     0,   111,     0,   337,     0,     0,   337,     0,     0,
       0,     0,     0,     0,   314,   314,     0,   314,   314,     0,
     111,     0,     0,     0,   455,   235,   459,     0,   111,   236,
       0,   791,   111,     0,     0,     0,     0,     0,   314,     0,
     314,     0,     0,     0,   321,     0,     0,     0,     0,     0,
       0,     0,   165,     0,     0,     0,   509,     0,     0,     0,
       0,     0,     0,   294,   238,     0,   239,   240,   241,     0,
     242,   243,   244,   791,   245,   246,   247,   248,     0,   250,
     251,   252,   253,     0,   254,     0,   256,     0,     0,   257,
     258,   259,   165,     0,     0,     0,     0,     0,   111,   111,
     111,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   111,   483,     0,     5,     6,
       7,     8,     9,    10,     0,  -389,     0,   127,     0,     0,
    -389,     0,     0,     0,     0,     0,     0,     0,  -389,     0,
      21,     0,     0,     0,     0,     0,   128,   129,   130,     0,
      28,     0,     0,     0,     0,    31,    32,     0,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,    38,     0,
      40,   586,     0,     0,     0,  -389,     0,     0,   294,  -389,
       0,     0,    48,    49,    50,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -389,
       0,   590,     0,     0,     0,   321,     0,     0,     0,   616,
       0,     0,    74,     0,  -389,    59,  -389,  -389,  -389,     0,
    -389,  -389,  -389,   195,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,    64,  -389,  -389,  -389,     0,     0,  -389,
    -389,  -389,     0,     0,   132,   658,    70,     0,   484,     0,
       0,     0,     0,   483,     0,     5,     6,     7,     8,     9,
      10,     0,     0,     0,   127,     0,     0,     0,     0,     0,
       0,   337,     0,   337,     0,     0,   337,    21,     0,   337,
       0,     0,   691,   128,   129,   130,     0,    28,     0,     0,
       0,   455,    31,    32,     0,    34,     0,    35,    36,     0,
     703,     0,     0,     0,     0,    38,     0,    40,     0,     0,
     708,     0,   712,   321,     0,     0,     0,    74,     0,    48,
      49,    50,   131,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,    61,     0,     0,     0,     0,    62,
       0,   724,     0,     0,     0,     0,     0,     0,    63,     0,
      64,     0,    65,    66,     0,     0,     0,     0,    68,     0,
       0,   132,     0,    70,     0,   484,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     760,     0,     0,     0,     0,     0,     0,     0,   764,     0,
       0,     0,   766,     0,     0,    -2,     4,     0,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
       0,    14,    15,    16,    17,  -245,    18,    19,     0,    20,
      21,   125,    22,     0,    23,    24,    25,    26,    27,   769,
      28,    29,     0,  -138,    30,    31,    32,    33,    34,   -37,
      35,    36,     0,    37,     0,     0,     0,  -245,    38,    39,
      40,    41,  -138,    42,    43,     0,  -245,    44,    45,     0,
      46,    47,    48,    49,    50,    51,     0,    52,     0,    53,
      54,  -245,     0,     0,    55,     0,    56,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,     0,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,    64,     0,    65,    66,     0,    67,     0,
       0,    68,     0,     0,    69,     0,    70,     4,    71,     5,
       6,     7,     8,     9,    10,     0,  -389,     0,    11,    12,
      13,  -389,    14,    15,    16,    17,  -245,    18,    19,  -389,
      20,    21,  -389,    22,     0,    23,    24,    25,    26,    27,
       0,    28,    29,     0,  -138,    30,    31,    32,    33,    34,
     -37,    35,    36,     0,    37,     0,     0,     0,  -245,    38,
       0,    40,    41,  -138,    42,    43,  -389,  -245,    44,    45,
    -389,    46,    47,    48,    49,    50,    51,     0,    52,     0,
      53,    54,  -245,     0,     0,    55,     0,    56,     0,     0,
    -389,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -389,    59,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,     0,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,    64,  -389,  -389,  -389,     0,    67,
    -389,  -389,  -389,     0,     0,    69,  -389,    70,     4,    71,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,     0,    14,    15,    16,    17,  -245,    18,    19,
       0,    20,    21,     0,    22,     0,    23,    24,    25,    26,
      27,     0,    28,    29,     0,  -138,    30,    31,    32,    33,
      34,   -37,    35,    36,     0,    37,     0,     0,     0,  -245,
      38,    39,    40,    41,  -138,    42,    43,     0,  -245,    44,
      45,     0,    46,    47,    48,    49,    50,    51,     0,    52,
       0,    53,    54,  -245,     0,     0,    55,     0,    56,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,    64,     0,    65,    66,   179,
      67,     0,     0,    68,     0,     0,    69,   206,    70,     4,
      71,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,    13,     0,    14,    15,    16,    17,  -245,    18,
      19,     0,    20,    21,     0,    22,     0,    23,    24,    25,
      26,    27,     0,    28,    29,     0,  -138,    30,    31,    32,
      33,    34,   -37,    35,    36,     0,    37,     0,     0,     0,
    -245,    38,    39,    40,    41,  -138,    42,    43,     0,  -245,
      44,    45,     0,    46,    47,    48,    49,    50,    51,     0,
      52,     0,    53,    54,  -245,     0,     0,    55,     0,    56,
       0,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    60,
      61,     0,     0,     0,     0,    62,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,    64,     0,    65,    66,
       0,    67,     0,     0,    68,     0,     0,    69,   349,    70,
       4,    71,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,     0,    14,    15,    16,    17,  -245,
      18,    19,     0,    20,    21,     0,    22,     0,    23,    24,
      25,    26,    27,     0,    28,    29,     0,  -138,    30,    31,
      32,    33,    34,   -37,    35,    36,     0,    37,     0,     0,
       0,  -245,    38,    39,    40,    41,  -138,    42,    43,     0,
    -245,    44,    45,     0,    46,    47,    48,    49,    50,    51,
       0,    52,     0,    53,    54,  -245,     0,     0,    55,     0,
      56,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,    64,     0,    65,
      66,     0,    67,     0,     0,    68,     0,     0,    69,   206,
      70,     4,    71,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    11,    12,    13,     0,    14,    15,    16,    17,
    -245,    18,    19,     0,    20,    21,     0,    22,     0,    23,
      24,    25,    26,    27,     0,    28,    29,     0,  -138,    30,
      31,    32,    33,    34,   -37,    35,    36,     0,    37,     0,
       0,     0,  -245,    38,    39,    40,    41,  -138,    42,    43,
       0,  -245,    44,    45,     0,    46,    47,    48,    49,    50,
      51,     0,    52,     0,    53,    54,  -245,     0,     0,    55,
       0,    56,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,    64,     0,
      65,    66,     0,    67,     0,     0,    68,     0,     0,    69,
     618,    70,     4,    71,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,     0,    14,    15,    16,
      17,  -245,    18,    19,     0,    20,    21,     0,    22,     0,
      23,    24,    25,    26,    27,     0,    28,    29,     0,  -138,
      30,    31,    32,    33,    34,   -37,    35,    36,     0,    37,
       0,     0,     0,  -245,    38,    39,    40,    41,  -138,    42,
      43,     0,  -245,    44,    45,     0,    46,    47,    48,    49,
      50,    51,     0,    52,     0,    53,    54,  -245,     0,     0,
      55,     0,    56,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,     0,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,    64,
       0,    65,    66,     0,    67,     0,     0,    68,     0,     0,
      69,   716,    70,     4,    71,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,    13,     0,    14,    15,
      16,    17,  -245,    18,    19,     0,    20,    21,     0,    22,
       0,    23,    24,    25,    26,    27,     0,    28,    29,     0,
    -138,    30,    31,    32,    33,    34,   -37,    35,    36,     0,
      37,     0,     0,     0,  -245,    38,   219,    40,    41,  -138,
      42,    43,     0,  -245,    44,    45,     0,    46,    47,    48,
      49,    50,    51,     0,    52,     0,    53,    54,  -245,     0,
       0,    55,     0,    56,     0,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,    61,     0,     0,     0,     0,    62,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
      64,     0,    65,    66,     0,    67,     0,     0,    68,     0,
       0,    69,     0,    70,     4,    71,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,     0,    14,
      15,    16,    17,  -245,    18,    19,     0,    20,    21,     0,
      22,     0,    23,    24,    25,    26,    27,     0,    28,    29,
       0,  -138,    30,    31,    32,    33,    34,   -37,    35,    36,
       0,    37,     0,     0,     0,  -245,    38,     0,    40,    41,
    -138,    42,    43,     0,  -245,    44,    45,     0,    46,    47,
      48,    49,    50,    51,     0,    52,     0,    53,    54,  -245,
       0,     0,    55,     0,    56,     0,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,     0,     0,     0,     0,
      62,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,    64,     0,    65,    66,     0,    67,     0,     0,    68,
       0,     0,    69,     0,    70,     4,    71,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,     0,
      14,    15,    16,    17,  -245,    18,    19,     0,    20,    21,
       0,    22,     0,    23,    24,    25,    26,   462,     0,    28,
      29,     0,  -138,    30,    31,    32,    33,    34,   -37,    35,
      36,     0,    37,     0,     0,     0,  -245,    38,     0,    40,
      41,  -138,    42,    43,     0,  -245,    44,    45,     0,    46,
      47,    48,    49,    50,    51,     0,    52,     0,    53,    54,
    -245,     0,     0,    55,     0,    56,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,     0,     0,     0,
       0,    62,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,    64,     0,    65,    66,     0,    67,     0,     0,
      68,     0,     0,    69,     0,    70,     4,    71,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
       0,    14,    15,    16,    17,  -245,    18,    19,     0,    20,
      21,     0,    22,     0,    23,    24,    25,    26,   466,     0,
      28,    29,     0,  -138,    30,    31,    32,    33,    34,   -37,
      35,    36,     0,    37,     0,     0,     0,  -245,    38,     0,
      40,    41,  -138,    42,    43,     0,  -245,    44,    45,     0,
      46,    47,    48,    49,    50,    51,     0,    52,     0,    53,
      54,  -245,     0,     0,    55,     0,    56,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,     0,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,    64,     0,    65,    66,     0,    67,     0,
       0,    68,     0,     0,    69,     0,    70,     4,    71,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
      13,     0,    14,    15,    16,    17,  -245,    18,    19,     0,
      20,    21,     0,    22,     0,    23,    24,    25,    26,   680,
       0,    28,    29,     0,  -138,    30,    31,    32,    33,    34,
     -37,    35,    36,     0,    37,     0,     0,     0,  -245,    38,
       0,    40,    41,  -138,    42,    43,     0,  -245,    44,    45,
       0,    46,    47,    48,    49,    50,    51,     0,    52,     0,
      53,    54,  -245,     0,     0,    55,     0,    56,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,    61,     0,
       0,     0,     0,    62,     0,     0,     0,     0,     0,     0,
       0,     0,    63,     0,    64,     0,    65,    66,     0,    67,
       0,     0,    68,     0,     0,    69,     0,    70,     4,    71,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,     0,    14,    15,    16,    17,  -245,    18,    19,
       0,    20,    21,     0,    22,     0,    23,    24,    25,    26,
     682,     0,    28,    29,     0,  -138,    30,    31,    32,    33,
      34,   -37,    35,    36,     0,    37,     0,     0,     0,  -245,
      38,     0,    40,    41,  -138,    42,    43,     0,  -245,    44,
      45,     0,    46,    47,    48,    49,    50,    51,     0,    52,
       0,    53,    54,  -245,     0,     0,    55,     0,    56,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,    64,     0,    65,    66,     0,
      67,     0,     0,    68,     0,     0,    69,     0,    70,     4,
      71,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,    13,     0,    14,    15,    16,    17,  -245,    18,
      19,     0,    20,    21,     0,    22,     0,    23,    24,    25,
      26,   685,     0,    28,    29,     0,  -138,    30,    31,    32,
      33,    34,   -37,    35,    36,     0,    37,     0,     0,     0,
    -245,    38,     0,    40,    41,  -138,    42,    43,     0,  -245,
      44,    45,     0,    46,    47,    48,    49,    50,    51,     0,
      52,     0,    53,    54,  -245,     0,     0,    55,     0,    56,
       0,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    60,
      61,     0,     0,     0,     0,    62,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,    64,     0,    65,    66,
       0,    67,     0,     0,    68,     0,     0,    69,     0,    70,
       4,    71,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,     0,    14,    15,    16,    17,  -245,
      18,    19,     0,    20,    21,     0,    22,     0,    23,    24,
      25,    26,   688,     0,    28,    29,     0,  -138,    30,    31,
      32,    33,    34,   -37,    35,    36,     0,    37,     0,     0,
       0,  -245,    38,     0,    40,    41,  -138,    42,    43,     0,
    -245,    44,    45,     0,    46,    47,    48,    49,    50,    51,
       0,    52,     0,    53,    54,  -245,     0,     0,    55,     0,
      56,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,    64,     0,    65,
      66,     0,    67,     0,     0,    68,     0,     0,    69,     0,
      70,     4,    71,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    11,    12,    13,     0,    14,    15,    16,    17,
    -245,    18,    19,     0,   702,    21,     0,    22,     0,    23,
      24,    25,    26,    27,     0,    28,    29,     0,  -138,    30,
      31,    32,    33,    34,   -37,    35,    36,     0,    37,     0,
       0,     0,  -245,    38,     0,    40,    41,  -138,    42,    43,
       0,  -245,    44,    45,     0,    46,    47,    48,    49,    50,
      51,     0,    52,     0,    53,    54,  -245,     0,     0,    55,
       0,    56,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,    64,     0,
      65,    66,     0,    67,     0,     0,    68,     0,     0,    69,
       0,    70,     4,    71,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,     0,    14,    15,    16,
      17,  -245,    18,    19,     0,    20,    21,     0,    22,     0,
      23,    24,    25,    26,   707,     0,    28,    29,     0,  -138,
      30,    31,    32,    33,    34,   -37,    35,    36,     0,    37,
       0,     0,     0,  -245,    38,     0,    40,    41,  -138,    42,
      43,     0,  -245,    44,    45,     0,    46,    47,    48,    49,
      50,    51,     0,    52,     0,    53,    54,  -245,     0,     0,
      55,     0,    56,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,     0,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,    64,
       0,    65,    66,     0,    67,     0,     0,    68,     0,     0,
      69,     0,    70,     4,    71,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,    13,     0,    14,    15,
      16,    17,  -245,    18,    19,     0,    20,    21,     0,    22,
       0,    23,    24,    25,    26,   711,     0,    28,    29,     0,
    -138,    30,    31,    32,    33,    34,   -37,    35,    36,     0,
      37,     0,     0,     0,  -245,    38,     0,    40,    41,  -138,
      42,    43,     0,  -245,    44,    45,     0,    46,    47,    48,
      49,    50,    51,     0,    52,     0,    53,    54,  -245,     0,
       0,    55,     0,    56,     0,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,    61,     0,     0,     0,     0,    62,
       5,     6,     7,     8,     9,    10,     0,     0,    63,   127,
      64,     0,    65,    66,     0,    67,     0,     0,    68,     0,
       0,    69,    21,    70,     0,    71,     0,     0,   128,   129,
     130,     0,    28,     0,     0,     0,     0,    31,    32,     0,
      34,     0,    35,    36,     0,     0,     0,     0,     0,     0,
      38,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    50,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
       0,     0,     0,     0,    62,     5,     6,     7,     8,     9,
      10,     0,     0,    63,   127,    64,     0,    65,    66,   179,
       0,     0,   427,    68,     0,     0,   132,    21,    70,     0,
     133,   785,     0,   128,   129,   130,   428,    28,     0,   429,
       0,     0,    31,    32,     0,    34,     0,    35,    36,     0,
       0,     0,     0,   430,   431,    38,     0,    40,     0,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,    48,
      49,    50,   131,     0,   433,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,    61,     0,     0,     0,     0,    62,
       5,     6,     7,     8,     9,    10,     0,     0,    63,   127,
      64,     0,    65,    66,     0,     0,     0,     0,    68,     0,
       0,   132,    21,    70,     0,   133,     0,     0,   128,   129,
     130,     0,    28,     0,     0,     0,     0,    31,    32,     0,
      34,     0,    35,    36,     0,     0,     0,     0,     0,     0,
      38,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    50,   131,     0,     0,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
       0,     0,     0,     0,    62,   211,     0,     5,     6,     7,
       8,     9,    10,    63,     0,    64,   127,    65,    66,   179,
       0,     0,     0,    68,     0,     0,   132,     0,    70,    21,
     133,     0,     0,     0,     0,   128,   129,   130,     0,    28,
       0,     0,     0,     0,    31,    32,     0,    34,     0,    35,
      36,     0,     0,     0,     0,     0,     0,    38,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,   131,     0,     0,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,     0,     0,     0,
       0,    62,     5,     6,     7,     8,     9,    10,     0,     0,
      63,   127,    64,     0,    65,    66,   179,     0,     0,     0,
      68,     0,     0,   132,    21,    70,   504,   133,     0,     0,
     128,   129,   130,     0,    28,     0,     0,     0,     0,    31,
      32,     0,    34,     0,    35,    36,     0,     0,     0,     0,
       0,   155,    38,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,     0,     0,     0,     0,    62,     5,     6,     7,
       8,     9,    10,     0,     0,    63,   127,    64,     0,    65,
      66,     0,     0,     0,     0,    68,     0,     0,   132,    21,
      70,     0,   133,     0,     0,   128,   129,   130,     0,    28,
       0,     0,     0,     0,    31,    32,     0,    34,     0,    35,
      36,     0,     0,     0,     0,     0,     0,    38,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,   131,     0,     0,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,     0,     0,     0,
       0,    62,     5,     6,     7,     8,     9,    10,     0,     0,
      63,   127,    64,     0,    65,    66,   179,     0,     0,     0,
      68,     0,     0,   132,    21,    70,     0,   133,     0,     0,
     128,   129,   130,     0,    28,     0,     0,     0,     0,    31,
      32,     0,    34,     0,    35,    36,     0,     0,     0,     0,
       0,     0,    38,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,     0,     0,     0,     0,    62,     5,     6,     7,
       8,     9,    10,     0,     0,    63,   127,    64,     0,    65,
      66,   179,     0,     0,     0,    68,     0,     0,   132,    21,
      70,     0,   133,     0,     0,   128,   129,   130,     0,    28,
       0,     0,     0,     0,    31,    32,     0,    34,     0,    35,
      36,     0,     0,     0,     0,     0,     0,    38,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,     0,     0,     0,
       0,    62,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,    64,     0,    65,    66,     0,   183,     0,     0,
      68,     0,     0,   132,     0,    70,     0,   133,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   186,
      21,     0,     0,     0,     0,     0,   128,   129,   130,     0,
      28,     0,     0,     0,     0,    31,    32,     0,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,    38,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,     0,     0,
       0,     0,    62,     5,     6,     7,     8,     9,    10,     0,
       0,    63,   127,    64,     0,    65,    66,     0,     0,     0,
       0,    68,     0,     0,    69,    21,    70,     0,   133,     0,
       0,   128,   129,   130,     0,    28,     0,     0,     0,     0,
      31,    32,     0,    34,     0,    35,    36,     0,     0,     0,
       0,     0,     0,    38,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,     0,     0,     0,     0,    62,     5,     6,
       7,     8,     9,    10,     0,     0,    63,   127,    64,     0,
      65,    66,     0,     0,     0,     0,    68,     0,     0,   132,
      21,    70,     0,   133,     0,     0,   128,   129,   130,     0,
      28,     0,     0,     0,     0,    31,    32,     0,    34,     0,
      35,    36,   600,     0,     0,     0,     0,     0,    38,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,     0,     0,
       0,     0,    62,     5,     6,     7,     8,     9,    10,     0,
       0,    63,   127,    64,     0,    65,    66,     0,     0,     0,
       0,    68,     0,     0,   132,   745,    70,     0,   133,     0,
       0,   128,   129,   130,     0,    28,     0,     0,     0,     0,
      31,    32,     0,    34,     0,    35,    36,     0,     0,     0,
       0,     0,     0,    38,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   746,    49,    50,
     747,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,     0,     0,     0,     0,    62,     5,     6,
       7,     8,     9,    10,     0,     0,    63,   127,    64,     0,
      65,    66,   179,     0,     0,     0,    68,     0,     0,   132,
      21,    70,     0,   748,     0,     0,   128,   129,   130,     0,
      28,     0,     0,     0,     0,    31,    32,     0,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,    38,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,     0,     0,
       0,     0,    62,     5,     6,     7,     8,     9,    10,     0,
       0,    63,   127,    64,     0,    65,    66,   179,     0,     0,
       0,    68,     0,     0,   132,    21,    70,     0,   748,     0,
       0,   128,   129,   736,     0,    28,     0,     0,     0,     0,
      31,    32,     0,    34,     0,    35,    36,     0,     0,     0,
       0,     0,     0,    38,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,     0,     0,     0,     0,    62,     5,     6,
       7,     8,     9,    10,     0,     0,    63,   127,    64,     0,
      65,    66,   179,     0,     0,     0,    68,     0,     0,   132,
      21,    70,     0,   133,     0,     0,   128,   129,   130,     0,
      28,     0,     0,     0,     0,    31,    32,     0,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,    38,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,     0,     0,
       0,     0,    62,     5,     6,     7,     8,     9,    10,     0,
       0,    63,   127,    64,     0,    65,    66,     0,     0,     0,
       0,    68,     0,     0,   132,    21,    70,     0,   133,     0,
       0,   128,   129,   551,     0,    28,     0,     0,     0,     0,
      31,    32,     0,    34,     0,    35,    36,     0,     0,     0,
       0,     0,     0,    38,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,     0,     0,     0,     0,    62,     5,     6,
       7,     8,     9,    10,     0,     0,    63,   127,    64,     0,
      65,    66,     0,     0,     0,     0,    68,     0,     0,   132,
      21,    70,     0,   133,     0,     0,   128,   129,   554,     0,
      28,     0,     0,     0,     0,    31,    32,     0,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,    38,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,     0,     0,
       0,     0,    62,     5,     6,     7,     8,     9,    10,     0,
       0,    63,   127,    64,     0,    65,    66,     0,     0,     0,
       0,    68,     0,     0,   132,    21,    70,     0,   133,     0,
       0,   128,   129,   730,     0,    28,     0,     0,     0,     0,
      31,    32,     0,    34,     0,    35,    36,     0,     0,     0,
       0,     0,     0,    38,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,     0,     0,     0,     0,    62,     5,     6,
       7,     8,     9,    10,     0,     0,    63,   127,    64,     0,
      65,    66,     0,     0,     0,     0,    68,     0,     0,   132,
      21,    70,     0,   133,     0,     0,   128,   129,   731,     0,
      28,     0,     0,     0,     0,    31,    32,     0,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,    38,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,     0,     0,
       0,     0,    62,     5,     6,     7,     8,     9,    10,     0,
       0,    63,   127,    64,     0,    65,    66,     0,     0,     0,
       0,    68,     0,     0,   132,    21,    70,     0,   133,     0,
       0,   128,   129,   733,     0,    28,     0,     0,     0,     0,
      31,    32,     0,    34,     0,    35,    36,     0,     0,     0,
       0,     0,     0,    38,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,     0,     0,     0,     0,    62,     5,     6,
       7,     8,     9,    10,     0,     0,    63,   127,    64,     0,
      65,    66,     0,     0,     0,     0,    68,     0,     0,   132,
      21,    70,     0,   133,     0,     0,   128,   129,   734,     0,
      28,     0,     0,     0,     0,    31,    32,     0,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,    38,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,     0,     0,
       0,     0,    62,     5,     6,     7,     8,     9,    10,     0,
       0,    63,   127,    64,     0,    65,    66,     0,     0,     0,
       0,    68,     0,     0,   132,    21,    70,     0,   133,     0,
       0,   128,   129,   735,     0,    28,     0,     0,     0,     0,
      31,    32,     0,    34,     0,    35,    36,     0,     0,     0,
       0,     0,     0,    38,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,     0,     0,     0,     0,    62,     5,     6,
       7,     8,     9,    10,     0,     0,    63,   127,    64,     0,
      65,    66,     0,     0,     0,     0,    68,     0,     0,   132,
      21,    70,     0,   133,     0,     0,   128,   129,   736,     0,
      28,     0,     0,     0,     0,    31,    32,     0,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,    38,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,     0,     0,
       0,     0,    62,     5,     6,     7,     8,     9,    10,     0,
       0,    63,   127,    64,     0,    65,    66,     0,     0,     0,
       0,    68,     0,     0,   132,    21,    70,     0,   133,     0,
       0,   128,   129,   130,     0,    28,     0,     0,     0,     0,
      31,    32,     0,    34,     0,    35,    36,     0,     0,     0,
       0,     0,     0,    38,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,     0,    21,     0,     0,     0,     0,     0,
     128,   129,   130,     0,    28,     0,    63,     0,    64,    31,
      32,    66,    34,     0,    35,    36,    68,     0,     0,   132,
       0,    70,    38,   133,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,   131,
       0,     0,     5,     6,     7,     8,     9,    10,     0,   234,
       0,   127,     0,     0,  -269,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,    59,
     128,   129,   130,  -269,    28,     0,     0,  -269,     0,    31,
      32,     0,    34,     0,    35,    36,   235,    64,     0,     0,
     236,   179,    38,     0,    40,     0,     0,     0,   132,     0,
      70,  -269,   748,     5,     0,     0,    48,    49,    50,   131,
     622,     0,     0,     0,     0,   623,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,   239,   240,   241,
       0,   242,   243,   244,     0,     0,   246,   247,   248,    59,
     250,   251,   252,   253,     0,     0,     0,   256,     0,     0,
     257,   258,   259,     0,     0,     0,     0,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,   133,     0,     0,     0,     0,     0,     0,   232,
       0,     0,     0,     0,   233,   624,   625,   626,   627,   628,
     629,     0,   234,   630,   631,   632,   633,   634,   635,   636,
     637,   638,   639,     0,     0,   640,     0,     0,     0,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   650,   651,
       0,   652,     0,     0,   653,   654,   655,   656,   657,   235,
       0,     0,     0,   236,     0,     0,     0,   232,     0,     0,
       0,     0,   233,     0,     0,     0,     0,     0,     0,   121,
     234,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
     239,   240,   241,     0,   242,   243,   244,     0,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   235,   254,   255,
     256,   236,     0,   257,   258,   259,     0,     0,     0,     0,
     232,     0,     0,   614,     0,   233,     0,     0,     0,     0,
       0,   237,     0,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   238,     0,   239,   240,
     241,     0,   242,   243,   244,     0,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,   254,   255,   256,     0,
     235,   257,   258,   259,   236,     0,     0,     0,   232,     0,
       0,   672,     0,   233,     0,     0,     0,     0,     0,     0,
       0,   234,     0,     0,   237,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,   239,   240,   241,     0,   242,   243,   244,     0,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   235,   254,
     255,   256,   236,     0,   257,   258,   259,     0,     0,     0,
       0,   232,     0,     0,   794,     0,   233,     0,     0,     0,
       0,     0,   237,     0,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,   239,
     240,   241,     0,   242,   243,   244,     0,   245,   246,   247,
     248,   249,   250,   251,   252,   253,     0,   254,   255,   256,
       0,   235,   257,   258,   259,   236,     0,     0,     0,   232,
       0,     0,   829,     0,   233,     0,     0,     0,     0,     0,
       0,     0,   234,   309,     0,   237,     0,     0,     0,     0,
       0,     0,     0,   310,     0,     0,     0,     0,     0,     0,
     238,     0,   239,   240,   241,     0,   242,   243,   244,     0,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   235,
     254,   255,   256,   236,     0,   257,   258,   259,     0,     0,
       0,     0,   232,   503,     0,     0,     0,   233,     0,   121,
       0,     0,     0,   237,     0,   234,   306,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   307,     0,   238,     0,
     239,   240,   241,     0,   242,   243,   244,     0,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,   254,   255,
     256,     0,   235,   257,   258,   259,   236,     0,   282,     0,
     232,     0,     0,     0,     0,   233,     0,     0,     0,     0,
       0,     0,     0,   234,   581,     0,   237,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,   239,   240,   241,     0,   242,   243,   244,
       0,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     235,   254,   255,   256,   236,     0,   257,   258,   259,     0,
       0,   282,     0,   232,     0,     0,     0,     0,   233,     0,
     121,     0,     0,     0,   237,     0,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,   239,   240,   241,     0,   242,   243,   244,     0,   245,
     246,   247,   248,   249,   250,   251,   252,   253,     0,   254,
     255,   256,     0,   235,   257,   258,   259,   236,     0,   282,
       0,   232,     0,     0,   313,     0,   233,     0,     0,     0,
       0,     0,     0,     0,   234,   186,     0,   237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,   239,   240,   241,     0,   242,   243,
     244,     0,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   235,   254,   255,   256,   236,     0,   257,   258,   259,
       0,     0,   282,     0,   232,     0,     0,     0,     0,   233,
       0,     0,     0,     0,     0,   237,     0,   234,   575,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,   239,   240,   241,     0,   242,   243,   244,     0,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     0,
     254,   255,   256,     0,   235,   257,   258,   259,   236,     0,
     282,     0,     0,     0,     0,     0,     0,   232,     0,     0,
       0,     0,   233,     0,     0,     0,     0,     0,   237,     0,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,     0,   239,   240,   241,     0,   242,
     243,   244,     0,   245,   246,   247,   248,   249,   250,   251,
     252,   253,     0,   254,   255,   256,     0,   235,   257,   258,
     259,   236,     0,   282,     0,     0,     0,     0,   679,     0,
     232,     0,     0,     0,     0,   233,     0,     0,     0,     0,
       0,   237,     0,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   238,     0,   239,   240,
     241,     0,   242,   243,   244,     0,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,   254,   255,   256,     0,
     235,   257,   258,   259,   236,     0,   282,     0,     0,     0,
       0,   684,     0,   232,     0,     0,     0,     0,   233,     0,
       0,     0,     0,     0,   237,     0,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,   239,   240,   241,     0,   242,   243,   244,     0,   245,
     246,   247,   248,   249,   250,   251,   252,   253,     0,   254,
     255,   256,     0,   235,   257,   258,   259,   236,     0,   282,
       0,     0,     0,     0,   780,     0,   232,     0,     0,     0,
       0,   233,     0,     0,     0,     0,     0,   237,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,   239,   240,   241,     0,   242,   243,
     244,     0,   245,   246,   247,   248,   249,   250,   251,   252,
     253,     0,   254,   255,   256,     0,   235,   257,   258,   259,
     236,     0,   282,     0,     0,     0,     0,   781,     0,   232,
       0,     0,     0,     0,   233,     0,     0,     0,     0,     0,
     237,     0,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,   239,   240,   241,
       0,   242,   243,   244,     0,   245,   246,   247,   248,   249,
     250,   251,   252,   253,     0,   254,   255,   256,     0,   235,
     257,   258,   259,   236,     0,   282,     0,     0,     0,     0,
     782,     0,   232,     0,     0,     0,     0,   233,     0,     0,
       0,     0,     0,   237,     0,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
     239,   240,   241,     0,   242,   243,   244,     0,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,   254,   255,
     256,     0,   235,   257,   258,   259,   236,     0,   282,     0,
       0,     0,     0,   783,     0,   232,     0,     0,     0,     0,
     233,     0,     0,     0,     0,     0,   237,     0,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,   239,   240,   241,     0,   242,   243,   244,
       0,   245,   246,   247,   248,   249,   250,   251,   252,   253,
       0,   254,   255,   256,     0,   235,   257,   258,   259,   236,
       0,   282,     0,     0,     0,     0,   796,     0,   232,     0,
       0,     0,     0,   233,     0,     0,     0,     0,     0,   237,
       0,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,     0,   239,   240,   241,     0,
     242,   243,   244,     0,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     0,   254,   255,   256,     0,   235,   257,
     258,   259,   236,     0,   282,     0,   232,     0,     0,   797,
       0,   233,     0,     0,     0,     0,     0,     0,     0,   234,
       0,     0,   237,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,   239,
     240,   241,     0,   242,   243,   244,     0,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   235,   254,   255,   256,
     236,     0,   257,   258,   259,     0,     0,   282,     0,   232,
       0,     0,     0,     0,   233,     0,     0,     0,     0,     0,
     237,     0,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,   239,   240,   241,
       0,   242,   243,   244,     0,   245,   246,   247,   248,   249,
     250,   251,   252,   253,     0,   254,   255,   256,     0,   235,
     257,   258,   259,   236,     0,   336,     0,   232,     0,     0,
       0,     0,   233,     0,     0,     0,     0,     0,     0,     0,
     234,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,   288,     0,     0,     0,     0,     0,     0,   238,     0,
     239,   240,   241,     0,   242,   243,   244,     0,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   235,   254,   255,
     256,   236,     0,   257,   258,   259,     0,  -351,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   238,     0,   239,   240,
     241,     0,   242,   243,   244,     0,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   232,   254,   255,   256,     0,
     233,   257,   258,   259,     0,     0,     0,     0,   234,     0,
       0,     0,     0,   345,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,     0,     0,
       0,     0,     0,     0,   346,     0,     0,     0,     0,   232,
       0,     0,     0,     0,   233,   235,     0,     0,     0,   236,
       0,     0,   234,   439,     0,     0,   274,  -350,     0,     0,
    -372,     0,  -372,   440,     0,     0,     0,     0,     0,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,     0,   239,   240,   241,   235,
     242,   243,   244,   236,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     0,   254,   255,   256,     0,     0,   257,
     258,   259,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
     239,   240,   241,     0,   242,   243,   244,     0,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   232,   254,   255,
     256,     0,   233,   257,   258,   259,     0,     0,     0,     0,
     234,   441,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   442,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,     0,     0,     0,     0,   233,     0,     0,     0,
       0,     0,     0,     0,   234,     0,     0,   235,     0,     0,
       0,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   232,     0,     0,     0,     0,
     233,   237,     0,     0,     0,     0,     0,     0,   234,     0,
       0,   235,     0,     0,     0,   236,   238,     0,   239,   240,
     241,     0,   242,   243,   244,     0,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   237,   254,   255,   256,     0,
       0,   257,   258,   259,     0,   235,     0,     0,     0,   236,
     238,     0,   239,   240,   241,     0,   242,   243,   244,     0,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   237,
     254,   255,   256,     0,   292,   257,   258,   259,     0,     0,
     232,     0,     0,     0,   238,   233,   239,   240,   241,     0,
     242,   243,   244,   234,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     0,   254,   255,   256,     0,   335,   257,
     258,   259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,     0,     0,     0,     0,   233,
     235,     0,     0,     0,   236,     0,     0,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,   239,   240,   241,   235,   242,   243,   244,   236,   245,
     246,   247,   248,   249,   250,   251,   252,   253,     0,   254,
     255,   256,     0,   348,   257,   258,   259,   360,   237,   232,
       0,     0,     0,     0,   233,     0,     0,     0,     0,     0,
       0,     0,   234,   238,     0,   239,   240,   241,     0,   242,
     243,   244,     0,   245,   246,   247,   248,   249,   250,   251,
     252,   253,     0,   254,   255,   256,     0,     0,   257,   258,
     259,     0,     0,   232,     0,     0,     0,     0,   233,   235,
       0,     0,     0,   236,     0,     0,   234,     0,     0,     0,
     443,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
     239,   240,   241,   235,   242,   243,   244,   236,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,   254,   255,
     256,   232,     0,   257,   258,   259,   233,   237,     0,     0,
       0,     0,     0,     0,   234,     0,     0,     0,     0,     0,
       0,     0,   238,     0,   239,   240,   241,     0,   242,   243,
     244,     0,   245,   246,   247,   248,   249,   250,   251,   252,
     253,     0,   254,   255,   256,   232,   527,   257,   258,   259,
     233,   235,     0,     0,     0,   236,     0,     0,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,   239,   240,   241,   235,   242,   243,   244,   236,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     0,
     254,   255,   256,   232,   528,   257,   258,   259,   233,   237,
       0,     0,     0,     0,     0,     0,   234,     0,     0,     0,
       0,     0,     0,     0,   238,     0,   239,   240,   241,     0,
     242,   243,   244,     0,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     0,   254,   255,   256,   232,   529,   257,
     258,   259,   233,   235,     0,     0,     0,   236,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,   239,   240,   241,   235,   242,   243,
     244,   236,   245,   246,   247,   248,   249,   250,   251,   252,
     253,     0,   254,   255,   256,   232,   530,   257,   258,   259,
     233,   237,     0,     0,     0,     0,     0,     0,   234,     0,
       0,     0,     0,     0,     0,     0,   238,     0,   239,   240,
     241,     0,   242,   243,   244,     0,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,   254,   255,   256,   232,
     531,   257,   258,   259,   233,   235,     0,     0,     0,   236,
       0,     0,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,     0,   239,   240,   241,   235,
     242,   243,   244,   236,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     0,   254,   255,   256,   232,   532,   257,
     258,   259,   233,   237,     0,     0,     0,     0,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,   238,     0,
     239,   240,   241,     0,   242,   243,   244,     0,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,   254,   255,
     256,   232,   533,   257,   258,   259,   233,   235,     0,     0,
       0,   236,     0,     0,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   238,     0,   239,   240,
     241,   235,   242,   243,   244,   236,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,   254,   255,   256,   232,
     534,   257,   258,   259,   233,   237,     0,     0,     0,     0,
       0,     0,   234,     0,     0,     0,     0,     0,     0,     0,
     238,     0,   239,   240,   241,     0,   242,   243,   244,     0,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     0,
     254,   255,   256,   232,   535,   257,   258,   259,   233,   235,
       0,     0,     0,   236,     0,     0,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
     239,   240,   241,   235,   242,   243,   244,   236,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,   254,   255,
     256,   232,   536,   257,   258,   259,   233,   237,     0,     0,
       0,     0,     0,     0,   234,     0,     0,     0,     0,     0,
       0,     0,   238,     0,   239,   240,   241,     0,   242,   243,
     244,     0,   245,   246,   247,   248,   249,   250,   251,   252,
     253,     0,   254,   255,   256,   232,   537,   257,   258,   259,
     233,   235,     0,     0,     0,   236,     0,     0,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,   239,   240,   241,   235,   242,   243,   244,   236,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     0,
     254,   255,   256,   232,   538,   257,   258,   259,   233,   237,
       0,     0,     0,     0,     0,     0,   234,     0,     0,     0,
       0,     0,     0,     0,   238,     0,   239,   240,   241,     0,
     242,   243,   244,     0,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     0,   254,   255,   256,   232,   539,   257,
     258,   259,   233,   235,     0,     0,     0,   236,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,   239,   240,   241,   235,   242,   243,
     244,   236,   245,   246,   247,   248,   249,   250,   251,   252,
     253,     0,   254,   255,   256,   232,   540,   257,   258,   259,
     233,   237,     0,     0,     0,     0,     0,     0,   234,     0,
       0,     0,     0,     0,     0,     0,   238,     0,   239,   240,
     241,     0,   242,   243,   244,     0,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,   254,   255,   256,   232,
     541,   257,   258,   259,   233,   235,     0,     0,     0,   236,
       0,     0,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,     0,   239,   240,   241,   235,
     242,   243,   244,   236,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     0,   254,   255,   256,   232,     0,   257,
     258,   259,   233,   237,     0,     0,     0,     0,     0,     0,
     234,     0,     0,   585,     0,     0,     0,     0,   238,     0,
     239,   240,   241,     0,   242,   243,   244,     0,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,   254,   255,
     256,     0,   561,   257,   258,   259,     0,   235,     0,     0,
       0,   236,     0,     0,     0,   232,   610,     0,     0,     0,
     233,     0,     0,     0,     0,     0,     0,     0,   234,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   238,     0,   239,   240,
     241,     0,   242,   243,   244,     0,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   235,   254,   255,   256,   236,
       0,   257,   258,   259,     0,     0,     0,     0,   232,     0,
       0,     0,     0,   233,     0,     0,     0,     0,     0,   237,
       0,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,     0,   239,   240,   241,     0,
     242,   243,   244,     0,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     0,   254,   255,   256,     0,   235,   257,
     258,   259,   236,     0,     0,     0,   232,     0,     0,     0,
       0,   233,     0,     0,     0,     0,     0,     0,     0,   234,
     667,   617,   237,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,   239,
     240,   241,     0,   242,   243,   244,     0,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   235,   254,   255,   256,
     236,     0,   257,   258,   259,     0,     0,     0,     0,   232,
       0,     0,     0,     0,   233,     0,     0,     0,     0,     0,
     237,     0,   234,   670,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,   239,   240,   241,
       0,   242,   243,   244,     0,   245,   246,   247,   248,   249,
     250,   251,   252,   253,     0,   254,   255,   256,     0,   235,
     257,   258,   259,   236,     0,     0,     0,   232,     0,     0,
       0,     0,   233,     0,     0,     0,     0,     0,     0,     0,
     234,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
     239,   240,   241,     0,   242,   243,   244,     0,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   235,   254,   255,
     256,   236,     0,   257,   258,   259,     0,     0,   729,     0,
     232,     0,     0,     0,     0,   233,     0,     0,     0,     0,
       0,   237,     0,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   238,     0,   239,   240,
     241,     0,   242,   243,   244,     0,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,   254,   255,   256,     0,
     235,   257,   258,   259,   236,     0,     0,     0,   232,   762,
       0,   732,     0,   233,     0,     0,     0,     0,     0,     0,
       0,   234,     0,     0,   237,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,   239,   240,   241,     0,   242,   243,   244,     0,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   235,   254,
     255,   256,   236,     0,   257,   258,   259,     0,     0,     0,
       0,   232,     0,     0,     0,     0,   233,     0,     0,     0,
       0,     0,   237,     0,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,   239,
     240,   241,     0,   242,   243,   244,     0,   245,   246,   247,
     248,   249,   250,   251,   252,   253,     0,   254,   255,   256,
       0,   235,   257,   258,   259,   236,     0,     0,     0,   232,
       0,     0,   802,     0,   233,     0,     0,     0,     0,     0,
       0,     0,   234,     0,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,   239,   240,   241,     0,   242,   243,   244,     0,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   235,
     254,   255,   256,   236,     0,   257,   258,   259,     0,     0,
     803,     0,   232,     0,     0,     0,     0,   233,     0,     0,
       0,     0,     0,   237,     0,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
     239,   240,   241,     0,   242,   243,   244,     0,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,   254,   255,
     256,     0,   235,   257,   258,   259,   236,     0,     0,     0,
     232,     0,     0,   804,     0,   233,     0,     0,     0,     0,
       0,     0,     0,   234,     0,     0,   237,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,   239,   240,   241,     0,   242,   243,   244,
       0,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     235,   254,   255,   256,   236,     0,   257,   258,   259,     0,
       0,   805,     0,   232,     0,     0,     0,     0,   233,     0,
       0,     0,     0,     0,   237,     0,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,   239,   240,   241,     0,   242,   243,   244,     0,   245,
     246,   247,   248,   249,   250,   251,   252,   253,     0,   254,
     255,   256,     0,   235,   257,   258,   259,   236,     0,     0,
       0,   232,     0,     0,   806,     0,   233,     0,     0,     0,
       0,     0,     0,     0,   234,     0,     0,   237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,   239,   240,   241,     0,   242,   243,
     244,     0,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   235,   254,   255,   256,   236,     0,   257,   258,   259,
       0,     0,   807,     0,   232,     0,     0,     0,     0,   233,
       0,     0,     0,     0,     0,   237,     0,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,   239,   240,   241,     0,   242,   243,   244,     0,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     0,
     254,   255,   256,     0,   235,   257,   258,   259,   236,     0,
       0,     0,   232,     0,     0,     0,     0,   233,     0,     0,
       0,     0,     0,     0,     0,   234,     0,     0,   237,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,     0,   239,   240,   241,     0,   242,
     243,   244,     0,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   549,   254,   255,   256,   236,     0,   257,   258,
     259,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,   239,   240,   241,     0,   242,   243,   244,
       0,   245,   246,   247,   248,   249,   250,   251,   252,   253,
       0,   254,   255,   256,     0,     0,   257,   258,   259
};

static const yytype_int16 yycheck[] =
{
      11,    41,    42,     2,   341,    16,    15,   143,    19,   320,
     620,   598,    34,   279,    25,    26,    27,   153,   279,    23,
       3,     0,   620,    34,    35,     3,    37,    38,   482,     1,
     159,   325,   660,    44,    45,    46,    47,    48,     1,     3,
      51,   161,     1,    54,    55,    56,    44,   341,    59,     3,
     756,    62,    63,    64,   174,    66,    54,    24,    69,    70,
      71,   785,   157,   158,   159,   226,   227,   228,   229,    24,
      80,    24,   192,    71,    70,    34,   171,     3,    24,   104,
       3,    50,   104,    61,    34,    80,    63,   216,    13,    34,
      73,    63,   798,    18,   189,   819,     3,    20,    34,    25,
      63,    34,    72,    25,   199,   130,    78,   104,    77,   696,
      85,    34,   134,    80,    37,    78,   127,   128,   129,   130,
     131,   132,   133,   721,   134,    63,    85,   737,    51,    52,
     139,   103,    16,   108,     7,   133,   147,   134,    61,   737,
     103,   595,   770,   771,   103,   104,    72,    80,   131,    72,
     161,   147,   129,   131,   104,   275,   276,   129,   104,   104,
     123,   130,   129,   174,   123,   161,   129,   131,   104,    85,
     481,   104,   176,   104,   129,    59,   129,   131,   174,    34,
     131,   192,   133,   129,   134,   123,   104,   104,   104,   134,
      74,   129,   108,    52,   289,   123,   192,   784,    69,   130,
     211,   134,    61,   131,   104,   133,    61,   368,   131,   208,
     131,   131,   133,    72,   132,   132,   132,   312,   131,   339,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   132,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   723,
       3,    20,   104,    19,     7,    38,    20,   288,   589,   275,
     276,   547,   293,    29,    30,   104,   547,   104,    23,   131,
      36,   104,    38,   304,    57,   306,   307,   131,   309,   310,
     132,   104,   313,    52,   123,    38,   304,   104,    52,   123,
     104,    57,    61,   235,   236,   132,   327,    61,    44,   132,
     123,   819,   333,    72,    57,    60,   123,     2,   339,    64,
     123,   829,    76,   104,   345,   346,    11,   333,   132,   468,
     469,   123,   353,   339,   355,    20,   357,   358,     3,   360,
     361,   128,     7,   104,   365,   277,   278,   353,    33,   355,
     129,   132,   104,   499,   701,    20,   288,   365,   103,   464,
     465,   106,   123,   468,   469,   110,    51,     2,   507,   508,
     104,   123,   123,   104,   104,   307,    11,     3,   310,   123,
     104,     7,    85,   104,    69,    20,    60,    52,    73,   123,
      64,   695,   123,   123,   123,   123,    61,   701,    33,   123,
       3,   104,   123,   123,     7,   108,     9,    72,    60,   131,
     123,    76,    64,    79,   129,    23,    51,    20,   439,   440,
     441,   442,   443,   444,   445,   357,   131,   446,   447,   132,
     451,   452,   131,   454,    69,   106,   131,   122,    73,   460,
     103,   462,   131,   106,   133,   466,   452,   110,   454,    52,
     123,    83,    60,    85,   559,   560,    64,   353,    61,   355,
      85,     7,   103,   484,   123,   570,   487,   104,   132,    72,
     123,    34,    26,    76,   132,   580,   484,   162,   583,    85,
     104,   785,   132,   132,   132,   104,   129,   122,   134,   129,
     794,    99,   134,   101,   102,   103,   132,   105,   106,    85,
      16,   186,   110,    19,    26,   132,   104,    24,   440,   117,
     442,    27,   132,    29,    30,   819,   124,   125,   126,    24,
      36,   134,    38,   208,    34,   829,   547,   162,   549,   550,
     551,   103,   129,   554,    61,   134,   106,   131,    54,   134,
      56,    57,    58,    59,   132,   566,    78,   514,   346,    23,
     154,   186,   573,    63,   575,   459,    72,   578,    74,   677,
     581,   725,   725,   567,   585,   726,   621,   798,    78,   587,
     784,    20,   768,   208,   744,    85,   454,   547,   328,    -1,
      -1,    -1,   603,    -1,    -1,    34,    60,   608,    37,   610,
      64,   612,    -1,   614,   104,   603,   617,   282,    -1,   704,
      -1,    -1,    51,    52,    -1,    -1,    -1,   123,    -1,    -1,
     619,    -1,    61,   123,   130,    -1,    19,   549,   550,   129,
      -1,   306,    -1,    72,   309,    -1,    29,    30,   313,   103,
      -1,   105,   106,    36,    -1,    38,   110,    -1,    -1,    -1,
      -1,    44,    -1,   117,    -1,   666,   667,   282,   669,   670,
     671,   672,   126,    -1,    57,    -1,    -1,     2,   679,   680,
      -1,   682,    -1,   684,   685,    -1,    11,   688,   718,   719,
      -1,   306,    -1,   358,   309,    20,    -1,    -1,   313,   700,
     701,    -1,    -1,    -1,    -1,    -1,   707,    -1,    33,   695,
     711,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    34,    -1,    51,    -1,   729,   730,
     731,   732,   733,   734,   735,   736,    -1,    -1,    -1,    -1,
       2,    -1,    -1,   358,    69,   746,   747,   748,    73,    11,
      63,   752,    -1,    63,   755,    -1,    -1,    -1,    20,    -1,
     748,   762,    -1,    -1,    -1,    78,   752,    -1,    78,   434,
      -1,    33,    85,    -1,    -1,    85,    -1,    -1,    -1,   780,
     781,   782,   783,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,   104,    -1,   794,   104,   796,   797,   122,    -1,   785,
      -1,   802,   803,   804,   805,   806,   807,    69,   473,    -1,
     123,    73,    -1,   123,    -1,    -1,   129,   818,   819,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   829,    -1,
      -1,    16,    -1,   819,    19,    -1,    -1,   162,    -1,    -1,
      23,    -1,    27,   829,    29,    30,   511,    -1,    -1,   514,
      -1,    36,    -1,    38,    -1,    -1,    -1,    -1,   473,    -1,
     122,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    56,    57,    58,    59,    -1,    -1,    60,    -1,    -1,
      -1,    64,    -1,   208,   549,   550,    -1,    72,    -1,    74,
      -1,    -1,    23,    -1,    -1,    -1,   511,    -1,    -1,   514,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   573,    -1,
     575,    -1,    -1,   578,    -1,    -1,   581,    -1,    -1,   584,
     103,    -1,   105,   106,   186,    -1,    -1,   110,    -1,    60,
      -1,    -1,    -1,    64,   117,    -1,    -1,   602,   123,    -1,
      -1,   124,   125,   126,    -1,   130,   208,   612,    -1,   614,
      -1,    -1,    -1,    -1,   619,    -1,    -1,   282,   573,    -1,
     575,    -1,    -1,   578,    -1,    -1,   581,    -1,    99,   584,
     101,   102,   103,    -1,   105,   106,   107,    -1,    -1,   110,
      -1,   306,    -1,    -1,   309,   116,   117,   602,   313,    -1,
     121,     2,    -1,   124,   125,   126,    -1,   612,    -1,   614,
      11,    -1,    -1,    -1,   619,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,   679,    -1,    -1,    -1,    -1,   684,
     282,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   358,     2,    -1,    -1,   702,    -1,    -1,
      51,    -1,    -1,    11,   306,   710,    -1,   309,    -1,   714,
      -1,   313,    20,    -1,     2,    -1,    19,    -1,    69,    -1,
      -1,    -1,    73,    11,   679,    33,    29,    30,    -1,   684,
      -1,    -1,    20,    36,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    51,    -1,    33,    -1,   702,    -1,    -1,
      -1,    -1,    -1,    -1,    57,   710,   358,    -1,    -1,   714,
      -1,    69,    -1,    51,    -1,    73,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,   780,   781,   782,   783,    -1,
      -1,    69,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,   796,   797,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,   473,    -1,
      16,   162,    -1,    19,   122,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    29,    30,   780,   781,   782,   783,    -1,
      36,    -1,    38,    -1,   122,   186,    -1,    -1,    -1,    -1,
      60,   796,   797,    -1,    64,    -1,   511,    -1,    54,   514,
      56,    57,    58,    59,   162,    -1,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    72,    -1,    74,    -1,
      -1,   473,    -1,    -1,   162,    -1,    -1,    -1,   186,    99,
      -1,   101,   102,   103,    -1,   105,   106,   107,    -1,   109,
     110,   111,   112,    -1,   114,   115,   116,   117,   186,   119,
     208,   121,    -1,    -1,   124,   125,   126,    -1,   573,   511,
     575,    -1,   514,   578,    -1,    -1,   581,   123,    -1,   584,
     208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   282,    -1,    -1,    -1,    -1,    -1,   602,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   612,    -1,   614,
      -1,    -1,    -1,    -1,   619,   306,    -1,    -1,   309,    -1,
      -1,    -1,   313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   573,    -1,   575,   282,    -1,   578,    -1,    -1,   581,
      -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   282,    -1,    -1,    -1,   306,    -1,
     602,   309,    -1,    -1,    -1,   313,    -1,   358,    -1,    -1,
     612,    -1,   614,    -1,   679,    -1,    -1,   619,   306,   684,
      -1,   309,    -1,    -1,    -1,   313,    -1,    23,    -1,    -1,
       2,    -1,    47,    -1,    -1,    -1,    -1,   702,    -1,    11,
      -1,    -1,    -1,    -1,    -1,   710,    -1,    -1,    20,   714,
     358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    60,    -1,    -1,    -1,    64,    -1,
     358,    -1,    -1,    -1,    -1,    -1,    -1,   679,    -1,    51,
      -1,    -1,   684,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
     702,    73,    -1,    99,    -1,   101,   102,   103,   710,   105,
     106,   126,   714,    -1,   110,   780,   781,   782,   783,    -1,
     116,   117,   473,    -1,    -1,   121,    -1,    -1,   124,   125,
     126,   796,   797,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
     122,    -1,    23,    -1,    -1,    -1,   171,    -1,    -1,    -1,
     511,    -1,    -1,   514,    -1,   473,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,   780,   781,
     782,   783,    -1,    -1,   199,   473,    -1,    -1,    -1,    60,
     162,    -1,    -1,    64,   796,   797,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   511,    -1,    -1,   514,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   573,   511,   575,    -1,   514,   578,    99,    -1,
     581,   102,   103,   584,   105,   106,   208,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,   602,    -1,   124,   125,   126,    -1,    -1,    -1,    -1,
      -1,   612,    -1,   614,    -1,   573,    -1,   575,   619,    -1,
     578,    -1,    -1,   581,   289,    -1,   584,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   573,    23,   575,    -1,    -1,
     578,    -1,    -1,   581,   602,    -1,   584,   312,    -1,    -1,
      -1,    -1,    -1,    -1,   612,    -1,   614,    -1,    -1,    -1,
     282,   619,    -1,    -1,   602,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,   612,    -1,   614,    64,   679,    -1,
      -1,   619,    -1,   684,   306,    -1,    -1,   309,    -1,    -1,
      -1,   313,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      -1,   702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   710,
      -1,    -1,    99,   714,   101,   102,   103,    -1,   105,   106,
     107,   679,   109,   110,   111,   112,   684,   114,   115,   116,
     117,    -1,   119,   120,   121,    -1,   358,   124,   125,   126,
      -1,   679,    -1,    -1,   702,    -1,   684,    -1,    -1,    -1,
      -1,    -1,   710,    -1,    -1,    -1,   714,    -1,    -1,    -1,
       2,    -1,    -1,    -1,   702,    -1,    -1,    -1,    -1,    11,
      -1,    -1,   710,    -1,    23,    -1,   714,    -1,    20,   780,
     781,   782,   783,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,   796,   797,    13,    -1,   464,
     465,    -1,    18,   468,   469,    -1,    22,    23,    24,    51,
      -1,    60,    -1,    -1,    30,    64,    32,    -1,    -1,    -1,
      -1,    -1,   780,   781,   782,   783,    -1,    69,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    52,    -1,   796,   797,
      -1,    -1,   780,   781,   782,   783,    -1,    -1,    -1,    -1,
      99,   473,    -1,    -1,   103,    -1,   105,   106,   796,   797,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    90,   124,   125,   126,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   511,
      -1,    -1,   514,    -1,   559,   560,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   570,    -1,   572,    -1,    -1,
      -1,    -1,   577,    -1,    -1,   580,    -1,    -1,   583,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,   155,
      -1,    -1,    -1,    -1,   186,   161,    -1,    -1,   164,    -1,
      -1,   573,    -1,   575,    -1,    -1,   578,    -1,   174,   581,
     176,    -1,   584,   179,    -1,    -1,   208,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,    -1,    -1,
     602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     612,    -1,   614,    -1,    -1,    -1,    -1,   619,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
     226,   227,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   704,
     282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   679,    -1,   275,
     276,    -1,   684,    -1,   306,    -1,    -1,   309,    -1,    -1,
      -1,    -1,    -1,    -1,   739,   740,    -1,   742,   743,    -1,
     702,    -1,    -1,    -1,   300,    60,   302,    -1,   710,    64,
      -1,   756,   714,    -1,    -1,    -1,    -1,    -1,   763,    -1,
     765,    -1,    -1,    -1,   320,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   328,    -1,    -1,    -1,   358,    -1,    -1,    -1,
      -1,    -1,    -1,   339,    99,    -1,   101,   102,   103,    -1,
     105,   106,   107,   798,   109,   110,   111,   112,    -1,   114,
     115,   116,   117,    -1,   119,    -1,   121,    -1,    -1,   124,
     125,   126,   368,    -1,    -1,    -1,    -1,    -1,   780,   781,
     782,   783,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   796,   797,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    12,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,   473,    -1,    -1,    -1,    60,    -1,    -1,   454,    64,
      -1,    -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,   477,    -1,    -1,    -1,   481,    -1,    -1,    -1,   511,
      -1,    -1,   514,    -1,    99,   100,   101,   102,   103,    -1,
     105,   106,   107,   499,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,   124,
     125,   126,    -1,    -1,   129,   521,   131,    -1,   133,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,   573,    -1,   575,    -1,    -1,   578,    25,    -1,   581,
      -1,    -1,   584,    31,    32,    33,    -1,    35,    -1,    -1,
      -1,   567,    40,    41,    -1,    43,    -1,    45,    46,    -1,
     602,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,
     612,    -1,   614,   589,    -1,    -1,    -1,   619,    -1,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,    -1,    -1,    -1,    -1,   107,
      -1,   637,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
     118,    -1,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,
      -1,   129,    -1,   131,    -1,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   710,    -1,
      -1,    -1,   714,    -1,    -1,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,   717,    27,    -1,    29,    30,    31,    32,    33,   725,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    66,    67,    68,    69,    70,    -1,    72,    -1,    74,
      75,    76,    -1,    -1,    79,    -1,    81,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,   118,    -1,   120,   121,    -1,   123,    -1,
      -1,   126,    -1,    -1,   129,    -1,   131,     1,   133,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    -1,    -1,    -1,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    -1,    72,    -1,
      74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,   123,
     124,   125,   126,    -1,    -1,   129,   130,   131,     1,   133,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    -1,    27,    -1,    29,    30,    31,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    65,    66,    67,    68,    69,    70,    -1,    72,
      -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,   118,    -1,   120,   121,   122,
     123,    -1,    -1,   126,    -1,    -1,   129,   130,   131,     1,
     133,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    -1,    27,    -1,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    67,    68,    69,    70,    -1,
      72,    -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,   118,    -1,   120,   121,
      -1,   123,    -1,    -1,   126,    -1,    -1,   129,   130,   131,
       1,   133,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    -1,    27,    -1,    29,    30,
      31,    32,    33,    -1,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    -1,    74,    75,    76,    -1,    -1,    79,    -1,
      81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,    -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,   118,    -1,   120,
     121,    -1,   123,    -1,    -1,   126,    -1,    -1,   129,   130,
     131,     1,   133,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    -1,    27,    -1,    29,
      30,    31,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    66,    67,    68,    69,
      70,    -1,    72,    -1,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,    -1,
     120,   121,    -1,   123,    -1,    -1,   126,    -1,    -1,   129,
     130,   131,     1,   133,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    -1,    27,    -1,
      29,    30,    31,    32,    33,    -1,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    66,    67,    68,
      69,    70,    -1,    72,    -1,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,
      -1,   120,   121,    -1,   123,    -1,    -1,   126,    -1,    -1,
     129,   130,   131,     1,   133,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    -1,    27,
      -1,    29,    30,    31,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    70,    -1,    72,    -1,    74,    75,    76,    -1,
      -1,    79,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,    -1,    -1,    -1,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
     118,    -1,   120,   121,    -1,   123,    -1,    -1,   126,    -1,
      -1,   129,    -1,   131,     1,   133,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    -1,
      27,    -1,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    -1,    -1,    -1,    52,    53,    -1,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    65,    66,
      67,    68,    69,    70,    -1,    72,    -1,    74,    75,    76,
      -1,    -1,    79,    -1,    81,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,   118,    -1,   120,   121,    -1,   123,    -1,    -1,   126,
      -1,    -1,   129,    -1,   131,     1,   133,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      -1,    27,    -1,    29,    30,    31,    32,    33,    -1,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    -1,    -1,    -1,    52,    53,    -1,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      66,    67,    68,    69,    70,    -1,    72,    -1,    74,    75,
      76,    -1,    -1,    79,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,   118,    -1,   120,   121,    -1,   123,    -1,    -1,
     126,    -1,    -1,   129,    -1,   131,     1,   133,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    -1,    27,    -1,    29,    30,    31,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    -1,    -1,    -1,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    66,    67,    68,    69,    70,    -1,    72,    -1,    74,
      75,    76,    -1,    -1,    79,    -1,    81,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,   118,    -1,   120,   121,    -1,   123,    -1,
      -1,   126,    -1,    -1,   129,    -1,   131,     1,   133,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    -1,    27,    -1,    29,    30,    31,    32,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    -1,    -1,    -1,    52,    53,
      -1,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    70,    -1,    72,    -1,
      74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,   118,    -1,   120,   121,    -1,   123,
      -1,    -1,   126,    -1,    -1,   129,    -1,   131,     1,   133,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    -1,    27,    -1,    29,    30,    31,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    -1,    -1,    -1,    52,
      53,    -1,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    65,    66,    67,    68,    69,    70,    -1,    72,
      -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,   118,    -1,   120,   121,    -1,
     123,    -1,    -1,   126,    -1,    -1,   129,    -1,   131,     1,
     133,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    -1,    27,    -1,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    -1,    -1,    -1,
      52,    53,    -1,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    67,    68,    69,    70,    -1,
      72,    -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,   118,    -1,   120,   121,
      -1,   123,    -1,    -1,   126,    -1,    -1,   129,    -1,   131,
       1,   133,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    -1,    27,    -1,    29,    30,
      31,    32,    33,    -1,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    -1,    -1,
      -1,    52,    53,    -1,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    -1,    74,    75,    76,    -1,    -1,    79,    -1,
      81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,    -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,   118,    -1,   120,
     121,    -1,   123,    -1,    -1,   126,    -1,    -1,   129,    -1,
     131,     1,   133,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    -1,    27,    -1,    29,
      30,    31,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    -1,
      -1,    -1,    52,    53,    -1,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    66,    67,    68,    69,
      70,    -1,    72,    -1,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,    -1,
     120,   121,    -1,   123,    -1,    -1,   126,    -1,    -1,   129,
      -1,   131,     1,   133,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    -1,    27,    -1,
      29,    30,    31,    32,    33,    -1,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      -1,    -1,    -1,    52,    53,    -1,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    66,    67,    68,
      69,    70,    -1,    72,    -1,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,
      -1,   120,   121,    -1,   123,    -1,    -1,   126,    -1,    -1,
     129,    -1,   131,     1,   133,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    -1,    27,
      -1,    29,    30,    31,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    -1,    -1,    -1,    52,    53,    -1,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    70,    -1,    72,    -1,    74,    75,    76,    -1,
      -1,    79,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,    -1,    -1,    -1,    -1,   107,
       3,     4,     5,     6,     7,     8,    -1,    -1,   116,    12,
     118,    -1,   120,   121,    -1,   123,    -1,    -1,   126,    -1,
      -1,   129,    25,   131,    -1,   133,    -1,    -1,    31,    32,
      33,    -1,    35,    -1,    -1,    -1,    -1,    40,    41,    -1,
      43,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,   107,     3,     4,     5,     6,     7,
       8,    -1,    -1,   116,    12,   118,    -1,   120,   121,   122,
      -1,    -1,    20,   126,    -1,    -1,   129,    25,   131,    -1,
     133,   134,    -1,    31,    32,    33,    34,    35,    -1,    37,
      -1,    -1,    40,    41,    -1,    43,    -1,    45,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,    -1,    -1,    -1,    -1,   107,
       3,     4,     5,     6,     7,     8,    -1,    -1,   116,    12,
     118,    -1,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,
      -1,   129,    25,   131,    -1,   133,    -1,    -1,    31,    32,
      33,    -1,    35,    -1,    -1,    -1,    -1,    40,    41,    -1,
      43,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,   107,   108,    -1,     3,     4,     5,
       6,     7,     8,   116,    -1,   118,    12,   120,   121,   122,
      -1,    -1,    -1,   126,    -1,    -1,   129,    -1,   131,    25,
     133,    -1,    -1,    -1,    -1,    31,    32,    33,    -1,    35,
      -1,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,   107,     3,     4,     5,     6,     7,     8,    -1,    -1,
     116,    12,   118,    -1,   120,   121,   122,    -1,    -1,    -1,
     126,    -1,    -1,   129,    25,   131,   132,   133,    -1,    -1,
      31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,    40,
      41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,    -1,    -1,    -1,    -1,   107,     3,     4,     5,
       6,     7,     8,    -1,    -1,   116,    12,   118,    -1,   120,
     121,    -1,    -1,    -1,    -1,   126,    -1,    -1,   129,    25,
     131,    -1,   133,    -1,    -1,    31,    32,    33,    -1,    35,
      -1,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,   107,     3,     4,     5,     6,     7,     8,    -1,    -1,
     116,    12,   118,    -1,   120,   121,   122,    -1,    -1,    -1,
     126,    -1,    -1,   129,    25,   131,    -1,   133,    -1,    -1,
      31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,    40,
      41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,    -1,    -1,    -1,    -1,   107,     3,     4,     5,
       6,     7,     8,    -1,    -1,   116,    12,   118,    -1,   120,
     121,   122,    -1,    -1,    -1,   126,    -1,    -1,   129,    25,
     131,    -1,   133,    -1,    -1,    31,    32,    33,    -1,    35,
      -1,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,   118,    -1,   120,   121,    -1,   123,    -1,    -1,
     126,    -1,    -1,   129,    -1,   131,    -1,   133,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,   107,     3,     4,     5,     6,     7,     8,    -1,
      -1,   116,    12,   118,    -1,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,    -1,   129,    25,   131,    -1,   133,    -1,
      -1,    31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,
      40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,   107,     3,     4,
       5,     6,     7,     8,    -1,    -1,   116,    12,   118,    -1,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,    -1,   129,
      25,   131,    -1,   133,    -1,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,   107,     3,     4,     5,     6,     7,     8,    -1,
      -1,   116,    12,   118,    -1,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,    -1,   129,    25,   131,    -1,   133,    -1,
      -1,    31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,
      40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,   107,     3,     4,
       5,     6,     7,     8,    -1,    -1,   116,    12,   118,    -1,
     120,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,   129,
      25,   131,    -1,   133,    -1,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,   107,     3,     4,     5,     6,     7,     8,    -1,
      -1,   116,    12,   118,    -1,   120,   121,   122,    -1,    -1,
      -1,   126,    -1,    -1,   129,    25,   131,    -1,   133,    -1,
      -1,    31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,
      40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,   107,     3,     4,
       5,     6,     7,     8,    -1,    -1,   116,    12,   118,    -1,
     120,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,   129,
      25,   131,    -1,   133,    -1,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,   107,     3,     4,     5,     6,     7,     8,    -1,
      -1,   116,    12,   118,    -1,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,    -1,   129,    25,   131,    -1,   133,    -1,
      -1,    31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,
      40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,   107,     3,     4,
       5,     6,     7,     8,    -1,    -1,   116,    12,   118,    -1,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,    -1,   129,
      25,   131,    -1,   133,    -1,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,   107,     3,     4,     5,     6,     7,     8,    -1,
      -1,   116,    12,   118,    -1,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,    -1,   129,    25,   131,    -1,   133,    -1,
      -1,    31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,
      40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,   107,     3,     4,
       5,     6,     7,     8,    -1,    -1,   116,    12,   118,    -1,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,    -1,   129,
      25,   131,    -1,   133,    -1,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,   107,     3,     4,     5,     6,     7,     8,    -1,
      -1,   116,    12,   118,    -1,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,    -1,   129,    25,   131,    -1,   133,    -1,
      -1,    31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,
      40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,   107,     3,     4,
       5,     6,     7,     8,    -1,    -1,   116,    12,   118,    -1,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,    -1,   129,
      25,   131,    -1,   133,    -1,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,   107,     3,     4,     5,     6,     7,     8,    -1,
      -1,   116,    12,   118,    -1,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,    -1,   129,    25,   131,    -1,   133,    -1,
      -1,    31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,
      40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,   107,     3,     4,
       5,     6,     7,     8,    -1,    -1,   116,    12,   118,    -1,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,    -1,   129,
      25,   131,    -1,   133,    -1,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,   107,     3,     4,     5,     6,     7,     8,    -1,
      -1,   116,    12,   118,    -1,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,    -1,   129,    25,   131,    -1,   133,    -1,
      -1,    31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,
      40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    -1,    35,    -1,   116,    -1,   118,    40,
      41,   121,    43,    -1,    45,    46,   126,    -1,    -1,   129,
      -1,   131,    53,   133,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    23,
      -1,    12,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,   100,
      31,    32,    33,   104,    35,    -1,    -1,   108,    -1,    40,
      41,    -1,    43,    -1,    45,    46,    60,   118,    -1,    -1,
      64,   122,    53,    -1,    55,    -1,    -1,    -1,   129,    -1,
     131,   132,   133,     3,    -1,    -1,    67,    68,    69,    70,
      10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,   103,
      -1,   105,   106,   107,    -1,    -1,   110,   111,   112,   100,
     114,   115,   116,   117,    -1,    -1,    -1,   121,    -1,    -1,
     124,   125,   126,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    15,    85,    86,    87,    88,    89,
      90,    -1,    23,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,   121,    -1,    -1,   124,   125,   126,   127,   128,    60,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      23,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
     101,   102,   103,    -1,   105,   106,   107,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    60,   119,   120,
     121,    64,    -1,   124,   125,   126,    -1,    -1,    -1,    -1,
      10,    -1,    -1,   134,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,
     103,    -1,   105,   106,   107,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,   120,   121,    -1,
      60,   124,   125,   126,    64,    -1,    -1,    -1,    10,    -1,
      -1,   134,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,   102,   103,    -1,   105,   106,   107,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    60,   119,
     120,   121,    64,    -1,   124,   125,   126,    -1,    -1,    -1,
      -1,    10,    -1,    -1,   134,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,
     102,   103,    -1,   105,   106,   107,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,   119,   120,   121,
      -1,    60,   124,   125,   126,    64,    -1,    -1,    -1,    10,
      -1,    -1,   134,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,   101,   102,   103,    -1,   105,   106,   107,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    60,
     119,   120,   121,    64,    -1,   124,   125,   126,    -1,    -1,
      -1,    -1,    10,   132,    -1,    -1,    -1,    15,    -1,    80,
      -1,    -1,    -1,    84,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    99,    -1,
     101,   102,   103,    -1,   105,   106,   107,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,   119,   120,
     121,    -1,    60,   124,   125,   126,    64,    -1,   129,    -1,
      10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,   101,   102,   103,    -1,   105,   106,   107,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      60,   119,   120,   121,    64,    -1,   124,   125,   126,    -1,
      -1,   129,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,
      80,    -1,    -1,    -1,    84,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,   102,   103,    -1,   105,   106,   107,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,   119,
     120,   121,    -1,    60,   124,   125,   126,    64,    -1,   129,
      -1,    10,    -1,    -1,    71,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,   101,   102,   103,    -1,   105,   106,
     107,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    60,   119,   120,   121,    64,    -1,   124,   125,   126,
      -1,    -1,   129,    -1,    10,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,   101,   102,   103,    -1,   105,   106,   107,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,   120,   121,    -1,    60,   124,   125,   126,    64,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,   101,   102,   103,    -1,   105,
     106,   107,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,   119,   120,   121,    -1,    60,   124,   125,
     126,    64,    -1,   129,    -1,    -1,    -1,    -1,    71,    -1,
      10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,
     103,    -1,   105,   106,   107,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,   120,   121,    -1,
      60,   124,   125,   126,    64,    -1,   129,    -1,    -1,    -1,
      -1,    71,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,   102,   103,    -1,   105,   106,   107,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,   119,
     120,   121,    -1,    60,   124,   125,   126,    64,    -1,   129,
      -1,    -1,    -1,    -1,    71,    -1,    10,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    84,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,   101,   102,   103,    -1,   105,   106,
     107,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,   119,   120,   121,    -1,    60,   124,   125,   126,
      64,    -1,   129,    -1,    -1,    -1,    -1,    71,    -1,    10,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,   103,
      -1,   105,   106,   107,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,   119,   120,   121,    -1,    60,
     124,   125,   126,    64,    -1,   129,    -1,    -1,    -1,    -1,
      71,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
     101,   102,   103,    -1,   105,   106,   107,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,   119,   120,
     121,    -1,    60,   124,   125,   126,    64,    -1,   129,    -1,
      -1,    -1,    -1,    71,    -1,    10,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    84,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,   101,   102,   103,    -1,   105,   106,   107,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,   119,   120,   121,    -1,    60,   124,   125,   126,    64,
      -1,   129,    -1,    -1,    -1,    -1,    71,    -1,    10,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   101,   102,   103,    -1,
     105,   106,   107,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,   120,   121,    -1,    60,   124,
     125,   126,    64,    -1,   129,    -1,    10,    -1,    -1,    71,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,
     102,   103,    -1,   105,   106,   107,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    60,   119,   120,   121,
      64,    -1,   124,   125,   126,    -1,    -1,   129,    -1,    10,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,   103,
      -1,   105,   106,   107,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,   119,   120,   121,    -1,    60,
     124,   125,   126,    64,    -1,   129,    -1,    10,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
     101,   102,   103,    -1,   105,   106,   107,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    60,   119,   120,
     121,    64,    -1,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,
     103,    -1,   105,   106,   107,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    10,   119,   120,   121,    -1,
      15,   124,   125,   126,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    28,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    15,    60,    -1,    -1,    -1,    64,
      -1,    -1,    23,    24,    -1,    -1,   127,   128,    -1,    -1,
     131,    -1,   133,    34,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   101,   102,   103,    60,
     105,   106,   107,    64,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,   120,   121,    -1,    -1,   124,
     125,   126,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
     101,   102,   103,    -1,   105,   106,   107,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    10,   119,   120,
     121,    -1,    15,   124,   125,   126,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    60,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      15,    84,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    60,    -1,    -1,    -1,    64,    99,    -1,   101,   102,
     103,    -1,   105,   106,   107,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    84,   119,   120,   121,    -1,
      -1,   124,   125,   126,    -1,    60,    -1,    -1,    -1,    64,
      99,    -1,   101,   102,   103,    -1,   105,   106,   107,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    84,
     119,   120,   121,    -1,   123,   124,   125,   126,    -1,    -1,
      10,    -1,    -1,    -1,    99,    15,   101,   102,   103,    -1,
     105,   106,   107,    23,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,   120,   121,    -1,   123,   124,
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      60,    -1,    -1,    -1,    64,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,   102,   103,    60,   105,   106,   107,    64,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,   119,
     120,   121,    -1,   123,   124,   125,   126,    83,    84,    10,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    99,    -1,   101,   102,   103,    -1,   105,
     106,   107,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,   119,   120,   121,    -1,    -1,   124,   125,
     126,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    60,
      -1,    -1,    -1,    64,    -1,    -1,    23,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
     101,   102,   103,    60,   105,   106,   107,    64,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,   119,   120,
     121,    10,    -1,   124,   125,   126,    15,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,   101,   102,   103,    -1,   105,   106,
     107,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,   119,   120,   121,    10,   123,   124,   125,   126,
      15,    60,    -1,    -1,    -1,    64,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,   101,   102,   103,    60,   105,   106,   107,    64,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,   120,   121,    10,   123,   124,   125,   126,    15,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   101,   102,   103,    -1,
     105,   106,   107,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,   120,   121,    10,   123,   124,
     125,   126,    15,    60,    -1,    -1,    -1,    64,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,   101,   102,   103,    60,   105,   106,
     107,    64,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,   119,   120,   121,    10,   123,   124,   125,   126,
      15,    84,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,
     103,    -1,   105,   106,   107,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,   120,   121,    10,
     123,   124,   125,   126,    15,    60,    -1,    -1,    -1,    64,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   101,   102,   103,    60,
     105,   106,   107,    64,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,   120,   121,    10,   123,   124,
     125,   126,    15,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
     101,   102,   103,    -1,   105,   106,   107,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,   119,   120,
     121,    10,   123,   124,   125,   126,    15,    60,    -1,    -1,
      -1,    64,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,
     103,    60,   105,   106,   107,    64,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,   120,   121,    10,
     123,   124,   125,   126,    15,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,   101,   102,   103,    -1,   105,   106,   107,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,   120,   121,    10,   123,   124,   125,   126,    15,    60,
      -1,    -1,    -1,    64,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
     101,   102,   103,    60,   105,   106,   107,    64,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,   119,   120,
     121,    10,   123,   124,   125,   126,    15,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,   101,   102,   103,    -1,   105,   106,
     107,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,   119,   120,   121,    10,   123,   124,   125,   126,
      15,    60,    -1,    -1,    -1,    64,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,   101,   102,   103,    60,   105,   106,   107,    64,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,   120,   121,    10,   123,   124,   125,   126,    15,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   101,   102,   103,    -1,
     105,   106,   107,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,   120,   121,    10,   123,   124,
     125,   126,    15,    60,    -1,    -1,    -1,    64,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,   101,   102,   103,    60,   105,   106,
     107,    64,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,   119,   120,   121,    10,   123,   124,   125,   126,
      15,    84,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,
     103,    -1,   105,   106,   107,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,   120,   121,    10,
     123,   124,   125,   126,    15,    60,    -1,    -1,    -1,    64,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   101,   102,   103,    60,
     105,   106,   107,    64,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,   120,   121,    10,    -1,   124,
     125,   126,    15,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    99,    -1,
     101,   102,   103,    -1,   105,   106,   107,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,   119,   120,
     121,    -1,   123,   124,   125,   126,    -1,    60,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,
     103,    -1,   105,   106,   107,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    60,   119,   120,   121,    64,
      -1,   124,   125,   126,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   101,   102,   103,    -1,
     105,   106,   107,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,   120,   121,    -1,    60,   124,
     125,   126,    64,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,
     102,   103,    -1,   105,   106,   107,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    60,   119,   120,   121,
      64,    -1,   124,   125,   126,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,   103,
      -1,   105,   106,   107,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,   119,   120,   121,    -1,    60,
     124,   125,   126,    64,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
     101,   102,   103,    -1,   105,   106,   107,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    60,   119,   120,
     121,    64,    -1,   124,   125,   126,    -1,    -1,    71,    -1,
      10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,   102,
     103,    -1,   105,   106,   107,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,   120,   121,    -1,
      60,   124,   125,   126,    64,    -1,    -1,    -1,    10,    11,
      -1,    71,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,   102,   103,    -1,   105,   106,   107,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    60,   119,
     120,   121,    64,    -1,   124,   125,   126,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   101,
     102,   103,    -1,   105,   106,   107,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,   119,   120,   121,
      -1,    60,   124,   125,   126,    64,    -1,    -1,    -1,    10,
      -1,    -1,    71,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,   101,   102,   103,    -1,   105,   106,   107,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    60,
     119,   120,   121,    64,    -1,   124,   125,   126,    -1,    -1,
      71,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
     101,   102,   103,    -1,   105,   106,   107,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,   119,   120,
     121,    -1,    60,   124,   125,   126,    64,    -1,    -1,    -1,
      10,    -1,    -1,    71,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,   101,   102,   103,    -1,   105,   106,   107,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      60,   119,   120,   121,    64,    -1,   124,   125,   126,    -1,
      -1,    71,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,   101,   102,   103,    -1,   105,   106,   107,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,   119,
     120,   121,    -1,    60,   124,   125,   126,    64,    -1,    -1,
      -1,    10,    -1,    -1,    71,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,   101,   102,   103,    -1,   105,   106,
     107,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    60,   119,   120,   121,    64,    -1,   124,   125,   126,
      -1,    -1,    71,    -1,    10,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,   101,   102,   103,    -1,   105,   106,   107,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,   120,   121,    -1,    60,   124,   125,   126,    64,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,   101,   102,   103,    -1,   105,
     106,   107,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    60,   119,   120,   121,    64,    -1,   124,   125,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,   101,   102,   103,    -1,   105,   106,   107,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,   119,   120,   121,    -1,    -1,   124,   125,   126
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   139,   140,     0,     1,     3,     4,     5,     6,     7,
       8,    12,    13,    14,    16,    17,    18,    19,    21,    22,
      24,    25,    27,    29,    30,    31,    32,    33,    35,    36,
      39,    40,    41,    42,    43,    45,    46,    48,    53,    54,
      55,    56,    58,    59,    62,    63,    65,    66,    67,    68,
      69,    70,    72,    74,    75,    79,    81,    84,    99,   100,
     101,   102,   107,   116,   118,   120,   121,   123,   126,   129,
     131,   133,   141,   142,   143,   144,   145,   146,   149,   150,
     151,   153,   156,   157,   158,   159,   160,   162,   163,   166,
     167,   170,   173,   176,   177,   198,   201,   202,   219,   220,
     221,   222,   223,   224,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   240,   241,   242,   243,   244,   143,
     232,    80,   225,   226,   152,   153,   225,    12,    31,    32,
      33,    70,   129,   133,   173,   219,   223,   230,   231,   232,
     233,   235,   236,    72,   152,   232,   143,   131,   153,     7,
     152,   154,     9,    72,   154,    52,    82,   161,   232,   232,
     232,   131,   153,   174,   131,   153,   203,   204,   143,   232,
     232,   232,   232,     7,   131,    19,    30,   158,   158,   122,
     194,   213,   232,   123,   232,   232,    24,   146,   155,   232,
     232,    69,   131,   143,   232,   153,   199,   213,   232,   232,
     232,   232,   232,   232,   232,   232,   130,   141,   147,   213,
      73,   108,   194,   214,   215,   232,   213,   232,   239,    54,
     143,    44,   153,    38,    57,   190,    20,    52,    61,    76,
     123,   128,    10,    15,    23,    60,    64,    84,    99,   101,
     102,   103,   105,   106,   107,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   119,   120,   121,   124,   125,   126,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   127,   131,   133,    60,    64,   131,
     143,   123,   129,   146,   232,   232,   232,   213,    34,   225,
     199,   123,   123,    79,   153,   194,   216,   217,   218,   232,
     129,   199,   167,   153,   131,   155,    24,    34,   155,    24,
      34,   155,   226,    71,   146,   216,   143,   131,   184,    73,
     131,   153,   205,   206,     1,   103,   208,    34,   104,   155,
     216,   154,   153,   104,   123,   123,   129,   143,   155,   131,
     216,    85,   200,   123,   123,    28,    49,   155,   123,   130,
     141,   130,   232,   104,   132,   104,   132,    34,   134,   226,
      83,   104,   134,     7,   153,   103,   168,   178,    61,   203,
     203,   203,   203,   232,   232,   232,   232,   161,   232,   161,
     232,   232,   232,   232,   232,   232,   232,    25,    72,   153,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   216,   216,   161,   232,   161,   232,    20,    34,    37,
      51,    52,    61,    72,   188,   227,   228,   232,   244,    24,
      34,    24,    34,    71,    34,   134,   161,   232,   155,   123,
     232,    83,    85,   132,   104,   153,   171,   172,   123,   153,
      34,   213,    33,   232,   161,   232,    33,   232,   161,   232,
     155,   143,   232,    26,   132,   185,   186,   187,   188,   175,
     206,   104,   132,     1,   133,   209,   220,    85,   207,   232,
     204,   132,   194,   232,   164,   216,   132,   209,   220,   104,
     148,   232,   148,   132,   132,   214,   214,   161,   232,   143,
     232,   134,   232,   232,   129,   213,   129,    52,    61,    72,
     180,   189,   203,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   132,   134,    34,    61,   219,   104,   132,    60,
      60,    33,   161,   232,    33,   161,   232,   161,   232,   225,
     225,   123,   232,   194,   232,   218,    85,   104,   130,   168,
     232,   132,   232,    24,   155,    24,   155,   232,    24,   155,
     226,    24,   155,   226,    26,    26,   143,   104,   132,   131,
     153,    20,    52,    61,    72,   191,   132,   206,   208,   213,
      47,   232,    50,    77,   130,   165,   132,   199,   104,   123,
      11,   123,   134,   226,   134,   226,   143,    83,   130,   147,
     169,   179,    10,    15,    85,    86,    87,    88,    89,    90,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     105,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   121,   124,   125,   126,   127,   128,   153,   181,
     182,   123,   228,   219,   219,   232,    24,    24,   232,    24,
      24,   134,   134,   155,   155,   232,   172,   129,   155,    71,
      33,   232,    33,   232,    71,    33,   232,   155,    33,   232,
     155,   143,   232,   186,   206,   103,   212,    61,   208,   207,
      34,   134,    24,   143,   213,   232,   232,    33,   143,   232,
     134,    33,   143,   232,   134,   232,   130,    30,    56,    58,
     130,   142,   157,   191,   153,   106,   131,   183,   183,    71,
      33,    33,    71,    33,    33,    33,    33,   169,   232,   232,
     232,   232,   232,   232,   132,    25,    67,    70,   133,   194,
     211,   220,   108,   196,   207,    78,   197,   232,   209,   220,
     143,   155,    11,   232,   143,   232,   143,   157,   208,   153,
     181,   182,   185,   232,   232,   232,   232,   232,   232,   130,
      71,    71,    71,    71,   212,   134,   213,   194,   195,   232,
     232,   146,   156,   193,   134,   232,    71,    71,   197,   183,
     183,   132,    71,    71,    71,    71,    71,    71,   232,   232,
     232,   232,   196,   207,   194,   210,   211,   220,    34,   134,
     220,   232,   232,   123,   192,   193,   232,   210,   211,   134,
     210
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   138,   139,   140,   140,   141,   141,   142,   142,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   144,   144,   145,   145,   145,
     146,   146,   147,   147,   148,   148,   148,   148,   149,   149,
     149,   150,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   152,   152,   153,
     154,   154,   155,   155,   156,   156,   157,   157,   157,   157,
     157,   157,   157,   158,   158,   159,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   161,   162,
     162,   162,   162,   163,   164,   164,   165,   165,   165,   166,
     166,   167,   167,   167,   168,   168,   169,   169,   169,   170,
     171,   171,   171,   172,   172,   174,   175,   173,   176,   176,
     176,   176,   178,   179,   177,   180,   180,   180,   180,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   183,   183,   184,
     185,   185,   185,   186,   186,   186,   186,   187,   187,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   189,   189,
     189,   189,   190,   190,   191,   191,   191,   191,   191,   191,
     192,   192,   193,   193,   194,   194,   195,   195,   196,   196,
     197,   197,   198,   198,   198,   199,   199,   200,   200,   200,
     201,   201,   201,   201,   201,   202,   202,   202,   203,   203,
     204,   204,   205,   205,   205,   206,   206,   206,   207,   207,
     207,   208,   208,   208,   208,   209,   209,   209,   209,   210,
     210,   210,   211,   211,   211,   211,   211,   212,   212,   212,
     212,   212,   212,   212,   213,   213,   213,   213,   214,   214,
     214,   215,   215,   216,   216,   217,   217,   218,   218,   218,
     218,   218,   219,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   222,   223,   224,   224,   224,   224,   224,   224,
     224,   224,   225,   225,   226,   227,   227,   228,   228,   228,
     229,   229,   230,   231,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   233,   233,
     233,   233,   234,   234,   235,   235,   235,   236,   236,   236,
     237,   237,   237,   238,   238,   238,   238,   238,   238,   238,
     238,   239,   239,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   241,   241,   241,   241,
     241,   241,   242,   242,   242,   242,   243,   243,   243,   243,
     244,   244,   244,   244,   244,   244,   244
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     2,     2,     3,     1,     5,     6,     0,     1,     1,
       2,     3,     1,     2,     1,     3,     3,     5,     3,     5,
       5,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     1,     1,
       1,     1,     2,     1,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     2,     5,     3,     6,     6,
       4,     5,     5,     3,     3,     6,     5,     6,     5,     6,
       3,     4,     6,     7,     6,     7,     4,     5,     4,     4,
       3,     6,     5,     5,     0,     2,     3,     2,     3,     6,
       8,     1,     1,     1,     0,     2,     0,     2,     3,     5,
       1,     2,     3,     1,     3,     0,     0,     8,     0,     1,
       2,     2,     0,     0,     9,     3,     3,     5,     5,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     3,
       0,     1,     3,     4,     4,     6,     6,     0,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     0,     1,     2,     2,
       0,     2,     3,     4,     4,     2,     4,     0,     2,     2,
       4,     4,     4,     5,     4,     0,     1,     1,     1,     3,
       3,     5,     1,     1,     3,     1,     2,     3,     0,     2,
       2,     0,     2,     2,     1,     4,     4,     6,     1,     0,
       1,     1,     3,     4,     3,     4,     6,     0,     2,     2,
       2,     2,     2,     2,     1,     1,     3,     3,     1,     1,
       1,     3,     3,     0,     1,     1,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     2,     6,     6,     4,     9,     9,
       7,     6,     6,     4,     9,     9,     7,     4,     6,     6,
       9,     9,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     4,     1,     3,     2,     3,     3,
       1,     3,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     3,     3,     3,
       3,     4,     3,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1
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
      yyerror (&yylloc, context, YY_("syntax error: cannot back up")); \
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
                  Type, Value, Location, context); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParserContext* context)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (context);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParserContext* context)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, context);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, ParserContext* context)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , context);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, context); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, ParserContext* context)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (context);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}



struct yypstate
  {
    /* Number of syntax errors so far.  */
    int yynerrs;

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
    /* Used to determine if this is the first time this instance has
       been used.  */
    int yynew;
  };

/* Initialize the parser data structure.  */
yypstate *
yypstate_new (void)
{
  yypstate *yyps;
  yyps = (yypstate *) malloc (sizeof *yyps);
  if (!yyps)
    return YY_NULLPTR;
  yyps->yynew = 1;
  return yyps;
}

void
yypstate_delete (yypstate *yyps)
{
#ifndef yyoverflow
  /* If the stack was reallocated but the parse did not complete, then the
     stack still needs to be freed.  */
  if (!yyps->yynew && yyps->yyss != yyps->yyssa)
    YYSTACK_FREE (yyps->yyss);
#endif
  free (yyps);
}

#define yynerrs yyps->yynerrs
#define yystate yyps->yystate
#define yyerrstatus yyps->yyerrstatus
#define yyssa yyps->yyssa
#define yyss yyps->yyss
#define yyssp yyps->yyssp
#define yyvsa yyps->yyvsa
#define yyvs yyps->yyvs
#define yyvsp yyps->yyvsp
#define yylsa yyps->yylsa
#define yyls yyps->yyls
#define yylsp yyps->yylsp
#define yyerror_range yyps->yyerror_range
#define yystacksize yyps->yystacksize


/*---------------.
| yypush_parse.  |
`---------------*/

int
yypush_parse (yypstate *yyps, int yypushed_char, YYSTYPE const *yypushed_val, YYLTYPE *yypushed_loc, ParserContext* context)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

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

  if (!yyps->yynew)
    {
      yyn = yypact[yystate];
      goto yyread_pushed_token;
    }

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = *yypushed_loc;
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
      if (!yyps->yynew)
        {
          YYDPRINTF ((stderr, "Return for a new token:\n"));
          yyresult = YYPUSH_MORE;
          goto yypushreturn;
        }
      yyps->yynew = 0;
yyread_pushed_token:
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yypushed_char;
      if (yypushed_val)
        yylval = *yypushed_val;
      if (yypushed_loc)
        yylloc = *yypushed_loc;
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
#line 416 "chapel.ypp" /* yacc.c:1661  */
    { yyblock = (yyval.pblockstmt); }
#line 4429 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 421 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt();                                  resetTempID(); }
#line 4435 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 422 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); context->generatedStmt = (yyvsp[-1].pblockstmt); resetTempID(); }
#line 4441 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 429 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPragmaStmt( (yyvsp[-1].vpch), (yyvsp[0].pblockstmt) ); }
#line 4447 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 434 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.vpch) = new Vec<const char*>(); (yyval.vpch)->add(astr((yyvsp[0].pch))); }
#line 4453 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 435 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].vpch)->add(astr((yyvsp[0].pch))); }
#line 4459 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 451 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 4465 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 452 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAtomicStmt((yyvsp[0].pblockstmt)); }
#line 4471 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 453 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildBeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 4477 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 454 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_BREAK, (yyvsp[-1].pch)); }
#line 4483 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 455 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCobeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));  }
#line 4489 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 456 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_CONTINUE, (yyvsp[-1].pch)); }
#line 4495 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 457 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_DELETE, (yyvsp[-1].pexpr)); }
#line 4501 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 458 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLabelStmt((yyvsp[-1].pch), (yyvsp[0].pblockstmt)); }
#line 4507 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 459 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[0].pblockstmt)); }
#line 4513 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 460 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildOnStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 4519 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 461 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildSerialStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 4525 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 462 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildSerialStmt(new SymExpr(gTrue), (yyvsp[0].pblockstmt)); }
#line 4531 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 463 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildSyncStmt((yyvsp[0].pblockstmt)); }
#line 4537 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 464 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_YIELD, (yyvsp[-1].pexpr)); }
#line 4543 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 465 "chapel.ypp" /* yacc.c:1661  */
    { printf("syntax error"); clean_exit(1); }
#line 4549 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 470 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(buildModule((yyvsp[-2].pch), new BlockStmt(), yyfilename, (yyvsp[-4].b), (yylsp[-4]).comment))); }
#line 4555 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 472 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(buildModule((yyvsp[-3].pch), (yyvsp[-1].pblockstmt), yyfilename, (yyvsp[-5].b), (yylsp[-5]).comment))); }
#line 4561 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 476 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 4567 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 477 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 4573 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 478 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = true; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 4579 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 493 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 4585 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 494 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt);              }
#line 4591 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 499 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); (yyval.pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 4597 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 500 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 4603 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 505 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyval.ponlylist)->push_back(cur); }
#line 4613 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 510 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyval.ponlylist)->push_back(cur); }
#line 4623 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 515 "chapel.ypp" /* yacc.c:1661  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyvsp[-2].ponlylist)->push_back(cur); }
#line 4632 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 519 "chapel.ypp" /* yacc.c:1661  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyvsp[-4].ponlylist)->push_back(cur); }
#line 4641 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 525 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-1].pcallexpr)); }
#line 4647 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 526 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true); }
#line 4653 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 527 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false); }
#line 4659 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 531 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildRequireStmt((yyvsp[-1].pcallexpr)); }
#line 4665 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 535 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "=");   }
#line 4671 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 536 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "+=");  }
#line 4677 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 537 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "-=");  }
#line 4683 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 538 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "*=");  }
#line 4689 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 539 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "/=");  }
#line 4695 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 540 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "%=");  }
#line 4701 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 541 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "**="); }
#line 4707 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 542 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "&=");  }
#line 4713 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 543 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "|=");  }
#line 4719 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 544 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "^=");  }
#line 4725 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 545 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), ">>="); }
#line 4731 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 546 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "<<="); }
#line 4737 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 547 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "<=>"); }
#line 4743 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 548 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLAndAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));    }
#line 4749 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 549 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLOrAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));     }
#line 4755 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 553 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = NULL; }
#line 4761 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 558 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 4767 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 562 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 4773 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 563 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 4779 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 567 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 4785 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 568 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 4791 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 572 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN, new SymExpr(gVoid)); }
#line 4797 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 573 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN, (yyvsp[-1].pexpr)); }
#line 4803 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 577 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new BlockStmt()); }
#line 4809 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 579 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 4815 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 580 "chapel.ypp" /* yacc.c:1661  */
    { applyPrivateToBlock((yyvsp[0].pblockstmt)); (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 4821 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 593 "chapel.ypp" /* yacc.c:1661  */
    {
#ifdef HAVE_LLVM
      if (externC) {
        (yyval.pblockstmt) = buildExternBlockStmt(astr((yyvsp[0].pch)));
      } else {
        USR_FATAL(new BlockStmt(), "extern block syntax is turned off. Use --extern-c flag to turn on.");
      }
#else
      USR_FATAL(new BlockStmt(), "Chapel must be built with llvm in order to use the extern block syntax");
#endif
    }
#line 4837 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 607 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = DoWhileStmt::build((yyvsp[-1].pexpr), (yyvsp[-3].pblockstmt)); }
#line 4843 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 608 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = WhileDoStmt::build((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 4849 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 609 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 4855 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 610 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), true); }
#line 4861 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 611 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 4867 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 612 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 4873 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 613 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 4879 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 614 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 4885 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 615 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 4891 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 616 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildParamForLoopStmt((yyvsp[-3].pch), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 4897 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 617 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt)); }
#line 4903 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 618 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt)); }
#line 4909 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 619 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt), true); }
#line 4915 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 620 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), true); }
#line 4921 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 621 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForallLoopStmt(NULL, (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt)); }
#line 4927 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 622 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForallLoopStmt(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt)); }
#line 4933 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 624 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)));
    }
#line 4943 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 630 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pexpr), "invalid index expression");
      (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)));
    }
#line 4953 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 636 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), true);
    }
#line 4963 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 642 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pexpr), "invalid index expression");
      (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), true);
    }
#line 4973 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 648 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = buildForallLoopStmt(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), NULL, new BlockStmt((yyvsp[0].pblockstmt)));
      else
        (yyval.pblockstmt) = buildForallLoopStmt(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(), NULL, new BlockStmt((yyvsp[0].pblockstmt)));
    }
#line 4984 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 655 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-3].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = buildForallLoopStmt(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-3].pcallexpr)), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)));
      else
        (yyval.pblockstmt) = buildForallLoopStmt(NULL, (yyvsp[-3].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)));
    }
#line 4995 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 664 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("_build_tuple", (yyvsp[-1].pcallexpr)); }
#line 5001 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 668 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-2].pexpr), (yyvsp[0].pblockstmt)); }
#line 5007 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 669 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5013 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 111:
#line 670 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-4].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 5019 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 112:
#line 671 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-3].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 5025 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 676 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(buildSelectStmt((yyvsp[-3].pexpr), (yyvsp[-1].pblockstmt))); }
#line 5031 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 680 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 5037 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 115:
#line 681 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 5043 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 116:
#line 686 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN, (yyvsp[-1].pcallexpr)), (yyvsp[0].pblockstmt)); }
#line 5049 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 117:
#line 688 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 5055 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 690 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 5061 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 697 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch), NULL, (yyvsp[-5].ptype), (yyvsp[-3].pcallexpr), (yyvsp[-1].pblockstmt), FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 5070 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 120:
#line 702 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch), (yyvsp[-6].pch), (yyvsp[-5].ptype), (yyvsp[-3].pcallexpr), (yyvsp[-1].pblockstmt), FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 5079 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 121:
#line 709 "chapel.ypp" /* yacc.c:1661  */
    {
             (yyval.ptype)                     = new AggregateType(AGGREGATE_CLASS);
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 5089 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 714 "chapel.ypp" /* yacc.c:1661  */
    {
             (yyval.ptype)                     = new AggregateType(AGGREGATE_RECORD);
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 5099 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 123:
#line 719 "chapel.ypp" /* yacc.c:1661  */
    {
             (yyval.ptype)                     = new AggregateType(AGGREGATE_UNION);
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 5109 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 124:
#line 727 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = NULL; }
#line 5115 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 125:
#line 728 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = (yyvsp[0].pcallexpr); }
#line 5121 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 126:
#line 733 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 5127 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 127:
#line 735 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pblockstmt)); }
#line 5133 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 128:
#line 737 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pblockstmt)->insertAtTail(buildPragmaStmt((yyvsp[-1].vpch), (yyvsp[0].pblockstmt))); }
#line 5139 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 129:
#line 742 "chapel.ypp" /* yacc.c:1661  */
    {
      EnumType* pdt = (yyvsp[-1].penumtype);
      TypeSymbol* pst = new TypeSymbol((yyvsp[-3].pch), pdt);
      (yyvsp[-1].penumtype)->symbol = pst;
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr(pst));
    }
#line 5150 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 130:
#line 752 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.penumtype) = new EnumType();
      (yyvsp[0].pdefexpr)->sym->type = (yyval.penumtype);
      (yyval.penumtype)->constants.insertAtTail((yyvsp[0].pdefexpr));
      (yyval.penumtype)->defaultValue = (yyvsp[0].pdefexpr)->sym;
      (yyval.penumtype)->doc = context->latestComment;
      context->latestComment = NULL;
    }
#line 5163 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 131:
#line 761 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.penumtype) = (yyvsp[-1].penumtype);
    }
#line 5171 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 765 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyvsp[-2].penumtype)->constants.insertAtTail((yyvsp[0].pdefexpr));
      (yyvsp[0].pdefexpr)->sym->type = (yyvsp[-2].penumtype);
    }
#line 5180 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 772 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[0].pch))); }
#line 5186 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 773 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr)); }
#line 5192 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 778 "chapel.ypp" /* yacc.c:1661  */
    {
      captureTokens = 1;
      captureString[0] = '\0';
    }
#line 5201 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 783 "chapel.ypp" /* yacc.c:1661  */
    {
      captureTokens = 0;
      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 5210 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 137:
#line 788 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyvsp[-5].pfnsymbol)->retTag = (yyvsp[-3].retTag);
      if ((yyvsp[-3].retTag) == RET_REF || (yyvsp[-3].retTag) == RET_CONST_REF)
        USR_FATAL("'ref' return types are not allowed in lambdas");
      if ((yyvsp[-3].retTag) == RET_PARAM)
        USR_FATAL("'param' return types are not allowed in lambdas");
      if ((yyvsp[-3].retTag) == RET_TYPE)
        USR_FATAL("'type' return types are not allowed in lambdas");
      if ((yyvsp[-2].pexpr))
        (yyvsp[-5].pfnsymbol)->retExprType = new BlockStmt((yyvsp[-2].pexpr), BLOCK_SCOPELESS);
      if ((yyvsp[-1].pexpr))
        (yyvsp[-5].pfnsymbol)->where = new BlockStmt((yyvsp[-1].pexpr));
      (yyvsp[-5].pfnsymbol)->insertAtTail((yyvsp[0].pblockstmt));
      (yyval.pexpr) = new DefExpr(buildLambda((yyvsp[-5].pfnsymbol)));
    }
#line 5230 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 808 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 5241 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 814 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");
                  (yyval.pfnsymbol)->addFlag(FLAG_INLINE);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 5253 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 821 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol((yyvsp[0].pch));
                  (yyval.pfnsymbol)->addFlag(FLAG_EXPORT);
                  (yyval.pfnsymbol)->addFlag(FLAG_LOCAL_ARGS);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 5266 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 829 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol((yyvsp[0].pch));
                  (yyval.pfnsymbol)->addFlag(FLAG_EXTERN);
                  (yyval.pfnsymbol)->addFlag(FLAG_LOCAL_ARGS);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 5279 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 840 "chapel.ypp" /* yacc.c:1661  */
    {
      // Sets up to capture tokens while parsing the next grammar nonterminal.
      captureTokens = 1;
      captureString[0] = '\0';
    }
#line 5289 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 143:
#line 846 "chapel.ypp" /* yacc.c:1661  */
    {
      // Stop capturing and save the result.
      captureTokens = 0;

      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 5300 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 144:
#line 853 "chapel.ypp" /* yacc.c:1661  */
    {
      FnSymbol* fn = (yyvsp[-5].pfnsymbol);

      fn->copyFlags((yyvsp[-8].pfnsymbol));
      // The user explicitly named this function (controls mangling).
      if (*(yyvsp[-8].pfnsymbol)->name)
        fn->cname = (yyvsp[-8].pfnsymbol)->name;

      if ((yyvsp[-7].procIter) == ProcIter_ITER)
      {
        if (fn->hasFlag(FLAG_EXTERN))
          USR_FATAL_CONT(fn, "'iter' is not legal with 'extern'");
        fn->addFlag(FLAG_ITERATOR_FN);
      }

      (yyval.pblockstmt) = buildFunctionDecl((yyvsp[-5].pfnsymbol), (yyvsp[-3].retTag), (yyvsp[-2].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), (yylsp[-8]).comment);
      context->latestComment = NULL;
    }
#line 5323 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 145:
#line 875 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
    }
#line 5331 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 879 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 5340 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 884 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pch));
    }
#line 5348 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 148:
#line 888 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pch));
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 5357 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 896 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = astr("~", (yyvsp[0].pch)); }
#line 5363 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 897 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "&"; }
#line 5369 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 152:
#line 898 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "|"; }
#line 5375 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 899 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "^"; }
#line 5381 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 154:
#line 900 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "~"; }
#line 5387 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 901 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "=="; }
#line 5393 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 156:
#line 902 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "!="; }
#line 5399 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 157:
#line 903 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<="; }
#line 5405 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 158:
#line 904 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">="; }
#line 5411 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 159:
#line 905 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<"; }
#line 5417 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 160:
#line 906 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">"; }
#line 5423 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 161:
#line 907 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "+"; }
#line 5429 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 162:
#line 908 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "-"; }
#line 5435 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 163:
#line 909 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "*"; }
#line 5441 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 164:
#line 910 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "/"; }
#line 5447 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 165:
#line 911 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<<"; }
#line 5453 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 166:
#line 912 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">>"; }
#line 5459 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 167:
#line 913 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "%"; }
#line 5465 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 168:
#line 914 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "**"; }
#line 5471 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 169:
#line 915 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "!"; }
#line 5477 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 170:
#line 916 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "chpl_by"; }
#line 5483 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 171:
#line 917 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "#"; }
#line 5489 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 172:
#line 918 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "chpl_align"; }
#line 5495 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 173:
#line 919 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<=>"; }
#line 5501 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 174:
#line 920 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<~>"; }
#line 5507 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 175:
#line 924 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "="; }
#line 5513 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 176:
#line 925 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "+="; }
#line 5519 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 177:
#line 926 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "-="; }
#line 5525 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 178:
#line 927 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "*="; }
#line 5531 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 179:
#line 928 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "/="; }
#line 5537 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 180:
#line 929 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "%="; }
#line 5543 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 181:
#line 930 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "**="; }
#line 5549 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 182:
#line 931 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "&="; }
#line 5555 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 183:
#line 932 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "|="; }
#line 5561 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 184:
#line 933 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "^="; }
#line 5567 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 185:
#line 934 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">>="; }
#line 5573 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 186:
#line 935 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<<="; }
#line 5579 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 187:
#line 939 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = new FnSymbol("_"); (yyval.pfnsymbol)->addFlag(FLAG_NO_PARENS); }
#line 5585 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 188:
#line 940 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 5591 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 189:
#line 944 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 5597 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 190:
#line 948 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, NULL); }
#line 5603 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 191:
#line 949 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, (yyvsp[0].pdefexpr)); }
#line 5609 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 192:
#line 950 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = buildFunctionFormal((yyvsp[-2].pfnsymbol), (yyvsp[0].pdefexpr)); }
#line 5615 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 193:
#line 955 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), (yyvsp[0].pexpr), NULL); }
#line 5621 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 194:
#line 957 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), NULL, (yyvsp[0].pexpr)); }
#line 5627 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 195:
#line 959 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildTupleArgDefExpr((yyvsp[-5].pt), (yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 5633 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 196:
#line 961 "chapel.ypp" /* yacc.c:1661  */
    { USR_FATAL("variable-length argument may not be grouped in a tuple"); }
#line 5639 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 197:
#line 965 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_BLANK; }
#line 5645 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 198:
#line 966 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = (yyvsp[0].pt); }
#line 5651 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 199:
#line 970 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_IN; }
#line 5657 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 200:
#line 971 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_INOUT; }
#line 5663 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 201:
#line 972 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_OUT; }
#line 5669 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 202:
#line 973 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST; }
#line 5675 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 203:
#line 974 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST_IN; }
#line 5681 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 204:
#line 975 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST_REF; }
#line 5687 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 205:
#line 976 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_PARAM; }
#line 5693 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 206:
#line 977 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_REF; }
#line 5699 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 207:
#line 978 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_TYPE; }
#line 5705 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 208:
#line 982 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_BLANK; }
#line 5711 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 209:
#line 983 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_PARAM; }
#line 5717 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 210:
#line 984 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_REF;   }
#line 5723 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 211:
#line 985 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_TYPE;  }
#line 5729 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 212:
#line 989 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.procIter) = ProcIter_PROC; }
#line 5735 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 213:
#line 990 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.procIter) = ProcIter_ITER; }
#line 5741 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 214:
#line 994 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_VALUE; }
#line 5747 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 215:
#line 995 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_VALUE; }
#line 5753 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 216:
#line 996 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_CONST_REF; }
#line 5759 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 217:
#line 997 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_REF; }
#line 5765 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 218:
#line 998 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_PARAM; }
#line 5771 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 219:
#line 999 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_TYPE; }
#line 5777 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 220:
#line 1003 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = NULL; }
#line 5783 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 223:
#line 1009 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt((yyvsp[0].pblockstmt)); }
#line 5789 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 224:
#line 1014 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 5795 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 225:
#line 1016 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol(astr("chpl__query", istr(query_uid++)))); }
#line 5801 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 226:
#line 1020 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol(astr("chpl__query", istr(query_uid++)))); }
#line 5807 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 228:
#line 1025 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 5813 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 229:
#line 1026 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[0].pdefexpr)->sym->addFlag(FLAG_PARAM); (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 5819 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 230:
#line 1030 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 5825 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 231:
#line 1031 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 5831 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 232:
#line 1036 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt); }
#line 5837 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 233:
#line 1038 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = handleConfigTypes((yyvsp[-1].pblockstmt)); }
#line 5843 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 234:
#line 1040 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = convertTypesToExtern((yyvsp[-1].pblockstmt)); }
#line 5849 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 235:
#line 1045 "chapel.ypp" /* yacc.c:1661  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-1].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[0].pexpr));

      (yyval.pblockstmt) = buildChapelStmt(def);
    }
#line 5866 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 236:
#line 1058 "chapel.ypp" /* yacc.c:1661  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-3].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[-2].pexpr));

      (yyvsp[0].pblockstmt)->insertAtHead(def);
      (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pblockstmt));
    }
#line 5884 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 237:
#line 1074 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 5890 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 238:
#line 1076 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 5896 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 239:
#line 1078 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExprFromArrayType((yyvsp[0].pcallexpr)); }
#line 5902 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 240:
#line 1083 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-3].flag));
      flags.insert(FLAG_PARAM);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-3]).comment);
      context->latestComment = NULL;
    }
#line 5914 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 241:
#line 1091 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-3].flag));
      flags.insert(FLAG_CONST);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-3]).comment);
      context->latestComment = NULL;
    }
#line 5926 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 242:
#line 1099 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-3].flag));
      flags.insert(FLAG_REF_VAR);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-3]).comment);
      context->latestComment = NULL;
    }
#line 5938 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 243:
#line 1107 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-4].flag));
      flags.insert(FLAG_CONST);
      flags.insert(FLAG_REF_VAR);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-4]).comment);
      context->latestComment = NULL;
    }
#line 5951 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 244:
#line 1116 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-3].flag));
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-3]).comment);
      context->latestComment = NULL;
    }
#line 5962 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 245:
#line 1125 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.flag) = FLAG_UNKNOWN; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 5968 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 246:
#line 1126 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.flag) = FLAG_CONFIG;  (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 5974 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 247:
#line 1127 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.flag) = FLAG_EXTERN;  (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 5980 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 249:
#line 1133 "chapel.ypp" /* yacc.c:1661  */
    {
      for_alist(expr, (yyvsp[0].pblockstmt)->body)
        (yyvsp[-2].pblockstmt)->insertAtTail(expr->remove());
    }
#line 5989 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 250:
#line 1141 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(new VarSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr), (yyvsp[-1].pexpr))); }
#line 5995 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 251:
#line 1143 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildTupleVarDeclStmt((yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 6001 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 252:
#line 1148 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol("chpl__tuple_blank")); }
#line 6007 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 253:
#line 1150 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 6013 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 254:
#line 1152 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[-1].pblockstmt); }
#line 6019 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 255:
#line 1157 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pexpr)); }
#line 6025 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 256:
#line 1159 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 6031 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 257:
#line 1161 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ((yyvsp[0].pblockstmt)->insertAtHead((yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 6037 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 258:
#line 1167 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 6043 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 259:
#line 1168 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(gNoInit); }
#line 6049 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 260:
#line 1169 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6055 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 261:
#line 1173 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 6061 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 262:
#line 1174 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6067 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 263:
#line 1175 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pcallexpr); }
#line 6073 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 264:
#line 1176 "chapel.ypp" /* yacc.c:1661  */
    {printf("bad type specification"); }
#line 6079 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 265:
#line 1197 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 6087 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 266:
#line 1201 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pcallexpr));
    }
#line 6095 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 267:
#line 1205 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)->get(1)->remove(),
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)->copy()));
    }
#line 6107 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 268:
#line 1212 "chapel.ypp" /* yacc.c:1661  */
    {printf("bad array type specification"); clean_exit(1); }
#line 6113 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 269:
#line 1216 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 6119 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 270:
#line 1217 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6125 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 271:
#line 1218 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 6131 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 272:
#line 1223 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 6137 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 273:
#line 1225 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 6143 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 274:
#line 1231 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 6149 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 275:
#line 1233 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 6155 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 276:
#line 1235 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pexpr), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)); }
#line 6161 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 277:
#line 1239 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 6167 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 278:
#line 1240 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6173 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 279:
#line 1241 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 6179 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 280:
#line 1242 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("_domain"); }
#line 6185 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 281:
#line 1243 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr( "_singlevar"); }
#line 6191 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 282:
#line 1244 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr( "_syncvar"); }
#line 6197 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 283:
#line 1245 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6203 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 284:
#line 1251 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 6209 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 285:
#line 1252 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pdefexpr)); }
#line 6215 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 286:
#line 1253 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 6221 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 287:
#line 1254 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pdefexpr)); }
#line 6227 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 288:
#line 1258 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("chpl__tuple_blank"); }
#line 6233 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 289:
#line 1259 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6239 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 290:
#line 1260 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 6245 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 291:
#line 1264 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6251 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 292:
#line 1265 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 6257 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 293:
#line 1269 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); }
#line 6263 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 295:
#line 1274 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 6269 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 296:
#line 1275 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 6275 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 297:
#line 1279 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pdefexpr)); }
#line 6281 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 298:
#line 1280 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pexpr)); }
#line 6287 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 299:
#line 1281 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildNamedAliasActual((yyvsp[-2].pch), (yyvsp[0].pexpr)); }
#line 6293 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 300:
#line 1282 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 6299 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 302:
#line 1287 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 6305 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 308:
#line 1304 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( "_singlevar", (yyvsp[0].pexpr)); }
#line 6311 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 309:
#line 1306 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildIndexType", (yyvsp[-1].pcallexpr)); }
#line 6317 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 310:
#line 1308 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainRuntimeType", new UnresolvedSymExpr("defaultDist"), (yyvsp[-1].pcallexpr)); }
#line 6323 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 311:
#line 1310 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSubDomainType", (yyvsp[-1].pcallexpr)); }
#line 6329 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 312:
#line 1312 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSparseDomainRuntimeType", buildDotExpr((yyvsp[-1].pcallexpr)->copy(), "defaultSparseDist"), (yyvsp[-1].pcallexpr)); }
#line 6335 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 313:
#line 1314 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__atomicType", (yyvsp[0].pexpr)); }
#line 6341 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 314:
#line 1316 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( "_syncvar", (yyvsp[0].pexpr)); }
#line 6347 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 315:
#line 1321 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6353 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 316:
#line 1323 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr), NULL, false, true); }
#line 6359 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 317:
#line 1325 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6365 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 318:
#line 1327 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 6371 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 319:
#line 1329 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 6377 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 320:
#line 1331 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 6383 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 321:
#line 1333 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6389 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 322:
#line 1335 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr), NULL, false, true); }
#line 6395 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 323:
#line 1337 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6401 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 324:
#line 1339 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 6407 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 325:
#line 1341 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 6413 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 326:
#line 1343 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 6419 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 327:
#line 1345 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pexpr) = buildForallLoopExpr(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr), NULL, true);
      else
        (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(), (yyvsp[0].pexpr), NULL, true);
    }
#line 6430 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 328:
#line 1352 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), (yyvsp[0].pexpr), NULL, true);
    }
#line 6440 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 329:
#line 1358 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), (yyvsp[0].pexpr), NULL, false, true);
    }
#line 6450 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 330:
#line 1364 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 6460 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 331:
#line 1370 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true);
    }
#line 6470 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 332:
#line 1379 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(new DefExpr(buildIfExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)))); }
#line 6476 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 333:
#line 1383 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(gNil); }
#line 6482 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 341:
#line 1399 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6488 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 342:
#line 1403 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = NULL; }
#line 6494 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 344:
#line 1408 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 6500 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 345:
#line 1413 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pIntentExpr).first, (yyvsp[0].pIntentExpr).second); }
#line 6506 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 346:
#line 1415 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pIntentExpr).first);
      (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pIntentExpr).second);
    }
#line 6515 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 347:
#line 1423 "chapel.ypp" /* yacc.c:1661  */
    {
      ArgSymbol* tiMark = tiMarkForIntent((yyvsp[-1].pt));
      if (!tiMark) {
        USR_FATAL_CONT((yyvsp[0].pexpr), "%s is not supported in a 'with' clause",
                           intentDescrString((yyvsp[-1].pt)));
        tiMark = tiMarkForIntent(INTENT_IN); //dummy, so parser can continue
      }
      (yyval.pIntentExpr).first = new SymExpr(tiMark);
      (yyval.pIntentExpr).second = (yyvsp[0].pexpr);
    }
#line 6530 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 348:
#line 1433 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pIntentExpr).first = (yyvsp[-2].pexpr), (yyval.pIntentExpr).second = (yyvsp[0].pexpr); }
#line 6536 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 349:
#line 1434 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pIntentExpr).first = (yyvsp[-2].pexpr), (yyval.pIntentExpr).second = (yyvsp[0].pexpr); }
#line 6542 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 351:
#line 1440 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6548 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 352:
#line 1445 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_NEW, (yyvsp[0].pexpr)); }
#line 6554 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 353:
#line 1450 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildLetExpr((yyvsp[-2].pblockstmt), (yyvsp[0].pexpr)); }
#line 6560 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 362:
#line 1466 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_TUPLE_EXPAND, (yyvsp[-1].pexpr)); }
#line 6566 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 363:
#line 1468 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("_cast", (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 6572 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 364:
#line 1470 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_bounded_range", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6578 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 365:
#line 1472 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_low_bounded_range", (yyvsp[-1].pexpr)); }
#line 6584 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 366:
#line 1474 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_high_bounded_range", (yyvsp[0].pexpr)); }
#line 6590 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 367:
#line 1476 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_unbounded_range"); }
#line 6596 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 374:
#line 1499 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 6602 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 375:
#line 1500 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildSquareCallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 6608 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 376:
#line 1501 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildPrimitiveExpr((yyvsp[-1].pcallexpr)); }
#line 6614 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 377:
#line 1505 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), (yyvsp[0].pch)); }
#line 6620 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 378:
#line 1506 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_TYPEOF, (yyvsp[-2].pexpr)); }
#line 6626 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 379:
#line 1507 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), "_dom"); }
#line 6632 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 380:
#line 1515 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 6638 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 381:
#line 1516 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildOneTuple((yyvsp[-2].pexpr)); }
#line 6644 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 382:
#line 1517 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildTuple((yyvsp[-1].pcallexpr)); }
#line 6650 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 383:
#line 1521 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildIntLiteral((yyvsp[0].pch));    }
#line 6656 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 384:
#line 1522 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildRealLiteral((yyvsp[0].pch));   }
#line 6662 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 385:
#line 1523 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildImagLiteral((yyvsp[0].pch));   }
#line 6668 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 386:
#line 1524 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildStringLiteral((yyvsp[0].pch)); }
#line 6674 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 387:
#line 1525 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildCStringLiteral((yyvsp[0].pch)); }
#line 6680 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 388:
#line 1526 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-1].pcallexpr)); }
#line 6686 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 389:
#line 1527 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-1].pcallexpr)); }
#line 6692 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 390:
#line 1529 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-1].pcallexpr));
    }
#line 6700 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 391:
#line 1535 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6706 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 392:
#line 1536 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[-2].pexpr)); (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 6712 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 393:
#line 1540 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6718 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 394:
#line 1541 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6724 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 395:
#line 1542 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("*", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6730 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 396:
#line 1543 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("/", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6736 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 397:
#line 1544 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6742 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 398:
#line 1545 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6748 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 399:
#line 1546 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("%", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6754 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 400:
#line 1547 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6760 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 401:
#line 1548 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("!=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6766 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 402:
#line 1549 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6772 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 403:
#line 1550 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6778 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 404:
#line 1551 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6784 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 405:
#line 1552 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6790 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 406:
#line 1553 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6796 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 407:
#line 1554 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("|", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6802 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 408:
#line 1555 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("^", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6808 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 409:
#line 1556 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("&&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6814 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 410:
#line 1557 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("||", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6820 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 411:
#line 1558 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("**", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6826 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 412:
#line 1559 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_by", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6832 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 413:
#line 1560 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_align", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6838 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 414:
#line 1561 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("#", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6844 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 415:
#line 1562 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__distributed", (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 6850 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 416:
#line 1566 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[0].pexpr)); }
#line 6856 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 417:
#line 1567 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[0].pexpr)); }
#line 6862 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 418:
#line 1568 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '-'); }
#line 6868 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 419:
#line 1569 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '+'); }
#line 6874 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 420:
#line 1570 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("!", (yyvsp[0].pexpr)); }
#line 6880 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 421:
#line 1571 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("~", (yyvsp[0].pexpr)); }
#line 6886 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 422:
#line 1575 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6892 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 423:
#line 1576 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr), true); }
#line 6898 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 424:
#line 1577 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6904 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 425:
#line 1578 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr), true); }
#line 6910 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 426:
#line 1582 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6916 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 427:
#line 1583 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr), true); }
#line 6922 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 428:
#line 1584 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6928 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 429:
#line 1585 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr), true); }
#line 6934 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 430:
#line 1590 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("SumReduceScanOp"); }
#line 6940 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 431:
#line 1591 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("ProductReduceScanOp"); }
#line 6946 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 432:
#line 1592 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalAndReduceScanOp"); }
#line 6952 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 433:
#line 1593 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalOrReduceScanOp"); }
#line 6958 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 434:
#line 1594 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseAndReduceScanOp"); }
#line 6964 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 435:
#line 1595 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseOrReduceScanOp"); }
#line 6970 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 436:
#line 1596 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseXorReduceScanOp"); }
#line 6976 "bison-chapel.cpp" /* yacc.c:1661  */
    break;


#line 6980 "bison-chapel.cpp" /* yacc.c:1661  */
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
      yyerror (&yylloc, context, YY_("syntax error"));
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
        yyerror (&yylloc, context, yymsgp);
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
                      yytoken, &yylval, &yylloc, context);
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
                  yystos[yystate], yyvsp, yylsp, context);
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
  yyerror (&yylloc, context, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, context);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, context);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  yyps->yynew = 1;

yypushreturn:
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
