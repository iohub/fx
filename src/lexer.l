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

    #define TO_STR yylval.str = new std::string(yytext, yyleng)
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
<ML_COMMENT>"\n"		{ lineno += 1; }


"str"       	{ TO_STR; return STR; }
"int"			{ TO_STR; return INT; }
"float"			{ TO_STR; return FLOAT; }
"if"			{ return IF; }
"else"			{ return ELSE; }
"while"			{ return WHILE; }
"for"			{ return FOR; }
"continue"	    { return CONTINUE; }
"break"			{ return BREAK; }
"void"			{ return VOID; }
"def"			{ return FN; }
"return"		{ return RETURN; }


"+"					    { TO_STR; return ADDOP; }
"-"					    { TO_STR; return MINUSOP; }
"*"						{ TO_STR; return MULOP; }
"/"						{ TO_STR; return DIVOP; }
"++"|"--"				{ return INCR; }
"||"					{ return OROP; }
"&&"					{ return ANDOP; }
"!"						{ TO_STR; return NOTOP; }
"=="				    { TO_STR; return EQOP; }
"!="				    { TO_STR; return NEQOP; }
">"				        { TO_STR; return GTOP; }
">="				    { TO_STR; return GEOP; }
"<"				        { TO_STR; return LTOP; }
"<="				    { TO_STR; return LEOP; }


"("				{ return LPAREN; }
")"				{ return RPAREN; }
"]"				{ return LBRACK; }
"["				{ return RBRACK; }
"{"				{ return LBRACE; }
"}"				{ return RBRACE; }
";"				{ return SEMI; }
":"				{ return COLON; }
"."				{ return DOT; }
","				{ return COMMA; }
"="				{ return ASSIGN; }
"&"				{ return REFER; }


{IDENT} 		{ TO_STR; return IDENT; }

{ICONST} 		{ TO_STR; return ICONST; }
{FCONST} 		{ TO_STR; return FCONST; }
{CCONST} 		{ return CCONST; }
{STRING} 		{ TO_STR; return STRING; }


"\n"			{ lineno += 1; }
[ \t\r\f]+      { }

.				{ yyerror("Unrecognized character"); }

%%




