/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:04:11 by tbihoues          #+#    #+#             */
/*   Updated: 2023/08/20 20:04:14 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	moins;
	int	resul;

	i = 0;
	moins = 1;
	resul = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			moins *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resul = resul * 10 + (str[i] - '0');
		i++;
	}
	return (resul * moins);
}

/*int	main(void)
{
	char	*str = " ----+++157872";
	ft_atoi(str);
	printf("%d\n", ft_atoi(str));
}*/
