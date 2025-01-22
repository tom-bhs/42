/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:14:52 by tbihoues          #+#    #+#             */
/*   Updated: 2024/05/25 19:59:09 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// int	if_number(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str[0] == '-' || str[0] == '+')
// 		i++;
// 	if (str[i] == '\0')
// 		return (0);
// 	while (str[i])
// 	{
// 		if (!ft_isdigit(str[i]))
// 		{
// 			print_error();
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// void	if_doubles(int *data, int size)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while(i < size - 1)
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (data[i] == data[j])
// 				print_error();
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	free_tab(char **argv)
// {
// 	int i;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		free(argv[i]);
// 		i++;
// 	}
// 	free(argv);
// }