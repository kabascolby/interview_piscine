/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:12:06 by lkaba             #+#    #+#             */
/*   Updated: 2018/09/20 23:12:19 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

void insertionSort(struct s_player **players)
{
    int pos;
    struct s_player *tmp;
    for (int i = 1; players[i]; i++)
    {
        pos = i;
        tmp = players[i];       
        while(pos > 0 && players[pos - 1]->score < tmp->score)
        {
            players[pos] = players[pos - 1];
            pos--;
        }
        players[pos] = tmp;
    }
}