#include<stdio.h>
#define MAXLEN 3
extern int getmaline(char *, int);

int main()
{
	char s[MAXLEN];
	int c;

	while(c = getmaline(s, MAXLEN))
		printf("%d\t%s\n", c, s);

}
