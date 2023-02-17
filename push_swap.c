#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (create_stack(&stack_a, argc, argv))
	{
		printf("Oh, oh! Some shit happened!\n");
		return (1);
	}
	create_stack(&stack_b, 1, NULL);
	printf("stack A = %i/%i\nstack B = %i/%i\n", stack_a.size, stack_a.max, stack_b.size, stack_b.max);
	for (int i = 0; i < stack_a.size * 2; i++)
	{
		printf("Stack A head is %i\n", stack_a.head->value);
		stack_a.head = stack_a.head->next;
	}
	for (int i = 0; i < 3; i++)
	{
		printf("Stack B -> ");
		remove_item(&stack_b);
	}
	
	for (int i = 0; i < 6; i++)
	{
		printf("Stack A -> ");
		remove_item(&stack_a);
	}

	return (0);
}
