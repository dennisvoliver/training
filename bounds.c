/*	compile with the following bash shell command:
	cc bounds dab.c
*/


#define TRUE	1 
#define FALSE 	0 

/* bounds: finds upper/lower bound of the roots of a polynomial in the form a_0x^n + a_1x^n-1 + a_2x^n-2...a_n-2x^2 + a_n-1x + a_n */
double bounds(double coefs[], int terms, double increment) 
{
	int i, isbound(double x, double coefs[], int terms);
	double x;

	x = 0.0;
	while(!isbound(x, coefs, terms))
		x += increment;
	return x;
}

/* isbound: checks if x is a lower/upper bound */
int isbound(double x, double coefs[], int terms)
{
	double rem, dabs(double);
	int i, stable;
	rem = coefs[0];

	/* for each coefficient */
	for(i = stable = 1; i < terms && stable > 0; i++){

		/* if the magnitude of the addend is less than the coefficient and their signs are not the same */
		if(dabs(rem * x) <= dabs(coefs[i]) && (rem * x * coefs[i]) <= 0){

			/* then x is not a bound */
			stable = FALSE;
		}
		rem = (rem * x) + coefs[i];
	}
	
	return stable;
	
}
