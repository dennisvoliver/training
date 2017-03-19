#include<stdio.h>
extern int getch(void);
extern void ungetch(int c);

/* getmaline: reads a line from input and dumps to a pointer-to-char, newline not included */
int getmaline(char *s, int max)
{
	int c = getch();
	if(EOF == c || '\n' == c || max < 1){
		if('\n' != c && EOF != c)
			ungetch(c);	/* in case of overflow */
		return (*s = '\0');
	}
	*s = c;
	return 1 + getmaline(s + 1, max - 1);

}


