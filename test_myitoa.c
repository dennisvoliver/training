#include<stdio.h>

extern int itoa(int n, char s[], int i);
extern char *myitoa(int , char *);

int main()
{
	char *s;
	int n = 12304;
	myitoa(n, s);
	printf("%s\n", s);
}


