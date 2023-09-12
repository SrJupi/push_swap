#include "push_swap.h"

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    ft_putstr_fd("pa\n", 1);
    push_stack(stack_b, stack_a);
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    ft_putstr_fd("pb\n", 1);
    push_stack(stack_a, stack_b);
}