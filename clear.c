/* clear: clears char array */
void clear(char s[])
{
	int i;
	for(i = 0; '\0' != s[i]; i++)
		s[i] = '\0';
}


