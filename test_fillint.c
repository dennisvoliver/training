/* cc test_fillint.c fillint.c getint.c getch.c */

#include "fillint.h"

extern int fillint(int *);

int main()
{
	int array[SIZE], i,  n = fillint(array);
	for(i = 0;i < n; i++)
		printf("%d\n", array[i]);
//		printf("%d\t", array[i]);
}
