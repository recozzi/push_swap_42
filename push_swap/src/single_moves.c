/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:48:57 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/06 16:59:01 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack **stack, char stack_name, bool moves)
{
	int	tmp;

	if (!(*stack)->head || !(*stack)->head->next)
		return ;
	tmp = (*stack)->head->data;
	(*stack)->head->data = (*stack)->head->next->data;
	(*stack)->head->next->data = tmp;
	if (moves == false)
	{
		if (stack_name == 'a')
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
}

void	ft_rotate(t_stack **stack, char stack_name, bool moves)
{
	t_node	*last;
	t_node	*head;

	if (!(*stack)->head || !(*stack)->head->next)
		return ;
	head = (*stack)->head;
	last = ft_last_node((*stack)->head);
	(*stack)->head = (*stack)->head->next;
	last->next = head;
	head->next = NULL;
	if (moves == false)
	{
		if (stack_name == 'a')
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
}

void	ft_reverse_rotate(t_stack **stack, char stack_name, bool moves)
{
	t_node	*last;
	t_node	*prev_last;
	t_node	*head_next;

	if (!(*stack)->head || !(*stack)->head->next)
		return ;
	head_next = (*stack)->head;
	last = ft_last_node((*stack)->head);
	prev_last = ft_prev_last((*stack)->head);
	prev_last->next = NULL;
	(*stack)->head = last;
	(*stack)->head->next = head_next;
	if (moves == false)
	{
		if (stack_name == 'a')
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
}

void	ft_push(t_stack **from, t_stack **to, char stack_name, bool checker)
{
	t_node	*tmp;

	if (!(*from)->head)
		return ;
	tmp = (*from)->head;
	(*from)->head = (*from)->head->next;
	tmp->next = NULL;
	*to = ft_addnode_front(*to, tmp);
	(*from)->size--;
	(*to)->size++;
	if (checker == false)
	{
		if (stack_name == 'a')
			ft_printf("pa\n");
		else
			ft_printf("pb\n");
	}
}
