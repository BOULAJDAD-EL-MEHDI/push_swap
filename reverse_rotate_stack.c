/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:39:08 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/02 16:36:16 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		reverse_rotate_stack(node **top, node **tail)
{
	node	*temp;

	temp = *tail;
	if (!tail || !(*tail) || !(*tail)->prev)
		return (0);
	*tail = temp->prev;
	temp->next = *top;
	temp->prev = NULL;
	(*top)->prev = temp;
	*top = (*top)->prev;
	return (1);
}