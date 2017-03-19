#include <stdio.h>
#include <math.h>

double funct(double x);
extern double f(double ar[], int n, double c);

int main()
{
	double x = 0.745898;
	double ar[] = {1, -3, -1, 2};
	printf("%g\n", funct(x));
	printf("%g\n", f(ar, 4, x));
	return 0;
}

double funct(double x)
{
	return pow(x, 3) - (3 * pow(x, 2)) - x + 2;
}
