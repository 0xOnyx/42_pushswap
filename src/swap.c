/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:00:30 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/14 23:00:31 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa(t_data *data)
{
	int	tmp;

	if (data->len_stack_a < 2)
		return ;
	tmp = data->stack_a[data->len_stack_a - 1];
	data->stack_a[data->len_stack_a - 1] = data->stack_a[data->len_stack_a - 2];
	data->stack_a[data->len_stack_a - 2] = tmp;
}

void	swap_sb(t_data *data)
{
	int	tmp;

	if (data->len_stack_b < 2)
		return ;
	tmp = data->stack_b[data->len_stack_b - 1];
	data->stack_b[data->len_stack_b - 1] = data->stack_b[data->len_stack_b - 2];
	data->stack_b[data->len_stack_b - 2] = tmp;
}

void	swap_ss(t_data *data)
{
	swap_sa(data);
	swap_sb(data);
}
