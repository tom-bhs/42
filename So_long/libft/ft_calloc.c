/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:26:22 by tbihoues          #+#    #+#             */
/*   Updated: 2024/04/11 16:26:26 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* alloue de la mémoire pour un bloc de données de taille count * size
et initialise toutes les valeurs de ce bloc à zéro */

void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;
	int		total;

	total = count * size;
	dst = malloc(total);
	if (!dst)
		return (NULL);
	ft_bzero(dst, total);
	return ((void *)dst);
}
