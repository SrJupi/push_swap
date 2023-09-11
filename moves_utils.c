#include "push_swap.h"

int	rotate_stack(t_stack *stack)
{
	if (stack->size >= 2)
	{
		stack->head = stack->head->next;
		return (0);
	}
	return (1);
}

int	rev_rotate_stack(t_stack *stack)
{
	if (stack->size >= 2)
	{
		stack->head = stack->head->prev;
		return (0);
	}
	return (1);

}

int	push_stack(t_stack *popped, t_stack *pushed)
{
	return (insert_item(remove_item(popped), pushed));
}

int	swap_stack(t_stack *stack)
{
	int	tmp;

	if (stack->size >= 2)
	{
		tmp = stack->head->value;
		stack->head->value = stack->head->next->value;
		stack->head->next->value = tmp;
		return (0);
	}
	return (1);
}
