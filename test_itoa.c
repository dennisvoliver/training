#include<stdio.h>

/* test cases for itoa() function */
int main()
{
	extern int itoa(int n, char s[], int i);
	char s[100];

	itoa(-1234, s, 0);

	printf("%s\n", s);

}
