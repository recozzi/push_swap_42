/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:25:28 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/06 17:33:52 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_check_moves(t_stack **a, t_stack **b, const char *input)
{
	if (!ft_strncmp(input, "sa\n", 3))
		ft_swap(a, 'a', true);
	else if (!ft_strncmp(input, "sb\n", 3))
		ft_swap(b, 'b', true);
	else if (!ft_strncmp(input, "ss\n", 3))
		ft_ss(a, b, true);
	else if (!ft_strncmp(input, "ra\n", 3))
		ft_rotate(a, 'a', true);
	else if (!ft_strncmp(input, "rb\n", 3))
		ft_rotate(b, 'b', true);
	else if (!ft_strncmp(input, "rr\n", 3))
		ft_rr(a, b, true);
	else if (!ft_strncmp(input, "pa\n", 3))
		ft_push(b, a, 'a', true);
	else if (!ft_strncmp(input, "pb\n", 3))
		ft_push(a, b, 'b', true);
	else if (!ft_strncmp(input, "rra\n", 4))
		ft_reverse_rotate(a, 'a', true);
	else if (!ft_strncmp(input, "rrb\n", 4))
		ft_reverse_rotate(b, 'b', true);
	else if (!ft_strncmp(input, "rrr\n", 4))
		ft_rrr(a, b, true);
	else
		return (0);
	return (1);
}

static void	ft_execute_input(t_stack **a, t_stack **b)
{
	char	*input;
	int		res;

	res = 0;
	input = get_next_line(0);
	while (input)
	{
		res = ft_check_moves(a, b, input);
		free(input);
		if (!res)
		{
			write(2, "Error\n", 6);
			return ;
		}
		input = get_next_line(0);
	}
	if (ft_is_sorted(*a) == true && (*b)->size == 0)
	{
		ft_printf("OK\n");
		free(input);
	}
	else
		ft_printf("KO\n");
}

void	ft_checker_errors(int argc, char **argv, bool split)
{
	if (!argc)
	{
		if (split == true)
			ft_free_argv(argv);
		write(2, "Error\n", 6);
		exit(1);
	}
	ft_check_int(argc, argv, split);
	ft_find_duplicates(argc, argv, split);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	bool	split;

	split = false;
	if (argc == 1)
		return (0);
	if (argc == 2)
		ft_check_split(&argc, &argv, &split);
	ft_checker_errors(argc, argv, split);
	a = ft_calloc(1, sizeof(t_stack));
	b = ft_calloc(1, sizeof(t_stack));
	a = ft_populate_stack(a, argc, argv, split);
	b->size = 0;
	ft_execute_input(&a, &b);
	get_next_line(-42);
	ft_free_everything(&a, &b, argv, split);
	return (0);
}
