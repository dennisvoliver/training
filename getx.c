
/* getx: returns an array of doubles with interval */
int getx(double x[], double lbound, double ubound, double interv)
{
	double d;
	int i = 0;
	for(d = lbound; d < ubound; d += interv)
		x[i++] = d;
	x[i++] = ubound;
	return i;
}
