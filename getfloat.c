#include<stdio.h>
#include<ctype.h>

extern int getch(void);
extern void ungetch(int);

/* getfloat: collects floats from keyboard input */
int getfloat(double *pn)
{
	int c;
	double sign = 1.0;
	double denom = 1.0;	/* denominator */

	while(isspace(c = getch()))	/* skip spaces */
		;

	/* if not a number,a sign, nor and end of file, stop reading */
	if(!isdigit(c) && c != EOF && c != '+' && c!= '-'){
		ungetch(c);
		return 0;	
	}

	sign = (c == '-') ? -1.0 : 1.0;	/* check if negative */

	if(c == '+' || c == '-' ){	/* is sign is encountered */
		int d;
		if(!isdigit(d = getch()) && '.' != d){ /* and if the next character is not a digit */
			ungetch(d);	/* put the two characters back to buffer */
			ungetch(c);
			return 0;	/* and get the next float */
		}else
			c = d;	/* else, then skip the sign character */
	}


	for(*pn = 0.0; isdigit(c); c =  getch()) /* collect integer  */
		*pn = (*pn * 10.0) + (c - '0');	

	if(c == '.')	 
		c = getch();

	for(; isdigit(c); c =  getch()){ /* collect fractions */
		*pn = (*pn * 10.0) + (c - '0');
		denom *= 10.0;
	}


	*pn = (*pn * sign) / denom;	/* place the decimal point to the right spot and the correct sign */

	if(c != EOF)
		ungetch(c); /* return last non-digit character for next reading */

	return c;
}
