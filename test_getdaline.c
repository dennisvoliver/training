#include<stdio.h>
#define MAXLEN 30
extern int getdaline(char *, int);

int test(char *s, int max);

int main()
{
	char s[MAXLEN];
	test(s, MAXLEN);

}

int test(char *s, int max)
{
	int c = getdaline(s, max);
	if(!c)
		return 0;
	printf("%s\n%d characters \n", s, c);
	return 1 + test(s, max);
}
