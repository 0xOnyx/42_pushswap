/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:44:06 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/14 22:44:08 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int set_sort_pivot(int pivot, t_data *data, int *len_stack, int *stack)
{
	int	i;

	i = 0;

	while (i < data->max_len)
	{
		if (stack[i] < pivot)
		{
			if (stack == data->stack_a)
				push_pa(data);
		}
		else
		{
			if (stack == data->stack_b)
				push_pb(data);
		}

	}
	return (i);
}

static int quicksort(t_data *data)
{
	t_min_max	min_max_a;
	t_min_max	min_max_b;
	int 		len;

	set_min_max(&min_max_a, data->stack_a, data->len_stack_a);
	set_min_max(&min_max_b, data->stack_b, data->len_stack_b);
	len = set_sort_pivot(min_max_a.pivot, data, &data->len_stack_a, data->stack_a);
	len = set_sort_pivot(min_max_b.pivot, data, &data->len_stack_b, data->stack_b);
	quicksort(data);
	print_array(data);
	return (len);
}

int	resolve(t_data *data)
{
	quicksort(data);
	return (0);
}


3

2