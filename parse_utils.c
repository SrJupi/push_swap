#include "push_swap.h"

int	split_size(char **split)
{
	int	size;

	size = 0;
	while (split[size] != NULL)
		size++;
	return (size + 1);
}

int	check_parameters(int *argc, char ***argv, int *split)
{
	if (*argc < 2)
		return (1);
	else if (*argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		if (*argv == NULL)
			return (1);
		*argc = split_size(*argv);
		*split = 1;
	}
	else
	{
		(*argv)++;
	}
	return (0);
}