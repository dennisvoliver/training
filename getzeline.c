#include<stdio.h>
extern int getch(void);
extern void ungetch(int c);

/* getzeline: reads a line from keyboard input, newline included, returns number of characters  */
int getzeline(char *s, int max)
{
	int c = *s = getch();
	if(EOF != c && '\n' != c && 0 < max)
		return 1 + getzeline(s + 1, max - 1);

	if(!max && EOF != c)
		ungetch(c);	/*  overflow */
	if('\n' == c)
		s = s + 1;
	return (*s = '\0');

}
