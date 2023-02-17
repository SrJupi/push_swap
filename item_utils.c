#include "push_swap.h"
#include <stdio.h>

void	clean_item(t_item **item)
{
	printf("\n~~~~Cleaning Item - %i ~~~~\n", (*item)->value);
	free(*item);
	*item = NULL;
}

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	item_atoi(int *item_value, char *str)
{
	long	neg;
	long	tmp;

	*item_value = 0;
	neg = 1;
	if (!ft_isdigit(*str) && *str != '-')
		return (1);
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		tmp = tmp * 10 + ((*str - '0') * neg);
		str++;
	}
	if (tmp >= INT_MAX || tmp <= INT_MIN)
		return (1);
	*item_value = (int)tmp;
	return (0);
}

t_item	*create_item(char *str)
{
	t_item	*new_item;

	printf("Creating item with str: %s\n", str);
	new_item = (t_item *) malloc (sizeof(t_item));
	if (new_item != NULL)
	{
		new_item->prev = new_item;
		new_item->next = new_item;
		if (item_atoi(&(new_item->value), str))
			clean_item(&new_item);
	}
	return (new_item);
}
