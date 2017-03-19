#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(char argc, char *argv[])
{
	FILE *fx, *fy;
	int maxlen = (argc > 3) ? atof(argv[3]) : 100;
	char *sx = (char *)malloc(maxlen);	
	char *sy = (char *)malloc(maxlen);	

	if (argc < 3) {
		fprintf(stdout, "not enough arguments");
		return 2;
	}
	char *prog = argv[0], *first = argv[1], *second = argv[2] ;
	fx = fopen(first, "r");
	fy = fopen(second, "r");

	while ((sx = fgets(sx, maxlen, fx)) != NULL ) {
		sy = fgets(sy, maxlen, fy);
		if (strcmp(sx, sy) != 0 || sy == NULL)  {
			fprintf(stdout, "%s: %s\n%s: %s\n", first, sx, second, sy);
			if (ferror(stdout))
				fprintf(stderr, "%s error writing stdout\n", prog);
		}
		exit(1);
	}

	if (sy != NULL)
			fprintf(stdout, "%s: %s\n%s: %s\n", first, sx, second, sy);
	else
		fprintf(stdout, "%s and %s are similar", first, second);

	fclose(fx);
	fclose(fy);
	return 0;
}

	/* open both files */
	/* while there is a line on both files */
		/* if the two lines are not equal */
			/* print the two lines in the output file */
			/* if there is an error in the output file */
				/* print an error in the std err */
		/* exit the program */
	/* exit the program and return all files */
