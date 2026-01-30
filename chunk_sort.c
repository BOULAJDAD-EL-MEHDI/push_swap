/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:03:29 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/30 17:26:23 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_big(node **a, node **ta, node **b, node **tb)
{
    int size;
    int chunk;

    size = stack_size(*a);
    if (size <= 100)
        chunk = 15;
    else
        chunk = 30;
    push_chunks(a, ta, b, tb, chunk);
    push_back(a, ta, b, tb);
}

 void push_chunks(node **a, node **ta, node **b, node **tb, int chunk)
{
    int min;
    int max;

    min = 0;
    max = chunk;
    while (*a)
    {
        if ((*a)->index >= min && (*a)->index < max)
        {
            push_stack(b, tb, a, ta);
            if ((*b)->index < min + chunk / 2)
                rotate_stack(b, tb);
            min++;
            max++;
        }
        else
            rotate_stack(a, ta);
    }
}

// static int max_index_pos(node *b)
// {
//     int max;
//     int pos;
//     int i;

//     max = b->index;
//     pos = 0;
//     i = 0;
//     while (b)
//     {
//         if (b->index > max)
//         {
//             max = b->index;
//             pos = i;
//         }
//         b = b->next;
//         i++;
//     }
//     return (pos);
// }

void sort_stack(node **top_a, node **tail_a, node **top_b, node **tail_b)
{
    int size;

    size = stack_size(*top_a);
    if (size <= 1)
        return;
    indexing(*top_a);
    if (size <= 5)
        sort_small(top_a, tail_a, top_b, tail_b);
    else
        sort_big(top_a, tail_a, top_b, tail_b);
}