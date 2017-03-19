#include<stdlib.h>
#include<string.h>

/* numcmp: compares num1 and num2 numerically, returns - 1 if num1 < num2, 1 if num2 < num1, and 0 if num1 = num2 */
int numcmp(char *num1, char *num2)
{
	double v1, v2;
	v1 = atof(num1);
	v2 = atof(num2);

	if(v1 < v2)
		return -1;
	else if (v2 < v1)
		return 1;
	else	
		return 0;

}
/* numncmp: same as numcmp but only compares the first n characters */
int numncmp(char *num1, char *num2, int n)
{
	double v1, v2;
	char buf[n];
	strncpy(buf, num1, n);
	v1 = atof(buf);

	strncpy(buf, num2, n);
	v2 = atof(buf);

	if(v1 < v2)
		return -1;
	else if (v2 < v1)
		return 1;
	else	
		return 0;

}

/* numncmpr: reverse of numncmp */
int numncmpr(char *num1, char *num2, int n)
{
	double v1, v2;
	char buf[n];
	strncpy(buf, num1, n);
	v1 = atof(buf);

	strncpy(buf, num2, n);
	v2 = atof(buf);

	if(v1 > v2)
		return -1;
	else if (v2 > v1)
		return 1;
	else	
		return 0;

}
