#include <stdio.h>
#include "malloc.h" 
#define MAX 30 

	void bfree(char *, unsigned);
	void *my_malloc(unsigned nbytes);
	void my_free(void *ap);

int main()
{
/*
	void *my_calloc(unsigned, unsigned);
	int n = 10;
	int *p = (int *) my_calloc(10, sizeof(int));
	int i;
	for (i = 0; i < n; i++)
		printf("%d\n", p[i]);

*/

/*
	Header *p = (Header *) my_malloc(MAX);
	my_free(p);
*/

	char s[MAX] = "012345678901234567890123hello";
	bfree(s, 30);
	printf("%s\n", (char *) my_malloc(10));
	return 0;
}

