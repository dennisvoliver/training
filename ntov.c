#include<stdio.h>

double var[26];

/* intov: assigns a double into a single-letter variable */
void ntov(double d, char c)
{
	if('a' <= c && c <= 'z')
		var[c - 'a'] = d;
	else
		printf("ntov: no such variable\n");
}

/* vton: returns the value of a variable */
double vton(char c)
{
	if('a' <= c && c <= 'z')
		return var[c - 'a'];
	else
		printf("vton: no such variable\n");

}

/* initializes all variables */
void initv(void)
{
	int i;
	for(i = 0; i < 26; i++)
		var[i] = 0.0;
}
