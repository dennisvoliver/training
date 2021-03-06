/* cc sortlines1.c getdaline.c getch.c */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXCHARS 10000	/* total number of characters in all lines */

#define pprint(ptr, i) printf("%s\n", ptr[i])	/* debugging tools */
#define assert(x, Y, N)	x ? Y : N 
#define tprint(x, t) printf("%" #t, x)

char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int maxlines, char *linebuf, int maxchars);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
main()
{
	int nlines;
	char linebuf[MAXLEN];	/* where all lines are actually stored, separated only by '\0'*/

	/* number of input lines read */
	if ((nlines = readlines(lineptr, MAXLINES, linebuf, MAXCHARS)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000 /* max length of any input line */
int getdaline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *linebuf, int maxchars)
{
	int len, nlines, i = 0;
	char line[MAXLEN];
	nlines = 0;
	while ((len = getdaline(line, MAXLEN)) > 0){	
		if (nlines >= maxlines || len >= maxchars)
			return -1;
		else {
			strcpy(linebuf+i, line);
			lineptr[nlines++] = linebuf+i;
			i += len + 2;	/* giving room for NULL */
		}
	}

	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
	printf("%s\n", lineptr[i]);

}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{

	int i, last;
	void swap(char *v[], int i, int j);
	if (left >= right) /* do nothing if array contains */
		return;	/* fewer than two elements */

	swap(v, left, (left + right)/2);
	last = left;

	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

