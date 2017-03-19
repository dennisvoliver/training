#define ALLOCSIZE 10000	/* size of stack */

static char allocbuf[ALLOCSIZE];	/* stack */
static char *allocp = allocbuf;		/* free space index */

/* alloc: allocates n memory spaces of size char */
char *alloc(int n)
{
	if((allocp + n - allocbuf) < ALLOCSIZE) 	/* if n spaces will not exceed the buffer size */{
		allocp += n;	/* move allocp to new free space */
		return allocp - n;	/* return original allocp */
	}
		return 0;	/* overflow */

}
void afree(char *p)
{
	if(allocbuf <= p && p < allocbuf + ALLOCSIZE)	/* as long as p falls within the stack address */
		allocp = p;	/* free the space */
}
