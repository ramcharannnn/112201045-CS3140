#ifndef HEADER_H
#define HEADER_H

#define SYMBOL_TABLE_SIZE 100

typedef enum {
    INTEGER,
    VARIABLE,
    OP
} exprtype;

typedef enum {
    ADD,
    SUB,
    MUL,
    DIV,
    ASSIGN_OP,
    WRITE_OP
} op_type;

typedef enum {
    DECL_STMT,
    ASSIGN,
    WRITE_STMT,
    END_DECL
} stmt_type;

typedef enum {
    VAR_SYM,
    FUNC_SYM
} symType;

typedef enum {
    INT_SYM,
    FLOAT_SYM
} symbol_value_type;

typedef enum {
    DEF,
    UNDECL
} checking;

typedef struct expr_node {
    exprtype type;
    struct expr_node* left;
    struct expr_node* right;
    op_type op;
    int conval;
    char* name;
    int* index;
} expr_node;

typedef struct decl_node {
    char* name;
    struct decl_node* next;
} decl_node;

typedef struct stmt_list {
    stmt_type type;
    struct stmt_list* next;
    int line_num;
    union {
        expr_node* root;
        decl_node* decl_list;  
    } tree;
} stmt_list;

typedef struct {
    checking check;
    symType type;
    symbol_value_type sym_val_type;
    char* name;
    int value;
} symbolDataType;

typedef struct {
    checking check;
    symType type;
} SearchResult;
void initializeSymbolTable();
expr_node* opNode(exprtype type, expr_node* left, expr_node* right, op_type op, int conval, char *var_name);
decl_node* newDeclNode(char* name);
stmt_list* newDeclStmt(int ret_type, decl_node* node);
stmt_list* newEndDeclStmt();
stmt_list* newStmt(stmt_type type, expr_node* expr1, expr_node* expr2);
void printAst(stmt_list* root, int indent);
void printExpr(expr_node* root, int indent);
int evalExpr(expr_node* root, int line_num);
void evalProg(stmt_list* root);
void printSymbolTableValues();
SearchResult search(char* name);
checking addToSymbolTable(char* name, symType type, symbol_value_type sym_val_type);
checking updateSymbolTable(char* name, int val);
void freeExpr(expr_node* root);
void freeStmtList(stmt_list* root);

#endif
