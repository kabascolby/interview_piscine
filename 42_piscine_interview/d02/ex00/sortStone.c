/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:12:16 by lkaba             #+#    #+#             */
/*   Updated: 2018/09/20 23:12:17 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

void swap(struct s_stone **a, struct s_stone **b)
{
	int c;
	c = (*a)->size;
	(*a)->size = (*b)->size;
	(*b)->size = c;
}

void sortStones(struct s_stone **stone)
{
	struct s_stone *i, *j;
	i = *stone;
	for(i = *stone; i != NULL; i = i->next)
	{
		int is_swap = 1;
		for(j = i->next; j != NULL; j = j->next)
		{
			if(i->size > j->size)
			{
				swap(&i, &j);
				is_swap = 0;
			}
		}
		if(is_swap)
			return;
	}
}