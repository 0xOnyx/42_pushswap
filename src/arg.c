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

static int	calc_len(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[0])
	{
		if ((str[i + 1] == ' ' || str[i + 1] == '\0')
			&& (str[i] != ' ' && str[i] != '\0'))
			res++;
		if (str[i + 1] == '\0')
			break ;
		i++;
	}
	return (res);
}

int	init_resolve(char *str, t_data *data)
{
	int	i;
	int	tab_i;

	data->max_len = calc_len(str);
	data->len_stack_a = data->max_len;
	if (ft_calloc((void **)&data->stack_a, sizeof(int), data->max_len)
		|| ft_calloc((void **)&data->stack_b, sizeof(int), data->max_len))
		return (1);
	i = 0;
	tab_i = 0;
	while (str[i])
	{
		while (str[i] && (!ft_isdigit(str[i]) && str[i] != '-'))
			i++;
		if (str[i])
			data->stack_a[tab_i++] = ft_atoi(str + i);
		while (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
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
			if (x != i && data.stack_a[i] == data.stack_b[i])
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}
