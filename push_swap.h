/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:16:28 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 16:18:27 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_item
{
	int				value;
	int				distance;
	int				my_moves;
	int				other_moves;
	struct t_item	*prev;
	struct t_item	*next;
}					t_item;

typedef struct t_stack
{
	int				size;
	int				min;
	int				max;
	struct t_item	*head;
	struct t_item	*shortest;

}					t_stack;

// Parse utils
int		split_size(char **split);
int		check_parameters(int *argc, char ***argv, int *split);

// Stack utils
int		create_stack(t_stack *stack, int argc, char **argv);
void	clean_stack(t_stack *stack);
int		insert_item(t_item *new_item, t_stack *stack);
void	print_stack(t_stack *stack);
t_item	*remove_item(t_stack *stack);

// Item utils
t_item	*create_item(char *str);
void	clean_item(t_item **item);

// Move utils
void	rotate_stack(t_stack *stack);
void	rev_rotate_stack(t_stack *stack);
void	push_stack(t_stack *popped, t_stack *pushed);
void	swap_stack(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);

// Sort functions
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_big(t_stack *stack_a, t_stack *stack_b);

// Sort utils
void	push_b_to_a(t_stack *stack_a, t_stack *stack_b);
int		ft_abs(int num);
int		get_r_or_rr(int counter, int size);
void	get_max_to_top(t_stack *stack);
void	do_negative_moves(t_stack *stack_a, t_stack *stack_b,
			int *moves_a, int *moves_b);
void	do_positive_moves(t_stack *stack_a, t_stack *stack_b,
			int *moves_a, int *moves_b);
void	get_distance_max(t_item *head, t_stack *stack_b);
void	get_distance_normal(t_item *head, t_stack *stack_b, long tmp,
			long closest);
void	get_distance(t_item *head);
void	get_shortest(t_stack *stack);

#endif
