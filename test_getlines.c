#include<stdio.h>

int main()
{
	extern int getlines(char *s, int last);
	char s[100];
	getlines(s, 100);
	printf("%s\n", s);
}
