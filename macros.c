#include<stdio.h>

#define min(A, B) (A < B) ? (A) : (B)
#define square(x) x * x
#define debugprint(expression) printf(#expression " = %d\n",expression)
#define conc(left, right) left ## right
#define swap(t, x, y) {t temp; temp = y; y = x; x = temp;}

#ifndef HDR
	#define HDR	\ 
		'1'
#endif
int main()
{
	printf("%c\n", HDR);
}
