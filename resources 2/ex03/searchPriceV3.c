#include "header.h"
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

size_t hash(char *input) //return hash result
{
	size_t hash = 5381;
    for (int i = 0; input[i]; i++){
        hash = ((hash << 5) + hash) + input[i];
		printf("%shere----------\n", input);	

    }
    return hash;
}

struct s_dict *dictInit(int capacity) //initialize the dictionnary, given as parameter the capacity of the array.
{
	struct s_dict *dict;
	dict = (struct s_dict *)malloc(sizeof(struct s_dict));
	dict->items = (struct s_item **)malloc(sizeof(struct s_item *) * capacity);
	for(int i = 0; i < capacity; i++)
		dict->items[i] = 0;
	dict->capacity = capacity;
	return(dict);
}

struct s_item *create_value (struct s_item *v, char *key, struct s_art *value)
{
	v = (struct s_item *)malloc(sizeof(struct s_item));
	v->key = strdup(key);
	v->value = value;
	v->next = NULL;
	return(v);
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value) //add one element in the dictionnary, if FAIL return 0, otherwise 1
{
	if(value == NULL || key == NULL)
		return(0);
	int key_value = hash(key) % dict->capacity;
	printf("here----------\n");	

	
	struct s_item *temp = dict->items[key_value];
	if(temp != NULL)
	{
		while(temp)
		{
			if(strcmp(temp->key, key) == 0)
			{
				temp->value = value;
				return 1;
			}
			if(temp->next == NULL)
			{
				temp->next =  create_value(temp, key, value);
				return 1;
			}
			temp = temp->next;
		}
		temp = create_value(temp, key, value);
		return 1;
	}
	else
	{
		dict->items[key_value] = create_value(temp, key, value);
		return 1;
	}
	return(0);
}

struct s_art *dictSearch(struct s_dict *dict, char *key) //find one element in the dictionnary, if not found, return NULL
{
	int key_value = hash(key) % dict->capacity;
	if(dict->items[key_value])
	{
		printf("key_value = %i\n", key_value);
		struct s_item  *temp = dict->items[key_value];
		while(temp)
		{
			if(strcmp(temp->key, key) == 0)
				return(temp->value);
			temp = temp->next;
		}
	}
	return(NULL);
}

int searchPrice(struct s_dict *dict, char *name)
{
	struct s_art *tmp;
		tmp = NULL;
	if(dict && name)
		tmp = dictSearch(dict, name);
		printf("name = %s | string = %s\n", name, tmp->name);
	return(tmp ? tmp->price : -1);
}