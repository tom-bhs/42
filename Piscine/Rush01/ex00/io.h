/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:00:52 by dalebran          #+#    #+#             */
/*   Updated: 2023/08/19 18:01:11 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_grid(int grid[4][4]);
void	initialize_grid(int grid[4][4]);
void	print_error(void);
int		create_clues(int argc, char *argv[], int clues[]);
