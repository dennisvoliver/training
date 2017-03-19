#include<stdio.h>

int main()
{
	extern void myreverse(char *);
	char s[1000] = "Muthaar fooockaaz!!\0!!";

	myreverse(s);

	printf("%s\n", s);

}
