/* mystrncmp: compares n characters of s with t, returns <0 , ==0, or >0 as lexical comparisons */
int mystrncmp(char *s, char *t, int n)
{
	if(*s == *t && 1 < n && *t )
		return mystrncmp(s + 1, t + 1, n - 1);
	return *s - *t;

}
