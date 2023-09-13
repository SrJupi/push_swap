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
		ft_putstr_fd("Printing Stack: ", 1);
		ft_putnbr_fd(stack->head->value, 1);
		//printf("Printing Stack: %i", stack->head->value);
		rotate_stack(stack);
		while (stack->head != tmp)
		{
			ft_putstr_fd("-> ", 1);
			ft_putnbr_fd(stack->head->value, 1);

			//printf(", %i", stack->head->value);
			rotate_stack(stack);
		}
		ft_putstr_fd(".\n",1);
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

int	check_double(t_stack *stack)
{
	t_item *current;

	current = stack->head;
	rotate_stack(stack);
	while (stack->head != current)
	{
		if (current->value == stack->head->value)
			return (1);
		rotate_stack(stack);
	}
	return (0);
}

int	create_stack(t_stack *stack, int size, char **argv)
{
	t_item *new_item;
	stack->size = 0;
	stack->max = INT_MIN;
	stack->min = INT_MAX;
	stack->head = NULL;
	if (argv != NULL)
	{
		while (size)
		{
			new_item = create_item(argv[size - 1]);
			if (insert_item(new_item, stack) || check_double(stack))
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
	if (new_item->value > stack->max)
		stack->max = new_item->value;
	if (new_item->value < stack->min)
		stack->min = new_item->value;
	return (0);
}

t_item	*remove_item(t_stack *stack)
{
	t_item	*ret_item;

	ret_item = NULL;
	if (stack->size != 0)
	{
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
