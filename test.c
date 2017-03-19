        /*      testing functions      */
#include<stdio.h>
#include<string.h>
#define STOP EOF
#define MAXLINE 10
int getlinez (char s[], int last); 
int bitcount(unsigned x);
int bitcount2(unsigned x);
int query(void);
int readint(void);
void escape(char s[], char t[]);
void shellsort(int v[], int n);
void imprison(char t[], char s[]);
void shellsort2(int v[], int n);
void a2z(char s[], int n);
void A2Z(char s[], int n);
int isthere(char s[], int n, char t[], int m);
int isa2z(char s[], int start);
int isA2Z(char s[], int start);
int is0-9(char s[], int start);

int main()        
{
/*
	int v[10], i;
	for(i = 9; i >= 0; i--)
		v[i] = i;
	shellsort2(v, 10);
	for(i = 0; i < 10; i++)
		printf("%d\n", v[i]);


	char s[10], t[10];
	s[0] = 'h';
	s[1] = 'e';
	s[2] = 'l';
	s[3] = 'l';
	s[4] = 'o';
	s[5] = '\\';
	s[6] = 'n';
	s[7] = '\0';

	imprison(t, s);
	printf("%s\n", t);

	char s[27];
	A2Z(s, 0);
	s[26] = '\0';
	printf("%s\n", s);
*/

/*
	char s[4], t[3];
	s[0] = '0';
	s[1] = '-';
	s[2] = '9';
	s[3] = '\0';
	t[0] = 'a';
	t[1] = 'a';
	t[2] = '\0';
	printf("%d\n", isa2z(s,0));
*/

	int getch(void);
	void ungetch(int c);
	char s[] = "hello\0";
	printf("%d\n", strlen(s));

}


/* checks if s[start] is "0-9" */
int is0-9(char s[], int start)
{
	char word[4];
	word[0]= '0';
	word[1] = '-';
	word[2] = '9';
	word[3] = '\0';
	if(isthere(s, start, word, 3))
		return 1;
	else
		return 0;
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



