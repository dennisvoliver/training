#include "dcl.h"

/* gettoken: return next token */
int gettoken(void)
{
	int c;
	extern int getch(void);
	extern void ungetch(int);
	char *p = token; 	/* because arrays can't be incremented */


	while ((c = getch()) == ' ' || c == '\t')
		;	/* skip blanks */
	if (c == '(') {
		if ((c = getch()) == ')') { /* if empty parens */
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}

	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) { /* if identifier */
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else {
		return tokentype = c;
	}
}
