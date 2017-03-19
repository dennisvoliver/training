#include<ctype.h>

/* readcoefs: reads coefficients */
int readcoefs(double ar[], int max)
{
	int i, j, k, getmyline (char [], int);
	char s[max], t[max];
	double x, atof(char []);
	void clear(char []);

	getmyline(s, max);


	i = j = k = 0;
	while(i < max && '\0' != s[i]){
		while(!isspace(s[i]))
			t[j++] = s[i++];
		t[j] = '\0';
		if('\0' != t[0])
			ar[k++] = atof(t);
		clear(t);
		j = 0;
		i++;
	}
	return k;
}
