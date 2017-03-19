/* reverse: reverses a string */
int reverse(char s[], int i)
{
	if('\0' == s[i])
		return (i - 1);

	int n = reverse(s, i + 1);
	char temp = s[i];

	if(i > n / 2)
		s[i] = s[n - i], s[n - i] = temp;
	return n;
}
