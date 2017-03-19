#include "test.h"

int main(int argc, char *argv[])
{
	extern int getdalines(char *s[], int maxrow, int maxcol);
	extern int printlines(char *s[], int lines);
	extern int reverses(void *arr[], int n);
	extern int numncmp(char *num1, char *num2, int n);
	extern int strncmp(char *, char *, int len);
	extern int fstrncmp(char *s, char *t, int len);
	extern int dstrncmp(char *s, char *t, int len);
	extern int fdstrncmp(char *s, char *t, int len);
	extern void qsort(void *v[], int left, int right, int from, int to, int (*comp)(void *, void *, int));
	/* the page */
	char *v[MAXLINES];
	int lines;

	/* field/column */
	int start = 1; 
	int end = MAXLEN;

	/* options */
	int revrs = 0;
	int fold = 0;
	int numeric = 0;
	int directory = 0;
	char opt = 0;
	int temp = 0;
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
				case 's':
					temp = atoi(++*argv);
					start = (0 < temp) ? temp : start;
					break;
				case 'e':
					temp = atoi(++*argv);
					end = (0 < temp) ? temp : end;
					break;
				default:
					break;
			}

	/* comparison functions */
	int (*comp)(void *, void*, int);
	if(numeric)
		comp = numncmp;
	else if(directory && fold)
		comp = fdstrncmp;
	else if(directory)
		comp = dstrncmp;
	else if(fold)
		comp = fstrncmp;
	else
		comp = strncmp;

	/* main algor */
	if((lines = getdalines(v, MAXLINES, MAXLEN)) > 0){
		qsort(v, 0, lines - 1, start, end, comp);
		if(revrs == 1)
			reverses(v, lines);
		printlines(v, lines);
	}
	return 0;
}

/* cc test_qnsort.c qnsort.c strncmp.c numncmp.c getdalines.c getdaline.c getch.c swap.c printlines.c reverses.c*/
