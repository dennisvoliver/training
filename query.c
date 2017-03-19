#include<stdio.h>

/* asks for binary input */
int query(void)
{
	printf("Continue? y/n\n");

	char s[2];
	int getmyline (char s[], int last); 

	getmyline(s, 2);

	if('n' == (s[0]) || 'N' == s[0])
		return 0;
	else 
		return 1;
}
