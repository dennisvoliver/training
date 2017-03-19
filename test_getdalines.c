#include<stdio.h>
#include<stdlib.h>
#define COLS 1000	/* number of columns in table (including) '\0' */
#define ROWS 1000 /* number of rows in table (including) '\0' */	

void test(char *s[], int rows);
extern int getdalines(char *s[], int maxrow, int maxcol);

int main()
{
	char *t[ROWS];
	test(t, getdalines(t, ROWS, COLS));
}

void test(char *s[], int rows)
{
	if(0 < rows){
		printf("%s\n", *s);
		test(s + 1, rows - 1);
	}
}
