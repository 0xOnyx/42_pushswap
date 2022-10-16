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

typedef struct s_min_max
{
	int	min;
	int	max;
	int pivot;
}	t_min_max;

typedef enum e_list
{
	sa, sb,	ss,
	pa,	pb,
	ra,	rb,	rr,	rra,
	rrb, rrr
}	t_list;

typedef struct s_node
{
	enum e_list 	data;
	struct s_node 	*next;

}	t_node;

typedef struct s_data
{
	int		max_len;
	int		len_stack_a;
	int		len_stack_b;
	int		*stack_a;
	int		*stack_b;
	t_node	*instruct;
}	t_data;

int		ft_strlen(char *str);
int		ft_putstr_fd(int fd, char *str);
int		init_resolve(char *str, t_data *data);
int		valid_argv(t_data data);
int		resolve(t_data *data);
int		ft_isdigit(char c);
int		ft_atoi(char *str);
int		ft_calloc(void **ptr, size_t size, size_t len);

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

void 	set_min_max(t_min_max *min_max, int *tab, int len);
int 	push_front(t_node **node, t_list list);

void	print_array(t_data *data);

#endif
