/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:07:07 by tbihoues          #+#    #+#             */
/*   Updated: 2024/10/04 22:49:46 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	append_node(t_stack **a, int num)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!a)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->num = num;
	new_node->next = NULL;
	if (!(*a))
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	fill_stack(t_stack **a, char **argv)
{
	int	num;
	int	i;

	i = 0;
	while (argv[i])
	{
		num = (int)ft_atol(argv[i]);
		append_node(a, num);
		i++;
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	if (*stack && stack)
	{
		temp = *stack;
		while (temp)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
		*stack = NULL;
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
