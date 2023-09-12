#include "push_swap.h"

void    sort_two(t_stack *stack)
{
    if (stack->head->value > stack->head->next->value)
        sa(stack);
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
            return (0);
        stack->head = stack->head->next;
    }
    return (1);
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    t_item *smallest;
    t_item *a_start;
    
    if (is_sorted(stack_a))
        return ;
    while (stack_a->size > 3)
        pb(stack_a, stack_b);
    sort_two(stack_b);
    sort_three(stack_a);
    a_start = stack_a->head;
    if (stack_a->head->value < stack_b->head->value)
        smallest = stack_a->head;
    else
        smallest = stack_b->head;
    while(stack_b->size)
    {
        while (stack_b->head->value > stack_a->head->value)
        {
            ra(stack_a);
            if (stack_a->head == a_start)
                break;
        }
        pa(stack_a, stack_b);
    }
    while(stack_a->head != smallest)
        ra(stack_a);
}

void sort_big(t_stack *stack_a, t_stack *stack_b)
{
    (void)stack_a;
    (void)stack_b;
}
