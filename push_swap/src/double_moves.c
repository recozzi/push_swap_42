/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:06:34 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/03 12:00:58 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ss(t_stack **a, t_stack **b, bool checker)
{
	ft_swap(a, 'a', true);
	ft_swap(b, 'b', true);
	if (checker == false)
		ft_printf("ss\n");
}

void	ft_rr(t_stack **a, t_stack **b, bool checker)
{
	ft_rotate(a, 'a', true);
	ft_rotate(b, 'b', true);
	if (checker == false)
		ft_printf("rr\n");
}

void	ft_rrr(t_stack **a, t_stack **b, bool checker)
{
	ft_reverse_rotate(a, 'a', true);
	ft_reverse_rotate(b, 'b', true);
	if (checker == false)
		ft_printf("rrr\n");
}
