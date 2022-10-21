/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:44:06 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/21 14:46:00 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	raddix(t_data *data, int chift)
{
	int	len;

	if (chift >= data->len_bits)
		return ;
	len = data->len_stack_a;
	while (--len >= 0)
	{
		if ((data->stack_a[data->len_stack_a - 1] >> chift) & 1)
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

void	short_solve(t_data *data)
{
	struct s_min_max	val;
	struct s_min_max	pos;

	val.min = get_min(data->stack_a, data->len_stack_a);
	val.max = get_max(data->stack_a, data->len_stack_a);
	val.pivot = get_mid(data->stack_a, data->len_stack_a, val.min, val.max);
	get_pos(data->stack_a, &pos.min, val.min);
	get_pos(data->stack_a, &pos.max, val.max);
	get_pos(data->stack_a, &pos.pivot, val.pivot);
	hard_code_short_solve1(data, pos);
	hard_code_short_solve2(data, pos);
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

static void	middle_solve(t_data *data)
{
	if (data->stack_a[0] < data->stack_a[1]
		&& data->stack_a[1] < data->stack_a[2]
		&& data->stack_a[2] < data->stack_a[3]
		&& data->stack_a[3] < data->stack_a[4])
		return (hard_code_sort_five(data));
	up_two_first_elem(data);
	short_solve(data);
	push_pa(data);
	push_front(&data->instruct, pa);
	push_pa(data);
	push_front(&data->instruct, pa);
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
