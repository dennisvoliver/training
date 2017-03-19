#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
	char c;
	struct tnode *bro;
	struct tnode *son;
} Dad = {'\0', NULL, NULL};

int read(struct tnode *r);
char *pluck(const char *s, int n);

int main()
{
	
//	read(Dad.son);
	printf("%s\n", pluck("hello there mate", 8));
	return 0;
}


/* read: reads all nodes in the tree in depth-first order */
int read(struct tnode *r)
{
	if (r == NULL)
		return 0;
	putchar(r->c);
	read(r->son);
	return read(r->bro);
}

/* grow: creates a tree where-in each stem is a permutation of s */
int grow(struct tnode *r, int level, char *s, int symbol)
{


/*
	if container is full or there are no more symbols
		return
	pluck out a symbol and send to son
	when it returns,
		create a brother
		send all symbols to brother and tell him which symbol to pluck next
	
*/

}

/* pluck: returns a string s without the nth character */
char *pluck(const char *s, int n)
{
	int m = strlen(s);
	if (n < 1 || n > m)
		return NULL;
	char *temp = (char *)malloc(m);
	int i;

	for (i = 0; (*temp = s[i]) != '\0' ; i++) {
		if ((i != (n - 1))) {
			temp++;
		}
	}
	return temp - m + 1;
}
