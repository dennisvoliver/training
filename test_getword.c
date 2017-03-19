#include "test.h"

int main()
{
	extern int getword(char *word, int lim);
	char line[MAXLEN];
	while (getword(line, MAXLEN) != EOF)
		printf("%s\n", line);
}
