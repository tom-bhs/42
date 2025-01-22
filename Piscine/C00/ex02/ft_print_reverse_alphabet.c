/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 00:12:13 by tbihoues          #+#    #+#             */
/*   Updated: 2023/08/13 00:12:20 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void);

void	ft_print_reverse_alphabet(void)
{
	char	varz;
	char	vara;

	varz = 'z';
	vara = 'a';
	while (varz >= vara)
	{
		write (1, &varz, 1);
		varz = varz - 1;
	}
}
