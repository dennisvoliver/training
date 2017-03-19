/* compiles with cc parsop.c getmeline.c */

#include<stdio.h>
#include<ctype.h>
#define MAXOP 100	/* max digits of numbers including period */
#define MAXLEN 1000	/* max length of line excluding NULL */
#define NUMBER '0'	/* identifier that means we read a number */


/* parsop: reads a line and copies the numerical digits to an array, returns NUMBER if it read a number and the character if it read a non-digit character */
int parsop(char oper[])
{
	extern char line[];
	extern cp;
	int i;
	i = 0;	



	/* skip spaces before operator/operand */
	while((' ' == line[cp] || '\t' == line[cp]) && cp < MAXLEN)
		cp++;

	/* if negative sign is followed immediately by a digit, then collect the sign for atof() to interpret instead of returning a minus operator */
	if('-' == line[cp] && isdigit(line[cp+1]))
		oper[i++] = line[cp++];

	/* if its not a number or an indication that it is a fraction that starts with '.', return the character and seal oper[] with NULL */
	if(!isdigit(line[cp]) && '.' != line[cp]){
		oper[0] = line[cp];
		oper[1] = '\0';
		return line[cp++];
	}

	/* collect the integers */
	if(isdigit(line[cp]))
		while(cp < MAXLEN && i < MAXOP && isdigit(line[cp]))
			oper[i++] = line[cp++];
	/* collect fraction part */
	if('.' == line[cp]){
		oper[i++] = line[cp++];
		while(cp < MAXLEN && i < MAXOP && isdigit(line[cp]))
			oper[i++] = line[cp++];
	}	
	oper[i] = '\0';


	/* tell caller we copied a number to oper[]) */
	return NUMBER;
}
