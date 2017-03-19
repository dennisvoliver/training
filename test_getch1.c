#include<stdio.h>

int main()
{

	extern int getch1(void);
	int c;
	while((c=getch1()) != '.')
		putchar(c);
}

