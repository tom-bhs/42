/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psicoli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:10:15 by psicoli           #+#    #+#             */
/*   Updated: 2023/08/13 11:10:17 by psicoli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(int c);

void	char_cmpr(int c_max, int l_max, int cl, int ln)
{
	if (cl == 0 && ln == 0 || cl == 0 && ln == l_max)
		ft_putchar('A');
	else if (cl == c_max && ln == 0 || cl == c_max && ln == l_max)
		ft_putchar('C');
	else if (cl == 0 || cl == c_max)
		ft_putchar('B');
	else if (ln == 0 || ln == l_max)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	cl;
	int	ln;
	int	c_max;
	int	l_max;

	c_max = y - 1;
	l_max = x - 1;
	cl = 0;
	ln = 0;
	while (cl <= c_max)
	{
		while (ln <= l_max)
		{
			char_cmpr(c_max, l_max, cl, ln);
			ln++;
		}
		cl++;
		ft_putchar('\n');
		ln = 0;
	}
}
