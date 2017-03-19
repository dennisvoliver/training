#include<stdlib.h>
#include<string.h>

/* getdalines: reads and dumps all lines to a table, returns number of lines */
int getdalines(char *s[], int maxrow, int maxcol) 
{   
	extern int getdaline(char *s, int max);
/*
	if(0 < maxrow && 0 < getdaline(*s = malloc(maxcol), maxcol))
		return 1 + getdalines(s + 1, maxrow - 1, maxcol);
*/
	char line[maxcol];
	int len = getdaline(line, maxcol);

	if(0 >= maxrow || 0 >= len)
		return 0;

	strcpy(*s = malloc(len + 1), line);
	return 1 + getdalines(s + 1, maxrow - 1, maxcol);
}
