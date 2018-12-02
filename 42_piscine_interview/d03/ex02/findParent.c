#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	if(!root)
		return(NULL);
	for(int i = 0; root->children[i]; i++)
	{
		if(!root->children[i])
			return(NULL);
		if(!strcmp(root->children[i]->name, firstSpecies) && !strcmp(root->children[i]->name, secondSpecies))
			return(root->children[i]);
	}


}