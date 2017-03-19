#include<stdio.h>
extern int mygetline(char *);

int main()
{
	char *s;
	int c = mygetline(s);
	printf("%s\n%d characters", s, c);	

}
