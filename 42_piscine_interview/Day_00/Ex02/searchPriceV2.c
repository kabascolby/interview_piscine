/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:08:12 by lkaba             #+#    #+#             */
/*   Updated: 2018/09/18 14:59:23 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...


int bynarysearch(struct s_art **a, int l, int r, char * n)
{
    if(r >= l)
    {
        int mid = l + (r - l) / 2;
        if(!strcmp(a[mid]->name, n))
            return(mid);
        if(strcmp(a[mid]->name, n) > 0)
            return(bynarysearch(a, l, (mid - 1), n));
        return(bynarysearch(a, (mid + 1), r, n));
    }
    return -1;
}

int searchPrice(struct s_art **arts, int n, char *name)
{
    int index = bynarysearch(arts, 0, n, name);
        return(index > 0 ? arts[index]->price : -1);
}