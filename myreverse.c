#include<stdio.h>
/* myreverse: same as reverse but uses pointers instead of arrays */

void myreverse(char *s)
{
	extern int myreverse2(char *, int);
	myreverse2(s, 0);

}

int myreverse2(char *s, int i)
{
	if(!*(s+i))	/* find NULL */
		return i - 1;

	int n = myreverse2(s, i + 1);	/* string length */
	char temp = *(s+i);

	if(i > (n/2)){	/* swap */
		*(s+i) = *(s+n-i);
		*(s+n-i) = temp;
	}

	return n;
}
