grammar fx;

compilationUnit
    :   translationUnit? EOF
    ;

translationUnit
    :   externalDeclaration+
    ;

externalDeclaration
    :   functionDefinition
    ;

functionDefinition
    :   typeSpecifier Identifier '(' parameterList ')' compoundStatement
    ;

declarationSpecifiers
    :   declarationSpecifier+
    ;

declarationSpecifier
    : typeSpecifier
    ;

parameterList
    :   parameterDeclaration (',' parameterDeclaration)*
    ;

parameterDeclaration
    :   declarationSpecifiers Identifier
    ;

identifierList
    :   Identifier (',' Identifier)*
    ;

assignmentOperator
    :   '=' | '*=' | '/=' | '%=' | '+=' | '-=' | '<<=' | '>>=' | '&=' | '^=' | '|='
    ;

typeSpecifier
    :   ('void'
    |   'char'
    |   'int'
    |   'float'
    |   'str'
    |   'bool')
    ;

compoundStatement
    :   '{' blockItemList? '}'
    ;

blockItemList
    :   blockItem+
    ;

blockItem
    :   statement
    ;

statement
    :   expressionStatement
    ;

expressionStatement
    :   'if' '(' Identifier ')' Identifier ('else' Identifier )?
    ;

Break : 'break';
Case : 'case';
Char : 'char';
Const : 'const';
Continue : 'continue';
Default : 'default';
Do : 'do';
Else : 'else';
Enum : 'enum';
Float : 'float';
For : 'for';
If : 'if';
Inline : 'inline';
Int : 'int';
Return : 'return';
Struct : 'struct';
Switch : 'switch';
Void : 'void';
While : 'while';

Bool : 'bool';

LeftParen : '(';
RightParen : ')';
LeftBracket : '[';
RightBracket : ']';
LeftBrace : '{';
RightBrace : '}';

Less : '<';
LessEqual : '<=';
Greater : '>';
GreaterEqual : '>=';
LeftShift : '<<';
RightShift : '>>';

Plus : '+';
PlusPlus : '++';
Minus : '-';
MinusMinus : '--';
Star : '*';
Div : '/';
Mod : '%';

And : '&';
Or : '|';
AndAnd : '&&';
OrOr : '||';
Caret : '^';
Not : '!';
Tilde : '~';

Question : '?';
Colon : ':';
Semi : ';';
Comma : ',';

Assign : '=';
// '*=' | '/=' | '%=' | '+=' | '-=' | '<<=' | '>>=' | '&=' | '^=' | '|='
StarAssign : '*=';
DivAssign : '/=';
ModAssign : '%=';
PlusAssign : '+=';
MinusAssign : '-=';
LeftShiftAssign : '<<=';
RightShiftAssign : '>>=';
AndAssign : '&=';
XorAssign : '^=';
OrAssign : '|=';

Equal : '==';
NotEqual : '!=';

Arrow : '->';
Dot : '.';


Identifier
    :   IdentifierNondigit
        (   IdentifierNondigit
        |   Digit
        )*
    ;

Constant
    :   IntegerConstant
    |   FloatingConstant
    |   CharacterConstant
    ;

fragment
Nondigit
    :   [a-zA-Z_]
    ;

fragment
IdentifierNondigit
    :   Nondigit
    ;

fragment
Digit
    :   [0-9]
    ;

fragment
IntegerConstant
    :   DecimalConstant
    ;

fragment
DecimalConstant
    :   NonzeroDigit Digit*
    ;

fragment
NonzeroDigit
    :   [1-9]
    ;

fragment
FloatingConstant
    :   DecimalFloatingConstant
    ;

fragment
DecimalFloatingConstant
    :   FractionalConstant
    |   DigitSequence
    ;

DigitSequence
    :   Digit+
    ;

fragment
FractionalConstant
    :   DigitSequence? '.' DigitSequence
    |   DigitSequence '.'
    ;

fragment
CharacterConstant
    :   '\'' CCharSequence '\''
    |   'L\'' CCharSequence '\''
    |   'u\'' CCharSequence '\''
    |   'U\'' CCharSequence '\''
    ;

fragment
CCharSequence
    :   CChar+
    ;

fragment
CChar
    :   ~['\\\r\n]
    ;

Whitespace
    :   [ \t]+
        -> skip
    ;

Newline
    :   (   '\r' '\n'?
        |   '\n'
        )
        -> skip
    ;

BlockComment
    :   '/*' .*? '*/'
        -> skip
    ;

LineComment
    :   '//' ~[\r\n]*
        -> skip
    ;
