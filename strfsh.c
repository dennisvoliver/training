
/* strfsh: same as strcat but returns a pointer to the NULL character instead of the first */
char *strfsh(char *dest, char *src)
{
	extern char *strbks(char *, char*);
	if(*dest)
		return strfsh(dest + 1, src);
	return strbks(dest, src);
}

/* strbks: same as strcpy but returns a pointer to the NULL character instead of the first */
char *strbks(char *dest, char *src)
{
	if(*dest = *src)
		return strbks(dest + 1, src + 1);
	return dest;
}

