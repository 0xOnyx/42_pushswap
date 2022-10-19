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
#include <stdio.h>

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

static int parition_quicksort(int *tab, int min, int max)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[max];
	i = min - 1;
	j = min;
	while (j < max)
	{
		if (tab[j] < pivot)
		{
			i++;
			ft_swap(&tab[i], &tab[j]);
		}
		j++;
	}
	ft_swap(&tab[i + 1], &tab[max]);
	return (i + 1);

}

static void quicksort(int *tab, int min, int max)
{
	int	partition;

	if (min < max)
	{
		partition = parition_quicksort(tab, min, max);
		quicksort(tab, min, partition - 1);
		quicksort(tab, partition + 1, max);
	}
}

static void init_b(t_data *data)
{
	int	a;
	int	b;
	int *res;

	a = 0;
	quicksort(data->stack_b, 0, data->max_len - 1);
	if (ft_calloc((void **)&res, sizeof(int),  data->max_len))
		return ;
	while(a < data->max_len)
	{
		b = 0;
		while(b < data->max_len)
		{
			if (data->stack_a[a] == data->stack_b[b])
				res[a] = b;
			b++;
		}
		a++;
	}
	free(data->stack_a);
	data->stack_a = res;
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
		data->stack_a[data->max_len - tab_i - 1] = ft_atoi(argv[i]);
		data->stack_b[data->max_len - tab_i - 1] = data->stack_a[data->max_len - tab_i - 1];
		tab_i++;
		i++;
	}
	init_b(data);
	i = 0;
	while (i < data->max_len)
		data->stack_b[i++] = 0;
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
