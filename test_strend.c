#include<stdio.h>
#define MAXLINE 1000

extern int strend(char *, char *);

int main()
{
	char s[MAXLINE] = "BHello there, Dennis";
	char t[MAXLINE] = "BHello there, Dennis";

	printf("%d\n%c\n", strend(s, t), s[-1]);
}
