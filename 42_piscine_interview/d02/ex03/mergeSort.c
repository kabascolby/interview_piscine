/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:11:54 by lkaba             #+#    #+#             */
/*   Updated: 2018/09/20 23:12:02 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

int compare_time(char *time1, char *time2)
{
    struct tm t1;
    struct tm t2;
    strptime(time1, "%Y-%m-%d %T", &t1);
    strptime(time2, "%Y-%m-%d %T", &t2);
    time_t mt1 = mktime(&t1);
    time_t mt2 = mktime(&t1);
    return(difftime(mt1, mt2) > 0 ? 1 : 0);
}

void merge(struct s_player **a, struct s_player **l, struct s_player **r, int nl, int nr)
{
    int i = 0, j = 0, k = 0;

    while( i < nl && j < nr)
    {
        if(l[i]->score > r[j]->score)
        {
            a[k] = l[i];
            i++;
        }
        else if(l[i]->score == r[j]->score)
        {
            if(!compare_time(l[i]->timeStamp, r[j]->timeStamp))
                a[k] = l[i++];
            else
                a[k] = r[j++];
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while(i < nl)
        a[k++] = l[i++];
    while(j < nr)
        a[k++] = r[j++];
}


int array_size(struct s_player **a)
{
    int i = -1;
    while(a[++i])
        ;
    return (i);
}

void merge_sort_array(struct s_player **a, int n)
{
    int nl, nr;

    if(n < 2)
        return ;
    nl = n / 2;
    nr = n - nl;
    struct s_player *l[nl];
    struct s_player *r[nr];
    
    for (int i = 0; i < nl; i++)
       l[i] = a[i];

    int j = nl;
    for (int i = 0; i < nr; i++)
        r[i] = a[j++];
    
    merge_sort_array(l, nl);
    merge_sort_array(r, nr);
    merge(a, l, r, nl, nr);
}

struct s_player **mergeSort(struct s_player **players)
{
    int n;
    n = array_size(players);
    merge_sort_array(players, n);
    return(players);
}