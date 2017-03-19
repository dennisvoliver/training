#include <stdio.h>
#include <limits.h>
#include <float.h>

	/* program that displays the ranges of char, short, int, and long
		variables, both signed and unsigned, by printing appropriate values from standard headers
		and by direct computation.
	*/


int main()
{

	/* headers*/

	printf("\n\theaders unsigned\n\tMIN\tMAX\n");
	printf("char\t0\t%u\nshort\t0\t%d\nint\t0\t%u\nlong\t0\t%lu\n", UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX);



	printf("\n\t\t\theaders signed\n\t\tMIN\t\t\tMAX\n");
	printf("char\t%20d\t%20d\nshort\t%20d\t%20d\nint\t%20d\t%20u\nlong\t%20ld\t%20lu\n", SCHAR_MIN, CHAR_MAX, SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, LONG_MIN, LONG_MAX);



	/* computations */

	unsigned char ucharmax;
	unsigned short int ushrtmax;
	unsigned int uintmax;
	unsigned long int ulongmax;
	ucharmax = ushrtmax = uintmax = ulongmax = 0;


	printf("\n\tcomputations unsigned\n\tMIN\tMAX\n");
	printf("char\t0\t%u\nshort\t0\t%d\nint\t0\t%u\nlong\t0\t%lu\n", --ucharmax, --ushrtmax, --uintmax, --ulongmax);

	signed char charmin, charmax;
	signed short int shrtmin, shrtmax;
	signed int intmin, intmax;
	signed long int longmin, longmax;
	charmin = charmax = shrtmin = shrtmax = intmin = intmax = longmin = longmax = 0;


/*
	very long computation 

	while(0 < ++charmin); charmax = charmin - 1; 
	while(0 < ++shrtmin); shrtmax = shrtmin - 1;
	while(0 < ++intmin); intmax = intmin - 1;
	while(0 < ++longmin); longmax = longmin - 1;
*/

	/* practical computation */
	charmax = ucharmax / 2; charmin = charmax - ucharmax;
	shrtmax = ushrtmax / 2; shrtmin = shrtmax - ushrtmax;
	intmax = uintmax / 2; intmin = intmax - uintmax;
	longmax = ulongmax / 2; longmin = longmax - ulongmax;

	printf("\n\t\t\tcomputations signed\n\t\tMIN\t\t\tMAX\n");
	printf("char\t%20d\t%20d\nshort\t%20d\t%20d\nint\t%20d\t%20u\nlong\t%20ld\t%20lu\n", charmin, charmax, shrtmin, shrtmax, intmin, intmax, longmin, longmax);

/*

B.11 Implementation-defined Limits:
<limits.h> and <float.h>
The header <limits.h> defines constants for the sizes of integral types.
The values below are acceptable minimum magnitudes; larger values may be
used.
CHAR_BIT
8
bits in a char
UCHAR_MAX or
CHAR_MAX
maximum value of char
SCHAR_MAX
CHAR_MIN
0 or SCHAR_MIN
maximum value of char
INT_MAX
32767
maximum value of int
INT_MIN
-32767
minimum value of int
LONG_MAX
2147483647
maximum value of long
LONG_MIN
-2147483647
minimum value of long
SCHAR_MAX +127
maximum value of signed char
SCHAR_MIN -127
minimum value of signed char
SHRT_MAX
+32767
maximum value of short
SHRT_MIN
-32767
minimum value of short
UCHAR_MAX 255
maximum value of unsigned char
UINT_MAX
65535
maximum value of unsigned int
ULONG_MAX 4294967295
maximum value of unsigned long
maximum value of unsigned
USHRT_MAX 65535
short




The names in the table below, a subset of <float.h>, are constants related
to floating-point arithmetic. When a value is given, it represents the
minimum magnitude for the corresponding quantity. Each implementation
defines appropriate values.
FLT_RADIX
2
radix of exponent, representation, e.g., 2, 16
FLT_ROUNDS
floating-point rounding mode for addition
FLT_DIG
6
decimal digits of precision
FLT_EPSILON
1E-5
smallest number x such that 1.0+x != 1.0
FLT_MANT_DIG
number of base FLT_RADIX in mantissa
FLT_MAX
1E+37
maximum floating-point number
FLT_MAX_EXP
maximum n such that FLT_RADIXn-1 is representable
FLT_MIN
1E-37
minimum normalized floating-point number
FLT_MIN_EXP
minimum n such that 10n is a normalized number
DBL_DIG
10
decimal digits of precision
DBL_EPSILON
1E-9
smallest number x such that 1.0+x != 1.0
DBL_MANT_DIG
number of base FLT_RADIX in mantissa
214
DBL_MAX
DBL_MAX_EXP
DBL_MIN
DBL_MIN_EXP
1E+37
1E-37
maximum double floating-point number
maximum n such that FLT_RADIXn-1 is representable
minimum normalized double floating-point number
minimum n such that 10n is a normalized number

*/
	
}
