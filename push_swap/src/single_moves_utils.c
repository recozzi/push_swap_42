/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_moves_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:47:04 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/01 12:10:22 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_prev_last(t_node *node)
{
	if (node->next)
		while (node->next->next)
			node = node->next;
	return (node);
}

t_stack	*ft_addnode_front(t_stack *stack, t_node *new_node)
{
	if (new_node)
	{
		if (stack->head)
			new_node->next = stack->head;
		stack->head = new_node;
	}
	return (stack);
}
