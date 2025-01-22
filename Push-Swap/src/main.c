/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tombihoues <tombihoues@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:04:39 by tbihoues          #+#    #+#             */
/*   Updated: 2024/11/12 14:27:24 by tombihoues       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	process_args(int argc, char **argv, char ***args)
{
	if (argc == 2)
		*args = ft_split(argv[1], ' ');
	else
		*args = argv + 1;
	if (error_syntax(*args) || error_int(*args) || error_dup(*args))
	{
		if (argc == 2)
			free_split(*args);
		print_error();
	}
}

static void	sort_stack(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, 0);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else if (stack_len(*a) <= 5)
			sort(a, b, 1);
		else
			sort(a, b, 0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc == 1)
	{
		write(1, "Need Arguments\n", 15);
		return (0);
	}
	process_args(argc, argv, &args);
	fill_stack(&a, args);
	sort_stack(&a, &b);
	ft_free_stack(&a);
	if (argc == 2)
		free_split(args);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_stack		*a;
// 	t_stack		*b;
// 	char		**args;

// 	a = NULL;
// 	b = NULL;
// 	if (argc == 1)
// 		return (0);
// 	if (argc == 2)
// 		args = ft_split(argv[1], ' ');
// 	else
// 		args = argv + 1;
// 	if (error_syntax(args) || error_int(args) || error_dup(args))
// 	{
// 		if (argc == 2)
// 			free_split(args);
// 		print_error();
// 	}
// 	fill_stack(&a, args);
// 	if (!is_sorted(a))
// 	{
// 		if (stack_len(a) == 2)
// 			sa(&a, 0);
// 		else if (stack_len(a) == 3)
// 			sort_three(&a);
// 		else if (stack_len(a) <= 5)
// 			sort(&a, &b, 1);
// 		else
// 			sort(&a, &b, 0);
// 	}
// 	ft_free_stack(&a);
// 	if (argc == 2)
// 		free_split(args);
// 	return (0);
// }
