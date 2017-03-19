#include<ctype.h>

/* unicmp: 
	universal comparison; 
	returns -1, 0 or 1 if s<t, s=st or s>t;
	f = fold;
	d = directory;
	n = numeric;
*/
	
int unicmp(char *s, char *t, int f, int d, int n)
{
	char char1 = *s, char2 = *t;
	
	if(0 < n){
		double v1, v2;
		v1 = atof(s);
		v2 = atof(t);

		if(v1 < v2)
			return -1;
		else if (v2 < v1)
			return 1;
		else	
			return 0;
	}

	if(0 < f){
		char1 = (isupper(char1)) ? tolower(char1): char1;
		char2 = (isupper(char2)) ? tolower(char2): char2;

	}

	if(0 < d){
		return (char1 == char2 && char2 != '\0' &&
			(isalnum(char1) || isblank(char1)) &&
			(isalnum(char2) || isblank(char2))) ? 
			unicmp(s + 1, t + 1, f, d, n): 
			(char1 - char2);
	}

	return (char1 == char2 && char2 != '\0') ? unicmp(s + 1, t + 1, f, d, n) : (char1 - char2);
}
