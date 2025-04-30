%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../include/header.h"

    int yylex();
    void yyerror(const char *s);
    int lineno = 1;

    SearchResult search(char* name);

    decl_node* newDeclNode(char* name, int array_size);
    beg_node* newBegNode(char* name, int array_size);
    expr_node* opNode(exprtype type, expr_node* left, expr_node* right, op_type op, int conval, char *var_name, expr_node* index);
    stmt_list* newStmt(stmt_type type, expr_node* expr1, expr_node* expr2, stmt_list* stmt_list1, stmt_list* stmt_list2);
    stmt_list* newCondStmt(cond_type type, stmt_list* startAssign, expr_node* condition, stmt_list* updateAssign, stmt_list* s1, stmt_list* s2);
    stmt_list* newEndDeclStmt();
    stmt_list* newEndStmt();
    stmt_list* newDeclStmt(int ret_type, decl_node* node);

    void printAst(stmt_list* root, int indent);
    void printExpr(expr_node* root, int indent);
    int evalExpr(expr_node* root, int line_num);
    void evalProg(stmt_list *root);
    void printSymbolTableValues();

%}

%union {
    int num;
    float fnum;
    char* var;
    struct expr_node* expr_ptr;
    struct decl_node* decl_node_ptr;
    struct stmt_list* stmt_list_ptr;
}
%token RETURN MAIN
%token INC
%token T_INT T_BOOL T_FLOAT
%token PRINT
%token BEGINDECL
%token READ WRITE BREAK
%token IF THEN ELSE ENDIF
%token FOR 
%token BEG  END  ENDWHILE 
%token DO WHILE
%token DECL ENDDECL
%token EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%token <var> VAR
%token <num> NUM
%token <fnum> FLOAT


%right INC  
%left '<' '>'
%left EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%left '+' '-'
%left '*' '/'

%type <expr_ptr> expr var_expr exprList 
%type <stmt_list_ptr> Prog statement stmt_list assign_stmt write_stmt read_stmt cond_stmt Gdecl_sec Gdecl_list Gdecl MainBlock Ldecl_sec Ldecl_list Ldecl init_assign update_assign
%type <num> ret_type type
%type <decl_node_ptr> Glist Gid Lid Lid_list

//%type <stmt_list_ptr>  
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
                          genProgCode($$);
                     }
        |Gdecl_sec BEG stmt_list END { 
                     $$ = $3; 
                     printf("\nAST\n");
                     printAst($$, 0); 
                     evalProg($$);
                     printf("\nSymbol Table Values\n");
                     printSymbolTableValues();
                     genProgCode($$);
                   }
        |   MainBlock { $$ = $1;
        genProgCode($$); }

        ;

Gdecl_sec:  DECL Gdecl_list ENDDECL{  $$ = $2 ;  }
    | BEGINDECL Gdecl_list ENDDECL{   $$ = $2;}
   // |BEG Gdecl_list END {  $$ = $2;}
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

Gdecl   :   ret_type Glist ';'{
                $$ = newDeclarationStmt(DECL_STMT, $1 , $2);  // Using DECL_STMT for declarations
                $$->line_num = lineno;
                decl_node* current = $2;
                while(current != NULL){
                    addToSymbolTable(current->name, VAR_SYM, INT_SYM, current->array_size);
                    updateSymbolTable(current->name, 0);
                    current = current->next;
                }
            }
    ;
ret_type:   T_INT       { $$ = 0 ; }
        |   T_FLOAT      { $$ = 1 ; }

    ;

Glist   :   Gid         { $$ = $1; }
    |   Gid ',' Glist     { $1->next = $3; $$ = $1 ; }
    ;

Gid :   VAR         { $$ = newDeclNode($1, 0); }
    |   VAR '[' NUM ']'    { $$ = newDeclNode($1, $3); }
    ;

/*func 	:	VAR '(' arg_list ')' {opNode(VARIABLE, NULL, NULL, ADD, 0, $1, NULL);}
			
arg_list:	
		|	arg_list1
		;
		
arg_list1:	arg_list1 ';' arg
		|	arg
		;
		
arg 	:	arg_type var_list	
		;
		
arg_type:	T_INT		 {  }
		;

var_list:	VAR 		 { }
		|	VAR ',' var_list { 	}
		;
		
Fdef_sec:	
		;
		
Fdef	:	func_ret_type func_name '(' FargList ')' '{' Ldecl_sec BEG stmt_list ret_stmt END '}'	{	 				}
		;
func_ret_type:	T_INT		{ }
		;
			
func_name:	VAR		{ 					}
		;
		
FargList:	arg_list	{ 					}
		;


ret_stmt: RETURN expr ';' {  };
			*/
MainBlock: ret_type MAIN '(' ')' '{' Ldecl_sec BEG stmt_list END '}' {
    $$ = $6; 
    stmt_list* current = $$;
    if(current != NULL){
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = $8;  //stmt_list
    } else{
        $$ = $8;
    }
}
		;
/*main	:	MAIN	{$$ = strdup("main"); }
		;*/

Ldecl_sec:	DECL Ldecl_list ENDDECL	{$$ = $2;}
        |   /* Empty local declaration section */ { $$ = NULL; }
		;

Ldecl_list: /* Empty list */ { $$ = NULL; }
        | Ldecl Ldecl_list {
                if($1 != NULL){
                    $1->next = $2;
                     $$ = $1;
                } else{
                     $$ = $2;
                }

            }
		;

Ldecl	:	type Lid_list ';'		{ $$ = newDeclarationStmt(DECL_STMT, 0, $2); }
		;

type	:	T_INT			{ }
		;

Lid_list:	Lid		{ $$ = $1; }
		|	Lid ',' Lid_list	{ $1->next = $3; $$ = $1; }
		;

Lid	:	VAR		{ $$ = newDeclNode($1, 0); }
		|   VAR '[' NUM ']'    { $$ = newDeclNode($1, $3); }
		;

stmt_list:   /* NULL */                { $$ = NULL; }
    |   statement stmt_list    {
                                    if($1 != NULL){
                                       $1 -> next = $2 ;
                                        $$ = $1 ;
                                    } else{
                                         $$ = $2 ;
                                    }

                                }
    //|func_stmt stmt_list{ $$ = $1 ;}
    ;

statement:  assign_stmt  ';'    {$$ = $1; }
    |   write_stmt ';'        {$$ = $1; }
    |   read_stmt ';'        {$$ = $1; }
    |   cond_stmt             { $$ = $1; }
    |    BREAK ';'                { $$ = newStmt(BREAK_STMT, NULL, NULL, NULL, NULL); $$->line_num = lineno; }
    ;
//
write_stmt: WRITE '(' exprList')' { $$ = newStmt(WRITE_STMT, $3, NULL, NULL, NULL); $$->line_num = lineno; }
    ;
read_stmt: READ '('exprList')' {
    $$ = newStmt(READ_STMT, $3, NULL, NULL,NULL);
    $$->line_num = lineno;

    // ADD THIS CHECK IMMEDIATELY AFTER READING 'len'
    ////if (strcmp(((expr_node *)$3)->name, "len") == 0) { // Assuming 'len' is the variable name
    //    $$->next = (stmt_list*)malloc(sizeof(stmt_list));
    //    if ($$->next == NULL) {
    //        yyerror("Memory allocation error");
    //    }
    //    $$->next->type = -1; //Just a flag
    //    $$->next->tree.root = NULL;
    //    $$->next->next = NULL;
    //}
}

exprList: expr                   { $$ = $1; }
        | expr ',' exprList    {  $$ = opNode(OP, $1, $3, LIST, 0, NULL, NULL); }
        ;

assign_stmt:  var_expr '=' expr         { $$ = newStmt(ASSIGN , $1 , $3, NULL, NULL);    $$->line_num = lineno ;   }
    ;

cond_stmt:	IF expr THEN stmt_list	ENDIF			{ $$ = newCondStmt(IFCONDITION ,NULL, $2 ,NULL, $4 , NULL);    	 }
		|	IF expr THEN stmt_list ELSE stmt_list ENDIF		{ $$ = newCondStmt(IFELSECONDITION  ,NULL, $2 ,NULL, $4 , $6);  }
        |   FOR '(' init_assign  ';'  expr ';'  update_assign ')' '{' stmt_list '}'   {  $$ = newCondStmt(FORLOOPCONDITION,$3,$5,$7,$10,NULL); }
        |  DO '{' stmt_list'}' WHILE '(' expr ')' ';' { $$ = newCondStmt(DOWHILECONDITION, NULL, $7, NULL, $3, NULL); $$->line_num = lineno; }
        ;

init_assign: 
    assign_stmt  { $$ = $1; }  // Already has type from %type
  | /* empty */  { $$ = NULL; }  // Type declared via %type <stmt_list_ptr>
  ;

update_assign: 
    assign_stmt  { $$ = $1; }  // Already has type from %type
    | VAR INC ';'                 {
          /* i++ → i = i + 1 */
          expr_node *var_n = opNode(VARIABLE, NULL, NULL, ADD, 0, $1, NULL);
          expr_node *one_n = opNode(INTEGER,  NULL, NULL, ADD, 1, NULL, NULL);
          $$ = newStmt(ASSIGN, var_n, one_n, NULL, NULL);
          $$->line_num = lineno;
      }
  //| expr ';'     { $$ = newStmt(ASSIGN, $1, NULL, NULL, NULL); }  // Handle expressions like i++
  | /* empty */  { $$ = NULL; }  // Type declared via %type <stmt_list_ptr>
/*func_stmt:	func_call 		{ 		$$ = newStmt(FUNC_CALL, NULL, NULL, NULL, NULL); 				}
		;
		
func_call:	VAR '(' param_list ')'	{ 						   }
		;
		
param_list:				
		|	param_list1		
		;
		
param_list1:	para			
		|	para ',' param_list1	
		;

	para	:	expr			{ 						}
		;
*/

expr    :   NUM                 { $$ = opNode(INTEGER , NULL , NULL , ADD , $1, NULL, NULL); }
    |   '-' NUM             { $$ = opNode(INTEGER , NULL , NULL , ADD , -1*$2, NULL, NULL); }
    |   FLOAT               { $$ = opNode(FLOAT_NUM , NULL , NULL , ADD , $1, NULL, NULL);  }//$$->fval = $1;
    |   '-' FLOAT           { $$ = opNode(FLOAT_NUM , NULL , NULL , ADD , -1*$2, NULL, NULL);  } //$$->fval = -$2;
    |   var_expr            { $$ = $1; }
    |   '(' expr ')'            { $$ = $2; }
    |   expr '+' expr         { $$ = opNode(OP , $1 , $3 , ADD, 0, NULL, NULL); }
    |   expr '-' expr          { $$ = opNode(OP , $1 , $3 , SUB, 0, NULL, NULL); }
    |   expr '*' expr         { $$ = opNode(OP , $1 , $3 , MUL, 0, NULL, NULL); }
    |   expr '/' expr         { $$ = opNode(OP , $1 , $3 , DIV, 0, NULL, NULL); }
    |   expr EQUALEQUAL expr { $$ = opNode(OP, $1, $3, EQUAL, 0, NULL, NULL); }
    |   expr LESSTHANOREQUAL expr { $$ = opNode(OP, $1, $3, LESSEQUAL, 0, NULL, NULL); }
    |   expr GREATERTHANOREQUAL expr { $$ = opNode(OP, $1, $3, GREATEREQUAL, 0, NULL, NULL); }
    |   expr NOTEQUAL expr { $$ = opNode(OP, $1, $3, NOTEQUALS, 0, NULL, NULL); }
    |   expr '<' expr { $$ = opNode(OP, $1, $3, LESS, 0, NULL, NULL); }
    |   expr '>' expr { $$ = opNode(OP, $1, $3, GREATER, 0, NULL, NULL); }
    ;


var_expr:   VAR { $$ = opNode(VARIABLE , NULL , NULL , ADD , 0 , $1, NULL); }
    |   var_expr '[' expr ']' { $$ = opNode(VARIABLE, NULL, NULL, ADD, 0, ((expr_node *)$1)->name, $3); }
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
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }
    
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        fprintf(stderr, "Failed to open input file '%s'\n", argv[1]);
        exit(1);
    }
    
    // Initialize assembly file
    initAssemblyFile(argv[1]);
    
    // Parse input
    yyparse();
    
    // Generate code and finalize assembly file
    finalizeAssemblyFile();
    
    fclose(yyin);
    return 0;
}