#include "push_swap.h"

void    sort_two(t_stack *stack)
{
    if (stack->head->value > stack->head->next->value)
        sa(stack);
}

void    reverse_two(t_stack *stack)
{
    if (stack->head->value < stack->head->next->value)
        sb(stack);
}

void sort_three(t_stack *stack)
{
    int a;
    int b;
    int c;

    a = stack->head->value;
    b = stack->head->next->value;
    c = stack->head->prev->value;

    if (a < b && b > c && c > a)
    {
        sa(stack);
        ra(stack);
    }
    else if (a > b && b < c && c > a)
        sa(stack);
    else if (a < b && b > c && c < a)
        rra(stack);
    else if (a > b && b < c && c < a)
        ra(stack);
    else if (a > b && b > c && c < a)
    {
        sa(stack);
        rra(stack);
    }
}

int is_sorted(t_stack *stack)
{
    t_item *tmp;

    tmp = stack->head;
    while (stack->head->next != tmp)
    {
        if (stack->head->value > stack->head->next->value)
        {
            stack->head = tmp;
            return (0);
        }
        stack->head = stack->head->next;
    }
    return (1);
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_a))
        return ;
    while (stack_a->size > 3)
        pb(stack_a, stack_b);
    reverse_two(stack_b);
    sort_three(stack_a);
    push_b_to_a(stack_a, stack_b);
}

void sort_big(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_a))
        return ;
    if (stack_a->size > 4)
        pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    while (stack_a->size > 3)
    {
        get_moves(stack_a, stack_b);
        move_shortest(stack_a, stack_b);
    }
    get_max_to_top(stack_b);
    sort_three(stack_a);
    push_b_to_a(stack_a, stack_b);    
}
