#include<stdio.h>

int main()
{
	extern int insert(char *dest, char *src, int n);
	extern int trim(char *s, int from, int to);
	char s[] = "1234567890";
	trim(s, 3, 5);
	printf("%s\n", s);
}
