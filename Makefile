# Static library name
NAME = build/libft.a

# Compiler and compiler flags
CC = cc
C_FLAGS = -Wall -Werror -Wextra -g3 -I $(HEADER_DIR)

# Directories
SRC_DIR = source
OBJ_DIR = build/obj
HEADER_DIR = /include

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile .c files into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "\033[1;33mCOMPILING $<...\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and executable
clean:
	@echo "\033[1;31mCLEANING OBJECT FILES AND EXECUTABLES FROM LIBFT...\033[0m" 
	rm -rf $(OBJ_DIR)
	rm -f ./test_program
	@echo "\033[32mCLEANING LIBFT DONE\033[0m"

# Full clean (including library)
fclean: clean
	rm -f $(NAME)
	@echo "\033[32mLIBFT CLEAR\033[0m"

# Rebuild the project
re: fclean all
	@echo "\033[1;34mREBUILDING LIBFT LIBRARY...\033[0m"

# Rule to run single tests
test: $(NAME) 
	@echo "\033[1;36mCOMPILING AND RUNNING TESTS...\033[0m"
	$(CC) $(CFLAGS) -o test_program $(OBJ_DIR)/main.o $(NAME)
	@./test_program
	rm -f ./test_program

bonus: .b

.b: $(OBJS) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJS)
	touch $(OBJ_DIR)/.b

# Rule to run bonus tests
bonus_test: $(NAME) 
	@echo "\033[1;36mCOMPILING AND RUNNING BONUS TESTS...\033[0m"
	$(CC) $(CFLAGS) -o test_program $(OBJ_DIR)/main_bonus.o $(NAME)
	@./test_program
	rm -f ./test_program

.PHONY: all clean fclean re test bonus bonus_test