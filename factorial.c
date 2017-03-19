#include <stdio.h>

int factorial(int n);
int permut(int n, int r);

int main()
{
	int x;
	//x = factorial(11) / (factorial(2) * factorial(4) * factorial(4));
	x = permut(9, 3);
	printf("%d\n", x);
	return 0;
}

int factorial(int n)
{
	if (n <= 0)
		return 1;
	return n * factorial(n - 1);
}

int permut(int n, int r)
{
	return factorial(n) / factorial(n - r);
}
