
extern char *slice(char *s);

/* trim: removes to-from+1 characters  in  a string */
int trim(char *s, int from, int to)
{
	char *buf = slice(s + from - 1);
	strfsh(s, buf + to - from + 1);
	return 0;
	
}
