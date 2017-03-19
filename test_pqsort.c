#include "test.h"

int main(int argc, char *argv[])
{
	extern void qsort(void *v[], int left, int right, int (*com)(void *, void *));
	extern int numcmp(char *num1, char *num2);
	extern int strcmp(char *s, char *t);
	extern int fstrcmp(char *s, char *t);
	extern int getdalines(char *s[], int maxrow, int maxcol);
	extern int printlines(char *s[], int lines);
	extern int reverses(void *arr[], int n);
	extern int dstrcmp(char *s, char *t);
	extern int fdstrcmp(char *s, char *t);

	/* the page */
	char *v[MAXLINES];
	int lines;


	/* options */
	int revrs = 0;
	int fold = 0;
	int numeric = 0;
	int directory = 0;
	char opt = 0;
	while(--argc > 0 && **++argv == '-')
		while((opt = *++*argv) != '\0')
			switch(opt){
				case 'r':
					revrs = 1;
					break;
				case 'n':
					numeric = 1;
					break;
				case 'f':
					fold = 1;
					break;
				case 'd':
					directory = 1;
					break;
				default:
					break;
			}

	/* comparison functions */
	int (*comp)(void *, void*);
	if(numeric)
		comp = numcmp;
	else if(directory && fold)
		comp = fdstrcmp;
	else if(directory)
		comp = dstrcmp;
	else if(fold)
		comp = fstrcmp;
	else
		comp = strcmp;

	/* main algor */
	if((lines = getdalines(v, MAXLINES, MAXLEN)) > 0){
		qsort(v, 0, lines - 1, comp);
		if(revrs == 1)
			reverses(v, lines);
		printlines(v, lines);
	}
	return 0;
}

/* cc test_pqsort.c pqsort.c strcmp.c numcmp.c getdalines.c getdaline.c getch.c swap.c printlines.c reverses.c*/
