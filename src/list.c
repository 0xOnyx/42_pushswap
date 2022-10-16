#include "push_swap.h"

static t_node *create_node(t_list list)
{
	t_node	*current;

	if (ft_calloc((void *)&current, sizeof(t_node), 1))
		return (NULL);
	current->data = list;
	current->next = NULL;
	return (current);
}

int	push_front(t_node **node, t_list list)
{
	t_node	*current;
	t_node	*new_node;

	current = *node;
	new_node = create_node(list);
	if (*node == NULL)
		return (1);
	if (current == NULL)
	{
		*node = new_node;
		return (0);
	}
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (1);
}