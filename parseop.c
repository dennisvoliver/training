#include<ctype.h>
#include<stdio.h>

#define NUMBER '0'
#define MAXLEN 1000	/* maximum length of line */

char line[MAXLEN];	/* buffer line */
int id	= 0;		/* buffer index */

int parseop(char s[])
{
	extern char line[];
	extern int id;

	int getmyline(char [],int);	/* function prototype */

	if(0 == id)	
		getmyline(line, MAXLEN);	

	while((s[0] = line[id++]) == ' ' || s[0] == '\t')
		;	/* skip blanks */

	if( !isdigit(s[0]) && s[0] != '.' && s[0] != '\n')
		return s[0];	/* not a number */

	int i = 0;
	if(isdigit(line[--id]))	/* collect integer part */
		while(isdigit(s[i++] = line[id++]))
			;

	if(line[--id] == '.')	/* collect fraction part */
		while(isdigit(s[i++]=line[++id]))
			;
	/* seal the operator */
	s[--i] = '\0';

	/* refresh after every line */
	if(line[id] == '\n' || line[id] == '\0')
		id = 0;
	else if(line[id] != EOF)	/* unread character */
		--id;

	return NUMBER; 

}

