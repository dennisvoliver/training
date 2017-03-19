#include <stdio.h>
#include <stdlib.h>

int read(char **s, int n);

int main()
{
	char symbols[] = "hello";
	int symn = sizeof(symbols) - 1;

	int keyn = 3;
	char *keys[3];
	keys[0] = "hello";
	keys[1] = "ahere";
	keys[2] = "iate";

	read(keys, keyn);

	return 0;
}

int read(char **s, int n)
{
	if (n <= 0)
		return 0;
	putchar(**s);
	return read(s + 1, n - 1);
}

int spread(char **key, int n, char *sym)
{
	if (n <= 0)
		read(key, sizeof(key) / sizeof(*key));
}

