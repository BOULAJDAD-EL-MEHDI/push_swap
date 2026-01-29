/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:17:31 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/20 14:17:38 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_tail(node **top_one, node **tail_one, node **top_two, node **tail_two)
{
	node	*temp;

	temp = (*top_two);
	(*top_two) = NULL;
	(*tail_two) = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	if (*top_one)
	{
		(*top_one)->prev = temp;
		temp->next = (*top_one);
		(*top_one) = temp;
	}
	else
	{
		(*top_one) = temp;
		(*tail_one) = temp;
	}
}

static void	push_head(node **top_one, node **tail_one, node **top_two)
{
	node	*temp;

	temp = (*top_two);
	(*top_two) = (*top_two)->next;
	temp->next = NULL;
	temp->prev = NULL;
	if (*top_one)
	{
		temp->next = (*top_one);
		(*top_one)->prev = temp;
		(*top_one) = temp;
	}
	else
	{
		(*top_one) = temp;
		(*tail_one) = temp;
	}
}

int	push_stack(node **top_one, node **tail_one, node **top_two, node **tail_two)
{
	if ((*top_two) == (*tail_two) && (*top_two) == NULL)
		return (0);
	if ((*top_two) == (*tail_two))
		push_tail(top_one, tail_one, top_two, tail_two);
	else
		push_head(top_one, tail_one, top_two);
	return (1);
}
