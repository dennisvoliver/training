/* stretch: stretches an interval if the curve shifts, returns number of trials */

int stretch(double x[], double y[],  int trials)
{

	int i, j;
	double tan1, tan2;
	double buf[trials];

	/* copy lowerbound */
	buf[0] = x[0];

	for(i = 1, j = 1; i < (trials - 1) && j < (trials - 1); i++, j++){

		/* get intervals of neighboring ys */
		tan1 = y[i] - y[i-1];
		tan2 = y[i+1] - y[i];
		
		buf[j] = x[i];

		/* if curve shifts, cut the interval around x[i] in half  */
		if((tan1 * tan2) <= 0.0){ 
			buf[j++] = (x[i-1] +  x[i]) / 2;	

			buf[j++] = x[i];

			buf[j] = (x[i+1] +  x[i]) / 2;	

		}else
			buf[j] = x[i];

	}

	/* copy upperbound */
	buf[j] = x[trials - 1];

	/* points  x[] to buf[] */
	for(i = 0; i <= j; i++)
		x[i] = buf[i];

	return ++j;
}
