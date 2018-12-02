#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

char *check_complement(char *s)
{
    if(strlen(s) == 5 && (*s == '~' && s++))
        for(int i = 0; i < 4; i++)
           s[i] =  s[i] == '1' ? '0' : '1';
    return(s);
}

char *getAnd(char *a, char *b)
{
    a = check_complement(a);
    b =  check_complement(b);
    
    for (int i = 3; i >= 0; i--)
        b[i] = (a[i] == '1' && b[i] == '1') ? '1' : '0';
    
    return(b);
}

char *getOr(char *a, char *b)
{
    a = check_complement(a);
    b =  check_complement(b);
    
    for (int i = 3; i >= 0; i--)
        b[i] = (a[i] == '1' ||  b[i] == '1') ? '1' : '0';
    return(b);
}

int toInt(char *bits)
{
	int base = 1;
	int sum = 0;
	for(int i = 3; i >= 0; i--)
	{
		if(bits[i] == '1')
			sum += base;
		base *= 2;
	}
	return(sum);
}