/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:17:31 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/30 15:02:22 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	push_tail(node **top_one, node **tail_one, node **top_two, node **tail_two)
// {
// 	node	*temp;

// 	temp = (*top_two);
// 	(*top_two) = NULL;
// 	(*tail_two) = NULL;
// 	temp->next = NULL;
// 	temp->prev = NULL;
// 	if (*top_one)
// 	{
// 		(*top_one)->prev = temp;
// 		temp->next = (*top_one);
// 		(*top_one) = temp;
// 	}
// 	else
// 	{
// 		(*top_one) = temp;
// 		(*tail_one) = temp;
// 	}
// }

// static void	push_head(node **top_one, node **tail_one, node **top_two)
// {
// 	node	*temp;

// 	temp = (*top_two);
// 	(*top_two) = (*top_two)->next;
// 	temp->next = NULL;
// 	temp->prev = NULL;
// 	if (*top_one)
// 	{
// 		temp->next = (*top_one);
// 		(*top_one)->prev = temp;
// 		(*top_one) = temp;
// 	}
// 	else
// 	{
// 		(*top_one) = temp;
// 		(*tail_one) = temp;
// 	}
// }

int	push_stack(node **top_one, node **tail_one, node **top_two, node **tail_two)
{
	node	*temp;

	if (!*top_two)
    	return (0);
	temp = *top_two;
	*top_two = temp->next;
	if (*top_two)
    	(*top_two)->prev = NULL;
	else
    	*tail_two = NULL;
	temp->next = *top_one;
	temp->prev = NULL;
	if (*top_one)
	    (*top_one)->prev = temp;
	else
	    *tail_one = temp;
	*top_one = temp;
	return (1);
}
