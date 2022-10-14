/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:46:39 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/10/14 22:46:40 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int	max_len;
	int	len_stack_a;
	int	len_stack_b;
	int	*stack_a;
	int	*stack_b;
}	t_data;

int		ft_strlen(char *str);
int		ft_putstr_fd(int fd, char *str);
int		init_resolve(char *str, t_data *data);
int		valid_argv(t_data data);
int		resolve(t_data *data);
int		ft_isdigit(char c);
int		ft_atoi(char *str);

void	swap_sa(t_data *data);
void	swap_sb(t_data *data);
void	swap_ss(t_data *data);

void	push_pa(t_data *data);
void	push_pb(t_data *data);

void	rotate_ra(t_data *data);
void	rotate_rb(t_data *data);
void	rotate_rr(t_data *data);

void	reverse_rra(t_data *data);
void	reverse_rrb(t_data *data);
void	reverse_rrr(t_data *data);

#endif
