#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>	
#include "debug.h"

#define MAXWORD 100

	/* 
	Let there be a tree T whose nodes are sorted in some manner.
	Let there be another tree U whose nodes are sorted in some other manner.
	Let each node of U be a node in T.
	*/

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;

};

struct unode {

	struct tnode *t;
	struct unode *left;
	struct unode *right;

};


struct tnode *addtree(struct tnode *, char *);
extern int getword(char *, int);

/* prints distinct words in its input sorted into decreasing order of frequency of occurrence, each word is preceded by its count */
int main(int argc, char *argv[])
{
	struct tnode *root;
	struct unode yggdrasil;
	struct tnode head;
	char word[MAXWORD];
	extern void treeprint(struct tnode *);
	extern void utreeprint(struct unode *);
	extern struct unode *readt(struct unode *u, struct tnode *t);


	root = NULL;
	while (getword(word, MAXWORD)  != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);

	/* print in descending frequency */
	if (argc > 1 && **++argv == '-' && *++*argv == 'f')  {
		yggdrasil.left = yggdrasil.right = NULL;
		head.word = "";
		head.left = head.right = NULL;
		yggdrasil.t = &head;
		utreeprint(readt(&yggdrasil, root)->right);

	}
	else
		treeprint(root);
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


struct tnode *talloc(void);
char *strdups(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {	/* a new word has arrived */
		p = talloc();	/* make a new node */
		p->word = strdups(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;	/* repeated word */
	else if (cond < 0)	/* less than into left subtree */
		p->left = addtree(p->left, w);
	else			/* greater than into right subtree */
		p->right = addtree(p->right, w);
	return p;
}


/* readt: reads all nodes in t */
struct unode *readt(struct unode *u, struct tnode *t)
{
	extern struct unode *resort(struct unode *u, struct tnode *t);
	if (t != NULL) {
		readt(u, t->left);
		readt(u, t->right);
		return resort(u, t); 
	}

}

/* resort: stores a tnode in a tree sorted in decreasing word frequency */
struct unode *resort(struct unode *u, struct tnode *t)
{
	extern struct tnode *recrop(struct tnode *, struct tnode *);
	if (u == NULL) {
		u = (struct unode *)malloc(sizeof(struct unode));
		u->t = t;
		u->left = u->right = NULL;
		u->t->left = u->t->right = NULL;
	} else if (t->count == u->t->count)
			u->t = recrop(u->t, t);
	else if (t->count < u->t->count)
		u->left = resort(u->left, t);
	else
		u->right = resort(u->right, t);
	return u;
}

/* recrop: same as addtree except that it does not reserve storage but merely overwrites the left and right child nodes*/
struct tnode *recrop(struct tnode *dest, struct tnode *src)
{
	int cond;

	if (dest == NULL) {	/* a new word has arrived */
		dest = src;	/* make a new node */
		dest->left = dest->right = NULL;
	} else if ((cond = strcmp(src->word, dest->word)) == 0)
		; /* all words in src are distinct */
	else if (cond < 0)	/* less than into left subtree */
		dest->left = recrop(dest->left, src);
	else			/* greater than into right subtree */
		dest->right = recrop(dest->right, src);
	return dest;
}


/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* utreeprint: in-order print of tree p */
void utreeprint(struct unode *p)
{
	extern void treeprint(struct tnode *p);
	if (p != NULL) {
		utreeprint(p->right);
		treeprint(p->t);
		utreeprint(p->left);
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdups(char *s)	/* make a duplicate of s */
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);	/* +1 for '\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}
