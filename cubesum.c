#include <stdio.h>
#include <math.h>
#define FIRST 1
#define LAST 20 
#define EXP 3 

/* prints sums of cubes (or more) in ascending order or only those which can be represented in two ways */
int main()
{

	int total = LAST * (LAST + 1) / 2;
	int i, j, k, v[total];

	k = 0;
	for (i = FIRST; i <= LAST; i++) {
		for (j = FIRST; j <= i; j++) {
			if (k < total)
				v[k++] = (int)(pow(j, EXP) + pow(i, EXP));
		}
	}

	
	extern void qsort(int v[], int, int);
	qsort(v, 0, total - 1);	

	int current = v[0];
	for (k = 1; k < total; k++) {
		if (current == v[k])
		//if (1)
			printf("%5d ", v[k]);
		else
			current = v[k];
	}

	return 0;
}
