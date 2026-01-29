/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:41:15 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/27 14:49:47 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	i;

	ret = malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ret[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[j++] = s2[i++];
	ret[j] = '\0';
	return (ret);
}

static char	*join_step(char *ret, char *arg, int space)
{
	char	*tmp;

	tmp = ft_strjoin(ret, arg);
	free(ret);
	if (!tmp)
		return (NULL);
	ret = tmp;
	if (space)
	{
		tmp = ft_strjoin(ret, " ");
		free(ret);
		if (!tmp)
			return (NULL);
		ret = tmp;
	}
	return (ret);
}

char	*ft_join_args(int argc, char **argv)
{
	int		i;
	char	*ret;

	ret = ft_strdup("");
	if (!ret)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		ret = join_step(ret, argv[i], i + 1 < argc);
		if (!ret)
			return (NULL);
		i++;
	}
	return (ret);
}
