#include<stdio.h>
/* Exercise 2-10 of K&R */

int getmyline (char s[], int last);
void lower(char s[]);

int main()
{
	char s[10];
	getmyline(s, 10);
	lower(s);
	printf("%s\n", s);
	printf("%d\n", 6 % 3 * 3);
	
}

void lower(char s[])
{
	int i;
	for(i = 0; '\0' != s[i]; i++)
		s[i] += 'A' <= s[i] && 'Z' >= s[i] ? 'a' - 'A': 0;

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
