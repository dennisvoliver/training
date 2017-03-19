#include<ctype.h>

/* readword: get next word or character from line */
char *readword(char *line, char *word, int maxlen)
{
/*
	Skip spaces.
	Copy the first character.
	If first character is a letter or # and there is enough room in word[], continue copying.
	If non-alphanumeric character is read, stop.
	Put a null character at the end of word[].
	Return a pointer to the last character read in line[].
*/

	while (isspace(*line))
		line++;

	if ((*word = *line++) == '#' || isalpha(*word++)) 
		while (isalnum(*word = *line) && --maxlen > 0) 
			word++, line++;
	*word = '\0';

	return line;
}
