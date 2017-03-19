#include "test.h"
#include<math.h>
#include "debug.h"

extern int gpow(int a, int b);
extern int gmul(int a, int b);
extern int part(int v, int b);
extern int partits(int v, int b);
extern int gfac(int a, int b);
extern int gexp(int a, int b);
extern int fdig(int v, int b);
extern int btoa(int v, int b, char *s);
extern int maxdig(int b, int n);
extern int maxdig2(int b, int x, int y);

int main()
{

/*
	int v = 16;
	int b = 8;
	char s[MAXLEN];
	btoa(v, b, s);
	printf("%s\n", s);
*/
	/* for any b, x, and y > 0 */
	int n, b, x, y;
	x = 3;
	y = 2;
	b = 2;
	n = x * y;

	printf("%s\n", maxdig(b, n) == maxdig2(b, x, y) ? "PROVEN": "DISPROVEN");

}

/* maxdig: returns (b-1)(b^0) + (b-1)(b^1) +...+ (b-1)(b^xy) */
int maxdig2(int b, int x, int y)
{
	return x > 0 ? (pow(b, y) - 1) * pow(b, y * (x - 1)) + maxdig2(b, x - 1, y): 0;
}

/* maxdig: returns (b-1)(b^0) + (b-1)(b^1) +...+ (b-1)(b^n) */
int maxdig(int b, int n)
{
	return n > 0 ? (b - 1) * pow(b, n - 1) + maxdig(b, n - 1) : 0;
}

int btoa(int v, int b, char *s)
{
	if (0 < v) {
		*s = fdig(v, b) + '0';
		return btoa(v - part(v, b), b, s + 1);
	}
	return *s = '\0';
}

/* fdig: returns the first digit of v in base b */
int fdig(int v, int b)
{
	return gfac(v, gpow(v, b));
}

/* partits: tests if the sum of all partitions is equal to the input value */
int partits(int v, int b)
{
	int nextv = v - part(v, b);
	if (nextv > 0)
		return v + partits(nextv, b);
	return 0;
}

/* part: returns the greatest partition of v that is a multple of b */
int part(int v, int b)
{
	return gmul(v, gpow(v, b));
}

/* gfac: returns the greatest factor of a that is less than a and that is a multple of b */
int gfac(int a, int b)
{
	if (a < b)
		return a;
	return gmul_1(a, b, 1);
}

/* gmul: returns the greatest multiple of b that is less than a */
int gmul(int a, int b)
{
	if (a < b)
		return a;
	return b * gmul_1(a, b, 1);
}

int gmul_1(int a, int b, int c)
{
	if (a < (b * c))
		return c - 1;
	return gmul_1(a, b, c + 1);
}

/* gexp: returns the largest n such that a < b^n */
int gexp(int a, int b)
{
	return gpow_1(a, b, 0);
}

/* gpow: returns the greatest power of b that is less than a */
int gpow(int a, int b)
{
	if (a < b)
		return a;
	return pow(b, gpow_1(a, b, 0));
}

int gpow_1(int a, int b, int c)
{
	if (a < pow(b, c))
		return c - 1;
	return gpow_1(a, b, c + 1);
}
