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
    : ';'                                # Empty
    | block                              # BlockStmt
    | type_ item ( ',' item )* ';'       # Decl
    | expr '=' expr ';'                  # Ass
    | expr '++' ';'                      # Incr
    | expr '--' ';'                      # Decr
    | 'return' expr ';'                  # Ret
    | 'return' ';'                       # VRet
    | 'if' '(' expr ')' stmt             # Cond
    | 'if' '(' expr ')' stmt 'else' stmt # CondElse
    | 'while' '(' expr ')' stmt          # While
    | expr ';'                           # SExp
    ;

type_
    : 'int'     # Int
    | 'str'     # Str
    | 'bool'    # Bool
    | 'void'    # Void
    | ID        # ClassName
    ;

item
    : ID
    | ID '=' expr
    ;

expr
    : expr '(' ( expr ( ',' expr )* )? ')'  # EFunCall
    | expr '.' ID                           # EMemberExpr
    | ('-'|'!') expr                        # EUnOp
    | expr mulOp expr                       # EMulOp
    | expr addOp expr                       # EAddOp
    | expr relOp expr                       # ERelOp
    | <assoc=right> expr '&&' expr          # EAnd
    | <assoc=right> expr '||' expr          # EOr
    | 'new' type_                           # ENewExpr
    | ID                                    # EId
    | INT                                   # EInt
    | 'true'                                # ETrue
    | 'false'                               # EFalse
    | STR                                   # EStr
    | 'null'                                # ENull
    | '(' expr ')'                          # EParen
    | '(' type_ ')' expr                    # EClassCast
    ;


addOp
    : '+'
    | '-'
    ;

mulOp
    : '*'
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

