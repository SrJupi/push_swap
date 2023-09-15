/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:19:47 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 14:19:48 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_distance_max(t_item *head, t_stack *stack_b)
{
	int		j;
	t_item	*og_head;

	j = 0;
	og_head = stack_b->head;
	while (1)
	{
		if (stack_b->head->value == stack_b->max)
			head->other_moves = get_r_or_rr(j, stack_b->size);
		j++;
		stack_b->head = stack_b->head->next;
		if (stack_b->head == og_head)
			break ;
	}
}

void	get_distance_normal(t_item *head, t_stack *stack_b, long tmp,
		long closest)
{
	int		j;
	t_item	*og_head;

	j = 0;
	og_head = stack_b->head;
	while (1)
	{
		if (stack_b->head->value < head->value)
		{
			tmp = head->value - stack_b->head->value;
			if (tmp < closest)
			{
				closest = tmp;
				head->other_moves = get_r_or_rr(j, stack_b->size);
			}
		}
		j++;
		stack_b->head = stack_b->head->next;
		if (stack_b->head == og_head)
			break ;
	}
}

void	get_distance(t_item *head)
{
	int	mine;
	int	other;

	mine = head->my_moves;
	other = head->other_moves;
	if (mine * other >= 0)
	{
		if (ft_abs(mine) > ft_abs(other))
			head->distance = ft_abs(mine);
		else
			head->distance = ft_abs(other);
	}
	else
	{
		head->distance = ft_abs(mine) + ft_abs(other);
	}
}

void	get_shortest(t_stack *stack)
{
	if (stack->shortest == NULL)
		stack->shortest = stack->head;
	else
	{
		if (stack->head->distance < stack->shortest->distance)
			stack->shortest = stack->head;
	}
}
