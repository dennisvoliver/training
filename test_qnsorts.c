#include "test.h"
#define MAXFIELDS 100

int main(int argc, char *argv[])
{
	extern int printlines(char *s[], int lines);
	extern int numncmp(char *num1, char *num2, int n);
	extern int strncmp(char *, char *, int len);
	extern int fstrncmp(char *s, char *t, int len);
	extern int dstrncmp(char *s, char *t, int len);
	extern int fdstrncmp(char *s, char *t, int len);
	extern void qsort(void *v[], int left, int right, int *from, int *to, int (**comp)(void *, void *, int));

	/* the page */
	char *page[] = {"e62!!", "E62##", "e44@@", "a52&&"};
	int lines = 4;

	/* field/column defaults */
	int start[] = {1, 2, 4, 0}; 
	int end[] = {1, 3, 5, 0};
	int (*comp[])(void *, void *, int) = {fstrncmp, numncmp, strncmp};

	qsort(page, 0, lines - 1, start, end, comp);

	printlines(page, lines);
}

/* cc test_qnsort.c qnsort.c strncmp.c numncmp.c  printlines.c */
