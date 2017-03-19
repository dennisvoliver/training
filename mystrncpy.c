/* mystrncpy: copies t to s starting from the nth character */
void mystrncpy(char *s, char *t, int n)
{	
	if(0 >= n)
		return;
	*s = *t;
	mystrncpy(s + 1, t + 1, n - 1);
}
