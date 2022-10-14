/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:01:18 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/14 23:01:19 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_pa(t_data *data)
{
	if (data->len_stack_b == 0)
		return ;
	data->len_stack_a++;
	data->stack_a[data->len_stack_a - 1] = data->stack_b[data->len_stack_b - 1];
	data->stack_b[data->len_stack_b - 1] = 0;
	data->len_stack_b--;
}

void	push_pb(t_data *data)
{
	if (data->len_stack_a == 0)
		return ;
	data->len_stack_b++;
	data->stack_b[data->len_stack_b - 1] = data->stack_a[data->len_stack_a - 1];
	data->stack_a[data->len_stack_a - 1] = 0;
	data->len_stack_a--;
}
