/* dlbound: finds integral lowerbound of the roots of a polynomial in the form a_0x^n + a_1x^n-1 + a_2x^n-2...a_n-2x^2 + a_n-1x + a_n */

double dlbound(double ar[], int n) 
{
	int a, found;
	double ar2[n], c;

	found = c = 0;
	if(1 == n) return 0;
	else{
		while(0 == found){
			for(a = 0; a < n; ++a){
				if(0 < a)
					ar2[a] = ar[a] + (ar2[a-1]*c);
				else ar2[0] = ar[0];
			}
			found = 1;
			for(a = 1; a < n; ++a){
				if(0 <= (ar2[a] * ar2[a - 1])) found = 0;
			}
			
			c = c - 1;
		}
		return ++c;
	}
}
