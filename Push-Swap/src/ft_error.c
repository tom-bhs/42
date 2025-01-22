/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:06:26 by tbihoues          #+#    #+#             */
/*   Updated: 2024/05/25 19:58:12 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	print_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	if_not_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' ||str[i] == '+')&& ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error();
		i++;
	}
}

void	if_doubles(int *data, int size)
{
	int	i;
	int	j;

	i = 0;
	while(i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (data[i] == data[j])
				print_error();
			j++;
		}
		i++;
	}
}