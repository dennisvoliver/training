#include<string.h>
#include<stdlib.h>
#include<stdio.h> 
/* slice: cuts the preceding characters of a string copies them to a buffer, returns a pointer to the buffer */
char *slice(char *s)
{
	char *buf = malloc(strlen(s) + 1);
	strcpy(buf, s);
	*s = '\0';
	return buf;
}
