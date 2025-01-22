/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:17:39 by tbihoues          #+#    #+#             */
/*   Updated: 2024/10/05 20:53:25 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	count_words(const char *s, char delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != delimiter && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == delimiter)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*allocate_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 1) * sizeof(char));
	i = 0;
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static char	**split_words(const char *s, char delimiter, char **result)
{
	int	i;
	int	start;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == delimiter)
			i++;
		start = i;
		while (s[i] && s[i] != delimiter)
			i++;
		if (start < i)
		{
			result[j] = allocate_word(s, start, i);
			if (!result[j])
				return (NULL);
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(const char *s, char delimiter)
{
	char	**result;

	if (!s || !*s)
	{
		result = malloc(sizeof(char *));
		if (!result)
			return (NULL);
		result[0] = NULL;
		return (result);
	}
	result = malloc((count_words(s, delimiter) + 1) * sizeof(char *));
	if (!result)
	{
		free_split(result);
		return (NULL);
	}
	return (split_words(s, delimiter, result));
}

// char	**ft_split(const char *s, char delimiter)
// {
// 	int		i;
// 	int		start;
// 	int		j;
// 	char	**result;

// 	i = 0;
// 	j = 0;
// 	start = 0;
// 	if (!s || !*s)
// 	{
// 		result = malloc(sizeof(char *));
// 		if (!result)
// 			return (NULL);
// 		result[0] = NULL;
// 		return (result);
// 	}
// 	result = malloc((count_words(s, delimiter) + 1) * sizeof(char *));
// 	if (!result)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		while (s[i] == delimiter)
// 			i++;
// 		start = i;
// 		while (s[i] && s[i] != delimiter)
// 			i++;
// 		if (start < i)
// 		{
// 			result[j] = allocate_word(s, start, i);
// 			if (!result[j])
// 				return (NULL);
// 			j++;
// 		}
// 	}
// 	result[j] = (NULL);
// 	return (result);
// }
