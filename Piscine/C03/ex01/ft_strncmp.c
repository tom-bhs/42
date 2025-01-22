/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpidi-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 05:41:35 by jpidi-pi          #+#    #+#             */
/*   Updated: 2023/08/16 05:41:42 by jpidi-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0 && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		n--;
	}
	return (0);
}
/*int main()
{
    char *str1 = "ell";
    char *str2 = "ello";
    
    ft_strncmp(str1, str2, 1);
    printf("my -%d-\n", ft_strncmp(str1, str2, 2));
    printf("reel -%d-\n", strncmp(str1, str2, 2));
    return (0);
}*/
