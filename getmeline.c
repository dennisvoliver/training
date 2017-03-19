#include<stdio.h>

/* getmeline: copies a stream input to an array and returns the number of characters, stops at \n, requires array size maxlen to avoid overflow, puts NULL ('\0') to the end of the string, does not copy \n unlike getline() */
int getmeline(int s[], int maxlen)
{
	int i, c;
	i = 0;
	while(i < maxlen && (c = getchar()) != '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
