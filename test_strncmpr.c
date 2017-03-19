#include<stdio.h>


int main()
{

	extern int strncmpr(char *, char *, int len);
	extern int fstrncmpr(char *s, char *t, int len);
	extern int dstrncmpr(char *s, char *t, int len);
	extern int fdstrncmpr(char *s, char *t, int len);

	char s[] = "a^cdefghijk";
	char t[] = "Abcdefghijk";
	int n;
	int i = 0;
	int j = 11;
	if((n = fdstrncmpr(s + i, t + i, j)) > 0)
		printf("s>t");
	else if(n < 0)
		printf("s<t");
	else
		printf("s==t");

}
