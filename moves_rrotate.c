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