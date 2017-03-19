#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000


int getdaline(char *s, int max);

/* not done yet */
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int count = 0;
	int n, m;
	n = 1;
	m = 8;
	while (getdaline(line, MAXLINE) > 0) {
		if (line[n - 1] == 'b' && line[m - 1] == 'a')
			printf("%s %d\n", line, ++count);
	}
	return 0;
}
