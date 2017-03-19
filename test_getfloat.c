/* cc test_getfloat.c getfloat.c getch.c && ./a.out */

#include<stdio.h>
#define MAX 100
extern int getfloat(double *);

int main()
{
	double d;
	int c;
	getfloat(&d);
	printf("%d\t%g\n", c, d);
}
