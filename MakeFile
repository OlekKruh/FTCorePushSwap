# **************************************************************************** #
#                               PUSH SWAP MAKEFILE                             #
# **************************************************************************** #

# --- Compiler settings ---
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
NAME = push_swap

# --- Directories ---
INC_DIR = include
LIB_DIR = library
SRC_DIR = src
OBJ_DIR = obj

# --- Headers ---
HEADERS = $(INC_DIR)/ft_printf.h \
          $(INC_DIR)/libft.h \
          $(INC_DIR)/pushswap.h

# --- 1. Source Libft ---
LIBFT_SRC_FILES = ft_atoi.c ft_isdigit.c ft_memcpy.c ft_split.c ft_strchr.c \
                  ft_strdup.c ft_strlen.c ft_substr.c ft_toupper.c
LIBFT_SRC = $(addprefix $(LIB_DIR)/libft/, $(LIBFT_SRC_FILES))

# --- 2. Source ft_printf ---
PRINTF_SRC_FILES = ft_printf.c print_char_str.c print_fig.c
PRINTF_SRC = $(addprefix $(LIB_DIR)/printf/, $(PRINTF_SRC_FILES))

# --- 3. Source Push_Swap Commands/Utils ---
PS_SRC_FILES = comand_push.c comand_reverse_rotate.c comand_rotate.c \
               comand_swap.c command_general.c error_output.c node_crud1.c \
               node_crud2.c node_crud3.c sort_big.c sort_small.c \
               stack_creation.c validation_argv.c validation_stack.c
PS_SRC = $(addprefix $(LIB_DIR)/pushswap/, $(PS_SRC_FILES))

# --- 4. General Source ---
MAIN_SRC_FILES = push_swap.c
MAIN_SRC = $(addprefix $(SRC_DIR)/, $(MAIN_SRC_FILES))

# --- C file ---
ALL_SRC = $(LIBFT_SRC) $(PRINTF_SRC) $(PS_SRC) $(MAIN_SRC)

# --- Object files ---
ALL_OBJ_FILES = $(patsubst %.c, %.o, $(notdir $(ALL_SRC)))
ALL_OBJ = $(addprefix $(OBJ_DIR)/, $(ALL_OBJ_FILES))

# ---------------------------------------------------------------------------- #
#                                   RULES                                      #
# ---------------------------------------------------------------------------- #

# General rule
all: $(NAME)

# Executable rule
$(NAME): $(ALL_OBJ)
	@echo "Linking dependencies..."
	@$(CC) $(CFLAGS) $(ALL_OBJ) -o $(NAME)
	@echo "\nPush_Swap compiled successfully!"

# 'obj' rule
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compiling .c files in to .o file accordingly
$(OBJ_DIR)/%.o: $(LIB_DIR)/libft/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/printf/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/pushswap/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Deletion of obj files
clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "Cleaned object files."

# Kill all
fclean: clean
	@$(RM) $(NAME)
	@echo "Cleaned executable ($(NAME))."

# Recompilation
re: fclean all

# Conflict solving
.PHONY: all clean fclean re