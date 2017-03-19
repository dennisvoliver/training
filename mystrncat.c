#include<string.h>

/* mystrncat: copies n characters of t to s */
void mystrncat(char *s, char *t, int n)
{
	if(0 >= n)
		return;
	*(s += strlen(s)) =  *t;
	*++s = '\0';
	mystrncat(s, t + 1, n - 1);
}
