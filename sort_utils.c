#include "push_swap.h"

int ft_abs(int num)
{
    if (num < 0)
        num *= -1;
    return num;
}

void    push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_b->size)
    {
        while (stack_b->size &&
            stack_b->head->value > stack_a->head->prev->value)
            pa(stack_a, stack_b);
        rra(stack_a);
    }
    while (stack_a->head->prev->value < stack_a->head->value)
        rra(stack_a);
}