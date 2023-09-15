/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:15:01 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 14:15:02 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	ft_putstr_fd("ra\n", 1);
	rotate_stack(stack);
}

void	rb(t_stack *stack)
{
	ft_putstr_fd("rb\n", 1);
	rotate_stack(stack);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("rr\n", 1);
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}
