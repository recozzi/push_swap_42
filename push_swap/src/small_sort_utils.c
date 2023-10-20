/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:11:17 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/06 17:32:35 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_smallest(t_node *node)
{
	int		smallest;
	t_node	*tmp;

	smallest = 0;
	tmp = node;
	while (node)
	{
		node = node->next;
		while (node && (tmp->data < node->data))
			node = node->next;
		smallest = tmp->data;
		tmp = node;
	}
	return (smallest);
}

void	ft_which_half(t_stack **a, t_stack **b, int position)
{
	if (position > ((*a)->size / 2) + 1)
	{
		while (position <= (*a)->size)
		{
			ft_reverse_rotate(a, 'a', false);
			position++;
		}
		ft_push(a, b, 'b', false);
	}
	else
	{
		while (position > 1)
		{
			ft_rotate(a, 'a', false);
			position--;
		}
		ft_push(a, b, 'b', false);
	}
}

bool	ft_is_sorted(t_stack *stack)
{
	t_node	*previous;
	t_node	*following;

	if (stack->size > 1)
	{
		previous = stack->head;
		following = stack->head->next;
		while (following)
		{
			if (previous->data > following->data)
				return (false);
			previous = following;
			following = following->next;
		}
	}
	return (true);
}
