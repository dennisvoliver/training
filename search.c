#include<stdio.h>

#define MAXLINE 1000 /* buffer size */

char pattern[] = "ould"; /* pattern looked for */
int strindex(char s[], chart[]);

/* find all lines matching pattern */
int main()
{

	char line[MAXLINE];
	int found = 0;

	while(getmyline(line, MAXLINE) > 0){ /* while there is a line */
		if(strindex(line, pattern) >= 0) /* if pattern is found in that line */
			printf("%s", line); /* print that line */
			found++;	/* keep track of the number of lines found */
	}
	return found;
}

