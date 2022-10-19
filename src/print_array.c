#include "push_swap.h"

#include <stdio.h>

void	print_array(t_data *data)
{
	int i;

	i = data->max_len;
	while (--i >= 0)
	{
		printf(" %d\t| %d\n",
			   data->stack_a[i] > 0 ? data->stack_a[i]: 0,
			   data->stack_b[i] > 0 ? data->stack_b[i]: 0);
	}
	printf(" A_\t| B_\n\n");
}
