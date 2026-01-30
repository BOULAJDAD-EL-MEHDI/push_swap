/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:16:27 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/30 17:24:48 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error_two(node *stack)
{
	write(2, "Error\n", 6);
	while (stack)
	{
		node *tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	exit(1);
}

static void print_stack(node *stack)
{
	while (stack)
	{
		printf("data :%d  |index : %d\n", stack->data, stack->index);
		stack = stack->next;
	}
}


static void free_stack(node *stack)
{
	node *tmp;

	while (stack)
	{
		tmp = stack;
	stack = stack->next;
	free(tmp);
	}
}

static void free_tokens_local(char **tokens)
{
	int i;

	if (!tokens)
	return ;
	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}


int check_args(int argc, char **argv, int **out_arr, int *out_size)
{
	char *joined;
	char **tokens;
	int *arr;
	int size;

	if (!args_are_valid(argc, argv))
		return (0);
	joined = ft_join_args(argc, argv);
	if (!joined)
		return (0);
	tokens = ft_split_args(joined);
	free(joined);
	if (!tokens)
		return (0);
	arr = args_to_int_array(tokens, &size);
	if (!arr || check_duplicate(arr, size))
	{
		free_tokens_local(tokens);
		free(arr);
		return (0);
	}
	free_tokens_local(tokens);
	*out_arr = arr;
	*out_size = size;
	return (1);
}


int push_args_to_stack(node **stack, int *arr, int size)
{
	if (!arr || size <= 0)
		return (0);
	init_stack_from_array(stack, arr, size);
	return (1);
}

void	set_ptrs_to_null(node **stack_a_top, node **stack_a_tail, node **stack_b_top, node **stack_b_tail)
{
	*stack_a_top = NULL;
	*stack_a_tail = NULL;
	*stack_b_top = NULL;
	*stack_b_tail = NULL;
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	parcing(int argc, char **argv, int **arr, int *size)
{
	if (argc < 2 || !check_args(argc, argv, arr, size))
		error_exit();
}

void	check_push_to_stack(node **stack_a, int *arr, int size)
{
	if (!push_args_to_stack(stack_a, arr, size))
	{
		free(arr);
		error_exit();
	}
}

void printnode(node *a)
{
	while(a)
	{
		printf("%d->", a->data);
		a = a->next;
	}
	printf("NULL");
}

int main(int argc, char **argv)
{
	node	*stack_a_top;
	node	*stack_b_top;
	node	*stack_a_tail;
	node	*stack_b_tail;
	int		*arr;
	int		size;

	arr = NULL;
	size = 0;
	set_ptrs_to_null(&stack_a_top, &stack_a_tail, &stack_b_top, &stack_b_tail);
	parcing(argc, argv, &arr, &size);
	check_push_to_stack(&stack_a_top, arr, size);
	printnode(stack_a_top);
	indexing(stack_a_top);
	sort_stack(&stack_a_top, &stack_a_tail, &stack_b_top, &stack_b_tail);
	print_stack(stack_a_top);
	free(arr);
	free_stack(stack_a_top);
	return (0);
}
