/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:11:37 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 16:12:17 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_moves(t_stack *stack_a, t_stack *stack_b)
{
	long	closest;
	long	tmp;
	int		i;
	t_item	*og_head;

	i = 0;
	tmp = 0;
	og_head = stack_a->head;
	while (1)
	{
		stack_a->head->my_moves = get_r_or_rr(i, stack_a->size);
		closest = LONG_MAX;
		if (stack_a->head->value < stack_b->min)
			get_distance_max(stack_a->head, stack_b);
		else
			get_distance_normal(stack_a->head, stack_b, tmp, closest);
		i++;
		get_distance(stack_a->head);
		get_shortest(stack_a);
		rotate_stack(stack_a);
		if (stack_a->head == og_head)
			break ;
	}
}

static void	move_shortest(t_stack *stack_a, t_stack *stack_b)
{
	int	moves_a;
	int	moves_b;

	moves_a = stack_a->shortest->my_moves;
	moves_b = stack_a->shortest->other_moves;
	do_positive_moves(stack_a, stack_b, &moves_a, &moves_b);
	do_negative_moves(stack_a, stack_b, &moves_a, &moves_b);
	pb(stack_a, stack_b);
	stack_a->shortest = NULL;
}

static int	is_sorted(t_stack *stack)
{
	t_item	*tmp;

	tmp = stack->head;
	while (stack->head->next != tmp)
	{
		if (stack->head->value > stack->head->next->value)
		{
			stack->head = tmp;
			return (0);
		}
		stack->head = stack->head->next;
	}
	return (1);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size > 4)
		pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_a->size > 3)
	{
		get_moves(stack_a, stack_b);
		move_shortest(stack_a, stack_b);
	}
	get_max_to_top(stack_b);
	sort_three(stack_a);
	push_b_to_a(stack_a, stack_b);
}
