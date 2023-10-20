/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:14:31 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/06 17:16:59 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_everything(t_stack **a, t_stack **b, char **argv, bool split)
{
	t_node	*tmp;

	while ((*a)->head)
	{
		tmp = (*a)->head;
		(*a)->head = (*a)->head->next;
		free(tmp);
	}
	while ((*b)->head)
	{
		tmp = (*b)->head;
		(*b)->head = (*b)->head->next;
		free(tmp);
	}
	free(*a);
	free(*b);
	if (split == true)
		ft_free_argv(argv);
}
