/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:54:03 by tbihoues          #+#    #+#             */
/*   Updated: 2024/10/04 23:07:15 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	int				pos;
	int				above_median;
	int				min_mouv;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				ft_free_stack(t_stack **stack);
void				fill_stack(t_stack **a, char **argv);
t_stack				*ft_last_node(t_stack *stack);
int					is_sorted(t_stack *stack);
int					stack_len(t_stack *stack);
t_stack				*max_node(t_stack *stack);
t_stack				*min_node(t_stack *stack);
char				**ft_split(const char *s, char delimiter);
void				free_split(char **split);

//				SORT			//
void				sa(t_stack **a, int check);
void				sb(t_stack **b, int check);
void				ss(t_stack **a, t_stack **b, int check);
void				pa(t_stack **b, t_stack **a, int check);
void				pb(t_stack **a, t_stack **b, int check);
void				ra(t_stack **a, int check);
void				rb(t_stack **b, int check);
void				rr(t_stack **a, t_stack **b, int check);
void				rra(t_stack **a, int check);
void				rrb(t_stack **b, int check);
void				rrr(t_stack **a, t_stack **b, int check);
void				sort_three(t_stack **a);
void				set_pos(t_stack *stack);
void				min_mouv(t_stack *a, t_stack *b);
t_stack				*best_min_mouv(t_stack *stack);
void				best_min_mouv_on_top(t_stack **stack,
						t_stack *best_min_node, int a);
void				min_on_top(t_stack **a, int five);
void				sort(t_stack **a, t_stack **b, int five);

//			ERROR			//
int					error_int(char **argv);
int					error_syntax(char **argv);
int					error_dup(char **argv);
long				ft_atol(char *str);
void				print_error(void);

#endif