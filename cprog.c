#include<stdio.h>

int main()
{
	int fhar, celsius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	fhar = lower;

         while(fhar <= upper){
                celsius = 5 * (fhar - 32) / 9;
                printf("%d\t%d\n", celsius, fhar);
		fhar = fhar + step;
	}

}
