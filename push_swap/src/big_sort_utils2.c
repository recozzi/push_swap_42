/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:54:24 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/02 14:04:06 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_min_on_top(t_node *node)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = node;
	while (tmp->data != ft_smallest(node))
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

bool	ft_find_smaller(int data, t_node *node)
{
	t_node	*tmp;

	tmp = node->next;
	while (tmp)
	{
		if (tmp->data > data && tmp->data < node->data)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

int	ft_biggest(t_node *node)
{
	int		biggest;
	t_node	*tmp;

	biggest = 0;
	tmp = node;
	while (node)
	{
		node = node->next;
		while (node && tmp->data > node->data)
			node = node->next;
		biggest = tmp->data;
		tmp = node;
	}
	return (biggest);
}
