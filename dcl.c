#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN 100
#define MAXLEN 1000

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;		/* type of last token */
char token[MAXTOKEN];	/* last token string */
char name[MAXTOKEN];	/* identifier name */
char datatype[MAXTOKEN];/* data type = char, int, etc. */
char out[MAXLEN];		/* what will be printed */
int reset(void);

int main()	/* convert declaration to words */
{
	while (gettoken() != EOF) {	/* 1st token on line */
		strcpy(datatype, token);/* is the datatype */
		out[0] = name[0] = '\0';
		dcl();		/* parse rest of line */
		if (tokentype != '\n') {
			printf("syntax error\n");
			reset();
		}
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

/* reset: resets all variables and arrays */
int reset(void)
{
	int i;
	for (i = 0; i < MAXTOKEN; i++) 
		name[i] = datatype[i] = token[i] = out[i] = '\0';
	for (; i < MAXLEN; i++) 
		out[i] = '\0';
	tokentype = '\n';
	return  0;
}

/* dcl: parse a declarator */
void dcl(void)
{
	int ns; /* pointer to */
	for (ns = 0; gettoken() == '*'; ) /* count asterisks */
		ns++;
	dirdcl();	/* read inner parens */
	while (ns-- > 0)
		strcat(out, " pointer to");
}

/* dirdcl: parse a declarator */
void dirdcl(void)
{
	int type;

	if (tokentype == '(') {		/* ( dcl ) */
		dcl();
		if (tokentype != ')') 
			printf("error: missing )\n");
	} else if (tokentype == NAME)	/* variable name */
		strcpy(name, token);
	else 
		printf("error: expected name or (dcl)\n");
	while ((type=gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS) {
//			strcat(out, " function returning");
			strcat(out, " function accepting ");
			strcat(out, token);
			strcat(out, " returning");
		} else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}
/* gettoken: return next token */
int gettoken(void)
{
	int c;
	extern int getch(void);
	extern void ungetch(int);
	char *p = token; 	/* because arrays can't be incremented */


	while ((c = getch()) == ' ' || c == '\t')
		;	/* skip blanks */
	if (c == '(') {
		if ((c = getch()) == ')') { /* if empty parens */
			strcpy(token, "()");
			return tokentype = PARENS;
		 } else if (isalpha(c) && 0 < strlen(name)) { /* or function parameter */
			for (*p++ = '(', *p++ = c; (*p++ = getch()) != ')'; )
				;
			*p = '\0';
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}

	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) { /* if identifier */
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else {
		return tokentype = c;
	}
}
