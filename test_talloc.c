#include<stdio.h>

extern char **talloc(int n);
extern void tafree(char *p);

int main()
{
	char **s;
	s = talloc(5);
	*s = "hello";
	printf("%s\n", *s);
}
