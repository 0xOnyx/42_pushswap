/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:02:11 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/14 23:02:12 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rra(t_data *data)
{
	int	i;
	int	first;

	if (data->len_stack_a < 2)
		return ;
	first = data->stack_a[0];
	i = 0;
	while (i < data->len_stack_a - 1)
	{
		data->stack_a[i] = data->stack_a[i + 1];
		i++;
	}
	data->stack_a[i] = first;
}

void	reverse_rrb(t_data *data)
{
	int	i;
	int	first;

	if (data->len_stack_b < 2)
		return ;
	first = data->stack_b[0];
	i = 0;
	while (i < data->len_stack_b - 1)
	{
		data->stack_b[i] = data->stack_b[i + 1];
		i++;
	}
	data->stack_b[i] = first;
}

void	reverse_rrr(t_data *data)
{
	reverse_rra(data);
	reverse_rrb(data);
}
