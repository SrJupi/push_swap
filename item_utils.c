/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:15:31 by lsulzbac          #+#    #+#             */
/*   Updated: 2023/09/15 14:16:31 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_item(t_item **item)
{
	free(*item);
	*item = NULL;
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r'
		|| c == '\n')
		return (1);
	return (0);
}

static int	item_cmp(int item_value, char *str)
{
	char	*value_itoa;
	int		size_itoa;
	int		size_str;
	int		cmp;

	value_itoa = ft_itoa(item_value);
	if (value_itoa == NULL)
		return (1);
	while (ft_isspace(*str))
		str++;
	size_itoa = ft_strlen(value_itoa);
	size_str = ft_strlen(str);
	if (size_itoa >= size_str)
		cmp = ft_strncmp(str, value_itoa, size_itoa);
	else
		cmp = ft_strncmp(str, value_itoa, size_str);
	free(value_itoa);
	return (cmp);
}

t_item	*create_item(char *str)
{
	t_item	*new_item;

	new_item = (t_item *)malloc(sizeof(t_item));
	if (new_item != NULL)
	{
		new_item->prev = new_item;
		new_item->next = new_item;
		new_item->value = ft_atoi(str);
		if (item_cmp(new_item->value, str))
			clean_item(&new_item);
	}
	return (new_item);
}
