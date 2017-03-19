
/* itoa: converts an integer to a string of digits */
int itoa(int n, char s[], int i)
{
	if(n < 0)
		s[i++] = '-', n = -n;

	if(n / 10)
		i = itoa(n / 10, s, i);

	s[i++] = (n % 10) + '0', s[i] = '\0';

	return i;

}
