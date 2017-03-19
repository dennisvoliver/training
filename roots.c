/* cc roots.c feval.c readcoefs.c getmyline.c clear.c -lm */
#include "feval.h"
#include<math.h>
#define MAXLEN 1000
#define MAXFACTS 1000

/* evaluates a single variable polynomial f(x) = a[0]x^n+a[1]x^n-1+...+ a[n-1]x+a[n] */
int main()
{
//	/* attempting to make a stand-alone program, not finished yet */
//	double a[MAXLEN]; /* coefficients */
//	double x = 1.5;
//	int n = readcoefs(a, MAXLEN) - 1;

//	printf("f(%g) = %g\n",x[0], feval(x[0], a, n));

//	double a[] = {4, 8, -7, -21, -9};
//	double x = 0.5 * (1.0 + sqrt(5.0));
//	int n = 4;
//	printf("f(%10.10g) = %g\n", x, feval(x, a, n));

}

int candids(int *coefs, double *cands)
{

}

