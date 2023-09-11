NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD

ft = libft/libft.a

SRC = push_swap.c item_utils.c stack_utils.c moves_utils.c
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

%.o : %.c
	$(CC) $(CFLAGS) 	-Ilibft -O3 -c $< -o $@

all: lib $(NAME)

$(NAME): $(OBJ) $(ft)
	$(CC) $(OBJ) -L./libft -lft -o $(NAME)
	@echo "So long compiled!"


lib: 
	make -C libft

clean:
	rm -rf $(OBJ) $(DEP)
	make clean -C libft

fclean:
	rm -rf $(NAME) $(OBJ) $(DEP)
	make fclean -C libft

re:	fclean all

-include $(DEP)

.PHONY: all re clean fclean