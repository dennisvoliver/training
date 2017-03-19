#include "test.h"
#include "debug.h"
#include<string.h>
#include<stdlib.h>
#define MAXCHARS 1000
#define ON 1
#define OFF 0

struct nlist {	/* table entry: */

	struct nlist *next; 	/* next entry in chain */
	char *name; 		/* defined name */
	char *defn;		/* replacement text */

};

/* a simple implementation of the #define feature in a C compiler */
int main()
{
	extern struct nlist *lookup(char *s);
	extern struct nlist *install(char *name, char *defn);
	extern char *isdefine(char *word);
	extern int getword(char *word, int len);
	extern char *strfsh(char *dest, char *src);

	char strip[MAXCHARS];
	char *pstrip = strip;
	char word[MAXLEN];
	struct nlist *w;
	char *name = NULL;
	

	while (getword(word, MAXLEN) >= 0) {
		if ((w = lookup(word)) != NULL)
			pstrip = strfsh(pstrip, w->defn);
		else
			pstrip = strfsh(pstrip, word);
		if ((name = isdefine(word)) != NULL)
			install(name, word);
	}
	printf("%s\n", strip);
}

/* getword: This function collects a word from text stream. It returns -1 if EOF, 0 if too long and 1 if normal.  A word is either a singe special character or a string of alphanumeric characters.
*/
int getword(char *word, int len)
{
	int c;
	if ((c = getch()) == EOF)
		return -1;

	if (!isalnum(c)) {
		*word++ = (char)c;
		*word = '\0';
		return 0;
	}

	*word++ = (char)c;
	while (isalnum(c = getch()) && --len > 0)
		*word++ = (char)c;
	*word = '\0';
	ungetch(c);
	return 1;
}




/* isstate: This function returns a pointer to A if the last group of words is in the form "#define A B", and returns NULL otherwise. A and B are placeholders for words. Did I mention it's also a turing machine? */
char *isdefine(char *word)
{
	static int state = 0;
	static char *name = NULL;

	switch (state) {
		case 0:
			if (strcmp(word, "#") == 0)
				state = 1;
			break;
		case 1:
			if (strcmp(word, "define") == 0)
				state = 2;
			else
				state = 0;
			break;
		case 2:
			if (word[0] != ' ') {
				name = (char *)malloc(sizeof(word) + 1);
				strcpy(name, word);
				state = 3;
			}
			break;
		case 3:
			if (word[0] != ' ') {
				state = 0;
				return name;
			}
			break;
	}
	return NULL;
}
