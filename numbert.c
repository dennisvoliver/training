#include<stdio.h>
#include<string.h>

/* this program plays with number conversions */


int htoi(char s[]);
int dtoi(char s[]);
int getmyline (char s[], int last);
void myreverse(char s[]);
void itoa(unsigned n, char s[], int sign);
void reverse(char s[]);
void itob(int n, char s[], int b);
void itoa2(int n, char s[], int w);
int last(char s[]);

int main()
{
	char s[10], t[10], u[10], v[10];

	/* scan 9 digits then print*/
	getmyline(s, 10);
/*	printf("dtoi:\t%d\nhtoi:\t%d\natoi:\t%d\n", dtoi(s), htoi(s), atoi(s));
*/
	itoa(atoi(s), t, -1);
	itob(atoi(s), u, 16);
	itoa2(atoi(s), v, 10);

	printf("itoa:\t%s\nitob:\t%s\nitoa2:\t%s\n", t, u, v);


	return 0;
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

/* reverses stringe */
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
void myreverse(char s[])
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

/* convert string of decimal digits to its integral value */
int dtoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;

}


/* get input from keyboard then dump result to s[] */
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
