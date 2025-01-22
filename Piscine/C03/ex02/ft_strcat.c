/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpidi-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:34:10 by jpidi-pi          #+#    #+#             */
/*   Updated: 2023/08/16 18:34:14 by jpidi-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int	main(void)
{
	char	dest[] = "rien";
	char	src[] = " a gratter";
	char	dest2[] = "rien";
	char	src2[] = " a gratter";

	ft_strcat(dest, src);
	strcat(dest2, src2);
	printf("my -%s-\n", dest);
	printf("reel -%s-\n", dest2);
}*/
