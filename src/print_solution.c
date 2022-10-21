/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:45:44 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/21 14:45:45 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_solution(t_node *current)
{
	while (current)
	{
		if (current->data == sa)
			ft_putstr_fd(1, "sa\n");
		else if (current->data == sb)
			ft_putstr_fd(1, "sb\n");
		else if (current->data == pa)
			ft_putstr_fd(1, "pa\n");
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
