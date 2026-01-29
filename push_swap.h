/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:07:00 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/28 13:35:11 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	struct Node	*prev;
	struct Node	*next;
	int		data;
	int 	index;
}node;

int    swap_stack(node **top);
int	   sswap_stack(node **top_a, node **top_b);
int		push_stack(node **top_a, node **tail_a, node **top_b, node **tail_b);
int    rotate_stack(node **top, node **tail);
int    rrotate_stack(node **top_a, node **tail_a, node **top_b, node **tail_b);
int    reverse_rotate_stack(node **top, node **tail);
int    rreverse_rotate_stack(node **top_a, node **tail_a, node **top_b, node **tail_b);
void	init_stack_from_array(node **stack, int *arr, int size);
void	push_front_node(node **stack, int value);
int		check_duplicate(int *arr, int size);
int		*args_to_int_array(char **tokens, int *size);
char	**ft_split_args(char *s);
char	*ft_join_args(int argc, char **argv);
int    args_are_valid(int argc, char **argv);


#endif
