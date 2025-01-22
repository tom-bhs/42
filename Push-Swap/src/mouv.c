/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:59:19 by tbihoues          #+#    #+#             */
/*   Updated: 2024/06/06 23:00:24 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	mouv(t_stack *stack)
{
	int	len;

	len = stack_len(stack);
	while (stack)
	{
		if (stack->above_median)
			stack->min_mouv = stack->pos;
		else
			stack->min_mouv = len - stack->pos;
		stack = stack->next;
	}
}

static void	sum_target_movement(t_stack *a)
{
	while (a)
	{
		if (a->above_median == a->target->above_median
			&& a->min_mouv < a->target->min_mouv)
			a->min_mouv = a->target->min_mouv;
		else if (a->above_median != a->target->above_median)
			a->min_mouv = a->min_mouv + a->target->min_mouv;
		a = a->next;
	}
}

void	min_mouv(t_stack *a, t_stack *b)
{
	mouv(a);
	mouv(b);
	sum_target_movement(a);
}
