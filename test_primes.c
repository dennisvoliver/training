#include "test.h"
#define MAX 1000000

int main()
{
	unsigned int num[MAX];
	unsigned int i, j;
	for(i = 0; i < MAX; i++)
		num[i] = i;
	for(i = 2; i < MAX; i++)
		for(j = 2 * i; j < MAX; j += i)
			num[j] = 0;
	
	unsigned int primes[MAX];
	unsigned int k = 0;
	for(i = 2; i < MAX; i++)
		if(num[i] != 0)
			printf("%uth %u\n",k,  primes[k++] = num[i]);
}
