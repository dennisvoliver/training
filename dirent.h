#include <stdlib.h>
#include <fcntl.h>	/* flags for read and write */
#include <sys/stat.h>	/* structure returned by stat */
#include <string.h>

#define NAME_MAX 14 /* longest file name component */
			/* system-dependent */

typedef struct {	/* portable directory entry */
	long ino;		/* inode number */
	char name[NAME_MAX+1];	/* name + '\0' terminator */
} Dirent;

typedef struct {	/* minimal DIRT: no buffering, etc. */
	int fd;		/* file descriptor for the directory */
	Dirent d;	/* the directory entry */
} DIRT;

DIRT *my_opendir(char *dirname);
Dirent *my_readdir(DIRT *dfd);
void my_closedir(DIRT *dfd);


#ifndef DIRSIZ
#define DIRSIZ 14
#endif

struct direct {	/*directory entry */
	ino_t d_ino;	/* inode number */
	char d_name[DIRSIZ];	/* long name does not have '\0' */
};

/* my_opendir: open a directory for my_readdir calls */
DIRT *my_opendir(char *dirname)
{
		int fd;
		struct stat stbuf;
		DIRT *dp;

		if ((fd = open(dirname, O_RDONLY, 0)) == -1
		 || fstat(fd, &stbuf) == -1
		 || (stbuf.st_mode & S_IFMT) != S_IFDIR
		 || (dp = (DIRT *) malloc(sizeof(DIRT))) == NULL)
			return NULL;
		dp->fd = fd;
		return dp;
}

/* my_closedir: close directory opened by my_opendir */
void my_closedir(DIRT *dp)
{
	if (dp) {
		close(dp->fd);
		free(dp);
	}
}

#include <sys/dir.h>	/* local directory structure */

/* my_readdir: read directory entries in sequence */
Dirent *my_readdir(DIRT *dp)
{
	struct direct dirbuf;	/* local directory structure */
	static Dirent d;	/* return: portable structure */

	while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf))
			== sizeof(dirbuf)) {
		if (dirbuf.d_ino == 0)	/* slot not in use */
			continue;
		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, DIRSIZ);
		d.name[DIRSIZ] = '\0';	/* ensure termination */
		return &d;
	}
	return NULL;
}
