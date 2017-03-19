#include<stdio.h>

/* getlines: gets all lines and dumps them to one array, returns the number of characters */

int getlines(char *s, int last)  
{   
	if((*s = getch()) != EOF && last)
		return 1 + getlines(s + 1, last - 1);
	if(!last)
		ungetch(*s);
	*s = '\0';
	return 0;
}


