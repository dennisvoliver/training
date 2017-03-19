#include<stdio.h>
#include<string.h>

int main()
{
	extern char *strfsh(char *dest, char *src);
	extern char *strbks(char *, char *);
	char s[] = "hello";
	char t[] = ", there ";
	char u[] = "mate.";

//	printf("%s%s%s\n", s, t, u); 
//	strfsh(strfsh(s, t), u);
//	printf("%s \n", s); 
	printf("%s\n", strcpy(s, s + 3));
}
