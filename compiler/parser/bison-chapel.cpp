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
#line 32 "chapel.ypp" /* yacc.c:355  */

  #include <string>
  extern int         captureTokens;
  extern std::string captureString;
#line 45 "chapel.ypp" /* yacc.c:355  */

  #ifndef _BISON_CHAPEL_DEFINES_0_
  #define _BISON_CHAPEL_DEFINES_0_

  #define YYLEX_NEWLINE                  -1
  #define YYLEX_SINGLE_LINE_COMMENT      -2
  #define YYLEX_BLOCK_COMMENT            -3

  typedef void* yyscan_t;

  int processNewline(yyscan_t scanner);
  void stringBufferInit();

  #endif
#line 65 "chapel.ypp" /* yacc.c:355  */

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
    const char*               pch;

    Vec<const char*>*         vpch;
    RetTag                    retTag;
    AggregateTag              aggrTag;
    bool                      b;
    IntentTag                 pt;
    Expr*                     pexpr;
    DefExpr*                  pdefexpr;
    CallExpr*                 pcallexpr;
    BlockStmt*                pblockstmt;
    Type*                     ptype;
    EnumType*                 penumtype;
    std::vector<DefExpr*>*    pvecOfDefs;
    FnSymbol*                 pfnsymbol;
    Flag                      flag;
    ProcIter                  procIter;
    FlagSet*                  flagSet;
    ShadowVarSymbol*          pShadowVar;
    ShadowVarPrefix           pShadowVarPref;
    std::vector<OnlyRename*>* ponlylist;
  };

  #endif
#line 131 "chapel.ypp" /* yacc.c:355  */

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
#line 153 "chapel.ypp" /* yacc.c:355  */

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

#line 223 "bison-chapel.cpp" /* yacc.c:355  */

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
    TBOOL = 270,
    TBORROWED = 271,
    TBY = 272,
    TCATCH = 273,
    TCLASS = 274,
    TCOBEGIN = 275,
    TCOFORALL = 276,
    TCOMPLEX = 277,
    TCONFIG = 278,
    TCONST = 279,
    TCONTINUE = 280,
    TDEFER = 281,
    TDELETE = 282,
    TDMAPPED = 283,
    TDO = 284,
    TDOMAIN = 285,
    TELSE = 286,
    TENUM = 287,
    TEXCEPT = 288,
    TEXPORT = 289,
    TEXTERN = 290,
    TFALSE = 291,
    TFOR = 292,
    TFORALL = 293,
    TFORWARDING = 294,
    TIF = 295,
    TIMAG = 296,
    TIN = 297,
    TINDEX = 298,
    TINLINE = 299,
    TINOUT = 300,
    TINT = 301,
    TITER = 302,
    TLABEL = 303,
    TLAMBDA = 304,
    TLET = 305,
    TLOCAL = 306,
    TLOCALE = 307,
    TMINUSMINUS = 308,
    TMODULE = 309,
    TNEW = 310,
    TNIL = 311,
    TNOINIT = 312,
    TON = 313,
    TONLY = 314,
    TOTHERWISE = 315,
    TOUT = 316,
    TOVERRIDE = 317,
    TOWNED = 318,
    TPARAM = 319,
    TPLUSPLUS = 320,
    TPRAGMA = 321,
    TPRIMITIVE = 322,
    TPRIVATE = 323,
    TPROC = 324,
    TPROTOTYPE = 325,
    TPUBLIC = 326,
    TREAL = 327,
    TRECORD = 328,
    TREDUCE = 329,
    TREF = 330,
    TREQUIRE = 331,
    TRETURN = 332,
    TSCAN = 333,
    TSELECT = 334,
    TSERIAL = 335,
    TSHARED = 336,
    TSINGLE = 337,
    TSPARSE = 338,
    TSTRING = 339,
    TSUBDOMAIN = 340,
    TSYNC = 341,
    TTHEN = 342,
    TTHIS = 343,
    TTHROW = 344,
    TTHROWS = 345,
    TTRUE = 346,
    TTRY = 347,
    TTRYBANG = 348,
    TTYPE = 349,
    TUINT = 350,
    TUNDERSCORE = 351,
    TUNION = 352,
    TUNMANAGED = 353,
    TUSE = 354,
    TVAR = 355,
    TWHEN = 356,
    TWHERE = 357,
    TWHILE = 358,
    TWITH = 359,
    TYIELD = 360,
    TZIP = 361,
    TALIAS = 362,
    TAND = 363,
    TASSIGN = 364,
    TASSIGNBAND = 365,
    TASSIGNBOR = 366,
    TASSIGNBXOR = 367,
    TASSIGNDIVIDE = 368,
    TASSIGNEXP = 369,
    TASSIGNLAND = 370,
    TASSIGNLOR = 371,
    TASSIGNMINUS = 372,
    TASSIGNMOD = 373,
    TASSIGNMULTIPLY = 374,
    TASSIGNPLUS = 375,
    TASSIGNREDUCE = 376,
    TASSIGNSL = 377,
    TASSIGNSR = 378,
    TBAND = 379,
    TBNOT = 380,
    TBOR = 381,
    TBXOR = 382,
    TCOLON = 383,
    TCOMMA = 384,
    TDIVIDE = 385,
    TDOT = 386,
    TDOTDOT = 387,
    TDOTDOTDOT = 388,
    TEQUAL = 389,
    TEXP = 390,
    TGREATER = 391,
    TGREATEREQUAL = 392,
    THASH = 393,
    TIO = 394,
    TLESS = 395,
    TLESSEQUAL = 396,
    TMINUS = 397,
    TMOD = 398,
    TNOT = 399,
    TNOTEQUAL = 400,
    TOR = 401,
    TPLUS = 402,
    TQUESTION = 403,
    TSEMI = 404,
    TSHIFTLEFT = 405,
    TSHIFTRIGHT = 406,
    TSTAR = 407,
    TSWAP = 408,
    TLCBR = 409,
    TRCBR = 410,
    TLP = 411,
    TRP = 412,
    TLSBR = 413,
    TRSBR = 414,
    TNOELSE = 415,
    TUPLUS = 416,
    TUMINUS = 417
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
#line 184 "chapel.ypp" /* yacc.c:355  */

  extern int yydebug;

  void yyerror(YYLTYPE*       ignored,
               ParserContext* context,
               const char*    str);

#line 431 "bison-chapel.cpp" /* yacc.c:355  */

#endif /* !YY_YY_INCLUDE_BISON_CHAPEL_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 437 "bison-chapel.cpp" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 38 "chapel.ypp" /* yacc.c:359  */

  #include <string>
  int         captureTokens;
  std::string captureString;
#line 192 "chapel.ypp" /* yacc.c:359  */

  #include "build.h"
  #include "CatchStmt.h"
  #include "DeferStmt.h"
  #include "DoWhileStmt.h"
  #include "driver.h"
  #include "flex-chapel.h"
  #include "ForallStmt.h"
  #include "ForLoop.h"
  #include "IfExpr.h"
  #include "misc.h"
  #include "parser.h"
  #include "stmt.h"
  #include "stringutil.h"
  #include "TryStmt.h"
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

    // like USR_FATAL_CONT
    setupError("parser", __FILE__, __LINE__, 3);

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
  }

#line 511 "bison-chapel.cpp" /* yacc.c:359  */

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
#define YYLAST   15924

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  163
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  134
/* YYNRULES -- Number of rules.  */
#define YYNRULES  556
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  998

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   417

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
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   466,   466,   471,   472,   478,   479,   484,   485,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   523,
     526,   528,   534,   535,   536,   540,   541,   554,   555,   556,
     561,   562,   567,   572,   577,   581,   588,   593,   597,   602,
     606,   607,   608,   612,   616,   618,   620,   622,   624,   631,
     632,   636,   637,   638,   641,   642,   643,   655,   656,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   686,   687,   688,   689,   690,
     691,   692,   693,   700,   701,   702,   703,   704,   705,   706,
     707,   712,   713,   717,   718,   722,   723,   727,   728,   729,
     730,   731,   732,   733,   734,   738,   739,   743,   744,   745,
     746,   750,   757,   758,   759,   760,   761,   762,   763,   764,
     765,   766,   767,   768,   769,   770,   771,   772,   773,   779,
     785,   791,   797,   804,   814,   818,   819,   820,   821,   822,
     824,   826,   828,   833,   836,   837,   838,   839,   840,   841,
     845,   846,   850,   851,   852,   856,   857,   861,   864,   866,
     871,   872,   876,   878,   880,   887,   897,   907,   917,   930,
     935,   940,   948,   949,   954,   955,   957,   962,   978,   985,
     994,  1002,  1006,  1013,  1014,  1019,  1024,  1018,  1049,  1055,
    1062,  1068,  1074,  1085,  1091,  1084,  1123,  1127,  1132,  1136,
    1141,  1148,  1149,  1153,  1154,  1155,  1156,  1157,  1158,  1159,
    1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,
    1170,  1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,
    1193,  1197,  1198,  1202,  1206,  1207,  1208,  1212,  1214,  1216,
    1218,  1220,  1225,  1226,  1230,  1231,  1232,  1233,  1234,  1235,
    1236,  1237,  1238,  1242,  1243,  1244,  1245,  1246,  1247,  1251,
    1252,  1256,  1257,  1258,  1259,  1260,  1261,  1265,  1266,  1269,
    1270,  1274,  1275,  1279,  1281,  1286,  1287,  1291,  1292,  1296,
    1297,  1301,  1303,  1305,  1310,  1323,  1340,  1341,  1343,  1348,
    1356,  1364,  1372,  1381,  1391,  1392,  1393,  1397,  1398,  1406,
    1408,  1413,  1415,  1417,  1422,  1424,  1426,  1433,  1434,  1435,
    1440,  1442,  1444,  1448,  1452,  1454,  1458,  1466,  1467,  1468,
    1469,  1470,  1475,  1476,  1477,  1478,  1479,  1499,  1503,  1507,
    1515,  1522,  1523,  1524,  1528,  1530,  1536,  1538,  1540,  1545,
    1546,  1547,  1548,  1549,  1555,  1556,  1557,  1558,  1562,  1563,
    1567,  1568,  1569,  1573,  1574,  1578,  1579,  1583,  1584,  1588,
    1589,  1590,  1591,  1595,  1596,  1607,  1608,  1609,  1610,  1611,
    1612,  1614,  1616,  1618,  1620,  1622,  1624,  1626,  1628,  1630,
    1632,  1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,  1653,
    1655,  1657,  1659,  1661,  1668,  1674,  1680,  1686,  1695,  1705,
    1713,  1714,  1715,  1716,  1717,  1718,  1719,  1720,  1725,  1726,
    1730,  1734,  1735,  1739,  1743,  1744,  1748,  1752,  1756,  1763,
    1764,  1765,  1766,  1767,  1768,  1772,  1773,  1778,  1783,  1791,
    1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1801,  1803,
    1805,  1807,  1809,  1811,  1813,  1818,  1819,  1822,  1823,  1824,
    1827,  1828,  1829,  1830,  1841,  1842,  1846,  1847,  1848,  1852,
    1853,  1854,  1855,  1863,  1864,  1865,  1866,  1870,  1871,  1875,
    1876,  1877,  1878,  1879,  1880,  1881,  1882,  1883,  1884,  1885,
    1889,  1897,  1898,  1902,  1903,  1904,  1905,  1906,  1907,  1908,
    1909,  1910,  1911,  1912,  1913,  1914,  1915,  1916,  1917,  1918,
    1919,  1920,  1921,  1922,  1923,  1924,  1928,  1929,  1930,  1931,
    1932,  1933,  1937,  1938,  1939,  1940,  1944,  1945,  1946,  1947,
    1952,  1953,  1954,  1955,  1956,  1957,  1958
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENT", "INTLITERAL", "REALLITERAL",
  "IMAGLITERAL", "STRINGLITERAL", "CSTRINGLITERAL", "EXTERNCODE", "TALIGN",
  "TAS", "TATOMIC", "TBEGIN", "TBREAK", "TBOOL", "TBORROWED", "TBY",
  "TCATCH", "TCLASS", "TCOBEGIN", "TCOFORALL", "TCOMPLEX", "TCONFIG",
  "TCONST", "TCONTINUE", "TDEFER", "TDELETE", "TDMAPPED", "TDO", "TDOMAIN",
  "TELSE", "TENUM", "TEXCEPT", "TEXPORT", "TEXTERN", "TFALSE", "TFOR",
  "TFORALL", "TFORWARDING", "TIF", "TIMAG", "TIN", "TINDEX", "TINLINE",
  "TINOUT", "TINT", "TITER", "TLABEL", "TLAMBDA", "TLET", "TLOCAL",
  "TLOCALE", "TMINUSMINUS", "TMODULE", "TNEW", "TNIL", "TNOINIT", "TON",
  "TONLY", "TOTHERWISE", "TOUT", "TOVERRIDE", "TOWNED", "TPARAM",
  "TPLUSPLUS", "TPRAGMA", "TPRIMITIVE", "TPRIVATE", "TPROC", "TPROTOTYPE",
  "TPUBLIC", "TREAL", "TRECORD", "TREDUCE", "TREF", "TREQUIRE", "TRETURN",
  "TSCAN", "TSELECT", "TSERIAL", "TSHARED", "TSINGLE", "TSPARSE",
  "TSTRING", "TSUBDOMAIN", "TSYNC", "TTHEN", "TTHIS", "TTHROW", "TTHROWS",
  "TTRUE", "TTRY", "TTRYBANG", "TTYPE", "TUINT", "TUNDERSCORE", "TUNION",
  "TUNMANAGED", "TUSE", "TVAR", "TWHEN", "TWHERE", "TWHILE", "TWITH",
  "TYIELD", "TZIP", "TALIAS", "TAND", "TASSIGN", "TASSIGNBAND",
  "TASSIGNBOR", "TASSIGNBXOR", "TASSIGNDIVIDE", "TASSIGNEXP",
  "TASSIGNLAND", "TASSIGNLOR", "TASSIGNMINUS", "TASSIGNMOD",
  "TASSIGNMULTIPLY", "TASSIGNPLUS", "TASSIGNREDUCE", "TASSIGNSL",
  "TASSIGNSR", "TBAND", "TBNOT", "TBOR", "TBXOR", "TCOLON", "TCOMMA",
  "TDIVIDE", "TDOT", "TDOTDOT", "TDOTDOTDOT", "TEQUAL", "TEXP", "TGREATER",
  "TGREATEREQUAL", "THASH", "TIO", "TLESS", "TLESSEQUAL", "TMINUS", "TMOD",
  "TNOT", "TNOTEQUAL", "TOR", "TPLUS", "TQUESTION", "TSEMI", "TSHIFTLEFT",
  "TSHIFTRIGHT", "TSTAR", "TSWAP", "TLCBR", "TRCBR", "TLP", "TRP", "TLSBR",
  "TRSBR", "TNOELSE", "TUPLUS", "TUMINUS", "$accept", "program",
  "toplevel_stmt_ls", "toplevel_stmt", "pragma_ls", "stmt",
  "module_decl_stmt", "access_control", "opt_prototype", "block_stmt",
  "stmt_ls", "only_ls", "opt_only_ls", "except_ls", "use_stmt",
  "require_stmt", "assignment_stmt", "opt_label_ident", "ident_fn_def",
  "ident_def", "ident_use", "internal_type_ident_def", "scalar_type",
  "reserved_type_ident_use", "opt_string", "do_stmt", "return_stmt",
  "class_level_stmt", "private_decl", "forwarding_stmt",
  "extern_block_stmt", "loop_stmt", "zippered_iterator", "if_stmt",
  "defer_stmt", "try_stmt", "catch_stmt_ls", "catch_stmt", "catch_expr",
  "throw_stmt", "select_stmt", "when_stmt_ls", "when_stmt",
  "class_decl_stmt", "class_tag", "opt_inherit", "class_level_stmt_ls",
  "enum_decl_stmt", "enum_header", "enum_ls", "enum_item",
  "lambda_decl_expr", "$@1", "$@2", "linkage_spec", "fn_decl_stmt", "$@3",
  "$@4", "fn_decl_stmt_inner", "fn_decl_receiver_expr", "fn_ident",
  "assignop_ident", "opt_formal_ls", "req_formal_ls", "formal_ls",
  "formal", "opt_intent_tag", "required_intent_tag", "opt_this_intent_tag",
  "proc_or_iter", "opt_ret_tag", "opt_throws_error",
  "opt_function_body_stmt", "function_body_stmt", "query_expr",
  "opt_query_expr", "var_arg_expr", "opt_where_part",
  "type_alias_decl_stmt", "type_alias_decl_stmt_inner", "opt_init_type",
  "var_decl_stmt", "opt_config", "var_decl_stmt_inner_ls",
  "var_decl_stmt_inner", "tuple_var_decl_component",
  "tuple_var_decl_stmt_inner_ls", "opt_init_expr", "ret_array_type",
  "opt_ret_type", "opt_type", "array_type", "opt_formal_array_elt_type",
  "formal_array_type", "opt_formal_type", "expr_ls", "simple_expr_ls",
  "tuple_component", "tuple_expr_ls", "opt_actual_ls", "actual_ls",
  "actual_expr", "ident_expr", "type_level_expr", "for_expr", "cond_expr",
  "nil_expr", "stmt_level_expr", "opt_task_intent_ls",
  "task_intent_clause", "task_intent_ls", "forall_intent_clause",
  "forall_intent_ls", "intent_expr", "shadow_var_prefix", "io_expr",
  "new_expr", "let_expr", "expr", "opt_expr", "opt_try_expr", "lhs_expr",
  "fun_expr", "call_expr", "dot_expr", "parenthesized_expr",
  "bool_literal", "literal_expr", "assoc_expr_ls", "binary_op_expr",
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
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417
};
# endif

#define YYPACT_NINF -907

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-907)))

#define YYTABLE_NINF -508

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -907,   120,  2664,  -907,     3,  -907,  -907,  -907,  -907,  -907,
    -907,  4071,    77,   246,  -907,  9333,  -907,    77,  9333,  -907,
     158,   246,  4071,  9333,  4071,   134,  -907,  9333,  6258,  -907,
    7732,  9333,  7888,  9333,  -907,   148,  -907,  -907, 15826,  -907,
    1966,  8443,  -907,  9333,  9333,  -907,  9333,  -907,  9333,  9333,
     351,   175,  1258,  1411,  -907,  -907,  8576,  7287,  9333,  8443,
    9333,  9333,   276,  -907,   220,  4071,  -907,  9333,  -907,  9466,
    9466, 15826,  -907,  -907,  9333,  8576,  9333,  9333,  -907,  -907,
    9333,  -907,  -907, 11461,  9333,  9333,  -907,  9333,  -907,  -907,
    3135,  6547,  8576,  -907,  3915,  -907,  -907,   316,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907, 15826,  -907, 15826,   243,
     171,  -907,  -907,  -907,   146,   254,  -907,  -907,  -907,   264,
     270,   284,   279,   288, 15518,  2019,    41,   293,   295,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,    88,  -907,  -907, 15518,
     296,  4071,  -907,  -907,   298,  9333,  9333,  9333,  9333,  9333,
    8576,  8576,   191,  -907,  -907,  -907,  -907,   328,   266,  -907,
    -907,   301, 13773, 15826,   313,  -907,   133, 15518,   369,  7443,
   15518,  -907,    38,  -907, 15826,   138,  -907, 15826,   317,    42,
   13310, 13259,  -907,  -907,  -907, 13694, 12572,  7443,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  4071,  -907,   325,   173,
      98,     9,  -907,  4071,  -907,  -907, 13448,   501,   328, 13448,
     328,   501,  -907,  7443,  8021,  -907,  -907, 15826,  -907,   135,
   15518,  9333,  9333,  -907, 15518,   333, 13624,  -907, 13448,   328,
   15518,   327,  7443,  -907, 15518, 14019,  -907,  -907, 14070, 11719,
    -907,  -907, 14157,   365,   336,   328,   201, 13843, 13448, 14208,
     332,  2806,   501,   332,   501,   136,  -907,  -907,  3291,   -88,
    -907,  9333,  -907,   -24,    72,  -907,    -3, 14295,     2,   479,
    -907,  -907,   435,   362,   337,  -907,  -907,  -907,  1293,  1966,
    1966,  1966,  -907,  9333,  9333,  9333,  9333,  8732,  8732,  9333,
    9333,  9333,  9333,  9599,  9333,   428, 11461,  9333,  9333,  9333,
    9333,  9333,  9333,  9333,  9333,  9333,  9333,  9333,  9333,  9333,
    9333,  9333,  -907,  -907,  -907,  -907,  -907,  -907,  8154,  8154,
    -907,  -907,  -907,  -907,  8154,  -907,  -907,  8154,  8154,  7443,
    7443,  8732,  8732,  7015,  -907,  -907, 13918, 13988, 14244,    10,
    3447,  -907,  8732,    42,   346,  -907,  9333,  -907,  9333,   387,
    -907,   341,   370,  -907,  -907,   353, 15826,   461,  8576,  -907,
    4227,  8732,  -907,  4383,  8732,   344,  -907,    42,  9732,  9333,
    -907,  4071,   474,  9333,   350,  -907,   657,  -907,  -907,   173,
    -907,   386,   363,  -907,  9865,   415,  9333,  1966,  -907,  -907,
    -907,   368,  -907,  8576,  -907, 15518, 15518,  -907,    35,  -907,
    7443,   373,  -907,   509,  -907,   509,  -907,  9998,   405,  -907,
    -907,  9732,  9333,  -907,  -907,  -907,  -907,  -907,  8287,  -907,
   12422,  6703,  -907,  6859,  -907,  8732,  5787,  2979,   378,  9333,
    6101,  -907,  -907, 15826,  8576,   385, 15773,   169,  1966,   203,
     214,   215,   230, 14382, 15619, 15619,   318,  -907,   318,  -907,
     318,  2476,   326,   539,  1090, 11848, 11848,   328,   332,  -907,
    -907,  -907,  -907,  2806, 12247,   318,  2267,  2267, 15619,  2267,
    2267,  1061,   332, 12247, 15670,  1061,   501,   501,   332,   393,
     394,   395,   396,   397,   392,   402,  -907,   318,  -907,   318,
      55,  -907,  -907,  -907,   108,  -907,  1057, 15588,   320, 10131,
    8732, 10264,  8732,  9333,  8732, 12040,    77, 14433,  -907,  -907,
   15518, 14464,  7443,  -907,  7443,  -907,   362,  9333,   109,  9333,
   15518,    48, 13479,  9333, 15518,    33, 13397,  7015,  -907,   404,
     422,   413, 14534,   422,   414,   523, 14609,  4071, 13549,  -907,
      90,  -907,  -907,  -907,  -907,  -907,  -907,   828,   110,  -907,
    2220,  -907,   321,   407,   173,    98,  9333,   134,   148,  9333,
    9333,  9333,  9333,  9333,  5631,  -907,  -907,   429,  7599,  -907,
   15518,  -907,  -907,  -907, 15518,   411,    54,   417,  -907,  2167,
    -907,  -907,   258, 15826,   427,   432,  -907,  -907,  -907,  -907,
    -907,  -907,   -43,  2437,  -907,  -907, 15518,  4071, 15518,  -907,
   14679,   430,   453,  1388,   434,   478,    62,  -907,   515,  -907,
    -907,  -907,  -907,  7133,   259,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  7015,  -907,
      14,  8732,  8732,  9333,   562, 14754,  9333,   564, 14824,   440,
   12207,    42,    42,  -907,  -907,  -907,  -907,   446, 13448,  -907,
   12647,  4539,  -907,  4695,  -907, 12722,  4851,  -907,    42,  5007,
    -907,    42,   121,  -907,  9333,  -907,  9333,  -907,  4071,  9333,
    -907,  4071,   570,  -907,  -907, 15826,   984,  -907,   173,   475,
     529,  -907,  -907,  -907,    26,  -907,  -907,   415,   447,    56,
    -907,  -907,  -907,  5163,  8576,  -907,  -907,  -907, 15826,  -907,
     477,   301,  -907,  -907,  -907,  5319,   450,  5475,   452,  -907,
    9333,  3603,   463,   970,  -907,  9333, 15826,  -907,  -907,   321,
     460,   488,  -907,   489,  -907,   490,   491,   494,   495,   496,
     497,   499,   502,  -907, 15826,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  9333,  -907,  -907,   504,   460,
     460,  -907,  -907,  -907,   415,   124,   129, 14855, 10397, 10530,
   14993, 10663, 10796, 10929, 11062,  -907,  -907,  1818,  -907,  4071,
    9333, 15518,  9333, 15518,  4071,  9333, 15518,  -907,  9333, 15518,
    -907,  7015,  -907, 14906, 15518,  -907, 15518,   607,  4071,   475,
    -907,   482,  8865,   139,  -907,   541,  -907,  -907,  8732, 11944,
    4071,  -907,    46,   500,  9333,  -907,  9333,  -907, 15518,  4071,
    9333,  -907, 15518,  4071, 15518,   256,  -907,  3759,  -907,  6414,
     937,   937,  -907,  2432,  -907, 15518,  -907,    23,   657,  -907,
    -907, 12497, 12127,  -907,  -907,  -907,  9333,  9333,  9333,  9333,
    9333,  9333,  9333,  9333,   492,  2293, 14609, 12797, 12872, 14609,
   12947, 13022,  -907,  9333,  4071,  -907,   415,   475,  5944,  -907,
    -907,  -907,   -23,  8576,  -907,  -907,  9333,     5, 12277,  -907,
     656,   369,  -907,   301, 15518, 13097,  -907, 13172,  -907,  -907,
    -907,  -907,  -907, 11195,   556,   131,  -907,  -907,  -907,   460,
     460, 15068, 15143, 15218, 15293, 15368, 15443,  -907,  -907,  4071,
    4071,  4071,  4071, 15518,  -907,  -907,   139,  9021,    65,  -907,
    -907, 15518, 15518,  -907,  -907,  -907, 11062,  -907,  4071,  4071,
    2820,  -907,  -907,   291,  -907,   541,  -907,  -907,  -907,  9333,
    9333,  9333,  9333,  9333,  9333, 14609, 14609, 14609, 14609,  -907,
    -907,  -907,  -907,  -907,    99,  8732, 11594,   658, 14609, 14609,
     493, 11328,    75,    25, 12352,  -907,  -907,  -907,  -907,   339,
   11725,  -907,  -907,  -907,  9177,  -907,   458,  -907
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,     1,     0,    77,   500,   501,   502,   503,
     504,     0,   438,    69,    95,     0,   189,   438,     0,   100,
     325,    69,     0,     0,     0,     0,   199,   475,   326,   497,
       0,     0,   324,     0,    99,     0,   209,    96,     0,   205,
       0,     0,   102,     0,     0,   429,     0,   212,     0,     0,
       0,     0,   324,   324,    98,   190,     0,     0,     0,     0,
       0,     0,     0,   101,     0,     0,    78,     0,   498,     0,
       0,     0,    97,   191,     0,     0,     0,     0,   552,   554,
       0,   555,   556,   474,     0,     0,   553,   550,   117,   551,
       0,     0,     0,     4,     0,     5,     9,    45,    10,    11,
      12,    14,   393,   394,    22,    13,   118,   124,    15,    17,
      16,    19,    20,    21,    18,   123,     0,   121,     0,   464,
       0,   125,   122,   126,     0,   480,   460,   461,   397,   395,
       0,     0,   465,   466,     0,   396,     0,   481,   482,   483,
     499,   459,   399,   398,   462,   463,     0,    38,    24,   405,
       0,     0,   439,    70,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   480,   395,   465,   466,   407,   396,   481,
     482,     0,   438,     0,     0,   163,     0,   378,     0,   385,
     476,   210,   503,   131,     0,     0,   211,     0,     0,     0,
       0,     0,   325,   326,   130,     0,     0,   385,    74,    79,
      90,    84,    92,    83,    93,    80,    94,    88,    82,    89,
      87,    85,    86,    75,    81,    91,     0,    76,     0,     0,
       0,     0,   327,     0,   114,    32,     0,   538,   457,     0,
     408,   539,     7,   385,   326,   120,   119,   304,   375,     0,
     374,     0,     0,   115,   479,     0,     0,    35,     0,   410,
     400,     0,   385,    36,   406,     0,   170,   166,     0,   396,
     170,   167,     0,   316,     0,   409,     0,   374,     0,     0,
     541,   473,   537,   540,   536,     0,    47,    50,     0,     0,
     380,     0,   382,     0,     0,   381,     0,   374,     0,     0,
       6,    46,     0,   192,     0,   290,   289,   213,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   472,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   249,   256,   257,   258,   253,   255,     0,     0,
     251,   254,   252,   250,     0,   260,   259,     0,     0,   385,
     385,     0,     0,     0,    25,    26,     0,     0,     0,     0,
       0,    27,     0,     0,     0,    28,     0,    29,     0,   393,
     391,     0,   386,   387,   392,     0,     0,     0,     0,   140,
       0,     0,   139,     0,     0,     0,   146,     0,     0,    56,
     127,     0,   156,     0,     0,    30,   272,   206,   331,     0,
     332,   334,     0,   356,     0,   337,     0,     0,   113,    31,
      33,     0,   303,     0,    63,   477,   478,   116,     0,    34,
     385,     0,   177,   168,   164,   169,   165,     0,   314,   311,
      60,     0,    56,   133,    37,    49,    48,    51,     0,   505,
       0,     0,   493,     0,   495,     0,     0,     0,     0,     0,
       0,   509,     8,     0,     0,     0,     0,   283,     0,     0,
       0,     0,     0,   437,   533,   532,   535,   543,   542,   547,
     546,   529,   526,   527,   528,   469,   470,   468,   516,   491,
     492,   490,   489,   471,   520,   531,   525,   523,   534,   524,
     522,   514,   519,   521,   530,   513,   517,   518,   515,     0,
       0,     0,     0,     0,     0,     0,   545,   544,   549,   548,
     449,   450,   452,   454,     0,   441,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   507,   438,   438,   136,   312,
     379,     0,     0,   402,     0,   313,   192,     0,     0,     0,
     413,     0,     0,     0,   419,     0,     0,     0,   147,   551,
      59,     0,    52,    57,     0,   155,     0,     0,     0,   401,
     277,   274,   275,   276,   280,   281,   282,   272,     0,   265,
       0,   273,   291,     0,   335,     0,   107,   109,   110,   105,
     106,   104,   103,   108,     0,   355,   354,   460,     0,   329,
     458,   328,   488,   377,   376,     0,     0,     0,   403,     0,
     171,   318,   460,     0,     0,     0,   506,   467,   494,   383,
     496,   384,     0,     0,   508,   152,   423,     0,   511,   510,
       0,     0,   193,     0,     0,   203,     0,   200,   287,   284,
     285,   288,   214,     0,     0,   320,   319,   321,   323,    67,
      68,    66,    65,    64,   486,   487,   451,   453,     0,   440,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   132,   389,   390,   388,     0,     0,   154,
       0,     0,   138,     0,   137,     0,     0,   144,     0,     0,
     142,     0,     0,   444,     0,   128,     0,   129,     0,     0,
     158,     0,   160,   278,   279,     0,   272,   263,     0,   369,
     292,   295,   294,   296,     0,   333,   336,   337,     0,     0,
     338,   339,   179,     0,     0,   178,   181,   404,     0,   172,
     175,     0,   315,    61,    62,     0,     0,     0,     0,   153,
       0,     0,     0,   324,   198,     0,   201,   197,   286,   291,
     261,    71,   246,    79,   244,    84,    83,    80,    94,    82,
      85,    72,    81,   225,   228,   226,   227,   238,   229,   242,
     234,   232,   245,   248,   233,   231,   236,   241,   243,   230,
     235,   239,   240,   237,   247,     0,   223,    73,     0,   261,
     261,   221,   322,   442,   337,   480,   480,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   134,     0,   141,     0,
       0,   412,     0,   411,     0,     0,   418,   145,     0,   417,
     143,     0,   443,    54,    53,   157,   428,   159,     0,   369,
     266,     0,     0,   337,   293,   309,   330,   360,     0,   507,
       0,   183,     0,     0,     0,   173,     0,   150,   425,     0,
       0,   148,   424,     0,   512,     0,    39,     0,   187,   326,
     324,   324,   185,   324,   195,   204,   202,     0,   272,   220,
     224,     0,     0,   216,   217,   446,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   324,   416,     0,     0,   422,
       0,     0,   445,     0,     0,   162,   337,   369,     0,   372,
     371,   373,   460,   305,   269,   267,     0,     0,     0,   358,
     460,   184,   182,     0,   176,     0,   151,     0,   149,    41,
      40,   196,   351,     0,   297,     0,   222,    71,    72,   261,
     261,     0,     0,     0,     0,     0,     0,   188,   186,     0,
       0,     0,     0,    55,   161,   268,   337,   361,     0,   306,
     308,   307,   310,   301,   302,   207,     0,   174,     0,     0,
       0,   350,   349,   460,   298,   309,   262,   218,   219,     0,
       0,     0,     0,     0,     0,   415,   414,   421,   420,   271,
     270,   363,   364,   366,   460,     0,   507,   460,   427,   426,
       0,   341,     0,     0,     0,   365,   367,   346,   344,   460,
     507,   299,   215,   300,   361,   345,   460,   368
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -907,  -907,  -907,    -1,  -371,  1811,  -907,  -907,  -907,  1556,
     -83,  -311,   222,   227,  -907,  -907,   204,   638,  -907,   953,
    -137,  -619,  -907,  -794,  -907,   366,  -842,  -693,   -47,  -907,
    -907,  -907,   -28,  -907,  -907,  -907,   401,  -907,   -54,  -907,
    -907,  -907,  -907,  -907,   486,   141,  -125,  -907,  -907,  -907,
     -57,   819,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -179,  -132,  -736,  -907,  -173,   -10,   125,  -907,  -907,  -907,
     -52,  -907,  -907,  -295,   300,  -907,  -243,  -261,  -907,  -155,
    -907,   663,  -907,  -207,   289,  -907,  -376,  -694,  -823,  -907,
    -541,  -417,  -906,  -854,  -734,    12,  -907,  -154,  -907,  -144,
    -907,   163,   324,  -396,  -907,  -907,   869,  -907,    -8,  -907,
    -907,  -162,  -907,  -536,  -907,  -907,  1084,  1273,   -11,   674,
      27,   586,  -907,  1349,  1713,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -327
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   277,    94,   555,    96,    97,   292,    98,
     278,   550,   554,   551,    99,   100,   101,   154,   776,   220,
     102,   217,   103,   585,   185,   225,   104,   105,   106,   107,
     108,   109,   659,   110,   111,   112,   423,   600,   721,   113,
     114,   596,   716,   115,   116,   455,   733,   117,   118,   626,
     627,   162,   218,   572,   120,   121,   457,   739,   632,   778,
     779,   393,   859,   397,   568,   569,   570,   571,   633,   297,
     704,   955,   992,   945,   238,   940,   894,   897,   122,   264,
     428,   123,   124,   221,   222,   401,   402,   589,   952,   914,
     405,   586,   972,   891,   823,   279,   176,   283,   284,   371,
     372,   373,   163,   126,   127,   128,   164,   130,   151,   152,
     514,   387,   682,   515,   516,   131,   165,   166,   134,   186,
     374,   168,   136,   169,   170,   139,   140,   141,   288,   142,
     143,   144,   145,   146
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     149,    93,   189,   348,   167,   235,   236,   172,   587,   171,
     601,   683,   177,   826,   777,   403,   180,   180,   364,   190,
     191,   195,   196,   573,   912,   567,   518,   403,   889,   375,
     226,   602,   227,   228,   707,   229,   595,   230,   231,   445,
     854,   438,   369,   863,   864,   240,   244,   246,   248,   249,
     250,   406,   524,   394,   254,   944,   255,  -112,   258,   262,
     369,   385,   676,   265,   267,   268,   269,   439,   239,   270,
     985,   223,   271,   272,   273,   223,   274,   671,   553,   240,
     244,   287,    57,   973,   245,   886,  -370,   266,   997,   411,
     865,   459,   460,   461,   462,  -180,   369,   646,   828,   403,
    -347,   385,    57,  -352,   286,   441,  -370,   975,   421,   784,
    -370,  -112,   783,  -347,   713,   369,   725,   524,   285,   951,
       3,   553,   986,  -352,   448,  -347,   446,   348,  -352,   895,
     647,   450,   693,   442,  -370,  -112,  -180,   385,   407,   446,
    -352,   944,   404,  -352,   149,   356,   357,   358,   254,   240,
     287,   913,   147,   936,   404,   714,   447,    16,   988,   360,
     911,   451,   351,   825,   363,   694,   352,   995,   244,   525,
     298,  -352,  -347,   359,   991,   413,   198,  -347,   482,   360,
    -352,   150,   854,   957,   958,   446,   244,   360,   199,   200,
    -180,   736,   935,   628,   446,   201,   360,   349,   706,   350,
     360,   443,   360,   202,   446,   504,   505,  -352,  -362,   715,
     299,    55,   369,   369,   203,   829,   204,   737,   295,   205,
     518,   300,   244,   180,   976,   206,   404,  -352,  -362,   444,
     415,   416,  -362,   629,   990,    73,   207,   648,   413,   696,
     296,   244,   970,   777,   630,   208,   301,  -352,   588,   153,
     811,   634,   173,  -448,   209,   210,  -362,   211,  -447,   212,
     696,   213,   366,   631,   413,   649,   669,   697,   214,   398,
     440,   215,   893,   257,   261,   882,   597,   437,   812,   467,
     469,  -448,   367,   369,   414,   147,  -447,   609,   956,   611,
     179,   435,   463,   464,   465,   466,   468,   470,   471,   472,
     473,   474,   477,   478,   197,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   518,   821,   506,   508,   567,   125,   244,   244,   399,
     413,   233,   407,   244,   526,   125,   244,   244,   244,   244,
     507,   509,   517,   407,   407,   700,   125,  -485,   125,  -485,
     430,   527,   635,   541,   306,   530,   545,   531,   232,   407,
     306,   251,   853,   636,   637,   499,   500,   240,  -348,   540,
     542,   501,   544,   546,   502,   503,   252,   552,   552,   638,
     556,  -348,   558,   678,   681,   701,   291,  -317,   407,   125,
     538,   282,  -434,  -348,   652,   590,   702,   369,   352,  -485,
     307,  -485,   594,  -431,   308,   147,   307,  -317,   782,   244,
     308,   909,   899,  -430,   125,   703,  -340,   612,   125,   302,
     552,   552,  -484,   303,  -484,   247,   892,   594,  -435,  -340,
     244,     5,   244,   900,   613,   594,   616,  -436,   618,   620,
    -348,  -340,  -433,   240,  -432,  -348,   313,   355,   722,   315,
     726,   728,   353,   318,   313,   360,   314,   315,   479,   315,
     313,   318,   365,   315,   167,   265,   622,   318,   285,   325,
     285,  -353,   368,   378,   427,   125,   329,   330,   331,   370,
     480,   396,   417,   420,   518,   429,   452,   567,  -340,   453,
     454,   456,   654,  -340,   657,   529,   532,   370,   533,   534,
     547,   780,   535,   537,   853,   557,  -353,   559,   540,   655,
     544,   658,   556,   660,   616,   574,    66,   953,   661,   662,
     575,   244,   481,   244,   588,   592,   668,   599,   670,   306,
     598,  -353,   675,   370,   603,  -342,   517,   617,  -353,   623,
     125,   974,   639,   640,   641,   642,   643,   125,  -342,   644,
     977,   684,   370,   -58,   688,   379,   382,   386,  -353,   665,
    -342,   645,   685,   687,   705,   167,   712,   306,   230,   249,
     250,   254,   265,   287,   717,   307,   723,   244,  -353,   308,
     974,   724,   413,  -353,   731,   989,  -353,   735,   135,   734,
     738,   788,   409,   791,   996,   410,   709,   135,   974,   793,
     797,   818,   125,   822,   824,   834,   827,  -342,   135,   839,
     135,   843,  -342,   307,   419,   711,   858,   308,   848,   -77,
     -95,  -100,   -99,   467,   506,   -96,  -102,   -98,  -101,   313,
     -78,   314,   315,   -97,   433,   862,   318,   517,   884,   887,
     468,   507,   787,   896,   325,   790,   954,   927,   847,   370,
     370,   135,   987,   331,   605,   259,   259,   903,   604,   174,
     801,   425,   803,   310,   833,   806,   312,   313,   809,   314,
     315,   376,   875,   813,   318,   814,   135,   667,   816,   856,
     135,   560,   325,   919,   125,   915,   820,   857,   993,   329,
     330,   331,   695,   969,   983,   194,   591,   666,  -357,   561,
    -359,   181,   562,   240,   125,     0,     0,   125,     0,     0,
       0,     0,     0,   593,   838,   125,   842,     0,   563,   844,
     370,   564,     0,    50,   855,     0,   832,     0,     0,   528,
     920,     0,   565,  -357,     0,  -359,     0,   135,   593,     0,
       0,   282,     0,   282,     0,     0,   593,     0,     0,     0,
       0,   566,     0,   548,     0,     0,     0,     0,  -357,     0,
    -359,     0,     0,     0,   861,  -357,     0,  -359,     0,     0,
       0,   125,     0,     0,     0,     0,     0,   801,   803,     0,
     806,   809,   838,   842,     0,  -357,  -264,  -359,   876,   877,
       0,   878,     0,   879,   880,     0,     0,   881,     0,     0,
     517,     0,   135,   235,   236,  -357,     0,  -359,     0,   135,
    -357,     0,  -359,  -357,  -264,  -359,     0,   898,   616,     0,
       0,   119,     0,   904,     0,   905,     0,     0,     0,   907,
     119,     0,   664,     0,   370,     0,     0,     0,   180,     0,
     650,   119,     0,   119,     0,     0,   437,     0,     0,     0,
       0,     0,   560,     0,     0,   876,   921,   922,   879,   923,
     924,   925,   926,     0,   135,     0,     0,     0,     0,     0,
     561,   129,   933,   562,     0,     0,     0,   287,     0,     0,
     129,   125,   941,     0,   119,   942,     0,     0,     0,   563,
       0,   129,   564,   129,   289,     0,     0,     0,     0,     0,
     938,     0,     0,   565,     0,     0,     0,   672,   674,   119,
       0,   677,   680,   119,     0,     0,     0,     0,   965,   966,
     967,   968,   566,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   842,     0,   978,   979,   287,
       0,   125,     0,     0,     0,     0,   135,     0,   965,   966,
     967,   968,   978,   979,     0,     0,     0,   781,     0,   129,
     192,     0,   982,   129,   984,   616,   135,     0,     0,   135,
     119,    27,   234,     0,     0,   785,   786,   135,     0,   616,
       0,    36,     0,   842,  -208,     0,     0,     0,     0,    16,
       0,   216,     0,    20,     0,   125,     0,   125,     0,    47,
     125,     0,    26,   125,    27,   849,  -208,     0,   560,    32,
       0,     0,   125,     0,    36,   125,     0,  -208,     0,     0,
     129,     0,     0,     0,   263,     0,   561,   795,   796,   562,
       0,     0,    47,   135,   798,   119,    50,   125,   850,  -208,
       0,   851,   119,    55,   807,   563,     0,   810,   564,   125,
      50,   125,     0,     0,     0,   125,     0,     0,     0,   565,
       5,     0,     0,     0,    71,     0,     0,    73,     0,   293,
       0,   294,    14,     0,     0,     0,     0,     0,   566,    19,
       0,     0,     0,     0,     0,   129,   132,     0,     0,   306,
       0,     0,   129,     0,     0,   132,     0,   119,    34,     0,
       0,     0,     0,    37,     0,     0,   132,     0,   132,    42,
       0,     0,     0,     0,     0,     0,     0,     0,   306,    88,
       0,     0,   890,   125,     0,   852,   263,     0,   125,    54,
       0,     0,     0,     0,     0,   307,     0,   263,     0,   308,
     377,    63,   125,   135,     0,    66,     0,   129,     0,   132,
       0,     0,    72,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   307,     0,     0,   125,   308,     0,
       0,   125,   400,     0,   132,     0,     0,     0,   132,   119,
       0,     0,     0,     0,     0,   310,     0,   311,   312,   313,
     412,   314,   315,   939,     0,     0,   318,     0,   902,   119,
       0,     0,   119,   135,   325,     0,     0,     0,   125,     0,
     119,   329,   330,   331,   310,     0,     0,     0,   313,     0,
     314,   315,     0,     0,     0,   318,     0,     0,     0,   129,
       0,     0,     0,   325,     0,   132,     0,   971,     0,     0,
     329,   330,   331,     0,     0,     0,     0,     0,     0,   129,
       0,     0,   129,   125,   125,   125,   125,   135,     0,   135,
     129,     0,   135,     0,     0,   135,   119,     0,     0,     0,
       0,     0,   125,   125,   135,   133,   971,   135,     0,     0,
       0,   192,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,    27,   234,   971,   133,   198,   133,     0,   135,
     132,     0,    36,     0,     0,  -208,     0,   132,   199,   200,
       0,   135,   -44,   135,     0,   201,   129,   135,     0,     0,
      47,     0,     0,   202,     0,     0,     0,  -208,   -44,   536,
       0,     0,     0,     0,   203,     0,   204,     0,   133,   205,
       0,     0,     0,     0,     0,   206,     0,     0,     0,     0,
       0,   137,   400,     0,     0,     0,   207,     0,     0,     0,
     137,     0,   132,   133,     0,   208,     0,   133,   458,     0,
       0,   137,     0,   137,   209,   210,   119,   211,     0,   212,
       0,   213,     0,     0,     0,   135,     0,     0,   214,   732,
     135,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,     0,   621,  -194,     0,   625,
       0,  -194,  -194,     0,   137,     0,   135,     0,     0,     0,
    -194,     0,  -194,  -194,   133,   135,   129,  -194,     0,   135,
       0,     0,  -194,   135,   192,  -194,   119,     0,     0,   137,
       0,     0,     0,   137,   132,    27,   234,     0,     0,   219,
    -194,     0,  -194,     0,  -194,    36,  -194,  -194,  -208,  -194,
       0,  -194,     0,  -194,   132,   -43,     0,   132,     0,     0,
     135,     0,     0,    47,     0,   132,     0,     0,     0,     0,
    -208,   -43,  -194,     0,     0,  -194,   129,     0,  -194,   133,
     119,     0,   119,     0,     0,   119,   133,     0,   119,     0,
     137,     0,     0,     0,     0,     0,     0,   119,     0,     0,
     119,     0,     0,     0,     0,   135,   135,   135,   135,     0,
       0,     0,     0,   699,     0,     0,     0,   400,     0,     0,
       0,   132,   119,     0,   135,   135,     0,  -194,     0,     0,
     129,     0,   129,  -194,   119,   129,   119,     0,   129,     0,
     119,   133,   720,     0,     0,     0,   263,   129,     0,     0,
     129,     0,     0,     0,     0,   137,     0,     0,     0,     0,
       0,     0,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   129,   224,     0,     0,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   224,     0,     0,   119,     0,
       0,     0,     0,   119,     0,   256,   260,   137,     0,     0,
       0,     0,     0,   133,     0,     0,     0,   119,     0,     0,
       0,   132,     0,     0,     0,     0,     0,     0,   819,   119,
       0,   400,     0,   133,     0,     0,   133,     0,   119,     0,
       0,     0,   119,     0,   133,     0,   119,     0,   129,     0,
       0,   720,     0,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,     0,   625,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   132,     0,   119,     0,     0,     0,   860,   129,   137,
       0,     0,   129,     0,     0,   138,   129,     0,     0,     0,
     133,     0,     0,     0,   138,     0,     0,   361,     0,   137,
       0,     0,   137,     0,     0,   138,     0,   138,     0,     0,
     137,     0,     0,     0,     0,   224,   224,   224,   119,   119,
     119,   119,   392,   129,     0,   132,     0,   132,     0,     0,
     132,     0,     0,   132,     0,     0,     0,   119,   119,     0,
       0,     0,   132,     0,     0,   132,     0,     0,   138,     0,
       0,     0,   224,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   132,   129,   129,
     129,   129,     0,   138,   224,     0,     0,   138,     0,   132,
       0,   132,     0,    95,     0,   132,     0,   129,   129,   874,
       0,     0,   148,     0,   224,     0,     0,     0,     0,     0,
     133,     0,     0,   175,     0,   178,     0,  -194,     0,     0,
       0,  -194,  -194,     0,     0,     0,     0,     0,     0,     0,
    -194,     0,  -194,  -194,     0,     0,     0,  -194,     0,     0,
       0,     0,  -194,     0,   138,  -194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   253,     0,     0,     0,
    -194,     0,  -194,   132,  -194,     0,  -194,  -194,   132,  -194,
     133,  -194,     0,  -194,     0,     0,     0,     0,     0,     0,
       0,    95,   132,     0,     0,   290,   137,     0,     0,     0,
       0,     0,  -194,     0,   132,  -194,     0,     0,  -194,   224,
       0,     0,     0,   132,     0,     0,     0,   132,     0,   138,
       0,   132,     0,     0,     0,     0,   138,     0,     0,     0,
       0,     0,     0,   224,   133,     0,   133,     0,     0,   133,
       0,     0,   133,     0,     0,     0,     0,     0,     0,     0,
       0,   133,   354,     0,   133,     0,   137,  -194,   132,   198,
       0,     0,     0,  -194,     0,     0,     0,     0,     0,     0,
       0,   199,   200,     0,     0,     0,   133,     0,   201,     0,
       0,   138,     0,     0,     0,     0,   202,     0,   133,     0,
     133,     0,     0,     0,   133,     0,     0,   203,     0,   204,
       0,     0,   205,   132,   132,   132,   132,     0,   206,     0,
     137,     0,   137,     0,     0,   137,     0,   395,   137,   207,
       0,     0,   132,   132,   408,     0,     0,   137,   208,     0,
     137,     0,     0,     0,     0,     0,     0,   209,   210,     0,
     211,     0,   212,     0,   213,     0,     0,     0,     0,     0,
       0,   214,   137,     0,   215,     0,     0,     0,     0,     0,
       0,     0,   133,   138,   137,     0,   137,   133,     0,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,   133,     0,   138,     0,     0,   138,   224,   224,     0,
       0,   224,   224,   133,   138,     0,     0,     0,     0,     0,
       0,     0,   133,     0,   692,     0,   133,     0,     0,     0,
     133,     0,   219,     0,     0,     0,     0,     0,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,     0,     0,     0,     0,     0,   137,     0,
       0,     0,     0,   137,     0,   719,     0,   133,  -455,     0,
     138,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     198,    95,   347,     0,     0,  -484,     0,  -484,     0,   137,
       0,     0,   199,   200,     0,     0,     0,     0,   137,   201,
       0,   408,   137,     0,   408,     0,   137,   202,     0,     0,
       0,     0,   133,   133,   133,   133,     0,     0,   203,     0,
     204,     0,     0,   205,     0,     0,     0,   224,   224,   206,
       0,   133,   133,   198,   224,     0,   392,     0,     0,     0,
     207,   392,     0,   137,   224,   199,   200,   224,     0,   208,
       0,     0,   201,     0,     0,     0,     0,     0,   209,   210,
     202,   211,     0,   212,     0,   213,     0,     0,   615,     0,
       0,   203,   214,   204,     0,   215,   205,     0,     0,     0,
     138,     0,   206,     0,     0,     0,     0,   835,   137,   137,
     137,   137,     0,   207,     0,     0,     0,     0,     0,     0,
       0,     0,   208,     0,     0,   306,     0,   137,   137,     0,
       0,   209,   210,     0,   211,     0,   212,     0,   213,     0,
       0,     0,    16,     0,     0,   214,    20,     0,   215,     0,
       0,   360,     0,   718,     0,    26,     0,    27,   849,     0,
     138,     0,    32,     0,     0,     0,     0,    36,     0,     0,
    -208,   307,     0,     0,     0,   308,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,    50,
       0,   850,  -208,     0,   851,     0,    55,     0,   690,     0,
       0,     0,     0,     0,     0,     0,   698,     0,     0,     0,
       0,     0,     0,     0,   138,     0,   138,    71,   224,   138,
      73,   310,   138,   311,   312,   313,     0,   314,   315,   316,
       0,   138,   318,     0,   138,     0,     0,     0,     0,   324,
     325,     0,     0,     0,   328,     0,     0,   329,   330,   331,
       0,     0,     0,     0,     0,     0,   138,     0,   729,     0,
       0,     0,     0,   392,   392,     0,   392,   392,   138,     0,
     138,     0,    88,     0,   138,     0,     0,   304,   928,     0,
       0,    16,     0,   943,   305,    20,     0,     0,     0,   947,
       0,   392,     0,   392,    26,   306,    27,   849,     0,     0,
       0,    32,     0,     0,     0,     0,    36,     0,     0,  -208,
       0,     0,   408,     0,   408,     0,     0,   408,     0,     0,
     408,     0,     0,     0,    47,     0,     0,     0,   289,   815,
     850,  -208,   817,   851,   306,    55,     0,     0,     0,     0,
       0,   307,   138,     0,     0,   308,     0,   138,     0,     0,
       0,     0,     0,     0,   831,     0,    71,     0,     0,    73,
       0,   138,     0,     0,     0,     0,   837,     0,   841,   943,
       0,   385,    95,   138,     0,   309,     0,     0,     0,     0,
     307,     0,   138,     0,   308,     0,   138,     0,     0,     0,
     138,   310,     0,   311,   312,   313,     0,   314,   315,   316,
       0,   317,   318,   319,   320,   321,     0,   322,   323,   324,
     325,    88,   326,   327,   328,     0,     0,   329,   330,   331,
       0,     0,     0,     0,     0,     0,   727,   138,     0,     0,
     310,     0,   311,   312,   313,     0,   314,   315,   316,     0,
     317,   318,   319,   320,     0,     0,   322,   323,   324,   325,
       0,   326,     0,   328,     0,     0,   329,   330,   331,   885,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   901,   138,   138,   138,   138,     0,     0,     0,     0,
     906,     0,     0,     0,   908,     0,     0,     0,    95,     0,
       0,   138,   138,     0,    -2,     4,     0,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,    18,    19,    20,  -324,    21,
      22,    23,     0,    24,    25,   934,    26,     0,    27,    28,
      29,    30,    31,    32,    33,    34,     0,    35,    36,     0,
      37,  -208,    38,    39,    40,    41,    42,    43,   -42,    44,
      45,     0,    46,     0,     0,     0,    47,    48,  -324,    49,
      50,    51,    52,  -208,   -42,    53,    54,    55,     0,  -324,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,     0,    68,    69,    70,    71,    72,
       0,    73,    74,    75,  -324,     0,     0,    76,     0,    77,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,    85,     0,
      86,    87,     0,    88,     0,     0,    89,     0,    90,     0,
      91,   980,    92,     5,     6,     7,     8,     9,    10,     0,
       0,     0,   155,     0,   306,    14,    15,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,    29,   156,   157,     0,
     158,    34,     0,    35,     0,     0,    37,     0,     0,    39,
      40,     0,    42,    43,     0,    44,    45,     0,     0,     0,
     307,     0,     0,    48,   308,    49,     0,    51,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,   159,     0,    66,     0,
       0,    68,     0,     0,     0,    72,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
     310,     0,   311,   312,   313,     0,   314,   315,     0,     0,
       0,   318,     0,     0,    79,    80,    81,    82,   324,   325,
       0,     0,    83,   328,     0,     0,   329,   330,   331,     0,
       0,     0,    84,     0,    85,     0,    86,    87,   237,     0,
       0,     0,    89,     0,   160,     0,    91,     0,   161,   981,
       4,     0,     5,     6,     7,     8,     9,    10,     0,  -507,
       0,    11,    12,    13,    14,    15,  -507,     0,    16,    17,
      18,    19,    20,  -324,    21,    22,    23,  -507,    24,    25,
    -507,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,     0,    35,    36,     0,    37,  -208,    38,    39,    40,
      41,    42,    43,   -42,    44,    45,     0,    46,     0,     0,
       0,    47,    48,  -324,    49,     0,    51,    52,  -208,   -42,
      53,    54,    55,  -507,  -324,    56,    57,  -507,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,     0,
      68,    69,    70,    71,    72,     0,    73,    74,    75,  -324,
       0,     0,    76,     0,    77,     0,     0,  -507,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -507,    80,  -507,  -507,  -507,  -507,  -507,
    -507,  -507,     0,  -507,  -507,  -507,  -507,  -507,     0,  -507,
    -507,  -507,  -507,    85,  -507,  -507,  -507,     0,    88,  -507,
    -507,  -507,     0,    90,  -507,    91,   275,    92,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,  -324,
      21,    22,    23,     0,    24,    25,     0,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,     0,    35,    36,
       0,    37,  -208,    38,    39,    40,    41,    42,    43,   -42,
      44,    45,     0,    46,     0,     0,     0,    47,    48,  -324,
      49,    50,    51,    52,  -208,   -42,    53,    54,    55,     0,
    -324,    56,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    67,     0,    68,    69,    70,    71,
      72,     0,    73,    74,    75,  -324,     0,     0,    76,     0,
      77,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    85,
       0,    86,    87,   237,    88,     0,     0,    89,     0,    90,
     276,    91,     4,    92,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,    18,    19,    20,  -324,    21,    22,    23,     0,
      24,    25,     0,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,     0,    35,    36,     0,    37,  -208,    38,
      39,    40,    41,    42,    43,   -42,    44,    45,     0,    46,
       0,     0,     0,    47,    48,  -324,    49,    50,    51,    52,
    -208,   -42,    53,    54,    55,     0,  -324,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,     0,    68,    69,    70,    71,    72,     0,    73,    74,
      75,  -324,     0,     0,    76,     0,    77,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,    85,     0,    86,    87,     0,
      88,     0,     0,    89,     0,    90,   436,    91,   275,    92,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,  -324,    21,    22,    23,     0,    24,    25,     0,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,     0,
      35,    36,     0,    37,  -208,    38,    39,    40,    41,    42,
      43,   -42,    44,    45,     0,    46,     0,     0,     0,    47,
      48,  -324,    49,    50,    51,    52,  -208,   -42,    53,    54,
      55,     0,  -324,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,     0,    68,    69,
      70,    71,    72,     0,    73,    74,    75,  -324,     0,     0,
      76,     0,    77,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,    85,     0,    86,    87,     0,    88,     0,     0,    89,
       0,    90,   276,    91,   845,    92,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,  -324,    21,    22,
      23,     0,    24,    25,     0,    26,     0,    27,    28,    29,
      30,    31,    32,    33,    34,     0,    35,    36,     0,    37,
    -208,    38,    39,    40,    41,    42,    43,   -42,    44,    45,
       0,    46,     0,     0,     0,    47,    48,  -324,    49,    50,
      51,    52,  -208,   -42,    53,    54,    55,     0,  -324,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
       0,    66,    67,     0,    68,    69,    70,    71,    72,     0,
      73,    74,    75,  -324,     0,     0,    76,     0,    77,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,    85,     0,    86,
      87,     0,    88,     0,     0,    89,     0,    90,   846,    91,
       4,    92,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
      18,    19,    20,  -324,    21,    22,    23,     0,    24,    25,
       0,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,     0,    35,    36,     0,    37,  -208,    38,    39,    40,
      41,    42,    43,   -42,    44,    45,     0,    46,     0,     0,
       0,    47,    48,  -324,    49,    50,    51,    52,  -208,   -42,
      53,    54,    55,     0,  -324,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,     0,
      68,    69,    70,    71,    72,     0,    73,    74,    75,  -324,
       0,     0,    76,     0,    77,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,    85,     0,    86,    87,     0,    88,     0,
       0,    89,     0,    90,   910,    91,     4,    92,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,  -324,
      21,    22,    23,     0,    24,    25,     0,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,     0,    35,    36,
       0,    37,  -208,    38,    39,    40,    41,    42,    43,   -42,
      44,    45,     0,    46,     0,     0,     0,    47,    48,  -324,
      49,   289,    51,    52,  -208,   -42,    53,    54,    55,     0,
    -324,    56,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    67,     0,    68,    69,    70,    71,
      72,     0,    73,    74,    75,  -324,     0,     0,    76,     0,
      77,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    85,
       0,    86,    87,     0,    88,     0,     0,    89,     0,    90,
       0,    91,     4,    92,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,    18,    19,    20,  -324,    21,    22,    23,     0,
      24,    25,     0,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,     0,    35,    36,     0,    37,  -208,    38,
      39,    40,    41,    42,    43,   -42,    44,    45,     0,    46,
       0,     0,     0,    47,    48,  -324,    49,     0,    51,    52,
    -208,   -42,    53,    54,    55,     0,  -324,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,     0,    68,    69,    70,    71,    72,     0,    73,    74,
      75,  -324,     0,     0,    76,     0,    77,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,    85,     0,    86,    87,     0,
      88,     0,     0,    89,     0,    90,     0,    91,     4,    92,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,  -324,    21,    22,    23,     0,    24,    25,     0,    26,
       0,    27,    28,    29,    30,    31,    32,   539,    34,     0,
      35,    36,     0,    37,  -208,    38,    39,    40,    41,    42,
      43,   -42,    44,    45,     0,    46,     0,     0,     0,    47,
      48,  -324,    49,     0,    51,    52,  -208,   -42,    53,    54,
      55,     0,  -324,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,     0,    68,    69,
      70,    71,    72,     0,    73,    74,    75,  -324,     0,     0,
      76,     0,    77,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,    85,     0,    86,    87,     0,    88,     0,     0,    89,
       0,    90,     0,    91,     4,    92,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,  -324,    21,    22,
      23,     0,    24,    25,     0,    26,     0,    27,    28,    29,
      30,    31,    32,   543,    34,     0,    35,    36,     0,    37,
    -208,    38,    39,    40,    41,    42,    43,   -42,    44,    45,
       0,    46,     0,     0,     0,    47,    48,  -324,    49,     0,
      51,    52,  -208,   -42,    53,    54,    55,     0,  -324,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
       0,    66,    67,     0,    68,    69,    70,    71,    72,     0,
      73,    74,    75,  -324,     0,     0,    76,     0,    77,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,    85,     0,    86,
      87,     0,    88,     0,     0,    89,     0,    90,     0,    91,
       4,    92,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
      18,    19,    20,  -324,    21,    22,    23,     0,    24,    25,
       0,    26,     0,    27,    28,    29,    30,    31,    32,   800,
      34,     0,    35,    36,     0,    37,  -208,    38,    39,    40,
      41,    42,    43,   -42,    44,    45,     0,    46,     0,     0,
       0,    47,    48,  -324,    49,     0,    51,    52,  -208,   -42,
      53,    54,    55,     0,  -324,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,     0,
      68,    69,    70,    71,    72,     0,    73,    74,    75,  -324,
       0,     0,    76,     0,    77,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,    85,     0,    86,    87,     0,    88,     0,
       0,    89,     0,    90,     0,    91,     4,    92,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,  -324,
      21,    22,    23,     0,    24,    25,     0,    26,     0,    27,
      28,    29,    30,    31,    32,   802,    34,     0,    35,    36,
       0,    37,  -208,    38,    39,    40,    41,    42,    43,   -42,
      44,    45,     0,    46,     0,     0,     0,    47,    48,  -324,
      49,     0,    51,    52,  -208,   -42,    53,    54,    55,     0,
    -324,    56,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    67,     0,    68,    69,    70,    71,
      72,     0,    73,    74,    75,  -324,     0,     0,    76,     0,
      77,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    85,
       0,    86,    87,     0,    88,     0,     0,    89,     0,    90,
       0,    91,     4,    92,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,    18,    19,    20,  -324,    21,    22,    23,     0,
      24,    25,     0,    26,     0,    27,    28,    29,    30,    31,
      32,   805,    34,     0,    35,    36,     0,    37,  -208,    38,
      39,    40,    41,    42,    43,   -42,    44,    45,     0,    46,
       0,     0,     0,    47,    48,  -324,    49,     0,    51,    52,
    -208,   -42,    53,    54,    55,     0,  -324,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,     0,    68,    69,    70,    71,    72,     0,    73,    74,
      75,  -324,     0,     0,    76,     0,    77,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,    85,     0,    86,    87,     0,
      88,     0,     0,    89,     0,    90,     0,    91,     4,    92,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,  -324,    21,    22,    23,     0,    24,    25,     0,    26,
       0,    27,    28,    29,    30,    31,    32,   808,    34,     0,
      35,    36,     0,    37,  -208,    38,    39,    40,    41,    42,
      43,   -42,    44,    45,     0,    46,     0,     0,     0,    47,
      48,  -324,    49,     0,    51,    52,  -208,   -42,    53,    54,
      55,     0,  -324,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,     0,    68,    69,
      70,    71,    72,     0,    73,    74,    75,  -324,     0,     0,
      76,     0,    77,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,    85,     0,    86,    87,     0,    88,     0,     0,    89,
       0,    90,     0,    91,     4,    92,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,  -324,    21,    22,
      23,     0,   830,    25,     0,    26,     0,    27,    28,    29,
      30,    31,    32,    33,    34,     0,    35,    36,     0,    37,
    -208,    38,    39,    40,    41,    42,    43,   -42,    44,    45,
       0,    46,     0,     0,     0,    47,    48,  -324,    49,     0,
      51,    52,  -208,   -42,    53,    54,    55,     0,  -324,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
       0,    66,    67,     0,    68,    69,    70,    71,    72,     0,
      73,    74,    75,  -324,     0,     0,    76,     0,    77,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,    85,     0,    86,
      87,     0,    88,     0,     0,    89,     0,    90,     0,    91,
       4,    92,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
      18,    19,    20,  -324,    21,    22,    23,     0,    24,    25,
       0,    26,     0,    27,    28,    29,    30,    31,    32,   836,
      34,     0,    35,    36,     0,    37,  -208,    38,    39,    40,
      41,    42,    43,   -42,    44,    45,     0,    46,     0,     0,
       0,    47,    48,  -324,    49,     0,    51,    52,  -208,   -42,
      53,    54,    55,     0,  -324,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,     0,
      68,    69,    70,    71,    72,     0,    73,    74,    75,  -324,
       0,     0,    76,     0,    77,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,    85,     0,    86,    87,     0,    88,     0,
       0,    89,     0,    90,     0,    91,     4,    92,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,  -324,
      21,    22,    23,     0,    24,    25,     0,    26,     0,    27,
      28,    29,    30,    31,    32,   840,    34,     0,    35,    36,
       0,    37,  -208,    38,    39,    40,    41,    42,    43,   -42,
      44,    45,     0,    46,     0,     0,     0,    47,    48,  -324,
      49,     0,    51,    52,  -208,   -42,    53,    54,    55,     0,
    -324,    56,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    67,     0,    68,    69,    70,    71,
      72,     0,    73,    74,    75,  -324,     0,     0,    76,     0,
      77,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    85,
       0,    86,    87,     0,    88,     0,     0,    89,     0,    90,
       0,    91,   708,    92,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   155,     0,     0,    14,    15,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,    29,   156,   157,
       0,   158,    34,     0,    35,     0,     0,    37,     0,     0,
      39,    40,     0,    42,    43,     0,    44,    45,     0,     0,
       0,     0,     0,     0,    48,     0,    49,     0,    51,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,   159,     0,    66,
       0,     0,    68,     0,     0,     0,    72,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,    85,     0,    86,    87,   237,
       0,     0,     0,    89,     0,   160,     0,    91,     0,   161,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   155,
       0,     0,    14,    15,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,    29,   156,   157,     0,   158,    34,     0,
      35,     0,     0,    37,     0,     0,    39,    40,     0,    42,
      43,     0,    44,    45,     0,     0,     0,     0,     0,     0,
      48,     0,    49,     0,    51,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,   159,     0,    66,     0,     0,    68,     0,
       0,     0,    72,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,    85,     0,    86,    87,   237,     0,     0,     0,    89,
       0,   160,     0,    91,     0,   161,   614,     5,     6,     7,
       8,     9,    10,     0,     0,     0,   155,     0,     0,    14,
      15,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
      29,   156,   157,     0,   158,    34,     0,    35,     0,     0,
      37,     0,     0,    39,    40,     0,    42,    43,     0,    44,
      45,     0,     0,     0,     0,     0,     0,    48,     0,    49,
       0,    51,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
     159,     0,    66,     0,     0,    68,     0,     0,     0,    72,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,    85,     0,
      86,    87,   237,     0,     0,     0,    89,     0,   160,     0,
      91,     0,   161,   937,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   155,     0,     0,    14,    15,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,    29,   156,   157,
       0,   158,    34,     0,    35,     0,     0,    37,     0,     0,
      39,    40,     0,    42,    43,     0,    44,    45,     0,     0,
       0,     0,     0,     0,    48,     0,    49,     0,    51,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,   159,     0,    66,
       0,     0,    68,     0,     0,     0,    72,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,    85,     0,    86,    87,     0,
       0,     0,     0,    89,     0,   160,     0,    91,     0,   161,
     619,     5,     6,     7,     8,   182,    10,   183,     0,     0,
     155,     0,     0,    14,    15,     0,     0,  -111,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,     0,    29,   156,   157,     0,   158,    34,
       0,    35,     0,     0,    37,  -475,     0,    39,    40,     0,
      42,    43,     0,    44,    45,     0,     0,     0,     0,     0,
       0,    48,     0,    49,     0,    51,     0,  -475,     0,     0,
      54,  -111,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,   159,     0,    66,     0,     0,    68,
       0,     0,   184,    72,     0,  -111,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,    85,     0,    86,    87,     0,     0,     0,     0,
      89,     0,   160,     0,    91,     0,   161,     5,     6,     7,
       8,   182,    10,     0,     0,     0,   155,     0,     0,    14,
      15,     0,     0,  -111,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
      29,   156,   157,     0,   158,    34,     0,    35,     0,     0,
      37,  -475,     0,    39,    40,     0,    42,    43,     0,    44,
      45,     0,     0,     0,     0,     0,     0,    48,     0,    49,
       0,    51,     0,  -475,     0,     0,    54,  -111,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
     159,     0,    66,     0,     0,    68,     0,     0,   184,    72,
       0,  -111,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,     0,     0,     0,     0,    83,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    84,     0,    85,   155,
      86,    87,    14,    15,     0,     0,    89,     0,   160,    19,
      91,     0,   161,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,    29,   156,   157,     0,   158,    34,     0,
      35,     0,     0,    37,     0,     0,    39,    40,     0,    42,
      43,     0,    44,    45,     0,     0,     0,     0,     0,     0,
      48,     0,    49,     0,    51,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,   159,     0,    66,     0,     0,    68,   241,
     242,     0,    72,   280,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,     0,     0,     0,     0,    83,
     281,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,    85,     0,    86,    87,   237,     0,     0,     0,    89,
       0,   160,     0,    91,     0,   161,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   155,     0,     0,    14,    15,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,    29,
     156,   157,     0,   158,    34,     0,    35,     0,     0,    37,
       0,     0,    39,    40,     0,    42,    43,     0,    44,    45,
       0,     0,     0,     0,     0,     0,    48,     0,    49,     0,
      51,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,   159,
       0,    66,     0,     0,    68,   241,   242,     0,    72,   280,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,    85,     0,    86,
      87,   237,     0,     0,     0,    89,     0,   160,     0,    91,
     608,   161,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   155,     0,     0,    14,    15,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,    29,   156,   157,     0,   158,
      34,     0,    35,     0,     0,    37,     0,     0,    39,    40,
       0,    42,    43,     0,    44,    45,     0,     0,     0,     0,
       0,     0,    48,     0,    49,     0,    51,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,   159,     0,    66,     0,     0,
      68,   241,   242,     0,    72,   280,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,    85,     0,    86,    87,   237,     0,     0,
       0,    89,     0,   160,     0,    91,   610,   161,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   155,     0,     0,
      14,    15,     0,     0,     0,     0,     0,    19,     0,   510,
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
       0,    29,   156,   157,     0,   158,    34,   511,    35,     0,
       0,    37,     0,     0,    39,    40,     0,    42,    43,     0,
      44,    45,     0,     0,     0,     0,     0,     0,    48,     0,
      49,     0,    51,     0,     0,     0,     0,    54,     0,     0,
     512,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,   159,     0,    66,     0,     0,    68,     0,     0,     0,
      72,     0,     0,    74,     0,   513,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   740,     0,   741,     0,     0,    79,
      80,    81,    82,   742,     0,     0,     0,    83,   743,   200,
     744,     0,     0,     0,     0,   745,     0,    84,     0,    85,
       0,    86,    87,   202,     0,     0,     0,    89,     0,   160,
       0,    91,     0,   161,   746,     0,   204,     0,     0,   747,
       0,     0,     0,     0,     0,   748,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,     0,     0,
       0,     0,     0,     0,     0,   749,     0,     0,     0,     0,
       0,     0,     0,     0,   209,   210,     0,   750,     0,   212,
       0,   751,     0,     0,     0,     0,     0,     0,   752,     0,
       0,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   332,   333,   334,   335,   336,   337,     0,     0,
     340,   341,   342,   343,     0,   345,   346,   753,   754,   755,
     756,     0,     0,   757,     0,     0,     0,   758,   759,   760,
     761,   762,   763,   764,   765,   766,   767,   768,   769,     0,
     770,     0,     0,   771,   772,   773,   774,     0,     0,   775,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   155,
       0,     0,    14,    15,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,    29,   156,   157,     0,   158,    34,     0,
      35,     0,     0,    37,     0,     0,    39,    40,     0,    42,
      43,     0,    44,    45,     0,     0,     0,     0,     0,     0,
      48,     0,    49,     0,    51,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,   159,     0,    66,     0,     0,    68,   241,
     242,     0,    72,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,    85,     0,    86,    87,     0,   243,     0,     0,    89,
       0,   160,     0,    91,     0,   161,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   155,     0,     0,    14,    15,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,    29,
     156,   157,     0,   158,    34,     0,    35,     0,     0,    37,
       0,     0,    39,    40,     0,    42,    43,     0,    44,    45,
       0,     0,     0,     0,     0,     0,    48,     0,    49,     0,
      51,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,   159,
       0,    66,     0,     0,    68,   241,   242,     0,    72,     0,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,    85,     0,    86,
      87,   237,     0,     0,     0,    89,     0,   160,     0,    91,
       0,   161,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   155,     0,     0,    14,    15,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,    29,   156,   157,     0,   158,
      34,     0,    35,     0,     0,    37,     0,     0,    39,    40,
       0,    42,    43,     0,    44,    45,   710,     0,     0,     0,
       0,     0,    48,     0,    49,     0,    51,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,   159,     0,    66,     0,     0,
      68,   241,   242,     0,    72,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,    83,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    84,     0,    85,   155,    86,    87,    14,    15,     0,
       0,    89,     0,   160,    19,    91,     0,   161,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,    29,   156,
     157,     0,   158,    34,     0,    35,     0,     0,    37,     0,
       0,    39,    40,     0,    42,    43,     0,    44,    45,     0,
       0,     0,     0,     0,     0,    48,   187,    49,     0,    51,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,   159,     0,
      66,     0,     0,    68,     0,     0,     0,    72,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,   188,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80,    81,    82,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,    85,     0,    86,    87,
       0,     0,     0,     0,    89,     0,   160,     0,    91,     0,
     161,     5,     6,     7,     8,     9,    10,     0,     0,     0,
     155,     0,     0,    14,    15,     0,     0,     0,     0,     0,
      19,   192,     0,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,   193,    29,   156,   157,     0,   158,    34,
       0,    35,     0,     0,    37,     0,     0,    39,    40,     0,
      42,    43,     0,    44,    45,     0,     0,     0,     0,     0,
       0,    48,     0,    49,     0,    51,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,   159,     0,    66,     0,     0,    68,
       0,     0,     0,    72,     0,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,     0,     0,     0,     0,
      83,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      84,     0,    85,   155,    86,    87,    14,    15,     0,     0,
      89,     0,   160,    19,    91,     0,   161,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,    29,   156,   157,
       0,   158,    34,     0,    35,     0,     0,    37,  -475,     0,
      39,    40,     0,    42,    43,     0,    44,    45,     0,     0,
       0,     0,     0,     0,    48,     0,    49,     0,    51,     0,
    -475,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,   159,     0,    66,
       0,     0,    68,     0,     0,     0,    72,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,    83,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    84,     0,    85,   155,    86,    87,    14,
      15,     0,     0,    89,     0,   160,    19,    91,     0,   161,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
      29,   156,   157,     0,   158,    34,     0,    35,     0,     0,
      37,     0,     0,    39,    40,     0,    42,    43,     0,    44,
      45,     0,     0,     0,     0,     0,     0,    48,     0,    49,
       0,    51,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
     159,     0,    66,     0,     0,    68,   241,   242,     0,    72,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,     0,     0,     0,     0,    83,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    84,     0,    85,   155,
      86,    87,    14,    15,     0,     0,    89,     0,   160,    19,
      91,     0,   161,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,    29,   156,   157,     0,   158,    34,     0,
      35,     0,     0,    37,     0,     0,    39,    40,     0,    42,
      43,     0,    44,    45,     0,     0,     0,     0,     0,     0,
      48,     0,    49,     0,    51,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,   159,     0,    66,     0,     0,    68,     0,
       0,     0,    72,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,    85,     0,    86,    87,   237,     0,     0,     0,    89,
       0,   160,   606,    91,     0,   161,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   155,     0,     0,    14,    15,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,   223,    25,     0,     0,     0,     0,     0,    29,
     156,   157,     0,   158,    34,     0,    35,     0,     0,    37,
       0,     0,    39,    40,     0,    42,    43,     0,    44,    45,
       0,     0,     0,     0,     0,     0,    48,     0,    49,     0,
      51,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,   159,
       0,    66,     0,     0,    68,     0,     0,     0,    72,     0,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,     0,     0,     0,     0,    83,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    84,     0,    85,   155,    86,
      87,    14,    15,     0,     0,    89,     0,    90,    19,    91,
       0,   161,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    29,   156,   157,     0,   158,    34,     0,    35,
       0,     0,    37,     0,     0,    39,    40,     0,    42,    43,
       0,    44,    45,     0,     0,     0,     0,     0,     0,    48,
       0,    49,     0,    51,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,   159,     0,    66,     0,     0,    68,     0,     0,
       0,    72,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,    80,    81,    82,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,     0,
      85,     0,    86,    87,   237,     0,     0,     0,    89,     0,
     160,     0,    91,     0,   161,     5,     6,     7,     8,     9,
      10,     0,     0,     0,   155,     0,     0,    14,    15,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,    29,   156,
     157,     0,   158,    34,     0,    35,     0,     0,    37,     0,
       0,    39,    40,     0,    42,    43,     0,    44,    45,     0,
       0,     0,     0,     0,     0,    48,     0,    49,     0,    51,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,   159,     0,
      66,     0,     0,    68,     0,     0,     0,    72,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,   188,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80,    81,    82,
       0,     0,     0,     0,    83,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    84,     0,    85,   155,    86,    87,
      14,   576,     0,     0,    89,     0,   160,    19,    91,     0,
     161,     0,     0,     0,     0,   577,     0,     0,     0,     0,
       0,    29,   156,   157,     0,   158,    34,     0,   578,     0,
       0,    37,     0,     0,    39,    40,     0,    42,    43,     0,
      44,    45,     0,     0,     0,     0,     0,     0,   579,     0,
      49,     0,    51,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,   580,   581,    62,    63,
      64,   582,     0,    66,     0,     0,    68,     0,     0,     0,
      72,     0,     0,   583,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    85,
       0,    86,    87,   237,     0,     0,     0,    89,     0,   160,
       0,    91,     0,   888,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   155,     0,     0,    14,    15,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,    29,   156,   157,
       0,   158,    34,     0,    35,     0,     0,    37,     0,     0,
      39,    40,     0,    42,    43,     0,    44,    45,     0,     0,
       0,     0,     0,     0,    48,     0,    49,     0,    51,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,   159,     0,    66,
       0,     0,    68,     0,     0,     0,    72,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,    85,     0,    86,    87,   237,
       0,     0,     0,    89,     0,   160,     0,    91,     0,   888,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   155,
       0,     0,    14,    15,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,    29,   156,   157,     0,   873,    34,     0,
      35,     0,     0,    37,     0,     0,    39,    40,     0,    42,
      43,     0,    44,    45,     0,     0,     0,     0,     0,     0,
      48,     0,    49,     0,    51,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,   159,     0,    66,     0,     0,    68,     0,
       0,     0,    72,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,    85,     0,    86,    87,   237,     0,     0,     0,    89,
       0,   160,     0,    91,     0,   161,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   155,     0,     0,    14,    15,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,    29,
     156,   157,     0,   158,    34,     0,    35,     0,     0,    37,
       0,     0,    39,    40,     0,    42,    43,     0,    44,    45,
       0,     0,     0,     0,     0,     0,    48,     0,    49,     0,
      51,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,   159,
       0,    66,     0,     0,    68,     0,     0,     0,    72,     0,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,     0,     0,     0,     0,    83,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    84,     0,    85,   155,    86,
      87,    14,    15,     0,     0,    89,     0,   160,    19,    91,
       0,   161,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    29,   156,   157,     0,   158,    34,     0,    35,
       0,     0,    37,     0,     0,    39,    40,     0,    42,    43,
       0,    44,    45,     0,     0,     0,     0,     0,     0,    48,
       0,    49,     0,    51,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,   159,     0,    66,     0,     0,    68,     0,     0,
       0,    72,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,    80,    81,    82,     0,     0,     0,     0,    83,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    84,     0,
      85,   155,    86,    87,    14,   475,     0,     0,    89,     0,
      90,    19,    91,     0,   161,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,    29,   156,   157,     0,   158,
      34,     0,    35,     0,     0,    37,     0,     0,    39,    40,
       0,    42,    43,     0,    44,    45,     0,     0,     0,     0,
       0,     0,    48,     0,    49,     0,    51,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,   159,     0,    66,     0,     0,
      68,     0,     0,     0,    72,     0,     0,   476,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,    83,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    84,     0,    85,   155,    86,    87,    14,    15,     0,
       0,    89,     0,   160,    19,    91,     0,   161,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,    29,   156,
     157,     0,   158,    34,     0,    35,     0,     0,    37,     0,
       0,    39,    40,     0,    42,    43,     0,    44,    45,     0,
       0,     0,     0,     0,     0,    48,     0,    49,     0,    51,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,   159,     0,
      66,     0,     0,    68,     0,     0,     0,    72,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80,    81,    82,
       0,     0,     0,     0,    83,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    84,     0,    85,   155,    86,    87,
      14,   576,     0,     0,   549,     0,   160,    19,    91,     0,
     161,     0,     0,     0,     0,   577,     0,     0,     0,     0,
       0,    29,   156,   157,     0,   158,    34,     0,   578,     0,
       0,    37,     0,     0,    39,    40,     0,    42,    43,     0,
      44,    45,     0,     0,     0,     0,     0,     0,   579,     0,
      49,     0,    51,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,   580,   581,    62,    63,
      64,   582,     0,    66,     0,     0,    68,     0,     0,     0,
      72,     0,     0,   583,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,     0,     0,     0,     0,    83,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    84,     0,    85,
     155,    86,    87,    14,    15,     0,     0,    89,     0,   160,
      19,    91,     0,   584,     0,     0,     0,     0,    25,     0,
       0,     0,     0,     0,    29,   156,   157,     0,   158,    34,
       0,    35,     0,     0,    37,     0,     0,    39,    40,     0,
      42,    43,     0,    44,    45,     0,     0,     0,     0,     0,
       0,    48,     0,    49,     0,    51,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,   159,     0,    66,     0,     0,    68,
       0,     0,     0,    72,     0,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,     0,     0,     0,     0,
      83,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      84,     0,    85,   155,    86,    87,    14,    15,     0,     0,
      89,     0,   160,    19,    91,     0,   584,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,    29,   156,   157,
       0,   653,    34,     0,    35,     0,     0,    37,     0,     0,
      39,    40,     0,    42,    43,     0,    44,    45,     0,     0,
       0,     0,     0,     0,    48,     0,    49,     0,    51,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,   159,     0,    66,
       0,     0,    68,     0,     0,     0,    72,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,    83,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    84,     0,    85,   155,    86,    87,    14,
      15,     0,     0,    89,     0,   160,    19,    91,     0,   161,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
      29,   156,   157,     0,   656,    34,     0,    35,     0,     0,
      37,     0,     0,    39,    40,     0,    42,    43,     0,    44,
      45,     0,     0,     0,     0,     0,     0,    48,     0,    49,
       0,    51,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
     159,     0,    66,     0,     0,    68,     0,     0,     0,    72,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,     0,     0,     0,     0,    83,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    84,     0,    85,   155,
      86,    87,    14,    15,     0,     0,    89,     0,   160,    19,
      91,     0,   161,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,    29,   156,   157,     0,   867,    34,     0,
      35,     0,     0,    37,     0,     0,    39,    40,     0,    42,
      43,     0,    44,    45,     0,     0,     0,     0,     0,     0,
      48,     0,    49,     0,    51,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,   159,     0,    66,     0,     0,    68,     0,
       0,     0,    72,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,     0,     0,     0,     0,    83,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    84,
       0,    85,   155,    86,    87,    14,    15,     0,     0,    89,
       0,   160,    19,    91,     0,   161,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,    29,   156,   157,     0,
     868,    34,     0,    35,     0,     0,    37,     0,     0,    39,
      40,     0,    42,    43,     0,    44,    45,     0,     0,     0,
       0,     0,     0,    48,     0,    49,     0,    51,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,   159,     0,    66,     0,
       0,    68,     0,     0,     0,    72,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    80,    81,    82,     0,     0,
       0,     0,    83,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    84,     0,    85,   155,    86,    87,    14,    15,
       0,     0,    89,     0,   160,    19,    91,     0,   161,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,    29,
     156,   157,     0,   870,    34,     0,    35,     0,     0,    37,
       0,     0,    39,    40,     0,    42,    43,     0,    44,    45,
       0,     0,     0,     0,     0,     0,    48,     0,    49,     0,
      51,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,   159,
       0,    66,     0,     0,    68,     0,     0,     0,    72,     0,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,     0,     0,     0,     0,    83,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    84,     0,    85,   155,    86,
      87,    14,    15,     0,     0,    89,     0,   160,    19,    91,
       0,   161,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    29,   156,   157,     0,   871,    34,     0,    35,
       0,     0,    37,     0,     0,    39,    40,     0,    42,    43,
       0,    44,    45,     0,     0,     0,     0,     0,     0,    48,
       0,    49,     0,    51,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,   159,     0,    66,     0,     0,    68,     0,     0,
       0,    72,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,    80,    81,    82,     0,     0,     0,     0,    83,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    84,     0,
      85,   155,    86,    87,    14,    15,     0,     0,    89,     0,
     160,    19,    91,     0,   161,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,    29,   156,   157,     0,   872,
      34,     0,    35,     0,     0,    37,     0,     0,    39,    40,
       0,    42,    43,     0,    44,    45,     0,     0,     0,     0,
       0,     0,    48,     0,    49,     0,    51,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,   159,     0,    66,     0,     0,
      68,     0,     0,     0,    72,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,    83,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    84,     0,    85,   155,    86,    87,    14,    15,     0,
       0,    89,     0,   160,    19,    91,     0,   161,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,    29,   156,
     157,     0,   873,    34,     0,    35,     0,     0,    37,     0,
       0,    39,    40,     0,    42,    43,     0,    44,    45,     0,
       0,     0,     0,     0,     0,    48,     0,    49,     0,    51,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,   159,     0,
      66,     0,     0,    68,     0,     0,     0,    72,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80,    81,    82,
       0,     0,     0,     0,    83,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    84,     0,    85,   155,    86,    87,
      14,   576,     0,     0,    89,     0,   160,    19,    91,     0,
     161,     0,     0,     0,     0,   577,     0,     0,     0,     0,
       0,    29,   156,   157,     0,   158,    34,     0,   578,     0,
       0,    37,     0,     0,    39,    40,     0,    42,    43,     0,
      44,    45,     0,     0,     0,     0,     0,     0,   579,     0,
      49,     0,    51,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,   580,   581,    62,    63,
      64,   582,     0,    66,     0,     0,    68,     0,     0,     0,
      72,     0,     0,   583,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,     0,     0,     0,     0,    83,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    84,     0,    85,
     155,    86,    87,    14,    15,     0,     0,    89,     0,   160,
      19,    91,     0,   950,     0,     0,     0,     0,    25,     0,
       0,     0,     0,     0,    29,   156,   157,     0,   158,    34,
       0,    35,     0,     0,    37,     0,     0,    39,    40,     0,
      42,    43,     0,    44,    45,     0,     0,     0,     0,     0,
       0,    48,     0,    49,     0,    51,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,   159,     0,    66,     0,     0,    68,
       0,     0,     0,    72,     0,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,     0,     0,     0,     0,
      83,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      84,     0,    85,   155,    86,    87,    14,    15,     0,     0,
      89,     0,     0,    19,    91,     0,   950,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,    29,   156,   157,
       0,   158,    34,     0,    35,     0,     0,    37,     0,     0,
      39,    40,     0,    42,    43,     0,    44,    45,     0,     0,
       0,     0,     0,     0,    48,     0,    49,     0,    51,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,   159,     0,    66,
       0,     0,    68,     0,     0,     0,    72,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    84,     0,    85,   155,     0,    87,    14,
      15,     0,     0,    89,     0,   160,    19,    91,     0,   161,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
      29,   156,   157,     0,   158,    34,     0,    35,     0,     0,
      37,     0,     0,    39,    40,     0,    42,    43,     0,    44,
      45,     0,     0,     0,     0,     0,     0,    48,     0,    49,
       0,    51,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
     159,     0,    66,     0,     0,    68,     0,     0,     0,    72,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -361,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,  -361,     0,     0,     0,  -361,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   155,    85,     0,
      14,    15,   237,     0,     0,     0,     0,    19,   160,     0,
      91,  -361,   888,     0,     0,    25,     0,     0,     0,     0,
       0,    29,   156,   157,     0,   158,    34,     0,    35,     0,
       0,    37,     0,     0,    39,    40,     0,    42,    43,     0,
      44,    45,     0,     0,     0,     0,     0,     0,    48,     0,
      49,     0,    51,     0,     0,     0,     0,    54,     0,     0,
       0,     0,  -343,     0,     0,     0,    60,    61,    62,    63,
      64,   159,     0,    66,     0,  -343,    68,     0,     0,     0,
      72,     0,     0,    74,     0,     0,     0,  -343,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,     0,     0,     0,     0,     0,     0,     0,
      80,     5,     6,     7,     8,     9,    10,     0,     0,     0,
     155,     0,     0,    14,    15,     0,     0,     0,     0,    85,
      19,     0,   347,     0,  -343,  -484,     0,  -484,    25,  -343,
       0,    91,     0,   950,    29,   156,   157,     0,   158,    34,
       0,    35,     0,     0,    37,     0,     0,    39,    40,     0,
      42,    43,     0,    44,    45,     0,     0,     0,     0,     0,
       0,    48,     0,    49,     0,    51,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,   159,     0,    66,     0,     0,    68,
       0,     0,     0,    72,     0,     0,    74,     5,     6,     7,
       8,     9,    10,     0,     0,     0,   155,     0,     0,    14,
      15,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,    80,    25,     0,     0,     0,     0,     0,
      29,   156,   157,     0,   158,    34,     0,    35,     0,     0,
      37,     0,    85,    39,    40,     0,    42,    43,     0,    44,
      45,     0,   160,     0,    91,     0,   161,    48,     0,    49,
       0,    51,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
     159,     0,    66,     0,     0,    68,     0,     0,     0,    72,
       0,     0,    74,     5,     6,     7,     8,     9,    10,     0,
       0,     0,   155,     0,     0,    14,    15,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,    80,
      25,     0,     0,     0,     0,     0,    29,   156,   157,     0,
     158,    34,     0,    35,     0,     0,    37,     0,    85,    39,
      40,     0,    42,    43,     0,    44,    45,     0,   160,     0,
      91,     0,   584,    48,     0,    49,     0,    51,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,   159,     0,    66,     0,
     917,    68,     0,     0,     0,    72,     0,   742,    74,     0,
       0,     0,   199,   200,   744,     0,     0,     0,     0,   201,
       0,     0,     0,     0,     0,     0,     0,   202,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,   203,     0,
     204,     0,     0,   205,     0,     0,     0,     0,     0,   206,
       0,     0,     0,     0,    85,     0,     0,     0,     0,     0,
     207,     0,     0,     0,     0,     0,    91,     0,   161,   208,
       0,     0,     0,     0,     0,     0,     0,     0,   209,   210,
       0,   211,     0,   212,     0,   918,     0,   304,     0,     0,
       0,     0,   214,     0,   305,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,   332,   333,   334,   335,
     336,   337,     0,     0,   340,   341,   342,   343,     0,   345,
     346,   753,   754,   755,   756,     0,     0,   757,     0,     0,
       0,   758,   759,   760,   761,   762,   763,   764,   765,   766,
     767,   768,   769,     0,   770,   306,     0,   771,   772,   773,
     774,   307,     0,     0,     0,   308,     0,   304,     0,     0,
       0,     0,     0,     0,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,     0,     0,     0,
       0,   307,     0,     0,     0,   308,     0,     0,     0,     0,
       0,   310,     0,   311,   312,   313,     0,   314,   315,   316,
       0,   317,   318,   319,   320,   321,     0,   322,   323,   324,
     325,   307,   326,   327,   328,   308,     0,   329,   330,   331,
       0,     0,   304,     0,     0,     0,   794,     0,     0,   305,
       0,   310,     0,   311,   312,   313,     0,   314,   315,   316,
     306,     0,   318,   319,   320,   309,     0,   322,   323,   324,
     325,     0,     0,     0,   328,     0,     0,   329,   330,   331,
       0,   310,     0,   311,   312,   313,     0,   314,   315,   316,
       0,   317,   318,   319,   320,   321,     0,   322,   323,   324,
     325,     0,   326,   327,   328,     0,   307,   329,   330,   331,
     308,     0,   304,     0,     0,     0,   946,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   310,     0,   311,   312,
     313,     0,   314,   315,   316,     0,   317,   318,   319,   320,
     321,     0,   322,   323,   324,   325,   307,   326,   327,   328,
     308,     0,   329,   330,   331,     0,     0,   304,     0,     0,
       0,   994,     0,     0,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   310,     0,   311,   312,
     313,     0,   314,   315,   316,     0,   317,   318,   319,   320,
     321,     0,   322,   323,   324,   325,     0,   326,   327,   328,
       0,   307,   329,   330,   331,   308,     0,     0,     0,   607,
       0,     0,   304,     0,     0,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,   309,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   310,     0,   311,   312,   313,     0,   314,   315,   316,
       0,   317,   318,   319,   320,   321,     0,   322,   323,   324,
     325,     0,   326,   327,   328,     0,   307,   329,   330,   331,
     308,     0,     0,     0,   916,     0,     0,   304,     0,   391,
       0,     0,     0,     0,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
     309,   332,   333,   334,   335,   336,   337,     0,     0,   340,
     341,   342,   343,     0,   345,   346,   310,     0,   311,   312,
     313,     0,   314,   315,   316,     0,   317,   318,   319,   320,
     321,     0,   322,   323,   324,   325,     0,   326,   327,   328,
       0,   307,   329,   330,   331,   308,   360,     0,     0,     0,
       0,     0,   304,     0,   799,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,   309,   332,   333,   334,   335,
     336,   337,     0,     0,   340,   341,   342,   343,     0,   345,
     346,   310,     0,   311,   312,   313,     0,   314,   315,   316,
       0,   317,   318,   319,   320,   321,     0,   322,   323,   324,
     325,     0,   326,   327,   328,     0,   307,   329,   330,   331,
     308,   360,     0,     0,     0,     0,     0,   304,     0,   804,
       0,     0,     0,     0,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
     309,   332,   333,   334,   335,   336,   337,     0,     0,   340,
     341,   342,   343,     0,   345,   346,   310,     0,   311,   312,
     313,     0,   314,   315,   316,     0,   317,   318,   319,   320,
     321,     0,   322,   323,   324,   325,     0,   326,   327,   328,
       0,   307,   329,   330,   331,   308,   360,     0,     0,     0,
       0,     0,   304,     0,   929,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,   309,   332,   333,   334,   335,
     336,   337,     0,     0,   340,   341,   342,   343,     0,   345,
     346,   310,     0,   311,   312,   313,     0,   314,   315,   316,
       0,   317,   318,   319,   320,   321,     0,   322,   323,   324,
     325,     0,   326,   327,   328,     0,   307,   329,   330,   331,
     308,   360,     0,     0,     0,     0,     0,   304,     0,   930,
       0,     0,     0,     0,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
     309,   332,   333,   334,   335,   336,   337,     0,     0,   340,
     341,   342,   343,     0,   345,   346,   310,     0,   311,   312,
     313,     0,   314,   315,   316,     0,   317,   318,   319,   320,
     321,     0,   322,   323,   324,   325,     0,   326,   327,   328,
       0,   307,   329,   330,   331,   308,   360,     0,     0,     0,
       0,     0,   304,     0,   931,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,   309,   332,   333,   334,   335,
     336,   337,     0,     0,   340,   341,   342,   343,     0,   345,
     346,   310,     0,   311,   312,   313,     0,   314,   315,   316,
       0,   317,   318,   319,   320,   321,     0,   322,   323,   324,
     325,     0,   326,   327,   328,     0,   307,   329,   330,   331,
     308,   360,     0,     0,     0,     0,     0,   304,     0,   932,
       0,     0,     0,     0,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
     309,   332,   333,   334,   335,   336,   337,     0,     0,   340,
     341,   342,   343,     0,   345,   346,   310,     0,   311,   312,
     313,     0,   314,   315,   316,     0,   317,   318,   319,   320,
     321,     0,   322,   323,   324,   325,     0,   326,   327,   328,
       0,   307,   329,   330,   331,   308,   360,     0,     0,     0,
       0,     0,   304,     0,   948,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,   309,   332,   333,   334,   335,
     336,   337,     0,     0,   340,   341,   342,   343,     0,   345,
     346,   310,     0,   311,   312,   313,     0,   314,   315,   316,
       0,   317,   318,   319,   320,   321,     0,   322,   323,   324,
     325,     0,   326,   327,   328,     0,   307,   329,   330,   331,
     308,   360,     0,     0,     0,     0,     0,     0,     0,   949,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   304,
       0,     0,     0,     0,     0,     0,   305,     0,     0,     0,
     309,   332,   333,   334,   335,   336,   337,   306,   383,   340,
     341,   342,   343,     0,   345,   346,   310,     0,   311,   312,
     313,   384,   314,   315,   316,     0,   317,   318,   319,   320,
     321,     0,   322,   323,   324,   325,     0,   326,   327,   328,
     304,     0,   329,   330,   331,     0,   360,   305,     0,     0,
       0,     0,     0,   307,     0,     0,     0,   308,   306,   380,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   381,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   385,     0,     0,     0,   309,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   310,   307,   311,   312,   313,   308,   314,
     315,   316,     0,   317,   318,   319,   320,   321,     0,   322,
     323,   324,   325,     0,   326,   327,   328,   304,     0,   329,
     330,   331,     0,   360,   305,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,   306,   679,     0,     0,     0,
       0,     0,     0,     0,   310,     0,   311,   312,   313,     0,
     314,   315,   316,     0,   317,   318,   319,   320,   321,     0,
     322,   323,   324,   325,     0,   326,   327,   328,   304,     0,
     329,   330,   331,     0,   360,   305,     0,     0,     0,     0,
       0,   307,     0,     0,     0,   308,   306,   223,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   304,
       0,     0,     0,     0,     0,     0,   305,     0,     0,     0,
       0,   385,     0,     0,     0,   309,     0,   306,   673,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   310,   307,   311,   312,   313,   308,   314,   315,   316,
       0,   317,   318,   319,   320,   321,     0,   322,   323,   324,
     325,     0,   326,   327,   328,     0,     0,   329,   330,   331,
       0,   360,     0,   307,     0,     0,   309,   308,     0,   304,
       0,     0,     0,     0,     0,     0,   305,     0,     0,     0,
       0,     0,   310,     0,   311,   312,   313,   306,   314,   315,
     316,     0,   317,   318,   319,   320,   321,   309,   322,   323,
     324,   325,     0,   326,   327,   328,     0,     0,   329,   330,
     331,     0,   360,   310,     0,   311,   312,   313,     0,   314,
     315,   316,     0,   317,   318,   319,   320,   321,     0,   322,
     323,   324,   325,   307,   326,   327,   328,   308,     0,   329,
     330,   331,     0,   360,   304,     0,   691,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   306,     0,     0,     0,     0,   309,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   310,     0,   311,   312,   313,     0,   314,
     315,   316,     0,   317,   318,   319,   320,   321,     0,   322,
     323,   324,   325,     0,   326,   327,   328,     0,   307,   329,
     330,   331,   308,   360,   304,     0,     0,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   306,     0,     0,     0,     0,   388,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   310,     0,
     311,   312,   313,   389,   314,   315,   316,     0,   317,   318,
     319,   320,   321,     0,   322,   323,   324,   325,   307,   326,
     327,   328,   308,     0,   329,   330,   331,     0,   418,     0,
       0,     0,     0,   304,     0,     0,     0,     0,     0,     0,
     305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   306,   309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   362,     0,     0,   310,     0,
     311,   312,   313,     0,   314,   315,   316,     0,   317,   318,
     319,   320,   321,     0,   322,   323,   324,   325,     0,   326,
     327,   328,     0,   390,   329,   330,   331,   307,     0,     0,
       0,   308,     0,   304,     0,     0,     0,     0,     0,     0,
     305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   306,     0,     0,     0,     0,   431,   150,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   310,     0,   311,
     312,   313,   432,   314,   315,   316,     0,   317,   318,   319,
     320,   321,     0,   322,   323,   324,   325,   307,   326,   327,
     328,   308,     0,   329,   330,   331,     0,     0,   304,     0,
       0,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,   519,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,     0,     0,
     520,     0,     0,     0,     0,     0,     0,   310,     0,   311,
     312,   313,     0,   314,   315,   316,     0,   317,   318,   319,
     320,   321,     0,   322,   323,   324,   325,     0,   326,   327,
     328,     0,   307,   329,   330,   331,   308,     0,   304,     0,
       0,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,   521,     0,     0,
       0,     0,     0,     0,     0,     0,   309,     0,     0,   304,
     522,     0,     0,     0,     0,     0,   305,     0,     0,     0,
       0,     0,   310,     0,   311,   312,   313,   306,   314,   315,
     316,     0,   317,   318,   319,   320,   321,     0,   322,   323,
     324,   325,   307,   326,   327,   328,   308,     0,   329,   330,
     331,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     304,     0,     0,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,   307,     0,     0,   309,   308,   306,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,     0,   311,   312,   313,     0,   314,   315,
     316,     0,   317,   318,   319,   320,   321,   309,   322,   323,
     324,   325,     0,   326,   327,   328,     0,     0,   329,   330,
     331,     0,     0,   310,   307,   311,   312,   313,   308,   314,
     315,   316,     0,   317,   318,   319,   320,   321,     0,   322,
     323,   324,   325,     0,   326,   327,   328,   304,   422,   329,
     330,   331,     0,     0,   305,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
       0,     0,     0,     0,   310,     0,   311,   312,   313,     0,
     314,   315,   316,     0,   317,   318,   319,   320,   321,     0,
     322,   323,   324,   325,     0,   326,   327,   328,   304,   424,
     329,   330,   331,     0,     0,   305,     0,     0,     0,     0,
       0,   307,     0,     0,     0,   308,   306,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,     0,     0,     0,     0,     0,
       0,   305,     0,     0,     0,   309,     0,     0,     0,     0,
       0,     0,   306,     0,     0,     0,     0,     0,     0,     0,
       0,   310,   307,   311,   312,   313,   308,   314,   315,   316,
       0,   317,   318,   319,   320,   321,     0,   322,   323,   324,
     325,     0,   326,   327,   328,   304,   426,   329,   330,   331,
       0,     0,   305,     0,     0,     0,   309,     0,   307,     0,
       0,     0,   308,   306,     0,     0,     0,     0,     0,     0,
       0,   523,   310,     0,   311,   312,   313,     0,   314,   315,
     316,     0,   317,   318,   319,   320,   321,     0,   322,   323,
     324,   325,   309,   326,   327,   328,     0,   434,   329,   330,
     331,     0,     0,     0,     0,     0,     0,     0,   310,   307,
     311,   312,   313,   308,   314,   315,   316,     0,   317,   318,
     319,   320,   321,     0,   322,   323,   324,   325,     0,   326,
     327,   328,   304,     0,   329,   330,   331,     0,     0,   305,
       0,     0,   449,   309,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,     0,     0,     0,     0,   310,
       0,   311,   312,   313,     0,   314,   315,   316,     0,   317,
     318,   319,   320,   321,     0,   322,   323,   324,   325,     0,
     326,   327,   328,   304,     0,   329,   330,   331,     0,     0,
     305,     0,     0,     0,     0,     0,   307,     0,     0,     0,
     308,   306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,     0,     0,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
     309,     0,   306,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   310,   307,   311,   312,
     313,   308,   314,   315,   316,     0,   317,   318,   319,   320,
     321,  -456,   322,   323,   324,   325,     0,   326,   327,   328,
       0,     0,   329,   330,   331,     0,     0,   150,   307,     0,
       0,   309,   308,     0,   304,   686,     0,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,   310,     0,   311,
     312,   313,   306,   314,   315,   316,     0,   317,   318,   319,
     320,   321,   309,   322,   323,   324,   325,     0,   326,   327,
     328,     0,     0,   329,   330,   331,     0,     0,   310,     0,
     311,   312,   313,     0,   314,   315,   316,     0,   317,   318,
     319,   320,   321,     0,   322,   323,   324,   325,   307,   326,
     327,   328,   308,   663,   329,   330,   331,     0,     0,   304,
       0,     0,     0,     0,     0,     0,   305,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   306,     0,     0,
     689,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   310,     0,
     311,   312,   313,     0,   314,   315,   316,     0,   317,   318,
     319,   320,   321,     0,   322,   323,   324,   325,     0,   326,
     327,   328,     0,   307,   329,   330,   331,   308,     0,   304,
       0,     0,     0,     0,     0,     0,   305,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   306,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   309,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   310,     0,   311,   312,   313,     0,   314,
     315,   316,     0,   317,   318,   319,   320,   321,     0,   322,
     323,   324,   325,   307,   326,   327,   328,   308,     0,   329,
     330,   331,     0,     0,   304,     0,     0,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   306,   789,     0,     0,   730,   309,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   310,     0,   311,   312,   313,     0,   314,
     315,   316,     0,   317,   318,   319,   320,   321,     0,   322,
     323,   324,   325,     0,   326,   327,   328,     0,   307,   329,
     330,   331,   308,     0,   304,     0,     0,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   306,   792,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,     0,   304,     0,     0,     0,     0,
       0,     0,   305,     0,     0,     0,     0,     0,   310,     0,
     311,   312,   313,   306,   314,   315,   316,     0,   317,   318,
     319,   320,   321,     0,   322,   323,   324,   325,   307,   326,
     327,   328,   308,     0,   329,   330,   331,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   304,   883,     0,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,   307,
       0,     0,   309,   308,   306,     0,     0,     0,     0,     0,
       0,     0,   866,     0,     0,     0,     0,     0,   310,     0,
     311,   312,   313,     0,   314,   315,   316,     0,   317,   318,
     319,   320,   321,   309,   322,   323,   324,   325,     0,   326,
     327,   328,     0,     0,   329,   330,   331,     0,     0,   310,
     307,   311,   312,   313,   308,   314,   315,   316,     0,   317,
     318,   319,   320,   321,     0,   322,   323,   324,   325,     0,
     326,   327,   328,   304,     0,   329,   330,   331,     0,     0,
     305,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,   306,     0,     0,     0,     0,     0,     0,     0,     0,
     310,     0,   311,   312,   313,     0,   314,   315,   316,     0,
     317,   318,   319,   320,   321,     0,   322,   323,   324,   325,
       0,   326,   327,   328,     0,     0,   329,   330,   331,     0,
       0,     0,     0,     0,     0,     0,     0,   307,     0,     0,
       0,   308,     0,     0,     0,     0,     0,     0,   304,     0,
     869,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   310,     0,   311,
     312,   313,     0,   314,   315,   316,     0,   317,   318,   319,
     320,   321,     0,   322,   323,   324,   325,     0,   326,   327,
     328,     0,   307,   329,   330,   331,   308,     0,     0,     0,
       0,     0,     0,   304,     0,   959,     0,     0,     0,     0,
     305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   306,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,     0,   311,   312,   313,     0,   314,   315,
     316,     0,   317,   318,   319,   320,   321,     0,   322,   323,
     324,   325,     0,   326,   327,   328,     0,   307,   329,   330,
     331,   308,     0,     0,     0,     0,     0,     0,   304,     0,
     960,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   310,     0,   311,
     312,   313,     0,   314,   315,   316,     0,   317,   318,   319,
     320,   321,     0,   322,   323,   324,   325,     0,   326,   327,
     328,     0,   307,   329,   330,   331,   308,     0,     0,     0,
       0,     0,     0,   304,     0,   961,     0,     0,     0,     0,
     305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   306,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,     0,   311,   312,   313,     0,   314,   315,
     316,     0,   317,   318,   319,   320,   321,     0,   322,   323,
     324,   325,     0,   326,   327,   328,     0,   307,   329,   330,
     331,   308,     0,     0,     0,     0,     0,     0,   304,     0,
     962,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   310,     0,   311,
     312,   313,     0,   314,   315,   316,     0,   317,   318,   319,
     320,   321,     0,   322,   323,   324,   325,     0,   326,   327,
     328,     0,   307,   329,   330,   331,   308,     0,     0,     0,
       0,     0,     0,   304,     0,   963,     0,     0,     0,     0,
     305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   306,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,     0,   311,   312,   313,     0,   314,   315,
     316,     0,   317,   318,   319,   320,   321,     0,   322,   323,
     324,   325,     0,   326,   327,   328,     0,   307,   329,   330,
     331,   308,     0,     0,     0,     0,     0,     0,   304,     0,
     964,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   310,     0,   311,
     312,   313,     0,   314,   315,   316,     0,   317,   318,   319,
     320,   321,     0,   322,   323,   324,   325,     0,   326,   327,
     328,     0,   307,   329,   330,   331,   308,     0,   304,     0,
       0,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,     0,   311,   312,   313,   306,   314,   315,
     316,     0,   317,   318,   319,   320,   321,     0,   322,   323,
     324,   325,   651,   326,   327,   328,   308,     0,   329,   330,
     331,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   307,     0,     0,   309,   308,   306,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,     0,   311,   312,   313,     0,   314,   315,
     316,     0,   317,   318,   319,   320,   321,   309,   322,   323,
     324,   325,     0,   326,   327,   328,     0,     0,   329,   330,
     331,     0,     0,   310,   307,   311,   312,   313,   308,   314,
     315,   316,     0,   317,   318,   319,   320,     0,     0,   322,
     323,   324,   325,     0,   326,   327,   328,     0,     0,   329,
     330,   331,     0,     0,   624,     0,   198,     0,   309,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,   200,
       0,     0,     0,     0,   310,   201,   311,   312,   313,     0,
     314,   315,   316,   202,   317,   318,   319,   320,     0,     0,
     322,   323,   324,   325,   203,   326,   204,   328,     0,   205,
     329,   330,   331,     0,     0,   206,     0,     0,     0,   198,
       0,     0,     0,     0,     0,     0,   207,     0,     0,     0,
       0,   199,   200,     0,     0,   208,     0,     0,   201,     0,
       0,     0,     0,     0,   209,   210,   202,   211,     0,   212,
       0,   213,     0,     0,     0,     0,     0,   203,   214,   204,
       0,   215,   205,     0,     0,     0,     0,     0,   206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
       0,     0,     0,     0,     0,     0,     0,     0,   208,     0,
       0,     0,     0,     0,     0,     0,     0,   209,   210,     0,
     211,     0,   212,     0,   213,     0,     0,     0,     0,     0,
       0,   214,     0,     0,   215
};

static const yytype_int16 yycheck[] =
{
      11,     2,    30,   135,    15,    52,    53,    18,   404,    17,
     427,   547,    23,   707,   633,     1,    27,    28,   173,    30,
      31,    32,    33,   399,     1,   396,   353,     1,   822,   184,
      41,   427,    43,    44,   575,    46,     1,    48,    49,    42,
     733,   129,   179,   779,   780,    56,    57,    58,    59,    60,
      61,    42,    42,   197,    65,   897,    67,    19,    69,    70,
     197,   104,    29,    74,    75,    76,    77,   155,    56,    80,
     976,    29,    83,    84,    85,    29,    87,    29,   389,    90,
      91,    92,    77,   937,    57,   819,   109,    75,   994,   233,
     784,   298,   299,   300,   301,    60,   233,    42,    42,     1,
      77,   104,    77,    77,    92,   129,   129,    42,   252,   650,
     133,    73,   648,    90,    60,   252,   159,    42,    91,   913,
       0,   432,   976,   109,   286,   102,   129,   259,   102,   823,
      75,   129,    42,   157,   157,    97,   101,   104,   129,   129,
      42,   983,   128,   129,   155,   156,   157,   158,   159,   160,
     161,   128,   149,   887,   128,   101,   159,    19,   981,   154,
     853,   159,    74,   704,   172,    75,    78,   990,   179,   159,
      24,   157,   149,   161,   149,   129,     3,   154,   315,   154,
     154,   104,   875,   919,   920,   129,   197,   154,    15,    16,
     155,   129,   886,    24,   129,    22,   154,   156,   574,   158,
     154,   129,   154,    30,   129,   349,   350,   109,   109,   155,
      64,    73,   349,   350,    41,   159,    43,   155,    47,    46,
     547,    75,   233,   234,   159,    52,   128,   129,   129,   157,
     241,   242,   133,    64,   159,    97,    63,   129,   129,   129,
      69,   252,   936,   862,    75,    72,   100,   149,   109,     3,
     129,   458,    94,   129,    81,    82,   157,    84,   129,    86,
     129,    88,   129,    94,   129,   157,   157,   157,    95,    96,
     281,    98,   133,    69,    70,   811,   420,   278,   157,   307,
     308,   157,   149,   420,   149,   149,   157,   441,   157,   443,
     156,   155,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   156,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   648,   698,   351,   352,   696,     2,   338,   339,   156,
     129,   156,   129,   344,   362,    11,   347,   348,   349,   350,
     351,   352,   353,   129,   129,    24,    22,   156,    24,   158,
     149,   362,   149,   381,    28,   366,   384,   368,     7,   129,
      28,    85,   733,   149,   149,   338,   339,   378,    77,   380,
     381,   344,   383,   384,   347,   348,   156,   388,   389,   149,
     391,    90,   393,   545,   546,    64,    70,   129,   129,    65,
     378,    91,   149,   102,    74,   406,    75,   534,    78,   156,
      74,   158,   413,   149,    78,   149,    74,   149,   149,   420,
      78,   155,   829,   149,    90,    94,    77,   445,    94,   149,
     431,   432,   156,   139,   158,    59,   822,   438,   149,    90,
     441,     3,   443,   829,   445,   446,   447,   149,   449,   450,
     149,   102,   149,   454,   149,   154,   128,   149,   603,   131,
     612,   613,   156,   135,   128,   154,   130,   131,    30,   131,
     128,   135,   149,   131,   475,   476,   454,   135,   441,   143,
     443,    42,   103,   156,   109,   151,   150,   151,   152,   179,
      52,   156,   149,   156,   811,   149,     7,   858,   149,    54,
     128,   154,   520,   154,   522,   149,   109,   197,   157,   129,
     156,   633,   149,    42,   875,    31,    77,   157,   519,   520,
     521,   522,   523,   524,   525,   129,    88,   913,   526,   527,
     157,   532,    94,   534,   109,   157,   537,    18,   539,    28,
     157,   102,   543,   233,   129,    77,   547,   159,   109,   154,
     216,   937,   149,   149,   149,   149,   149,   223,    90,   157,
     946,   129,   252,   149,    31,   189,   190,   191,   129,   532,
     102,   159,   149,   149,   157,   576,   155,    28,   579,   580,
     581,   582,   583,   584,   157,    74,   149,   588,   149,    78,
     976,   149,   129,   154,   154,   981,   157,   109,     2,   155,
      75,    29,   226,    29,   990,   229,   584,    11,   994,   159,
     154,    31,   278,   128,    75,   128,   159,   149,    22,   159,
      24,   159,   154,    74,   248,   588,   156,    78,   155,   131,
     131,   131,   131,   651,   652,   131,   131,   131,   131,   128,
     131,   130,   131,   131,   268,   131,   135,   648,    31,   157,
     651,   652,   653,   102,   143,   656,    90,   155,   731,   349,
     350,    65,   159,   152,   432,    69,    70,   157,   431,    21,
     671,   260,   673,   124,   718,   676,   127,   128,   679,   130,
     131,   185,   797,   684,   135,   686,    90,   536,   689,   736,
      94,    24,   143,   862,   360,   858,   696,   739,   983,   150,
     151,   152,   567,   936,   955,    32,   407,   534,    42,    42,
      42,    27,    45,   714,   380,    -1,    -1,   383,    -1,    -1,
      -1,    -1,    -1,   413,   725,   391,   727,    -1,    61,   730,
     420,    64,    -1,    66,   735,    -1,   714,    -1,    -1,   363,
     862,    -1,    75,    77,    -1,    77,    -1,   151,   438,    -1,
      -1,   441,    -1,   443,    -1,    -1,   446,    -1,    -1,    -1,
      -1,    94,    -1,   387,    -1,    -1,    -1,    -1,   102,    -1,
     102,    -1,    -1,    -1,   775,   109,    -1,   109,    -1,    -1,
      -1,   447,    -1,    -1,    -1,    -1,    -1,   788,   789,    -1,
     791,   792,   793,   794,    -1,   129,   129,   129,   799,   800,
      -1,   802,    -1,   804,   805,    -1,    -1,   808,    -1,    -1,
     811,    -1,   216,   850,   851,   149,    -1,   149,    -1,   223,
     154,    -1,   154,   157,   157,   157,    -1,   828,   829,    -1,
      -1,     2,    -1,   834,    -1,   836,    -1,    -1,    -1,   840,
      11,    -1,   532,    -1,   534,    -1,    -1,    -1,   849,    -1,
     516,    22,    -1,    24,    -1,    -1,   847,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,   866,   867,   868,   869,   870,
     871,   872,   873,    -1,   278,    -1,    -1,    -1,    -1,    -1,
      42,     2,   883,    45,    -1,    -1,    -1,   888,    -1,    -1,
      11,   557,   893,    -1,    65,   896,    -1,    -1,    -1,    61,
      -1,    22,    64,    24,    66,    -1,    -1,    -1,    -1,    -1,
     888,    -1,    -1,    75,    -1,    -1,    -1,   541,   542,    90,
      -1,   545,   546,    94,    -1,    -1,    -1,    -1,   929,   930,
     931,   932,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,   946,    -1,   948,   949,   950,
      -1,   617,    -1,    -1,    -1,    -1,   360,    -1,   959,   960,
     961,   962,   963,   964,    -1,    -1,    -1,   633,    -1,    90,
      23,    -1,   950,    94,   975,   976,   380,    -1,    -1,   383,
     151,    34,    35,    -1,    -1,   651,   652,   391,    -1,   990,
      -1,    44,    -1,   994,    47,    -1,    -1,    -1,    -1,    19,
      -1,    38,    -1,    23,    -1,   671,    -1,   673,    -1,    62,
     676,    -1,    32,   679,    34,    35,    69,    -1,    24,    39,
      -1,    -1,   688,    -1,    44,   691,    -1,    47,    -1,    -1,
     151,    -1,    -1,    -1,    71,    -1,    42,   661,   662,    45,
      -1,    -1,    62,   447,   668,   216,    66,   713,    68,    69,
      -1,    71,   223,    73,   678,    61,    -1,   681,    64,   725,
      66,   727,    -1,    -1,    -1,   731,    -1,    -1,    -1,    75,
       3,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,   116,
      -1,   118,    15,    -1,    -1,    -1,    -1,    -1,    94,    22,
      -1,    -1,    -1,    -1,    -1,   216,     2,    -1,    -1,    28,
      -1,    -1,   223,    -1,    -1,    11,    -1,   278,    41,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    22,    -1,    24,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,   149,
      -1,    -1,   822,   799,    -1,   155,   173,    -1,   804,    72,
      -1,    -1,    -1,    -1,    -1,    74,    -1,   184,    -1,    78,
     187,    84,   818,   557,    -1,    88,    -1,   278,    -1,    65,
      -1,    -1,    95,    -1,   830,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   839,    74,    -1,    -1,   843,    78,    -1,
      -1,   847,   219,    -1,    90,    -1,    -1,    -1,    94,   360,
      -1,    -1,    -1,    -1,    -1,   124,    -1,   126,   127,   128,
     237,   130,   131,   893,    -1,    -1,   135,    -1,   832,   380,
      -1,    -1,   383,   617,   143,    -1,    -1,    -1,   884,    -1,
     391,   150,   151,   152,   124,    -1,    -1,    -1,   128,    -1,
     130,   131,    -1,    -1,    -1,   135,    -1,    -1,    -1,   360,
      -1,    -1,    -1,   143,    -1,   151,    -1,   937,    -1,    -1,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   380,
      -1,    -1,   383,   929,   930,   931,   932,   671,    -1,   673,
     391,    -1,   676,    -1,    -1,   679,   447,    -1,    -1,    -1,
      -1,    -1,   948,   949,   688,     2,   976,   691,    -1,    -1,
      -1,    23,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,   994,    22,     3,    24,    -1,   713,
     216,    -1,    44,    -1,    -1,    47,    -1,   223,    15,    16,
      -1,   725,    54,   727,    -1,    22,   447,   731,    -1,    -1,
      62,    -1,    -1,    30,    -1,    -1,    -1,    69,    70,   376,
      -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    65,    46,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,     2,   399,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      11,    -1,   278,    90,    -1,    72,    -1,    94,    75,    -1,
      -1,    22,    -1,    24,    81,    82,   557,    84,    -1,    86,
      -1,    88,    -1,    -1,    -1,   799,    -1,    -1,    95,     1,
     804,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   818,    -1,   453,    19,    -1,   456,
      -1,    23,    24,    -1,    65,    -1,   830,    -1,    -1,    -1,
      32,    -1,    34,    35,   151,   839,   557,    39,    -1,   843,
      -1,    -1,    44,   847,    23,    47,   617,    -1,    -1,    90,
      -1,    -1,    -1,    94,   360,    34,    35,    -1,    -1,   156,
      62,    -1,    64,    -1,    66,    44,    68,    69,    47,    71,
      -1,    73,    -1,    75,   380,    54,    -1,   383,    -1,    -1,
     884,    -1,    -1,    62,    -1,   391,    -1,    -1,    -1,    -1,
      69,    70,    94,    -1,    -1,    97,   617,    -1,   100,   216,
     671,    -1,   673,    -1,    -1,   676,   223,    -1,   679,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,   688,    -1,    -1,
     691,    -1,    -1,    -1,    -1,   929,   930,   931,   932,    -1,
      -1,    -1,    -1,   570,    -1,    -1,    -1,   574,    -1,    -1,
      -1,   447,   713,    -1,   948,   949,    -1,   149,    -1,    -1,
     671,    -1,   673,   155,   725,   676,   727,    -1,   679,    -1,
     731,   278,   599,    -1,    -1,    -1,   603,   688,    -1,    -1,
     691,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   713,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   725,    -1,   727,    41,    -1,    -1,
     731,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,   799,    -1,
      -1,    -1,    -1,   804,    -1,    69,    70,   278,    -1,    -1,
      -1,    -1,    -1,   360,    -1,    -1,    -1,   818,    -1,    -1,
      -1,   557,    -1,    -1,    -1,    -1,    -1,    -1,   695,   830,
      -1,   698,    -1,   380,    -1,    -1,   383,    -1,   839,    -1,
      -1,    -1,   843,    -1,   391,    -1,   847,    -1,   799,    -1,
      -1,   718,    -1,   804,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   818,    -1,   736,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   830,
      -1,   617,    -1,   884,    -1,    -1,    -1,   754,   839,   360,
      -1,    -1,   843,    -1,    -1,     2,   847,    -1,    -1,    -1,
     447,    -1,    -1,    -1,    11,    -1,    -1,   171,    -1,   380,
      -1,    -1,   383,    -1,    -1,    22,    -1,    24,    -1,    -1,
     391,    -1,    -1,    -1,    -1,   189,   190,   191,   929,   930,
     931,   932,   196,   884,    -1,   671,    -1,   673,    -1,    -1,
     676,    -1,    -1,   679,    -1,    -1,    -1,   948,   949,    -1,
      -1,    -1,   688,    -1,    -1,   691,    -1,    -1,    65,    -1,
      -1,    -1,   226,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   447,   713,   929,   930,
     931,   932,    -1,    90,   248,    -1,    -1,    94,    -1,   725,
      -1,   727,    -1,     2,    -1,   731,    -1,   948,   949,     1,
      -1,    -1,    11,    -1,   268,    -1,    -1,    -1,    -1,    -1,
     557,    -1,    -1,    22,    -1,    24,    -1,    19,    -1,    -1,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    44,    -1,   151,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      62,    -1,    64,   799,    66,    -1,    68,    69,   804,    71,
     617,    73,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,   818,    -1,    -1,    94,   557,    -1,    -1,    -1,
      -1,    -1,    94,    -1,   830,    97,    -1,    -1,   100,   363,
      -1,    -1,    -1,   839,    -1,    -1,    -1,   843,    -1,   216,
      -1,   847,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,    -1,    -1,   387,   671,    -1,   673,    -1,    -1,   676,
      -1,    -1,   679,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   688,   151,    -1,   691,    -1,   617,   149,   884,     3,
      -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    -1,    -1,    -1,   713,    -1,    22,    -1,
      -1,   278,    -1,    -1,    -1,    -1,    30,    -1,   725,    -1,
     727,    -1,    -1,    -1,   731,    -1,    -1,    41,    -1,    43,
      -1,    -1,    46,   929,   930,   931,   932,    -1,    52,    -1,
     671,    -1,   673,    -1,    -1,   676,    -1,   216,   679,    63,
      -1,    -1,   948,   949,   223,    -1,    -1,   688,    72,    -1,
     691,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    95,   713,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   799,   360,   725,    -1,   727,   804,    -1,    -1,
     731,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,
      -1,   818,    -1,   380,    -1,    -1,   383,   541,   542,    -1,
      -1,   545,   546,   830,   391,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   839,    -1,   558,    -1,   843,    -1,    -1,    -1,
     847,    -1,   156,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,    -1,    -1,    -1,    -1,   799,    -1,
      -1,    -1,    -1,   804,    -1,   599,    -1,   884,   139,    -1,
     447,    -1,    -1,    -1,    -1,    -1,    -1,   818,    -1,    -1,
       3,   360,   153,    -1,    -1,   156,    -1,   158,    -1,   830,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,   839,    22,
      -1,   380,   843,    -1,   383,    -1,   847,    30,    -1,    -1,
      -1,    -1,   929,   930,   931,   932,    -1,    -1,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,   661,   662,    52,
      -1,   948,   949,     3,   668,    -1,   670,    -1,    -1,    -1,
      63,   675,    -1,   884,   678,    15,    16,   681,    -1,    72,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    81,    82,
      30,    84,    -1,    86,    -1,    88,    -1,    -1,   447,    -1,
      -1,    41,    95,    43,    -1,    98,    46,    -1,    -1,    -1,
     557,    -1,    52,    -1,    -1,    -1,    -1,   721,   929,   930,
     931,   932,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    28,    -1,   948,   949,    -1,
      -1,    81,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      -1,    -1,    19,    -1,    -1,    95,    23,    -1,    98,    -1,
      -1,   154,    -1,   156,    -1,    32,    -1,    34,    35,    -1,
     617,    -1,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      47,    74,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    66,
      -1,    68,    69,    -1,    71,    -1,    73,    -1,   557,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   671,    -1,   673,    94,   832,   676,
      97,   124,   679,   126,   127,   128,    -1,   130,   131,   132,
      -1,   688,   135,    -1,   691,    -1,    -1,    -1,    -1,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   713,    -1,   617,    -1,
      -1,    -1,    -1,   877,   878,    -1,   880,   881,   725,    -1,
     727,    -1,   149,    -1,   731,    -1,    -1,    10,   155,    -1,
      -1,    19,    -1,   897,    17,    23,    -1,    -1,    -1,   903,
      -1,   905,    -1,   907,    32,    28,    34,    35,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,
      -1,    -1,   671,    -1,   673,    -1,    -1,   676,    -1,    -1,
     679,    -1,    -1,    -1,    62,    -1,    -1,    -1,    66,   688,
      68,    69,   691,    71,    28,    73,    -1,    -1,    -1,    -1,
      -1,    74,   799,    -1,    -1,    78,    -1,   804,    -1,    -1,
      -1,    -1,    -1,    -1,   713,    -1,    94,    -1,    -1,    97,
      -1,   818,    -1,    -1,    -1,    -1,   725,    -1,   727,   983,
      -1,   104,   731,   830,    -1,   108,    -1,    -1,    -1,    -1,
      74,    -1,   839,    -1,    78,    -1,   843,    -1,    -1,    -1,
     847,   124,    -1,   126,   127,   128,    -1,   130,   131,   132,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,   149,   145,   146,   147,    -1,    -1,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   884,    -1,    -1,
     124,    -1,   126,   127,   128,    -1,   130,   131,   132,    -1,
     134,   135,   136,   137,    -1,    -1,   140,   141,   142,   143,
      -1,   145,    -1,   147,    -1,    -1,   150,   151,   152,   818,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   830,   929,   930,   931,   932,    -1,    -1,    -1,    -1,
     839,    -1,    -1,    -1,   843,    -1,    -1,    -1,   847,    -1,
      -1,   948,   949,    -1,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,   884,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    75,
      76,    77,    -1,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    89,    -1,    91,    92,    93,    94,    95,
      -1,    97,    98,    99,   100,    -1,    -1,   103,    -1,   105,
      -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,   144,    -1,
     146,   147,    -1,   149,    -1,    -1,   152,    -1,   154,    -1,
     156,     1,   158,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    28,    15,    16,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,
      50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,    -1,
      74,    -1,    -1,    63,    78,    65,    -1,    67,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,
     124,    -1,   126,   127,   128,    -1,   130,   131,    -1,    -1,
      -1,   135,    -1,    -1,   124,   125,   126,   127,   142,   143,
      -1,    -1,   132,   147,    -1,    -1,   150,   151,   152,    -1,
      -1,    -1,   142,    -1,   144,    -1,   146,   147,   148,    -1,
      -1,    -1,   152,    -1,   154,    -1,   156,    -1,   158,   159,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,   134,   135,   136,   137,   138,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,   149,   150,
     151,   152,    -1,   154,   155,   156,     1,   158,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      75,    76,    77,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    -1,    91,    92,    93,    94,
      95,    -1,    97,    98,    99,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,   144,
      -1,   146,   147,   148,   149,    -1,    -1,   152,    -1,   154,
     155,   156,     1,   158,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    75,    76,    77,    -1,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    -1,    91,    92,    93,    94,    95,    -1,    97,    98,
      99,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,   144,    -1,   146,   147,    -1,
     149,    -1,    -1,   152,    -1,   154,   155,   156,     1,   158,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    75,    76,    77,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,    95,    -1,    97,    98,    99,   100,    -1,    -1,
     103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      -1,   144,    -1,   146,   147,    -1,   149,    -1,    -1,   152,
      -1,   154,   155,   156,     1,   158,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    75,    76,
      77,    -1,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    95,    -1,
      97,    98,    99,   100,    -1,    -1,   103,    -1,   105,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,   144,    -1,   146,
     147,    -1,   149,    -1,    -1,   152,    -1,   154,   155,   156,
       1,   158,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    75,    76,    77,    -1,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,    -1,   144,    -1,   146,   147,    -1,   149,    -1,
      -1,   152,    -1,   154,   155,   156,     1,   158,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      75,    76,    77,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    -1,    91,    92,    93,    94,
      95,    -1,    97,    98,    99,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,   144,
      -1,   146,   147,    -1,   149,    -1,    -1,   152,    -1,   154,
      -1,   156,     1,   158,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    75,    76,    77,    -1,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    -1,    91,    92,    93,    94,    95,    -1,    97,    98,
      99,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,   144,    -1,   146,   147,    -1,
     149,    -1,    -1,   152,    -1,   154,    -1,   156,     1,   158,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    -1,    -1,    -1,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    -1,    75,    76,    77,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,    95,    -1,    97,    98,    99,   100,    -1,    -1,
     103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      -1,   144,    -1,   146,   147,    -1,   149,    -1,    -1,   152,
      -1,   154,    -1,   156,     1,   158,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    -1,    75,    76,
      77,    -1,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    95,    -1,
      97,    98,    99,   100,    -1,    -1,   103,    -1,   105,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,   144,    -1,   146,
     147,    -1,   149,    -1,    -1,   152,    -1,   154,    -1,   156,
       1,   158,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    -1,    75,    76,    77,    -1,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,    -1,   144,    -1,   146,   147,    -1,   149,    -1,
      -1,   152,    -1,   154,    -1,   156,     1,   158,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    -1,
      75,    76,    77,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    -1,    91,    92,    93,    94,
      95,    -1,    97,    98,    99,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,   144,
      -1,   146,   147,    -1,   149,    -1,    -1,   152,    -1,   154,
      -1,   156,     1,   158,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    75,    76,    77,    -1,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    -1,    91,    92,    93,    94,    95,    -1,    97,    98,
      99,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,   144,    -1,   146,   147,    -1,
     149,    -1,    -1,   152,    -1,   154,    -1,   156,     1,   158,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    -1,    -1,    -1,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    -1,    75,    76,    77,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    -1,    91,    92,
      93,    94,    95,    -1,    97,    98,    99,   100,    -1,    -1,
     103,    -1,   105,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      -1,   144,    -1,   146,   147,    -1,   149,    -1,    -1,   152,
      -1,   154,    -1,   156,     1,   158,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    -1,    75,    76,
      77,    -1,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    -1,    91,    92,    93,    94,    95,    -1,
      97,    98,    99,   100,    -1,    -1,   103,    -1,   105,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,   144,    -1,   146,
     147,    -1,   149,    -1,    -1,   152,    -1,   154,    -1,   156,
       1,   158,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    -1,    75,    76,    77,    -1,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    -1,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,    -1,   144,    -1,   146,   147,    -1,   149,    -1,
      -1,   152,    -1,   154,    -1,   156,     1,   158,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    -1,
      75,    76,    77,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    -1,    91,    92,    93,    94,
      95,    -1,    97,    98,    99,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,   144,
      -1,   146,   147,    -1,   149,    -1,    -1,   152,    -1,   154,
      -1,   156,     1,   158,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,   144,    -1,   146,   147,   148,
      -1,    -1,    -1,   152,    -1,   154,    -1,   156,    -1,   158,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      -1,   144,    -1,   146,   147,   148,    -1,    -1,    -1,   152,
      -1,   154,    -1,   156,    -1,   158,   159,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      -1,    67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,   144,    -1,
     146,   147,   148,    -1,    -1,    -1,   152,    -1,   154,    -1,
     156,    -1,   158,   159,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,   144,    -1,   146,   147,    -1,
      -1,    -1,    -1,   152,    -1,   154,    -1,   156,    -1,   158,
     159,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    -1,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,
      -1,    43,    -1,    -1,    46,    47,    -1,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65,    -1,    67,    -1,    69,    -1,    -1,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    94,    95,    -1,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,    -1,   144,    -1,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,   154,    -1,   156,    -1,   158,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,
      16,    -1,    -1,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    47,    -1,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      -1,    67,    -1,    69,    -1,    -1,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      86,    -1,    88,    -1,    -1,    91,    -1,    -1,    94,    95,
      -1,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,   142,    -1,   144,    12,
     146,   147,    15,    16,    -1,    -1,   152,    -1,   154,    22,
     156,    -1,   158,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    91,    92,
      93,    -1,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      -1,   144,    -1,   146,   147,   148,    -1,    -1,    -1,   152,
      -1,   154,    -1,   156,    -1,   158,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    49,    50,    -1,    52,    53,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,
      67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    91,    92,    93,    -1,    95,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,   144,    -1,   146,
     147,   148,    -1,    -1,    -1,   152,    -1,   154,    -1,   156,
     157,   158,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    65,    -1,    67,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    86,    -1,    88,    -1,    -1,
      91,    92,    93,    -1,    95,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,    -1,   144,    -1,   146,   147,   148,    -1,    -1,
      -1,   152,    -1,   154,    -1,   156,   157,   158,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    49,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      65,    -1,    67,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    -1,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,    -1,    -1,   124,
     125,   126,   127,    10,    -1,    -1,    -1,   132,    15,    16,
      17,    -1,    -1,    -1,    -1,    22,    -1,   142,    -1,   144,
      -1,   146,   147,    30,    -1,    -1,    -1,   152,    -1,   154,
      -1,   156,    -1,   158,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,    -1,    -1,
     117,   118,   119,   120,    -1,   122,   123,   124,   125,   126,
     127,    -1,    -1,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
     147,    -1,    -1,   150,   151,   152,   153,    -1,    -1,   156,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    91,    92,
      93,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      -1,   144,    -1,   146,   147,    -1,   149,    -1,    -1,   152,
      -1,   154,    -1,   156,    -1,   158,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    49,    50,    -1,    52,    53,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,
      67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    91,    92,    93,    -1,    95,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,   144,    -1,   146,
     147,   148,    -1,    -1,    -1,   152,    -1,   154,    -1,   156,
      -1,   158,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    52,    53,    -1,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    65,    -1,    67,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    86,    -1,    88,    -1,    -1,
      91,    92,    93,    -1,    95,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,   142,    -1,   144,    12,   146,   147,    15,    16,    -1,
      -1,   152,    -1,   154,    22,   156,    -1,   158,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,
      -1,    49,    50,    -1,    52,    53,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,    67,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,   144,    -1,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,   154,    -1,   156,    -1,
     158,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    -1,    40,    41,
      -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
     142,    -1,   144,    12,   146,   147,    15,    16,    -1,    -1,
     152,    -1,   154,    22,   156,    -1,   158,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    47,    -1,
      49,    50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,    -1,
      69,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   142,    -1,   144,    12,   146,   147,    15,
      16,    -1,    -1,   152,    -1,   154,    22,   156,    -1,   158,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      -1,    67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      86,    -1,    88,    -1,    -1,    91,    92,    93,    -1,    95,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,   142,    -1,   144,    12,
     146,   147,    15,    16,    -1,    -1,   152,    -1,   154,    22,
     156,    -1,   158,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      -1,   144,    -1,   146,   147,   148,    -1,    -1,    -1,   152,
      -1,   154,   155,   156,    -1,   158,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    49,    50,    -1,    52,    53,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,
      67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,   142,    -1,   144,    12,   146,
     147,    15,    16,    -1,    -1,   152,    -1,   154,    22,   156,
      -1,   158,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,    43,
      -1,    -1,    46,    -1,    -1,    49,    50,    -1,    52,    53,
      -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    65,    -1,    67,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,
      -1,    95,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,
     144,    -1,   146,   147,   148,    -1,    -1,    -1,   152,    -1,
     154,    -1,   156,    -1,   158,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,
      -1,    49,    50,    -1,    52,    53,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,   142,    -1,   144,    12,   146,   147,
      15,    16,    -1,    -1,   152,    -1,   154,    22,   156,    -1,
     158,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    49,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      65,    -1,    67,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,   144,
      -1,   146,   147,   148,    -1,    -1,    -1,   152,    -1,   154,
      -1,   156,    -1,   158,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,   144,    -1,   146,   147,   148,
      -1,    -1,    -1,   152,    -1,   154,    -1,   156,    -1,   158,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      -1,   144,    -1,   146,   147,   148,    -1,    -1,    -1,   152,
      -1,   154,    -1,   156,    -1,   158,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    49,    50,    -1,    52,    53,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,
      67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,   142,    -1,   144,    12,   146,
     147,    15,    16,    -1,    -1,   152,    -1,   154,    22,   156,
      -1,   158,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,    43,
      -1,    -1,    46,    -1,    -1,    49,    50,    -1,    52,    53,
      -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    65,    -1,    67,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,
      -1,    95,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,   142,    -1,
     144,    12,   146,   147,    15,    16,    -1,    -1,   152,    -1,
     154,    22,   156,    -1,   158,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    65,    -1,    67,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    86,    -1,    88,    -1,    -1,
      91,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,   142,    -1,   144,    12,   146,   147,    15,    16,    -1,
      -1,   152,    -1,   154,    22,   156,    -1,   158,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,
      -1,    49,    50,    -1,    52,    53,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,   142,    -1,   144,    12,   146,   147,
      15,    16,    -1,    -1,   152,    -1,   154,    22,   156,    -1,
     158,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    49,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      65,    -1,    67,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,   142,    -1,   144,
      12,   146,   147,    15,    16,    -1,    -1,   152,    -1,   154,
      22,   156,    -1,   158,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,
      -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
     142,    -1,   144,    12,   146,   147,    15,    16,    -1,    -1,
     152,    -1,   154,    22,   156,    -1,   158,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   142,    -1,   144,    12,   146,   147,    15,
      16,    -1,    -1,   152,    -1,   154,    22,   156,    -1,   158,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      -1,    67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,   142,    -1,   144,    12,
     146,   147,    15,    16,    -1,    -1,   152,    -1,   154,    22,
     156,    -1,   158,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,   142,
      -1,   144,    12,   146,   147,    15,    16,    -1,    -1,   152,
      -1,   154,    22,   156,    -1,   158,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,
      50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    65,    -1,    67,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,   142,    -1,   144,    12,   146,   147,    15,    16,
      -1,    -1,   152,    -1,   154,    22,   156,    -1,   158,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    49,    50,    -1,    52,    53,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,
      67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,   142,    -1,   144,    12,   146,
     147,    15,    16,    -1,    -1,   152,    -1,   154,    22,   156,
      -1,   158,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,    43,
      -1,    -1,    46,    -1,    -1,    49,    50,    -1,    52,    53,
      -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    65,    -1,    67,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,
      -1,    95,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,   142,    -1,
     144,    12,   146,   147,    15,    16,    -1,    -1,   152,    -1,
     154,    22,   156,    -1,   158,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    65,    -1,    67,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    86,    -1,    88,    -1,    -1,
      91,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,   142,    -1,   144,    12,   146,   147,    15,    16,    -1,
      -1,   152,    -1,   154,    22,   156,    -1,   158,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,
      -1,    49,    50,    -1,    52,    53,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,   142,    -1,   144,    12,   146,   147,
      15,    16,    -1,    -1,   152,    -1,   154,    22,   156,    -1,
     158,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    49,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      65,    -1,    67,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,   142,    -1,   144,
      12,   146,   147,    15,    16,    -1,    -1,   152,    -1,   154,
      22,   156,    -1,   158,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,
      -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
     142,    -1,   144,    12,   146,   147,    15,    16,    -1,    -1,
     152,    -1,    -1,    22,   156,    -1,   158,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   142,    -1,   144,    12,    -1,   147,    15,
      16,    -1,    -1,   152,    -1,   154,    22,   156,    -1,   158,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      -1,    67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
      -1,    -1,    -1,   129,    -1,    -1,    -1,   133,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,   144,    -1,
      15,    16,   148,    -1,    -1,    -1,    -1,    22,   154,    -1,
     156,   157,   158,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    49,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      65,    -1,    67,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,    90,    91,    -1,    -1,    -1,
      95,    -1,    -1,    98,    -1,    -1,    -1,   102,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,   144,
      22,    -1,   153,    -1,   149,   156,    -1,   158,    30,   154,
      -1,   156,    -1,   158,    36,    37,    38,    -1,    40,    41,
      -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    -1,    -1,    98,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,   144,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,   154,    -1,   156,    -1,   158,    63,    -1,    65,
      -1,    67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,
      -1,    -1,    98,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,   125,
      30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      40,    41,    -1,    43,    -1,    -1,    46,    -1,   144,    49,
      50,    -1,    52,    53,    -1,    55,    56,    -1,   154,    -1,
     156,    -1,   158,    63,    -1,    65,    -1,    67,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
       3,    91,    -1,    -1,    -1,    95,    -1,    10,    98,    -1,
      -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,   156,    -1,   158,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    84,    -1,    86,    -1,    88,    -1,    10,    -1,    -1,
      -1,    -1,    95,    -1,    17,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,   109,   110,   111,   112,
     113,   114,    -1,    -1,   117,   118,   119,   120,    -1,   122,
     123,   124,   125,   126,   127,    -1,    -1,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,   147,    28,    -1,   150,   151,   152,
     153,    74,    -1,    -1,    -1,    78,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,    -1,   130,   131,   132,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,    74,   145,   146,   147,    78,    -1,   150,   151,   152,
      -1,    -1,    10,    -1,    -1,    -1,   159,    -1,    -1,    17,
      -1,   124,    -1,   126,   127,   128,    -1,   130,   131,   132,
      28,    -1,   135,   136,   137,   108,    -1,   140,   141,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,   150,   151,   152,
      -1,   124,    -1,   126,   127,   128,    -1,   130,   131,   132,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,    -1,   145,   146,   147,    -1,    74,   150,   151,   152,
      78,    -1,    10,    -1,    -1,    -1,   159,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,   126,   127,
     128,    -1,   130,   131,   132,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,    74,   145,   146,   147,
      78,    -1,   150,   151,   152,    -1,    -1,    10,    -1,    -1,
      -1,   159,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,   126,   127,
     128,    -1,   130,   131,   132,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,    -1,   145,   146,   147,
      -1,    74,   150,   151,   152,    78,    -1,    -1,    -1,   157,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,    -1,   130,   131,   132,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,    -1,   145,   146,   147,    -1,    74,   150,   151,   152,
      78,    -1,    -1,    -1,   157,    -1,    -1,    10,    -1,    87,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,   117,
     118,   119,   120,    -1,   122,   123,   124,    -1,   126,   127,
     128,    -1,   130,   131,   132,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,    -1,   145,   146,   147,
      -1,    74,   150,   151,   152,    78,   154,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    87,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,   117,   118,   119,   120,    -1,   122,
     123,   124,    -1,   126,   127,   128,    -1,   130,   131,   132,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,    -1,   145,   146,   147,    -1,    74,   150,   151,   152,
      78,   154,    -1,    -1,    -1,    -1,    -1,    10,    -1,    87,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,   117,
     118,   119,   120,    -1,   122,   123,   124,    -1,   126,   127,
     128,    -1,   130,   131,   132,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,    -1,   145,   146,   147,
      -1,    74,   150,   151,   152,    78,   154,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    87,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,   117,   118,   119,   120,    -1,   122,
     123,   124,    -1,   126,   127,   128,    -1,   130,   131,   132,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,    -1,   145,   146,   147,    -1,    74,   150,   151,   152,
      78,   154,    -1,    -1,    -1,    -1,    -1,    10,    -1,    87,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,   117,
     118,   119,   120,    -1,   122,   123,   124,    -1,   126,   127,
     128,    -1,   130,   131,   132,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,    -1,   145,   146,   147,
      -1,    74,   150,   151,   152,    78,   154,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    87,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,   117,   118,   119,   120,    -1,   122,
     123,   124,    -1,   126,   127,   128,    -1,   130,   131,   132,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,    -1,   145,   146,   147,    -1,    74,   150,   151,   152,
      78,   154,    -1,    -1,    -1,    -1,    -1,    10,    -1,    87,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,   117,
     118,   119,   120,    -1,   122,   123,   124,    -1,   126,   127,
     128,    -1,   130,   131,   132,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,    -1,   145,   146,   147,
      -1,    74,   150,   151,   152,    78,   154,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    87,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,   117,   118,   119,   120,    -1,   122,
     123,   124,    -1,   126,   127,   128,    -1,   130,   131,   132,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,    -1,   145,   146,   147,    -1,    74,   150,   151,   152,
      78,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,    28,    29,   117,
     118,   119,   120,    -1,   122,   123,   124,    -1,   126,   127,
     128,    42,   130,   131,   132,    -1,   134,   135,   136,   137,
     138,    -1,   140,   141,   142,   143,    -1,   145,   146,   147,
      10,    -1,   150,   151,   152,    -1,   154,    17,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    74,   126,   127,   128,    78,   130,
     131,   132,    -1,   134,   135,   136,   137,   138,    -1,   140,
     141,   142,   143,    -1,   145,   146,   147,    10,    -1,   150,
     151,   152,    -1,   154,    17,    -1,    -1,    -1,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    -1,   126,   127,   128,    -1,
     130,   131,   132,    -1,   134,   135,   136,   137,   138,    -1,
     140,   141,   142,   143,    -1,   145,   146,   147,    10,    -1,
     150,   151,   152,    -1,   154,    17,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,   108,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,    74,   126,   127,   128,    78,   130,   131,   132,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,    -1,   145,   146,   147,    -1,    -1,   150,   151,   152,
      -1,   154,    -1,    74,    -1,    -1,   108,    78,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,    28,   130,   131,
     132,    -1,   134,   135,   136,   137,   138,   108,   140,   141,
     142,   143,    -1,   145,   146,   147,    -1,    -1,   150,   151,
     152,    -1,   154,   124,    -1,   126,   127,   128,    -1,   130,
     131,   132,    -1,   134,   135,   136,   137,   138,    -1,   140,
     141,   142,   143,    74,   145,   146,   147,    78,    -1,   150,
     151,   152,    -1,   154,    10,    -1,    87,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,    -1,   130,
     131,   132,    -1,   134,   135,   136,   137,   138,    -1,   140,
     141,   142,   143,    -1,   145,   146,   147,    -1,    74,   150,
     151,   152,    78,   154,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,    59,   130,   131,   132,    -1,   134,   135,
     136,   137,   138,    -1,   140,   141,   142,   143,    74,   145,
     146,   147,    78,    -1,   150,   151,   152,    -1,   154,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,   124,    -1,
     126,   127,   128,    -1,   130,   131,   132,    -1,   134,   135,
     136,   137,   138,    -1,   140,   141,   142,   143,    -1,   145,
     146,   147,    -1,   149,   150,   151,   152,    74,    -1,    -1,
      -1,    78,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    33,   104,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,    59,   130,   131,   132,    -1,   134,   135,   136,
     137,   138,    -1,   140,   141,   142,   143,    74,   145,   146,
     147,    78,    -1,   150,   151,   152,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,    -1,   130,   131,   132,    -1,   134,   135,   136,
     137,   138,    -1,   140,   141,   142,   143,    -1,   145,   146,
     147,    -1,    74,   150,   151,   152,    78,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    10,
      42,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,    28,   130,   131,
     132,    -1,   134,   135,   136,   137,   138,    -1,   140,   141,
     142,   143,    74,   145,   146,   147,    78,    -1,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,   108,    78,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,    -1,   130,   131,
     132,    -1,   134,   135,   136,   137,   138,   108,   140,   141,
     142,   143,    -1,   145,   146,   147,    -1,    -1,   150,   151,
     152,    -1,    -1,   124,    74,   126,   127,   128,    78,   130,
     131,   132,    -1,   134,   135,   136,   137,   138,    -1,   140,
     141,   142,   143,    -1,   145,   146,   147,    10,   149,   150,
     151,   152,    -1,    -1,    17,    -1,    -1,    -1,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    -1,   126,   127,   128,    -1,
     130,   131,   132,    -1,   134,   135,   136,   137,   138,    -1,
     140,   141,   142,   143,    -1,   145,   146,   147,    10,   149,
     150,   151,   152,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,    74,   126,   127,   128,    78,   130,   131,   132,
      -1,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
     143,    -1,   145,   146,   147,    10,   149,   150,   151,   152,
      -1,    -1,    17,    -1,    -1,    -1,   108,    -1,    74,    -1,
      -1,    -1,    78,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,   124,    -1,   126,   127,   128,    -1,   130,   131,
     132,    -1,   134,   135,   136,   137,   138,    -1,   140,   141,
     142,   143,   108,   145,   146,   147,    -1,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    74,
     126,   127,   128,    78,   130,   131,   132,    -1,   134,   135,
     136,   137,   138,    -1,   140,   141,   142,   143,    -1,   145,
     146,   147,    10,    -1,   150,   151,   152,    -1,    -1,    17,
      -1,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,    -1,   130,   131,   132,    -1,   134,
     135,   136,   137,   138,    -1,   140,   141,   142,   143,    -1,
     145,   146,   147,    10,    -1,   150,   151,   152,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      78,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,    74,   126,   127,
     128,    78,   130,   131,   132,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,   145,   146,   147,
      -1,    -1,   150,   151,   152,    -1,    -1,   104,    74,    -1,
      -1,   108,    78,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,    28,   130,   131,   132,    -1,   134,   135,   136,
     137,   138,   108,   140,   141,   142,   143,    -1,   145,   146,
     147,    -1,    -1,   150,   151,   152,    -1,    -1,   124,    -1,
     126,   127,   128,    -1,   130,   131,   132,    -1,   134,   135,
     136,   137,   138,    -1,   140,   141,   142,   143,    74,   145,
     146,   147,    78,   149,   150,   151,   152,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      31,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,    -1,   130,   131,   132,    -1,   134,   135,
     136,   137,   138,    -1,   140,   141,   142,   143,    -1,   145,
     146,   147,    -1,    74,   150,   151,   152,    78,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,    -1,   130,
     131,   132,    -1,   134,   135,   136,   137,   138,    -1,   140,
     141,   142,   143,    74,   145,   146,   147,    78,    -1,   150,
     151,   152,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,    -1,   130,
     131,   132,    -1,   134,   135,   136,   137,   138,    -1,   140,
     141,   142,   143,    -1,   145,   146,   147,    -1,    74,   150,
     151,   152,    78,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,    28,   130,   131,   132,    -1,   134,   135,
     136,   137,   138,    -1,   140,   141,   142,   143,    74,   145,
     146,   147,    78,    -1,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,   108,    78,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,    -1,   130,   131,   132,    -1,   134,   135,
     136,   137,   138,   108,   140,   141,   142,   143,    -1,   145,
     146,   147,    -1,    -1,   150,   151,   152,    -1,    -1,   124,
      74,   126,   127,   128,    78,   130,   131,   132,    -1,   134,
     135,   136,   137,   138,    -1,   140,   141,   142,   143,    -1,
     145,   146,   147,    10,    -1,   150,   151,   152,    -1,    -1,
      17,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,    -1,   130,   131,   132,    -1,
     134,   135,   136,   137,   138,    -1,   140,   141,   142,   143,
      -1,   145,   146,   147,    -1,    -1,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      87,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,    -1,   130,   131,   132,    -1,   134,   135,   136,
     137,   138,    -1,   140,   141,   142,   143,    -1,   145,   146,
     147,    -1,    74,   150,   151,   152,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    87,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,    -1,   130,   131,
     132,    -1,   134,   135,   136,   137,   138,    -1,   140,   141,
     142,   143,    -1,   145,   146,   147,    -1,    74,   150,   151,
     152,    78,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      87,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,    -1,   130,   131,   132,    -1,   134,   135,   136,
     137,   138,    -1,   140,   141,   142,   143,    -1,   145,   146,
     147,    -1,    74,   150,   151,   152,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    87,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,    -1,   130,   131,
     132,    -1,   134,   135,   136,   137,   138,    -1,   140,   141,
     142,   143,    -1,   145,   146,   147,    -1,    74,   150,   151,
     152,    78,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      87,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,    -1,   130,   131,   132,    -1,   134,   135,   136,
     137,   138,    -1,   140,   141,   142,   143,    -1,   145,   146,
     147,    -1,    74,   150,   151,   152,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    87,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,    -1,   130,   131,
     132,    -1,   134,   135,   136,   137,   138,    -1,   140,   141,
     142,   143,    -1,   145,   146,   147,    -1,    74,   150,   151,
     152,    78,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      87,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,    -1,   130,   131,   132,    -1,   134,   135,   136,
     137,   138,    -1,   140,   141,   142,   143,    -1,   145,   146,
     147,    -1,    74,   150,   151,   152,    78,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,    28,   130,   131,
     132,    -1,   134,   135,   136,   137,   138,    -1,   140,   141,
     142,   143,    74,   145,   146,   147,    78,    -1,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,   108,    78,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,    -1,   130,   131,
     132,    -1,   134,   135,   136,   137,   138,   108,   140,   141,
     142,   143,    -1,   145,   146,   147,    -1,    -1,   150,   151,
     152,    -1,    -1,   124,    74,   126,   127,   128,    78,   130,
     131,   132,    -1,   134,   135,   136,   137,    -1,    -1,   140,
     141,   142,   143,    -1,   145,   146,   147,    -1,    -1,   150,
     151,   152,    -1,    -1,     1,    -1,     3,    -1,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,   124,    22,   126,   127,   128,    -1,
     130,   131,   132,    30,   134,   135,   136,   137,    -1,    -1,
     140,   141,   142,   143,    41,   145,    43,   147,    -1,    46,
     150,   151,   152,    -1,    -1,    52,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    15,    16,    -1,    -1,    72,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    81,    82,    30,    84,    -1,    86,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    41,    95,    43,
      -1,    98,    46,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    98
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   164,   165,     0,     1,     3,     4,     5,     6,     7,
       8,    12,    13,    14,    15,    16,    19,    20,    21,    22,
      23,    25,    26,    27,    29,    30,    32,    34,    35,    36,
      37,    38,    39,    40,    41,    43,    44,    46,    48,    49,
      50,    51,    52,    53,    55,    56,    58,    62,    63,    65,
      66,    67,    68,    71,    72,    73,    76,    77,    79,    80,
      81,    82,    83,    84,    85,    86,    88,    89,    91,    92,
      93,    94,    95,    97,    98,    99,   103,   105,   108,   124,
     125,   126,   127,   132,   142,   144,   146,   147,   149,   152,
     154,   156,   158,   166,   167,   168,   169,   170,   172,   177,
     178,   179,   183,   185,   189,   190,   191,   192,   193,   194,
     196,   197,   198,   202,   203,   206,   207,   210,   211,   214,
     217,   218,   241,   244,   245,   265,   266,   267,   268,   269,
     270,   278,   279,   280,   281,   284,   285,   286,   287,   288,
     289,   290,   292,   293,   294,   295,   296,   149,   168,   281,
     104,   271,   272,     3,   180,    12,    37,    38,    40,    86,
     154,   158,   214,   265,   269,   279,   280,   281,   284,   286,
     287,   271,   281,    94,   180,   168,   259,   281,   168,   156,
     281,   282,     7,     9,    94,   187,   282,    64,   106,   195,
     281,   281,    23,    35,   244,   281,   281,   156,     3,    15,
      16,    22,    30,    41,    43,    46,    52,    63,    72,    81,
      82,    84,    86,    88,    95,    98,   182,   184,   215,   156,
     182,   246,   247,    29,   172,   188,   281,   281,   281,   281,
     281,   281,     7,   156,    35,   191,   191,   148,   237,   258,
     281,    92,    93,   149,   281,   283,   281,   188,   281,   281,
     281,    85,   156,   168,   281,   281,   172,   179,   281,   284,
     172,   179,   281,   182,   242,   281,   258,   281,   281,   281,
     281,   281,   281,   281,   281,     1,   155,   166,   173,   258,
      96,   133,   237,   260,   261,   283,   258,   281,   291,    66,
     168,    70,   171,   182,   182,    47,    69,   232,    24,    64,
      75,   100,   149,   139,    10,    17,    28,    74,    78,   108,
     124,   126,   127,   128,   130,   131,   132,   134,   135,   136,
     137,   138,   140,   141,   142,   143,   145,   146,   147,   150,
     151,   152,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   153,   224,   156,
     158,    74,    78,   156,   168,   149,   281,   281,   281,   258,
     154,   172,    42,   271,   242,   149,   129,   149,   103,   183,
     237,   262,   263,   264,   283,   242,   207,   182,   156,   188,
      29,    42,   188,    29,    42,   104,   188,   274,    33,    59,
     149,    87,   172,   224,   262,   168,   156,   226,    96,   156,
     182,   248,   249,     1,   128,   253,    42,   129,   168,   188,
     188,   262,   182,   129,   149,   281,   281,   149,   154,   188,
     156,   262,   149,   199,   149,   199,   149,   109,   243,   149,
     149,    33,    59,   188,   149,   155,   155,   166,   129,   155,
     281,   129,   157,   129,   157,    42,   129,   159,   274,   107,
     129,   159,     7,    54,   128,   208,   154,   219,    75,   246,
     246,   246,   246,   281,   281,   281,   281,   195,   281,   195,
     281,   281,   281,   281,   281,    16,    98,   281,   281,    30,
      52,    94,   183,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   283,
     283,   283,   283,   283,   262,   262,   195,   281,   195,   281,
      24,    42,    75,   100,   273,   276,   277,   281,   296,    29,
      42,    29,    42,    87,    42,   159,   195,   281,   188,   149,
     281,   281,   109,   157,   129,   149,   182,    42,   258,    40,
     281,   195,   281,    40,   281,   195,   281,   156,   188,   152,
     174,   176,   281,   174,   175,   168,   281,    31,   281,   157,
      24,    42,    45,    61,    64,    75,    94,   167,   227,   228,
     229,   230,   216,   249,   129,   157,    16,    30,    43,    63,
      81,    82,    86,    98,   158,   186,   254,   266,   109,   250,
     281,   247,   157,   237,   281,     1,   204,   262,   157,    18,
     200,   254,   266,   129,   176,   175,   155,   157,   157,   260,
     157,   260,   195,   281,   159,   168,   281,   159,   281,   159,
     281,   182,   258,   154,     1,   182,   212,   213,    24,    64,
      75,    94,   221,   231,   246,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   157,   159,    42,    75,   129,   157,
     265,    74,    74,    40,   195,   281,    40,   195,   281,   195,
     281,   271,   271,   149,   237,   283,   264,   208,   281,   157,
     281,    29,   188,    29,   188,   281,    29,   188,   274,    29,
     188,   274,   275,   276,   129,   149,    11,   149,    31,    31,
     168,    87,   172,    42,    75,   229,   129,   157,   156,   182,
      24,    64,    75,    94,   233,   157,   249,   253,     1,   258,
      57,   283,   155,    60,   101,   155,   205,   157,   156,   172,
     182,   201,   242,   149,   149,   159,   274,   159,   274,   168,
     107,   154,     1,   209,   155,   109,   129,   155,    75,   220,
       1,     3,    10,    15,    17,    22,    41,    46,    52,    72,
      84,    88,    95,   124,   125,   126,   127,   130,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     147,   150,   151,   152,   153,   156,   181,   184,   222,   223,
     224,   265,   149,   276,   253,   265,   265,   281,    29,    29,
     281,    29,    29,   159,   159,   188,   188,   154,   188,    87,
      40,   281,    40,   281,    87,    40,   281,   188,    40,   281,
     188,   129,   157,   281,   281,   168,   281,   168,    31,   182,
     228,   249,   128,   257,    75,   253,   250,   159,    42,   159,
      29,   168,   258,   201,   128,   172,    40,   168,   281,   159,
      40,   168,   281,   159,   281,     1,   155,   173,   155,    35,
      68,    71,   155,   167,   190,   281,   213,   233,   156,   225,
     182,   281,   131,   225,   225,   250,    87,    40,    40,    87,
      40,    40,    40,    40,     1,   209,   281,   281,   281,   281,
     281,   281,   276,    11,    31,   168,   257,   157,   158,   186,
     237,   256,   266,   133,   239,   250,   102,   240,   281,   254,
     266,   168,   188,   157,   281,   281,   168,   281,   168,   155,
     155,   190,     1,   128,   252,   227,   157,     3,    88,   223,
     224,   281,   281,   281,   281,   281,   281,   155,   155,    87,
      87,    87,    87,   281,   168,   250,   257,   159,   258,   237,
     238,   281,   281,   172,   189,   236,   159,   172,    87,    87,
     158,   186,   251,   266,    90,   234,   157,   225,   225,    87,
      87,    87,    87,    87,    87,   281,   281,   281,   281,   239,
     250,   237,   255,   256,   266,    42,   159,   266,   281,   281,
       1,   159,   258,   240,   281,   255,   256,   159,   251,   266,
     159,   149,   235,   236,   159,   251,   266,   255
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   163,   164,   165,   165,   166,   166,   167,   167,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   169,
     169,   169,   170,   170,   170,   171,   171,   172,   172,   172,
     173,   173,   174,   174,   174,   174,   175,   175,   176,   176,
     177,   177,   177,   178,   179,   179,   179,   179,   179,   180,
     180,   181,   181,   181,   182,   182,   182,   183,   183,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   185,   185,   185,   185,   185,
     185,   185,   185,   186,   186,   186,   186,   186,   186,   186,
     186,   187,   187,   188,   188,   189,   189,   190,   190,   190,
     190,   190,   190,   190,   190,   191,   191,   192,   192,   192,
     192,   193,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   195,   196,   196,   196,   196,   196,
     196,   196,   196,   197,   198,   198,   198,   198,   198,   198,
     199,   199,   200,   200,   200,   201,   201,   202,   203,   203,
     204,   204,   205,   205,   205,   206,   206,   206,   206,   207,
     207,   207,   208,   208,   209,   209,   209,   210,   210,   211,
     212,   212,   212,   213,   213,   215,   216,   214,   217,   217,
     217,   217,   217,   219,   220,   218,   221,   221,   221,   221,
     221,   222,   222,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   225,   225,   226,   227,   227,   227,   228,   228,   228,
     228,   228,   229,   229,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   231,   231,   231,   231,   231,   231,   232,
     232,   233,   233,   233,   233,   233,   233,   234,   234,   235,
     235,   236,   236,   237,   237,   238,   238,   239,   239,   240,
     240,   241,   241,   241,   242,   242,   243,   243,   243,   244,
     244,   244,   244,   244,   245,   245,   245,   246,   246,   247,
     247,   248,   248,   248,   249,   249,   249,   250,   250,   250,
     251,   251,   251,   251,   251,   251,   251,   252,   252,   252,
     252,   252,   253,   253,   253,   253,   253,   254,   254,   254,
     254,   255,   255,   255,   256,   256,   256,   256,   256,   257,
     257,   257,   257,   257,   258,   258,   258,   258,   259,   259,
     260,   260,   260,   261,   261,   262,   262,   263,   263,   264,
     264,   264,   264,   265,   265,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   268,   269,
     270,   270,   270,   270,   270,   270,   270,   270,   271,   271,
     272,   273,   273,   274,   275,   275,   276,   276,   276,   277,
     277,   277,   277,   277,   277,   278,   278,   279,   280,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   282,   282,   283,   283,   283,
     284,   284,   284,   284,   285,   285,   286,   286,   286,   287,
     287,   287,   287,   288,   288,   288,   288,   289,   289,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   291,   291,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   293,   293,   293,   293,
     293,   293,   294,   294,   294,   294,   295,   295,   295,   295,
     296,   296,   296,   296,   296,   296,   296
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     2,     2,     3,     2,     6,
       7,     7,     0,     1,     1,     0,     1,     2,     3,     3,
       1,     2,     1,     3,     3,     5,     0,     1,     1,     1,
       3,     5,     5,     3,     4,     4,     4,     4,     4,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     2,     1,     2,     3,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     5,     5,
       2,     2,     5,     3,     6,     6,     4,     5,     5,     3,
       3,     6,     5,     6,     5,     6,     3,     4,     6,     7,
       6,     7,     4,     5,     4,     4,     3,     6,     5,     6,
       5,     8,     7,     2,     3,     3,     2,     2,     3,     3,
       0,     2,     2,     3,     5,     1,     3,     3,     5,     5,
       0,     2,     3,     2,     3,     6,     8,     6,     8,     1,
       1,     1,     0,     2,     0,     2,     3,     5,     5,     1,
       1,     2,     3,     1,     3,     0,     0,     8,     0,     1,
       2,     2,     1,     0,     0,    10,     3,     3,     5,     5,
       3,     1,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     3,     0,     1,     3,     4,     5,     4,
       6,     6,     0,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     0,     1,     1,     2,     1,     1,     1,
       1,     0,     1,     2,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     2,     1,     0,     1,     2,     2,     0,
       2,     3,     4,     4,     2,     4,     0,     2,     2,     4,
       4,     4,     5,     4,     0,     1,     1,     1,     3,     3,
       5,     1,     1,     3,     1,     2,     3,     0,     2,     2,
       3,     2,     4,     3,     3,     4,     3,     0,     2,     2,
       2,     1,     0,     2,     2,     2,     1,     4,     4,     6,
       3,     0,     1,     1,     3,     4,     3,     4,     6,     0,
       2,     2,     2,     2,     1,     1,     3,     3,     1,     3,
       1,     1,     1,     3,     3,     0,     1,     1,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     5,     2,     2,     2,     2,     2,
       2,     6,     6,     4,     9,     9,     7,     6,     6,     4,
       9,     9,     7,     4,     6,     6,     9,     9,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     1,
       4,     1,     3,     4,     1,     3,     4,     3,     3,     1,
       1,     2,     1,     2,     1,     1,     3,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     3,
       3,     3,     2,     2,     1,     0,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     3,
       3,     3,     3,     3,     4,     3,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     4,     3,
       4,     3,     5,     3,     3,     3,     3,     3,     3,     3,
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
#line 466 "chapel.ypp" /* yacc.c:1661  */
    { yyblock = (yyval.pblockstmt); }
#line 5480 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 471 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); resetTempID(); }
#line 5486 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 472 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); context->generatedStmt = (yyvsp[-1].pblockstmt); resetTempID(); }
#line 5492 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 479 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPragmaStmt( (yyvsp[-1].vpch), (yyvsp[0].pblockstmt) ); }
#line 5498 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 484 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.vpch) = new Vec<const char*>(); (yyval.vpch)->add(astr((yyvsp[0].pch))); }
#line 5504 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 485 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].vpch)->add(astr((yyvsp[0].pch))); }
#line 5510 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 504 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 5516 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 505 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAtomicStmt((yyvsp[0].pblockstmt)); }
#line 5522 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 506 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildBeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 5528 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 507 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_BREAK, (yyvsp[-1].pch)); }
#line 5534 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 508 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCobeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));  }
#line 5540 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 509 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_CONTINUE, (yyvsp[-1].pch)); }
#line 5546 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 510 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildDeleteStmt((yyvsp[-1].pcallexpr)); }
#line 5552 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 511 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLabelStmt((yyvsp[-1].pch), (yyvsp[0].pblockstmt)); }
#line 5558 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 512 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5564 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 513 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[0].pblockstmt)); }
#line 5570 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 514 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildOnStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5576 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 515 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildSerialStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5582 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 516 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildSerialStmt(new SymExpr(gTrue), (yyvsp[0].pblockstmt)); }
#line 5588 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 517 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildSyncStmt((yyvsp[0].pblockstmt)); }
#line 5594 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 518 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_YIELD, (yyvsp[-1].pexpr)); }
#line 5600 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 519 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 5606 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 524 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(buildModule((yyvsp[-2].pch), currentModuleType,
    new BlockStmt(), yyfilename, (yyvsp[-5].b), (yyvsp[-4].b), (yylsp[-5]).comment))); }
#line 5613 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 527 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(buildModule((yyvsp[-3].pch), currentModuleType, (yyvsp[-1].pblockstmt), yyfilename, (yyvsp[-6].b), (yyvsp[-5].b), (yylsp[-6]).comment))); }
#line 5619 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 529 "chapel.ypp" /* yacc.c:1661  */
    {(yyval.pblockstmt) = buildChapelStmt(new DefExpr(buildModule((yyvsp[-3].pch), currentModuleType,
        buildErrorStandin(), yyfilename, (yyvsp[-6].b), (yyvsp[-5].b), (yylsp[-6]).comment))); }
#line 5626 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 534 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 5632 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 535 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 5638 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 536 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = true; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 5644 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 540 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; }
#line 5650 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 541 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = true;  }
#line 5656 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 554 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 5662 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 555 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt);              }
#line 5668 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 556 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 5674 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 561 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); (yyval.pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 5680 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 562 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 5686 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 567 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyval.ponlylist)->push_back(cur); }
#line 5696 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 572 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyval.ponlylist)->push_back(cur); }
#line 5706 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 577 "chapel.ypp" /* yacc.c:1661  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyvsp[-2].ponlylist)->push_back(cur); }
#line 5715 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 581 "chapel.ypp" /* yacc.c:1661  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyvsp[-4].ponlylist)->push_back(cur); }
#line 5724 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 588 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = new UnresolvedSymExpr("");
                                         (yyval.ponlylist)->push_back(cur); }
#line 5734 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 597 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = new UnresolvedSymExpr("");
                                         (yyval.ponlylist)->push_back(cur); }
#line 5744 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 606 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-1].pcallexpr)); }
#line 5750 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 607 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true); }
#line 5756 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 608 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false); }
#line 5762 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 612 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildRequireStmt((yyvsp[-1].pcallexpr)); }
#line 5768 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 617 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[-2].pch));   }
#line 5774 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 619 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "<=>"); }
#line 5780 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 621 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), PRIM_REDUCE_ASSIGN); }
#line 5786 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 623 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLAndAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));    }
#line 5792 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 625 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLOrAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));     }
#line 5798 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 631 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = NULL; }
#line 5804 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 632 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 5810 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 636 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 5816 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 637 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "this"; }
#line 5822 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 638 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); redefiningReservedTypeError((yyvsp[0].pch)); }
#line 5828 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 641 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 5834 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 642 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "this"; redefiningReservedWordError("this"); }
#line 5840 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 643 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); redefiningReservedTypeError((yyvsp[0].pch)); }
#line 5846 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 655 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 5852 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 656 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "this"; }
#line 5858 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 667 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "bool"; }
#line 5864 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 668 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "int"; }
#line 5870 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 669 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "uint"; }
#line 5876 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 670 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "real"; }
#line 5882 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 671 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "imag"; }
#line 5888 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 672 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "complex"; }
#line 5894 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 673 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "string"; }
#line 5900 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 674 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "sync"; }
#line 5906 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 675 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "single"; }
#line 5912 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 676 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "owned"; }
#line 5918 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 677 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "shared"; }
#line 5924 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 678 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "borrowed"; }
#line 5930 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 679 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "unmanaged"; }
#line 5936 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 680 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "domain"; }
#line 5942 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 681 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "index"; }
#line 5948 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 682 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "locale"; }
#line 5954 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 686 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtBools[BOOL_SIZE_DEFAULT]->symbol); }
#line 5960 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 687 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtInt[INT_SIZE_DEFAULT]->symbol); }
#line 5966 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 688 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtUInt[INT_SIZE_DEFAULT]->symbol); }
#line 5972 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 689 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtReal[FLOAT_SIZE_DEFAULT]->symbol); }
#line 5978 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 690 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtImag[FLOAT_SIZE_DEFAULT]->symbol); }
#line 5984 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 691 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtComplex[COMPLEX_SIZE_DEFAULT]->symbol); }
#line 5990 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 692 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtString->symbol); }
#line 5996 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 693 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtLocale->symbol); }
#line 6002 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 700 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_syncvar"; }
#line 6008 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 701 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_singlevar"; }
#line 6014 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 702 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_owned"; }
#line 6020 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 703 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_shared"; }
#line 6026 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 704 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_borrowed"; }
#line 6032 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 705 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_unmanaged"; }
#line 6038 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 706 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_domain"; }
#line 6044 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 707 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_index"; }
#line 6050 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 111:
#line 712 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = NULL; }
#line 6056 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 112:
#line 713 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6062 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 717 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6068 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 718 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6074 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 115:
#line 722 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN); }
#line 6080 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 116:
#line 723 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN, (yyvsp[-1].pexpr)); }
#line 6086 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 117:
#line 727 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new BlockStmt()); }
#line 6092 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 729 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6098 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 120:
#line 730 "chapel.ypp" /* yacc.c:1661  */
    { applyPrivateToBlock((yyvsp[0].pblockstmt)); (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6104 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 127:
#line 743 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-1].pexpr)); }
#line 6110 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 128:
#line 744 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true); }
#line 6116 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 129:
#line 745 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false); }
#line 6122 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 130:
#line 746 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForwardingDeclStmt((yyvsp[0].pblockstmt)); }
#line 6128 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 131:
#line 751 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildExternBlockStmt(astr((yyvsp[0].pch)));
    }
#line 6136 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 757 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = DoWhileStmt::build((yyvsp[-1].pexpr), (yyvsp[-3].pblockstmt)); }
#line 6142 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 758 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = WhileDoStmt::build((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6148 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 759 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 6154 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 760 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), true); }
#line 6160 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 761 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 6166 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 137:
#line 762 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 6172 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 763 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 6178 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 764 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 6184 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 765 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 6190 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 766 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildParamForLoopStmt((yyvsp[-3].pch), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6196 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 767 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt)); }
#line 6202 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 143:
#line 768 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt)); }
#line 6208 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 144:
#line 769 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr), NULL, (yyvsp[0].pblockstmt), true); }
#line 6214 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 145:
#line 770 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), true); }
#line 6220 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 771 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt)); }
#line 6226 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 772 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt)); }
#line 6232 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 148:
#line 774 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)));
    }
#line 6242 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 149:
#line 780 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)));
    }
#line 6252 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 786 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pcallexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), true);
    }
#line 6262 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 792 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pcallexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pcallexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), true);
    }
#line 6272 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 152:
#line 798 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = ForallStmt::build(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), NULL, new BlockStmt((yyvsp[0].pblockstmt)));
      else
        (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(), NULL, new BlockStmt((yyvsp[0].pblockstmt)));
    }
#line 6283 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 805 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-3].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = ForallStmt::build(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-3].pcallexpr)), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)));
      else
        (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-3].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)));
    }
#line 6294 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 154:
#line 814 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ZIP, (yyvsp[-1].pcallexpr)); }
#line 6300 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 818 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-2].pexpr), (yyvsp[0].pblockstmt)); }
#line 6306 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 156:
#line 819 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6312 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 157:
#line 820 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-4].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6318 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 158:
#line 821 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-3].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6324 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 159:
#line 822 "chapel.ypp" /* yacc.c:1661  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-4].pexpr),(yyvsp[-3].pch),(yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 6331 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 160:
#line 824 "chapel.ypp" /* yacc.c:1661  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-3].pexpr),(yyvsp[-2].pch),(yyvsp[-1].pexpr)), (yyvsp[0].pblockstmt)); }
#line 6338 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 161:
#line 826 "chapel.ypp" /* yacc.c:1661  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-6].pexpr),(yyvsp[-5].pch),(yyvsp[-4].pexpr)), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6345 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 162:
#line 828 "chapel.ypp" /* yacc.c:1661  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-5].pexpr),(yyvsp[-4].pch),(yyvsp[-3].pexpr)), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6352 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 163:
#line 833 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = DeferStmt::build((yyvsp[0].pblockstmt)); }
#line 6358 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 164:
#line 836 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[-1].pexpr)); }
#line 6364 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 165:
#line 837 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[-1].pexpr)); }
#line 6370 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 166:
#line 838 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[0].pblockstmt)); }
#line 6376 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 167:
#line 839 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[0].pblockstmt)); }
#line 6382 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 168:
#line 840 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[-1].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6388 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 169:
#line 841 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[-1].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6394 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 170:
#line 845 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 6400 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 171:
#line 846 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 6406 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 172:
#line 850 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[0].pblockstmt)); }
#line 6412 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 173:
#line 851 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6418 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 174:
#line 852 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[-2].pexpr), (yyvsp[0].pblockstmt)); }
#line 6424 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 175:
#line 856 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch)), NULL, new UnresolvedSymExpr("Error")); }
#line 6430 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 176:
#line 857 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[-2].pch)), NULL, (yyvsp[0].pexpr));   }
#line 6436 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 177:
#line 861 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_THROW, (yyvsp[-1].pexpr)); }
#line 6442 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 178:
#line 865 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(buildSelectStmt((yyvsp[-3].pexpr), (yyvsp[-1].pblockstmt))); }
#line 6448 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 179:
#line 867 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 6454 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 180:
#line 871 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 6460 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 181:
#line 872 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 6466 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 182:
#line 877 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN, (yyvsp[-1].pcallexpr)), (yyvsp[0].pblockstmt)); }
#line 6472 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 183:
#line 879 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 6478 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 184:
#line 881 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 6484 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 185:
#line 888 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 6498 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 186:
#line 898 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             (yyvsp[-6].pch),
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 6512 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 187:
#line 908 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             new BlockStmt(),
                                             FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 6526 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 188:
#line 918 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             (yyvsp[-6].pch),
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             new BlockStmt(),
                                             FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 6540 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 189:
#line 930 "chapel.ypp" /* yacc.c:1661  */
    {
             (yyval.aggrTag)                     = AGGREGATE_CLASS;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 6550 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 190:
#line 935 "chapel.ypp" /* yacc.c:1661  */
    {
             (yyval.aggrTag)                     = AGGREGATE_RECORD;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 6560 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 191:
#line 940 "chapel.ypp" /* yacc.c:1661  */
    {
             (yyval.aggrTag)                     = AGGREGATE_UNION;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 6570 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 192:
#line 948 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = NULL; }
#line 6576 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 193:
#line 949 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = (yyvsp[0].pcallexpr); }
#line 6582 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 194:
#line 954 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 6588 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 195:
#line 956 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pblockstmt)); }
#line 6594 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 196:
#line 958 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pblockstmt)->insertAtTail(buildPragmaStmt((yyvsp[-1].vpch), (yyvsp[0].pblockstmt))); }
#line 6600 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 197:
#line 963 "chapel.ypp" /* yacc.c:1661  */
    {
      EnumType* pdt = (yyvsp[-4].penumtype);
      for_vector(DefExpr, ec, *(yyvsp[-1].pvecOfDefs)) {
        ec->sym->type = pdt;
        pdt->constants.insertAtTail(ec);
        if (pdt->defaultValue == NULL) {
          pdt->defaultValue = ec->sym;
        }
      }
      delete (yyvsp[-1].pvecOfDefs);
      pdt->doc = (yylsp[-4]).comment;
      TypeSymbol* pst = new TypeSymbol((yyvsp[-3].pch), pdt);
      (yyvsp[-4].penumtype)->symbol = pst;
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr(pst));
    }
#line 6620 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 198:
#line 979 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildErrorStandin();
    }
#line 6628 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 199:
#line 986 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.penumtype) = new EnumType();
      (yyloc).comment = context->latestComment;
      context->latestComment = NULL;
    }
#line 6638 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 200:
#line 995 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pvecOfDefs) = new std::vector<DefExpr*>();
      (yyval.pvecOfDefs)->push_back((yyvsp[0].pdefexpr));
      //$$->doc = context->latestComment;
      // start here for enabling documentation of enum constants
      //context->latestComment = NULL;
    }
#line 6650 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 201:
#line 1003 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pvecOfDefs) = (yyvsp[-1].pvecOfDefs);
    }
#line 6658 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 202:
#line 1007 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyvsp[-2].pvecOfDefs)->push_back((yyvsp[0].pdefexpr));
    }
#line 6666 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 203:
#line 1013 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[0].pch))); }
#line 6672 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 204:
#line 1014 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr)); }
#line 6678 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 205:
#line 1019 "chapel.ypp" /* yacc.c:1661  */
    {
      captureTokens = 1;
      captureString.clear();
    }
#line 6687 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 206:
#line 1024 "chapel.ypp" /* yacc.c:1661  */
    {
      captureTokens = 0;
      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 6696 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 207:
#line 1029 "chapel.ypp" /* yacc.c:1661  */
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
#line 6716 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 208:
#line 1049 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 6727 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 209:
#line 1055 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");
                  (yyval.pfnsymbol)->addFlag(FLAG_INLINE);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 6739 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 210:
#line 1062 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = buildLinkageFn(FLAG_EXPORT, (yyvsp[0].pexpr));

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 6750 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 211:
#line 1068 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = buildLinkageFn(FLAG_EXTERN, (yyvsp[0].pexpr));

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 6761 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 212:
#line 1074 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");
                  (yyval.pfnsymbol)->addFlag(FLAG_OVERRIDE);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 6773 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 213:
#line 1085 "chapel.ypp" /* yacc.c:1661  */
    {
      // Sets up to capture tokens while parsing the next grammar nonterminal.
      captureTokens = 1;
      captureString.clear();
    }
#line 6783 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 214:
#line 1091 "chapel.ypp" /* yacc.c:1661  */
    {
      // Stop capturing and save the result.
      captureTokens = 0;

      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 6794 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 215:
#line 1098 "chapel.ypp" /* yacc.c:1661  */
    {
      FnSymbol* fn = (yyvsp[-6].pfnsymbol);
      FnSymbol* linkageFn = (yyvsp[-9].pfnsymbol);

      fn->copyFlags((yyvsp[-9].pfnsymbol));
      if (*linkageFn->name)
        // The user explicitly named this function (controls mangling).
        fn->cname = linkageFn->name;
      else if (linkageFn->numFormals() == 1)
        // cname should be set based upon param
        fn->insertFormalAtTail(linkageFn->getFormal(1));

      if ((yyvsp[-8].procIter) == ProcIter_ITER)
      {
        if (fn->hasFlag(FLAG_EXTERN))
          USR_FATAL_CONT(fn, "'iter' is not legal with 'extern'");
        fn->addFlag(FLAG_ITERATOR_FN);
      }

      (yyval.pblockstmt) = buildFunctionDecl((yyvsp[-6].pfnsymbol), (yyvsp[-4].retTag), (yyvsp[-3].pexpr), (yyvsp[-2].b), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), (yylsp[-9]).comment);
      context->latestComment = NULL;
    }
#line 6821 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 216:
#line 1124 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
    }
#line 6829 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 217:
#line 1128 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 6838 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 218:
#line 1133 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pexpr));
    }
#line 6846 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 219:
#line 1137 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pexpr));
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 6855 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 220:
#line 1142 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), "dummy", INTENT_BLANK, NULL);
    }
#line 6863 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 222:
#line 1149 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 6869 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 223:
#line 1153 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6875 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 224:
#line 1154 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = astr("~", (yyvsp[0].pch)); }
#line 6881 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 225:
#line 1155 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "&"; }
#line 6887 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 226:
#line 1156 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "|"; }
#line 6893 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 227:
#line 1157 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "^"; }
#line 6899 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 228:
#line 1158 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "~"; }
#line 6905 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 229:
#line 1159 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "=="; }
#line 6911 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 230:
#line 1160 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "!="; }
#line 6917 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 231:
#line 1161 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<="; }
#line 6923 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 232:
#line 1162 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">="; }
#line 6929 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 233:
#line 1163 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<"; }
#line 6935 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 234:
#line 1164 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">"; }
#line 6941 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 235:
#line 1165 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "+"; }
#line 6947 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 236:
#line 1166 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "-"; }
#line 6953 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 237:
#line 1167 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "*"; }
#line 6959 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 238:
#line 1168 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "/"; }
#line 6965 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 239:
#line 1169 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<<"; }
#line 6971 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 240:
#line 1170 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">>"; }
#line 6977 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 241:
#line 1171 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "%"; }
#line 6983 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 242:
#line 1172 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "**"; }
#line 6989 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 243:
#line 1173 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "!"; }
#line 6995 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 244:
#line 1174 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "chpl_by"; }
#line 7001 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 245:
#line 1175 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "#"; }
#line 7007 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 246:
#line 1176 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "chpl_align"; }
#line 7013 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 247:
#line 1177 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<=>"; }
#line 7019 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 248:
#line 1178 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<~>"; }
#line 7025 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 249:
#line 1182 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "="; }
#line 7031 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 250:
#line 1183 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "+="; }
#line 7037 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 251:
#line 1184 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "-="; }
#line 7043 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 252:
#line 1185 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "*="; }
#line 7049 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 253:
#line 1186 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "/="; }
#line 7055 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 254:
#line 1187 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "%="; }
#line 7061 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 255:
#line 1188 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "**="; }
#line 7067 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 256:
#line 1189 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "&="; }
#line 7073 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 257:
#line 1190 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "|="; }
#line 7079 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 258:
#line 1191 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "^="; }
#line 7085 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 259:
#line 1192 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">>="; }
#line 7091 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 260:
#line 1193 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<<="; }
#line 7097 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 261:
#line 1197 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = new FnSymbol("_"); (yyval.pfnsymbol)->addFlag(FLAG_NO_PARENS); }
#line 7103 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 262:
#line 1198 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 7109 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 263:
#line 1202 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 7115 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 264:
#line 1206 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, NULL); }
#line 7121 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 265:
#line 1207 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, (yyvsp[0].pdefexpr)); }
#line 7127 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 266:
#line 1208 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = buildFunctionFormal((yyvsp[-2].pfnsymbol), (yyvsp[0].pdefexpr)); }
#line 7133 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 267:
#line 1213 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), (yyvsp[0].pexpr), NULL); }
#line 7139 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 268:
#line 1215 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildPragmaDefExpr((yyvsp[-4].vpch), buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), (yyvsp[0].pexpr), NULL)); }
#line 7145 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 269:
#line 1217 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), NULL, (yyvsp[0].pexpr)); }
#line 7151 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 270:
#line 1219 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildTupleArgDefExpr((yyvsp[-5].pt), (yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 7157 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 271:
#line 1221 "chapel.ypp" /* yacc.c:1661  */
    { USR_FATAL("variable-length argument may not be grouped in a tuple"); }
#line 7163 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 272:
#line 1225 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_BLANK; }
#line 7169 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 273:
#line 1226 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = (yyvsp[0].pt); }
#line 7175 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 274:
#line 1230 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_IN; }
#line 7181 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 275:
#line 1231 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_INOUT; }
#line 7187 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 276:
#line 1232 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_OUT; }
#line 7193 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 277:
#line 1233 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST; }
#line 7199 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 278:
#line 1234 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST_IN; }
#line 7205 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 279:
#line 1235 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST_REF; }
#line 7211 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 280:
#line 1236 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_PARAM; }
#line 7217 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 281:
#line 1237 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_REF; }
#line 7223 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 282:
#line 1238 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_TYPE; }
#line 7229 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 283:
#line 1242 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_BLANK; }
#line 7235 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 284:
#line 1243 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_PARAM; }
#line 7241 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 285:
#line 1244 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_REF;   }
#line 7247 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 286:
#line 1245 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST_REF;   }
#line 7253 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 287:
#line 1246 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST;   }
#line 7259 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 288:
#line 1247 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_TYPE;  }
#line 7265 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 289:
#line 1251 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.procIter) = ProcIter_PROC; }
#line 7271 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 290:
#line 1252 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.procIter) = ProcIter_ITER; }
#line 7277 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 291:
#line 1256 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_VALUE; }
#line 7283 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 292:
#line 1257 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_VALUE; }
#line 7289 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 293:
#line 1258 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_CONST_REF; }
#line 7295 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 294:
#line 1259 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_REF; }
#line 7301 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 295:
#line 1260 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_PARAM; }
#line 7307 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 296:
#line 1261 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_TYPE; }
#line 7313 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 297:
#line 1265 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; }
#line 7319 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 298:
#line 1266 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = true;  }
#line 7325 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 299:
#line 1269 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = NULL; }
#line 7331 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 302:
#line 1275 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt((yyvsp[0].pblockstmt)); }
#line 7337 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 303:
#line 1280 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 7343 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 304:
#line 1282 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol(astr("chpl__query", istr(query_uid++)))); }
#line 7349 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 305:
#line 1286 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol(astr("chpl__query", istr(query_uid++)))); }
#line 7355 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 307:
#line 1291 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7361 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 308:
#line 1292 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[0].pdefexpr)->sym->addFlag(FLAG_PARAM); (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 7367 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 309:
#line 1296 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7373 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 310:
#line 1297 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7379 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 311:
#line 1302 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt); }
#line 7385 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 312:
#line 1304 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = handleConfigTypes((yyvsp[-1].pblockstmt)); }
#line 7391 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 313:
#line 1306 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = convertTypesToExtern((yyvsp[-1].pblockstmt)); }
#line 7397 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 314:
#line 1311 "chapel.ypp" /* yacc.c:1661  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-1].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[0].pexpr));

      (yyval.pblockstmt) = buildChapelStmt(def);
    }
#line 7414 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 315:
#line 1324 "chapel.ypp" /* yacc.c:1661  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-3].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[-2].pexpr));

      (yyvsp[0].pblockstmt)->insertAtHead(def);
      (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pblockstmt));
    }
#line 7432 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 316:
#line 1340 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7438 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 317:
#line 1342 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7444 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 318:
#line 1344 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExprFromArrayType((yyvsp[0].pcallexpr)); }
#line 7450 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 319:
#line 1349 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-3].flag));
      flags.insert(FLAG_PARAM);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-3]).comment);
      context->latestComment = NULL;
    }
#line 7462 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 320:
#line 1357 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-3].flag));
      flags.insert(FLAG_CONST);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-3]).comment);
      context->latestComment = NULL;
    }
#line 7474 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 321:
#line 1365 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-3].flag));
      flags.insert(FLAG_REF_VAR);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-3]).comment);
      context->latestComment = NULL;
    }
#line 7486 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 322:
#line 1373 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-4].flag));
      flags.insert(FLAG_CONST);
      flags.insert(FLAG_REF_VAR);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-4]).comment);
      context->latestComment = NULL;
    }
#line 7499 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 323:
#line 1382 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-3].flag));
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-3]).comment);
      context->latestComment = NULL;
    }
#line 7510 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 324:
#line 1391 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.flag) = FLAG_UNKNOWN; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 7516 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 325:
#line 1392 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.flag) = FLAG_CONFIG;  (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 7522 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 326:
#line 1393 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.flag) = FLAG_EXTERN;  (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 7528 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 328:
#line 1399 "chapel.ypp" /* yacc.c:1661  */
    {
      for_alist(expr, (yyvsp[0].pblockstmt)->body)
        (yyvsp[-2].pblockstmt)->insertAtTail(expr->remove());
    }
#line 7537 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 329:
#line 1407 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(new VarSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr), (yyvsp[-1].pexpr))); }
#line 7543 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 330:
#line 1409 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildTupleVarDeclStmt((yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 7549 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 331:
#line 1414 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol("chpl__tuple_blank")); }
#line 7555 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 332:
#line 1416 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 7561 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 333:
#line 1418 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[-1].pblockstmt); }
#line 7567 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 334:
#line 1423 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pexpr)); }
#line 7573 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 335:
#line 1425 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 7579 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 336:
#line 1427 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ((yyvsp[0].pblockstmt)->insertAtHead((yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 7585 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 337:
#line 1433 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7591 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 338:
#line 1434 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(gNoInit); }
#line 7597 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 339:
#line 1435 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7603 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 340:
#line 1441 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 7609 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 341:
#line 1443 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, NULL); }
#line 7615 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 342:
#line 1445 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 7623 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 343:
#line 1449 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-1].pcallexpr)), NULL);
    }
#line 7631 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 344:
#line 1453 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 7637 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 345:
#line 1455 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 7645 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 346:
#line 1459 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pexpr) = new CallExpr(PRIM_ERROR);
    }
#line 7653 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 347:
#line 1466 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7659 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 348:
#line 1467 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7665 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 349:
#line 1468 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7671 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 350:
#line 1469 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 7677 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 351:
#line 1470 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7683 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 352:
#line 1475 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7689 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 353:
#line 1476 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7695 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 354:
#line 1477 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pcallexpr); }
#line 7701 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 355:
#line 1478 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 7707 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 356:
#line 1479 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7713 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 357:
#line 1500 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 7721 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 358:
#line 1504 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pcallexpr));
    }
#line 7729 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 359:
#line 1508 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)->get(1)->remove(),
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)->copy()));
    }
#line 7741 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 360:
#line 1516 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pcallexpr) = new CallExpr(PRIM_ERROR);
    }
#line 7749 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 361:
#line 1522 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7755 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 362:
#line 1523 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7761 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 363:
#line 1524 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 7767 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 364:
#line 1529 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 7773 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 365:
#line 1531 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 7779 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 366:
#line 1537 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 7785 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 367:
#line 1539 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 7791 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 368:
#line 1541 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pexpr), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)); }
#line 7797 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 369:
#line 1545 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7803 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 370:
#line 1546 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7809 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 371:
#line 1547 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 7815 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 372:
#line 1548 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 7821 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 373:
#line 1549 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7827 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 374:
#line 1555 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 7833 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 375:
#line 1556 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pdefexpr)); }
#line 7839 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 376:
#line 1557 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 7845 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 377:
#line 1558 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pdefexpr)); }
#line 7851 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 378:
#line 1562 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr));}
#line 7857 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 379:
#line 1563 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 7863 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 380:
#line 1567 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("chpl__tuple_blank"); }
#line 7869 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 381:
#line 1568 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7875 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 382:
#line 1569 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 7881 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 383:
#line 1573 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7887 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 384:
#line 1574 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 7893 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 385:
#line 1578 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); }
#line 7899 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 387:
#line 1583 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 7905 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 388:
#line 1584 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 7911 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 389:
#line 1588 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pdefexpr)); }
#line 7917 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 390:
#line 1589 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pexpr)); }
#line 7923 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 391:
#line 1590 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 7929 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 392:
#line 1591 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7935 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 393:
#line 1595 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 7941 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 394:
#line 1596 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7947 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 400:
#line 1613 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( "_singlevar", (yyvsp[0].pexpr)); }
#line 7953 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 401:
#line 1615 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildIndexType", (yyvsp[-1].pcallexpr)); }
#line 7959 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 402:
#line 1617 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainRuntimeType", new UnresolvedSymExpr("defaultDist"), (yyvsp[-1].pcallexpr)); }
#line 7965 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 403:
#line 1619 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSubDomainType", (yyvsp[-1].pcallexpr)); }
#line 7971 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 404:
#line 1621 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSparseDomainRuntimeType", buildDotExpr((yyvsp[-1].pcallexpr)->copy(), "defaultSparseDist"), (yyvsp[-1].pcallexpr)); }
#line 7977 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 405:
#line 1623 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__atomicType", (yyvsp[0].pexpr)); }
#line 7983 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 406:
#line 1625 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( "_syncvar", (yyvsp[0].pexpr)); }
#line 7989 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 407:
#line 1627 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_BORROWED_CLASS, (yyvsp[0].pexpr)); }
#line 7995 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 408:
#line 1629 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( "_owned", (yyvsp[0].pexpr)); }
#line 8001 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 409:
#line 1631 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_UNMANAGED_CLASS, (yyvsp[0].pexpr)); }
#line 8007 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 410:
#line 1633 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( "_shared", (yyvsp[0].pexpr)); }
#line 8013 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 411:
#line 1638 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8019 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 412:
#line 1640 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true); }
#line 8025 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 413:
#line 1642 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8031 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 414:
#line 1644 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8037 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 415:
#line 1646 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 8043 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 416:
#line 1648 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8049 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 417:
#line 1650 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8055 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 418:
#line 1652 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true); }
#line 8061 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 419:
#line 1654 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8067 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 420:
#line 1656 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8073 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 421:
#line 1658 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 8079 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 422:
#line 1660 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8085 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 423:
#line 1662 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pexpr) = buildForallLoopExpr(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr), NULL, true);
      else
        (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(), (yyvsp[0].pexpr), NULL, true);
    }
#line 8096 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 424:
#line 1669 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), (yyvsp[0].pexpr), NULL, true);
    }
#line 8106 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 425:
#line 1675 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pcallexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true);
    }
#line 8116 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 426:
#line 1681 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8126 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 427:
#line 1687 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pcallexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true);
    }
#line 8136 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 428:
#line 1696 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new IfExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8142 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 429:
#line 1705 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(gNil); }
#line 8148 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 437:
#line 1721 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8154 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 438:
#line 1725 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = NULL; }
#line 8160 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 440:
#line 1730 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 8166 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 441:
#line 1734 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); addTaskIntent((yyval.pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8172 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 442:
#line 1735 "chapel.ypp" /* yacc.c:1661  */
    { addTaskIntent((yyvsp[-2].pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8178 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 443:
#line 1739 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 8184 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 444:
#line 1743 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); addForallIntent((yyval.pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8190 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 445:
#line 1744 "chapel.ypp" /* yacc.c:1661  */
    { addForallIntent((yyvsp[-2].pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8196 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 446:
#line 1749 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildForPrefix((yyvsp[-3].pShadowVarPref), (yyvsp[-2].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pexpr));
    }
#line 8204 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 447:
#line 1753 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromReduceIntent((yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8212 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 448:
#line 1757 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromReduceIntent((yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8220 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 449:
#line 1763 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pShadowVarPref) = SVP_CONST;     }
#line 8226 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 450:
#line 1764 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pShadowVarPref) = SVP_IN;        }
#line 8232 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 451:
#line 1765 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pShadowVarPref) = SVP_CONST_IN;  }
#line 8238 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 452:
#line 1766 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pShadowVarPref) = SVP_REF;       }
#line 8244 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 453:
#line 1767 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pShadowVarPref) = SVP_CONST_REF; }
#line 8250 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 454:
#line 1768 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pShadowVarPref) = SVP_VAR;       }
#line 8256 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 456:
#line 1774 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8262 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 457:
#line 1779 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_NEW, (yyvsp[0].pexpr)); }
#line 8268 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 458:
#line 1784 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildLetExpr((yyvsp[-2].pblockstmt), (yyvsp[0].pexpr)); }
#line 8274 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 467:
#line 1800 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_TUPLE_EXPAND, (yyvsp[-1].pexpr)); }
#line 8280 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 468:
#line 1802 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = createCast((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8286 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 469:
#line 1804 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("_to_borrowed", (yyvsp[-2].pexpr)); }
#line 8292 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 470:
#line 1806 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("_to_unmanaged", (yyvsp[-2].pexpr)); }
#line 8298 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 471:
#line 1808 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_bounded_range", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8304 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 472:
#line 1810 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_low_bounded_range", (yyvsp[-1].pexpr)); }
#line 8310 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 473:
#line 1812 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_high_bounded_range", (yyvsp[0].pexpr)); }
#line 8316 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 474:
#line 1814 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_unbounded_range"); }
#line 8322 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 475:
#line 1818 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 8328 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 476:
#line 1819 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8334 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 477:
#line 1822 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = tryExpr((yyvsp[0].pexpr)); }
#line 8340 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 478:
#line 1823 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = tryBangExpr((yyvsp[0].pexpr)); }
#line 8346 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 479:
#line 1824 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8352 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 486:
#line 1846 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 8358 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 487:
#line 1847 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildSquareCallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 8364 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 488:
#line 1848 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildPrimitiveExpr((yyvsp[-1].pcallexpr)); }
#line 8370 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 489:
#line 1852 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), (yyvsp[0].pch)); }
#line 8376 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 490:
#line 1853 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_TYPEOF, (yyvsp[-2].pexpr)); }
#line 8382 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 491:
#line 1854 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), "_dom"); }
#line 8388 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 492:
#line 1855 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), "locale"); }
#line 8394 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 493:
#line 1863 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 8400 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 494:
#line 1864 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildOneTuple((yyvsp[-2].pexpr)); }
#line 8406 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 495:
#line 1865 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildTuple((yyvsp[-1].pcallexpr)); }
#line 8412 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 496:
#line 1866 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildTuple((yyvsp[-2].pcallexpr)); }
#line 8418 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 497:
#line 1870 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(gFalse); }
#line 8424 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 498:
#line 1871 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(gTrue); }
#line 8430 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 500:
#line 1876 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildIntLiteral((yyvsp[0].pch), yyfilename, chplLineno);    }
#line 8436 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 501:
#line 1877 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildRealLiteral((yyvsp[0].pch));   }
#line 8442 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 502:
#line 1878 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildImagLiteral((yyvsp[0].pch));   }
#line 8448 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 503:
#line 1879 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildStringLiteral((yyvsp[0].pch)); }
#line 8454 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 504:
#line 1880 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildCStringLiteral((yyvsp[0].pch)); }
#line 8460 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 505:
#line 1881 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-1].pcallexpr)); }
#line 8466 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 506:
#line 1882 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-2].pcallexpr)); }
#line 8472 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 507:
#line 1883 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-1].pcallexpr)); }
#line 8478 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 508:
#line 1884 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-2].pcallexpr)); }
#line 8484 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 509:
#line 1886 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-1].pcallexpr));
    }
#line 8492 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 510:
#line 1890 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-2].pcallexpr));
    }
#line 8500 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 511:
#line 1897 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8506 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 512:
#line 1898 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[-2].pexpr)); (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8512 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 513:
#line 1902 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8518 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 514:
#line 1903 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8524 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 515:
#line 1904 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("*", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8530 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 516:
#line 1905 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("/", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8536 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 517:
#line 1906 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8542 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 518:
#line 1907 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8548 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 519:
#line 1908 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("%", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8554 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 520:
#line 1909 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8560 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 521:
#line 1910 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("!=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8566 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 522:
#line 1911 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8572 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 523:
#line 1912 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8578 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 524:
#line 1913 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8584 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 525:
#line 1914 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8590 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 526:
#line 1915 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8596 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 527:
#line 1916 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("|", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8602 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 528:
#line 1917 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("^", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8608 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 529:
#line 1918 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("&&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8614 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 530:
#line 1919 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("||", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8620 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 531:
#line 1920 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("**", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8626 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 532:
#line 1921 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_by", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8632 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 533:
#line 1922 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_align", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8638 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 534:
#line 1923 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("#", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8644 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 535:
#line 1924 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__distributed", (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8650 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 536:
#line 1928 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[0].pexpr)); }
#line 8656 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 537:
#line 1929 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[0].pexpr)); }
#line 8662 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 538:
#line 1930 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '-'); }
#line 8668 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 539:
#line 1931 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '+'); }
#line 8674 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 540:
#line 1932 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("!", (yyvsp[0].pexpr)); }
#line 8680 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 541:
#line 1933 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("~", (yyvsp[0].pexpr)); }
#line 8686 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 542:
#line 1937 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8692 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 543:
#line 1938 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 8698 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 544:
#line 1939 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8704 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 545:
#line 1940 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 8710 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 546:
#line 1944 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8716 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 547:
#line 1945 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 8722 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 548:
#line 1946 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8728 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 549:
#line 1947 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 8734 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 550:
#line 1952 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("SumReduceScanOp"); }
#line 8740 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 551:
#line 1953 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("ProductReduceScanOp"); }
#line 8746 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 552:
#line 1954 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalAndReduceScanOp"); }
#line 8752 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 553:
#line 1955 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalOrReduceScanOp"); }
#line 8758 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 554:
#line 1956 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseAndReduceScanOp"); }
#line 8764 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 555:
#line 1957 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseOrReduceScanOp"); }
#line 8770 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 556:
#line 1958 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseXorReduceScanOp"); }
#line 8776 "bison-chapel.cpp" /* yacc.c:1661  */
    break;


#line 8780 "bison-chapel.cpp" /* yacc.c:1661  */
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
