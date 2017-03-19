#include<stdio.h>

int main()
{
	extern int getzeline(char *s, int max);
	int cols  = 10;
	int rows = 20;
	char *s[rows];
	printf("%s\n%d characters\n", *s, getzeline(*s, cols));
 
}
