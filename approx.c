#include <stdio.h>
#include <math.h>
#define DEPTH 0x10	/* approxmate to the nth decimal */


int main()
{
	extern double func(double x);
	double x, y;
	double wall;

	x = 0.269366;
	y = 0.269367;
	for (wall = (y - x) / DEPTH; x <= y; x += wall)
		printf("f(%1.10g) = %g\n", x, func(x));


	printf("f(%g) = %g\n", x, func(x));
	printf("f(%g) = %g\n", y, func(y));
	return 0;
}



/* func: function platter */
double func(double x)
{
	//return pow(x, 3) - 3 * pow(x, 2) - 1 * x + 2;
	//return pow(x, 3) + 3 * pow(x, 2) - 6 * x - 3;
	//return pow(x, 3) - pow(x, 2) - 2 * x + 1;
	//return pow(x, 3) - 0 * pow(x, 2) - 3 * x + 1;
	//return pow(x, 3) - 0 * pow(x, 2) - 7 * x + 7;
	//return pow(x, 4) - pow(x, 3) + 2 * pow(x, 2) - 3 * x - 3;
	//return pow(x, 4) - 2 * pow(x, 3) + 1 * pow(x, 2) + 0 * x - 1;
	//return pow(x, 4) - 4 * pow(x, 3) + 0 * pow(x, 2) - 4 * x + 12;
	//return pow(x, 5) + 9;
	//return -pow(x, 3) + pow(x, 2) - 6 * x - 18;
	//return -pow(x, 3) + 0 * pow(x, 2) + 18 * x - 16;
	//return pow(x, 3) - 2 * pow(x, 2) - 1;
	return 2 * pow(x, 4) - 4 * pow(x, 3) + 2 * pow(x, 2) - 4 * x + 1;
}

/* fence: checks if a <= 0 < b or a >= 0 > b, if the two numbers are on the same side */
int cross(double a, double b)
{
	return (a == 0 || (a * b) < 0);

	
}
