/* syntax_tree.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/header.h"

int symbolTableIndex = 0;
symbolDataType symbolTable[SYMBOL_TABLE_SIZE];

void initializeSymbolTable() {
    for (int i = 0; i < SYMBOL_TABLE_SIZE; i++) {
        symbolTable[i].check = UNDECL;
        if (symbolTable[i].name != NULL) {
            free(symbolTable[i].name);
        }
        symbolTable[i].name = NULL;
        symbolTable[i].value = 0;
        symbolTable[i].array_size = 0;
        symbolTable[i].array = NULL;
    }
}

expr_node* opNode(exprtype type, expr_node* left, expr_node* right, op_type op, int conval, char *var_name, expr_node* index) {
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
    newNode->index = index;
    if (type == INTEGER) {
        newNode->value.intval = (int)conval;
        newNode->is_float = 0;
    } else if (type == FLOAT_NUM) {
        newNode->value.floatval = conval;
        newNode->is_float = 1;
    }
    return newNode;
}

decl_node* newDeclNode(char* name, int array_size) {
    decl_node* newNode = (decl_node*)malloc(sizeof(decl_node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory not available to create newDeclNode node.\n");
        exit(1);
    }
    newNode->name = strdup(name);
    newNode->next = NULL;
    newNode->array_size = array_size;

    return newNode;
}

beg_node* newBegNode(char* name, int array_size) {
    beg_node* newNode = (beg_node*)malloc(sizeof(beg_node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory not available to create newDeclNode node.\n");
        exit(1);
    }
    newNode->name = strdup(name);
    newNode->next = NULL;
    newNode->array_size = array_size;

    return newNode;
}

stmt_list* newDeclarationStmt(stmt_type type, int ret_type, decl_node* node) {
    stmt_list* new_stmt = (stmt_list*)malloc(sizeof(stmt_list));
    if (new_stmt == NULL) {
        fprintf(stderr, "Memory not available to create a new declaration-like statement node\n");
        exit(1);
    }

    new_stmt->type = type;
    new_stmt->next = NULL;
    new_stmt->tree.decl_list = node; 

    return new_stmt;
}

stmt_list* newBegStmt(int ret_type, decl_node* node) {
    stmt_list* new_stmt = (stmt_list*)malloc(sizeof(stmt_list));
    if (new_stmt == NULL) {
        fprintf(stderr, "Memory not available to create a new BEG statement node\n");
        exit(1);
    }

    new_stmt->type = BEG_STMT;
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

stmt_list* newEndStmt() {
    stmt_list* new_stmt = (stmt_list*)malloc(sizeof(stmt_list));
    if (new_stmt == NULL) {
        fprintf(stderr, "Memory not available to create newEndDeclStmt node\n");
        exit(1);
    }
    new_stmt->type = END_STMT;
    new_stmt->next = NULL;
    return new_stmt;
}

stmt_list* newStmt(stmt_type type, expr_node* expr1, expr_node* expr2, stmt_list* stmt_list1, stmt_list* stmt_list2) {
    stmt_list* new_stmt = (stmt_list*)malloc(sizeof(stmt_list));
    if (new_stmt == NULL) {
        fprintf(stderr, "Memory not available to create newStmt node\n");
        exit(1);
    }
    new_stmt->type = type;
    new_stmt->next = NULL;
    new_stmt->tree.root = NULL;

    switch (type) {
        case ASSIGN:
            new_stmt->tree.root = opNode(OP, expr1, expr2, ASSIGN_OP, 0, NULL, NULL);
            break;
        case WRITE_STMT:
            new_stmt->tree.root = expr1;
            break;
        case BREAK_STMT:  
            break;
        default:
            fprintf(stderr, "Invalid statement type in newStmt.\n");
            exit(EXIT_FAILURE);
    }
    return new_stmt;
}

stmt_list* newCondStmt(cond_type type, stmt_list* startAssign, expr_node* condition, stmt_list* updateAssign, stmt_list* s1, stmt_list* s2) {
    stmt_list* new_stmt = (stmt_list*)malloc(sizeof(stmt_list));
    if (new_stmt == NULL) {
        fprintf(stderr, "Memory not available to create newStmt node\n");
        exit(1);
    }
    new_stmt->type = COND_STMT;
    new_stmt->next = NULL;
    new_stmt->tree.cond_stmt.type = type;
    new_stmt->tree.cond_stmt.startAssign = startAssign;
    new_stmt->tree.cond_stmt.condition = condition;
    new_stmt->tree.cond_stmt.updateAssign = updateAssign;
    new_stmt->tree.cond_stmt.s1 = s1;
    new_stmt->tree.cond_stmt.s2 = s2;

    return new_stmt;
}

void printExpr(expr_node* root, int indent) {
    if (root != NULL) {
          for (int i = 0; i < indent; ++i) {
            printf("|   ");
        }
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
                    case EQUAL:
                        printf("EQUAL\n");
                        break;
                    case LESS:
                        printf("LESS\n");
                        break;
                    case GREATER:
                        printf("GREATER\n");
                        break;
                    case LESSEQUAL:
                        printf("LESSEQUAL\n");
                        break;
                    case GREATEREQUAL:
                        printf("GREATEREQUAL\n");
                        break;
                    case NOTEQUALS:
                        printf("NOTEQUALS\n");
                        break;
                    default:
                        printf("Unknown OP\n");
                        break;
                }
                if (root->left) {
                    for (int i = 0; i < indent+1; ++i) {
                        printf("|   ");
                    }
                    printf("Left Operand:\n");
                    printExpr(root->left, indent + 2);
                }
                if (root->right) {
                    for (int i = 0; i < indent+1; ++i) {
                        printf("|   ");
                    }
                    printf("Right Operand:\n");
                    printExpr(root->right, indent + 2);
                }
                break;
            case INTEGER:
                printf("NUM: %d\n", root->conval);
                break;
             case FLOAT_NUM:
                printf("FLOAT_NUM: %d\n", root->conval);
                break;
            case VARIABLE:
                printf("VAR: %s", root->name);
                if (root->index) {
                    printf(" [");
                    printExpr(root->index, 0);
                    printf("]");
                }
                printf("\n");
                break;
            default:
                printf("Unknown Expression Type\n");
                break;
        }
    } else {
         for (int i = 0; i < indent; ++i) {
            printf("|   ");
        }
        printf("[NULL]\n");
    }
}
void printAst(stmt_list* root, int indent) {
    while (root != NULL) {
        for (int i = 0; i < indent; ++i) {
            printf("|   ");
        }
        switch (root->type) {
            case DECL_STMT: {
                printf("DECL_STMT\n");
                break;
            }
            case BEG_STMT: {
                printf("BEG_STMT\n");
                break;
            }
             case BREAK_STMT:
                printf("BREAK_STMT\n");
                break;

            case ASSIGN:
                printf("ASSIGN_STMT\n");
                for (int i = 0; i < indent+1; ++i) {
                    printf("|   ");
                }
                printf("E\n");
                printExpr(root->tree.root, indent + 2);
                break;
            case WRITE_STMT:
                printf("WRITE_STMT\n");
                for (int i = 0; i < indent+1; ++i) {
                    printf("|   ");
                }
                printf("E\n");
                printExpr(root->tree.root, indent + 2);
                break;
            case COND_STMT:
                printf("COND_STMT\n");
                switch (root->tree.cond_stmt.type) {
                    case IFCONDITION:
                        printf("  IF\n");
                        break;
                    case IFELSECONDITION:
                        printf("  IF-ELSE\n");
                        break;
                    case FORLOOPCONDITION:
                        printf("  FOR\n");
                        break;
                    case DOWHILECONDITION:
                        printf("Do-While Loop\n");
                        printf("Condition:\n");
                        break;
                    
                    default:
                        printf("  Unknown Condition Type\n");
                        break;
                }
                for (int i = 0; i < indent+1; ++i) {
                    printf("|   ");
                }
                printf("Condition:\n");
                printExpr(root->tree.cond_stmt.condition, indent + 2);
                for (int i = 0; i < indent; ++i) {
                    printf("|   ");
                }
                printf("Then Branch:\n");
                printAst(root->tree.cond_stmt.s1, indent + 2);
                if (root->tree.cond_stmt.s2) {
                    for (int i = 0; i < indent; ++i) {
                        printf("|   ");
                    }
                    printf("Else Branch:\n");
                    printAst(root->tree.cond_stmt.s2, indent + 2);
                }
                break;
            case END_DECL:
                printf("ENDDECL\n");
                break;
            case END_STMT:
                printf("END_STMT\n");
                break;
            default:
                printf("Unknown Statement Type\n");
                break;
        }

        root = root->next;
    }
}


int evalExpr(expr_node* root, int line_num) {
    if (root == NULL) {
        return 0;
    }

    switch (root->type) {
        case INTEGER:
            return root->conval;
        case FLOAT_NUM:
            return root->conval;
        case VARIABLE: {
            SearchResult result = search(root->name);
            if (result.check == UNDECL) {
                fprintf(stderr, "Error: Variable '%s' undeclared on line %d\n", root->name, line_num);
                exit(1);
            }

            int symbolIndex = -1;
            for (int i = 0; i < symbolTableIndex; i++) {
                 if (symbolTable[i].check == DEF && symbolTable[i].name != NULL && strcmp(symbolTable[i].name, root->name) == 0) {
                    symbolIndex = i;
                     break;
        }
            }

            if (symbolIndex == -1) {
                    fprintf(stderr, "Error: Variable '%s' not found in symbol table\n", root->name);
                    exit(1);
            }


              if (root->index) {  
                int index = evalExpr(root->index, line_num);
                if (index < 0 || index >= symbolTable[symbolIndex].array_size) {
                      fprintf(stderr, "Error: Array index %d out of bounds for '%s' on line %d. Max size: %d\n",
                        index, root->name, line_num, symbolTable[symbolIndex].array_size);
                    exit(1);
              }

                return symbolTable[symbolIndex].array[index];
            } else {
                return symbolTable[symbolIndex].value;
            }
        }
        case OP:
            switch (root->op) {
                case ADD:
                    return evalExpr(root->left, line_num) + evalExpr(root->right, line_num);
                case SUB:
                    return evalExpr(root->left, line_num) - evalExpr(root->right, line_num);
                case MUL:
                    return evalExpr(root->left, line_num) * evalExpr(root->right, line_num);
                case DIV: {
                    int denominator = evalExpr(root->right, line_num);
                    if (denominator == 0) {
                        fprintf(stderr, "Error: Division by zero on line %d\n", line_num);
                        exit(1);
                    }
                    return evalExpr(root->left, line_num) / denominator;
                }
                case EQUAL:
                    return evalExpr(root->left, line_num) == evalExpr(root->right, line_num);
                case LESS:
                    return evalExpr(root->left, line_num) < evalExpr(root->right, line_num);
                case GREATER:
                    return evalExpr(root->left, line_num) > evalExpr(root->right, line_num);
                case LESSEQUAL:
                    return evalExpr(root->left, line_num) <= evalExpr(root->right, line_num);
                case GREATEREQUAL:
                    return evalExpr(root->left, line_num) >= evalExpr(root->right, line_num);
                case NOTEQUALS:
                    return evalExpr(root->left, line_num) != evalExpr(root->right, line_num);
                default:
                    fprintf(stderr, "Error: Unknown operator type\n");
                    exit(1);
            }
        default:
            fprintf(stderr, "Error: Unknown expression type\n");
            exit(1);
    }
}


void writeStmt(expr_node* node) {
    printf("%d\n", evalExpr(node, 0));
}
int break_flag =0;
void evalProg(stmt_list* root) {
    while (root) {
        switch (root->type) {
            case ASSIGN: {
                char* var_name = root->tree.root->left->name;
                int val = evalExpr(root->tree.root->right, root->line_num);

                if (root->tree.root->left->index != NULL) {
                    int index_val = evalExpr(root->tree.root->left->index, root->line_num);
                    updateArrayElement(var_name, index_val, val);
                } else {
                    updateSymbolTable(var_name, val);
                }
                break;
            }
            case WRITE_STMT:
                writeStmt(root->tree.root);
                break;
            case BREAK_STMT:
                   break_flag = 1; 
                  
                return;  
            case COND_STMT: {
                switch (root->tree.cond_stmt.type) {
                    case IFCONDITION: {
                        int condition_val = evalExpr(root->tree.cond_stmt.condition, root->line_num);
                        if (condition_val) {
                            evalProg(root->tree.cond_stmt.s1);
                        }
                        break;
                    }
                    case IFELSECONDITION: {
                        int condition_val = evalExpr(root->tree.cond_stmt.condition, root->line_num);
                        if (condition_val) {
                            evalProg(root->tree.cond_stmt.s1);
                        } else {
                            evalProg(root->tree.cond_stmt.s2);
                        }
                        break;
                    }
                    case FORLOOPCONDITION: {
                        if (root->tree.cond_stmt.startAssign) {
                            evalProg(root->tree.cond_stmt.startAssign);
                        }
                        expr_node* condition = root->tree.cond_stmt.condition;
                        while (evalExpr(condition, root->line_num)) {
                            evalProg(root->tree.cond_stmt.s1);
                              if (break_flag) {
                                         break_flag = 0;
                                        break; 
                                  }
                            if (root->tree.cond_stmt.updateAssign) {
                                evalProg(root->tree.cond_stmt.updateAssign);
                            }
                        }
                        break;
                    }
                     case DOWHILECONDITION: {
                        int loopCounter = 0;
                        do {
                            evalProg(root->tree.cond_stmt.s1);
                             if (break_flag) {
                                break_flag = 0;
                                 break; }
                            if (++loopCounter > 1000) {  
                                    fprintf(stderr, "Error: Infinite loop detected in do-while on line %d\n", root->line_num);
                                    exit(1);
                                    }
                            } while (evalExpr(root->tree.cond_stmt.condition, root->line_num));
                        
                        break;
                    }
                }
                break;
            }
            default:
                break;
        }
        root = root->next;
    }
}

void printSymbolTableValues() {
    for (int i = 0; i < symbolTableIndex; i++) {
        printf("%s : ", symbolTable[i].name);
        if (symbolTable[i].array != NULL) {
            printf("[");
            for (int j = 0; j < symbolTable[i].array_size; j++) {
                printf("%d", symbolTable[i].array[j]);
                if (j < symbolTable[i].array_size - 1) {
                    printf(", ");
                }
            }
            printf("]");
        } else {
            printf("%d", symbolTable[i].value);
        }
        printf("\n");
    }
}

SearchResult search(char* name) {
    SearchResult result;
    result.check = UNDECL;
    result.type = VAR_SYM;

    for (int i = 0; i < symbolTableIndex; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            result.check = DEF;
            result.type = symbolTable[i].type;
            return result;
        }
    }

    return result;
}

checking addToSymbolTable(char* name, symType type, symbol_value_type sym_val_type, int array_size) {
    if (symbolTableIndex >= SYMBOL_TABLE_SIZE) {
        fprintf(stderr, "Symbol table is full.\n");
        return UNDECL;
    }

    if (search(name).check == DEF) {
        fprintf(stderr, "Variable %s already defined.\n", name);
        return DEF;
    }

    symbolTable[symbolTableIndex].name = strdup(name);
    symbolTable[symbolTableIndex].type = type;
    symbolTable[symbolTableIndex].sym_val_type = sym_val_type;
    symbolTable[symbolTableIndex].check = DEF;
    symbolTable[symbolTableIndex].value = 0;
    symbolTable[symbolTableIndex].array_size = array_size;

    if (array_size > 0) {
        symbolTable[symbolTableIndex].array = (int*)malloc(sizeof(int) * array_size);
        if (symbolTable[symbolTableIndex].array == NULL) {
            fprintf(stderr, "Memory allocation failed for array %s.\n", name);
            exit(1);
        }
        for (int i = 0; i < array_size; i++) {
            symbolTable[symbolTableIndex].array[i] = 0;
        }
    } else {
        symbolTable[symbolTableIndex].array = NULL;
    }

    symbolTableIndex++;
    return UNDECL;
}

checking updateSymbolTable(char* name, int val) {
    for (int i = 0; i < symbolTableIndex; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            symbolTable[i].value = val;
            return DEF;
        }
    }
    fprintf(stderr, "Variable %s not found in symbol table.\n", name);
    return UNDECL;
}

checking updateArrayElement(char* name, int index, int val) {
    SearchResult result = search(name);
    if (result.check == UNDECL) {
        return UNDECL;
    }

    int symbolIndex = -1;
    for (int i = 0; i < SYMBOL_TABLE_SIZE; i++) {
        if (symbolTable[i].check == DEF && symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0) {
            symbolIndex = i;
            break;
        }
    }

    if (symbolIndex == -1) {
        return UNDECL; 
    }

    if (symbolTable[symbolIndex].array_size == 0) {
        fprintf(stderr, "Error: '%s' is not an array.\n", name);
        return UNDECL;
    }

    if (index < 0 || index >= symbolTable[symbolIndex].array_size) {
        fprintf(stderr, "Error: Array index out of bounds for '%s'.\n", name);
        return UNDECL;
         exit(1);
    }

    symbolTable[symbolIndex].array[index] = val;
    return DEF;
}


void freeExpr(expr_node* root) {
    if (root) {
        if (root->name) {
            free(root->name);
            root->name = NULL;
        }
        freeExpr(root->left);
        freeExpr(root->right);
        root->left = NULL;
        root->right = NULL;
        free(root);
    }
}


void freeStmtList(stmt_list* root) {
    while (root) {
        stmt_list* temp = root;
        root = root->next;
        
        if (temp->type == ASSIGN || temp->type == WRITE_STMT) {
            if (temp->tree.root) {
                freeExpr(temp->tree.root);
                temp->tree.root = NULL;  
            }
        } else if (temp->type == COND_STMT) {
            if (temp->tree.cond_stmt.condition) {
                freeExpr(temp->tree.cond_stmt.condition);
                temp->tree.cond_stmt.condition = NULL;
            }
            if (temp->tree.cond_stmt.s1) {
                freeStmtList(temp->tree.cond_stmt.s1);
                temp->tree.cond_stmt.s1 = NULL;
            }
            if (temp->tree.cond_stmt.s2) {
                freeStmtList(temp->tree.cond_stmt.s2);
                temp->tree.cond_stmt.s2 = NULL;
            }
            if (temp->tree.cond_stmt.startAssign) {
                freeStmtList(temp->tree.cond_stmt.startAssign);
                temp->tree.cond_stmt.startAssign = NULL;
            }
            if (temp->tree.cond_stmt.updateAssign) {
                freeStmtList(temp->tree.cond_stmt.updateAssign);
                temp->tree.cond_stmt.updateAssign = NULL;
            }
        }
        
        free(temp);
    }
}
// int evalExpr(expr_node* root, int line_num) {
//     if (root == NULL) {
//         return 0;
//     }

//     switch (root->type) {
//         case OP: {
//             int lval = evalExpr(root->left, line_num);
//             int rval = evalExpr(root->right, line_num);
//             switch (root->op) {
//                 case ADD: return lval + rval;
//                 case SUB: return lval - rval;
//                 case MUL: return lval * rval;
//                 case DIV:
//                     if (rval != 0) {
//                         return lval / rval;
//                     } else {
//                         fprintf(stderr, "Division by zero is not allowed - line %d\n", line_num);
//                         exit(1);
//                     }
//                 case EQUAL: return lval == rval;
//                 case LESS: return lval < rval;
//                 case GREATER: return lval > rval;
//                 case LESSEQUAL: return lval <= rval;
//                 case GREATEREQUAL: return lval >= rval;
//                 case NOTEQUALS: return lval != rval;
//                 default:
//                     fprintf(stderr, "Unexpected op_type in evalExpr: %d\n", root->op);
//                     exit(1);
//             }
//         }
//         case INTEGER: return root->conval;
//         case VARIABLE: {
//             SearchResult res = search(root->name);
//             if (res.check == DEF) {
//                 int index_val = 0;
//                 if (root->index != NULL) {
//                     index_val = evalExpr(root->index, line_num);
//                 }
//                 for (int i = 0; i < symbolTableIndex; i++) {
//                     if (strcmp(symbolTable[i].name, root->name) == 0) {
//                         if (symbolTable[i].array != NULL) {
//                             if (index_val >= 0 && index_val < symbolTable[i].array_size) {
//                                 return symbolTable[i].array[index_val];
//                             } else {
//                                 fprintf(stderr, "Array index out of bounds - line %d\n", line_num);
//                                 exit(1);
//                             }
//                         } else {
//                             return symbolTable[i].value;
//                         }
//                     }
//                 }
//                 fprintf(stderr, "Variable %s declared but not found in evalExpr\n", root->name);
//                 exit(1);
//             } else {
//                 fprintf(stderr, "Variable %s not defined\n", root->name);
//                 exit(1);
//             }
//         }
//         default:
//             fprintf(stderr, "Unexpected exprtype in evalExpr: %d\n", root->type);
//             exit(1);
//         }
//     }