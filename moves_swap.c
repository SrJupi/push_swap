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