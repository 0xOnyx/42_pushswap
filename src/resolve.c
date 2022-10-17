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
static int set_sort_pivot(int pivot, t_data *data, int len_stack, int *stack)
{
	int	i;
	int	res;
	int	ra_c;

	i = 0;
	ra_c = 0;
	res = 0;
	while (i < len_stack)
	{
		//printf("%d pivot => %d value => %d\n",i ,  pivot, stack[data->len_stack_a - 1]);
		if (stack[data->len_stack_a - 1] < pivot)
		{
			if (stack == data->stack_a)
			{
			//	printf("push %d to b \n", stack[data->len_stack_a - 1]);
				push_front(&data->instruct, pb);
				push_pb(data);
				res++;
			}
		}
		else
		{
			if (stack == data->stack_a)
			{
			//	printf("NOT PUSH => %d %d\n", pivot, stack[data->len_stack_a - 1]);
				push_front(&data->instruct, ra);
				rotate_ra(data);
				ra_c++;
			}
		}
		i++;
	}
	return (res);
}

static int	search_max(t_data *data, int len)
{
	int	i;
	int	rrb;
	int max_last;

	while (len > 0)
	{
		i = 0;
		rrb = 0;
		max_last = data->stack_b[data->len_stack_a - 1];
		while (i < len)
		{
			if (data->stack_b[data->len_stack_b - i -1] > max_last)
				max_last = data->stack_b[data->len_stack_b - i -1];
			i++;
		}
		i = 0;
		while (data->stack_b[data->len_stack_b - i - 1] != max_last)
		{
		//	printf("current => %d\n",data->stack_b[data->len_stack_b - i - 1] );
			push_front(&data->instruct, rb);
			rotate_rb(data);
			rrb++;
		}
		push_front(&data->instruct, pa);
		push_pa(data);
		//printf("res => %d\n", rrb);
		while (rrb-- > 0)
		{
			//printf("value rrb => %d\n", rrb);
			push_front(&data->instruct, rrb);
			reverse_rrb(data);
		}
		len--;
	}
	return (max_last);
}

static void	print_solution(t_node *current)
{
	while (current)
	{
		//if (current->data == sa)
		//	ft_putstr_fd(1, "sa\n");
		if (current->data == sb)
			ft_putstr_fd(1, "sb\n");
		//else if (current->data == ss)
		//	ft_putstr_fd(1, "ss\n");
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

static int quicksort(t_data *data)
{
	t_min_max	min_max_a;
	t_min_max	min_max_b;
	int 		len;

	set_min_max(&min_max_a, data->stack_a, data->len_stack_a);
	set_min_max(&min_max_b, data->stack_b, data->len_stack_b);
	//printf("min => %d max => %d pivot => %d\n", min_max_a.min, min_max_a.max, min_max_a.pivot);
	len = set_sort_pivot(min_max_a.pivot, data, data->len_stack_a, data->stack_a);
	//printf("value res => %d\n", len);
	if (len == 0)
	{
		if (data->stack_a[1] > data->stack_a[0])
		{
	//		push_front(&data->instruct, rra);
	//		reverse_rra(data);
		}
		return (0);
	}
	quicksort(data);
//	print_array(data);
	len = search_max(data, len);
	//printf("max => %d\n", len);
//	print_array(data);
	static int test;
	test++;
	if (test == 3)
	{
		print_solution(data->instruct);
		exit(0);
	}
	return (len);
}

int	resolve(t_data *data)
{

//	print_array(data);
	quicksort(data);
	print_solution(data->instruct);

	//print_array(data);
	return (0);
}
