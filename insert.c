#include<stdio.h>

extern char *slice(char *s);
extern char *strfsh(char *dest, char *src); /* strcat that can be nested without overhead */

/* insert: inserts src to dest before the nth character */
int insert(char *dest, char *src, int n)
{
	if(1 < n && *dest)
		return insert(dest + 1, src, n - 1);
	char *buf = slice(dest);
	strfsh(strfsh(dest, src), buf);
	return 0;
}

