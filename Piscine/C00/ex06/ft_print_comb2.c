/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 01:40:45 by tbihoues          #+#    #+#             */
/*   Updated: 2023/08/10 01:40:56 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < 100) 
	{
		while (j < 100) 
		{
			ft_putchar(i / 10 + '0'); 
			ft_putchar(i % 10 + '0');
			ft_putchar(' ');
			ft_putchar(j / 10 + '0'); 
			ft_putchar(j % 10 + '0');
			if (!(i == 98 && j == 99)) 
				write(1, ", ", 2);
			j++;
		}
		j = ++i + 1;
	}
}
