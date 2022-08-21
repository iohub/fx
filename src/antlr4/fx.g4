grammar fx;

program
    : topDef+
    ;

topDef
    : funcDef
    | classDef
    ;

funcDef
    : type_ ID '(' arg? ')' block
    ;

classDef
    : 'class' ID ('extends' ID)? '{' classItem* '}'
    ;

classItem
    : type_ ID ';'                   # FieldDecl
    | type_ ID '(' arg? ')' block    # MethodDef
    ;

arg
    : varDef ( ',' varDef)*
    ;

varDef
    : type_ ID
    ;

block
    : '{' stmt* '}'
    ;

stmt
    : ';'
    | varAssignDef
    | assignStmt
    | returnStmt
    | ifStmt
    | forStmt
    | expr ';'
    ;

forStmt
    : 'for' '(' expr? ';' expr ';' expr? ')' block
    ;

varAssignDef
    : type_ ID ';'       # VarDecl
    | type_ ID '=' expr ';' # AgnDecl
    ;

assignStmt
    : expr '=' expr ';'                  # AgnStmt
    ;

returnStmt
    : 'return' expr ';'
    | 'return' ';'
    ;

ifStmt
    : 'if' '(' expr ')' block
    | 'if' '(' expr ')' block 'else' block
    ;


type_
    : 'int'     # Int
    | 'str'     # Str
    | 'bool'    # Bool
    | 'void'    # Void
    | ID        # ClassName
    ;

expr
    : expr binOp expr                  # BinOpExpr
    | expr relOp expr                  # RelOpExpr
    | <assoc=right> expr '&&' expr     # AndExpr
    | <assoc=right> expr '||' expr     # OrExpr
    | ID '(' paramList? ')'            # CallExpr
    | ID                               # IDExpr
    | constant                         # ConstExpr
    ;

paramList
    : expr (',' expr)*
    ;


boolean
    : 'true'
    | 'false'
    ;

constant
    : boolean    # ConstBool
    | INT        # ConstInt
    | STR        # ConstStr
    ;

binOp
    : '+'
    | '-'
    | '*'
    | '/'
    | '%'
    ;

relOp
    : '<'
    | '<='
    | '>'
    | '>='
    | '=='
    | '!='
    ;

COMMENT : ('#' ~[\r\n]* | '//' ~[\r\n]*) -> channel(HIDDEN);
MULTICOMMENT : '/*' .*? '*/' -> channel(HIDDEN);

fragment Letter  : Capital | Small ;
fragment Capital : [A-Z\u00C0-\u00D6\u00D8-\u00DE] ;
fragment Small   : [a-z\u00DF-\u00F6\u00F8-\u00FF] ;
fragment Digit : [0-9] ;

INT : Digit+ ;
fragment ID_First : Letter | '_';
ID : ID_First (ID_First | Digit)* ;

WS : (' ' | '\r' | '\t' | '\n')+ ->  skip;

STR
    :   '"' StringCharacters? '"'
    ;

fragment StringCharacters
    :   StringCharacter+
    ;

fragment
StringCharacter
    :   ~["\\]
    |   '\\' [tnr"\\]
    ;

