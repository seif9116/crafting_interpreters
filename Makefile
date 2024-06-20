# Directories
SRC_DIR = com/craftinginterpreters
LOX_DIR = $(SRC_DIR)/lox
TOOL_DIR = $(SRC_DIR)/tool

# Java files
LOX_JAVA_FILES = $(wildcard $(LOX_DIR)/*.java)
TOOL_JAVA_FILES = $(wildcard $(TOOL_DIR)/*.java)

# Class files
LOX_CLASS_FILES = $(LOX_JAVA_FILES:.java=.class)
TOOL_CLASS_FILES = $(TOOL_JAVA_FILES:.java=.class)

# Compile function
compile_lox:
	@echo "Compiling Lox Java files..."
	@javac $(LOX_JAVA_FILES)
	@echo "Compilation finished."

compile_tool:
	@echo "Compiling Tool Java files..."
	@javac $(TOOL_JAVA_FILES)
	@echo "Compilation finished."

# Run function for Lox
run_lox:
	@echo "Running Lox..."
	@java com.craftinginterpreters.lox.Lox

# Run function for GenerateAst
run_generateast:
	@echo "Running GenerateAst..."
	@java com.craftinginterpreters.tool.GenerateAst com/craftinginterpreters/lox

# Run function for AstPrinter
run_astprinter:
	@echo "Running AstPrinter..."
	@java com.craftinginterpreters.lox.AstPrinter

# Clean function to remove class files
clean:
	@echo "Cleaning up..."
	@rm -f $(LOX_CLASS_FILES) $(TOOL_CLASS_FILES)
	@echo "Clean finished."

# Default target
.PHONY: all
all: compile_lox compile_tool

# Targets
.PHONY: compile_lox compile_tool run_lox run_generateast run_astprinter clean
