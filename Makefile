# Compiler and tools
CC = gcc
LEX = lex
YACC = yacc

# Flags
YACCFLAGS = -d -v    # Generate header file and verbose output
LEXFILE = calculator.l
YACCFILE = calculator.y
EXECUTABLE = calculator

# Intermediate files
LEX_OUTPUT = lex.yy.c
YACC_C_OUTPUT = y.tab.c
YACC_HEADER_OUTPUT = y.tab.h

# Default target: Build and run
all: $(EXECUTABLE) run

# Build the executable
$(EXECUTABLE): $(LEX_OUTPUT) $(YACC_C_OUTPUT)
	$(CC) $(LEX_OUTPUT) $(YACC_C_OUTPUT) -o $(EXECUTABLE)

# Run the program
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Generate Lex and Yacc outputs
$(LEX_OUTPUT): $(LEXFILE) $(YACC_HEADER_OUTPUT)
	$(LEX) $(LEXFILE)

$(YACC_C_OUTPUT) $(YACC_HEADER_OUTPUT): $(YACCFILE)
	$(YACC) $(YACCFLAGS) $(YACCFILE)

# Clean generated files
clean:
	rm -f $(LEX_OUTPUT) $(YACC_C_OUTPUT) $(YACC_HEADER_OUTPUT) $(EXECUTABLE) y.output

