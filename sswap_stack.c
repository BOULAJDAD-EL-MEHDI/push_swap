/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sswap_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:39:22 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/01 16:47:21 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	   sswap_stack(node **top_a, node **top_b)
{
	int		a;
	int		b;

	a = swap_stack(top_a);
	b = swap_stack(top_b);
	if (a && b)
		return(1);
	return (0);
}