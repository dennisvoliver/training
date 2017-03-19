#include<stdio.h>

extern char *slice(char *s);

int main()
{
	char s[] = "hello there";
	char *buf = slice(s + 6);
	printf("%s\n%s\n", s , buf); 
}
