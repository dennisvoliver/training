/* compile command: cc poly1.c readcoefs.c getmyline.c clear.c getx.c gety.c f.c stretch.c query.c bounds.c dab.c */

#include<stdio.h>
#define MAXLINE 1000 /* maximum length of polynomial including whitespaces and signs */
#define MAXTERM 100 /* maximum number of terms in the polynomial */
#define TRUE 1
#define FALSE 0

/* poly1: program that displays the table used for graphing a polynomial in the form a_0x^n + a_1x^n-1 + a_2x^n-2...a_n */
int main()
{
	/* function prototypes  */
	double coefs[MAXTERM];
	int readcoefs(double coefs[], int maxlength);
	int getx(double x[], double lbound, double ubound, double interv);
	void gety(double coefs[],double x[], double y[], int terms, int trials);
	int stretch(double x[], double y[], int trials);
	int query(void);
	double bounds(double coefs[], int terms, double increment);

	/* get coefficients from keyboard input */
	int terms;
	terms = readcoefs(coefs, MAXLINE);

	/* find lower & upper bounds */
	double lb, ub;
	lb = bounds(coefs, terms, -1.0);
	ub = bounds(coefs, terms, 1.0);

	/* generate initial values of x and y */
	double x[MAXTERM], y[MAXTERM]; 
	int trials;
	trials = getx(x, lb, ub, 1.0);
	gety(coefs, x, y, terms, trials);

	int i = 1;
	while(query()){

		/* print table */
		for(i = 0; i < trials; i++) 
			printf("x:\t%4.4f\ty:\t%4.4f\n", x[i], y[i]);


		/* start digging */
		trials = stretch(x, y, trials);
		gety(coefs, x, y, terms, trials);

	}
	return 0;
}






