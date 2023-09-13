#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
#include <stdio.h>
# include "libft/libft.h"

typedef struct t_item
{
	int				value;
	int distance;
	int my_moves;
	int other_moves;
	struct t_item	*prev;
	struct t_item	*next;
}	t_item;

typedef struct t_stack
{
	int				size;
	int				min;
	int				max;
	struct t_item	*head;
	struct t_item	*tmp;
}	t_stack;

//Parse utils
int split_size(char **split);
int check_parameters(int *argc, char ***argv);

//Stack utils
int		create_stack(t_stack *stack, int argc, char **argv);
int		insert_item(t_item *new_item, t_stack *stack);
void	print_stack(t_stack *stack);
t_item	*remove_item(t_stack *stack);

//Item utils
t_item	*create_item(char *str);
void	clean_item(t_item **item);

//Move utils
void	rotate_stack(t_stack *stack);
void	rev_rotate_stack(t_stack *stack);
void	push_stack(t_stack *popped, t_stack *pushed);
void	swap_stack(t_stack *stack);
void    ra(t_stack *stack);
void    rb(t_stack *stack);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack);
void    rrb(t_stack *stack);
void    rrr(t_stack *stack_a, t_stack *stack_b);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void    sa(t_stack *stack);
void    sb(t_stack *stack);
void    ss(t_stack *stack_a, t_stack *stack_b);

//Sort functions
void sort_two(t_stack *stack_a);
void sort_three(t_stack *stack_a);
void sort_five(t_stack *stack_a, t_stack *stack_b);
void sort_big(t_stack *stack_a, t_stack *stack_b);

//Sort utils
void    push_b_to_a(t_stack *stack_a, t_stack *stack_b);
int ft_abs(int num);
void move_shortest(t_stack *stack_a, t_stack *stack_b);
void get_moves(t_stack *stack_a, t_stack *stack_b);
void get_max_to_top(t_stack *stack);

#endif
