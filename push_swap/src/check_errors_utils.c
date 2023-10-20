/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:50:06 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/03 11:55:46 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_error(char **argv, bool split)
{
	if (split == true)
		ft_free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

bool	ft_find_space(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == ' ')
			return (true);
		i++;
	}
	return (false);
}
