#include<stdio.h>

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;		/* stack index */
double val[MAXVAL];	/* the stack itself */

/* push: push f onto value stack */
void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("push: stack is full, can't push %g\n", f);

}

/* pop: pop and return the top value from  stack */
double pop(void)
{

	if(sp >= 0)
		return val[--sp];
	else{
		printf("pop: stack empty\n");
		return 0.0;
	}
}


double peak(int i)
{
	if(0 <= i && i <= sp)
		return val[i];
	else
		printf("peak: invalid stack index\n");
}
/* clear: clears stack */
void clear(void)
{
	while(0 < sp)
		val[--sp] = '\0';
}

/* swap: swaps the top two elements of the stack */
void swap(void)
{
	double buf;
	if(1 < sp){
		buf = val[sp-2];
		val[sp-2] = val[sp-1];
		val[sp-1] = buf;
	}
	else
		printf("swap: not enough elements in stack \n");
}

/* dup: duplicates the top two elements in a stack */
void dup(void)
{
	if(1 < sp){
		val[sp] = val[-2+sp++];
		val[sp] = val[-2+sp++];
	}else if(0 < sp)
		val[sp] = val[-1+sp++];
	else
		printf("dup: stack empty\n");


}
/* prints the top 2 elements of the stack */
void ptop(void)
{
	if(1 < sp)
		printf("\t%g %g\n",val[sp-2], val[sp-1]);
	else if(0 < sp)
		printf("\t%g\n",val[sp-1]);
	else
		printf("ptop: stack empty\n");

}
/* prints the top  element of the stack */
void printop(void)
{
	if(0 < sp)
		printf("\t%g\n",val[sp-1]);
	else
		printf("printop: stack empty\n");

}

void pstack(void)
{
	int i = sp;
	while(--i >= 0)
		printf("--> %g\n",val[i]);
}
