#include "test.h"
#include<math.h>

int main()
{
	extern char *itor(int d, int r, char *s);
	char s[100];
	itor(16, 16, s);
	printf("%s\n", s);
}
