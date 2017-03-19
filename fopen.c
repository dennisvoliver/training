#include "stdio.h"
//#include <stdio.h>

int main()
{
	FILE *p = fopen("iob.h", "r");
	int c;
	while ((c = getc(p)) != 'f')
		putc(c, stderr);
	lseek(p->fd, 2L, 1);
	while ((c = getc(p)) != EOF)
		putc(c, stderr);
	return 0;
}


