#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>

typedef struct t_item
{
	int				value;
	struct t_item	*prev;
	struct t_item	*next;
}	t_item;

typedef struct t_stack
{
	int				size;
	int				max;
	struct t_item	*head;
}	t_stack;

//Stack utils
int		create_stack(t_stack *stack, int argc, char **argv);
int		insert_item(t_item *new_item, t_stack *stack);
t_item	*remove_item(t_stack *stack);

//Item utils
t_item	*create_item(char *str);
void	clean_item(t_item **item);
#endif
