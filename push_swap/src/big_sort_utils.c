/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:17:43 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/03 16:46:56 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_take_max(int a, int b)
{
	if (a < 0 && b < 0)
	{
		a *= -1;
		b *= -1;
	}
	if (a > b)
		return (a);
	return (b);
}

int	ft_take_sum(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}

static int	ft_arrlen_criminal(int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != -2147483648)
		i++;
	return (i);
}

int	ft_search_better(int *tmp_c, int smallest_i, int *mov_a, int *mov_b)
{
	int	i;
	int	size;

	size = ft_arrlen_criminal(mov_b);
	i = smallest_i;
	while (++i < size)
	{
		if (tmp_c[i] == tmp_c[smallest_i])
		{
			if (mov_a[smallest_i] == 0 || mov_b[smallest_i] == 0)
			{
				if (mov_a[i] != 0 && mov_b[i] != 0)
					return (i);
			}
		}
	}
	return (smallest_i);
}
