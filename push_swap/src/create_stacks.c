/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:30:05 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/03 16:52:19 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*ft_create_node(int nbr)
{
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	new_node->data = nbr;
	new_node->next = NULL;
	return (new_node);
}

t_node	*ft_last_node(t_node *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

static t_stack	*ft_addnode_back(t_stack *stack, t_node *new_node)
{
	t_node	*last;

	if (new_node)
	{
		if (stack->head)
		{
			last = ft_last_node(stack->head);
			last->next = new_node;
		}
		else
			stack->head = new_node;
	}
	return (stack);
}

static int	ft_lstlen(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	stack->size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		stack->size++;
	}
	return (stack->size);
}

t_stack	*ft_populate_stack(t_stack *a, int argc, char **argv, bool split)
{
	int	i;

	i = 1;
	if (split == true)
		i = 0;
	while (i < argc && argv[i])
	{
		a = ft_addnode_back(a, ft_create_node(ft_atoi(argv[i])));
		i++;
	}
	a->size = ft_lstlen(a);
	return (a);
}
