/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:30:58 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/05 15:10:03 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
}	t_stack;

void	ft_check_errors(int argc, char **argv, bool split);
void	ft_print_error(char **argv, bool split);
void	ft_check_split(int *argc, char ***argv, bool *split);
void	ft_free_argv(char **argv);
void	ft_reverse_rotate(t_stack **stack, char stack_name, bool moves);
void	ft_rotate(t_stack **stack, char stack_name, bool moves);
void	ft_swap(t_stack **stack, char stack_name, bool moves);
void	ft_push(t_stack **from, t_stack **to, char stack_name, bool checker);
void	ft_sort_3(t_stack **stack, char stack_name);
void	ft_which_half(t_stack **a, t_stack **b, int position);
void	ft_sort_5(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b, bool checker);
void	ft_rr(t_stack **a, t_stack **b, bool checker);
void	ft_ss(t_stack **a, t_stack **b, bool checker);
void	ft_big_sort(t_stack **a, t_stack **b);
void	ft_free_everything(t_stack **a, t_stack **b, char **argv, bool split);
void	ft_check_int(int argc, char **argv, bool split);
void	ft_find_duplicates(int argc, char **argv, bool split);

bool	ft_find_space(char *str);
bool	ft_is_sorted(t_stack *stack);
bool	ft_find_smaller(int data, t_node *node);

t_node	*ft_last_node(t_node *node);
t_node	*ft_prev_last(t_node *node);

t_stack	*ft_populate_stack(t_stack *a, int argc, char **argv, bool split);
t_stack	*ft_addnode_front(t_stack *stack, t_node *new_node);

int		ft_biggest(t_node *node);
int		ft_smallest(t_node *node);
int		ft_take_sum(int a, int b);
int		ft_take_max(int a, int b);
int		ft_search_better(int *tmp_c, int smallest_i, int *mov_a, int *mov_b);
int		ft_min_on_top(t_node *node);

#endif
