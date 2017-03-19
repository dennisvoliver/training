#define assert(x,n) ((x) ? 0: exit(n))
#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20 


/* max #files open at once */
typedef struct _iobuf {
	int cnt; 	/* characters left */
	char *ptr; 	/* next character position */
	char *base; 	/* location of buffer */
	unsigned int _READ : 1; 	/* file open for reading */
	unsigned int _WRITE : 1; 	/* file open for writing */
	unsigned int _ERR : 1; 	/* file unbuffered */
	unsigned int _UNBUF : 1; 	/* file unbuffered */
	unsigned int _EOF : 1;	/* EOF has occurred on this file */
	int fd;		/* file descriptor */
} FILE;

/* stdin, stdout, stderr */
FILE _iob[OPEN_MAX] = {
{0, (char *) 0, (char *) 0, 1, 0, 0, 0, 0, 0}, 
{0, (char *) 0, (char *) 0, 0, 1, 0, 0, 0, 1}, 
{0, (char *) 0, (char *) 0, 0, 1, 0, 1, 0, 2}, 

};


#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])


int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) (((p)->* _EOF) != 0)
#define ferror(p) (((p)->* _ERR) != 0)
#define fileno(p) (((p)->fd)

#define getc(p)	(--(p)->cnt >= 0 \
		? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p) (++(p)->cnt <= BUFSIZ && (p)->base != NULL \
		? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)



#include <sys/file.h>
#define PERMS 0666/* RW for owner, group, others */ 
FILE *fopen(char *name, char *mode)
{
	int fd;
	FILE *fp;
	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if ((fp->_READ == 0 && fp->_WRITE == 0))
			break;	/* found free slot */
	if (fp >= _iob + OPEN_MAX) /* no free slots */
		return NULL;
	if (*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else
		fd = open(name, O_RDONLY, 0);
	if (fd == -1) /* couldn't access name */
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;

	if (*mode == 'r') {
		fp->_READ = 1;
		fp->_WRITE = fp->_UNBUF = fp->_EOF =  fp->_ERR = 0;
	} else {
		fp->_WRITE = 1;
		fp->_READ = fp->_UNBUF = fp->_EOF =  fp->_ERR = 0;
	}

	return fp;
}


#include<stdlib.h>

/* _fillbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
	int bufsize;
	/* if not read only with no error or eof */
	if (!(fp->_READ == 1 && fp->_EOF == 0 && fp->_ERR == 0))
		return EOF;
	bufsize = (fp->_UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL) /* no buffer yet */
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF; /* can't get buffer */
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->_EOF;
		else
			fp->_ERR;
	fp->cnt = 0;
	return EOF;
	}
	return (unsigned char) *fp->ptr++;
}

/*
#define putc(x,p) (++(p)->cnt <= BUFSIZ && (p)->base != NULL \
		? *(p)->ptr++ = (x) : _flushbuf((x),p))
*/

/* _flushbuf: stores buffer to FILE */
int _flushbuf(int c, FILE *fp)
{
	if (fp->base == NULL) {
		if (fp->_UNBUF != 1)
			if((fp->ptr = fp->base = (char *) malloc(BUFSIZ)) == NULL)
				return -1;
		fp->cnt = 0;
		if(write(fp->fd, &c, 1) != 1) {
			fp->_ERR = 1;
			return -1;
		} else {
			return (unsigned char) c;
		}
	} else {
		*fp->ptr++ = c; /* *fp->ptr must be empty or replaceable */
		if (write(fp->fd, fp->base, fp->cnt) != fp->cnt) {
			fp->_ERR = 1;
			return -1;
		} else {
			fp->base = fp->ptr = NULL;
			fp->cnt = 0;
			return c;			
		}
	} 

}


/* fflush: flushes the buffer of fp */
int fflush(FILE *fp)
{
	if (fp->_UNBUF != 1)
		return _flushbuf(*--fp->ptr, fp) < 0 ? -1 : 0;
	return 0;
}
/* fclose: flushes a file's buffer then closes it */
int fclose(FILE *fp)
{
	int c = 0;
	fflush(fp);
	fp->_READ = fp->_WRITE = 0;
	close(fp->fd);
	return c;
}

/* fseek: same as lseek but does so with files */
int fseek(FILE *fp, long offset, int origin)
{
	if (fp->cnt > 0)
		fflush(fp);
	if (lseek(fp->fd, offset, origin) >= 0)
		return 0;
	return -1;
}
