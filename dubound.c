/* dubound: finds integral upperbound of the roots of a polynomial in the form a_0x^n + a_1x^n-1 + a_2x^n-2...a_n-2x^2 + a_n-1x + a_n */
double dubound(double ar[], int n) 
{
	int a, found;
	double ar2[n];	/* buffer for quotient */
	double c;

	found = c = 0;
	while(0 == found){
		
		/* evaluate polynomial with remainder theorem method */
		for(a = 0; a < n; ++a){
			if(0 < a)
				ar2[a] = ar[a] + (ar2[a-1] * c);
			else ar2[0] = ar[0];
		}

		/* parse the quotient coefficients */
		found = 1;
		for(a = 0; a < n; ++a){

			/* if no negative or zero is found then we found the upperbound */
			if(0 >= ar2[a]) 
				found = 0;
		}
		
		c = c + 1;
	}

	return --c;
}
