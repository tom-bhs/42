/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:05:46 by dalebran          #+#    #+#             */
/*   Updated: 2023/08/20 23:02:37 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int	is_valid_col_row(int grid[4][4], int x, int y, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[x][i] == num || grid[i][y] == num)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_all_clues(int grid[4][4], int clues[16])
{
	int	i;
	int	j;
	int	col[4];

	i = -1;
	while (++i < 4)
	{
		if (count_sky_start(grid[i]) != clues[8 + i]
			|| count_sky_end(grid[i]) != clues[12 + i])
			return (0);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			col[j] = grid[j][i];
		if (count_sky_start(col) != clues[i]
			|| count_sky_end(col) != clues[4 + i])
			return (0);
	}
	return (1);
}

int	solve(int grid[4][4], int x, int y, int clues[16])
{
	int	num;

	if (x == 4)
		y++;
	if (x == 4)
		x = 0;
	if (y == 4)
	{
		if (check_all_clues(grid, clues))
			return (1);
		else
			return (0);
	}
	num = 0;
	while (++num <= 4)
	{
		if (is_valid_col_row(grid, x, y, num))
		{
			grid[x][y] = num;
			if (solve(grid, x + 1, y, clues))
				return (1);
			grid[x][y] = 0;
		}
	}
	return (0);
}

int	count_sky_start(int arr[4])
{
	int	tallest_seen;
	int	count;
	int	i;

	tallest_seen = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (arr[i] > tallest_seen)
		{
			tallest_seen = arr[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_sky_end(int arr[4])
{
	int	tallest_seen;
	int	count;
	int	i;

	tallest_seen = 0;
	count = 0;
	i = 3;
	while (i >= 0)
	{
		if (arr[i] > tallest_seen)
		{
			tallest_seen = arr[i];
			count++;
		}
		i--;
	}
	return (count);
}
