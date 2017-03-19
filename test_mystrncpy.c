#include<stdio.h>
extern void mystrncpy(char *, char *, int);

int main()
{
	char s[1000];
	char t[1000] = "Saying hello to my little friend. ";
	int n = 4;
	mystrncpy(s, t, n);
	printf("%s\n", s);
}
