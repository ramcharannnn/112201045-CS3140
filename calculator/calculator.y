%{
#include <stdio.h>
#include <stdlib.h>

int symbol[26]; // For storing values of variables A-Z

int yylex(void); 
int yyerror(const char *s); 
%}

%union {
    int num;  
    char id;  
}

%token <num> NUMBER
%token <id> VARIABLE
%token ASSIGN ADD MINUS MULT DIV EOL

%type <num> expr statement

%left ADD MINUS
%left MULT DIV
%right ASSIGN

%%

prgm:
    prgm statement EOL { }
    |
    ;

statement:
    VARIABLE ASSIGN expr { 
        symbol[$1 - 'A'] = $3; 
        printf("%d\n", $3); 
    }
    | expr {
        printf("%d\n", $1);
    }
    ;

expr:
    expr ADD expr { $$ = $1 + $3; }
    | expr MINUS expr { $$ = $1 - $3; }
    | expr MULT expr { $$ = $1 * $3; }
    | expr DIV expr { 
        if ($3 == 0) {
            fprintf(stderr, "Error: Division by zero\n");
            exit(1);
        }
        $$ = $1 / $3; 
    }
    | NUMBER { $$ = $1; }
    | VARIABLE { $$ = symbol[$1 - 'A']; }
    ;

%%

int main() {
    printf("Enter expressions:\n");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}

