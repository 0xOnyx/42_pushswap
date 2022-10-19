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

static void	raddix(t_data *data, int chift)
{
	int len;

	if (chift == 8)
		return ;

	//print_array(data);
	len = data->len_stack_a;

	while (--len > 0)
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

int	resolve(t_data *data)
{
	raddix(data, 0);
	print_solution(data->instruct);
	return (0);
}
