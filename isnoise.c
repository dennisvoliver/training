#define SLEN (sizeof(noises) / sizeof(noises[0]))
#include<string.h>

static char *noises[] = {
	"a",
	"as",
	"at",
	"in",
	"is",
	"of",
	"on",
	"the",
	"to",
	/* NULL */
};



/* iskey: if s is a C keyword, return 1, else 0 */
int isnoise(char *s)
{
	extern binsearch(char *, char **, int);
	return (binsearch(s, noises, SLEN) >= 0) ? 1 : 0;
}

