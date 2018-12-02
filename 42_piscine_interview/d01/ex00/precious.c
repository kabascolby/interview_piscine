/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:52:05 by lkaba             #+#    #+#             */
/*   Updated: 2018/09/19 19:02:09 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include "header.h"

/*
**Create a double linked list node
*/

struct s_node	*create_dsllnode(char c)
{
	struct s_node	*temp;

	temp = (struct s_node *)malloc(sizeof(struct s_node));
	temp->c = c;
	temp->prev = NULL;
	temp->next = NULL;
	return (temp);
}

/*
** Insert a node at the head of given linked list
** first time the head is NULL so the
** the temp->next will be NULL at the first time;
** We can call this operation Push or Insert at head
*/

struct s_node	*pushend_dsll(char c, struct s_node *head)
{
	struct s_node	*temp;
	struct s_node   *last;

	temp = create_dsllnode(c);
	if (head == NULL)
	{
		head = temp;
		temp->next = head;
		temp->prev = head;
		return head;
	}
	last = head;
	while(last->next != head)
		last = last->next;
	last->next = temp;
	temp->prev = last;
	temp->next = head;
	head->prev = temp;
	return head;
}

struct s_node	* printchar(struct s_node *h, int n, char *c)
{
	if(n > 0)
		while(n--)
			h = h->next;
	else
		while(n++)
			h = h->prev;
	*c = h->c;
	return h;
}

char *precious(int *text, int size)
{
	struct s_node *h;
	static char tab[100];
	h = NULL;
	
	int i = -1, len = strlen(CS);

	while(++i < len)
		h = pushend_dsll(CS[i], h);
	struct s_node *tmp = h;
	for(i = 0; i < size; i++)
		tmp = printchar(tmp, text[i], &tab[i]);
	return(tab);
}