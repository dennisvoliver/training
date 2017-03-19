#include "fillint.h"
#include<ctype.h>

extern int getch(void);	/* gets character from input */
extern void ungetch(int);	/* puts character back to input */

int getint(int *pn)
{
	int c, sign;

	while(isspace(c = getch()))	
		;/* skip spaces */

	if(!isdigit(c) && c != EOF && c != '+' && c!= '-'){
		ungetch(c);
		return 0;	/* not a number */
	}

	sign = (c == '-') ? -1 : 1;	/* check if negative */

	if(c == '+' || c == '-' ){
		int d;
		if(!isdigit(d = getch())){	/* if + or - is not followed by a digit */
			ungetch(d);		/* then put the two characters back to input */
			ungetch(c);
			return 0;		
		}else				/*else, read the digit */
			c = d;
	}

	for(*pn = 0; isdigit(c); c =  getch()) /* collect integers */
		*pn = (*pn * 10) + (c - '0');

	*pn *= sign;

	if(c != EOF)
		ungetch(c); /* return last non-digit character read */

	return c;
}
