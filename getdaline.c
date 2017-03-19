#include<stdio.h>
extern int getch(void);
extern void ungetch(int c);

/* getdaline: reads a line from input and dumps to a pointer-to-char, newline not included */
/* WARNING: recursive function, returns the number of chars read, 0 if EOF */
int getdaline(char *s, int max)
{
	int c = getch();
	if(EOF != c && '\n' != c && 0 < max){
		*s = c;
		return 1 + getdaline(s + 1, max - 1);
	}
	if('\n' != c && EOF != c)
		ungetch(c);	/* in case of overflow */
	return (*s = '\0');

}

