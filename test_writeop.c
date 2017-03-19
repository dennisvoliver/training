#include<stdio.h>

int main()
{
	extern int writeop(char *s, int *argv[], int argc);
	int *argv[] = {"expr", "2", "3", "+", ""};
	char *s = "hello";
	writeop(s, argv, 3);
	printf("%s\n", s);
	
}

