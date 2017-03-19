/* cc find1.c getdaline.c getch.c */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#define MAXFILES 3

extern int getdaline(char *line, int max);

/* find: print lines that match pattern from 1st arg */
main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	/* check arguments */
	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])	/* while ((c = *++argv[0]) != '\0') */
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}

	FILE *in;
	char *pattern;
	if (argc < 1) /* if pattern not specified, print error */
		fprintf(stderr, "Usage: find -x -n pattern [file/s]\n");	

	else if (argc == 1) { /* if there are no input files specified, use stdin */
		while (getdaline(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s\n", line);
				found++;
			}
		}

	} else {
		pattern = *argv;
		while (--argc > 1) {/* while there is a file */
			if((in = fopen(*++argv, "r")) != NULL) {
				while (fgets(line, MAXLINE, in) > 0) { /* while there is a line */
					lineno++;
					if ((strstr(line, pattern) != NULL) != except) {
						printf("%s: ", *argv);
						if (number)
							printf("%ld:", lineno);
						printf("%s\n", line);
						found++;
					}
				}
				fclose(in);	
			}
		}
	}
	return found;
}

