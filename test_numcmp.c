#include<stdio.h>

int main()
{

	extern int numcmp(char *s, char *t);
	extern int numncmp(char *num1, char *num2, int n);
	extern int numncmpr(char *num1, char *num2, int n);

	char s[] = "0233.0";
	char t[] = "1233.1";
	int i = 1;
	int j = 4;
	printf("%d\n",numncmpr(s + i, t + i, j));
}
