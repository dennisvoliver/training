#include<stdio.h>

int dtoi(char s[]);
int getmyline (char s[], int last);
int getint(char str[], int max);


/* flab: program that tests functions */ 
int main()
{
	char str[10];

	printf("%d\n", getint(str, 10));
	return 0;
}

/* getint: retrieves a long integer from keyboard input */
int getint(char str[], int max)
{
	int j;
	for(j = 0; j < max; j++)
		str[j] = '\0';
	getmyline(str, max);
	return dtoi(str);
}

/* getmyline: get input from keyboard then dump result to s[] and return the number of characters including '\0' */
int getmyline (char s[], int last)  
{
        int i, c;

        for (i = 0; (c = getchar()) != EOF && i < (last - 1) && '\n' != c; ++i)
                s[i] = c;   
        if ('\n' == c) {    
                s[i] = c;
                ++i;        
        }
        s[i] = '\0';         
        return i;
}

/* dtoi: convert string of decimal digits to its integral value */
int dtoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;

}

