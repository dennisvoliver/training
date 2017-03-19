#include "test.h"
#define MAXFIELDS 100
#include<ctype.h>

/* qsortsort: sorts lines based on different fields and different criteria
 qsortsort -s1 -e5 -w -n  -r -s6 -e10 -w  
	 will sort the first five characters lexicography and the 6th to 10th characters numerically
	and in reverse order
*/

int main(int argc, char *argv[])
{
	extern int getdalines(char *s[], int maxfield, int maxcol);
	extern int printlines(char *s[], int lines);
	extern int reverses(void *arr[], int n);
	extern int numncmp(char *num1, char *num2, int n);
	extern int strncmp(char *, char *, int len);
	extern int fstrncmp(char *s, char *t, int len);
	extern int dstrncmp(char *s, char *t, int len);
	extern int fdstrncmp(char *s, char *t, int len);

	/* reverses */
	extern int numncmpr(char *num1, char *num2, int n);
	extern int strncmpr(char *, char *, int len);
	extern int fstrncmpr(char *s, char *t, int len);
	extern int dstrncmpr(char *s, char *t, int len);
	extern int fdstrncmpr(char *s, char *t, int len);

	extern void qsort(void *v[], int left, int right, int *from, int *to, int (**comp)(void *, void *, int));

	/* the page */
	char *v[MAXLINES];
	int lines;

	/* field/column defaults */
	int start[MAXFIELDS] = {1, 0}; 
	int end[MAXFIELDS] = {MAXLEN, 0};
	int (*comp[MAXFIELDS])(void *, void *, int) = {strncmp};
	int field = 0;
	

	/* options */
	int revrs = 0;
	int fold = 0;
	int numeric = 0;
	int directory = 0;
	char opt = 0;
	int temp = 0;

	/* comparison functions */
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
					start[field] = atoi(++*argv);
					break;
				case 'e':
					end[field] = atoi(++*argv);
					break;
				case 'w': /* next field */
					if(revrs && numeric)
						comp[field] = numncmpr;
					else if(revrs &&  directory && fold)
						comp[field] = fdstrncmpr;
					else if(revrs &&  directory)
						comp[field] = dstrncmpr;
					else if(revrs && fold)
						comp[field] = fstrncmpr;
					else if(revrs)
						comp[field] = strncmpr;
					else if(numeric)
						comp[field] = numncmp;
					else if(directory && fold)
						comp[field] = fdstrncmp;
					else if(directory)
						comp[field] = dstrncmp;
					else if(fold)
						comp[field] = fstrncmp;
					else
						comp[field] = strncmp;
					field++;
					start[field] = 0;
					end[field]= 0;
					fold = 0;
					numeric = 0;
					directory = 0;
					revrs = 0;
					break;
				default:
					break;
			}

	/* main algor */
	if((lines = getdalines(v, MAXLINES, MAXLEN)) > 0){

		qsort(v, 0, lines - 1, start, end, comp);
		/* if(revrs == 1) reverses(v, lines);
		*/
		printlines(v, lines);
	}
	return 0;
}

/* cc qsortsort.c qnsorts.c strncmp.c numncmp.c getdalines.c getdaline.c getch.c swap.c printlines.c reverses.c*/
