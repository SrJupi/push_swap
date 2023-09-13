#include<stdio.h>
#include "push_swap.h"


int get_r_or_rr(int counter, int size)
{
    if (counter > size/2)
        return (counter - size);
    return (counter);
}

void get_distance_max(t_item *head, t_stack *stack_b)
{
   // ft_putstr_fd("get_distance_max...\n", 1);

    int j;
    t_item *og_head;

    j = 0;
    og_head = stack_b->head;
    while(j < stack_b->size)
    {
        if (stack_b->head->value == stack_b->max)
            head->other_moves = get_r_or_rr(j, stack_b->size);
        j++;
        stack_b->head = stack_b->head->next;
        if (stack_b->head == og_head)
            break ;
    }
}

void get_distance_normal(t_item *head, t_stack *stack_b, long tmp, long closest)
{
    //ft_putstr_fd("get_distance_normal...\n", 1);

    int j;
    t_item *og_head;

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

void get_distance(t_item *head)
{
 //   ft_putstr_fd("get_distance...\n", 1);
    int mine;
    int other;
    
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

void get_moves(t_stack *stack_a, t_stack *stack_b)
{
//  ft_putstr_fd("moves...\n", 1);
  long      closest;
  long      tmp;
  int       i;
  t_item    *og_head;

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
    rotate_stack(stack_a);
    if (stack_a->head == og_head)
        break ;
  }
}

/* int get_max(int mine, int other)
{
    if (mine >= other)
        return mine;
    return other;
}

int get_min(int mine, int other)
{
    if (mine >= other)
        return other * -1;
    return mine * -1;
}

int get_distance(int mine, int other)
{
    if (mine < 0)
        mine *= -1;
    else
        other *= -1;
    return (mine + other);
} */

t_item  *find_shortest(t_stack *stack)
{
    int shortest = INT_MAX;
    t_item *short_item;
    int i;

    short_item = NULL;
    i = 0;
    while (i < stack->size)
    {
        if (stack->head->distance < shortest)
        {
            short_item = stack->head;
            shortest = stack->head->distance;
        }
        rotate_stack(stack);
        i++;
    }
    return (short_item); 
}

void move_shortest(t_stack *stack_a, t_stack *stack_b)
{
//    ft_putstr_fd("move shortest...\n", 1);
    t_item  *item_to_send;

    print_stack(stack_a);
    print_stack(stack_b);
    ft_putnbr_fd(stack_b->head->value, 1);
    ft_putchar_fd('\n', 1);
    item_to_send = find_shortest(stack_a);
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
}

void get_max_to_top(t_stack *stack)
{
    int i;
    t_item  *og_head;
    
    i = 0;
    og_head = stack->head;
    ft_putstr_fd("head: ",1);
    ft_putnbr_fd(stack->head->value, 1);
    ft_putchar_fd('\n', 1);
    while (i < stack->size)
    {
        if (stack->head->value == stack->max)
            break ;
        i++;
        stack->head = stack->head->next;
    }
    stack->head = og_head;
    i = get_r_or_rr(i, stack->size);
    ft_putnbr_fd(i, 1);
    ft_putchar_fd('\n', 1);

    ft_putstr_fd("head: ",1);
    ft_putnbr_fd(stack->head->value, 1);
    ft_putchar_fd('\n', 1);

    ft_putstr_fd("prev: ",1);
    ft_putnbr_fd(stack->head->prev->value, 1);
    ft_putchar_fd('\n', 1);

    ft_putstr_fd("next: ",1);
    ft_putnbr_fd(stack->head->next->value, 1);
    ft_putchar_fd('\n', 1);

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