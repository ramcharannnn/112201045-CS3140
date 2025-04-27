CC = gcc
YACC = yacc -d
LEX = lex

SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

YACC_SRC = $(SRC_DIR)/compiler.y
LEX_SRC = $(SRC_DIR)/compiler.l
TREE_SRC = $(SRC_DIR)/syntax_tree.c

YACC_OUT_C = y.tab.c
YACC_OUT_H = y.tab.h
LEX_OUT = lex.yy.c

EXEC = $(BIN_DIR)/compiler

all: $(EXEC)

$(EXEC): $(YACC_OUT_C) $(LEX_OUT) $(TREE_SRC)
	$(CC)  -o $(EXEC) $(LEX_OUT) $(YACC_OUT_C) $(TREE_SRC) -I$(INC_DIR) -ll -lm

$(YACC_OUT_C): $(YACC_SRC)
	$(YACC) $(YACC_SRC)

$(LEX_OUT): $(LEX_SRC)
	$(LEX) $(LEX_SRC)

clean:
	rm -f $(YACC_OUT_C) $(YACC_OUT_H) $(LEX_OUT) $(EXEC)

.PHONY: all clean
