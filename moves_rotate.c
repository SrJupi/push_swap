#include "push_swap.h"

void    ra(t_stack *stack)
{
    ft_putstr_fd("ra\n", 1);
    rotate_stack(stack);
}

void    rb(t_stack *stack)
{
    ft_putstr_fd("rb\n", 1);
    rotate_stack(stack);
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    ft_putstr_fd("rr\n", 1);
    rotate_stack(stack_a);
    rotate_stack(stack_b);
}