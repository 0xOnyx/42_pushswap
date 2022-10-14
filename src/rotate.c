/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:02:04 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/14 23:02:05 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ra(t_data *data)
{
	int	i;
	int	tmp;
	int	current_tmp;

	if (data->len_stack_a < 2)
		return ;
	i = 0;
	tmp = data->stack_a[data->len_stack_a - 1];
	while (i < data->len_stack_a)
	{
		current_tmp = data->stack_a[i];
		data->stack_a[i] = tmp;
		tmp = current_tmp;
		i++;
	}
}

void	rotate_rb(t_data *data)
{
	int	i;
	int	tmp;
	int	current_tmp;

	if (data->len_stack_b < 2)
		return ;
	i = 0;
	tmp = data->stack_b[data->len_stack_b - 1];
	while (i < data->len_stack_b)
	{
		current_tmp = data->stack_b[i];
		data->stack_b[i] = tmp;
		tmp = current_tmp;
		i++;
	}
}

void	rotate_rr(t_data *data)
{
	rotate_ra(data);
	rotate_rb(data);
}
