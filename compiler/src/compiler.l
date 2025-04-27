/* compiler.l */
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
begin					{ return BEG; }
begindecl				{ return BEGINDECL;}
enddecl                 { return ENDDECL; }
integer                 { return T_INT; }
float                   {return T_FLOAT;}
print                   { return PRINT; }
write                   { return WRITE; }
read                    {return READ;}
decl   					{ return DECL; }
end						{ return END;}
if                      { return IF; }
then                    { return THEN; }
else                    { return ELSE; }
endif                   { return ENDIF; }
do						{ return DO;}
while					{ return WHILE;}
endwhile				{ return ENDWHILE;}
for                     { return FOR; }
break                   { return BREAK; }
"=="                    { return EQUALEQUAL; }
"<="                    { return LESSTHANOREQUAL; }
">="                    { return GREATERTHANOREQUAL; }
"!="                    { return NOTEQUAL; }
"++"   					{ return INC; } 
{digit}+                { yylval.num = atoi(yytext); return NUM; }
[0-9]+"."[0-9]+     	{ yylval.fnum = atof(yytext); return FLOAT; }
<<EOF>> { return 0; }

{letter}({letter}|{digit})*   { yylval.var = strdup(yytext); return VAR; }
[-+*/=()><;,\{\}\[\]\%]         { return yytext[0]; }
[ \t]                   ;
[\n]                    { lineno++; }
"//".*                  ;   // Skip comments
.                       { fprintf(stderr, "Error: Illegal character '%s' on line %d\n", yytext, lineno); }

%%

int yywrap(void) {
    return 1;
}

