#include <stdio.h>
#include <stdlib.h>
#define MAXROW 12
#define MAXCOL 9 

struct team {
	int mem1;
	int mem2;
	struct team *next;
	struct team *prev;
} A = {0, 0, NULL};

int main()
{
	struct team *current = &A;
	int row, col;

	/* fill list */
	for (row = 1; row <= MAXROW; row++) {
		for (col = 1; col <= MAXCOL; col++) {
			current->mem1 = row;
			current->mem2 = col;
			current->next = (struct team *)malloc(sizeof(struct team));
			current->next->prev = current;
			current = current->next;
		}
		
	}

	/* remove the last item */
	current = current->prev;
	current->next = NULL;
	current = &A;
	struct team *minor;

	int count = 0;

	/* print combos */
	while (current != NULL) {
		minor = current->next;
		while (minor != NULL) {
				printf("(%d, %d) vs (%d, %d)\n", current->mem1, current->mem2, minor->mem1, minor->mem2);
				minor = minor->next;
				count++;
		}

		current = current->next;
	}

	printf("total: %d\n", count);
	return 0;
}
