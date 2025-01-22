/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:06:23 by tbihoues          #+#    #+#             */
/*   Updated: 2024/09/29 22:23:35 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_stack **a)
{
	int	max;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	max = max_node(*a)->num;
	if ((*a)->num == max)
		ra(a, 0);
	else if ((*a)->next->num == max)
		rra(a, 0);
	if ((*a)->next->num < (*a)->num)
		sa(a, 0);
}

void	set_pos(t_stack *stack)
{
	int	med;
	int	i;

	i = 0;
	med = stack_len(stack);
	if (med % 2 == 0)
		med /= 2;
	else
		med = (med + 1) / 2;
	while (stack)
	{
		if (i < med)
		{
			stack->above_median = 1;
			stack->pos = i;
		}
		else
		{
			stack->above_median = 0;
			stack->pos = i;
		}
		i++;
		stack = stack->next;
	}
}

t_stack	*best_min_mouv(t_stack *stack)
{
	int		min_mouv;
	t_stack	*node_min_mouv;

	if (!stack)
		return (NULL);
	min_mouv = INT_MAX;
	while (stack)
	{
		if (stack->min_mouv < min_mouv)
		{
			min_mouv = stack->min_mouv;
			node_min_mouv = stack;
		}
		stack = stack->next;
	}
	return (node_min_mouv);
}

void	best_min_mouv_on_top(t_stack **stack, t_stack *best_min_node, int a)
{
	while (*stack != best_min_node)
	{
		if (best_min_node->above_median)
		{
			if (a)
				ra(stack, 0);
			else
				rb(stack, 0);
		}
		else
		{
			if (a)
				rra(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

void	min_on_top(t_stack **a, int five)
{
	t_stack	*node_min;

	node_min = min_node(*a);
	while (*a != node_min)
	{
		if (five)
		{
			if (!node_min->above_median)
				ra(a, 0);
			else
				rra(a, 0);
		}
		else
		{
			if (node_min->above_median)
				ra(a, 0);
			else
				rra(a, 0);
		}
	}
}
