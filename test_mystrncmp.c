#include<stdio.h>
extern int mystrncmp(char *, char *, int);

int main()
{
	char s[1000] = "Dennis V. Oliver";
	char t[1000] = "Deneas V. Oliver";
	int n = 4;
	printf("%d\n",mystrncmp(s, t, n));
}
