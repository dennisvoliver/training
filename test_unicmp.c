#include "test.h"

int main()
{
	char s[] = "abcd123 \t\n@#$";
	char t[] = "ABCd123 \t\n@#*";

	extern int unicmp(char *s, char *t, int f, int d, int n);
	printf("%d\n", unicmp(s, t, 0, 1, 0));
}
