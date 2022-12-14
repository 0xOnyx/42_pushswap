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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	safe_clean(t_data data)
{
	if (!data.stack_a)
		free(data.stack_a);
	if (!data.stack_b)
		free(data.stack_b);
}

static void	init(t_data *data)
{
	data->max_len = 0;
	data->len_stack_a = 0;
	data->len_stack_b = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->instruct = NULL;
	data->len_bits = 0;
}

static int	ft_issort(t_data *data)
{
	int	i;
	int	last;
	int	current;

	i = 0;
	last = data->stack_a[data->len_stack_a - 1];
	while (i < data->max_len)
	{
		current = data->stack_a[data->len_stack_a - i - 1];
		if (last > current)
			return (0);
		last = current;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init(&data);
	if (argc <= 1)
		return (1);
	if (init_resolve(argc - 1, argv + 1, &data)
		|| valid_argv(data))
	{
		safe_clean(data);
		ft_putstr_fd(2, "Error\n");
		return (1);
	}
	if (ft_issort(&data))
		return (1);
	if (resolve(&data))
	{
		safe_clean(data);
		ft_putstr_fd(2, "Error\n");
		return (1);
	}
	safe_clean(data);
	return (0);
}
