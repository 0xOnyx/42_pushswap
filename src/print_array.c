#include "push_swap.h"

#include <stdio.h>

void print_bin(int a)
{
	int i;

	i = 4;
	while(i >= 0)
	{
		printf("%c", (a >> i)& 1 ? '1' : '0');
		i--;
	}
}

void	print_array(t_data *data)
{
	int	i;

	i = data->max_len;
	while (--i >= 0)
	{
		print_bin(data->stack_a[i]);
		printf("\t%d", data->stack_a[i]);
		printf("|");
		printf("%d\t", data->stack_b[i]);
		print_bin(data->stack_b[i]);
		printf("\n");
	}
	printf(" A_\t| B_\n\n");
}
