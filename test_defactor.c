#include "test.h"
#define MAXFACTS 1000
int main()
{
	extern int defactor(int, int *);
	int facts[MAXFACTS], i;
	int n = defactor(10, facts);
	for(i = 1; i < n; i++)
		printf("%d\n", facts[i]);
}
