#include<stdio.h>

int main()
{
	parseop_test();

}


void poly_test(void)
{

	double coefs[5];
	double bounds(double coefs[], int terms, double increment);
	int isbound(double x, double coefs[], int terms);
	double dabs(double);

	coefs[0] = -1.0;
	coefs[1] = 0.0;
	coefs[2] = 2.0;
	coefs[3] = 8.0;
	coefs[4] = 3.0;

	printf("%g\n",bounds(coefs, 5, 1.0));

}
