#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debug.h"

int combo(char *digits, int n, char *symbols, int m);
int perm(char *digits, int n, char *symbols, int m);
int checkdups(void);
int dist(char *w);

static int count = 0;
static int count2 = 0;

struct list {
	char *word;
	struct list *next;

} A = {NULL, NULL};

struct list B = {NULL, NULL};
struct list *current = &A;

/* combinatorics and permutations */
int main()
{


	char word[] = "abc";
	int m = sizeof(word) - 1;

	int n = m + 1;
	char buffer[n]; buffer[n - 1] = '\0';

	combo(buffer, n - 1, word, m);
	//checkdups();
	//printf("combo: %d perm: %d\n", count, count2);

	int i = 0;
/*
	for (current = A.next; current != &A; current = current->next) {
		if (dist(current->word) > 0 || 1) {
			printf("%s\n", current->word);
			i++;
		} 
	}
	printf("%d\n", i);
*/
	printf("%d\n", count);
	return 0;
}

/* permutation */
int checkdups(void)
{
	struct list *temp;
	current = A.next;
	int found = 0;

	for (; current->word != NULL; current = current->next) {
		found = 0;

		for (temp = &B; temp->next != NULL; temp = temp->next) {
			//printf("%s %s\n", current->word, temp->next->word);
			if (strcmp(current->word, temp->next->word) == 0) {
				found++;		
			} 		
		}

		if (found == 0) {
			temp->next = (struct list *)malloc(sizeof(struct list));
			temp->next->word = current->word;
			temp->next->next = NULL;
			//printf("%s\n", temp->next->word);
			count2++;
		}
	}
	return 0;
}

/* returns 1 if all characters are distinct, 0 otherwise */
int dist(char *w)
{
	char *temp1, *temp2;
	int found;
	for (temp1 = w; *temp1 != '\0'; temp1++)  {
		for (temp2 = w, found = 0; *temp2 != '\0'; temp2++) {
			if (*temp1 == *temp2) 
				found++;
		}
		if (found > 1)
			return 0;
	}

	return 1;
}


/* combinations */
int combo(char *digits, int n, char *symbols, int m)
{
	if (n <= 0 ) {
		current->next = &A;
		current->next = (struct list*)malloc(sizeof(struct list));
		current = current->next;
		current->word = (char *)malloc(sizeof(digits));
		strcpy(current->word , digits);
		count++;
		printf("%s\n", digits);
		assert(*digits != '\0');
		return 0;
	}

	int i;
	for (i = 0; i < m; i++) {
		digits[n - 1] = symbols[i];
		combo(digits, n - 1, symbols, m);
	}

	return 0;
}

/* 
int perm(char *digits, int n, char *symbols, int m)
{

	if (n <= 0) {
		//printf("%s\n", digits);
		count++;
		return 0;
	}

	int i;
	for (i = 0; i < m; i++) {
		if (digits[n] != symbols[i]) {
			digits[n - 1] = symbols[i];
			combo(digits, n - 1, symbols, m);
		}
	}

	return 0;

}
*/
