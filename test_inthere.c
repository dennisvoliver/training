#include<stdio.h>

int main()
{

	extern int inthere(int x, int *d, int n);
	extern int  isthere(char x, char *s);
	extern int inwhere(int x, int *d, int n);
	int d[] = { 1, 2, 3, 3, 4, 6, 7};
	char s[] = "hello there, matey";
	printf("inthere: %d\tisthere: %d\tinwhere: %d \n ", inthere(3, d, 7), isthere('e', s), inwhere(1, d, 7));

}
