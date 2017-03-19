#include <stdio.h>

int main()
{
	int header = 10;
	int nbytes = 0;
	int nunits = (nbytes+header-1)/header + 1;
	printf("%d %d\n", nunits, (nbytes-1)/header + 2);
}
