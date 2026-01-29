/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_array_in_to_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:31:44 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/27 16:32:47 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void exit_error(node *stack)
{
	node *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	push_front_node(node **stack, int value)
{
	node	*new;

	new = malloc(sizeof(node));
	if (!new)
		exit_error(*stack);
	new->data = value;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	new->prev = NULL;
	*stack = new;
}

void	init_stack_from_array(node **stack, int *arr, int size)
{
	int	i;

	*stack = NULL;
	i = 0;
	while (i < size)
	{
		push_front_node(stack, arr[i]);
		i++;
	}
}