/* cc readoubs.c getmyline.c -lm */

#include<ctype.h>
#include<math.h>
#define YES 1
#define NO 0


/* readoubs: retrieves a string of doubles separated by whitespace, returns the number of numbers collected */
int readoubs(double ar[], int max)
{
	/* get characters */
	char s[max];
	int getmyline (char s[], int last);
	getmyline(s, max);
	
	int i, sign, n, frac, dot;

	double x;
	for(sign  = 1, dot = frac = i = n = x = 0.0; (i < max) && ('\0' != s[i]); i++){

		/* get sign */
		if('-' == s[i])
			sign = -1;

		/* collect integer part */
		else if(isdigit(s[i])){
			x = (10 * x) + (s[i] - '0');	
			if(0 < dot)
				frac++;
		}

		/* collect fraction part */
		else if('.' == s[i])
			dot = YES;

		/* dump to ar[n] and reset all variables */
		else if(isspace(s[i])){
			ar[n++] = (sign * x) / pow(10, frac);
			frac = x = 0.0;
			dot = NO;
			sign = 1;
		}
	}
	return n;
}


