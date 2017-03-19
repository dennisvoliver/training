#include<stdio.h>

/* getmyline: get input from keyboard then dump result to s[] */
int getmyline (char s[], int last)  /* 1 */
{
        int i, c;

       for (i = 0; (c = getchar()) != EOF && i < (last - 1) && '\n' != c; ++i)
             s[i] = c;   

	/* ignore the EOF character but include the newline character */
	if('\n' == c)
		s[i++] = c;
        
	s[i] = '\0';         
	return i;



	
}


