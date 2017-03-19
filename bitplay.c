#include<stdio.h>

/* program for playing with bits */

char dec2bin(int x, char s[]);
unsigned getbits(unsigned x, int p, int n);
int dtoi(char s[]);
int getmyline (char s[], int last);
int power(int x, int y);
unsigned setbits(unsigned x, int p,int n,unsigned y);
unsigned invert(unsigned x, int p,int n);
unsigned rightrot(unsigned x, int n);
unsigned leftrot(unsigned x, int n);
int getmyline2 (char s[], int last); 


int main()
{

	printf("%d\n", leftrot(15, 2));
}

/* returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged */
unsigned invert(unsigned x, int p,int n)
{
	return (x & ((~0 << (p+1)) | ~(~0 << (p+1-n)))) | (~((x >> (p+1-n)) & ~(~0 << n)) & ~(~0 << n)) << (p+1-n);

/* getbits: get n bits to the right starting from position p (p=0 is the right most bit) */
}
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

/* setbits: returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged */
unsigned setbits(unsigned x, int p,int n,unsigned y)
{
	return ((x >> (p+1-n)) & ~(~0 << n)) | (y & (~0 << n));
}

/* dtoi: convert string of decimal digits to its integral value */
int dtoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;

}


/* dec2bin: converts decimal into a string of bits */
char dec2bin(int x, char s[])
{
	
}

/* power: raises x to y, provided y >= 0 */
int power(int x, int y)
{
	if(0 >= y)
		return 1;
	else
		return x * power(x, y - 1);
}



/* getmyline: get input from keyboard then dump result to s[] */
int getmyline (char s[], int last)  
{
        int i, c;

        for (i = 0; (c = getchar()) != EOF && i < (last - 1) && '\n' != c; ++i)
                s[i] = c;   
        if ('\n' == c) {    
                s[i] = c;
                ++i;        
        }
        s[i] = '\0';         
        return i;
}

/* rightrot: returns the value of the integer x rotated
to the right by n positions. */
unsigned rightrot(unsigned x, int n)
{

	int i;
	for(i = 0; (x >> i++) > 0;)
		/* puke blood */;
	return (x >> n) | ((x & ~(~0 << n)) << (--i-n));
	
}

/* leftrot: returns the value of the integer x rotated
to the left by n positions. */
unsigned leftrot(unsigned x, int n)
{
	int i;
	for(i = 0; (x >> i++) > 0;)
		;
	return ((x << n) & ~(~0 << --i)) | (x >> (i-n));
}

/* getmyline: get input from keyboard then dump result to s[] and return the number of characters including '\0' */
int getmyline2 (char s[], int last)  
{
        int i, c;

        for (i = 0; (c = getchar()) != EOF && i < (last - 1); ++i)
                s[i] = c;   
        if ('\n' == c) {    
                s[i] = c;
                ++i;        
        }
        s[i] = '\0';         
        return i;
}
