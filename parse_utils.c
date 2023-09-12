#include "push_swap.h"

int split_size(char **split)
{
    int size;

    size = 0;
    while (split[size] != NULL)
        size++;
    return (size + 1);
}

int check_parameters(int *argc, char ***argv)
{
    if (*argc < 2)
	{
		printf("NO PARAMETERS!\n");
		return (1);
	}
	else if (*argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		if (*argv == NULL)
			return (1);
		*argc = split_size(*argv);
	}
	else
	{
		(*argv)++;
	}
    return (0);
}