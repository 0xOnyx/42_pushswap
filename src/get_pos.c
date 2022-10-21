/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:46:45 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/21 14:46:46 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pos(int *tab, int *pos, int search)
{
	*pos = 0;
	while (tab[*pos] != search)
		(*pos)++;
}

void	hard_code_short_solve1(t_data *data, struct s_min_max pos)
{
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
}

void	hard_code_short_solve2(t_data *data, struct s_min_max pos)
{
	if (pos.min == 0 && pos.max == 2 && pos.pivot == 1)
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

void	hard_code_sort_five(t_data	*data)
{
	int	i;

	i = 2;
	while (i--)
	{
		reverse_rra(data);
		push_front(&data->instruct, rra);
		push_pb(data);
		push_front(&data->instruct, pb);
	}
	short_solve(data);
	push_pa(data);
	push_front(&data->instruct, pa);
	push_pa(data);
	push_front(&data->instruct, pa);
}

void	up_two_first_elem(t_data *data)
{
	int			i;
	int			final;

	while (data->len_stack_b < 2)
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
}
