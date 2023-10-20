/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:36:30 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/06 15:50:25 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_find_min(t_stack **a)
{
	int		i;
	int		smallest;
	t_node	*tmp;

	i = 0;
	smallest = ft_smallest((*a)->head);
	tmp = (*a)->head;
	while (tmp->data != smallest)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > ((*a)->size / 2))
	{
		while ((*a)->head->data != smallest)
			ft_reverse_rotate(a, 'a', false);
	}
	else
		while ((*a)->head->data != smallest)
			ft_rotate(a, 'a', false);
}

static void	ft_sort(t_stack **a, t_stack **b)
{
	if ((*a)->size == 2)
		ft_swap(a, 'a', false);
	else if ((*a)->size <= 10)
		ft_sort_5(a, b);
	else if ((*a)->size > 10)
	{
		while ((*a)->size > 2)
			ft_push(a, b, 'b', false);
		while ((*b)->head)
			ft_big_sort(a, b);
		ft_find_min(a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	bool	split;

	split = false;
	if (argc == 1)
		return (0);
	if (argc == 2)
		ft_check_split(&argc, &argv, &split);
	ft_check_errors(argc, argv, split);
	a = ft_calloc(1, sizeof(t_stack));
	b = ft_calloc(1, sizeof(t_stack));
	a = ft_populate_stack(a, argc, argv, split);
	b->size = 0;
	ft_sort(&a, &b);
	ft_free_everything(&a, &b, argv, split);
	return (0);
}
