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
    CLASS = 262,
    FOR = 263,
    CONTINUE = 264,
    BREAK = 265,
    VOID = 266,
    RETURN = 267,
    INT = 268,
    LET = 269,
    FLOAT = 270,
    COLON = 271,
    INCR = 272,
    OROP = 273,
    ANDOP = 274,
    NOTOP = 275,
    RELOP = 276,
    LPAREN = 277,
    RPAREN = 278,
    LBRACK = 279,
    RBRACK = 280,
    LBRACE = 281,
    RBRACE = 282,
    SEMI = 283,
    DOT = 284,
    COMMA = 285,
    ASSIGN = 286,
    REFER = 287,
    IDENT = 288,
    ICONST = 289,
    FCONST = 290,
    CCONST = 291,
    STRING = 292,
    NEQOP = 293,
    GTOP = 294,
    GEOP = 295,
    LTOP = 296,
    LEOP = 297,
    EQOP = 298,
    ADDOP = 299,
    MINUSOP = 300,
    MULOP = 301,
    DIVOP = 302,
    FN = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "src/parser.y" /* yacc.c:1909  */

    std::string *str;
    fx::AstNode *node;
    fx::AstNodePtr *node_ptr;
    fx::Decls *decls;
    fx::Stmts *exprs;
    fx::NodeVec *args;
    fx::Args *params;
    fx::FuncDecl *func;
    fx::IfStmt *ifnode;
    fx::Val *val;
    fx::Call *call;
    fx::BinaryExpr *op;

#line 118 "/home/do/cspace/fx/src/parser.hh" /* yacc.c:1909  */
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

#endif /* !YY_YY_HOME_DO_CSPACE_FX_SRC_PARSER_HH_INCLUDED  */
