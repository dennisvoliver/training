#include<stdio.h>
#define NUMBER '0'
#define NEGATIVE '_'

int getch(void);
void ungetch(int);
void ungets(char s[]);

/* mygetop: same as getop but uses pointers instead of arrays */
int mygetop(char *s)
{
	int i, c, sign = NUMBER;
	
	while((*s = c = getch()) == ' ' || c == '\t')
		;
	/* negative number */
	if(*s == '-' && isdigit(c = getch())){
		sign = NEGATIVE;
		*s = c;
	}else
		c = *s;

	*(s+1) = '\0';
	if(!isdigit(c) && c != '.')
		return c;	/* not a number */
	
	i = 0;
	if(isdigit(c))		/* collect integer part */
		while(isdigit(*(++i+s) = c = getch()))
			;
	if(c == '.')	/* collect fraction part */
		while(isdigit(*(++i+s) = c = getch()))
			;
	*(s+i) = '\0';
	if(c != EOF)
		ungetch(c);
	return sign;

}
