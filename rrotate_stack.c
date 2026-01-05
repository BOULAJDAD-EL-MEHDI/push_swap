/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:39:18 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/02 16:55:28 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rrotate_stack(node **top_a, node **tail_a, node **top_b, node **tail_b)
{
	int		a;
	int		b;

	a = rotate_stack(top_a, tail_a);
	b = rotate_stack(top_b, tail_b);
	if (a && b)
		return (1);
	return (0);
}