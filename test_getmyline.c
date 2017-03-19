#include<stdio.h>

/* test cases of getmyline() function */

int main()
{
	int getmyline(char [], int);
	char s[1000];
	getmyline(s, 1000);
	printf("%s#\n", s);

}
