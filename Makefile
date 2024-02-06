# Compiler and compiling flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Project file names
SRC = dlistfuncs.c sortingfunc.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

# Library paths
LIBFT = ./ft_libft
FT_PRINTF = ./ft_printf

# Include and library flags
INCLUDES = -I$(LIBFT) -I$(FT_PRINTF) -I.
LDFLAGS = -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf

# Compile and create everything
all: $(NAME)

# Compile the project
$(NAME): $(OBJ)
	make -C $(LIBFT)
	make -C $(FT_PRINTF)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

# Object file creation
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Cleaning up the object files
clean:
	make clean -C $(LIBFT)
	make clean -C $(FT_PRINTF)
	rm -f $(OBJ)

# Full clean (objects and executable)
fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(FT_PRINTF)
	rm -f $(NAME)

# Re-compile everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
