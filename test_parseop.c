/* test cases for parseop() function */
#include<stdio.h>


int main()
{
	int parseop(char []);
	char s[1000];
	int c;
	while(EOF != (c = parseop(s)))
		printf("%c\n", c);	



}

