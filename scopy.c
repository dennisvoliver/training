/* copy: copies one string to another and returns the number of characters */
int scopy(char *to, char *from)
{
	
	return (*to = *from) ? 1 + scopy(to + 1, from + 1) : 0;
}
