/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:01:19 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/21 19:01:20 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bit(int max, t_data *data)
{
	while ((max >> data->len_bits) != 0)
		++data->len_bits;
}

int	check_digit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	check_digit_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
