#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>
#include "header.h"

int number_of_nodes(struct s_node *r, int *i)
{
	if(!r)
		return(0);
	number_of_nodes(r->left, i);
		(*i)++;
	number_of_nodes(r->right, i);
	return(*i);
}

void get_min_max(struct s_node *r, int *i)
{
	if(!r)
		return;
	get_min_max(r->left, i);
	i[1] =  r->value > i[1] ? r->value: i[1];
	i[2] =  r->value < i[2] ? r->value: i[2];
	get_min_max(r->right, i);
}


int height(struct s_node *r)
{
	if(!r)
		return -1;
	int heightleft = height(r->left) + 1;
	int heightright = height(r->right) + 1;
	return(heightleft > heightright ? heightleft : heightright);
	// return(r &&  height(r->left) + 1 > height(r->left) + 1 ? height(r->left) + 1 : height(r->right) + 1);
}

	int isbalanced(struct s_node *r)
{
	if(!r)
		return -1;
	int heightleft = height(r->left) + 1;
	int heightright = height(r->right) + 1;
	return(abs(heightleft - heightright)  > 1 ? 0: 1);
}

int is_bst(struct s_node *r)
{
	if(!r)
		return(1);
	if(r->left && (r->left->value > r->value))
		return(0);
	if(r->right && (r->right->value < r->value))
		return(0);
	return(is_bst(r->left) && is_bst(r->right));
}


struct s_info   getInfo(struct s_node *root)
{
	struct s_info info;
	int i[6] = {0};
	memset(&info, 0, sizeof(struct s_info));

	info.elements = number_of_nodes(root, i);
	info.height = height(root);
	info.isBalanced = isbalanced(root);
	info.isBalanced = isbalanced(root);
	info.isBST = is_bst(root);
	i[1] = i[2] = root->value;
	get_min_max(root, i);
	info.max = i[1];
	info.min = i[2];
	return(info);
}