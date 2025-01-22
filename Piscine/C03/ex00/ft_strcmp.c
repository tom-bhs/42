/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpidi-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:05:57 by jpidi-pi          #+#    #+#             */
/*   Updated: 2023/08/16 02:06:03 by jpidi-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*int main()
{
    char *str1 = "helloo";
    char *str2 = "world";
    
    ft_strcmp(str1, str2);
    printf("my -%d-\n", ft_strcmp(str1, str2));
    printf("reel -%d-\n", strcmp(str1, str2));
    return (0);
}*/
