/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:56 by eboulajd          #+#    #+#             */
/*   Updated: 2026/01/29 15:37:38 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(node *a)
{
    int count = 0;

    while (a)
    {
        count++;
        a = a->next;
    }
    return count;
}

void fill_array(node *a, int *arr)
{
    int i = 0;

    while (a)
    {
        arr[i++] = a->data;
        a = a->next;
    }
}

void sort_array(int *arr, int size)
{
    int i;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
            i = 0;
        }
        else
            i++;
    }
}

void assign_index(node *a, int *arr, int size)
{
    int i;

    while (a)
    {
        i = 0;
        while (i < size)
        {
            if (a->data == arr[i])
            {
                a->index = i;
                break;
            }
            i++;
        }
        a = a->next;
    }
}

void indexing(node *a)
{
    int *arr;
    int size;

    size = stack_size(a);
    arr = malloc(sizeof(int) * size);
    if (!arr)
        return;

    fill_array(a, arr);
    sort_array(arr, size);
    assign_index(a, arr, size);

    free(arr);
}
