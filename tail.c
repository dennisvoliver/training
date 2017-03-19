#include<stdio.h>
#define MAXLINE 1000
#define MAXLEN 1000

/* prints last n lines in a page */
int main(int argc, char *argv[])
{
	extern int getdalines(char *s[], int rows, int cols);
	extern int tail(int n, char *page[], int lines);
	extern int tail1(int n, char *page[], int lines);
	extern double myatof(char *s);

	/* get input */
	char *page[MAXLINE];
	int lines = getdalines(page, MAXLINE, MAXLEN);
	int n = 10;

	/* if optional argument */
	if(argc > 1){
		if(**(argv + 1) == '-' && isdigit(*(*(argv + 1) + 1)))
			n = myatof(*(argv + 1) + 1);
		else
			printf("tail -n\n");
	}

	/* start printing */
	tail(n, page + lines - 1, lines);
	/* tail1(n, page, lines); */

	return 0;
}

/* tail: prints the last n lines in page, assumes *page is the last line */
int tail(int n, char *page[], int lines)
{
	if(lines <= n)
		printf("%s\n", *(page - lines + 1));
	return (1 < lines) ? tail(n, page, lines - 1) : 0;
}

/* tail1: loop version of tail, assumes *page is the first line */
int tail1(int n, char *page[], int lines)
{
	int i;
	for(i = 0; i < lines; i++)
		if(i + 1 > lines - n)
			printf("%s\n", *(page + i));
}
