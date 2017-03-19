#include<stdio.h>

extern strcopy(char *, char *);

int main()
{
	char s[] = "hello thereeeeeeeee";
	char t[] = "hello szhere, matey";
	strcopy(s, t);
	printf("%s\n", s);	

}
