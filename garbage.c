#include "push_swap.h"
#include <stdio.h>

int	get_r_or_rr(int counter, int size)
{
	if (counter > size / 2)
		return (counter - size);
	return (counter);
}

void	get_distance_max(t_item *head, t_stack *stack_b)
{
	int		j;
	t_item	*og_head;

	j = 0;
	og_head = stack_b->head;
	while (1)
	{
		if (stack_b->head->value == stack_b->max)
			head->other_moves = get_r_or_rr(j, stack_b->size);
		j++;
		stack_b->head = stack_b->head->next;
		if (stack_b->head == og_head)
			break ;
	}
}

void	get_distance_normal(t_item *head, t_stack *stack_b, long tmp,
		long closest)
{
	int		j;
	t_item	*og_head;

	j = 0;
	og_head = stack_b->head;
	while (1)
	{
		if (stack_b->head->value < head->value)
		{
			tmp = head->value - stack_b->head->value;
			if (tmp < closest)
			{
				closest = tmp;
				head->other_moves = get_r_or_rr(j, stack_b->size);
			}
		}
		j++;
		stack_b->head = stack_b->head->next;
		if (stack_b->head == og_head)
			break ;
	}
}

void	get_distance(t_item *head)
{
	int	mine;
	int	other;

	mine = head->my_moves;
	other = head->other_moves;
	if (mine * other >= 0)
	{
		if (ft_abs(mine) > ft_abs(other))
			head->distance = ft_abs(mine);
		else
			head->distance = ft_abs(other);
	}
	else
	{
		head->distance = ft_abs(mine) + ft_abs(other);
	}
}

void	get_shortest(t_stack *stack)
{
	if (stack->shortest == NULL)
		stack->shortest = stack->head;
	else
	{
		if (stack->head->distance < stack->shortest->distance)
			stack->shortest = stack->head;
	}
}

void	get_moves(t_stack *stack_a, t_stack *stack_b)
{
	long	closest;
	long	tmp;
	int		i;
	t_item	*og_head;

	i = 0;
	og_head = stack_a->head;
	while (1)
	{
		stack_a->head->my_moves = get_r_or_rr(i, stack_a->size);
		closest = LONG_MAX;
		if (stack_a->head->value < stack_b->min)
			get_distance_max(stack_a->head, stack_b);
		else
			get_distance_normal(stack_a->head, stack_b, tmp, closest);
		i++;
		get_distance(stack_a->head);
		get_shortest(stack_a);
		rotate_stack(stack_a);
		if (stack_a->head == og_head)
			break ;
	}
}

void	move_shortest(t_stack *stack_a, t_stack *stack_b)
{
	t_item *item_to_send;

	item_to_send = stack_a->shortest;
	while (item_to_send->my_moves > 0 && item_to_send->other_moves > 0)
	{
		rr(stack_a, stack_b);
		item_to_send->my_moves--;
		item_to_send->other_moves--;
	}
	while (item_to_send->my_moves > 0)
	{
		ra(stack_a);
		item_to_send->my_moves--;
	}
	while (item_to_send->other_moves > 0)
	{
		rb(stack_b);
		item_to_send->other_moves--;
	}
	while (item_to_send->my_moves < 0 && item_to_send->other_moves < 0)
	{
		rrr(stack_a, stack_b);
		item_to_send->my_moves++;
		item_to_send->other_moves++;
	}
	while (item_to_send->my_moves < 0)
	{
		rra(stack_a);
		item_to_send->my_moves++;
	}
	while (item_to_send->other_moves < 0)
	{
		rrb(stack_b);
		item_to_send->other_moves++;
	}
	pb(stack_a, stack_b);
	stack_a->shortest = NULL;
}

void	get_max_to_top(t_stack *stack)
{
	int i;
	t_item *og_head;

	i = 0;
	og_head = stack->head;
	while (1)
	{
		if (stack->head->value == stack->max)
			break ;
		i++;
		stack->head = stack->head->next;
		if (stack->head == og_head)
			break ;
	}
	stack->head = og_head;
	i = get_r_or_rr(i, stack->size);
	while (i < 0)
	{
		rrb(stack);
		i++;
	}
	while (i > 0)
	{
		rb(stack);
		i--;
	}
}