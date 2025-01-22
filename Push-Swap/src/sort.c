/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:05:55 by tbihoues          #+#    #+#             */
/*   Updated: 2024/06/06 22:54:44 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	min_target_closer(t_stack *a, t_stack *b)
{
	int		min;
	t_stack	*stack_b;

	while (a)
	{
		min = INT_MIN;
		stack_b = b;
		a->target = max_node(b);
		while (stack_b)
		{
			if (a->num > stack_b->num && stack_b->num >= min)
			{
				min = stack_b->num;
				a->target = stack_b;
			}
			stack_b = stack_b->next;
		}
		a = a->next;
	}
}

static void	max_target_closer(t_stack *b, t_stack *a)
{
	int		max;
	t_stack	*stack_a;

	while (b)
	{
		max = INT_MAX;
		stack_a = a;
		b->target = min_node(a);
		while (stack_a)
		{
			if (b->num < stack_a->num && stack_a->num <= max)
			{
				max = stack_a->num;
				b->target = stack_a;
			}
			stack_a = stack_a->next;
		}
		b = b->next;
	}
}

static void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*best;

	best = best_min_mouv(*a);
	if (best->above_median == best->target->above_median)
	{
		if (best->above_median)
		{
			while (*a != best && *b != best->target)
				rr(a, b, 0);
		}
		else
		{
			while (*a != best && *b != best->target)
				rrr(a, b, 0);
		}
	}
	best_min_mouv_on_top(a, best, 1);
	best_min_mouv_on_top(b, best->target, 0);
	pb(a, b, 0);
}

static void	b_to_a(t_stack **a, t_stack **b)
{
	best_min_mouv_on_top(a, (*b)->target, 1);
	pa(b, a, 0);
}

void	sort(t_stack **a, t_stack **b, int five)
{
	int	len;
	int	i;

	i = 0;
	len = stack_len(*a);
	while (i++ < 2 && len-- > 3 && !is_sorted(*a))
		pb(a, b, 0);
	while (len-- > 3 && !is_sorted(*a))
	{
		set_pos(*a);
		set_pos(*b);
		min_target_closer(*a, *b);
		min_mouv(*a, *b);
		a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_pos(*a);
		set_pos(*b);
		max_target_closer(*b, *a);
		b_to_a(a, b);
	}
	min_on_top(a, five);
}
