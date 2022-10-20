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

static void	print_solution(t_node *current)
{
	while (current)
	{
		if (current->data == sa)
			ft_putstr_fd(1, "sa\n");
		else if (current->data == sb)
			ft_putstr_fd(1, "sb\n");
		else if (current->data == pa)
			ft_putstr_fd(1, s"pa\n");
		else if (current->data == pb)
			ft_putstr_fd(1, "pb\n");
		else if (current->data == ra)
			ft_putstr_fd(1, "ra\n");
		else if (current->data == rb)
			ft_putstr_fd(1, "rb\n");
		else if (current->data == rra)
			ft_putstr_fd(1, "rra\n");
		else if (current->data == rrb)
			ft_putstr_fd(1, "rrb\n");
		current = current->next;
	}
}

static void	raddix(t_data *data, int chift)
{
	int len;

	if (chift >= data->len_bits)
		return ;
	len = data->len_stack_a;
	while (--len >= 0)
	{
		if ((data->stack_a[data->len_stack_a - 1] >> chift)&1)
		{
			rotate_ra(data);
			push_front(&data->instruct, ra);
		}
		else
		{
			push_pb(data);
			push_front(&data->instruct, pb);
		}
	}
	while (data->len_stack_b)
	{
		push_pa(data);
		push_front(&data->instruct, pa);
	}
	raddix(data, chift + 1);
}

static void	short_solve(t_data *data)
{
	struct	s_min_max val;
	struct	s_min_max pos;

	val.min = get_min(data->stack_a, data->len_stack_a);
	val.max = get_max(data->stack_a, data->len_stack_a);
	val.pivot = get_mid(data->stack_a, data->len_stack_a, val.min, val.max);
	pos.min = 0;
	while (data->stack_a[pos.min] != val.min)
		pos.min++;
	pos.max = 0;
	while (data->stack_a[pos.max] != val.max)
		pos.max++;
	pos.pivot = 0;
	while (data->stack_a[pos.pivot] != val.pivot)
		pos.pivot++;
	if (pos.min == 1 && pos.max == 0 && pos.pivot == 2)
	{
		swap_sa(data);
		push_front(&data->instruct, sa);
	}
	else if (pos.min == 1 && pos.max == 2 && pos.pivot == 0)
	{
		rotate_ra(data);
		push_front(&data->instruct, ra);
	}
	else if (pos.min == 0 && pos.max == 1 && pos.pivot == 2)
	{
		reverse_rra(data);
		push_front(&data->instruct, rra);
	}
	else if (pos.min == 0 && pos.max == 2 && pos.pivot == 1)
	{
		swap_sa(data);
		reverse_rra(data);
		push_front(&data->instruct, sa);
		push_front(&data->instruct, rra);
	}
	else if (pos.min == 2 && pos.max == 1 && pos.pivot == 0)
	{
		swap_sa(data);
		rotate_ra(data);
		push_front(&data->instruct, sa);
		push_front(&data->instruct, ra);
	}
}

static void	very_short_solve(t_data *data)
{
	if (data->len_stack_a == 2 && data->stack_a[1] > data->stack_a[0])
	{
		rotate_ra(data);
		push_front(&data->instruct, ra);
	}
	if (data->len_stack_b == 2 && data->stack_b[1] > data->stack_b[0])
	{
		rotate_rb(data);
		push_front(&data->instruct, rb);
	}
}

static void middle_solve(t_data *data)
{
	int			i;
	int			final;

	while (data->len_stack_a > 1)
	{
		i = 0;
		final = 0;
		while (i < data->len_stack_a)
		{
			if (data->stack_a[i] < data->stack_a[final])
				final = i;
			i++;
		}
		final = data->len_stack_a -1 - final;
		while (final--)
		{
			rotate_ra(data);
			push_front(&data->instruct, ra);
		}
		push_pb(data);
		push_front(&data->instruct, pb);
	}
	while (data->len_stack_a < data->max_len)
	{
		push_pa(data);
		push_front(&data->instruct, pa);
	}
}

int	resolve(t_data *data)
{
	if (data->max_len == 2)
		very_short_solve(data);
	else if (data->max_len == 3)
		short_solve(data);
	else if (data->max_len == 5)
		middle_solve(data);
	else
		raddix(data, 0);
	print_solution(data->instruct);
	return (0);
}
