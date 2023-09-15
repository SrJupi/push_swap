/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:14:34 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 14:14:37 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	ft_putstr_fd("sa\n", 1);
	swap_stack(stack);
}

void	sb(t_stack *stack)
{
	ft_putstr_fd("sb\n", 1);
	swap_stack(stack);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("ss\n", 1);
	swap_stack(stack_a);
	swap_stack(stack_b);
}
