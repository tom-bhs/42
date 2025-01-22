/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:35:42 by tbihoues          #+#    #+#             */
/*   Updated: 2024/05/26 20:01:37 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../inc/libft/libft.h"
//#include "../inc/libft/ft_printf.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct	s_stack
{
	int *data;
	int size;
} t_stack;


//		GENERAL		//


int		get_max_bits(t_stack *stack);
int		get_bit(int num, int bit);
void	init_stack(t_stack *stack, int size);
void	push_swap(t_stack *a, t_stack *b);
void	parse_args(t_stack *a, int argc, char **argv);
// void	check_args(int argc, char **argv);



//		MOVE		//


void sa(t_stack *a);
void sb(t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rr(t_stack *a,t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void rrr(t_stack *a, t_stack *b);


//		ERROR		//


int		print_error(void);
void	exit_error(const char *mess);


// 		UTILS		//

void	if_doubles(int *data, int size);
void	if_not_number(char *str);
// void	free_tab(char **argv);
// void	argv_verif(int argc, char **argv);

#endif