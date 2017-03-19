/* untested */

/* gety: inputs x[] to f(x) and dumps the results to y[] */
void gety(double coefs[],double x[], double y[], int terms, int trials)
{
	int i;
	double f(double [], int, double);
	for(i = 0; i < trials; i++)
		y[i] = f(coefs, terms, x[i]);	

}
