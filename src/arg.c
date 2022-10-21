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

static int	parition_quicksort(int *tab, int min, int max)
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

static void	quicksort(int *tab, int min, int max)
{
	int	partition;

	if (min < max)
	{
		partition = parition_quicksort(tab, min, max);
		quicksort(tab, min, partition - 1);
		quicksort(tab, partition + 1, max);
	}
}

static void	init_b(t_data *data)
{
	int	a;
	int	b;
	int	max;
	int	*res;

	a = 0;
	quicksort(data->stack_b, 0, data->max_len - 1);
	if (ft_calloc((void **)&res, sizeof(int), data->max_len))
		return ;
	while (a < data->max_len)
	{
		b = 0;
		while (b < data->max_len)
		{
			if (data->stack_a[a] == data->stack_b[b])
				res[a] = b;
			b++;
		}
		a++;
	}
	max = data->stack_b[data->max_len - 1];
	while ((max >> data->len_bits) != 0)
		++data->len_bits;
	free(data->stack_a);
	data->stack_a = res;
}

int	init_resolve(int argc, char **argv, t_data *data)
{
	int	i;

	if (argc == 1)
	{
		if (init_str(argv[0], data))
			return (1);
	}
	else if (init_arg(argc, argv, data))
		return (1);
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
