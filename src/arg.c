/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:43:05 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/14 22:43:19 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	init_resolve(int argc, char **argv, t_data *data)
{
	int	i;
	int	tab_i;

	data->max_len = argc;
	data->len_stack_a = data->max_len;
	if (ft_calloc((void **)&data->stack_a, sizeof(int), data->max_len)
		|| ft_calloc((void **)&data->stack_b, sizeof(int), data->max_len))
		return (1);
	i = 0;
	tab_i = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		data->stack_a[data->max_len - ++tab_i] = ft_atoi(argv[i]);
		i++;
	}
	return (0);
}
int	valid_argv(t_data data)
{
	int	i;
	int	x;

	i = 0;
	while (i < data.max_len)
	{
		x = i;
		while (x < data.max_len)
		{
			if (x != i && data.stack_a[x] == data.stack_a[i])
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}
