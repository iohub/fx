%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string>
	#include <string.h>
    #include "astnode.h"
	#include "parser.hh"

	extern FILE *yyin;
	extern FILE *yyout;
    void yyerror (char const*);
    extern YYLTYPE yylloc;

    #define Text do { yylval.str = new std::string(yytext, yyleng); } while(0);
    #define Eat do { yylloc.first_column = yylloc.last_column; yylloc.last_column += yyleng; } while(0);
%}


%x ML_COMMENT

alpha 		[a-zA-Z]
digit 		[0-9]
alnum 		{alpha}|{digit}
print		[ -~]

IDENT 		{alpha}+{alnum}*
ICONST		"0"|[0-9]{digit}*
FCONST		"0"|{digit}*"."{digit}+
CCONST		(\'{print}\')|(\'\\[nftrbv]\')
STRING		\"{print}*\"

%%

"//".*					{ }

"/*"					{ BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/" 		{ BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+
<ML_COMMENT>"*"
<ML_COMMENT>"\n"		{ ++yylloc.first_line; ++yylloc.last_line; }


"str"       	{ Eat; Text; return STR; }
"int"			{ Eat; Text; return INT; }
"float"			{ Eat; Text; return FLOAT; }
"if"			{ Eat; return IF; }
"else"			{ Eat; return ELSE; }
"while"			{ Eat; return WHILE; }
"for"			{ Eat; return FOR; }
"continue"	    { Eat; return CONTINUE; }
"break"			{ Eat; return BREAK; }
"void"			{ Eat; return VOID; }
"def"			{ Eat; return FN; }
"return"		{ Eat; return RETURN; }


"+"					    { Eat; Text; return ADDOP; }
"-"					    { Eat; Text; return MINUSOP; }
"*"						{ Eat; Text; return MULOP; }
"/"						{ Eat; Text; return DIVOP; }
"++"|"--"				{ Eat; return INCR; }
"||"					{ Eat; return OROP; }
"&&"					{ Eat; return ANDOP; }
"!"						{ Eat; Text; return NOTOP; }
"=="				    { Eat; Text; return EQOP; }
"!="				    { Eat; Text; return NEQOP; }
">"				        { Eat; Text; return GTOP; }
">="				    { Eat; Text; return GEOP; }
"<"				        { Eat; Text; return LTOP; }
"<="				    { Eat; Text; return LEOP; }


"("				{ Eat; return LPAREN; }
")"				{ Eat; return RPAREN; }
"]"				{ Eat; return LBRACK; }
"["				{ Eat; return RBRACK; }
"{"				{ Eat; return LBRACE; }
"}"				{ Eat; return RBRACE; }
";"				{ Eat; return SEMI; }
":"				{ Eat; return COLON; }
"."				{ Eat; return DOT; }
","				{ Eat; return COMMA; }
"="				{ Eat; return ASSIGN; }
"&"				{ Eat; return REFER; }


{IDENT} 		{ Eat; Text; return IDENT; }
{ICONST} 		{ Eat; Text; return ICONST; }
{FCONST} 		{ Eat; Text; return FCONST; }
{CCONST} 		{ Eat; Text; return CCONST; }
{STRING} 		{ Eat; Text; return STRING; }


"\n"			{ yylloc.first_column = 0; yylloc.last_column = 0; ++yylloc.last_line; ++yylloc.first_line; }
[ \t\r\f]+      { yylloc.first_column = yylloc.last_column; ++yylloc.last_column; }



.				{ yyerror("Unrecognized character"); }



%%




