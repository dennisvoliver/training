#include<stdio.h>
#include <math.h>
#define gprint(x) printf(#x " = %g\n", x) /* prints an argument of type double*/
#define dprint(x) printf(#x " = %d\n", x) /* prints an argument of type integer*/

double feval(double x, double a[], int n); /* the actual recursive function that does the thing */
int readcoefs(double ar[], int max); /* reads coefficients from keyboard input */

