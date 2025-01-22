/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:27:03 by tbihoues          #+#    #+#             */
/*   Updated: 2024/04/11 16:27:06 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* compte le nombre de chiffres dans un entier n */

size_t	count_n(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/* convertir un entier (de type int) en une chaîne de caractères */

char	*ft_itoa(int n)
{
	char	*nstr;
	size_t	count;
	long	nb;

	nb = n;
	count = count_n(nb) - 1;
	nstr = malloc(sizeof(char) * (count_n(n) + 1));
	if (!nstr)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		nstr[0] = '-';
	}
	if (nb == 0)
		nstr[0] = '0';
	while (nb > 0)
	{
		nstr[count] = nb % 10 + '0';
		count--;
		nb /= 10;
	}
	nstr[count_n(n)] = '\0';
	return (nstr);
}
