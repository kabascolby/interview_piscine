/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:15:51 by lkaba             #+#    #+#             */
/*   Updated: 2018/09/19 19:33:27 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void printReverse(struct s_node *head)
{

	if(head == NULL)
		return ;
	printReverse(head->next);
    if(head->next)
	    printf(" %s", head->word);
    else
	    printf("%s", head->word);
}