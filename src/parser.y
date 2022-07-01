
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string>
    #include "astnode.h"

    extern FILE *yyin;
    extern FILE *yyout;
    extern int lineno;
    extern int yylex();
    void yyerror (char const*);

    fx::AstNode* Program;

%}


%union {
    std::string *str;
    fx::AstNode *node;
    fx::AstNodePtr *node_ptr;
    fx::Decls *decls;
    fx::Exprs *exprs;
    fx::NodeVec *args;
    fx::Args *params;
    fx::FuncDecl *func;
    fx::Val *val;
    fx::Call *call;
    fx::BinaryOperator *binaryop;
}

%token STR IF ELSE WHILE FOR CONTINUE BREAK VOID RETURN INT FLOAT COLON
%token ADDOP MINUSOP MULOP DIVOP INCR OROP ANDOP NOTOP EQUOP RELOP
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI DOT COMMA ASSIGN REFER
%token <str> IDENT ICONST FCONST CCONST STRING
%token <str> FN

%type <str> var_type primitive_type INT FLOAT STR
%type <decls> program decls
%type <exprs> stmts stmts_block
%type <node> var_decl expr op unary_expr func_call expr_stmt
%type <func> func_decl
%type <node> stmt return_stmt for_stmt
%type <args> def_args
%type <params> call_args
%type <val> op_val primitive_val

%start program

/* grammar rules */

%%

program: decls { Program = $1; };

decls
    : decl
    {
        $$ = new fx::Decls();
        $$->append($<node>1);
    }
    | decls decl { $1->append($<node>2); }
    ;

decl: func_decl | var_decl ;

func_decl
     : FN IDENT LPAREN def_args RPAREN var_type stmts_block
     {
         $$ = new fx::FuncDecl($2, $6);
         $$->body = $7;
         $$->args = $4;
     }
     | FN IDENT LPAREN RPAREN var_type stmts_block
     {
         $$ = new fx::FuncDecl($2, $5); $$->body = $6;
     }
     ;

func_call
    : IDENT LPAREN call_args RPAREN
     {
         fx::Call *n = new fx::Call();
         n->args = $3;
         n->name = $1;
         $$ = n;
     }
     ;

stmts
    : stmt
    {
        $$ = new fx::Exprs();
        $$->push_back(fx::AstNodePtr($1));
    }
    | stmts stmt
    {
        $1->push_back(fx::AstNodePtr($2));
    }
    ;


stmt: var_decl | expr | return_stmt | for_stmt;

expr: op | func_call | unary_expr;

return_stmt
    : RETURN expr
    {
        fx::ReturnStmt *n = new fx::ReturnStmt($2->Type());
        n->stmt = fx::AstNodePtr($2);
        $$ = n;
    }
    ;

call_args
    : expr
    {
        $$ = new fx::Args();
        $$->push_back(fx::AstNodePtr($1));
    }
    | call_args COMMA expr
    {
        $1->push_back(fx::AstNodePtr($3));
    }
    ;


def_args
    : var_decl
        {
            $$ = new fx::NodeVec();
            $$->push_back(fx::AstNodePtr($1));
        }
    | def_args COMMA var_decl
        {
            $1->push_back(fx::AstNodePtr($3));
        }
    ;

unary_expr
    : op_val
       { $$ = dynamic_cast<fx::AstNode*>($1); }
    | unary_operator op_val
       { $$ = dynamic_cast<fx::AstNode*>($2); }
    ;


unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

op
    : op_val binary_op op_val
    {
        $$ = new fx::BinaryOperator($1, $3);
    };

op_val
      : IDENT { $$ = new fx::Val(fx::NodeKind::VarRef, $1); }
      | primitive_val { $$ = $1; };

binary_op: ADDOP | MINUSOP | MULOP | DIVOP;

stmts_block
      : LBRACE stmts RBRACE { $$ = $2; }
      | LBRACE RBRACE { $$ = new fx::Exprs(); }
      ;

var_decl: var_type IDENT { $$ = new fx::VarDecl($2, $1, nullptr); };

primitive_type: INT | FLOAT | STR;

var_type: primitive_type | IDENT;

primitive_val
         :ICONST
             { $$ = new fx::Val(fx::NodeKind::Constant, fx::TypeID::Int, $1); }
         | FCONST
             { $$ = new fx::Val(fx::NodeKind::Constant, fx::TypeID::Float, $1); }
         | STRING
             { $$ = new fx::Val(fx::NodeKind::Constant, fx::TypeID::Str, $1); }
         ;

for_stmt
    : FOR LPAREN expr_stmt expr_stmt RPAREN stmts_block
    {
        fx::ForStmt *n = new fx::ForStmt();
        n->cond_stmt = fx::AstNodePtr($3);
        n->next_stmt = fx::AstNodePtr($4);
        n->body = $6;
        $$ = n;
    }
    | FOR LPAREN expr_stmt expr_stmt expr_stmt RPAREN stmts_block
    {
        fx::ForStmt *n = new fx::ForStmt();
        n->init_stmt = fx::AstNodePtr($3);
        n->cond_stmt = fx::AstNodePtr($4);
        n->next_stmt = fx::AstNodePtr($5);
        n->body = $7;
        $$ = n;
    };

expr_stmt
    : SEMI
    {
        $$ = new fx::AstNode(fx::NodeKind::Nil);
    }
    | expr SEMI
    {
        $$ = $1;
    }
    ;


%%


void yyerror (char const* s)
{
	fflush(stdout);
	fprintf(stderr, "lineno:%d, *** %s\n", lineno, s);
    exit(-1);
}


