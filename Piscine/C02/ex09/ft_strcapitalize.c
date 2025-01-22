/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:56:55 by tbihoues          #+#    #+#             */
/*   Updated: 2023/08/15 12:56:58 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str += 32;
		}
		str++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	i = 0;
	first = 1;
	ft_strlowcase(str);
	while (str[i] != '\0' )
	{
		if (first == 1 && str[i] >= 'a' && str [i] <= 'z')
		{
			str[i] -= 32;
			first = 0;
		}
		else if ((str[i] >= 'a' && str[i] <= 'z') 
			|| (str [i] >= '0' && str [i] <= '9')) 
		{
			first = 0;
		}
		else
		{
			first = 1;
		}
		i++;
	}
	return (str);
}

/*int	main ()
{
	char	str2[] = "sALUT, comment ca va ? 56 chiffres; cinquante+et+un+mot";
	printf("%s\n", ft_strcapitalize(str2));
	return (0);
}*/
