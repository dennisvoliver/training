#include<stdio.h>


int main()
{
	extern int strcmp(char *, char *);
	extern int fstrcmp(char *s, char *t);
	extern int dstrcmp(char *s, char *t);
	extern int fdstrcmp(char *s, char *t);

	extern int strncmp(char *, char *, int len);
	extern int fstrncmp(char *s, char *t, int len);
	extern int dstrncmp(char *s, char *t, int len);
	extern int fdstrncmp(char *s, char *t, int len);

	char s[] = "abceef^eijk";
	char t[] = "abcdefghijk";
	int n;
	int i = 4;
	int j = 3;
	if((n = dstrncmp(s + i, t + i, j)) > 0)
		printf("s>t");
	else if(n < 0)
		printf("s<t");
	else
		printf("s==t");

}
