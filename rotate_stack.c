/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:39:12 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/02 16:37:26 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate_stack(node **top, node **tail)
{
	node	*temp;
	if (!top || !(*top) || !(*top)->next)
		return (0);
	temp = *top;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*tail)->next = temp;
	temp->prev = *tail;
	temp->next = NULL;
	return (1);
}