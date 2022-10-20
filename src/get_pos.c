#include "push_swap.h"

void	get_pos(int *tab, int *pos, int search)
{
	*pos = 0;
	while (tab[*pos] != search)
		(*pos)++;
}