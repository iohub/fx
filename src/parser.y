
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
    using namespace fx;

    AstNode* Program;

%}


%union {
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
}

%token STR IF ELSE WHILE CLASS FOR CONTINUE BREAK VOID RETURN INT LET FLOAT COLON
%token INCR OROP ANDOP NOTOP RELOP
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI DOT COMMA ASSIGN REFER
%token <str> IDENT ICONST FCONST CCONST STRING
%token <str> NEQOP GTOP GEOP LTOP LEOP EQOP ADDOP MINUSOP MULOP DIVOP
%token <str> FN

%type <str> var_type primitive_type INT FLOAT STR VOID compare_operator binary_op
%type <decls> program decls
%type <exprs> stmts stmts_block
%type <node> var_decl expr op unary_expr func_call expr_stmt assignment_expr
%type <func> func_decl
%type <node> stmt return_stmt for_stmt boolean_stmt
%type <args> def_args
%type <params> call_args
%type <node> op_val primitive_val value_expr
%type <node> if_stmt
%locations

%start program

/* grammar rules */

%%

program: decls { Program = $1; };

decls
    : decl
    {
        $$ = new Decls(Loc(@1.first_line, @1.first_column));
        $$->append($<node>1);
    }
    | decls decl { $1->append($<node>2); }
    ;

decl: func_decl | var_decl ;

func_decl
     : FN IDENT LPAREN def_args RPAREN var_type stmts_block
     {
         $$ = new FuncDecl(Loc(@1.first_line, @1.first_column), *$2, *$6);
         $$->body_ = $7;
         $$->args_ = $4;
     }
     | FN IDENT LPAREN RPAREN var_type stmts_block
     {
         $$ = new FuncDecl(Loc(@1.first_line, @1.first_column), *$2, *$5); $$->body_ = $6;
     }
     ;

func_call
    : IDENT LPAREN call_args RPAREN
     {
         Call *n = new Call(Loc(@1.first_line, @1.first_column));
         n->args_ = $3;
         n->name_ = $1;
         $$ = n;
     }
     ;

stmts
    : stmt
    {
        $$ = new Stmts();
        $$->push_back(AstNodePtr($1));
    }
    | stmts stmt
    {
        $1->push_back(AstNodePtr($2));
    }
    ;


stmt: var_decl | expr | return_stmt | for_stmt | if_stmt | assignment_expr ;

expr: op | func_call | unary_expr | boolean_stmt;

return_stmt
    : RETURN expr
    {
        ReturnStmt *n = new ReturnStmt(Loc(@1.first_line, @1.first_column), $2->Type());
        n->stmt = AstNodePtr($2);
        $$ = n;
    }
    ;

call_args
    : expr
    {
        $$ = new Args();
        $$->push_back(AstNodePtr($1));
    }
    | call_args COMMA expr
    {
        $1->push_back(AstNodePtr($3));
    }
    ;


def_args
    : var_decl
        {
            $$ = new NodeVec();
            $$->push_back(AstNodePtr($1));
        }
    | def_args COMMA var_decl
        {
            $1->push_back(AstNodePtr($3));
        }
    ;

unary_expr
    : op_val
       { $$ = dynamic_cast<AstNode*>($1); }
    | unary_operator op_val
       { $$ = dynamic_cast<AstNode*>($2); }
    ;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

compare_operator
    : EQOP
    | GTOP
    | GEOP
    | LTOP
    | LEOP
    | NEQOP
    ;

op
    : op_val binary_op op_val
    {
        $$ = new BinaryExpr(Loc(@1.first_line, @1.first_column),
            Kind::BinaryOperator, TypeID::Nil, $2, $1, $3);
    };

op_val
      : IDENT { $$ = new Val(Loc(@1.first_line, @1.first_column), Kind::Value, $1); }
      | primitive_val { $$ = $1; }
      | func_call { $$ = $1; } ;

value_expr
    : op_val
    {
        $$ = $1;
    }
    | op
    {
        $$ = $1;
    }
    ;

binary_op: ADDOP | MINUSOP | MULOP | DIVOP;

stmts_block
      : LBRACE stmts RBRACE { $$ = $2; }
      | LBRACE RBRACE { $$ = new Stmts(); }
      ;

var_decl
    : var_type IDENT
    { $$ = new VarDecl(Loc(@1.first_line, @1.first_column), *$2, *$1); };

primitive_type: INT | FLOAT | STR;

var_type: primitive_type | IDENT;

primitive_val
         :ICONST
             { $$ = new Val(Loc(@1.first_line, @1.first_column), Kind::Constant, TypeID::Int, $1); }
         | FCONST
             { $$ = new Val(Loc(@1.first_line, @1.first_column), Kind::Constant, TypeID::Float, $1); }
         | STRING
             { $$ = new Val(Loc(@1.first_line, @1.first_column), Kind::Constant, TypeID::Str, $1); }
         ;

for_stmt
    : FOR LPAREN expr_stmt expr_stmt expr_stmt RPAREN stmts_block
    {
        ForStmt *n = new ForStmt(Loc(@1.first_line, @1.first_column));
        n->init_stmt = AstNodePtr($3);
        n->cond_stmt = AstNodePtr($4);
        n->next_stmt = AstNodePtr($5);
        n->body = $7;
        $$ = n;
    };

if_stmt
    : IF LPAREN boolean_stmt RPAREN stmts_block
    {
        IfStmt *n = new IfStmt(Loc(@1.first_line, @1.first_column), $3, $5, nullptr);
        $$ = n;
    }
    | IF LPAREN boolean_stmt RPAREN stmts_block ELSE stmts_block
    {
        IfStmt *n = new IfStmt(Loc(@1.first_line, @1.first_column), $3, $5, $7);
        $$ = n;
    }
    ;

boolean_stmt
    : op_val compare_operator op_val
    {
        $$ = new BinaryExpr(Loc(@1.first_line, @1.first_column),
            Kind::BinaryCmp, TypeID::Bool, $2, $1, $3);
    };


expr_stmt
    : SEMI
    {
        $$ = new AstNode(Loc(@1.first_line, @1.first_column), Kind::Nil);
    }
    | expr SEMI
    {
        $$ = $1;
    }
    ;

assignment_operator
    : ASSIGN

assignment_expr
    : IDENT assignment_operator value_expr
    {
        $$ = new AssignStmt(Loc(@1.first_line, @1.first_column),
            new Val(Loc(@1.first_line, @1.first_column), Kind::VarRef, $1), $3);
    }
    | LET IDENT assignment_operator value_expr
    {
        VarDecl *n = new VarDecl(Loc(@2.first_line, @2.first_column), *$2, $4->TyStr());
        $$ = new LetAssign(Loc(@1.first_line, @1.first_column), AstNodePtr(n), AstNodePtr($4));
    };



%%


void yyerror (char const* s)
{
	fflush(stdout);
	fprintf(stderr, "location(%d:%d), *** %s\n", yylloc.first_line, yylloc.first_column, s);
    exit(-1);
}


