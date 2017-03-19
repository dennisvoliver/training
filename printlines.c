#include<stdio.h>
#include<string.h>

/* printlines: prints array of strings */
int printlines(char *s[], int lines)
{
	if(0 < lines){
		printf("%s\t: %d characters \n", *s, (int)strlen(*s));
		printlines(s + 1, lines - 1);
	}
	return 0;
}
