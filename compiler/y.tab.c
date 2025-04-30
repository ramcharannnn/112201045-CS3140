/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/compiler.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../include/header.h"

    int yylex();
    void yyerror(const char *s);
    int lineno = 1;

    SearchResult search(char* name);

    decl_node* newDeclNode(char* name, int array_size);
    beg_node* newBegNode(char* name, int array_size);
    expr_node* opNode(exprtype type, expr_node* left, expr_node* right, op_type op, int conval, char *var_name, expr_node* index);
    stmt_list* newStmt(stmt_type type, expr_node* expr1, expr_node* expr2, stmt_list* stmt_list1, stmt_list* stmt_list2);
    stmt_list* newCondStmt(cond_type type, stmt_list* startAssign, expr_node* condition, stmt_list* updateAssign, stmt_list* s1, stmt_list* s2);
    stmt_list* newEndDeclStmt();
    stmt_list* newEndStmt();
    stmt_list* newDeclStmt(int ret_type, decl_node* node);

    void printAst(stmt_list* root, int indent);
    void printExpr(expr_node* root, int indent);
    int evalExpr(expr_node* root, int line_num);
    void evalProg(stmt_list *root);
    void printSymbolTableValues();


#line 100 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    RETURN = 258,                  /* RETURN  */
    MAIN = 259,                    /* MAIN  */
    INC = 260,                     /* INC  */
    T_INT = 261,                   /* T_INT  */
    T_BOOL = 262,                  /* T_BOOL  */
    T_FLOAT = 263,                 /* T_FLOAT  */
    PRINT = 264,                   /* PRINT  */
    BEGINDECL = 265,               /* BEGINDECL  */
    READ = 266,                    /* READ  */
    WRITE = 267,                   /* WRITE  */
    BREAK = 268,                   /* BREAK  */
    IF = 269,                      /* IF  */
    THEN = 270,                    /* THEN  */
    ELSE = 271,                    /* ELSE  */
    ENDIF = 272,                   /* ENDIF  */
    FOR = 273,                     /* FOR  */
    BEG = 274,                     /* BEG  */
    END = 275,                     /* END  */
    ENDWHILE = 276,                /* ENDWHILE  */
    DO = 277,                      /* DO  */
    WHILE = 278,                   /* WHILE  */
    DECL = 279,                    /* DECL  */
    ENDDECL = 280,                 /* ENDDECL  */
    EQUALEQUAL = 281,              /* EQUALEQUAL  */
    LESSTHANOREQUAL = 282,         /* LESSTHANOREQUAL  */
    GREATERTHANOREQUAL = 283,      /* GREATERTHANOREQUAL  */
    NOTEQUAL = 284,                /* NOTEQUAL  */
    VAR = 285,                     /* VAR  */
    NUM = 286,                     /* NUM  */
    FLOAT = 287                    /* FLOAT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define RETURN 258
#define MAIN 259
#define INC 260
#define T_INT 261
#define T_BOOL 262
#define T_FLOAT 263
#define PRINT 264
#define BEGINDECL 265
#define READ 266
#define WRITE 267
#define BREAK 268
#define IF 269
#define THEN 270
#define ELSE 271
#define ENDIF 272
#define FOR 273
#define BEG 274
#define END 275
#define ENDWHILE 276
#define DO 277
#define WHILE 278
#define DECL 279
#define ENDDECL 280
#define EQUALEQUAL 281
#define LESSTHANOREQUAL 282
#define GREATERTHANOREQUAL 283
#define NOTEQUAL 284
#define VAR 285
#define NUM 286
#define FLOAT 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "src/compiler.y"

    int num;
    float fnum;
    char* var;
    struct expr_node* expr_ptr;
    struct decl_node* decl_node_ptr;
    struct stmt_list* stmt_list_ptr;

#line 226 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RETURN = 3,                     /* RETURN  */
  YYSYMBOL_MAIN = 4,                       /* MAIN  */
  YYSYMBOL_INC = 5,                        /* INC  */
  YYSYMBOL_T_INT = 6,                      /* T_INT  */
  YYSYMBOL_T_BOOL = 7,                     /* T_BOOL  */
  YYSYMBOL_T_FLOAT = 8,                    /* T_FLOAT  */
  YYSYMBOL_PRINT = 9,                      /* PRINT  */
  YYSYMBOL_BEGINDECL = 10,                 /* BEGINDECL  */
  YYSYMBOL_READ = 11,                      /* READ  */
  YYSYMBOL_WRITE = 12,                     /* WRITE  */
  YYSYMBOL_BREAK = 13,                     /* BREAK  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_THEN = 15,                      /* THEN  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_ENDIF = 17,                     /* ENDIF  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_BEG = 19,                       /* BEG  */
  YYSYMBOL_END = 20,                       /* END  */
  YYSYMBOL_ENDWHILE = 21,                  /* ENDWHILE  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_DECL = 24,                      /* DECL  */
  YYSYMBOL_ENDDECL = 25,                   /* ENDDECL  */
  YYSYMBOL_EQUALEQUAL = 26,                /* EQUALEQUAL  */
  YYSYMBOL_LESSTHANOREQUAL = 27,           /* LESSTHANOREQUAL  */
  YYSYMBOL_GREATERTHANOREQUAL = 28,        /* GREATERTHANOREQUAL  */
  YYSYMBOL_NOTEQUAL = 29,                  /* NOTEQUAL  */
  YYSYMBOL_VAR = 30,                       /* VAR  */
  YYSYMBOL_NUM = 31,                       /* NUM  */
  YYSYMBOL_FLOAT = 32,                     /* FLOAT  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '>'  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* '['  */
  YYSYMBOL_42_ = 42,                       /* ']'  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* '='  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_Prog = 49,                      /* Prog  */
  YYSYMBOL_Gdecl_sec = 50,                 /* Gdecl_sec  */
  YYSYMBOL_Gdecl_list = 51,                /* Gdecl_list  */
  YYSYMBOL_Gdecl = 52,                     /* Gdecl  */
  YYSYMBOL_ret_type = 53,                  /* ret_type  */
  YYSYMBOL_Glist = 54,                     /* Glist  */
  YYSYMBOL_Gid = 55,                       /* Gid  */
  YYSYMBOL_MainBlock = 56,                 /* MainBlock  */
  YYSYMBOL_Ldecl_sec = 57,                 /* Ldecl_sec  */
  YYSYMBOL_Ldecl_list = 58,                /* Ldecl_list  */
  YYSYMBOL_Ldecl = 59,                     /* Ldecl  */
  YYSYMBOL_type = 60,                      /* type  */
  YYSYMBOL_Lid_list = 61,                  /* Lid_list  */
  YYSYMBOL_Lid = 62,                       /* Lid  */
  YYSYMBOL_stmt_list = 63,                 /* stmt_list  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_write_stmt = 65,                /* write_stmt  */
  YYSYMBOL_read_stmt = 66,                 /* read_stmt  */
  YYSYMBOL_exprList = 67,                  /* exprList  */
  YYSYMBOL_assign_stmt = 68,               /* assign_stmt  */
  YYSYMBOL_cond_stmt = 69,                 /* cond_stmt  */
  YYSYMBOL_init_assign = 70,               /* init_assign  */
  YYSYMBOL_update_assign = 71,             /* update_assign  */
  YYSYMBOL_expr = 72,                      /* expr  */
  YYSYMBOL_var_expr = 73                   /* var_expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   214

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,    37,    35,    40,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      33,    47,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    80,    89,    94,    95,    99,   100,   114,
     125,   126,   130,   131,   134,   135,   175,   191,   192,   195,
     196,   207,   210,   213,   214,   217,   218,   221,   222,   234,
     235,   236,   237,   238,   241,   243,   259,   260,   263,   266,
     267,   268,   269,   273,   274,   278,   279,   287,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   325,   326
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "RETURN", "MAIN",
  "INC", "T_INT", "T_BOOL", "T_FLOAT", "PRINT", "BEGINDECL", "READ",
  "WRITE", "BREAK", "IF", "THEN", "ELSE", "ENDIF", "FOR", "BEG", "END",
  "ENDWHILE", "DO", "WHILE", "DECL", "ENDDECL", "EQUALEQUAL",
  "LESSTHANOREQUAL", "GREATERTHANOREQUAL", "NOTEQUAL", "VAR", "NUM",
  "FLOAT", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "';'", "','", "'['",
  "']'", "'('", "')'", "'{'", "'}'", "'='", "$accept", "Prog", "Gdecl_sec",
  "Gdecl_list", "Gdecl", "ret_type", "Glist", "Gid", "MainBlock",
  "Ldecl_sec", "Ldecl_list", "Ldecl", "type", "Lid_list", "Lid",
  "stmt_list", "statement", "write_stmt", "read_stmt", "exprList",
  "assign_stmt", "cond_stmt", "init_assign", "update_assign", "expr",
  "var_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,   -43,   -43,    -2,    -2,    11,    -4,    12,   -43,     2,
      -2,   -10,     9,   -43,    14,    34,    -1,    54,    48,    10,
      43,   -43,   -43,    10,    20,    56,    57,   -43,   -22,    58,
     -43,   -43,    61,    65,    67,   -43,    54,    54,   -43,   -43,
     -43,    24,    54,    88,    64,    68,    89,    10,   -43,   -43,
     -43,   -43,    54,    54,    66,    80,   -43,   -10,    69,   131,
      74,   -43,   -43,    45,    10,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,   -43,    92,   -43,    73,   114,
     160,    99,    91,   -43,   -43,    54,   -43,   -43,    59,   164,
     164,   164,   164,    16,    16,    55,    55,   -43,   -43,    54,
     123,   -43,   129,   -43,   -43,    10,   -43,   146,   111,   149,
     142,   145,   133,    54,   -43,   151,   149,   140,    10,   -43,
     172,   -43,   134,   101,   -43,   -43,   150,   153,   163,   170,
     165,   161,   166,   176,   -43,   140,   162,   -43,    10,   -43,
     167,   -43,   -43,   168,   -43,   -43
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    10,    11,     7,     7,     0,    27,     0,     4,     0,
       7,     0,     0,     1,     0,     0,     0,     0,     0,    27,
       0,    64,     2,    27,     0,     0,     0,    32,     0,     0,
       6,     8,    14,     0,    12,     5,     0,     0,    33,    48,
      50,     0,     0,     0,    52,    44,     0,    27,    28,    30,
      31,    29,     0,     0,     0,     0,     9,     0,     0,    36,
       0,    49,    51,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,     0,     3,     0,     0,
      38,     0,     0,    13,    35,     0,    34,    53,     0,    58,
      59,    60,    61,    62,    63,    54,    55,    56,    57,     0,
       0,    65,    18,    15,    37,    27,    39,     0,     0,    19,
       0,     0,    47,     0,    22,     0,    19,     0,    27,    40,
      64,    45,     0,     0,    17,    20,    25,     0,    23,     0,
       0,     0,     0,     0,    21,     0,     0,    46,    27,    42,
       0,    24,    16,     0,    26,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   -43,    26,   -43,   210,   154,   -43,   -43,   -43,
      96,   -43,   -43,    78,   -43,   -18,   -43,   -43,   -43,   -35,
     -42,   -43,   -43,   -43,    -5,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     9,    10,    11,    33,    34,     8,   110,
     115,   116,   117,   127,   128,    22,    23,    24,    25,    58,
      26,    27,    76,   122,    59,    44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    46,    60,    75,     1,    48,     2,    14,    15,    16,
      17,    13,    43,    28,    18,    19,    29,    28,    20,    52,
      32,    14,    15,    16,    17,    53,    21,    30,    18,    78,
      12,     1,    20,     2,    35,     3,    31,    63,    38,    28,
      21,    28,    65,    66,    67,    68,    88,    79,    80,     4,
     104,    71,    72,    73,    74,    61,    62,    36,    28,    49,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
     121,    65,    66,    67,    68,   105,   106,    37,    69,    70,
      71,    72,    73,    74,    21,    39,    40,   111,    47,    87,
      41,    45,    73,    74,   107,    50,    51,    42,    21,    28,
     129,    54,    55,    64,    56,    52,    28,    57,   123,    77,
      81,    82,    28,    84,    65,    66,    67,    68,    86,   100,
     143,    69,    70,    71,    72,    73,    74,    65,    66,    67,
      68,    99,    28,   103,    69,    70,    71,    72,    73,    74,
      65,    66,    67,    68,   102,   132,   108,    69,    70,    71,
      72,    73,    74,   109,   113,   114,   101,    65,    66,    67,
      68,   118,   119,   120,    69,    70,    71,    72,    73,    74,
     126,    85,    65,    66,    67,    68,   124,   130,   131,    69,
      70,    71,    72,    73,    74,   112,    65,    66,    67,    68,
     136,   133,   134,    69,    70,    71,    72,    73,    74,    71,
      72,    73,    74,   135,   137,   139,   138,   140,   142,   144,
       7,    83,   125,   141,   145
};

static const yytype_uint8 yycheck[] =
{
       6,    19,    37,    45,     6,    23,     8,    11,    12,    13,
      14,     0,    17,    19,    18,    19,     4,    23,    22,    41,
      30,    11,    12,    13,    14,    47,    30,    25,    18,    47,
       4,     6,    22,     8,    25,    10,    10,    42,    39,    45,
      30,    47,    26,    27,    28,    29,    64,    52,    53,    24,
      85,    35,    36,    37,    38,    31,    32,    43,    64,    39,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     112,    26,    27,    28,    29,    16,    17,    43,    33,    34,
      35,    36,    37,    38,    30,    31,    32,   105,    45,    44,
      36,    43,    37,    38,    99,    39,    39,    43,    30,   105,
     118,    43,    41,    15,    39,    41,   112,    40,   113,    20,
      44,    31,   118,    44,    26,    27,    28,    29,    44,    46,
     138,    33,    34,    35,    36,    37,    38,    26,    27,    28,
      29,    39,   138,    42,    33,    34,    35,    36,    37,    38,
      26,    27,    28,    29,    45,    44,    23,    33,    34,    35,
      36,    37,    38,    24,    43,     6,    42,    26,    27,    28,
      29,    19,    17,    30,    33,    34,    35,    36,    37,    38,
      30,    40,    26,    27,    28,    29,    25,     5,    44,    33,
      34,    35,    36,    37,    38,    39,    26,    27,    28,    29,
      20,    41,    39,    33,    34,    35,    36,    37,    38,    35,
      36,    37,    38,    40,    39,    39,    45,    31,    46,    42,
       0,    57,   116,   135,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     8,    10,    24,    49,    50,    53,    56,    51,
      52,    53,    51,     0,    11,    12,    13,    14,    18,    19,
      22,    30,    63,    64,    65,    66,    68,    69,    73,     4,
      25,    51,    30,    54,    55,    25,    43,    43,    39,    31,
      32,    36,    43,    72,    73,    43,    63,    45,    63,    39,
      39,    39,    41,    47,    43,    41,    39,    40,    67,    72,
      67,    31,    32,    72,    15,    26,    27,    28,    29,    33,
      34,    35,    36,    37,    38,    68,    70,    20,    63,    72,
      72,    44,    31,    54,    44,    40,    44,    44,    63,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    39,
      46,    42,    45,    42,    67,    16,    17,    72,    23,    24,
      57,    63,    39,    43,     6,    58,    59,    60,    19,    17,
      30,    68,    71,    72,    25,    58,    30,    61,    62,    63,
       5,    44,    44,    41,    39,    40,    20,    39,    45,    39,
      31,    61,    46,    63,    42,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    51,    51,    52,
      53,    53,    54,    54,    55,    55,    56,    57,    57,    58,
      58,    59,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    64,    64,    65,    66,    67,    67,    68,    69,
      69,    69,    69,    70,    70,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     1,     3,     3,     0,     2,     3,
       1,     1,     1,     3,     1,     4,    10,     3,     0,     0,
       2,     3,     1,     1,     3,     1,     4,     0,     2,     2,
       2,     2,     1,     2,     4,     4,     1,     3,     3,     5,
       7,    11,     9,     1,     0,     1,     3,     0,     1,     2,
       1,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Prog: Gdecl_sec stmt_list  */
#line 69 "src/compiler.y"
                                 {
                     (yyval.stmt_list_ptr) = (yyvsp[0].stmt_list_ptr) ;
                     printf("\nAST\n");
                         printf("-------------------\n");
                         printAst((yyval.stmt_list_ptr) , 0);
                     evalProg((yyval.stmt_list_ptr));
                     printf("\n\nSymbol Table Values\n");
                         printf("-------------------\n");
                         printSymbolTableValues();
                          genProgCode((yyval.stmt_list_ptr));
                     }
#line 1393 "y.tab.c"
    break;

  case 3: /* Prog: Gdecl_sec BEG stmt_list END  */
#line 80 "src/compiler.y"
                                     { 
                     (yyval.stmt_list_ptr) = (yyvsp[-1].stmt_list_ptr); 
                     printf("\nAST\n");
                     printAst((yyval.stmt_list_ptr), 0); 
                     evalProg((yyval.stmt_list_ptr));
                     printf("\nSymbol Table Values\n");
                     printSymbolTableValues();
                     genProgCode((yyval.stmt_list_ptr));
                   }
#line 1407 "y.tab.c"
    break;

  case 4: /* Prog: MainBlock  */
#line 89 "src/compiler.y"
                      { (yyval.stmt_list_ptr) = (yyvsp[0].stmt_list_ptr);
        genProgCode((yyval.stmt_list_ptr)); }
#line 1414 "y.tab.c"
    break;

  case 5: /* Gdecl_sec: DECL Gdecl_list ENDDECL  */
#line 94 "src/compiler.y"
                                   {  (yyval.stmt_list_ptr) = (yyvsp[-1].stmt_list_ptr) ;  }
#line 1420 "y.tab.c"
    break;

  case 6: /* Gdecl_sec: BEGINDECL Gdecl_list ENDDECL  */
#line 95 "src/compiler.y"
                                  {   (yyval.stmt_list_ptr) = (yyvsp[-1].stmt_list_ptr);}
#line 1426 "y.tab.c"
    break;

  case 7: /* Gdecl_list: %empty  */
#line 99 "src/compiler.y"
                                   {  (yyval.stmt_list_ptr) = NULL; }
#line 1432 "y.tab.c"
    break;

  case 8: /* Gdecl_list: Gdecl Gdecl_list  */
#line 100 "src/compiler.y"
                             {
                                    if ((yyvsp[-1].stmt_list_ptr) != NULL) {
                                        stmt_list* current = (yyvsp[-1].stmt_list_ptr);
                                        while (current->next != NULL) {
                                            current = current->next;
                                        }
                                        current->next = (yyvsp[0].stmt_list_ptr);
                                        (yyval.stmt_list_ptr) = (yyvsp[-1].stmt_list_ptr);
                                    } else {
                                        (yyval.stmt_list_ptr) = (yyvsp[0].stmt_list_ptr);
                                    }
                                }
#line 1449 "y.tab.c"
    break;

  case 9: /* Gdecl: ret_type Glist ';'  */
#line 114 "src/compiler.y"
                              {
                (yyval.stmt_list_ptr) = newDeclarationStmt(DECL_STMT, (yyvsp[-2].num) , (yyvsp[-1].decl_node_ptr));  // Using DECL_STMT for declarations
                (yyval.stmt_list_ptr)->line_num = lineno;
                decl_node* current = (yyvsp[-1].decl_node_ptr);
                while(current != NULL){
                    addToSymbolTable(current->name, VAR_SYM, INT_SYM, current->array_size);
                    updateSymbolTable(current->name, 0);
                    current = current->next;
                }
            }
#line 1464 "y.tab.c"
    break;

  case 10: /* ret_type: T_INT  */
#line 125 "src/compiler.y"
                        { (yyval.num) = 0 ; }
#line 1470 "y.tab.c"
    break;

  case 11: /* ret_type: T_FLOAT  */
#line 126 "src/compiler.y"
                         { (yyval.num) = 1 ; }
#line 1476 "y.tab.c"
    break;

  case 12: /* Glist: Gid  */
#line 130 "src/compiler.y"
                        { (yyval.decl_node_ptr) = (yyvsp[0].decl_node_ptr); }
#line 1482 "y.tab.c"
    break;

  case 13: /* Glist: Gid ',' Glist  */
#line 131 "src/compiler.y"
                          { (yyvsp[-2].decl_node_ptr)->next = (yyvsp[0].decl_node_ptr); (yyval.decl_node_ptr) = (yyvsp[-2].decl_node_ptr) ; }
#line 1488 "y.tab.c"
    break;

  case 14: /* Gid: VAR  */
#line 134 "src/compiler.y"
                    { (yyval.decl_node_ptr) = newDeclNode((yyvsp[0].var), 0); }
#line 1494 "y.tab.c"
    break;

  case 15: /* Gid: VAR '[' NUM ']'  */
#line 135 "src/compiler.y"
                           { (yyval.decl_node_ptr) = newDeclNode((yyvsp[-3].var), (yyvsp[-1].num)); }
#line 1500 "y.tab.c"
    break;

  case 16: /* MainBlock: ret_type MAIN '(' ')' '{' Ldecl_sec BEG stmt_list END '}'  */
#line 175 "src/compiler.y"
                                                                     {
    (yyval.stmt_list_ptr) = (yyvsp[-4].stmt_list_ptr); 
    stmt_list* current = (yyval.stmt_list_ptr);
    if(current != NULL){
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = (yyvsp[-2].stmt_list_ptr);  //stmt_list
    } else{
        (yyval.stmt_list_ptr) = (yyvsp[-2].stmt_list_ptr);
    }
}
#line 1517 "y.tab.c"
    break;

  case 17: /* Ldecl_sec: DECL Ldecl_list ENDDECL  */
#line 191 "src/compiler.y"
                                        {(yyval.stmt_list_ptr) = (yyvsp[-1].stmt_list_ptr);}
#line 1523 "y.tab.c"
    break;

  case 18: /* Ldecl_sec: %empty  */
#line 192 "src/compiler.y"
                                                  { (yyval.stmt_list_ptr) = NULL; }
#line 1529 "y.tab.c"
    break;

  case 19: /* Ldecl_list: %empty  */
#line 195 "src/compiler.y"
                             { (yyval.stmt_list_ptr) = NULL; }
#line 1535 "y.tab.c"
    break;

  case 20: /* Ldecl_list: Ldecl Ldecl_list  */
#line 196 "src/compiler.y"
                           {
                if((yyvsp[-1].stmt_list_ptr) != NULL){
                    (yyvsp[-1].stmt_list_ptr)->next = (yyvsp[0].stmt_list_ptr);
                     (yyval.stmt_list_ptr) = (yyvsp[-1].stmt_list_ptr);
                } else{
                     (yyval.stmt_list_ptr) = (yyvsp[0].stmt_list_ptr);
                }

            }
#line 1549 "y.tab.c"
    break;

  case 21: /* Ldecl: type Lid_list ';'  */
#line 207 "src/compiler.y"
                                                { (yyval.stmt_list_ptr) = newDeclarationStmt(DECL_STMT, 0, (yyvsp[-1].decl_node_ptr)); }
#line 1555 "y.tab.c"
    break;

  case 22: /* type: T_INT  */
#line 210 "src/compiler.y"
                                        { }
#line 1561 "y.tab.c"
    break;

  case 23: /* Lid_list: Lid  */
#line 213 "src/compiler.y"
                                { (yyval.decl_node_ptr) = (yyvsp[0].decl_node_ptr); }
#line 1567 "y.tab.c"
    break;

  case 24: /* Lid_list: Lid ',' Lid_list  */
#line 214 "src/compiler.y"
                                                { (yyvsp[-2].decl_node_ptr)->next = (yyvsp[0].decl_node_ptr); (yyval.decl_node_ptr) = (yyvsp[-2].decl_node_ptr); }
#line 1573 "y.tab.c"
    break;

  case 25: /* Lid: VAR  */
#line 217 "src/compiler.y"
                                { (yyval.decl_node_ptr) = newDeclNode((yyvsp[0].var), 0); }
#line 1579 "y.tab.c"
    break;

  case 26: /* Lid: VAR '[' NUM ']'  */
#line 218 "src/compiler.y"
                                       { (yyval.decl_node_ptr) = newDeclNode((yyvsp[-3].var), (yyvsp[-1].num)); }
#line 1585 "y.tab.c"
    break;

  case 27: /* stmt_list: %empty  */
#line 221 "src/compiler.y"
                                       { (yyval.stmt_list_ptr) = NULL; }
#line 1591 "y.tab.c"
    break;

  case 28: /* stmt_list: statement stmt_list  */
#line 222 "src/compiler.y"
                               {
                                    if((yyvsp[-1].stmt_list_ptr) != NULL){
                                       (yyvsp[-1].stmt_list_ptr) -> next = (yyvsp[0].stmt_list_ptr) ;
                                        (yyval.stmt_list_ptr) = (yyvsp[-1].stmt_list_ptr) ;
                                    } else{
                                         (yyval.stmt_list_ptr) = (yyvsp[0].stmt_list_ptr) ;
                                    }

                                }
#line 1605 "y.tab.c"
    break;

  case 29: /* statement: assign_stmt ';'  */
#line 234 "src/compiler.y"
                                {(yyval.stmt_list_ptr) = (yyvsp[-1].stmt_list_ptr); }
#line 1611 "y.tab.c"
    break;

  case 30: /* statement: write_stmt ';'  */
#line 235 "src/compiler.y"
                              {(yyval.stmt_list_ptr) = (yyvsp[-1].stmt_list_ptr); }
#line 1617 "y.tab.c"
    break;

  case 31: /* statement: read_stmt ';'  */
#line 236 "src/compiler.y"
                             {(yyval.stmt_list_ptr) = (yyvsp[-1].stmt_list_ptr); }
#line 1623 "y.tab.c"
    break;

  case 32: /* statement: cond_stmt  */
#line 237 "src/compiler.y"
                              { (yyval.stmt_list_ptr) = (yyvsp[0].stmt_list_ptr); }
#line 1629 "y.tab.c"
    break;

  case 33: /* statement: BREAK ';'  */
#line 238 "src/compiler.y"
                                  { (yyval.stmt_list_ptr) = newStmt(BREAK_STMT, NULL, NULL, NULL, NULL); (yyval.stmt_list_ptr)->line_num = lineno; }
#line 1635 "y.tab.c"
    break;

  case 34: /* write_stmt: WRITE '(' exprList ')'  */
#line 241 "src/compiler.y"
                                  { (yyval.stmt_list_ptr) = newStmt(WRITE_STMT, (yyvsp[-1].expr_ptr), NULL, NULL, NULL); (yyval.stmt_list_ptr)->line_num = lineno; }
#line 1641 "y.tab.c"
    break;

  case 35: /* read_stmt: READ '(' exprList ')'  */
#line 243 "src/compiler.y"
                               {
    (yyval.stmt_list_ptr) = newStmt(READ_STMT, (yyvsp[-1].expr_ptr), NULL, NULL,NULL);
    (yyval.stmt_list_ptr)->line_num = lineno;

    // ADD THIS CHECK IMMEDIATELY AFTER READING 'len'
    ////if (strcmp(((expr_node *)$3)->name, "len") == 0) { // Assuming 'len' is the variable name
    //    $$->next = (stmt_list*)malloc(sizeof(stmt_list));
    //    if ($$->next == NULL) {
    //        yyerror("Memory allocation error");
    //    }
    //    $$->next->type = -1; //Just a flag
    //    $$->next->tree.root = NULL;
    //    $$->next->next = NULL;
    //}
}
#line 1661 "y.tab.c"
    break;

  case 36: /* exprList: expr  */
#line 259 "src/compiler.y"
                                 { (yyval.expr_ptr) = (yyvsp[0].expr_ptr); }
#line 1667 "y.tab.c"
    break;

  case 37: /* exprList: expr ',' exprList  */
#line 260 "src/compiler.y"
                               {  (yyval.expr_ptr) = opNode(OP, (yyvsp[-2].expr_ptr), (yyvsp[0].expr_ptr), LIST, 0, NULL, NULL); }
#line 1673 "y.tab.c"
    break;

  case 38: /* assign_stmt: var_expr '=' expr  */
#line 263 "src/compiler.y"
                                        { (yyval.stmt_list_ptr) = newStmt(ASSIGN , (yyvsp[-2].expr_ptr) , (yyvsp[0].expr_ptr), NULL, NULL);    (yyval.stmt_list_ptr)->line_num = lineno ;   }
#line 1679 "y.tab.c"
    break;

  case 39: /* cond_stmt: IF expr THEN stmt_list ENDIF  */
#line 266 "src/compiler.y"
                                                                { (yyval.stmt_list_ptr) = newCondStmt(IFCONDITION ,NULL, (yyvsp[-3].expr_ptr) ,NULL, (yyvsp[-1].stmt_list_ptr) , NULL);    	 }
#line 1685 "y.tab.c"
    break;

  case 40: /* cond_stmt: IF expr THEN stmt_list ELSE stmt_list ENDIF  */
#line 267 "src/compiler.y"
                                                                                { (yyval.stmt_list_ptr) = newCondStmt(IFELSECONDITION  ,NULL, (yyvsp[-5].expr_ptr) ,NULL, (yyvsp[-3].stmt_list_ptr) , (yyvsp[-1].stmt_list_ptr));  }
#line 1691 "y.tab.c"
    break;

  case 41: /* cond_stmt: FOR '(' init_assign ';' expr ';' update_assign ')' '{' stmt_list '}'  */
#line 268 "src/compiler.y"
                                                                                      {  (yyval.stmt_list_ptr) = newCondStmt(FORLOOPCONDITION,(yyvsp[-8].stmt_list_ptr),(yyvsp[-6].expr_ptr),(yyvsp[-4].stmt_list_ptr),(yyvsp[-1].stmt_list_ptr),NULL); }
#line 1697 "y.tab.c"
    break;

  case 42: /* cond_stmt: DO '{' stmt_list '}' WHILE '(' expr ')' ';'  */
#line 269 "src/compiler.y"
                                                      { (yyval.stmt_list_ptr) = newCondStmt(DOWHILECONDITION, NULL, (yyvsp[-2].expr_ptr), NULL, (yyvsp[-6].stmt_list_ptr), NULL); (yyval.stmt_list_ptr)->line_num = lineno; }
#line 1703 "y.tab.c"
    break;

  case 43: /* init_assign: assign_stmt  */
#line 273 "src/compiler.y"
                 { (yyval.stmt_list_ptr) = (yyvsp[0].stmt_list_ptr); }
#line 1709 "y.tab.c"
    break;

  case 44: /* init_assign: %empty  */
#line 274 "src/compiler.y"
                 { (yyval.stmt_list_ptr) = NULL; }
#line 1715 "y.tab.c"
    break;

  case 45: /* update_assign: assign_stmt  */
#line 278 "src/compiler.y"
                 { (yyval.stmt_list_ptr) = (yyvsp[0].stmt_list_ptr); }
#line 1721 "y.tab.c"
    break;

  case 46: /* update_assign: VAR INC ';'  */
#line 279 "src/compiler.y"
                                  {
          /* i++ → i = i + 1 */
          expr_node *var_n = opNode(VARIABLE, NULL, NULL, ADD, 0, (yyvsp[-2].var), NULL);
          expr_node *one_n = opNode(INTEGER,  NULL, NULL, ADD, 1, NULL, NULL);
          (yyval.stmt_list_ptr) = newStmt(ASSIGN, var_n, one_n, NULL, NULL);
          (yyval.stmt_list_ptr)->line_num = lineno;
      }
#line 1733 "y.tab.c"
    break;

  case 47: /* update_assign: %empty  */
#line 287 "src/compiler.y"
                 { (yyval.stmt_list_ptr) = NULL; }
#line 1739 "y.tab.c"
    break;

  case 48: /* expr: NUM  */
#line 306 "src/compiler.y"
                                { (yyval.expr_ptr) = opNode(INTEGER , NULL , NULL , ADD , (yyvsp[0].num), NULL, NULL); }
#line 1745 "y.tab.c"
    break;

  case 49: /* expr: '-' NUM  */
#line 307 "src/compiler.y"
                            { (yyval.expr_ptr) = opNode(INTEGER , NULL , NULL , ADD , -1*(yyvsp[0].num), NULL, NULL); }
#line 1751 "y.tab.c"
    break;

  case 50: /* expr: FLOAT  */
#line 308 "src/compiler.y"
                            { (yyval.expr_ptr) = opNode(FLOAT_NUM , NULL , NULL , ADD , (yyvsp[0].fnum), NULL, NULL);  }
#line 1757 "y.tab.c"
    break;

  case 51: /* expr: '-' FLOAT  */
#line 309 "src/compiler.y"
                            { (yyval.expr_ptr) = opNode(FLOAT_NUM , NULL , NULL , ADD , -1*(yyvsp[0].fnum), NULL, NULL);  }
#line 1763 "y.tab.c"
    break;

  case 52: /* expr: var_expr  */
#line 310 "src/compiler.y"
                            { (yyval.expr_ptr) = (yyvsp[0].expr_ptr); }
#line 1769 "y.tab.c"
    break;

  case 53: /* expr: '(' expr ')'  */
#line 311 "src/compiler.y"
                                { (yyval.expr_ptr) = (yyvsp[-1].expr_ptr); }
#line 1775 "y.tab.c"
    break;

  case 54: /* expr: expr '+' expr  */
#line 312 "src/compiler.y"
                              { (yyval.expr_ptr) = opNode(OP , (yyvsp[-2].expr_ptr) , (yyvsp[0].expr_ptr) , ADD, 0, NULL, NULL); }
#line 1781 "y.tab.c"
    break;

  case 55: /* expr: expr '-' expr  */
#line 313 "src/compiler.y"
                               { (yyval.expr_ptr) = opNode(OP , (yyvsp[-2].expr_ptr) , (yyvsp[0].expr_ptr) , SUB, 0, NULL, NULL); }
#line 1787 "y.tab.c"
    break;

  case 56: /* expr: expr '*' expr  */
#line 314 "src/compiler.y"
                              { (yyval.expr_ptr) = opNode(OP , (yyvsp[-2].expr_ptr) , (yyvsp[0].expr_ptr) , MUL, 0, NULL, NULL); }
#line 1793 "y.tab.c"
    break;

  case 57: /* expr: expr '/' expr  */
#line 315 "src/compiler.y"
                              { (yyval.expr_ptr) = opNode(OP , (yyvsp[-2].expr_ptr) , (yyvsp[0].expr_ptr) , DIV, 0, NULL, NULL); }
#line 1799 "y.tab.c"
    break;

  case 58: /* expr: expr EQUALEQUAL expr  */
#line 316 "src/compiler.y"
                             { (yyval.expr_ptr) = opNode(OP, (yyvsp[-2].expr_ptr), (yyvsp[0].expr_ptr), EQUAL, 0, NULL, NULL); }
#line 1805 "y.tab.c"
    break;

  case 59: /* expr: expr LESSTHANOREQUAL expr  */
#line 317 "src/compiler.y"
                                  { (yyval.expr_ptr) = opNode(OP, (yyvsp[-2].expr_ptr), (yyvsp[0].expr_ptr), LESSEQUAL, 0, NULL, NULL); }
#line 1811 "y.tab.c"
    break;

  case 60: /* expr: expr GREATERTHANOREQUAL expr  */
#line 318 "src/compiler.y"
                                     { (yyval.expr_ptr) = opNode(OP, (yyvsp[-2].expr_ptr), (yyvsp[0].expr_ptr), GREATEREQUAL, 0, NULL, NULL); }
#line 1817 "y.tab.c"
    break;

  case 61: /* expr: expr NOTEQUAL expr  */
#line 319 "src/compiler.y"
                           { (yyval.expr_ptr) = opNode(OP, (yyvsp[-2].expr_ptr), (yyvsp[0].expr_ptr), NOTEQUALS, 0, NULL, NULL); }
#line 1823 "y.tab.c"
    break;

  case 62: /* expr: expr '<' expr  */
#line 320 "src/compiler.y"
                      { (yyval.expr_ptr) = opNode(OP, (yyvsp[-2].expr_ptr), (yyvsp[0].expr_ptr), LESS, 0, NULL, NULL); }
#line 1829 "y.tab.c"
    break;

  case 63: /* expr: expr '>' expr  */
#line 321 "src/compiler.y"
                      { (yyval.expr_ptr) = opNode(OP, (yyvsp[-2].expr_ptr), (yyvsp[0].expr_ptr), GREATER, 0, NULL, NULL); }
#line 1835 "y.tab.c"
    break;

  case 64: /* var_expr: VAR  */
#line 325 "src/compiler.y"
                { (yyval.expr_ptr) = opNode(VARIABLE , NULL , NULL , ADD , 0 , (yyvsp[0].var), NULL); }
#line 1841 "y.tab.c"
    break;

  case 65: /* var_expr: var_expr '[' expr ']'  */
#line 326 "src/compiler.y"
                              { (yyval.expr_ptr) = opNode(VARIABLE, NULL, NULL, ADD, 0, ((expr_node *)(yyvsp[-3].expr_ptr))->name, (yyvsp[-1].expr_ptr)); }
#line 1847 "y.tab.c"
    break;


#line 1851 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
                      yytoken, &yylval);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 329 "src/compiler.y"

#include <stdio.h>
#include <ctype.h>
extern FILE* yyin;

void yyerror(const char *s){
    fprintf(stderr, "Error: %s on line %d\n", s, lineno);
    exit(1);
}
int main(int argc, char *argv[]) {
    initializeSymbolTable();
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }
    
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        fprintf(stderr, "Failed to open input file '%s'\n", argv[1]);
        exit(1);
    }
    
    // Initialize assembly file
    initAssemblyFile(argv[1]);
    
    // Parse input
    yyparse();
    
    // Generate code and finalize assembly file
    finalizeAssemblyFile();
    
    fclose(yyin);
    return 0;
}
