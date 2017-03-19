/* strcat: copies strings t to s */
void mystrcat(char *s, char *t)
{
	/* find '\0' */
	while(*s)
		s++;	

	/* start copying */
	while(*s++ = *t++)
		;

}
