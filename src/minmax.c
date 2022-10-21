/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:46:08 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/21 14:46:09 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(int *tab, int len)
{
	int	min;
	int	i;

	i = 0;
	min = tab[i];
	while (i < len)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int	get_mid(int *tab, int len, int min, int max)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] != min && tab[i] != max)
			return (tab[i]);
		i++;
	}
	return (0);
}

int	get_max(int *tab, int len)
{
	int	max;
	int	i;

	i = 0;
	max = tab[i];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

void	set_min_max(t_min_max *min_max, int *tab, int len)
{
	min_max->min = get_min(tab, len);
	min_max->max = get_max(tab, len);
	min_max->pivot = (min_max->max + min_max->min) / 2;
}
