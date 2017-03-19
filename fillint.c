#include "fillint.h"
extern int getint(int *);

/* fillint: fills an array with integers from keyboard input*/
int fillint(int *array)
{
	int n, m;
	for(n = 0; n < SIZE && (m = getint(array + n)) != EOF; n++)
		;
	return n;

}

