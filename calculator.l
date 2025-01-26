%{
#include "y.tab.h"
#include <stdlib.h> // For atoi
%}

%%

[A-Z]             { yylval.id = yytext[0]; return VARIABLE; } // Single character variable
[0-9]+            { yylval.num = atoi(yytext); return NUMBER; } // Integer number
"="               { return ASSIGN; } // Assignment operator
"*"               { return MULT; } // Multiplication operator
"/"               { return DIV; } // Division operator
"+"               { return ADD; } // Addition operator
"-"               { return MINUS; } // Subtraction operator
[ \t]+            { /* Ignore whitespace */ }
\n                { return EOL; } // End of line
.                 { return yytext[0]; } // Other characters

%%

int yywrap() {
    return 1;
}
