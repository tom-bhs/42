/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpidi-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:20:12 by jpidi-pi          #+#    #+#             */
/*   Updated: 2023/08/16 19:20:17 by jpidi-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*origine;
	unsigned int	i;

	origine = dest;
	i = 0;
	while (*dest)
		dest++;
	while (*src && i < nb)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (origine);
}
/*int	main(void)
{
	char	dest[] = "rien";
	char	src[] = " a gratter";
	char	dest2[] = "rien";
	char	src2[] = " a gratter";

	ft_strncat(dest, src, 6);
	strncat(dest2, src2, 6);
	printf("my -%s-\n", dest);
	printf("reel -%s-\n", dest2);
}*/
