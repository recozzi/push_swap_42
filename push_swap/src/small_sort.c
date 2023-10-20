/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:28:24 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/16 10:28:51 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_3(t_stack **stack, char stack_name)
{
	if ((*stack)->head->data > (*stack)->head->next->data && (*stack)->head->data > (*stack)->head->next->next->data)
		ft_rotate(stack, stack_name, false);
	else if ((*stack)->head->next->data > (*stack)->head->data && (*stack)->head->next->data > (*stack)->head->next->next->data)
		ft_reverse_rotate(stack, stack_name, false);
	if ((*stack)->head->data > (*stack)->head->next->data)
		ft_swap(stack, stack_name, false);
}

void	ft_sort_5(t_stack **a, t_stack **b)
{
	int		position;
	int		min;
	t_node	*tmp;

	while ((*a)->size > 3)
	{
		tmp = (*a)->head;
		position = 1;
		min = ft_smallest((*a)->head);
		while (tmp->data != min)
		{
			tmp = tmp->next;
			position++;
		}
		ft_which_half(a, b, position);
	}
	if (ft_is_sorted(*a) == false)
		ft_sort_3(a, 'a');
	while ((*b)->size > 0)
		ft_push(b, a, 'a', false);
}
