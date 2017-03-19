#include<stdio.h>
#include<string.h>
#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position */

/* getch: get a possibly pushed back character */
int getch(void)
{
	return (bufp <= 0) ?  getchar() : buf[--bufp];

}

/* ungetch: push character back on inpu */
void ungetch(int c)	
{
	if(bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("ungetch: too many characters \n");

}

/* ungets: much like ungetch but pushes an entire string instead of just one character  into input */
void ungets(char s[])
{
	int i;
	void ungetch(int);

	for(i = strlen(s); 0 < i; i--)
		ungetch(s[i-1]);
}
