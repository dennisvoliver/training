#include<stdio.h>

/* program that displays the table used for graphing a polynomial in the form a_0x^n + a_1x^n-1 + a_2x^n-2...a_n */


int iubd(int coefficients[], int terms); 
int ilbd(int coefficients[], int terms);
int getmyline (char s[], int last);
int dtoi(char s[]);
int readint(void);
double f(int coefficients[], int terms, double x); 	
int query(void);

int main()
{

	/* ar[n] are the coefficients of the dividend polynomial
	* and ar2[n] are the coefficients of the quotient polynomial.
	* c is the constant in the divisor (x - c), used in evaluating the function using the remainder
	* theorem.
	*/


	printf("enter the number of terms:\n");
	int n;
	n = readint();


	printf("enter the value of the coefficients with each term separated by <enter>:\n");
	int i;
	
	int ar[n];
	for(i = 0; i < n; i++)
		ar[i] = readint();

	/* find upper and lower bound of x */
	int u, l;
	u = iubd(ar, n);	
	l = ilbd(ar, n);

	/* set interval */
	double z;
	z = 1;

	/* print table */
	double x;
	int q;
	q = 1;
	while(q){
		for(x = l; x <= u; x = x + z) printf("x = %f\ty = %f\n", x, f(ar, n, x));
		printf("continue? Y/N\n");
		q = query();
		if(!q)
			return 0;

		printf("decrease interval by half? Y/N\n");
		if(query())
			z /= 2;

		printf("manually set integral lower and upperbound? Y/N:\n");
		if(query()){

			printf("enter integral lowerbound:\n");
			l = readint();

			printf("enter integral upperbound Y/N\n");
			u = readint();
		}
	}
}

/* query: asks for user input, y/n */
int query(void)
{
	char s[2];
	getmyline(s, 2);
	if('y' == s[0] || 'Y' == s[0])
		return 1;
	else
		return 0;
}

/* readint: reads 5-digit integers */
int readint(void)
{

	int j, max;
	max = 5;
	char str[max];

	for(j = 0; j < max; j++)
		str[j] = '\0';
	getmyline(str, max);
	if('-' == str[0]){
		char str2[max];
		for(j = 1; '\0' != str[j]; j++)
			str2[j-1] = str[j];	
		str2[j] = '\0';
		return -dtoi(str2);
	} else
		return dtoi(str);

}
/* iubd: finds integral upperbound of the roots of a polynomial in the form a_0x^n + a_1x^n-1 + a_2x^n-2...a_n-2x^2 + a_n-1x + a_n */
int iubd(int ar[], int n) 

{
	int a, found;
	int ar2[n], c;

	found = c = 0;
	while(0 == found){
		
		for(a = 0; a < n; ++a){
			if(0 < a)
				ar2[a] = ar[a] + (ar2[a-1] * c);
			else ar2[0] = ar[0];
		}
		found = 1;
		for(a = 0; a < n; ++a){
			if(0 > ar2[a]) found = 0;
		}
		
		c = c + 1;
	}

	return --c;
}
/* ilbd: finds integral lowerbound of the roots of a polynomial in the form a_0x^n + a_1x^n-1 + a_2x^n-2...a_n-2x^2 + a_n-1x + a_n */
int ilbd(int ar[], int n) 

{
	int a, found;
	int ar2[n], c;

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


/* getmyline: get input from keyboard then dump result to s[] and return the number of characters including '\0' */
int getmyline (char s[], int last)  
{
        int i, c;

        for (i = 0; (c = getchar()) != EOF && i < (last - 1) && '\n' != c; ++i)
                s[i] = c;   
        if ('\n' == c) {    
                s[i] = c;
                ++i;        
        }
        s[i] = '\0';         
        return i;
}

/* dtoi: convert string of decimal digits to its integral value */
int dtoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;

}

/* f: returns f(x) using the remainder theorem */
double f(int ar[], int n, double c) 
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

