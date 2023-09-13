#include<stdio.h>
#include "push_swap.h"


int get_moves(t_stack *stack_a, t_stack *stack_b)
{
  long      closest;
  long      tmp;
  int       i;
  int       j;

  stack_a->tmp = stack_a->head;
  stack_b->tmp = stack_b->head;
  i = 0;

  while (stack_a->head->next != stack_a->tmp)
  {
    stack_a->head->my_moves = i;
    closest = LONG_MAX;
    j = 0;
    if (stack_a->head->value < stack_b->min)
        get_distance_max(stack_a->head, stack_b);
    else
    {
        while (stack_b->head->next != stack_b->tmp)
        {
            if (stack_b->head->value < stack_a->head->value)
            {
                tmp = stack_b->head->value - stack_a->head->value;
                if (tmp < closest)
                {
                    closest = tmp;
                    stack_a->head->other_moves = j;
                }
            }
            j++;
        }
    }
    i++;
  }
}

int get_max(int mine, int other)
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
}


void get_distances(num *stack_a)
{
    int mine;
    int other;
    int distance = 0;
    
    for (int i = 0; i < 5; i++)
    {
        mine = stack_a[i].my_moves;
        other = stack_a[i].other_moves;
        if (mine >= 0 && other >= 0)
        {
            distance = get_max(mine, other);
        }
        else if (mine <= 0 && other <= 0)
        {
            distance = get_min(mine, other);
        }
        else
        {
            distance = get_distance(mine, other);
        }
        stack_a[i].distance = distance;
    }
    
}

int calculate_distance(num *stack_a, num *stack_b)
{
  get_moves(stack_a, stack_b);
  get_distances(stack_a);
}

void move_shortest(num *stack)
{
    int shortest = INT_MAX;
    int short_i;
    for (int i = 0; i < 5; i++)
    {
        printf("pos: %d - value: %d - distance: %d - shortest: %d\n", i, stack[i].value, stack[i].distance, shortest);
        if (stack[i].distance < shortest)
        {
            short_i = i;
            shortest = stack[i].distance;
        }
    }
    while (stack[shortest].my_moves > 0 && stack[shortest].other_moves > 0)
    {
        printf("rr\n");
        stack[shortest].my_moves--;
        stack[shortest].other_moves--;
    }
    while (stack[shortest].my_moves > 0)
    {
        printf("ra\n");
        stack[shortest].my_moves--;
    }
    while (stack[shortest].other_moves > 0)
    {
        printf("rb\n");
        stack[shortest].other_moves--;
    }
    while (stack[shortest].my_moves < 0 && stack[shortest].other_moves < 0)
    {
        printf("rrr\n");
        stack[shortest].my_moves++;
        stack[shortest].other_moves++;
    }
    while (stack[shortest].my_moves < 0)
    {
        printf("rra\n");
        stack[shortest].my_moves++;
    }
    while (stack[shortest].other_moves < 0)
    {
        printf("rrb\n");
        stack[shortest].other_moves++;
    }
    printf("pb\n");
}