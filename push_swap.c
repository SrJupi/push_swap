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
	create_stack(&stack_b, argc, NULL);
	printf("A - %i/%i\nB - %i/%i\n", stack_a.size, stack_a.max, stack_b.size, stack_b.max);
	print_stack(&stack_a);
	print_stack(&stack_b);
	push_stack(&stack_b, &stack_a);
	print_stack(&stack_a);
	print_stack(&stack_b);
	push_stack(&stack_a, &stack_b);
	print_stack(&stack_a);
	print_stack(&stack_b);
	push_stack(&stack_a, &stack_b);
	print_stack(&stack_a);
	print_stack(&stack_b);
	rotate_stack(&stack_a);
	rotate_stack(&stack_b);
	print_stack(&stack_a);
	print_stack(&stack_b);
	swap_stack(&stack_a);
	swap_stack(&stack_b);
	print_stack(&stack_a);
	print_stack(&stack_b);
	printf("A - %i/%i\nB - %i/%i\n", stack_a.size, stack_a.max, stack_b.size, stack_b.max);
	return (0);
}
