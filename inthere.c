
/* inthere: checks how many times an integer occurs in an array */
int inthere(int x, int *d, int n)
{
	return (0 < n) ? (*d == x) + inthere(x, d + 1, n - 1) : 0;	
}

/* isthere: checks how many times a character occurs in a string */
int isthere(char c, char *s)
{
	return (*s != '\0') ? (*s == c) + isthere(c, s + 1) : 0;	
}

/* inwhere: returns the index of the first occurence of the integer x in array *d */
int inwhere(int x, int *d, int n)
{
	if(n)
		return (*(d + n - 1) == x) ? n - 1 : inwhere(x, d, n - 1);
	return 0;
}
