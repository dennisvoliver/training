#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NOWHERE 0xffffffff  /* not likely to be a root of any function */
#define assert(s,n) (s) ? 0: exit(n)
#define DECS 0x6	/* accurate to the nth decimal */
#define BASE 0x10 /* radix */
#define DEPTH 0x1000000 /* bare accuracy */

double funct(double x);
double func(double x);
double apr(double min, double max, double (*func)(double), int n);
double ipol(double min, double max, double (*func)(double));
double apr2(double min, double max, double (*func)(double), int n);
double approx(double min, double max, double (*func)(double));
double prox(double min, double max, double (*func)(double), int limit);
double ftrunc(double, double);	/* truncator */
extern double dlbound(double ar[], int n);
extern double dubound(double ar[], int n);
double coef[8][6] = {	/* the first element is the degree of the polynomial + 1 */
	{ 4,  1, -3, -1,  2,  0},
	{ 4,  1,  3, -6, -3,  0},
	{ 4,  1, -1, -2,  1,  0},
	{ 4,  1,  0, -3,  1,  0},
	{ 4,  1,  0, -7,  7,  0},
	{ 5,  1, -1,  2, -3, -3},
	{ 5,  1, -2,  1,  0, -1},
	{ 5,  1, -4,  0, -4, 12}

};

int row = 0;


/* apr: approximates all the roots of a set of single-variable polynomials */
int main()
{

	double root = 0.0;
	int min, max;
//	double chareq[] = {-1, 1, -6, -18};
	double chareq[] = {-1, 0, 18, -16};
	min = -6;//dlbound(chareq, 4);
	max = 4;//dlbound(chareq, 4);
	prox(min, max, funct, DECS);
	return 0;
	/* for each row */
	for (row = 0; row < 8; row++) {
		/* get x range */
		min = dlbound((1 + *(coef+row)), **(coef+row));
		max = dubound((1 + *(coef+row)), **(coef+row));
		/* for each sub-range */
//		for (; min < max; min++) {
//			/* if x is inside sub-range */
//			if((root = apr2(min, min + 1, func, DECS)) != NOWHERE)
//				printf("Problem %d\tf(%g) = %g\n", row + 1, root, func(root));
//		}
		
//		approx(min, max, func);
		prox(min, max, func, DECS);
	}

	return 0;
}
double funct(double x)
{
//	return -pow(x, 3) + pow(x, 2) - 6 * x - 18;
	return -pow(x, 3) + 0 * pow(x, 2) + 18 * x - 16;
}
/* func: a single-variable function in the form a_0x^n+a_1x^n-1+...+a_n*/
double func(double x)
{
	extern double f(double ar[], int n, double c);

	return f(1 + *(coef+row), **(coef+row), x);
}


/* apr: approximates x, the root of func to the nth decimal; provided max - min = 1 and min <= x < max */
double apr(double min, double max, double (*func)(double), int n)
{
	if ((*func)(min) == 0 ||  n <= 0)	/* found it*/
		return min;

	double d, final;
	int fence(double, double);

	/* for each sub-range */
	for (d = (max - min) / BASE; min < max; min += d) 
		if (fence((*func)(min), (*func)(min+d)))  /* root in sub-range */
			return apr(min, min+d, func, n - 1);	/* dig deeper */

	return NOWHERE;	/* not in range */

}

/* apr2: same as apr but with interpolation added  */
double apr2(double min, double max, double (*func)(double), int n)
{
	if ((*func)(min) == 0 ||  n <= 0)	/* found it*/
		return min;

	double ipol(double, double, double (*)(double));	/* interpolator */
	double ftrunc(double, double);	/* truncator */

	double d = (max - min) / BASE;	/* sub-range size */ 
	double wall;	/* moving lowerbound */

	/* if x is on the left side of the wall*/
	if (!fence((*func)(wall = ftrunc(ipol(min, max, func), d)), (*func)(max)))
		d = -d; /* movement is to the left */


	/* for each sub-range */
	for (; min <= wall && wall < max; wall += d) 
		if (fence((*func)(wall), (*func)(wall+d)))  /* x is in sub-range */
			return apr(wall, wall+d, func, n - 1);	/* dig deeper */

	/* not in range */
/*
	fprintf(stderr, "apr2: x not between %g and %g\n", min, max);
*/
	return NOWHERE;

}

/* approx: displays approximate zeroes of a single-variable normal polynomial */
double approx(double min, double max, double (*func)(double))
{
	extern int fence(double a, double b);
	double strip, y;

	for (strip = (max - min) / DEPTH; min < max; min += strip)
		if (fence(y = (*func)(min), (*func)(min + strip)))
			printf("Problem %d\tf(%g) = %g\n", row + 1, min, y);

}

/* prox: displays approximate zeroes of a single-variable normal polynomial */
double prox(double min, double max, double (*func)(double), int limit)
{
	extern int cross(double, double, double (*)(double));
	double strip, y;

	for (strip = (max - min) / BASE; min < max; min += strip) {
			//fprintf(stderr, "%g %g\n", func(min), func(max));
		if(cross(min, min + strip, func) > 0) {
			if (limit > 0)
				prox(min, min + strip, func, limit - 1);
			else
				printf("Problem %d\tf(%g) = %g\n", row + 1, min, (*func)(min));
		
		}
	}

}

/* ftrunc: truncates x to the nth digit by making it divisible by d^n where d is the radix */ 
double ftrunc(double x, double d)
{
	//return x - fmod(x, d);
	return floor(x / d) * d;
}

/* ipol: linearly interpolated value of x */
double ipol(double min, double max, double (*func)(double))
{
	return  min + ((max - min) * (fabs((*func)(min)) / (fabs((*func)(min)) + fabs((*func)(max)))));
}

/* fence: checks if a <= 0 < b or a >= 0 > b, if the two numbers are on the same side */
int fence(double a, double b)
{
	return (a == 0 || (a * b) < 0);

	
}

/* cross: checks if there is a root between min and max */
int cross(double min, double max, double (*func)(double))
{
	double left = (*func)(min);
	double right = (*func)(max);
	extern double fmin(double, double);
	extern double fmax(double, double);

	if (left == 0 || (left * right) < 0)
		return 1;

	double mid = (*func)(min + (max -  min) / 2);

	if ((mid = fabs(mid)) < fmax(left = fabs(left), right = fabs(right)) && mid > fmin(left, right))
		return 0;
	return 1;

}

/* fmax: returns the larger of two floats */
double fmax(double a, double b)
{

	if (a > b)
		return a;
	return b;
}

/* fmin: returns the smaller of two floats */
double fmin(double a, double b)
{

	if (a < b)
		return a;
	return b;
}
