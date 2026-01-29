/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:53:43 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/18 19:06:24 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

node*	make_stack_node(int data)
{
	node *ret_node;

	ret_node = (node *)malloc(sizeof(node));
	if (!ret_node)
		return (NULL);
	ret_node->next = NULL;
	ret_node->prev = NULL;
	ret_node->data = data;
	return (ret_node);
}

int		is_stack_empty(node **top)
{
	return (!top || !(*top));
}

void	printf_stack(node **top)
{
	node *temp;

	if (is_stack_empty(top))
	{
		printf("stack is empty !\n");
		return ;
	}
	temp = *top;
	while (temp->next)
	{
		printf("\n|%d|\n", temp->data);
		temp = temp->next;
	}
	return ;
}
