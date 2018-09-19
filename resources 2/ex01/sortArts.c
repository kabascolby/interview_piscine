/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:40:58 by lkaba             #+#    #+#             */
/*   Updated: 2018/09/18 14:04:29 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void merge(struct s_art **a, struct s_art **l, struct s_art **r, int nl, int nr)
{
    int i = 0, j = 0, k = 0;

    while( i < nl && j < nr)
    {
        if(strcmp(l[i]->name, r[j]->name) < 0)
        {
            a[k] = l[i];
            i++;
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

int array_size(struct s_art **a)
{
    int i = -1;
    while(a[++i])
        ;
        printf("i = %d\n", i);
    return (i);
}

void merge_sort(struct s_art **a, int n)
{
    int nl, nr;

    if(n < 2)
        return ;
    nl = n / 2;
    nr = n - nl;
    struct s_art *l[nl];
    struct s_art *r[nr];
    
    for (int i = 0; i < nl; i++)
       l[i] = a[i];

    int j = nl;
    for (int i = 0; i < nr; i++)
        r[i] = a[j++];
    
    merge_sort(l, nl);
    merge_sort(r, nr);
    merge(a, l, r, nl, nr);
}

void  sortArts(struct s_art **arts)
{
    int n;
    n =array_size(arts);
    merge_sort(arts, n);
}
