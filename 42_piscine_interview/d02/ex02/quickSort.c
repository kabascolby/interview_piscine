/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:11:59 by lkaba             #+#    #+#             */
/*   Updated: 2018/09/20 23:12:00 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

void swap(struct s_player **a, struct s_player **b)
{
	struct s_player *c;
	c = *a;
	*a = *b;
	*b = c;
}

int sort_partition(struct s_player **a, int s, int e)
{
    struct s_player *end = a[e];
    int index = s;
    for (int i = s; i < e; i++)
    {
        if(a[i]->score > end->score)
        {
            swap(&a[i], &a[index]);
            index++;
        }
    }
    swap(&a[index], &a[e]);
    return(index);
}

void divide_array(struct s_player **a, int s, int e)
{
    if(s < e)
    {
        int index = sort_partition(a, s, e);
        divide_array(a, s, index - 1);
        divide_array(a, index + 1, e);
    }
}

void quickSort(struct s_player **players)
{
    int len = 0;
    for(int i = 0; players[i]; i++)
        len++;
        printf("len = %i", len);
    divide_array(players, 0, len - 1);
}