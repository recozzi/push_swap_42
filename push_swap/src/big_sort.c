/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:25:48 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 09:27:40 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_index_movb(int i, int size)
{
	if (i > (size / 2))
		i -= size;
	return (i);
}

static int	ft_index_mova(t_node *node_a, int data_b, int size_a)
{
	int		i;

	i = 0;
	if (data_b > ft_biggest(node_a))
		return (ft_index_movb(ft_min_on_top(node_a), size_a));
	while (node_a)
	{
		if (data_b < node_a->data)
		{
			if (ft_find_smaller(data_b, node_a) == false)
				break ;
		}
		node_a = node_a->next;
		i++;
	}
	return (ft_index_movb(i, size_a));
}

static int	ft_best_combination(int *mov_a, int *mov_b, int size_b)
{
	int	i;
	int	smallest_i;
	int	*tmp_c;

	i = -1;
	tmp_c = ft_calloc(size_b, sizeof(int));
	while (++i < size_b)
	{
		if ((mov_a[i] >= 0 && mov_b[i] >= 0) || (mov_a[i] < 0 && mov_b[i] < 0))
			tmp_c[i] = ft_take_max(mov_a[i], mov_b[i]);
		else if ((mov_a[i] >= 0 && mov_b[i] < 0) || (mov_a[i] < 0 && mov_b[i] >= 0))
			tmp_c[i] = ft_take_sum(mov_a[i], mov_b[i]);
	}
	i = -1;
	smallest_i = 0;
	while (++i < size_b)
	{
		if (tmp_c[i] < tmp_c[smallest_i])
			smallest_i = i;
	}
	smallest_i = ft_search_better(tmp_c, smallest_i, mov_a, mov_b);
	free(tmp_c);
	return (smallest_i);
}

static void	ft_do_moves(t_stack **a, t_stack **b, int val_a, int val_b)
{
	while (val_a > 0 && val_b > 0)
	{
		ft_rr(a, b, false);
		val_a--;
		val_b--;
	}
	while (val_a < 0 && val_b < 0)
	{
		ft_rrr(a, b, false);
		val_a++;
		val_b++;
	}
	if (val_a > 0)
		while (val_a-- > 0)
			ft_rotate(a, 'a', false);
	else
		while (val_a++ < 0)
			ft_reverse_rotate(a, 'a', false);
	if (val_b > 0)
		while (val_b-- > 0)
			ft_rotate(b, 'b', false);
	else
		while (val_b++ < 0)
			ft_reverse_rotate(b, 'b', false);
}

void	ft_big_sort(t_stack **a, t_stack **b)
{
	int		i;
	t_node	*tmp_b;
	int		*mov_a;
	int		*mov_b;

	i = -1;
	tmp_b = (*b)->head;
	mov_a = ft_calloc(((*b)->size + 1), sizeof(int));
	mov_b = ft_calloc(((*b)->size + 1), sizeof(int));
	while (++i < (*b)->size)
		mov_b[i] = ft_index_movb(i, (*b)->size);
	mov_b[i] = -2147483648;
	i = -1;
	while (++i < (*b)->size && tmp_b)
	{
		mov_a[i] = ft_index_mova((*a)->head, tmp_b->data, (*a)->size);
		tmp_b = tmp_b->next;
	}
	mov_a[i] = -2147483648;
	i = ft_best_combination(mov_a, mov_b, (*b)->size);
	ft_do_moves(a, b, mov_a[i], mov_b[i]);
	ft_push(b, a, 'a', false);
	free(mov_a);
	free(mov_b);
}
