#include<ctype.h>
#include<math.h>
#include<stdio.h>

/* myatof: converts a string of decimal digits to a floating point number */
double myatof(char *s)
{

	double val, power = 1.0; 
	int i, sign;
	for(i = 0; isspace(s[i]); i++)	/* skip spaces */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if('+' == s[i] || '-' == s[i])	/* skip signs */
		i++;
	for(val = 0.0; isdigit(s[i]); i++)	/* record integer part */
		val = (10.0 * val) + (s[i] - '0');
	if('.' == s[i]){	/* if decimal point is encountered */
		i++;
		for(power = 1.0; isdigit(s[i]); i++){	/* record fractional part */
			val = (10.0 * val) + (s[i] - '0');
			power *= 10.0;
		}
	
		if('e' == s[i] || 'E' == s[i]){	/* if scientific notation is encountered */
			i++;
			double exp;
			int e = -1;
			if('-' == s[i]){	/* if exponent is negative */
				i++;
				e = 1;
			}
			for(exp = 0.0; isdigit(s[i]); i++)
				exp = (10.0 * exp) + (s[i] - '0');
			power = pow(power, e * exp);
		}
	}

	return (sign*val)/power;
}

