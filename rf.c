/* untested */

/* rf: recursive function evaluation of a single-variable polynomial */
double rf(double x, int ar[], int n) 
{
	if(0 < n) return ((x + ar[n]) * ef(x, &ar[0], n - 1));
	else return ar[0];

}
