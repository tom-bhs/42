/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:28:21 by dalebran          #+#    #+#             */
/*   Updated: 2023/08/20 23:02:45 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "solver.h"

int	main(int argc, char *argv[])
{
	int	grid[4][4];
	int	clues[16];

	if (!(create_clues(argc, argv, clues)))
	{
		print_error();
		return (0);
	}
	initialize_grid(grid);
	if (solve(grid, 0, 0, clues))
		print_grid(grid);
	else
		print_error();
	return (0);
}
