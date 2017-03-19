#include<stdio.h>

void mysqueeze(char s[], char t[]);
int getmyline (char s[], int last);
int mystrcat(char s[], char t[], int n);
int any(char s1[], char s2[]);
void a2z(char s[], int n);
void A2Z(char s[], int n);
void decs(char s[], int n);
void expand(char s1[], char s2[]);


/* program that plays with strings */

int main()
{
	char s[100];
	char t[100];
	
	/* fetch  strings */
	getmyline(s, 99);

	/* expand a-z strings */
	expand(s, t);

	printf("%s\n", t);

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

/* get input from keyboard then dump result to s[] and return the number of characters including '\0' */
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
