#ifndef HEADER_H
#define HEADER_H



#define SYMBOL_TABLE_SIZE 100


typedef enum {
    INTEGER,
    VARIABLE,
    FLOAT_NUM,
    OP
} exprtype;

typedef enum {
    LIST,
    ADD,
    SUB,
    MUL,
    DIV,
    ASSIGN_OP, 
    EQUAL,
    LESS,
    GREATER,
    LESSEQUAL,
    GREATEREQUAL,
    NOTEQUALS
} op_type;

typedef enum {
    DECL_STMT,
    BEG_STMT,
    ASSIGN,
    WRITE_STMT,
    READ_STMT,
    END_DECL,
    END_STMT,
    COND_STMT,
    BREAK_STMT
} stmt_type;

typedef enum {
    IFCONDITION,
    IFELSECONDITION,
    FORLOOPCONDITION,
    DOWHILECONDITION
} cond_type;

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
    struct expr_node* index;
    union {
        int intval;
        float floatval;
    } value;
    int is_float; 
} expr_node;

typedef struct decl_node {
    char* name;
    int array_size;
    struct decl_node* next;
} decl_node;
//
// typedef struct newDeclarationStmt{
//     stmt_type type;
//     int ret_type;
//     decl_node* node;
// } newDeclarationStmt;
typedef struct beg_node {
    char* name;
    int array_size;
    struct decl_node* next;
} beg_node;
typedef struct cond_stmt_node {
    cond_type type;
    struct stmt_list* startAssign;
    struct expr_node* condition;
    struct stmt_list* updateAssign;
    struct stmt_list* s1;
    struct stmt_list* s2;
} cond_stmt_node;

typedef struct stmt_list {
    stmt_type type;
    struct stmt_list* next;
    int line_num;
    union {
        expr_node* root;
        decl_node* decl_list;
        struct cond_stmt_node cond_stmt;
    } tree;
} stmt_list;

typedef struct {
    checking check;
    symType type;
    symbol_value_type sym_val_type;
    char* name;
    int value;
    int array_size;
    int* array;
} symbolDataType;

typedef struct {
    checking check;
    symType type;
} SearchResult;
typedef struct {
    checking check;
    symType type;
} DeclarationStmtResult;
void initializeSymbolTable();
expr_node* opNode(exprtype type, expr_node* left, expr_node* right, op_type op, int conval, char *var_name, expr_node* index);
decl_node* newDeclNode(char* name, int array_size);
stmt_list* newDeclarationStmt(stmt_type type, int ret_type, decl_node* node);
beg_node* newBegNode(char* name, int array_size);
stmt_list* newBegStmt(int ret_type, decl_node* node) ;
stmt_list* newDeclStmt(int ret_type, decl_node* node);
stmt_list* newEndStmt();
stmt_list* newEndDeclStmt();
stmt_list* newStmt(stmt_type type, expr_node* expr1, expr_node* expr2, stmt_list* stmt_list1, stmt_list* stmt_list2);

stmt_list* newCondStmt(cond_type type, stmt_list* startAssign, expr_node* condition, stmt_list* updateAssign, stmt_list* s1, stmt_list* s2);

void printAst(stmt_list* root, int indent);
void printExpr(expr_node* root, int indent);
int evalExpr(expr_node* root, int line_num);
void evalProg(stmt_list* root);
void printSymbolTableValues();
SearchResult search(char* name);
checking addToSymbolTable(char* name, symType type, symbol_value_type sym_val_type, int array_size) ;
checking updateSymbolTable(char* name, int val);
checking updateArrayElement(char* name, int index, int val);
void freeExpr(expr_node* root);
void freeStmtList(stmt_list* root);


const char* newLabel();  // Declaration
void initAssemblyFile(const char* inputFileName);
void finalizeAssemblyFile();
void genDataSection();
void genExpr(expr_node *node, int targetReg);
void genAssign(expr_node* left, expr_node* right);
void genWriteStmt(expr_node* expr);
void genIfStmt(expr_node* condition, stmt_list* thenBranch, stmt_list* elseBranch);
void genForLoop(stmt_list* init, expr_node* condition, stmt_list* update, stmt_list* body);
void genDoWhileLoop(expr_node* condition, stmt_list* body);
void genStmtList(stmt_list* root);
void genProgCode(stmt_list* root);
char* getNewLabel(const char* prefix);
#endif
