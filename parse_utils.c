/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:13:49 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 14:14:07 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
