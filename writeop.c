/* not working */

extern int scopy(char *to, char *from);

/* writeop: writes all arguments read from command line and stores it to one array */
int writeop(char *s, int *argv[], int argc)
{
	printf("%d\n", argc);
	return (argc > 1) ? writeop(s + scopy(s, argv + 1) + 1, argv + 1, argc - 1): 0;
}
