/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpidi-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:50:06 by jpidi-pi          #+#    #+#             */
/*   Updated: 2023/08/16 20:50:12 by jpidi-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			temp = i;
			while (str[temp] == to_find[j])
			{
				if (!to_find[j + 1])
					return (&str[i]);
				j++;
				temp++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}
/*int	main()
{
	const char s1[100] = "retoueeee";
	const char s2[100] = "tou";

	char mys1[] = "retoueeee";
	char mys2[] = "tou";

	printf("my -%s-\n", ft_strstr(mys1, mys2));
	printf("reel -%s-\n", strstr(s1, s2));
}*/
