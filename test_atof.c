#include<stdio.h>
#include<stdlib.h>

/* tests atof() function */
int main()
{
//	extern double atof(char []);
	char s[] = "-1234.5";
	printf("%g\n", atof(s));
}
