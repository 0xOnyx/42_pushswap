/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:43:41 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/14 23:00:40 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static void	safe_clean(t_data data)
{
	if (!data.stack_a)
		free(data.stack_a);
	if (!data.stack_b)
		free(data.stack_b);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.max_len = 0;
	data.len_stack_a = 0;
	data.len_stack_b = 0;
	data.stack_a = NULL;
	data.stack_b = NULL;
	data.instruct = NULL;
	if (argc < 2
		|| init_resolve(argc - 1, argv + 1, &data)
		|| valid_argv(data)
		|| resolve(&data))
	{
		safe_clean(data);
		ft_putstr_fd(2, "Error\n");
		return (1);
	}
	safe_clean(data);
	return (0);
}
