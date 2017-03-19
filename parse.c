char t[MAXOP];
int tp  = 0;

void parse(char c)
{
	t[tp++] = c;
	t[tp] = '\0';

}

/* is t[] in s[] ? */
int compare(char t[], char s[])
{
	int i;
	
	for(i = 0; i <= strlen(s) && t[i] == s[i]; i++)
		;
	if(--i > strlen(s))
		return 1;
	else
		return 0;
}
