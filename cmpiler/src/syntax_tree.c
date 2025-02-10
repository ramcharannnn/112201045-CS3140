#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/header.h"

int symbolTableIndex = 0;
symbolDataType symbolTable[SYMBOL_TABLE_SIZE];

void initializeSymbolTable() {
    for (int i = 0; i < SYMBOL_TABLE_SIZE; i++) {
        symbolTable[i].check = UNDECL;
        if(symbolTable[i].name != NULL){
            free(symbolTable[i].name);
        }
        symbolTable[i].name = NULL;
        symbolTable[i].value = 0;
    }
}

expr_node* opNode(exprtype type, expr_node* left, expr_node* right, op_type op, int conval, char *var_name) {
    expr_node* newNode = (expr_node*)malloc(sizeof(expr_node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory not available to create new opNode.\n");
        exit(1);
    }
    newNode->type = type;
    newNode->left = left;
    newNode->right = right;
    newNode->op = op;
    newNode->conval = conval;
    newNode->name = var_name ? strdup(var_name) : NULL;
    newNode->index = NULL;

    return newNode;
}

decl_node* newDeclNode(char* name) {
    decl_node* newNode = (decl_node*)malloc(sizeof(decl_node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory not available to create newDeclNode node.\n");
        exit(1);
    }
    newNode->name = strdup(name);
    newNode->next = NULL;

    return newNode;
}

stmt_list* newDeclStmt(int ret_type, decl_node* node) {
    stmt_list* new_stmt = (stmt_list*)malloc(sizeof(stmt_list));
    if (new_stmt == NULL) {
        fprintf(stderr, "Memory not available to create newDeclStmt node\n");
        exit(1);
    }
    new_stmt->type = DECL_STMT;
    new_stmt->next = NULL;
    new_stmt->tree.decl_list = node;  

    return new_stmt;
}

stmt_list* newEndDeclStmt() {
    stmt_list* new_stmt = (stmt_list*)malloc(sizeof(stmt_list));
    if (new_stmt == NULL) {
        fprintf(stderr, "Memory not available to create newEndDeclStmt node\n");
        exit(1);
    }
    new_stmt->type = END_DECL;
    new_stmt->next = NULL;
    return new_stmt;
}

stmt_list* newStmt(stmt_type type, expr_node* expr1, expr_node* expr2) {
    stmt_list* new_stmt = (stmt_list*)malloc(sizeof(stmt_list));
    if (new_stmt == NULL) {
        fprintf(stderr, "Memory not available to create newStmt node\n");
        exit(1);
    }
    new_stmt->type = type;
    new_stmt->next = NULL;
    new_stmt->tree.root = NULL; 

    if (type == ASSIGN) {
        new_stmt->tree.root = opNode(OP, expr1, expr2, ASSIGN_OP, 0, NULL);
    } else if (type == WRITE_STMT) {
        new_stmt->tree.root = expr1; 
    } else {
        fprintf(stderr, "Invalid statement type in newStmt.\n");
        exit(EXIT_FAILURE);
    }
    return new_stmt;
}

void printExpr(expr_node* root, int indent) {
    if (root != NULL) {
        switch (root->type) {
            case OP:
                switch (root->op) {
                    case ADD:
                        printf("PLUS\n");
                        break;
                    case SUB:
                        printf("SUB\n");
                        break;
                    case MUL:
                        printf("MUL\n");
                        break;
                    case DIV:
                        printf("DIV\n");
                        break;
                    case ASSIGN_OP:
                        printf("ASSIGN\n");
                        break;
                    default:
                        printf("Unknown OP\n");
                        break;
                }
                if (root->left) {
                    printf("    ");
                    for (int i = 0; i < indent; ++i) {
                        printf("|   ");
                    }
                    printf("F\n");
                    printExpr(root->left, indent + 1);
                }
                if (root->right) {
                    printf("    ");
                    for (int i = 0; i < indent; ++i) {
                        printf("|   ");
                    }
                    printf("E\n");
                    printExpr(root->right, indent + 1);
                }
                break;
            case INTEGER:
                printf("NUM: %d\n", root->conval);
                break;
            case VARIABLE:
                printf("VAR: %s\n", root->name);
                break;
            default:
                printf("Unknown Expression Type\n");
                break;
        }
    } else {
        printf("NULL\n");
    }
}

void printAst(stmt_list* root, int indent) {
    while (root != NULL) {
        printf("    ");
        for (int i = 0; i < indent; ++i) {
            printf("|   ");
        }

        switch (root->type) {
            case DECL_STMT: {
                printf("DECL_STMT\n");
                break;
            }
            case ASSIGN:
                printf("ASSIGN_STMT\n");
                printf("    ");
                for (int i = 0; i < indent; ++i) {
                    printf("|   ");
                }
                printf("F\n");
                printExpr(root->tree.root, indent + 1);
                break;
            case WRITE_STMT:
                printf("FUNC_CALL\n");
                printf("    ");
                for (int i = 0; i < indent; ++i) {
                    printf("|   ");
                }
                printf("E\n");
                printf("    ");
                for (int i = 0; i < indent + 1; ++i) {
                    printf("|   ");
                }
                printf("WRITE\n");
                printExpr(root->tree.root, indent + 1);
                break;
            case END_DECL:
                printf("ENDDECL\n");
                break;
            default:
                printf("Unknown Statement Type\n");
                break;
        }

        root = root->next;
    }
}

void freeExpr(expr_node* root) {
    if (root == NULL) return;

    freeExpr(root->left);
    freeExpr(root->right);
    if (root->name != NULL) {
        free(root->name);
    }
    free(root);
}

void freeStmtList(stmt_list* root) {
    while (root != NULL) {
        stmt_list* next = root->next;
        if (root->type == ASSIGN || root->type == WRITE_STMT) {
            freeExpr(root->tree.root);
        }

        if (root->type == DECL_STMT) {  
            decl_node* current = root->tree.decl_list;
            decl_node* next_decl;
            while (current != NULL) {
                next_decl = current->next;
                free(current->name);
                free(current);
                current = next_decl;
            }
        }

        free(root);
        root = next;
    }
}

int evalExpr(expr_node* root, int line_num) {
    if (root == NULL) {
        return 0;
    }

    switch (root->type) {
        case OP: {
            int lval = evalExpr(root->left, line_num);
            int rval = evalExpr(root->right, line_num);
            switch (root->op) {
                case ADD: return lval + rval;
                case SUB: return lval - rval;
                case MUL: return lval * rval;
                case DIV:
                    if (rval != 0) {
                        return lval / rval;
                    } else {
                        fprintf(stderr, "Division by zero is not allowed - line %d\n", line_num);
                        exit(1);
                    }
                default:
                    fprintf(stderr, "Unexpected op_type in evalExpr: %d\n", root->op);
                    exit(1);
            }
        }
        case INTEGER: return root->conval;
        case VARIABLE: {
            SearchResult res = search(root->name);
            if (res.check == DEF) {
                for (int i = 0; i < symbolTableIndex; i++) {
                    if (strcmp(symbolTable[i].name, root->name) == 0) {
                        return symbolTable[i].value;
                    }
                }
                fprintf(stderr, "Variable %s declared but not found in evalExpr\n", root->name);
                exit(1);
            } else {
                fprintf(stderr, "Variable %s not defined\n", root->name);
                exit(1);
            }
        }
        default:
            fprintf(stderr, "Unexpected exprtype in evalExpr: %d\n", root->type);
            exit(1);
    }
}

void writeStmt(expr_node* node) {
     printf("%d\n", evalExpr(node, 0));
}
void evalProg(stmt_list* root) {
    while (root) {
        if (root->type == ASSIGN) {
            int val = evalExpr(root->tree.root->right, root->line_num);
            updateSymbolTable(root->tree.root->left->name, val);
        } else if (root->type == WRITE_STMT) {
           writeStmt(root->tree.root);
        }
        root = root->next;
    }
}
void printSymbolTableValues() {
    for (int i = 0; i < symbolTableIndex; i++) {
        if (symbolTable[i].name != NULL) {
             printf("%s : %d\n", symbolTable[i].name, symbolTable[i].value);
        }
    }
}


SearchResult search(char* name) {
    SearchResult result;
    result.check = UNDECL; 
    result.type = VAR_SYM;

    for (int i = 0; i < symbolTableIndex; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0) {
            result.check = symbolTable[i].check;
            result.type = symbolTable[i].type;
            break;
        }
    }
    return result;
}

checking addToSymbolTable(char* name, symType type, symbol_value_type sym_val_type) {
    checking sym_check = (search(name)).check;
    if (sym_check == UNDECL) {
        if (symbolTableIndex < SYMBOL_TABLE_SIZE) {
            symbolTable[symbolTableIndex].check = DEF;
            symbolTable[symbolTableIndex].type = type;
            symbolTable[symbolTableIndex].sym_val_type = sym_val_type;
            symbolTable[symbolTableIndex].name = strdup(name);
            symbolTable[symbolTableIndex].value = 0; 
            symbolTableIndex++;
        } else {
            fprintf(stderr, "Symbol table is full!\n");
            exit(1);
        }
    }
    return sym_check;
}

checking updateSymbolTable(char* name, int val) {
    for (int i = 0; i < symbolTableIndex; i++) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0) {
            symbolTable[i].value = val;
            return DEF; 
        }
    }
    return UNDECL; 
}
