#include <stdio.h>
#include <sys/file.h>

void filecopy(int ifd, int ofd);

/* cat: concatenate files using file descriptors */
int main(int argc, char *argv[])
{
	int fd;
	if (argc == 1) /* no args; copy standard input */
		filecopy(0, 1);
	else
		while(--argc > 0)
			if ((fd = open(*++argv, O_RDONLY, 0)) < 3) { /* because 0, 1, and 2 are standard */
				fprintf(stderr, "cat: can't open %s\n", *argv);
				return 1;
			} else {
				filecopy(fd, 1);
				close(fd);
			}
	return 0;
}

/* filecopy: copy file ifd to file ofd */
void filecopy(int ifd, int ofd)
{
	char buf[BUFSIZ];
	int n;
	while ((n = read(ifd, buf, BUFSIZ)) > 0) 
		write(ofd, buf, n);
}


