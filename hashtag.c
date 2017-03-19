#include<stdlib.h>

struct nlist {	/* table entry: */

	struct nlist *next; 	/* next entry in chain */
	char *name; 		/* defined name */
	char *defn;		/* replacement text */

};


#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
	hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			/* found */
			return np;
	/* not found */
	return NULL;
}


struct nlist *lookup(char *);
char *strdup(char *);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	if ((np = lookup(name)) == NULL) { /* not found */
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else
		/* already there */
		free((void *)np->defn);

	/*free previous defn */
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

/* undef: will remove a name and definition from the table maintained by lookup and install.*/
int undef(char *name)
{
	struct nlist *np = lookup(name);
	free((void *)np->name);
	free((void *)np->defn);
	return 0;
}
