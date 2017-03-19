#include<ctype.h>

/* reverse of strncmp.c  */

/* strcncmpr: compares two strings, returns <0 , ==0, or >0 as lexical comparisons */
int strncmpr(char *s, char *t, int n)
{
	return (*s == *t && *s != '\0' && 1 < n) ? strncmpr(s + 1, t + 1, n - 1) : (*t - *s);
}

/* fstrncmpr: strncmpr but indifferent to cases */
int fstrncmpr(char *s, char *t, int n)
{
	char a = *s, b = *t;
	a = tolower(a);
	b = tolower(b);
	return (a == b && b != '\0' && 1 < n) ? fstrncmpr(s + 1, t + 1, n - 1) : (b - a);
}

/* dstrncmpr: strncmpr but compares only alpha-numeric and blank characters */
int dstrncmpr(char *s, char *t, int n)
{

	extern int noralnb(char, char);
	char a = *s, b = *t;
	if(noralnb(a, b)) /* if special character, ignore */
		a = b;
	return (a == b && b != '\0' && 1 < n) 
		? dstrncmpr(s + 1, t + 1, n - 1) 
		: (b - a);
}

/* fdstrncmpr: a combo of fstrncmpr and dstrncmpr */
int fdstrncmpr(char *s, char *t, int n)
{
	char a = *s, b = *t;
	extern int noralnb(char, char);

	a = tolower(a);
	b = tolower(b);

	if(noralnb(a, b)) /* if special character, ignore */
		a = b;

	return (a == b && b != '\0' && 1 < n) 
		? fdstrncmpr(s + 1, t + 1, n - 1) 
		: (b - a);
}

/* noralnb: returns 1 if one of two characters is neither an alphanumeric nor a blank character*/
int noralnb(char a, char b)
{
	extern int notalnb(char);
	return	notalnb(a) || notalnb(b);
}

/* notalnb: returns 1 if c is not an alphanumeric nor a blank character*/
int notalnb(char c)
{
	return (!isalnum(c) && !isblank(c));
}
