#include<stdio.h>

int main()
{
	char s[10];
	extern	int getop1(char []);
 
	printf("%c\n", getop1(s));
	printf("%s\n", s);
}
