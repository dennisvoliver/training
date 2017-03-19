#include <stdio.h>
#include <stddef.h>

size_t factorial(int n);
size_t permu(int n, int r);

/* returns the permutation of n taken r */
int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("permu n r");
		return 1;
	}
	printf("%u\n", (unsigned long)permu((size_t)atoi(argv[1]), (size_t)atoi(argv[2])));
	return 0;
}

/* permu: returns P(n, r) */
size_t permu(int n, int r)
{
	return factorial(n) / factorial(n - r);
}

/* factorial: returns n! */
size_t factorial(int n)
{
	if (n <= 0)
		return 1;
	return n * factorial(n - 1);
}

