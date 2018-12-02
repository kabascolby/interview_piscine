/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:11:48 by lkaba             #+#    #+#             */
/*   Updated: 2018/09/20 23:11:49 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

void countSort(unsigned char *utensils, int n)
{
    int count[16] = {0};
    for(int i = 0; i < n; i++)
        count[utensils[i]]++;
    
    int index = 0;
    for(int i = 0; i < 16; i++)
        while(count[i]--)
            utensils[index++] = i;
}