/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:32:47 by dalebran          #+#    #+#             */
/*   Updated: 2023/08/20 23:02:56 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include <unistd.h>

// Fonction pour afficher le tableau 4x4
void	print_grid(int grid[4][4])
{
	char	buf[3];
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			buf[0] = grid[i][j] + '0';
			buf[1] = ' ';
			if (j == 3)
			{
				buf[2] = '\n';
				write(1, buf, 3);
			}
			else
			{
				write(1, buf, 2);
			}
			j++;
		}
		i++;
	}
}

// Initialise la grille à zéro
void	initialize_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

// Fonction pour afficher le message d'erreur
void	print_error(void)
{
	write(1, "Error\n", 6);
}

// Fonction pour initialiser mon tableau de clues
int	create_clues(int argc, char *argv[], int clues[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i])
	{
		if (i % 2 == 0)
		{
			if ('1' <= argv[1][i] && argv[1][i] <= '4')
				clues[j++] = argv[1][i] - '0';
			else
				return (0);
		}
		else if (argv[1][i] != ' ' || j == 16)
			return (0);
		i++;
	}
	if (j != 16)
		return (0);
	return (1);
}
