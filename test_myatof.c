#include<stdio.h>

extern double myatof(char *s);

int main()
{
	char s[] = "123.4";
	printf("%g\n", myatof(s));
}
/* cc myatof.c test_myatof.c -lm */
