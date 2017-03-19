#include<stdio.h>

int main()
{
	extern int scopy(char *to, char *from);
	char s[1000];
	printf("%d: %s\n",scopy(s, "1234567890"), s);
}
