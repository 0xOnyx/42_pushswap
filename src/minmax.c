#include "push_swap.h"

static int	get_min(int *tab, int len)
{
	int	min;
	int i;

	i = 0;
	min = tab[i];
	while (i < len)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

static int	get_max(int *tab, int len)
{
	int	max;
	int i;

	i = 0;
	max = tab[i];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

void	set_min_max(t_min_max *min_max, int *tab, int len)
{
	min_max->min = get_min(tab, len);
	min_max->max = get_max(tab, len);
	min_max->pivot = min_max->max - min_max->min;
}