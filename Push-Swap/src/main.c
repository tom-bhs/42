/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:41:41 by tbihoues          #+#    #+#             */
/*   Updated: 2024/05/26 20:02:25 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	a;
	t_stack	b;
	char	**tab = NULL;

	if (argc < 2)
	{
		print_error();
		return (0);
	}
	i = 1;
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		while (tab[i] != NULL)
		{
			if_not_number(tab[i]);
			i++;
		}
	}
	else
	{
		while (i < argc)
		{
			if_not_number(argv[i]);
			i++;
		}
	}
	init_stack(&a, i -1);
	init_stack(&b, i -1);
	if (tab != NULL)
		parse_args(&a, i, tab);
	else
		parse_args(&a, argc, argv);
	if_doubles(a.data, a.size);
	i = 0;
	while (i < a.size)
	{
		printf("%d", a.data[i]);
		i++;
	}
	ft_printf("\n");
	push_swap(&a, &b);
	free(a.data);
	free(b.data);
	return (0);
}

