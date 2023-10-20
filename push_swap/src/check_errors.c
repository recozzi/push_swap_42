/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:30:08 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/06 16:46:27 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_duplicates(int argc, char **argv, bool split)
{
	int	i;
	int	j;

	i = 1;
	if (split == true)
		i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				ft_print_error(argv, split);
			j++;
		}
		i++;
	}
}

static bool	ft_check_order(int argc, char **argv, bool split)
{
	int	i;
	int	j;

	i = 1;
	if (split == true)
		i = 0;
	j = i + 1;
	while (i < argc && j < argc)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[j]))
			return (false);
		j++;
		i++;
	}
	return (true);
}

void	ft_check_split(int *argc, char ***argv, bool *split)
{
	if ((*argv)[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (ft_find_space(*(*argv + 1)) == true)
	{
		*argv = ft_split(*(*argv + 1), ' ');
		*argc = ft_matrixlen(*argv);
		*split = true;
	}
	else
		*split = false;
}

void	ft_check_int(int argc, char **argv, bool split)
{
	int		i;
	int		j;

	i = 1;
	if (split == true)
		i = 0;
	while (i < argc && argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				ft_print_error(argv, split);
			j++;
		}
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			ft_print_error(argv, split);
		i++;
	}
}

void	ft_check_errors(int argc, char **argv, bool split)
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
	if (ft_check_order(argc, argv, split) == true)
	{
		if (split == true)
			ft_free_argv(argv);
		exit(0);
	}
}
