#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_item	*tmp;

	if (stack->size == 0)
	{
		printf("Empty stack!\n");
	}
	else
	{
		tmp = stack->head;
		printf("Printing Stack: %i", stack->head->value);
		rotate_stack(stack);
		while (stack->head != tmp)
		{
			printf(", %i", stack->head->value);
			rotate_stack(stack);
		}
		printf(".\n");
	}
}

void	clean_stack(t_stack *stack)
{
	t_item	*tmp;

	if (stack->size > 0)
		printf("\n...Cleaning Stack...\n");
	while (stack->size > 0)
	{
		tmp = stack->head->next;
		clean_item(&stack->head);
		stack->size -= 1;
		stack->head = tmp;
	}
	stack->head = NULL;
}

int	create_stack(t_stack *stack, int size, char **argv)
{
	printf("size: %i\n", size);
	stack->size = 0;
	stack->max = size;
	stack->head = NULL;
	if (argv != NULL)
	{
		while (size)
		{
			if (insert_item(create_item(argv[size - 1]), stack))
			{
				clean_stack(stack);
				return (1);
			}
			size--;
		}
	}
	return (0);
}

int	insert_item(t_item *new_item, t_stack *stack)
{
	if (new_item == NULL)
		return (1);
	if (stack->size == 0)
		stack->head = new_item;
	else
	{
		new_item->next = stack->head;
		new_item->prev = stack->head->prev;
		stack->head->prev->next = new_item;
		stack->head->prev = new_item;
		stack->head = new_item;
	}
	stack->size += 1;
	return (0);
}

t_item	*remove_item(t_stack *stack)
{
	t_item	*ret_item;

	ret_item = NULL;
	if (stack->size != 0)
	{
		printf("Removing item: %i\n", stack->head->value);
		ret_item = stack->head;
		stack->size -= 1;
		if (stack->size == 0)
			stack->head = NULL;
		else
		{
			stack->head = ret_item->next;
			stack->head->prev = ret_item->prev;
			stack->head->prev->next = stack->head;
		}
		ret_item->prev = ret_item;
		ret_item->next = ret_item;
	}
	return (ret_item);
}
