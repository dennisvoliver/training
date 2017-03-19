#include<stdio.h>
/* mygetline: reads a line from input and dumps to a pointer-to-char, newline not included */
int mygetline(char *s)
{
	int c = getchar();
	if(EOF == c || '\n' == c)
		return (*s = '\0');
	*s = c;
	return 1 + mygetline(s + 1);

}
