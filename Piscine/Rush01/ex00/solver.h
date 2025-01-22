/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:01:00 by dalebran          #+#    #+#             */
/*   Updated: 2023/08/19 18:11:36 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fonction qui verifie si le nombre est deja sur la ligne ou la colonne
int	is_valid_col_row(int grid[4][4], int x, int y, int num);

// Fonction qui vérifie toutes les clues
int	check_all_clues(int grid[4][4], int clues[16]);

// Fonction récursive principale pour résoudre le puzzle
int	solve(int grid[4][4], int x, int y, int clues[16]);

// Compte les skyscrapper en fonction de la position
int	count_sky_start(int arr[4]);
int	count_sky_end(int arr[4]);
