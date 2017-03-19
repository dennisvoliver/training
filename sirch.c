#include<stdio.h>

/* program that plays with string searches */
int main()
{


}

/* checks if s[start] is "0-9" */
int is09(char s[], int start)
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
