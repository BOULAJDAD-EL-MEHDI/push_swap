/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:10:17 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/30 17:28:53 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h> // for INT_MAX, INT_MIN

static void sort_three(node **a, node **ta)
{
    int first, second, third;

    if (!a || !*a || !(*a)->next || !(*a)->next->next)
        return;

    first = (*a)->index;
    second = (*a)->next->index;
    third = (*a)->next->next->index;

    if (first > second && first < third)
        swap_stack(a);           // sa
    else if (first > second && second > third)
    {
        swap_stack(a);
        reverse_rotate_stack(a, ta); // rra
    }
    else if (first > second && second < third)
        rotate_stack(a, ta);     // ra
    else if (first < second && first > third)
        reverse_rotate_stack(a, ta); // rra
    else if (first < second && second > third)
    {
        swap_stack(a);
        rotate_stack(a, ta);     // sa + ra
    }
}

void sort_small(node **a, node **ta, node **b, node **tb)
{
    if (!a || !ta || !b || !tb)
        return;

    int size = stack_size(*a);
    if (size < 2)
        return;

    if (size == 2)
    {
        if ((*a)->index > (*a)->next->index)
            swap_stack(a);        // sa
        return;
    }

    if (size == 3)
    {
        sort_three(a, ta);
        return;
    }

    if (size == 4 || size == 5)
    {
        while (stack_size(*a) > 3)
        {
            /* find min and its position */
            node *tmp = *a;
            int min = INT_MAX;
            int pos = 0;
            int i = 0;
            while (tmp)
            {
                if (tmp->index < min)
                {
                    min = tmp->index;
                    pos = i;
                }
                tmp = tmp->next;
                ++i;
            }

            int cur_size = stack_size(*a);
            int rotations;

            if (pos <= cur_size / 2)
            {
                rotations = pos;
                for (i = 0; i < rotations; ++i)
                    rotate_stack(a, ta);        // ra
            }
            else
            {
                rotations = cur_size - pos;
                for (i = 0; i < rotations; ++i)
                    reverse_rotate_stack(a, ta); // rra
            }

            /* push smallest to B */
            push_stack(b, tb, a, ta);           // pb
        }

        /* sort remaining 3 */
        sort_three(a, ta);

        /* push back from B in correct order */
        while (*b)
            push_stack(a, ta, b, tb);          // pa
    }
}

/* helper that gets position of max in B (safer) */
static int max_index_pos(node *b)
{
    if (!b) return -1;
    int max = b->index;
    int pos = 0;
    int i = 0;

    while (b)
    {
        if (b->index > max)
        {
            max = b->index;
            pos = i;
        }
        b = b->next;
        ++i;
    }
    return pos;
}

void push_back(node **a, node **ta, node **b, node **tb)
{
    if (!a || !ta || !b || !tb)
        return;

    while (*b)
    {
        int size = stack_size(*b);
        int pos = max_index_pos(*b);
        if (pos < 0) break;

        int rotations;
        int i;
        if (pos <= size / 2)
        {
            rotations = pos;
            for (i = 0; i < rotations; ++i)
                rotate_stack(b, tb);           // rb
        }
        else
        {
            rotations = size - pos;
            for (i = 0; i < rotations; ++i)
                reverse_rotate_stack(b, tb);   // rrb
        }

        push_stack(a, ta, b, tb);              // pa
    }
}