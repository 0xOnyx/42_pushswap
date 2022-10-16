#include "push_swap.h"

#include <stdio.h>

void	print_array(t_data *data)
{
	int i;

	i = 0;
	while (i < data->max_len)
	{
		printf(" %d\t| %d\n",
			   data->stack_a[i] > 0 ? data->stack_a[i]: 0,
			   data->stack_b[i] > 0 ? data->stack_b[i]: 0);
		i++;
	}
	printf(" A_\t| B_\n");
}
