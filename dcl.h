#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN 100
#define MAXLEN 1000

enum { NAME, PARENS, BRACKETS };

char token[MAXTOKEN];	/* last token string */
char out[MAXLEN];		/* what will be printed */
int tokentype;		/* type of last token */
