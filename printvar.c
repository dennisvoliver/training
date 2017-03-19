#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>	

#define MAXWORD 100

/* A tnode is a node that contains a string, an integer, and pointers to its left and right child nodes */
struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;

};

/* A stem is a node that contains a pointer to a tnode tree. */
struct stem {
	struct tnode *node;
	int count;
	struct stem *left;
	struct stem *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
extern int getword(char *, int);
struct stem *addstem(struct stem *, struct tnode *, char *, int n);
void stemprint(struct stem *p);

/* Print all groups of partially equivalent C variables from a source code in the text stream. */
int main(int argc, char *argv[])
{
	struct tnode *root;
	struct stem *seed;
	char word[MAXWORD];
	extern int iskey(char *s);

	/* Variables are compared only up to the nth character. */
	int n = (argc > 1 && isdigit(**++argv)) ? atof(*argv): 6;

	/* For all distinct variables, find a place for them in the tree of trees. */
	root = NULL;
	seed = NULL;
	while (getword(word, MAXWORD)  != EOF)	
		if (isalpha(word[0]))		
			if (!iskey(word))	
				seed = addstem(seed, root, word, n);

	/* Print all words in all groups with more than one word. */
	stemprint(seed);
	return 0;
}

struct tnode *talloc(void);
char *strdups(char *);
struct stem *stalloc(void);

/* addstem: creates a tree of trees, compares only the first n characters */
struct stem *addstem(struct stem *s, struct tnode *root, char *w, int n)
{
	int cond;

	if (s == NULL) {
		s = stalloc();
		s->node = addtree(root, w);
		s->count = 1;
		s->left = s->right = NULL;
	} else if ((cond = strncmp(w, s->node->word, n)) < 0)
		s->left = addstem(s->left, root, w, n);
	else if (cond > 0)
		s->right = addstem(s->right, root, w, n);
	else 
		addtree(s->node, w);			/* add word but don't change s-> node */
	return s;
}

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

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* stemprint: print all words in all stems with more than one tnode */
void stemprint(struct stem *p)
{
	if (p != NULL) {
		stemprint(p->left);
		/* if there is more than one non-empty node, print the tree */
		if(p->node->left != NULL || p->node->right != NULL)
			treeprint(p->node);
		stemprint(p->right);
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/*stalloc: make a stem node */
struct stem *stalloc(void)
{
	return (struct stem *) malloc(sizeof(struct stem));
}

char *strdups(char *s)	/* make a duplicate of s */
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);	/* +1 for '\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}
