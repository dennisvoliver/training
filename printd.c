#include<stdio.h>

int main()
{
	extern void printd(int);

	printd(12345);

}

/* printd: prints n in decimal */
void printd(int n)
{
	if(n < 0){
		putchar('-');
		n = -n;
	}
	if(n / 10)
		printd(n / 10);
	
	putchar(n % 10 + '0');
}
