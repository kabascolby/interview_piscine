#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include "header.h"

struct s_stack  *stackInit(void)
{
    struct s_stack * h;
    h = (struct s_stack *)malloc(sizeof (struct s_stack));
    if(!h)
        return NULL;
    h->item = NULL;
    return(h);
}

void *pop(struct s_stack *stack)
{
    struct s_item *temp;
    char *s;
    if(stack->item == NULL)
        return NULL;
    temp = stack->item;
    s = temp->word;
    stack->item = stack->item->next;
    free(temp);
    return(s);
}

void push(struct s_stack *stack, char *word)
{
    struct s_item *temp;
    temp = (struct s_item *)malloc(sizeof(struct s_item));
    temp->word = word;
    temp->next = stack->item;
    stack->item = temp;    
}

void printReverseV2(struct s_node *lst)
{
    struct s_stack *h;
    h = stackInit();
    while(lst)
    {
        push(h, lst->word);
        lst = lst->next;
    }

    while(h->item)
    {
        if(h->item->next)
            printf("%s ", (char *)pop(h));
        else
            printf("%s", (char *)pop(h));
    }
}
