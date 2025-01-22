/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:26:33 by tbihoues          #+#    #+#             */
/*   Updated: 2024/04/11 16:26:34 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lowerhex(unsigned long n)
{
	char	*tab;
	int		i;

	tab = "0123456789abcdef";
	i = 0;
	if (n >= 16)
		i += ft_lowerhex(n / 16);
	ft_putchar(tab[n % 16]);
	return (i + 1);
}

int	ft_upperhex(unsigned long n)
{
	char	*tab;
	int		i;

	tab = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
		i += ft_upperhex(n / 16);
	ft_putchar(tab[n % 16]);
	return (i + 1);
}

int	ft_pointer(unsigned long ptr)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i += ft_putstr("0x");
	if (ptr == 0)
	{
		write(1, "0", 1);
		i++;
	}
	else
		i += ft_lowerhex(ptr);
	return (i);
}
