/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:39:02 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/04 16:59:59 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	   push_stack(node **top_a, node **tail_a, node **top_b, node **tail_b)
{
	node *temp;

	if (!top_a || !(*top_a))
		return (0);
	temp = *top_a;
	else if ((*top_a) ==  (tail_b))
	{
		*top_a = NULL;
		*tail_b = NULL;
	}
	else
		(*top_a) = temp->next;
	if (!top_b || !(*top_a))
	{
		(*top_b) = temp;
		(*tail_b) = temp;
	}
	else
		temp->next = (*top_b);
		(*top_b) = temp->prev;
}