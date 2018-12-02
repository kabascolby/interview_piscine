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

int pop(struct s_stack *stack)
{
    struct s_item *temp;
    int s;
    if(stack->item == NULL)
        return 0;
    temp = stack->item;
    s = temp->idx;
    stack->item = stack->item->next;
    free(temp);
    return(s);
}

void push(struct s_stack *stack, int idx)
{
    struct s_item *temp;
    temp = (struct s_item *)malloc(sizeof(struct s_item));
    temp->idx = idx;
    temp->next = stack->item;
    stack->item = temp;    
}

char *console(void)
{
    struct s_stack *h;
    h = stackInit();
    char *buff = (char *)malloc(255);

    int len;

    len = 0;

    while(1)
    {
       size_t linelen;
       linelen = 255;
        char *str;
        str = &buff[len];
        write(1, "?:", 3);
       (getp, getline(&buff, &linelen, stdin));
       // push(h, );
    }
    return(buff);
}