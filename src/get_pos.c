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
