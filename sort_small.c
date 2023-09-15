/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:10:43 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 16:11:01 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->head->value > stack->head->next->value)
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->head->value;
	b = stack->head->next->value;
	c = stack->head->prev->value;
	if (a < b && b > c && c > a)
	{
		sa(stack);
		ra(stack);
	}
	else if (a > b && b < c && c > a)
		sa(stack);
	else if (a < b && b > c && c < a)
		rra(stack);
	else if (a > b && b < c && c < a)
		ra(stack);
	else if (a > b && b > c && c < a)
	{
		sa(stack);
		rra(stack);
	}
}
