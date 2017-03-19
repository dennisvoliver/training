#include "test.h"

int isupper(int c);

int main()
{
	printf("%d\n", isupper('b'));
}

int isupper(int c)
{
	return (c >= 'A' && c <= 'Z') ? 1: 0;
}
