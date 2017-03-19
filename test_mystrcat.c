#include<stdio.h>
extern void mystrcat(char *, char *);

int main()
{
	
	char s[1000] = "Wanna know something funny?";	
	char t[] = "My balls are itchy. ";
	char u[] = "What, nothing?. Oh come on!!\n";

	mystrcat(s, t);
	mystrcat(s, u);

	printf("%s\n", s);

}
