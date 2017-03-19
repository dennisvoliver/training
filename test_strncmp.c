#include<stdio.h>


int main()
{

	extern int strncmp(char *, char *, int len);
	extern int fstrncmp(char *s, char *t, int len);
	extern int dstrncmp(char *s, char *t, int len);
	extern int fdstrncmp(char *s, char *t, int len);

	char s[] = "abceEf^eijk";
	char t[] = "abcdefghijk";
	int n;
	int i = 4;
	int j = 3;
	if((n = fdstrncmp(s + i, t + i, j)) > 0)
		printf("s>t");
	else if(n < 0)
		printf("s<t");
	else
		printf("s==t");

}
