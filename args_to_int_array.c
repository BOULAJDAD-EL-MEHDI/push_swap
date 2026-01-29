/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_int_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:23:13 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/28 17:33:34 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(const char *s, int *error)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	*error = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
		sign = -1;
		i++;
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			break;
		if (res > 217483647 / 10 || (res == 217483647 / 10 && s[i] - '0' > (sign == 1 ? 7 : 8)))
		{
			*error = 1;
			return (0);
		}
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sign);
}

int	*args_to_int_array(char **tokens, int *size)
{
	int	*arr;
	int	i;
	int	error;

	i = 0;
	while (tokens[i])
		i++;
	*size = i;
	arr = malloc(sizeof(int) * i);
	if (!arr)
		return (NULL);
	i = 0;
	while (tokens[i])
	{
		error = 0;
		arr[i] = ft_atoi(tokens[i], &error);
		if (error)
		{
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}