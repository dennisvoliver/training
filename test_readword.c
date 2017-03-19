#include "test.h"

int main()
{

	extern char *readword(char *, char *, int);
	char line[] = "hello citizens of the computer world\n";
	char *buf = line;
	char w[MAXLEN];
	char temp;

	while ((temp = *(buf = readword(buf, w, MAXLEN))) != '\0')
		printf("%s %c\n", w, temp);
}
