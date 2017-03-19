#include<stdio.h>
#include<stdlib.h>
#include "debug.h"

#define NCHARS 100

struct wnode {
	char *word;
	struct lnode *lines;
	struct wnode *left;
	struct wnode *right;
};

struct lnode {
	int line;
	struct lnode *left;
	struct lnode *right;
};

/* This program prints a list lf all words in a document, and for each word, a list of the line numbers on which it occurs. Noise words like "the," "and", and so on are ignored. */
int main()
{

	extern int isnoise(char *);
	extern int getword(char *, int);
	extern struct wnode *addword(struct wnode *, char *, int);
	extern void printwords(struct wnode *);
	struct wnode *words = NULL;
	struct lnode *lines = NULL;
	char w[NCHARS]; 

	int line = 1;
	while (getword(w, NCHARS) != EOF) {
		if (w[0] == '\n') 
			line++;
		if (!isnoise(w) &&  isalpha(w[0])) 
			words = addword(words, w, line);

	}
	printwords(words);
	return 0;
}


/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	extern int getch(void);
	extern void ungetch(int);
	int c;
	char *w = word;

	while (isspace(c = getch()) && c != '\n')
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

/* printwords: prints all words in a tree, wherein each word is followed by a list of integers */
void printwords(struct wnode *p)
{
	extern void printlines(struct lnode *);
	if (p != NULL) {
		printwords(p->left);
		printf("%s\t", p->word);
		printlines(p->lines);
		printf("\n");
		printwords(p->right);
	}
}

/* printlines: prints a tree of integers in ascending order separated by '\t' */
void printlines(struct lnode *p)
{
	if (p != NULL) {
		printlines(p->left);
		printf("%d ", p->line);
		printlines(p->right);
	}
}

struct wnode *addword(struct wnode *p, char *w, int n)
{
	extern struct lnode *addline(struct lnode *, int );
	extern struct wnode *walloc(void);
	extern char *strdups(char *);

	int cond;
	if (p == NULL) {	/* a new word has arrived */
		p = walloc();	/* make a new node */
		p->word = strdups(w);
		p->lines = addline(p->lines, n);
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		addline(p->lines, n);	/* repeat word */
	else if (cond < 0)	/* less than into left subtree */
		p->left = addword(p->left, w, n);
	else			/* greater than into right subtree */
		p->right = addword(p->right, w, n);
	return p;
}

/* lnode: adds new lnode, ignores if n is found in tree */
struct lnode *addline(struct lnode *p, int n)
{
	extern struct lnode *lalloc(void);
	if (p == NULL) {	/* a new integer has arrived */
		p = lalloc();	/* make a new node */
		p->line = n;
		p->left = p->right = NULL;
	} else if (n < p->line)	/* less than into left subtree */
		p->left = addline(p->left, n);
	else if (p->line < n)	/* greater than into right subtree */
		p->right = addline(p->right, n);
	return p;
}

/* walloc: make a new wnode */
struct wnode *walloc(void)
{
	return (struct wnode *) malloc(sizeof(struct wnode));
}

/* lalloc: make a new lnode */
struct lnode *lalloc(void)
{
	return (struct lnode *) malloc(sizeof(struct lnode));
}
