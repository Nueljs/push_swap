/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 06:23:35 by macerver          #+#    #+#             */
/*   Updated: 2026/02/18 10:31:08 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			words++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static int	word_len(const char *str, char c)
{
	int	j;

	j = 0;
	if (str[j] != c)
	{
		while (str[j] && str[j] != c)
			j++;
	}
	return (j);
}

static int	split_words(char const *s, char c, char **split, int words)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j] && i < words)
	{
		if (s[j] != c)
		{
			split[i] = ft_substr(s, j, word_len(&s[j], c));
			if (!split[i])
			{
				while (--i >= 0)
					free(split[i]);
				free(split);
				return (0);
			}
			i++;
			while (s[j] && s[j] != c)
				j++;
		}
		else
			j++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[words] = NULL;
	if (!split_words(s, c, split, words))
		return (NULL);
	return (split);
}
