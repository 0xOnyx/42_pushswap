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

static int set_sort_pivot(int pivot, t_data *data, int len_stack, int *stack)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < len_stack)
	{
		if (stack[i] < pivot)
		{
			if (stack == data->stack_a)
			{
				push_front(&data->instruct, pa);
				push_pa(data);
				res++;
			}
		}
		else
		{
			if (stack == data->stack_a)
			{
				push_front(&data->instruct, ra);
				rotate_ra(data);
				res++;
			}
		}
		i++;
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
	len = set_sort_pivot(min_max_a.pivot, data, data->len_stack_a, data->stack_a);
	//len = set_sort_pivot(min_max_b.pivot, data, &data->len_stack_b, data->stack_b);
	if (len > 0)
		return (0);
	print_array(data);
	return (len);
}

int	resolve(t_data *data)
{
	t_node	*current;

	quicksort(data);
	current = data->instruct;
	while (current)
	{
		if (current->data == pa)
			ft_putstr_fd(1, "pa\n");
		current = current->next;
	}
	return (0);
}
