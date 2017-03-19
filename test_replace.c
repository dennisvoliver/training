#include<stdio.h>

int main()
{

	extern int replace(char *in, char to, char from);
	char s[] = "hello there matey";
	replace(s, 'x', 'e');
	printf("%s\n", s);
}
