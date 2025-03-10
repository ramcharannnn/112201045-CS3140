/* compiler.l */
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	#include "header.h"

	extern YYSTYPE yylval;
	extern int lineno;
%}

digit   [0-9]
letter  [a-zA-Z]

%%
begin					{ printf("Lexer: Found 'begin', returning BEG\n"); return BEG;}
enddecl                 { return ENDDECL; }
integer                 { return T_INT; }
print                   { return PRINT; }
write                   { return WRITE; }
begindecl   			{ return DECL; }
end						{return END;}
if                      { return IF; }
then                    { return THEN; }
else                    { return ELSE; }
endif                   { return ENDIF; }
do						{return DO;}
while					{return WHILE;}
endwhile				{return ENDWHILE;}
for                     { return FOR; }
break                   { return BREAK; }
"=="                    { return EQUALEQUAL; }
"<="                    { return LESSTHANOREQUAL; }
">="                    { return GREATERTHANOREQUAL; }
"!="                    { return NOTEQUAL; }
{digit}+                { yylval.num = atoi(yytext); return NUM; }

{letter}({letter}|{digit})*   { yylval.var = strdup(yytext); return VAR; }
[-+*/=()><;,\{\}\[\]\%]         { return yytext[0]; }
[ \t]                   ;
[\n]                    { lineno++; }
.                       { fprintf(stderr, "Error: Illegal character '%s' on line %d\n", yytext, lineno); }

%%

int yywrap(void) {
	int token = yylex();
    printf("Token: %d\n", token);

    return 1;
}

