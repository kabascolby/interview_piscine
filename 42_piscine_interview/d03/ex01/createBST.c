#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

struct s_node *create_node(int n)
{
	struct s_node *tmp;
	tmp = (struct s_node *)malloc(sizeof(struct s_node));
	tmp->value = n;
	tmp->left = NULL;
	tmp->right = NULL;
	return(tmp);
}

struct s_node *convert_array_to_bbst(int *arr, int s, int e)
{
	if(s > e)
	return 0;
	int mid = (s + e)/2;
	struct s_node *root = create_node(arr[mid]);
	if(!root)
		return(NULL);
	root->left = convert_array_to_bbst(arr, s, mid - 1);
	root->right = convert_array_to_bbst(arr, mid + 1, e);
	return(root);
}


struct s_node *createBST(int *arr, int n)
{
	struct s_node *root;
	root = convert_array_to_bbst(arr, 0, n - 1);
	return(root);	
}