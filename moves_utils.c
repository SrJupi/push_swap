/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:14:21 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 14:14:22 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack)
{
	if (stack->size >= 2)
		stack->head = stack->head->next;
}

void	rev_rotate_stack(t_stack *stack)
{
	if (stack->size >= 2)
		stack->head = stack->head->prev;
}

void	push_stack(t_stack *popped, t_stack *pushed)
{
	insert_item(remove_item(popped), pushed);
}

void	swap_stack(t_stack *stack)
{
	int	tmp;

	if (stack->size >= 2)
	{
		tmp = stack->head->value;
		stack->head->value = stack->head->next->value;
		stack->head->next->value = tmp;
	}
}
