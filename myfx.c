/* this is a collection of all the functions I've written, there are currently 58 of them */


/*----------------HEADERS----------------*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<float.h>
#include<limits.h>

/*----------------MAGIC NUMBERS----------------*/
#define STOP EOF
#define MAXLINE 10
#define MAX 1000   /* max char input */     
#define OUT 0      /* outside a comment */
#define IN 1       /* inside a comment */
#define STALE -1   /* almost outside a comment */       

#define STEP 10 /* gap between each temperature*/
#define LOWER 0        /* lowerbound of temp*/ 
#define UPPER 300 /* upperbound of temp*/
#define MAXCHARS 1000  


/*----------------FUNCTION PROTOTYPES ----------------*/
int cels (int fahr); /* function prototype*/
int fahr (int cels);
int getlinez (char s[], int last); 
int bitcount(unsigned x);
int bitcount2(unsigned x);
void escape(char s[], char t[]);
void shellsort(int v[], int n);
void imprison(char t[], char s[]);
void shellsort2(int v[], int n);
int isthere(char s[], int n, char t[], int m);
int isa2z(char s[], int start);
int isA2Z(char s[], int start);
int is0to9(char s[], int start);
void mysqueeze(char s[], char t[]);
int mystrcat(char s[], char t[], int n);
int any(char s1[], char s2[]);
void a2z(char s[], int n);
void A2Z(char s[], int n);
void decs(char s[], int n);
void expand(char s1[], char s2[]);
int htoi(char s[]);
void myreverse(char s[]);
void myreverse2(char s[]);
void myreverse3(char s[]);
void itoa(unsigned n, char s[], int sign);
void itob(int n, char s[], int b);
void itoa2(int n, char s[], int w);
int last(char s[]);
int query(void);
int query2(void);
int iubd(int coefficients[], int terms); 	/* integral upper bound */
int ilbd(int coefficients[], int terms); 	/* integral lower bound */
double f(int coefficients[], int terms, double x); 	/* f(x) */
double ef(double x, int ar[], int n); /* same as f(x) except that it uses
 recursion*/
int getint(char str[], int max);
int getint2(char str[], int max);
int readint(void);
int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);
void lower(char s[]);
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
int mygetline(unsigned char string[], unsigned long lim);
long mod(long dividend, long divisor);	/* returns the remainder of a quotient */
int getlines(char s[], long last);  /* stores input to array */
int getline2(char s[], int last); /* gets input from keyboard then dumps result to specified array */
void copy (char to[], char from[]);   /* copies content of one char array to another */
int detab(char para[], long last, int y);   /* turns tabs into spaces */
void reverse(char s[]);


/*----------------THE FUNCTIONS THEMSELVES----------------*/


void reverse2(char s[])     /* reverses the character string */
{
        int i, j;
        i = 0;

        while ('\0' != s[i]) /* find the null character */
                i++;

        char temp[i];         /* i is the number of elements in s[] */
        for (j = 0; j < i - 1; ++j)
                temp[j] = s[(i - 2 ) - j ];          /* staring from the second to the last character of s[] (excluding '\0' of course), plug its values to temp[] */

        temp[i - 1] = '\0';                         /* end string with null character*/
        for (i =  0; i <= j; ++i)
                s[i] = temp[i];                   /* plug the elements from buffer to the original array */

}

int detab(char para[], long last, int y)  /* y is the number of spaces in a tab */
{
        int i, x, z, r;
        char buffer[last]; /* buffer array */

        r = z = 0;           /* array index */
        x = -1;         /* first char per line starts at 0 */

        /* while there is a character and before
           we reach the end of the array */
        while(z < getlines(para, last)){          


                /* keep counting the number of characters */
                ++x;


                /* if para[r] is just a normal character,
                   then plug its value in the buffer array */
                if('\t' != para[r] && '\n' != para[r])      
                      buffer[z] = para[r];             


                /* if we hit a newline, refresh the tab count */
                else if('\t' != para[r]){             
                        buffer[z] = para[r];             
                        x = -1;                  

                }

               /* if we hit a tab */
                else {

                        /* replace tab with spaces */
                        i = 0;
                        while(i < ((((x / y) + 1) * y) - x)){
                                buffer[z++] = ' ';                           
                                i++;
                        }


                        /* while keeping track of our char count */
                        x = x - 1 + ((((x / y) + 1) * y) - x);         
                        z--;
                }

               z++;
               r++;
        }

        /* the null character will mark the end of our string */
        buffer[z] = '\0';

        /* replace array with buffer content */
         copy(para, buffer);

        /* this function returns the number of chars in the array */
        return --z;
}

int getlines(char s[], long last)  /* one */
{   
        int c;
        long i;

        i = 0;

         /* while there is an input
            store the char in the array */
        while (EOF != (c = getchar()) && i < (last - 1))      
                s[i++] = c;   

        /* save the last spot for the null char */
        s[i++] = '\0';

        return i;
}



int getline2(char s[], int last) /* first */
{
        int i, c;

        for (i = 0; (c = getchar()) != EOF && i < (last - 1) && '\n' != c; ++i)       /* for each character that is not null and is at least 2 places away from the limit */
                s[i] = c;   /* dump the character to an array*/
        if ('\n' == c) {    /* when newline is encountered*/
                s[i] = c;
                ++i;        /* save that last spot*/
        }
        s[i] = '\0';         /* for the null character */
        return i;
}

void copy (char to[], char from[])  
{
        int i;
        i = 0;
        while('\0' != (to[i] = from[i])) 
                ++i;        
}


int cels(int fahr)
{
        int c;
        c = 5*(fahr - 32) / 9;
        return c;
}        

int fahr(int cels)
{
        int f;
        f = ((cels*9)/5) + 32;
        return f;
}        

long mod(long x, long y)	/* returns the remainder of x/y */
{
	long buf;
	if(x < y || 0 == y) return 0;
	else{
		buf = x/y;
		return x - (buf * y);
	}
}

int mygetline(unsigned char string[], unsigned long lim) /* one */
{

	unsigned long i = 0; 
	int c = 0;
	while(i < lim-1){
		string[i] = (c=getchar());
		if(EOF == c){		
			string[i] = '\0'; 
			return 0;	/* multiple exit points*/
		}
		else if('\n' == c){
			string[i] = '\0'; 
			return 0;	/* multiple exit points*/
		}
		i++;
	}
	string[i] = '\0';
	return 1;	/* tells when string[] is full */
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
int dtoi(char s[]) /* 1 */
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
int getmyline (char s[], int last)  /* 1 */
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
void lower(char s[])
{
	int i;
	for(i = 0; '\0' != s[i]; i++)
		s[i] += 'A' <= s[i] && 'Z' >= s[i] ? 'a' - 'A': 0;

}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch2(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low < high) {
		mid = (low+high)/2;
		if (x <= v[mid])
			high = mid;
		else 
			low = mid + 1;
	}

	if(x == v[low])		
		return low;
	else
		return -1;

}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		printf("%d %d %d\n", low,  mid, high);
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			/* found match */
		return mid;

	}
	return -1;
	/* no match */
}



/* readint: reads 5-digit integers */
int readint(void)
{

	int j, max;
	max = 5;
	char str[max];

	for(j = 0; j < max; j++)
		str[j] = '\0';
	getmyline(str, max);
	if('-' == str[0]){
		char str2[max];
		for(j = 1; '\0' != str[j]; j++)
			str2[j-1] = str[j];	
		str2[j] = '\0';
		return -dtoi(str2);
	} else
		return dtoi(str);

}
/* iubd: finds integral upperbound of the roots of a polynomial in the form a_0x^n + a_1x^n-1 + a_2x^n-2...a_n-2x^2 + a_n-1x + a_n */
int iubd(int ar[], int n) 

{
	int a, found;
	int ar2[n], c;

	found = c = 0;
	while(0 == found){
		
		for(a = 0; a < n; ++a){
			if(0 < a)
				ar2[a] = ar[a] + (ar2[a-1] * c);
			else ar2[0] = ar[0];
		}
		found = 1;
		for(a = 0; a < n; ++a){
			if(0 > ar2[a]) found = 0;
		}
		
		c = c + 1;
	}

	return --c;
}
/* ilbd: finds integral lowerbound of the roots of a polynomial in the form a_0x^n + a_1x^n-1 + a_2x^n-2...a_n-2x^2 + a_n-1x + a_n */
int ilbd(int ar[], int n) 

{
	int a, found;
	int ar2[n], c;

	found = c = 0;
	if(1 == n) return 0;
	else{
		while(0 == found){
			for(a = 0; a < n; ++a){
				if(0 < a)
					ar2[a] = ar[a] + (ar2[a-1]*c);
				else ar2[0] = ar[0];
			}
			found = 1;
			for(a = 1; a < n; ++a){
				if(0 <= (ar2[a] * ar2[a - 1])) found = 0;
			}
			
			c = c - 1;
		}
		return ++c;
	}
}

/* f: returns f(x) using the remainder theorem */
double f(int ar[], int n, double c) 
{

	int a;
	double ar2[n];
	for(a = 0; a < n; ++a){
		if(0 < a)
			ar2[a] = ar[a] + (ar2[a-1] * c);
		else ar2[0] = ar[0];
	}
	return ar2[n - 1];
}
/* ef: recursive function evaluation of a polynomial */
double ef(double x, int ar[], int n) 
{
	if(0 < n) return ((x + ar[n]) * ef(x, &ar[0], n - 1));
	else return ar[0];

}



/* getint: retrieves an integer from keyboard input */
int getint(char str[], int max) 
{
	int j;
	for(j = 0; j < max; j++)
		str[j] = '\0';
	getmyline(str, max);
	if('-' == str[0]){
		char str2[max];
		for(j = 1; '\0' != str[j]; j++)
			str2[j-1] = str[j];	
		str2[j] = '\0';
		return -dtoi(str2);
	} else
		return dtoi(str);
}

/* query2: asks for user input, y/n */
int query2(void)
{
	char s[2];
	getmyline(s, 2);
	if('y' == s[0] || 'Y' == s[0])
		return 1;
	else
		return 0;
}




/* expand: expands shorthand notations like a-z and 0-9 */
void expand(char s1[], char s2[])
{

	int i, j;
/*	i = j = 0;
	while('\0' != s1[i]){
		if(i > 0 && '-' == s1[i]){
			if((i > 1 && '-' == s1[i-2]) || '-' == s1[i+2])
			goto next; 
			switch(shorts(s1, i)){
				case 1:
					a2z(s2, j-1), j += 24, i++;
					break;
				case 2:
					A2Z(s2, j-1), j += 24, i++;
					break;
				case 3:
					decs(s2, j-1), j += 8, i++;
					break;
				default:
					s2[j] = s1[i];
					break;
			}
		}else
next:
			s2[j] = s1[i];
		j++, i++;
	} 
*/

	for(i = j = 0; '\0' != s1[i]; i++, j++){
		if(i > 0 && '-' == s1[i]){
			if((i > 1 && '-' == s1[i-2]) || '-' == s1[i+2])
				s2[j] = s1[i];
			else{
				switch(shorts(s1, i)){
					case 1: 
						a2z(s2, j-1), j += 24, i++;
						break;
					case 2:	
						A2Z(s2, j-1), j += 24, i++;
						break;
					case 3:	
						decs(s2, j-1), j += 8, i++;
						break;
					default: 
						s2[j] = s1[i];
						break;
				}	
			}	
		}else
			s2[j] = s1[i];
	}
	s2[j] = '\0';

}

/* finds out which of the shorthand notations a-z, A-Z, or 0-9 does a 3-character string belongs to, it assumes that s[i] = '-')*/
int shorts(char s[], int i)
{
	if('a' == s[i-1] && 'z' == s[i+1])
		return 1;
	else if('A' == s[i-1] && 'Z' == s[i+1])
		return 2;
	else if('0' == s[i-1] && '9' == s[i+1])
		return 3;
	else
		return 0;
}

/* writes 0, 1,...,9 to s[] starting from index n*/
void decs(char s[], int n)
{
	int i;
	i = 0;
	while(i <= 9)
		s[n++] = '0' + i++;

}
/* writes a, b,...,z to s[] starting from index n*/
void a2z(char s[], int n)
{
	int i;
	i = 0;
	while(i < 26)
		s[n++] = 'a' + i++;

}
/* writes A, B,...,Z to s[] starting from index n*/
void A2Z(char s[], int n)
{
	int i;
	i = 0;
	while(i < 26)
		s[n++] = 'A' + i++;

}
/* concatenates t[] to s[] */
int mystrcat(char s[], char t[], int i)
{
	int j;
	j = 0;
	while('\0' != s[i])
		i++;
	while('\0' != (s[i++] = t[j++]))
		 ;
	return --i;
	
}
/* delete all characters from s[] that is also in t[] */
void mysqueeze(char s[], char t[])
{

	int i, j, k, skip;
	for(i = j = skip = 0;'\0' != s[i]; i++){
		for(k = 0; '\0' != t[k]; k++)
			if(s[i] == t[k])
				skip = 1;
			
		if(0 == skip)
			s[j++] = s[i];
		else
			skip = 0;
	}
	s[j] = '\0';
}



/* returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
 */
int any(char s1[], char s2[])
{
	int i, j;
	for(i = 0; '\0' != s2[i]; i++)
		for(j = 0; '\0' != s1[j]; j++)
			if(s1[j] == s2[i])
				return j;
	return -1;


}
/* checks if s[start] is "A-z" */
int isA2Z(char s[], int start)
{
	char word[4];
	word[0]= 'A';
	word[1] = '-';
	word[2] = 'Z';
	word[3] = '\0';
	if(isthere(s, start, word, 3))
		return 1;
	else
		return 0;
}

/* checks if s[start] is "a-z" */
int isa2z(char s[], int start)
{
	char word[4];
	word[0]= 'a';
	word[1] = '-';
	word[2] = 'z';
	word[3] = '\0';
	if(isthere(s, start, word, 3))
		return 1;
	else
		return 0;
}
/* checks whether the word in t is found in s starting at index n. m is the number of characters in the word excluding the terminating null character */
int isthere(char s[], int n, char t[], int m)
{
	int i, found;
	i = found = 0;
	while('\0' != t[i]){
		if(s[n] == t[i])
			found++;
		i++;
		n++;
	}

	if(found == m)
		return 1;
	else
		return 0;
}

/* does th esame as shellsort but without excess for loops */
void shellsort2(int v[], int n)
{
	int i, j, temp, gap;
	for(gap = n/2; gap > 0; gap /= 2)
		for(i = gap; i < n; i++)
			if(v[i-gap] > v[i]){
				temp = v[i];
				v[i] = v[i-gap];
				v[i-gap] = temp;
			}

}
/* shellsort: sorts an array using shellsort algorithm */
void shellsort(int v[], int n)
{
	int i, j, gap, temp;
	for(gap = n/2; gap > 0; gap /= 2)
		for(i = gap; i < n; i++)
			for(j = i-gap; j >=0 && v[j] > v[j+gap]; j -= gap){
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}

/* imprison: does the inverse of escape(), octal and hex digits excluded */
void imprison(char t[], char s[])
{
	int i, j;
	i = j = 0;
	while('\0' != s[i]){
		if('\\' == s[i]){
			switch(s[i+1]){
				case 'n':
					t[j] = '\n';
					i++;
					break;
				case 't':
					t[j] = '\t';
					i++;
					break;
				case 'a':
					t[j] = '\a';
					i++;
					break;
				case 'b':
					t[j] = '\b';
					i++;
					break;

				case 'f':
					t[j] = '\f';
					i++;
					break;
				case 'r':
					t[j] = '\r';
					i++;
					break;
				case 'v':
					t[j] = '\v';
					i++;
					break;
				case '\\':
					t[j] = '\\';
					i++;
					break;
				case '?':
					t[j] = '\?';
					i++;
					break;
				case '\'':
					t[j] = '\'';
					i++;
					break;
				case '\"':
					t[j] = '\"';
					i++;
					break;

				default:
					t[j] = s[i];
					break;
			}
		}else
			t[j] = s[i];
		i++;
		j++;
	}
	t[j] = '\0';
}
/* escape: changes a character like newline into \n */
void escape(char s[], char t[])
{

	int i, j;
	i = j = 0;
	while('\0' != t[i]){
		switch(t[i]){
			case '\t':
				s[j++] = '\\';
				s[j] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				s[j] = 'n';
				break;
			case '\a':
				s[j++] = '\\';
				s[j] = 'a';
				break;
			case '\b':
				s[j++] = '\\';
				s[j] = 'b';
				break;
			case '\f':
				s[j++] = '\\';
				s[j] = 'f';
				break;
			case '\r':
				s[j++] = '\\';
				s[j] = 'r';
				break;
			case '\v':
				s[j++] = '\\';
				s[j] = 'v';
				break;
			case '\\':
				s[j++] = '\\';
				s[j] = '\\';
				break;

			case '\?':
				s[j++] = '\\';
				s[j] = '?';
				break;
			case '\'':
				s[j++] = '\\';
				s[j] = '\'';
				break;
			case '\"':
				s[j++] = '\\';
				s[j] = '\"';
				break;
			default: 
				s[j] = t[i];
				break;
		}
		i++;
		j++;
	}
	s[j] = '\0';

}
int query(void)
{
	int c;
	if((c = getchar()) == 'y' || 'Y' == c)
		return 1;
	else
		return 0;
}

/*bitcount2 counts the number of 1 bits */
int bitcount2(unsigned x)
{
	int b;
	b = 0;
	while(x != 0)
		if(x % 2){
			x &= (x-1);
			b++;
		} else
			x >>= 1;
	return b;
}

/*bitcount: counts the number of 1 bits */
int bitcount(unsigned x)
{
	int b;
	for(b = 0; x != 0; x >>= 1)
		if(x & 01)
			b++;
	return b;
}

/*getlinez: what getline does, only slower*/
int getlinez (char s[], int last)  
{
        int i, c;

        for (i = 0; (c = getchar()) != STOP && i < (last - 1) && '\n' != c; ++i)       /* for each character that is not null and is at least 2 places away from the limit */
                s[i] = c;   /* dump the character to an array*/
        if ('\n' == c) {    /* when newline is encountered*/
                s[i] = c;
                ++i;        /* save that last spot*/
        }
        s[i] = '\0';         /* for the null character */
        return i;
}



/* converts a number into a string of digits with trailing spaces */
void itoa2(int n, char s[], int w)
{
	int i, sign;
	i = 0;
	if((sign = n) < 0)
		n = -n;
	
	do{
		if(n > 0)
			s[i++] = (n % 10) + '0';
		else
			s[i++] = ' ';
		n /= 10;	
	}while( i < w);
	s[i] = '\0';

	if(sign < 0)
		s[last(s)] = '-';
	 reverse(s);

}

/* returns the position of the last non-blank character in a string */
int last(char s[])
{

	int i;
	i = strlen(s) - 1;
	while(i > 0 && ' ' == s[i])
		i--;
	return i+1;
}


/* converts an integer to a string of digits of base b */
void itob(int n, char s[], int b)
{
	int i, sign, dig;
	i = 0;
	if((sign = n) < 0)
		n = -n;
	do{
		dig = n % b;
		if(dig > 9)
			s[i++] = dig-10 + 'A';
		else
			s[i++] = (n % b) + '0';
	}while((n /= b) > 0);

	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* reverses strings */
void reverse(char s[])
{
	int c, i, j;
	for(i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;

}


/* converts a large integer to a string */
void itoa(unsigned n, char s[], int sign)
{
	int i;
	i = 0;
	do{
		s[i++] = (n % 10) + '0';
	}while((n /= 10) > 0);
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);

}
/* reverses a string */
void myreverse3(char s[])
{
	int i, max;
	char buf;
	max = strlen(s);
	for(i = 0; i < max/2; i++)
		buf = s[i], s[i] = s[max - 1 - i], s[max - 1 - i] = buf;
	s[max] = '\0';
}

/* convert string of hexadecimal digits to its integral value */
int htoi(char s[])
{
	int i, n;
	n = 0;
	i = -1;

	while('\0' != s[++i]){

		/* ignore the 0x or 0X prefix */
		if('0' == s[i] && ('x' == s[i+1] || 'X' == s[i+1]))
			++i;

		else if(s[i] >= 'a' && s[i] <= 'f')
			n = 16 * n + (s[i] - 'a' + 10);
		else if(s[i] >= 'A' && s[i] <= 'F')
			n = 16 * n + (s[i] - 'A' + 10);
		else if(s[i] >= '0' && s[i] <= '9')
			n = 16 * n + (s[i] - '0');

		/* stop reading if invalid character is encountered*/
		else
			return n;
		
	}
	return n;
}




/* getint: retrieves a long integer from keyboard input */
int getint2(char str[], int max)
{
	int j;
	for(j = 0; j < max; j++)
		str[j] = '\0';
	getmyline(str, max);
	return dtoi(str);
}


