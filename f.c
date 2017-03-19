#include "feval.h"

/* f: returns f(x) using the remainder theorem */
double f(double ar[], int n, double c) 
{

	int a;
	double ar2[n];
	for(a = 0; a < n; ++a){
		if(0 < a)
			ar2[a] = ar[a] + (ar2[a-1] * c);
		else ar2[0] = ar[0];
	}
	return ar2[n - 1];
}

