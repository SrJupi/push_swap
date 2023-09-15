/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:10:51 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 16:11:21 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

void	push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (stack_b->size && i < 3)
	{
		while (stack_b->size
			&& stack_b->head->value > stack_a->head->prev->value)
			pa(stack_a, stack_b);
		rra(stack_a);
		i++;
	}
	while (stack_b->size)
		pa(stack_a, stack_b);
	while (stack_a->head->prev->value < stack_a->head->value)
		rra(stack_a);
}

int	get_r_or_rr(int counter, int size)
{
	if (counter > size / 2)
		return (counter - size);
	return (counter);
}

void	get_max_to_top(t_stack *stack)
{
	int		i;
	int		j;
	t_item	*og_head;

	i = 0;
	j = 0;
	og_head = stack->head;
	while (1)
	{
		if (stack->head->value == stack->max)
			break ;
		i++;
		stack->head = stack->head->next;
		if (stack->head == og_head)
			break ;
	}
	stack->head = og_head;
	i = get_r_or_rr(i, stack->size);
	do_negative_moves(NULL, stack, &j, &i);
	do_positive_moves(NULL, stack, &j, &i);
}
