#include <stdio.h> /* for NULL */
#include <stdlib.h> /* for exit() */
#define assert(x,n) (x) ? 0: exit(n)

typedef long Align;	/* for alignment ot long boundary */

union header {	/* block header */
	struct {
		union header *ptr;	/* next block if on free list */
		unsigned size;		/* size of this block */
	} s;
	Align x;		/* force alignment of blocks */
};

typedef union header Header;

static Header base;	/* empty list to get started */
static Header *freep = NULL;	/* start of free list */

/* my_malloc: general-purpose storage allocator */
void *my_malloc(unsigned nbytes)
{
	Header *p, *prevp;
	Header *morecore(unsigned);
	unsigned nunits;

	if (nbytes == 0)
		return NULL;


	/* size of one block in terms of headers + 1*/
	nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1; 	

	/* if no free list yet, set pointers to base */
	if ((prevp = freep) == NULL) {	
		base.s.ptr = freep = prevp = &base;
		base.s.size = 0;
	}

	/* for each block in the list */
	for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {

		/* if block is big enough, use it*/
		if (p->s.size >= nunits) {	
			
			/* if size of block to be used is equal to requested */
			if (p->s.size == nunits)	

				/* unlink block from list */
				prevp->s.ptr = p->s.ptr;
			else {			
				/* else, truncate the block from left to create a new block */
				p->s.size -= nunits;

				/* get the address of the new block */
				p += p->s.size;
			}
			/* set the beginning of the list to the old block */	
			freep = prevp;

			/* return address of new block to user, excluding the header */
			return (void *)(p+1);
		}

		/* if we went around and found no big-enough block, ask system for more */
		if (p == freep)	 {
			/* if system cannot provide any, return NULL */
			if ((p = morecore(nunits)) == NULL)
				return NULL;
		}
	}
}

#define NALLOC 1024	/* minimum #units to request */

/* morecore: ask system for more memory , declared static because of freep */
Header *morecore(unsigned nu)
{
	char *cp;  /* buffer before the memory is casted properly */
	char *sbrk(int); /* the syscall */
	Header *up; /* buffer after the memory is casted properly */

	/* round up requested space to minimum */
	if (nu < NALLOC)
		nu = NALLOC;

	/* ask for nu Headers from system */
	cp = sbrk(nu * sizeof(Header));

	/* if system cannot provide any, return NULL */
	if (cp == (char *) -1)	
		return NULL;

	/* cast! */
	up = (Header *) cp;
	up->s.size = nu;

	/* store block to the free list, +1 to exclude the header */
	void my_free(void *);
	my_free((void *)(up+1));
	return freep;
}

/* free: put block ap in free list */
void my_free(void *ap)
{
	
	Header *p;  /*  blocks inside the list */
	Header *bp;  /* the thing we need to insert */

	/* point to block header */
	if (ap == NULL || (bp = (Header *)ap - 1)->s.size < 1)
		return;

	/* for all p wherein bp is not between p and p->s.ptr */
	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
		/* if p is the last block */
		if (p >= p->s.ptr 
			/* and bp is either after the last block or before the first block */
			&& (bp > p || bp < p->s.ptr))
			/* stop at p */
			break;


	/* if bp is exactly at the left side of a next-block */
	if (bp + bp->s.size == p->s.ptr) { 
		/* merge them */
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	} else /* else just let bp point to it */
		bp->s.ptr = p->s.ptr;
	/* if bp is exactly at the right side of a block */
	if (p + p->s.size == bp) {	
		/* merge them */
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	} else /* else just let bp be pointed to */
		p->s.ptr = bp;

	/* at the end, bp will end up either being part of a block, or just in the middle of two */

	/* set freep to the block before bp */
	freep = p;
}

/* my_calloc: returns a pointer to n objects of size nbytes, with storage initialize to zero */
void *my_calloc(unsigned n, unsigned nbytes)
{
	char *b;
	void *my_malloc(unsigned);
	b = (char *) my_malloc(n * nbytes);

	int i;
	for (i = 0; i < nbytes; i++)
		b[i] = (char) 0;
	return (void *) b;
}

/* bfree: frees any block p of n characters into the free list maintained by malloc and free */
void bfree(char *p, unsigned n)
{
	void my_free(void *);
	Header *b;

	/* if no free list yet, set pointers to base */
	if (freep == NULL) {	
		base.s.ptr = freep = &base;
		base.s.size = 0;
	} 

	if (n > sizeof(Header)) {
		b = (Header *) p;
		b->s.size = (n+sizeof(Header)-1)/sizeof(Header);
		my_free((void *) ++b);
	}
}
