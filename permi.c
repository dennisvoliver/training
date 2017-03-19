#include <stdio.h>
#include <stdlib.h>

struct key {
	char *c;
	struct key *next;
} Board = {"\0", NULL};

int main()
{
	char symbols[] = "hello";
	int keyn = 3;
	int symn = sizeof(word) - 1;

	return 0;
}

int read(struct key *r)
{
	if (r == NULL)
		return 0;
	putchar(*(r->c));
	return read(r->next);
}

int spread(struct key *r, int n, char *s)
{
	if (n <= 0)
		read(&Board);

	int i = sizeof(s) - 2;

	for (; i > 0; i--) {
		if (s != r->c) {
			r->next = (struct key *)malloc(sizeof(struct key));
			r->next->c = s + i;
			r->next->next = NULL;
		}
	}
}
