NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD

ft = libft/libft.a

SRC = push_swap.c item_utils.c stack_utils.c moves_utils.c parse_utils.c moves_push.c moves_rotate.c moves_rrotate.c moves_swap.c sort_small.c sort_big.c sort_utils.c sort_distance.c sort_moves.c
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

%.o : %.c
	$(CC) $(CFLAGS) 	-Ilibft -O3 -c $< -o $@

all: lib $(NAME)

$(NAME): $(OBJ) $(ft)
	$(CC) $(OBJ) -L./libft -lft -o $(NAME)

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