#include <math.h>

/* defactor: returns a pointer to int containing the factors of x */
int defactor(int x, int *factors)
{
	extern int factor(int x, int *factors, int prime);
	return factor(x, factors, 1);
}

int intcpy(int *to, int *from, int size)
{
	if(size <= 0)
		return 0;
	*to = *from;	
	return intcpy(to + 1, from + 1, size - 1);
}

int factor(int x, int *factors, int prime)
{
	if(1 == x)
		return 1;
	if(prime > sqrt(x))
		return 0;

	double quotient = x / prime;
	if(!(quotient == (int)quotient))
		return factor(x, factors, prime + 1);

	*factors = prime;
	return 1 + factor(quotient, factors + 1, prime);
}


