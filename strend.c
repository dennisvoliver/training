#include<string.h>

/* strend: returns 1 if the string t occurs at the end of string s */
int strend(char *s, char *t)
{
	char *sp = s + strlen(s) + 1;
	char *tp = t + strlen(t) + 1;

	while(*--tp == *--sp)
		;
	if(tp < t)
		return 1;
	return 0;
}

