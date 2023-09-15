/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:31:15 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 14:34:37 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

void	do_positive_moves(t_stack *stack_a, t_stack *stack_b,
			int *moves_a, int *moves_b)
{
	while (*moves_a > 0 && *moves_b > 0)
	{
		rr(stack_a, stack_b);
		*moves_a -= 1;
		*moves_b -= 1;
	}
	while (*moves_a > 0)
	{
		ra(stack_a);
		*moves_a -= 1;
	}
	while (*moves_b > 0)
	{
		rb(stack_b);
		*moves_b -= 1;
	}
}

void	do_negative_moves(t_stack *stack_a, t_stack *stack_b,
			int *moves_a, int *moves_b)
{
	while (*moves_a < 0 && *moves_b < 0)
	{
		rrr(stack_a, stack_b);
		*moves_a += 1;
		*moves_b += 1;
	}
	while (*moves_a < 0)
	{
		rra(stack_a);
		*moves_a += 1;
	}
	while (*moves_b < 0)
	{
		rrb(stack_b);
		*moves_b += 1;
	}
}
