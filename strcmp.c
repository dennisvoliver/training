#include<ctype.h>

/* strcmp: compares to strings, returns <0 , ==0, or >0 as lexical comparisons */
int strcmp(char *s, char *t)
{
/*
	for(;*s == *t && *t != '\0';s++, t++)
		;
	return *s - *t;
*/

	return (*s == *t && *t != '\0') ? strcmp(s + 1, t + 1) : (*s - *t);
}

/* fstrcmp: strcmp but indifferent to cases */
int fstrcmp(char *s, char *t)
{
	char char1 = *s, char2 = *t;
	char1 = ('A' <= char1 && char1 <= 'Z') ? 'a' + char1 - 'A': char1;
	char2 = ('A' <= char1 && char2 <= 'Z') ? 'a' + char2 - 'A': char2;
	return (char1 == char2 && char2 != '\0') ? fstrcmp(s + 1, t + 1) : (char1 - char2);
}

/* dstrcmp: strcmp but compares only alpha-numeric and blank characters */
int dstrcmp(char *s, char *t)
{

	extern int noralnb(char, char);
	char a = *s, b = *t;
	return ((a == b || noralnb(a, b)) && b != '\0') 
		? dstrcmp(s + 1, t + 1) 
		: (a - b);
}

/* fdstrcmp: a combo of fstrcmp and dstrcmp */
int fdstrcmp(char *s, char *t)
{
	char a = *s, b = *t;
	extern int noralnb(char, char);

	a = tolower(a);
	b = tolower(b);

	return ((a == b || noralnb(a, b)) && b != '\0') 
		? dstrcmp(s + 1, t + 1) 
		: (a - b);
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

