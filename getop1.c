#include<stdio.h>
#include "calc.h"

/* getop: get next character or numeric operand */
int getop1(char s[])
{
	int i, sign = NUMBER;
	static int c = ' ';
	
	/* skip spaces */
	while((s[0] = c) == ' ' || c == '\t')
		s[0] = c = getchar();


	s[1] = '\0';

	/* if character is not a digit or a decimal period implying it will be a fraction, return it and refresh the buffer c */
	if(!isdigit(s[0]) && s[0] != '.'){
		c = ' ';
		return s[0];
	}

	i = 0;
	if(isdigit(c))		/* collect integer part */
		while(isdigit(s[++i] = c = getchar()))
			;
	if(c == '.')	/* collect fraction part */
		while(isdigit(s[++i] = c = getchar()))
			;
	s[i] = '\0';

	return sign;

}
