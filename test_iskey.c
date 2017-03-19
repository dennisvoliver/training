#include<stdio.h>

int main()
{
	extern int iskey(char *);
	char s[] = "while";
	printf("%d\n", iskey(s));
}
