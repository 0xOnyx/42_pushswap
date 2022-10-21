/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:59:01 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/21 16:59:02 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	check_max_int(char *str)
{
	long	res;

	res = 0;
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	if (res > 2147483647)
		return (1);
	return (0);
}

int	init_arg(int argc, char **argv, t_data *data)
{
	int	i;
	int	pos;
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
		pos = data->max_len - tab_i - 1;
		if (!is_number(argv[i]))
			return (1);
		if (check_max_int(argv[i]))
			return (1);
		data->stack_a[pos] = ft_atoi(argv[i]);
		data->stack_b[pos] = data->stack_a[pos];
		tab_i++;
		i++;
	}
	return (0);
}

static int	get_len(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (number(str[i]) && !number(str[i + 1]))
			res++;
		i++;
	}
	return (res);
}

int	len_nbr(int nbr)
{
	int	res;

	res = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		res++;
	}
	while (nbr)
	{
		nbr /= 10;
		res++;
	}
	return (res);
}

int	init_str(char *str, t_data *data)
{
	int	i;
	int	tab_i;

	data->max_len = get_len(str);
	data->len_stack_a = data->max_len;
	if (ft_calloc((void **)&data->stack_a, sizeof(int), data->max_len)
		|| ft_calloc((void **)&data->stack_b, sizeof(int), data->max_len))
		return (1);
	i = 0;
	tab_i = 0;
	while (str[i])
	{
		while (!number(str[i]) && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			return (0);
		if ((str[i] == '-' && !number(str[i + 1])) || check_max_int(str + 1))
			return (1);
		data->stack_a[data->max_len - tab_i - 1] = ft_atoi(str + i);
		data->stack_b[data->max_len - tab_i - 1] = ft_atoi(str + i);
		i += len_nbr(data->stack_a[data->max_len - tab_i++ - 1]);
		if (str[i] != ' ' && str[i] != '\0')
			return (1);
	}
	return (0);
}
