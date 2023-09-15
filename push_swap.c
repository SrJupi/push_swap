#include "push_swap.h"
#include <stdio.h>

static void	free_split(char **r, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(r[j]);
		j++;
	}
	free(r);
}

static void	do_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else
		sort_big(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		split;

	split = 0;
	if (check_parameters(&argc, &argv, &split))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (create_stack(&stack_a, argc - 1, argv))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	create_stack(&stack_b, argc - 1, NULL);
	do_push_swap(&stack_a, &stack_b);
	clean_stack(&stack_a);
	clean_stack(&stack_b);
	if (split)
		free_split(argv, argc);
	exit(EXIT_SUCCESS);
	return (0);
}
