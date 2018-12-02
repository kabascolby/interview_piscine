#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_art {
	char *name;
	int price;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/

void  sortArts(struct s_art **arts);
void  merge(struct s_art **a, struct s_art **l, struct s_art **r, int nl, int nr);
int   array_size(struct s_art **a);
void  merge_sort(struct s_art **a, int n);
void  sortArts(struct s_art **arts);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

struct s_art **getArts(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
