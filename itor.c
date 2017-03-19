
/* itor: converts decimal d to a string s with radix r, returns pointer to '\0' */
char *itor(int d, int r, char *s)
{
	if (d < 0) {
		*s = '-';
		return itor(-d, r, s + 1);
	} else {
		if (d / r)
			s = itor(d / r, r, s);
		*s = (d % r) + (((d % r) < 10) ? '0' : 'A' - 10);
		s[1] = '\0';
		return s + 1;
	}
}

/*
	formula in conventional math notation:

	Let p be any digit in the target radix.
	Let n be the place of the digit.
	Let v be the value to be converted.
	Let b be the target radix.

	p_n = (v / b^n) mod b

	Note: The code itor(d / r, r, s) simply increments the invisible n in the above formula.
	For example ((v / b) / b) = (v / b^2)
*/


