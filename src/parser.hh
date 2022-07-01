/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_HOME_DO_CSPACE_FX_SRC_PARSER_HH_INCLUDED
# define YY_YY_HOME_DO_CSPACE_FX_SRC_PARSER_HH_INCLUDED
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
    STR = 258,
    IF = 259,
    ELSE = 260,
    WHILE = 261,
    FOR = 262,
    CONTINUE = 263,
    BREAK = 264,
    VOID = 265,
    RETURN = 266,
    INT = 267,
    FLOAT = 268,
    COLON = 269,
    ADDOP = 270,
    MINUSOP = 271,
    MULOP = 272,
    DIVOP = 273,
    INCR = 274,
    OROP = 275,
    ANDOP = 276,
    NOTOP = 277,
    EQUOP = 278,
    RELOP = 279,
    LPAREN = 280,
    RPAREN = 281,
    LBRACK = 282,
    RBRACK = 283,
    LBRACE = 284,
    RBRACE = 285,
    SEMI = 286,
    DOT = 287,
    COMMA = 288,
    ASSIGN = 289,
    REFER = 290,
    IDENT = 291,
    ICONST = 292,
    FCONST = 293,
    CCONST = 294,
    STRING = 295,
    FN = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "src/parser.y" /* yacc.c:1909  */

    std::string *str;
    fx::AstNode *node;
    fx::AstNodePtr *node_ptr;
    fx::Decls *defs;
    fx::Exprs *exprs;
    fx::NodeVec *args;
    fx::Args *params;
    fx::FuncDecl *func;
    fx::Val *val;
    fx::Call *call;
    fx::BinaryOperator *binaryop;

#line 110 "/home/do/cspace/fx/src/parser.hh" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_DO_CSPACE_FX_SRC_PARSER_HH_INCLUDED  */
