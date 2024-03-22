# Compiler and compiling flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Project file names
SRC = dlistfuncs_part1.c sortingfunc_part1.c sortingfunc_part3.c \
      dlistfuncs_part2.c sortingfunc_part2.c sortingfunc_part4.c \
      sortingfunc_part5.c sortingfunc_part6.c dlistfuncs_part3.c \
      sortingfunc_part7.c main.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

# Bonus project file names
BONUS_SRC = check_utils.c check_utils2.c check_utils3.c \
            check_utils4.c check_utils5.c checker_main.c checker_porc.c \
			get_next_line.c get_next_line_utils.c check_utils6.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_NAME = checker

# Library paths
LIBFT = ./ft_libft
FT_PRINTF = ./ft_printf

# Include and library flags
INCLUDES = -I$(LIBFT) -I$(FT_PRINTF) -I.
LDFLAGS = -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(FT_PRINTF)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

bonus: $(BONUS_OBJ)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(FT_PRINTF)
	$(CC) $(BONUS_OBJ) $(LDFLAGS) -o $(BONUS_NAME)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(FT_PRINTF)
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) fclean -C $(FT_PRINTF)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
.SECONDARY: $(OBJ) $(BONUS_OBJ)