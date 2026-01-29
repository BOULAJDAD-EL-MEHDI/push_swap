/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:39:08 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/20 17:09:20 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		reverse_rotate_stack(node **top, node **tail)
{
	node	*temp;

	temp = (*tail);
	if (!(*top) || (*tail) == (*top))
		return (1);
	else
	{
		(*top)->prev = temp;
		temp->next = (*top);
		(*top) = temp;
		(*tail) = temp->prev;
		(*top)->prev = NULL;
		(*tail)->next = NULL;

	}
	return (0);
}
