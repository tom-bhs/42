/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:46:46 by tbihoues          #+#    #+#             */
/*   Updated: 2024/10/04 23:08:48 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	error_int(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	int	j;

	j = 0;
	if (!str[j])
		return (0);
	if (str[j] == '-' || str[j] == '+')
	{
		if (!(str[j + 1] >= '0' && str[j + 1] <= '9'))
			return (0);
		j++;
	}
	while (str[j])
	{
		if (!(str[j] >= '0' && str[j] <= '9'))
			return (0);
		j++;
	}
	return (1);
}

int	error_syntax(char **argv)
{
	int	i;

	i = 0;
	if (!argv[0])
		return (1);
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	error_dup(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
			{
				write(1, "Doublons ", 9);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// int	error_syntax(char **argv)
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	if (!argv[0])
// 		return (1);
// 	while (argv[i])
// 	{
// 		j = 0;
// 		if (!argv[i][j])
// 			return (1);
// 		if (argv[i][j] == '-' || argv[i][j] == '+')
// 		{
// 			if (!(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
// 				return (1);
// 			j++;
// 		}
// 		while (argv[i][j])
// 		{
// 			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }