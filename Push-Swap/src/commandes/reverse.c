/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:15:29 by tbihoues          #+#    #+#             */
/*   Updated: 2024/06/06 22:32:37 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_last_node(*stack);
	first_node = *stack;
	last_node->next = *stack;
	last_node->prev->next = NULL;
	first_node->prev = last_node;
	*stack = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	rra(t_stack **a, int check)
{
	reverse(a);
	if (!check)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int check)
{
	reverse(b);
	if (!check)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int check)
{
	reverse(a);
	reverse(b);
	if (!check)
		write(1, "rrr\n", 4);
}
