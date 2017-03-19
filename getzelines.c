#include<stdio.h>

extern int getzeline(char *s, int max);
extern char *alloc(int n);

/* getzelines: reads and dumps all lines to a table, returns number of lines */
int getzelines(char *s[], int maxrow, int maxcol) 
{   
	if(maxrow && getzeline(*s = alloc(maxcol), maxcol))
		return 1 + getzelines(s + 1, maxrow - 1, maxcol);
	return 0;
}
