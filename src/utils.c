/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:44:13 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/14 22:44:14 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr_fd(int fd, char *str)
{
	int	len;

	len = ft_strlen(str);
	len = write(fd, str, len);
	return (len);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	neg;
	int	res;

	neg = 1;
	res = 0;
	if (*str == '-')
	{
		neg *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * neg);
}

int ft_calloc(void **ptr, size_t size, size_t len)
{
	unsigned char	*current;
	void			*res;
	size_t			i;

	res = malloc(size * len);
	*ptr = res;
	current = (unsigned char *)res;
	if (!res)
		return (1);
	i = 0;
	while (i < len)
		current[i++] = 0;
	return (0);
}
