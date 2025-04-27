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

#line 140 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
