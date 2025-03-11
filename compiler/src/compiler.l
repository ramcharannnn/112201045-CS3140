%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	#include "../include/header.h"

	extern YYSTYPE yylval;
	extern int lineno;
%}

digit   [0-9]
letter  [a-zA-Z]

%%

begindecl               { return DECL; }
enddecl                 { return ENDDECL; }
integer                 { return T_INT; }
print                   { return PRINT; }
write                   { return WRITE; } 

{digit}+                { yylval.num = atoi(yytext); return NUM; }

{letter}({letter}|{digit})*   { yylval.var = strdup(yytext); return VAR; }
[-+*/=()><;,\{\}\[\]\%]         { return yytext[0]; }
[ \t]                   ;
[\n]                    { lineno++; }
.                       { fprintf(stderr, "Error: Illegal character '%s' on line %d\n", yytext, lineno); }

%%

int yywrap() {
    return 1;
}
