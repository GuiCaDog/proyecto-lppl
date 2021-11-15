/* A Bison parser, made by GNU Bison 3.8.1.  */

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

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
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
    INTEGER_ = 258,                /* INTEGER_  */
    BOOLEAN_ = 259,                /* BOOLEAN_  */
    STRUCT_ = 260,                 /* STRUCT_  */
    RETURN_ = 261,                 /* RETURN_  */
    READ_ = 262,                   /* READ_  */
    PRINT_ = 263,                  /* PRINT_  */
    IF_ = 264,                     /* IF_  */
    ELSE_ = 265,                   /* ELSE_  */
    WHILE_ = 266,                  /* WHILE_  */
    TRUE_ = 267,                   /* TRUE_  */
    FALSE_ = 268,                  /* FALSE_  */
    OPAREN_ = 269,                 /* OPAREN_  */
    CPAREN_ = 270,                 /* CPAREN_  */
    OBRACK_ = 271,                 /* OBRACK_  */
    CBRACK_ = 272,                 /* CBRACK_  */
    OBRACE_ = 273,                 /* OBRACE_  */
    CBRACE_ = 274,                 /* CBRACE_  */
    SEMIC_ = 275,                  /* SEMIC_  */
    AND_ = 276,                    /* AND_  */
    OR_ = 277,                     /* OR_  */
    EQ_ = 278,                     /* EQ_  */
    NEQ_ = 279,                    /* NEQ_  */
    GT_ = 280,                     /* GT_  */
    GTEQ_ = 281,                   /* GTEQ_  */
    LT_ = 282,                     /* LT_  */
    LTEQ_ = 283,                   /* LTEQ_  */
    PLUS_ = 284,                   /* PLUS_  */
    MINUS_ = 285,                  /* MINUS_  */
    MULT_ = 286,                   /* MULT_  */
    DIV_ = 287,                    /* DIV_  */
    EXCL_ = 288,                   /* EXCL_  */
    ASIG_ = 289,                   /* ASIG_  */
    COMMA_ = 290,                  /* COMMA_  */
    DOT_ = 291,                    /* DOT_  */
    ID_ = 292,                     /* ID_  */
    CTE_ = 293                     /* CTE_  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ASIN_H_INCLUDED  */
