/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:07:28 by lkaba             #+#    #+#             */
/*   Updated: 2018/09/17 13:36:42 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int  searchPrice(struct s_art **arts, char *name)
{
	uint32_t i;
	i = -1;
	while(arts[++i])
	{
		if (!strcmp(arts[i]->name, name))
			return (arts[i]->price);
	}
	return(-1);
}