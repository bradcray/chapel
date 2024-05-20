/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YYCHPL_BISON_CHPL_LIB_H_INCLUDED
# define YY_YYCHPL_BISON_CHPL_LIB_H_INCLUDED
/* Debug traces.  */
#ifndef YYCHPL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define YYCHPL_DEBUG 1
#  else
#   define YYCHPL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define YYCHPL_DEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined YYCHPL_DEBUG */
#if YYCHPL_DEBUG
extern int yychpl_debug;
#endif
/* "%code requires" blocks.  */
#line 72 "chpl.ypp"

  #include "parser-dependencies.h"
  #include "chpl/util/assertions.h"
#line 78 "chpl.ypp"

  #ifndef _BISON_CHAPEL_DEFINES_0_
  #define _BISON_CHAPEL_DEFINES_0_

  #define YYLEX_NEWLINE                  -1
  #define YYLEX_SINGLE_LINE_COMMENT      -2
  #define YYLEX_BLOCK_COMMENT            -3

  typedef void* yyscan_t;

  namespace chpl {
    int processNewline(yyscan_t scanner);
  }

  // Include the already defined parser location type so that we can use it.
  #include "parser-yyltype.h"

  #endif
#line 107 "chpl.ypp"

  #ifndef _BISON_CHAPEL_DEFINES_1_
  #define _BISON_CHAPEL_DEFINES_1_

  // TODO: Replace me with bool.
  enum ThrowsTag {
    ThrowsTag_DEFAULT,
    ThrowsTag_THROWS,
  };

  using ParserExprList = std::vector<AstNode*>;
  using UniqueStrList = std::vector<PODUniqueString>;

  // these structures do not use constructors to avoid
  // errors about being in the union below. Additionally
  // they only have pointer or numeric fields.

  struct WhereAndLifetime {
    AstNode* where;
    ParserExprList* lifetime;
  };
  static inline
  WhereAndLifetime makeWhereAndLifetime(AstNode* w, ParserExprList* lt) {
    WhereAndLifetime ret = {w, lt};
    return ret;
  }

  // This is used to propagate any comments that hug the top of a statement
  // upwards through parser rules.
  struct CommentsAndStmt {
    std::vector<ParserComment>* comments;
    AstNode* stmt;
  };
  static inline
  CommentsAndStmt makeCommentsAndStmt(std::vector<ParserComment>* comments,
                                      AstNode* stmt) {
    CommentsAndStmt ret = {comments, stmt};
    return ret;
  }
  static inline
  CommentsAndStmt makeCommentsAndStmt(std::vector<ParserComment>* comments,
                                      owned<AstNode> stmt) {
    return makeCommentsAndStmt(comments, stmt.release());
  }

  // A struct for storing a partially constructed function prototype
  // during parsing for linkage_spec/fn_decl_stmt/etc
  // It is just saving some components of a function to be used
  // when building the FunctionDecl.
  struct FunctionParts {
    bool isBodyNonBlockExpression;
    std::vector<ParserComment>* comments;
    ErroneousExpression* errorExpr; // only used for parser error
    AttributeGroup* attributeGroup;
    Decl::Visibility visibility;
    Decl::Linkage linkage;
    AstNode* linkageNameExpr;
    bool isInline;
    bool isOverride;
    Function::Kind kind;
    Formal::Intent thisIntent;
    Formal* receiver;
    Identifier* name;
    Function::ReturnIntent returnIntent;
    bool throws;
    ParserExprList* formals;
    AstNode* returnType;
    AstNode* where;
    ParserExprList* lifetime;
    ParserExprList* body;
    TextLocation headerLoc;
  };

  // A struct to thread along some pieces of a module before it is built.
  struct ModuleParts {
    std::vector<ParserComment>* comments;
    AttributeGroup* attributeGroup;
    Decl::Visibility visibility;
    Module::Kind kind;
    PODUniqueString name;
    TextLocation locName;
  };

  // A struct to thread along some pieces of a type before it is built.
  struct TypeDeclParts {
    std::vector<ParserComment>* comments;
    Decl::Visibility visibility;
    Decl::Linkage linkage;
    AstNode* linkageName;
    AttributeGroup* attributeGroup;
    PODUniqueString name;
    asttags::AstTag tag;
    TextLocation locName;
  };

  // This is produced by do_stmt. It records whether the do_stmt statements
  // were produced following a 'do' or not. E.g...
  // do { ... } vs { ... }
  struct BlockOrDo {
    CommentsAndStmt cs;
    bool usesDo;
  };

  struct SizedStr {
    const char* allocatedData; // *not* a uniqued string!
    long size;
  };

  struct MaybeNamedActual {
    AstNode* expr;
    PODUniqueString name;
    TextLocation locName;
  };

  static inline MaybeNamedActual
  makeMaybeNamedActual(AstNode* expr, PODUniqueString name,
                       TextLocation locName=TextLocation::create()) {
    MaybeNamedActual ret = {expr, name, locName};
    return ret;
  }
  static inline
  MaybeNamedActual makeMaybeNamedActual(AstNode* expr) {
    PODUniqueString emptyName = PODUniqueString::get();
    MaybeNamedActual ret = {expr, emptyName, TextLocation::create()};
    return ret;
  }

  using MaybeNamedActualList = std::vector<MaybeNamedActual>;

  // These currently all need to be POD types (i.e. pointers and ints)
  // rather than say std::vector to keep bison working with the current
  // strategy. In the future we could probably switch to a more
  // C++ mode of using bison.
  union YYCHPL_STYPE {
    // The lexer only uses these
    PODUniqueString uniqueStr;
    SizedStr sizedStr;
    AstNode* expr;

    // The remaining types are used only in parser productions

    // integer/enum values

    asttags::AstTag astTag;
    Formal::Intent intentTag;
    Function::Kind functionKind;
    Function::ReturnIntent returnTag;
    Decl::Linkage linkageTag;
    Module::Kind moduleKind;
    New::Management newManagement;
    TaskVar::Intent taskIntent;
    Decl::Visibility visibilityTag;
    ThrowsTag throwsTag;
    Variable::Kind variableKind;

    // simple pointer values
    AttributeGroup* attributeGroup;
    Block* block;
    Call* call;
    Function* function;
    Module* module;
    WithClause* withClause;

    // values that are temporary groupings
    BlockOrDo blockOrDo;
    CommentsAndStmt commentsAndStmt;
    TypeDeclParts typeDeclParts;
    FunctionParts functionParts;
    MaybeNamedActual maybeNamedActual;
    MaybeNamedActualList* maybeNamedActualList;
    ModuleParts moduleParts;
    ParserExprList* exprList;
    UniqueStrList* uniqueStrList;
    WhereAndLifetime lifetimeAndWhere;
  };

  // Put our types in a different namespace to avoid conflicting with the
  // production compiler parser's YYSTYPE.
  #define YYSTYPE YYCHPL_STYPE

  // Note that the 'YYSTYPE_IS_TRIVIAL' macro tells the generated parser
  // that YYSTYPE only contains simple scalars (it can be bitcopied).
  // This is normally communicated by the '%union' directive, but we
  // stopped using that.
  #define YYCHPL_STYPE_IS_TRIVIAL 1
  #define YYSTYPE_IS_TRIVIAL 1

  #endif
#line 301 "chpl.ypp"

  // forward declare ParserContext
  struct ParserContext;

#line 274 "bison-chpl-lib.h"

/* Token kinds.  */
#ifndef YYCHPL_TOKENTYPE
# define YYCHPL_TOKENTYPE
  enum yychpl_tokentype
  {
    YYCHPL_EMPTY = -2,
    YYCHPL_EOF = 0,                /* "end of file"  */
    YYCHPL_error = 256,            /* error  */
    YYCHPL_UNDEF = 257,            /* "invalid token"  */
    TIDENT = 258,                  /* TIDENT  */
    TQUERIEDIDENT = 259,           /* TQUERIEDIDENT  */
    TATTRIBUTEIDENT = 260,         /* TATTRIBUTEIDENT  */
    INTLITERAL = 261,              /* INTLITERAL  */
    REALLITERAL = 262,             /* REALLITERAL  */
    IMAGLITERAL = 263,             /* IMAGLITERAL  */
    STRINGLITERAL = 264,           /* STRINGLITERAL  */
    BYTESLITERAL = 265,            /* BYTESLITERAL  */
    CSTRINGLITERAL = 266,          /* CSTRINGLITERAL  */
    EXTERNCODE = 267,              /* EXTERNCODE  */
    TALIGN = 268,                  /* TALIGN  */
    TAS = 269,                     /* TAS  */
    TATOMIC = 270,                 /* TATOMIC  */
    TBEGIN = 271,                  /* TBEGIN  */
    TBREAK = 272,                  /* TBREAK  */
    TBOOL = 273,                   /* TBOOL  */
    TBORROWED = 274,               /* TBORROWED  */
    TBY = 275,                     /* TBY  */
    TBYTES = 276,                  /* TBYTES  */
    TCATCH = 277,                  /* TCATCH  */
    TCLASS = 278,                  /* TCLASS  */
    TCOBEGIN = 279,                /* TCOBEGIN  */
    TCOFORALL = 280,               /* TCOFORALL  */
    TCOMPLEX = 281,                /* TCOMPLEX  */
    TCONFIG = 282,                 /* TCONFIG  */
    TCONST = 283,                  /* TCONST  */
    TCONTINUE = 284,               /* TCONTINUE  */
    TDEFER = 285,                  /* TDEFER  */
    TDELETE = 286,                 /* TDELETE  */
    TDMAPPED = 287,                /* TDMAPPED  */
    TDO = 288,                     /* TDO  */
    TDOMAIN = 289,                 /* TDOMAIN  */
    TELSE = 290,                   /* TELSE  */
    TENUM = 291,                   /* TENUM  */
    TEXCEPT = 292,                 /* TEXCEPT  */
    TEXPORT = 293,                 /* TEXPORT  */
    TEXTERN = 294,                 /* TEXTERN  */
    TFALSE = 295,                  /* TFALSE  */
    TFOR = 296,                    /* TFOR  */
    TFORALL = 297,                 /* TFORALL  */
    TFOREACH = 298,                /* TFOREACH  */
    TFORWARDING = 299,             /* TFORWARDING  */
    TIF = 300,                     /* TIF  */
    TIMAG = 301,                   /* TIMAG  */
    TIMPORT = 302,                 /* TIMPORT  */
    TIN = 303,                     /* TIN  */
    TINCLUDE = 304,                /* TINCLUDE  */
    TINDEX = 305,                  /* TINDEX  */
    TINLINE = 306,                 /* TINLINE  */
    TINOUT = 307,                  /* TINOUT  */
    TINT = 308,                    /* TINT  */
    TITER = 309,                   /* TITER  */
    TINIT = 310,                   /* TINIT  */
    TINITEQUALS = 311,             /* TINITEQUALS  */
    TIMPLEMENTS = 312,             /* TIMPLEMENTS  */
    TINTERFACE = 313,              /* TINTERFACE  */
    TLABEL = 314,                  /* TLABEL  */
    TLAMBDA = 315,                 /* TLAMBDA  */
    TLET = 316,                    /* TLET  */
    TLIFETIME = 317,               /* TLIFETIME  */
    TLOCAL = 318,                  /* TLOCAL  */
    TLOCALE = 319,                 /* TLOCALE  */
    TMANAGE = 320,                 /* TMANAGE  */
    TMINUSMINUS = 321,             /* TMINUSMINUS  */
    TMODULE = 322,                 /* TMODULE  */
    TNEW = 323,                    /* TNEW  */
    TNIL = 324,                    /* TNIL  */
    TNOINIT = 325,                 /* TNOINIT  */
    TNONE = 326,                   /* TNONE  */
    TNOTHING = 327,                /* TNOTHING  */
    TON = 328,                     /* TON  */
    TONLY = 329,                   /* TONLY  */
    TOPERATOR = 330,               /* TOPERATOR  */
    TOTHERWISE = 331,              /* TOTHERWISE  */
    TOUT = 332,                    /* TOUT  */
    TOVERRIDE = 333,               /* TOVERRIDE  */
    TOWNED = 334,                  /* TOWNED  */
    TPARAM = 335,                  /* TPARAM  */
    TPLUSPLUS = 336,               /* TPLUSPLUS  */
    TPRAGMA = 337,                 /* TPRAGMA  */
    TPRIMITIVE = 338,              /* TPRIMITIVE  */
    TPRIVATE = 339,                /* TPRIVATE  */
    TPROC = 340,                   /* TPROC  */
    TPROTOTYPE = 341,              /* TPROTOTYPE  */
    TPUBLIC = 342,                 /* TPUBLIC  */
    TPROCLP = 343,                 /* TPROCLP  */
    TREAL = 344,                   /* TREAL  */
    TRECORD = 345,                 /* TRECORD  */
    TREDUCE = 346,                 /* TREDUCE  */
    TREF = 347,                    /* TREF  */
    TREQUIRE = 348,                /* TREQUIRE  */
    TRETURN = 349,                 /* TRETURN  */
    TSCAN = 350,                   /* TSCAN  */
    TSELECT = 351,                 /* TSELECT  */
    TSERIAL = 352,                 /* TSERIAL  */
    TSHARED = 353,                 /* TSHARED  */
    TSINGLE = 354,                 /* TSINGLE  */
    TSPARSE = 355,                 /* TSPARSE  */
    TSTRING = 356,                 /* TSTRING  */
    TSUBDOMAIN = 357,              /* TSUBDOMAIN  */
    TSYNC = 358,                   /* TSYNC  */
    TTHEN = 359,                   /* TTHEN  */
    TTHIS = 360,                   /* TTHIS  */
    TTHROW = 361,                  /* TTHROW  */
    TTHROWS = 362,                 /* TTHROWS  */
    TTRUE = 363,                   /* TTRUE  */
    TTRY = 364,                    /* TTRY  */
    TTRYBANG = 365,                /* TTRYBANG  */
    TTYPE = 366,                   /* TTYPE  */
    TUINT = 367,                   /* TUINT  */
    TUNDERSCORE = 368,             /* TUNDERSCORE  */
    TUNION = 369,                  /* TUNION  */
    TUNMANAGED = 370,              /* TUNMANAGED  */
    TUSE = 371,                    /* TUSE  */
    TVAR = 372,                    /* TVAR  */
    TVOID = 373,                   /* TVOID  */
    TWHEN = 374,                   /* TWHEN  */
    TWHERE = 375,                  /* TWHERE  */
    TWHILE = 376,                  /* TWHILE  */
    TWITH = 377,                   /* TWITH  */
    TYIELD = 378,                  /* TYIELD  */
    TZIP = 379,                    /* TZIP  */
    TALIAS = 380,                  /* TALIAS  */
    TAND = 381,                    /* TAND  */
    TASSIGN = 382,                 /* TASSIGN  */
    TASSIGNBAND = 383,             /* TASSIGNBAND  */
    TASSIGNBOR = 384,              /* TASSIGNBOR  */
    TASSIGNBXOR = 385,             /* TASSIGNBXOR  */
    TASSIGNDIVIDE = 386,           /* TASSIGNDIVIDE  */
    TASSIGNEXP = 387,              /* TASSIGNEXP  */
    TASSIGNLAND = 388,             /* TASSIGNLAND  */
    TASSIGNLOR = 389,              /* TASSIGNLOR  */
    TASSIGNMINUS = 390,            /* TASSIGNMINUS  */
    TASSIGNMOD = 391,              /* TASSIGNMOD  */
    TASSIGNMULTIPLY = 392,         /* TASSIGNMULTIPLY  */
    TASSIGNPLUS = 393,             /* TASSIGNPLUS  */
    TASSIGNREDUCE = 394,           /* TASSIGNREDUCE  */
    TASSIGNSL = 395,               /* TASSIGNSL  */
    TASSIGNSR = 396,               /* TASSIGNSR  */
    TATMARK = 397,                 /* TATMARK  */
    TBANG = 398,                   /* TBANG  */
    TBAND = 399,                   /* TBAND  */
    TBNOT = 400,                   /* TBNOT  */
    TBOR = 401,                    /* TBOR  */
    TBXOR = 402,                   /* TBXOR  */
    TCOLON = 403,                  /* TCOLON  */
    TCOMMA = 404,                  /* TCOMMA  */
    TDIVIDE = 405,                 /* TDIVIDE  */
    TDOT = 406,                    /* TDOT  */
    TDOTDOT = 407,                 /* TDOTDOT  */
    TDOTDOTDOT = 408,              /* TDOTDOTDOT  */
    TEQUAL = 409,                  /* TEQUAL  */
    TEXP = 410,                    /* TEXP  */
    TGREATER = 411,                /* TGREATER  */
    TGREATEREQUAL = 412,           /* TGREATEREQUAL  */
    THASH = 413,                   /* THASH  */
    TLESS = 414,                   /* TLESS  */
    TLESSEQUAL = 415,              /* TLESSEQUAL  */
    TMINUS = 416,                  /* TMINUS  */
    TMOD = 417,                    /* TMOD  */
    TNOTEQUAL = 418,               /* TNOTEQUAL  */
    TOR = 419,                     /* TOR  */
    TPLUS = 420,                   /* TPLUS  */
    TQUESTION = 421,               /* TQUESTION  */
    TSEMI = 422,                   /* TSEMI  */
    TSHIFTLEFT = 423,              /* TSHIFTLEFT  */
    TSHIFTRIGHT = 424,             /* TSHIFTRIGHT  */
    TSTAR = 425,                   /* TSTAR  */
    TSWAP = 426,                   /* TSWAP  */
    TLCBR = 427,                   /* TLCBR  */
    TRCBR = 428,                   /* TRCBR  */
    TLP = 429,                     /* TLP  */
    TRP = 430,                     /* TRP  */
    TLSBR = 431,                   /* TLSBR  */
    TRSBR = 432,                   /* TRSBR  */
    TNOELSE = 433,                 /* TNOELSE  */
    TDOTDOTOPENHIGH = 434,         /* TDOTDOTOPENHIGH  */
    TUPLUS = 435,                  /* TUPLUS  */
    TUMINUS = 436,                 /* TUMINUS  */
    TLNOT = 437                    /* TLNOT  */
  };
  typedef enum yychpl_tokentype yychpl_token_kind_t;
#endif

/* Value type.  */

/* Location type.  */
#if ! defined YYCHPL_LTYPE && ! defined YYCHPL_LTYPE_IS_DECLARED
typedef struct YYCHPL_LTYPE YYCHPL_LTYPE;
struct YYCHPL_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYCHPL_LTYPE_IS_DECLARED 1
# define YYCHPL_LTYPE_IS_TRIVIAL 1
#endif




#ifndef YYPUSH_MORE_DEFINED
# define YYPUSH_MORE_DEFINED
enum { YYPUSH_MORE = 4 };
#endif

typedef struct yychpl_pstate yychpl_pstate;


int yychpl_push_parse (yychpl_pstate *ps,
                  int pushed_char, YYCHPL_STYPE const *pushed_val, YYCHPL_LTYPE *pushed_loc, ParserContext* context);

yychpl_pstate *yychpl_pstate_new (void);
void yychpl_pstate_delete (yychpl_pstate *ps);

/* "%code provides" blocks.  */
#line 309 "chpl.ypp"

  extern int yychpl_debug;

  void yychpl_error(YYLTYPE*       loc,
                    ParserContext* context,
                    const char*    errorMessage);
#line 317 "chpl.ypp"

  // include ParserContext.h here because it depends
  // upon YYLTYPE and other types defined by the generated parser
  // headers.
  #include "ParserContext.h"
  // include override of macro used to compute locations
  #include "parser-yylloc-default.h"

#line 519 "bison-chpl-lib.h"

#endif /* !YY_YYCHPL_BISON_CHPL_LIB_H_INCLUDED  */
