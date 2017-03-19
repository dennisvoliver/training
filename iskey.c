#define NKEYS sizeof(keytab) / sizeof(keytab[0])
#include<string.h>

static char *keytab[] = {
	"auto",
	"asm",
	"break",
	"case",
	"char",
	"const",
	"continue",
	"default",
	"do",
	"double",
	"else",
	"enum",
	"extern",
	"float",
	"for",
	"fortran",
	"goto",
	"if",
	"int",
	"long",
	"register",
	"return",
	"short",
	"signed",
	"sizeof",
	"static",
	"struct",
	"switch",
	"typedef",
	"union",
	"unsigned",
	"void",
	"volatile",
	"while",
	NULL, 
};



/* iskey: if s is a C keyword, return 1, else 0 */
int iskey(char *s)
{
	extern binsearch(char *, char **, int);
	return (binsearch(s, keytab, NKEYS) >= 0) ? 1 : 0;
}

/* binsearch: returns the index in list where word is found */
int binsearch(char *word, char **list, int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if ((cond = strcmp(word, list[mid])) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
