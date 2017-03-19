#include<ctype.h>

/* myatoi: converts a string to an integer */
int myatoi(char *s)
{
	extern myatoi2(char *, int);
	return myatoi2(s, 0);
	int n = 0;
	if(*s)
		n = myatoi(s + 1);
	return (n * 10) + (*s - '0');
} 

int myatoi2(char *s, int n)
{
	if(isdigit(*s) && *s)
		return myatoi2(s + 1, n * 10 + (*s - '0'));
	return n;
}
