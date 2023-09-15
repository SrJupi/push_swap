/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:14:50 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 14:14:56 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	ft_putstr_fd("rra\n", 1);
	rev_rotate_stack(stack);
}

void	rrb(t_stack *stack)
{
	ft_putstr_fd("rrb\n", 1);
	rev_rotate_stack(stack);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("rrr\n", 1);
	rev_rotate_stack(stack_a);
	rev_rotate_stack(stack_b);
}
