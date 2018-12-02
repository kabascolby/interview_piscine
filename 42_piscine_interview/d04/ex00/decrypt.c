#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#define C(a, b)
#include "header.h"

char *getSum(char *a, char *b)
{
	int carry = 0;
	for(int i = 5; i >= 0; i--)
	{
		while(i >= 0 && carry && a[i] == '1')
		{
			if(a[i] != '1')
			{
				a[i] = '1';
				carry = 0;
				break ;
			}
			i--;
		}
		if(a[i] == '1' && b[i] == '1')
		{
			b[i] = '0';
			carry = 1;
		}
		else if(a[i] != b[i])
		{
			b[i] = '1';
		}
		else if(carry && (a[i] == '0' && b[i] == '0'))
		{
			b[i] = '1';
			carry = 0;
		}

	}
	return b;
}

int toInt(char *bits)
{
	int base = 1;
	int sum = 0;
	for(int i = 5; i >= 0; i--)
	{
		if(bits[i] == '1')
			sum += base;
		base *= 2;
	}
	return(sum);
}