/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:26:41 by tbihoues          #+#    #+#             */
/*   Updated: 2023/08/14 18:26:45 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (*str < 'a' || *str > 'z')
			return (0);
		str ++;
	}
	return (1);
}

/*int	main(void)
{
	char	test[] = "test";
	
	printf ("%d", ft_str_is_alpha(test));
}*/
