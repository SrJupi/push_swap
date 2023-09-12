#include "push_swap.h"

void	rotate_stack(t_stack *stack)
{
	if (stack->size >= 2)
		stack->head = stack->head->next;
}

void	rev_rotate_stack(t_stack *stack)
{
	if (stack->size >= 2)
		stack->head = stack->head->prev;
}

void	push_stack(t_stack *popped, t_stack *pushed)
{
	insert_item(remove_item(popped), pushed);
}

void	swap_stack(t_stack *stack)
{
	int	tmp;

	if (stack->size >= 2)
	{
		tmp = stack->head->value;
		stack->head->value = stack->head->next->value;
		stack->head->next->value = tmp;
	}
}
