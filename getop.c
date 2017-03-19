#include<stdio.h>
#define NUMBER '0'
#define NEGATIVE '_'

int getch(void);
void ungetch(int);
void ungets(char s[]);

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c, sign = NUMBER;
	
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	/* negative number */
	if(s[0]  == '-' && isdigit(c = getch())){
		sign = NEGATIVE;
		s[0] = c;
	}else
		c = s[0];

	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c;	/* not a number */
	
	i = 0;
	if(isdigit(c))		/* collect integer part */
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')	/* collect fraction part */
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return sign;

}
