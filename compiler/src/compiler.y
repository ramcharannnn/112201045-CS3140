%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../include/header.h"

    int yylex();
    void yyerror(const char *s);
    int lineno = 1;

    SearchResult search(char* name);

    decl_node* newDeclNode(char* name);
    expr_node* opNode(exprtype type, expr_node* left, expr_node* right, op_type op, int conval, char *var_name);
    stmt_list* newStmt(stmt_type type, expr_node* expr1, expr_node* expr2);
    stmt_list* newEndDeclStmt();
    stmt_list* newDeclStmt(int ret_type, decl_node* node);

    void printAst(stmt_list* root, int indent);
    void printExpr(expr_node* root,int indent);
    int evalExpr(expr_node* root, int line_num);
    void evalProg(stmt_list *root);
    void printSymbolTableValues();

%}

%union {
    int num;
    char* var;
    struct expr_node* expr_ptr;
    struct decl_node* decl_node_ptr;
    struct stmt_list* stmt_list_ptr;
}

%token T_INT
%token PRINT
%token WRITE
%token DECL ENDDECL
%token <var> VAR
%token <num> NUM

%left '+' '-'
%left '*' '/'

%type <expr_ptr> expr var_expr
%type <stmt_list_ptr> Prog statement stmt_list assign_stmt write_stmt Gdecl_sec Gdecl_list Gdecl
%type <num> ret_type
%type <decl_node_ptr> Glist Gid

%%

Prog    :   Gdecl_sec  stmt_list {
                     $$ = $2 ;
                     printf("\nAST\n");
                         printf("-------------------\n");
                         printAst($$ , 0);
                     evalProg($$);
                     printf("\n\nSymbol Table Values\n");
                         printf("-------------------\n");
                         printSymbolTableValues();
                         freeStmtList($$); // Important: Free the allocated memory

                     }
    ;

Gdecl_sec:  DECL Gdecl_list ENDDECL{  $$ = $2 ;  }
    ;

Gdecl_list: /*  NULL */            {  $$ = NULL; }
    |   Gdecl Gdecl_list     {
                                    if ($1 != NULL) {
                                        stmt_list* current = $1;
                                        while (current->next != NULL) {
                                            current = current->next;
                                        }
                                        current->next = $2;
                                        $$ = $1;
                                    } else {
                                        $$ = $2;
                                    }
                                }
    ;

Gdecl   :   ret_type Glist ';'{ $$ = newDeclStmt($1 , $2); $$->line_num = lineno;
                                decl_node* current = $2;
                                    while(current != NULL){
                                        addToSymbolTable(current->name, VAR_SYM, INT_SYM);
                                        updateSymbolTable(current->name, 0);
                                        current = current->next;
                                    }
                                }
    ;

ret_type:   T_INT       { $$ = 0 ; }
    ;

Glist   :   Gid         { $$ = $1; }
    |   Gid ',' Glist     { $1->next = $3; $$ = $1 ; }
    ;

Gid :   VAR         { $$ = newDeclNode($1); }
    |   Gid '[' NUM ']'    { /* TODO: Array declaration */   yyerror("Arrays are not supported in this version"); $$ = NULL; }
    ;

stmt_list:   /* NULL */                { $$ = NULL; }
    |   statement stmt_list    {
                                    if($2 != NULL){
                                       $1 -> next = $2 ;
                                    } else{
                                        $1->next = NULL;
                                    }
                                    $$ = $1 ;
                                }
    ;

statement:  assign_stmt  ';'    {$$ = $1; }
    |   write_stmt ';'        {$$ = $1; }
    ;

	write_stmt:	WRITE '(' expr ')' 	{ $$ = newStmt(WRITE_STMT , $3 , NULL);    $$->line_num = lineno ;  }
		 

		;


assign_stmt:  var_expr '=' expr         { $$ = newStmt(ASSIGN , $1 , $3);    $$->line_num = lineno ;   }
    ;

expr    :   NUM                 { $$ = opNode(INTEGER , NULL , NULL , ADD , $1, NULL); }
    |   '-' NUM             { $$ = opNode(INTEGER , NULL , NULL , ADD , -1*$2, NULL); }
    |   var_expr            { $$ = $1; }
    |   '(' expr ')'            { $$ = $2; }
    |   expr '+' expr         { $$ = opNode(OP , $1 , $3 , ADD, 0, NULL); }
    |   expr '-' expr          { $$ = opNode(OP , $1 , $3 , SUB, 0, NULL); }
    |   expr '*' expr         { $$ = opNode(OP , $1 , $3 , MUL, 0, NULL); }
    |   expr '/' expr         { $$ = opNode(OP , $1 , $3 , DIV, 0, NULL); }
	

    ;

var_expr:   VAR { $$ = opNode(VARIABLE , NULL , NULL , ADD , 0 , $1); }
    |   var_expr '[' expr ']'    { yyerror("Arrays are not supported in this version"); $$ = NULL; }
    ;
%%
#include <stdio.h>
#include <ctype.h>
extern FILE* yyin;

void yyerror(const char *s){
    fprintf(stderr, "Error: %s on line %d\n", s, lineno);
    exit(1);
}
int main(int argc, char *argv[]) {
    initializeSymbolTable(); 
    if (argc != 2){
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }
    yyin = fopen(argv[1], "r");
    if (yyin == NULL){
        fprintf(stderr, "Failed to open input file '%s'\n", argv[1]);
        exit(1);
    }
    yyparse();
    fclose(yyin);
    return 0;
}
