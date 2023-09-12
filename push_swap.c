#include <stdio.h>
#include "push_swap.h"

static void	do_push_swap(t_stack stack_a, t_stack stack_b)
{
	if (stack_a.size == 1)
		ft_putchar_fd('\n', 1);
	else if (stack_a.size == 2)
		sort_two(&stack_a);
	else if (stack_a.size == 3)
		sort_three(&stack_a);
	else if (stack_a.size <= 5)
		sort_five(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b);
}


int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (check_parameters(&argc, &argv))
		return (1);
	if (create_stack(&stack_a, argc - 1, argv))
	{
		exit(EXIT_FAILURE);
	}
	create_stack(&stack_b, argc - 1, NULL);
	do_push_swap(stack_a, stack_b);
	exit(EXIT_SUCCESS);
/* 	printf("A - %i/%i\nB - %i/%i\n", stack_a.size, stack_a.max, stack_b.size, stack_b.max);
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
	printf("A - %i/%i\nB - %i/%i\n", stack_a.size, stack_a.max, stack_b.size, stack_b.max); */
	return (0);
}
