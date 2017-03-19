#include<stdio.h>
extern void mystrncat(char *, char *, int);

int main()
{
	char s[1000] = "I'm just ";
	char t[1000] = "saying hello to my little friend. ";
	int n = 33;
	mystrncat(s, t, n);
	printf("%s\n", s);
}
