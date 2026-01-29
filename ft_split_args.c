/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:00:11 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/27 15:21:26 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i] && s[i] != ' ')
		{
			count++;
			while (s[i] && s[i] != ' ')
				i++;
		}
	}
	return (count);
}

static char	*word_dup(char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split_args(char *s)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	split = malloc((word_count(s) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		j = i;
		while (s[i] && s[i] != ' ')
			i++;
		if (i > j)
			split[k++] = word_dup(s, j, i);
	}
	split[k] = NULL;
	return (split);
}
