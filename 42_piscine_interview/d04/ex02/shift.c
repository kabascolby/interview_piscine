#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

char *rightShift(char *bin, int k)
{
    // char tab[i]
    if(k == 5)
    return("111111");
    if(k > 0)
    {        
        for(int i = 0; i < k; i++)
            bin[k + i] = bin[i % k];
        for(int i = 0; i < k; i++)
            bin[i] = '1';
    }
    return (bin);
}
char *leftShift(char *bin, int k)
{
    if(k == 5)
    return("000000");
    int len = strlen(bin);
    for(int i = len - 1; i > k; i--)
        bin[k + i] = bin[i % k];
    for(int i = 0; i < k; i++)
        bin[i] = '1';
    return("000000");

}
// int toInt(char *bits)
int toInt(char *bits)
{
    int len = strlen(bits) - 1;
	int base = 1;
	int sum = 0;
	for(int i = len; i > 2; i--)
	{
		if(bits[i] == '1')
			sum += base;
		base *= 2;
	}
	return(bits[0] == '1' ? -sum : sum);
}