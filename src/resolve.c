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
#include <stdio.h>
static int set_sort_pivot(int pivot, t_data *data, int *len_stack, int *stack)
{
	int	i;
	int	res;
	int	ra_c;

	i = 0;
	ra_c = 0;
	res = 0;
	while (i <= *len_stack)
	{
		if (stack[*len_stack - 1] <= pivot)
		{
			if (stack == data->stack_a)
			{
				push_front(&data->instruct, pb);
				push_pb(data);
				res++;
			}
		}
		else
		{
			if (stack == data->stack_a)
			{
				push_front(&data->instruct, ra);
				rotate_ra(data);
				ra_c++;
				res++;
			}
		}
		i++;
	}
	while (ra_c--)
	{
		push_front(&data->instruct, rra);
		reverse_rra(data);
	}
	return (res);
}

static int quicksort(t_data *data)
{
	t_min_max	min_max_a;
	t_min_max	min_max_b;
	int 		len;

	set_min_max(&min_max_a, data->stack_a, data->len_stack_a);
	set_min_max(&min_max_b, data->stack_b, data->len_stack_b);
	//printf("value min => %d max => %d pivot => %d\n", min_max_a.min, min_max_a.max, min_max_a.pivot);
	len = set_sort_pivot(min_max_a.pivot, data, &data->len_stack_a, data->stack_a);
	//len = set_sort_pivot(min_max_b.pivot, data, &data->len_stack_b, data->stack_b);
	if (data->len_stack_a == 0)
		return (0);
	//print_array(data);
	quicksort(data);
	return (len);
}

int	resolve(t_data *data)
{
	t_node	*current;

	quicksort(data);
	current = data->instruct;
	while (current)
	{
		if (current->data == pb)
			ft_putstr_fd(1, "pb\n");
		else if (current->data == ra)
			ft_putstr_fd(1, "ra\n");
		else if (current->data == rra)
			ft_putstr_fd(1, "rra\n");
		current = current->next;
	}
	return (0);
}
