/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:11:06 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/28 14:21:37 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_char(char c)
{
	return (c == ' ' || c == '+' || c == '-'
		|| (c >= '0' && c <= '9'));
}

int	just_spaces(char *argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i])
	{
		if (argv[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_chars(char *argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i])
	{
		if (!is_valid_char(argv[i]))
			return (0);
		i++;
	}
	if (just_spaces(argv))
		return (0);
	return (1);
}

int	is_two_signes(char x, char y)
{
	if ((x == '+' || x == '-') && (y == '+' || y == '-'))
		return (1);
	return (0);
}

int	is_valid_arg(char *argv)
{
	int	i;

	if (!argv || !is_valid_chars(argv))
		return (0);
	i = 0;
	while (argv[i])
	{
		if (argv[i] == '+' || argv[i] == '-')
		{
			if (i > 0 && argv[i - 1] != ' ')
				return (0);
			if (argv[i + 1] < '0' || argv[i + 1] > '9')
				return (0);
			if (is_two_signes(argv[i], argv[i + 1]))
				return (0);
		}
		i++;
	}
	return (1);
}

int    args_are_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_arg(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
