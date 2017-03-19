#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* characteristic equations of third-order matrices */
int main()
{
	double det(int m[3][3]);
	double det2(int m[3][3], int x);
	double func(int x);
	int x = 100;

/*
	int m[3][3] = {
	{ 2 - x, -1    , 3    },
	{ 1    , -2 - x, 0    },
	{ 3    ,  1    , 1 - x},
	};

	int n[3][3] = {
	{ 2, -1, 3},
	{ 1, -2, 0},
	{ 3,  1, 1},
	};
*/
	int m[3][3] = {
	{ 1 - x,  2    , -3    },
	{ 0    , -2 - x,  4    },
	{ 1    , -3    ,  1 - x},
	};

	int n[3][3] = {
	{ 1,  2, -3},
	{ 0, -2,  4},
	{ 1, -3,  1},
	};

	printf("%g\n%g\n%g\n", det(m), det2(n, x), func(x));
	return 0;
}

double func(int x)
{
//	return -pow(x, 3) + pow(x, 2) - 6 * x - 18;
	return -pow(x, 3) + 0 * pow(x, 2) + 18 * x - 16;
}

double det2(int n[3][3], int x)
{
	return  -pow(x, 3) 
		+ (n[0][0] + n[1][1] + n[2][2]) * pow(x, 2) 
		- (n[0][0] * n[1][1] 
			+ n[0][0] * n[2][2] + n[1][1] * n[2][2] 
			+ n[2][0] * n[0][2] - n[1][0] * n[0][1]
			+ n[2][1] * n[1][2]) * x 
		+ (n[0][0] * n[1][1] * n[2][2] 
			+ n[0][0] * n[2][1] * n[1][2] + n[1][0] * n[2][1] * n[0][2] 
			+ n[2][0] * n[1][1] * n[0][2] - n[1][0] * n[0][1] * n[2][2] 
			- n[2][0] * n[0][1] * n[1][2]);
}

double det(int m[3][3])
{
	double dmin(int m[3][3], int min);
	return m[0][0] * dmin(m, 0) - m[0][1] * dmin(m, 1) + m[0][2] * dmin(m, 2);
}

double dmin(int m[3][3], int min)
{
	switch(min) {
		case 0:
			return m[1][1] * m[2][2] + m[2][1] * m[1][2];
			break;
		case 1:
			return m[1][0] * m[2][2] + m[2][0] * m[1][2];
			break;
		case 2:
			return m[1][0] * m[2][1] + m[2][0] * m[1][1];
			break;
		default:
			exit(100);
			break;
	}

}

