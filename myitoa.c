
/* myitoa: itoa but using pointers */
char *myitoa(int n, char *s)
{
	if(0 > n){
		*s++ = '-';
		n = -n;
	}

	if(n/10)
		s = myitoa(n/10, s);
	*s++ = (n % 10) + '0';
	*s = '\0';
	return s;
}

