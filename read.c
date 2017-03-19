#include<stdio.h>
#define MAXLEN 100
#define MAXLINE  39

/* read: prints all pages in a group of files */
int main(int argc, char *argv[])
{
	int pn, ln = 0;
	FILE *fp;
	char buf[MAXLEN];

	/* while there is a file */
	while(--argc > 0) {
		fp = fopen(*++argv, "r");
		pn = 0;
		printf("\n\nFILE: %s\n\t\t\t\t\t\t\t\t\t\tPAGE: %d\n\n", *argv, ++pn);
		/* while there is a line */
		while (fgets(buf, MAXLEN, fp) != NULL) {
			if (ln < MAXLINE) { /* if line is within page */
				ln++;
			} else {
				printf("\n\nFILE: %s\n\t\t\t\t\t\t\t\t\t\tPAGE: %d\n\n", *argv, ++pn);
				ln = 0;
			}
			printf("%s", buf);
		}
		fclose(fp);
	}
	return 0;
}
