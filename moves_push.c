/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:15:18 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 14:15:19 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("pa\n", 1);
	push_stack(stack_b, stack_a);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("pb\n", 1);
	push_stack(stack_a, stack_b);
}
