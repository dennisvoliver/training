/* if I am asked how this works, I will not be very honest */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINES 1000
#define MAXLEN 1000
#define MAXTABS 100
#define TRUE 1
#define FALSE 0

int findtab(int i, int *tabs, int n);
int spread(char *s, char c, int n);
int spacer(char *s, int i, int *tabs, int n);
int detab(char *s, int *tabs, int n);
int detab_1(char *s, int i, int *tabs, int nt);
int entab(char *s, int *tabs, int nt);
int entab_1(char *s, int last, int *tabs, int nt);
int blankend(char *from, char *to);
int stot(char *from, char *to);
int printlines(char *s[], int lines);
int dentabs(char *s[], int lines, int *tabs, int nt, int entab);
int settabs(int *tabs, int tabn, int tablen);
int tabmod(int *tabs, int m, int n,  int maxtab);
int rantabs(int argc, char *argv[], int *tabs);
int parsarg(int argc, char *argv[], int *tabs, int maxtabs);

extern int insert(char *dest, char *src, int cn);
extern int getdalines(char *s[], int maxrow, int maxcol);
extern int getdaline(char *s, int max);
extern int inthere(int x, int *d, int n);

/* tab: sets or removes tabs */
int main(int argc, char *argv[])
{
	int tabs[MAXTABS];
	int nt = parsarg(argc - 1, argv + 1, tabs, MAXTABS);

	if(nt < 0){
		printf("syntax: entab [-m + n] [t, t2, t3,...tabstops]");
		return 1;
	}

	char *s[MAXLINES];
	int lines = getdalines(s, MAXLINES, MAXLEN);
	dentabs(s, lines, tabs, nt, TRUE); /* entab */
//	dentabs(s, lines, tabs, nt, FALSE); /* detab */
	printlines(s, lines);	
	return 0;
}

/* parsarg: reads and interprets arguments from terminal input, returns number of tabstops */
int parsarg(int argc, char *argv[], int *tabs, int maxtabs)
{

	*tabs = 0;
	int nt = maxtabs; 

	if(argc == 2){
		int m,  n;
		m = (**argv == '-') ? atof(*(argv) + 1): 0;
		n = (**(argv + 1) == '+') ? atof(*(argv + 1) + 1): 8;
		tabmod(tabs, m, n, maxtabs);
	}
	else if(argc == 0)
		settabs(tabs + 1, maxtabs, 8); 
	else if(isdigit(**argv))
		nt = rantabs(argc - 1, argv + 1, tabs + 1);		
	else /* error */
		return -1;
	return nt;
}

/* entabs: performs entab/detab in an array of strings */
int dentabs(char *s[], int lines, int *tabs, int nt, int en)
{
	if(0 < lines){
		if(1 == en)
			entab(*s, tabs, nt);
		else
			detab(*s, tabs, nt);
		dentabs(s + 1, lines - 1, tabs, nt, en);
	}
	return 0;
}


/* printlines: prints array of strings */
int printlines(char *s[], int lines)
{
	if(0 < lines){
		printf("%d: %s\n", strlen(*s), *s);
		printlines(s + 1, lines - 1);
	}
	return 0;
}
/* entab: replaces trailing spaces with appropriate tabs */
int entab(char *s, int *tabs, int nt)
{
	detab(s, tabs, nt);
	entab_1(s, strlen(s) - 1, tabs, nt);
}

/* entab_1: child process of entab */
int entab_1(char *s, int last, int *tabs, int nt)
{
	int ti = inwhere(last + 1, tabs, nt);
	(0 < ti) ? stot(s + *(tabs + ti - 1) - 1, s + last - 1) : 0;
	return (0 < last - 1) ? entab_1(s, last - 1, tabs, nt) : 0;
}

/* detab: removes tab and replaces them with spaces of custom length */
int detab(char *s, int *tabs, int nt)
{
	return detab_1(s, 0, tabs, nt);
}

/* detab_1: child process of detab */
int detab_1(char *s, int i, int *tabs, int nt)
{
	(*(s+i) == '\t') ? spacer(s, i + 1, tabs, nt) : 0;
	return (0 < *(s+i)) ? detab_1(s, i + 1, tabs, nt) : 0; 
}

/* stot: replaces postfix spaces with a tab in a non-terminated string */
int stot(char *from, char *to)
{
	if(*to == ' '){
		strcpy(from = (to + 1 - blankend(from, to)) , to);
		*from = '\t';
	}
	return 0;
}

/* rantabs: retrieves tabs from terminal input, argv must start from argv[1] and tabs from tabs[1], the function also assumes there is enough space in tabs[] */
int rantabs(int argc, char *argv[], int *tabs)
{
	if(0 < argc){
		*tabs = atof(*argv);
		return 1 +  rantabs(argc - 1, argv + 1, tabs + 1);
	}
	return 0;
}

/* tabmod: tab stops every n column starting at column m */
int tabmod(int *tabs, int m, int n,  int maxtab )
{
	*tabs = 0;
	*(tabs + 1) = m;
	settabs(tabs + 2, maxtab, n);
}

/* settabs: sets tabs based on preferred tab lengths */
int settabs(int *tabs, int tabn, int tablen)
{
	(0 < tabn) ? settabs(tabs, tabn - 1, tablen) : (*tabs = 0);
	return *(tabs + tabn) = *(tabs + tabn - 1) + tablen;
}

/* rspacecnt: counts adjacent spaces from the left of cn */
int rspacecnt(char *s, int cn)
{
	return (0 < cn && *s == ' ') ? (1 + rspacecnt(s - 1, cn - 1)) : 0;
}

/* blankend: returns the # of spaces at the right end of a string */
int blankend(char *from, char *to)
{
	return (*to == ' ' && from <= to) ? 1 + blankend(from, to - 1) : 0;
}

/* spacer: enters spaces to s[cn - 1]   */
int spacer(char *s, int cn, int *tabs, int tabn)
{
	*(s + cn - 1) = ' ';
	char *buf = malloc(strlen(s) + 1);
	spread(buf, ' ', findtab(cn + 1, tabs, tabn) - cn);
	insert(s, buf, cn);
	return 0;
}

/* findtab: returns the next tabstop after the cnth character, nt = number of tabstops */
int findtab(int cn, int *tabs, int nt)
{
	return (*tabs > cn || nt <= 1) ? (*tabs) : findtab(cn, tabs + 1, nt - 1);
}

/*spread: fills s[] with c */
int spread(char *s, char c, int slen)
{
	return (0 < slen) ? spread(s + 1, *s = c, slen - 1) : (*s = '\0');
}



/* cc  tab.c insert.c strfsh.c slice.c getdalines.c getdaline.c alloc.c inthere.c */
