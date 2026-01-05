/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:07:00 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/03 11:01:15 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node	*prev;
	struct Node	*next;
	int		data;
}	node;

int    swap_stack(node **top);
int	   sswap_stack(node **top_a, node **top_b);
int		push_stack(node **top_a, node **tail_a, node **top_b, node **tail_b);
int    rotate_stack(node **top, node **tail);
int    rrotate_stack(node **top_a, node **tail_a, node **top_b, node **tail_b);
int    reverse_rotate_stack(node **top, node **tail);
int    rreverse_rotate_stack(node **top_a, node **tail_a, node **top_b, node **tail_b);

#endif
