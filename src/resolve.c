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

static void	print_solution(t_node *current)
{
	while (current)
	{
		if (current->data == sa)
			ft_putstr_fd(1, "sa\n");
		else if (current->data == sb)
			ft_putstr_fd(1, "sb\n");
		else if (current->data == ss)
			ft_putstr_fd(1, "ss\n");
		else if (current->data == pa)
			ft_putstr_fd(1, "pa\n");
		else if (current->data == pb)
			ft_putstr_fd(1, "pb\n");
		else if (current->data == ra)
			ft_putstr_fd(1, "ra\n");
		else if (current->data == rb)
			ft_putstr_fd(1, "rb\n");
		else if (current->data == rr)
			ft_putstr_fd(1, "rr\n");
		else if (current->data == rra)
			ft_putstr_fd(1, "rra\n");
		else if (current->data == rrb)
			ft_putstr_fd(1, "rrb\n");
		else if (current->data == rrr)
			ft_putstr_fd(1, "rrr\n");

		current = current->next;
	}
}

static void	search_max(t_data *data, int len)
{
	int	i;
	int	max;
	int rrb;

	i = 1;
	rrb = 0;
	max = data->stack_b[0];
	while (i < len)
	{
		if (data->stack_b[i] > max)
			max = data->stack_b[i];
		i++;
	}
	while (data->stack_b[data->len_stack_b - 1] != max)
	{
		push_front(&data->instruct, rb);
		rotate_rb(data);
		rrb++;
	}
	printf("rrb => %d\n", rrb);
	push_front(&data->instruct, pa);
	push_pa(data);
	/*while(rrb--)
	{
		push_front(&data->instruct, rrb);
		reverse_rrb(data);
	}*/
}

static int	pivoting(int pivot, t_data *data)
{
	int i;
	int res;
	int max_len;

	i = 0;
	res = 0;
	max_len = data->len_stack_a;
	while (i < max_len)
	{
		if (data->stack_a[data->len_stack_a - 1] < pivot)
		{
			push_front(&data->instruct, pb);
			push_pb(data);
			res++;
		}
		else
		{
			push_front(&data->instruct, ra);
			rotate_ra(data);
		}
		i++;
	}
	return (res);
}

static void	quicksort(t_data *data)
{

	t_min_max	min_max_a;
	t_min_max	min_max_b;
	int			res;

	set_min_max(&min_max_a, data->stack_a, data->len_stack_a);
	set_min_max(&min_max_b, data->stack_b, data->len_stack_b);
	printf("pivot => %d\n", min_max_a.pivot);
	res = pivoting(min_max_a.pivot, data);
	if (res < 3)
		return ;
	quicksort(data);
	while (data->len_stack_b)
		search_max(data, data->len_stack_b);
	//print_array(data);
}

int	resolve(t_data *data)
{
	quicksort(data);

	print_solution(data->instruct);
	//print_array(data);
	return (0);
}
