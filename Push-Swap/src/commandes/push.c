/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:10:09 by tbihoues          #+#    #+#             */
/*   Updated: 2024/06/06 22:32:27 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push(t_stack **ori, t_stack **dest)
{
	t_stack	*first_node;

	first_node = *ori;
	*ori = (*ori)->next;
	if (*ori)
		(*ori)->prev = NULL;
	if (!*dest)
	{
		*dest = first_node;
		(*dest)->next = NULL;
	}
	else
	{
		(*dest)->prev = first_node;
		first_node->next = *dest;
		*dest = first_node;
	}
}

void	pa(t_stack **b, t_stack **a, int check)
{
	if (!*b)
		return ;
	push(b, a);
	if (!check)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int check)
{
	if (!*a)
		return ;
	push(a, b);
	if (!check)
		write(1, "pb\n", 3);
}
