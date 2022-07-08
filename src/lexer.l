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
	int lineno = 1;
    void yyerror (char const*);
    extern YYLTYPE yylloc;

    #define Text yylval.str = new std::string(yytext, yyleng)
    #define EatColumn yylloc.first_column = yylloc.last_column; yylloc.last_column += yyleng;
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


"str"       	{ EatColumn; Text; return STR; }
"int"			{ EatColumn; Text; return INT; }
"float"			{ EatColumn; Text; return FLOAT; }
"if"			{ EatColumn; return IF; }
"else"			{ EatColumn; return ELSE; }
"while"			{ EatColumn; return WHILE; }
"for"			{ EatColumn; return FOR; }
"continue"	    { EatColumn; return CONTINUE; }
"break"			{ EatColumn; return BREAK; }
"void"			{ EatColumn; return VOID; }
"def"			{ EatColumn; return FN; }
"return"		{ EatColumn; return RETURN; }


"+"					    { EatColumn; Text; return ADDOP; }
"-"					    { EatColumn; Text; return MINUSOP; }
"*"						{ EatColumn; Text; return MULOP; }
"/"						{ EatColumn; Text; return DIVOP; }
"++"|"--"				{ EatColumn; return INCR; }
"||"					{ EatColumn; return OROP; }
"&&"					{ EatColumn; return ANDOP; }
"!"						{ EatColumn; Text; return NOTOP; }
"=="				    { EatColumn; Text; return EQOP; }
"!="				    { EatColumn; Text; return NEQOP; }
">"				        { EatColumn; Text; return GTOP; }
">="				    { EatColumn; Text; return GEOP; }
"<"				        { EatColumn; Text; return LTOP; }
"<="				    { EatColumn; Text; return LEOP; }


"("				{ EatColumn; return LPAREN; }
")"				{ EatColumn; return RPAREN; }
"]"				{ EatColumn; return LBRACK; }
"["				{ EatColumn; return RBRACK; }
"{"				{ EatColumn; return LBRACE; }
"}"				{ EatColumn; return RBRACE; }
";"				{ EatColumn; return SEMI; }
":"				{ EatColumn; return COLON; }
"."				{ EatColumn; return DOT; }
","				{ EatColumn; return COMMA; }
"="				{ EatColumn; return ASSIGN; }
"&"				{ EatColumn; return REFER; }


{IDENT} 		{ EatColumn; Text; return IDENT; }
{ICONST} 		{ EatColumn; Text; return ICONST; }
{FCONST} 		{ EatColumn; Text; return FCONST; }
{CCONST} 		{ EatColumn; Text; return CCONST; }
{STRING} 		{ EatColumn; Text; return STRING; }


"\n"			{ yylloc.first_column = 0; yylloc.last_column = 0; ++yylloc.last_line; ++yylloc.first_line; }
[ \t\r\f]+      { yylloc.first_column = yylloc.last_column; ++yylloc.last_column; }



.				{ yyerror("Unrecognized character"); }



%%




