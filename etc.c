#include <stdio.h>
#include <math.h>

void two(void);
void three(void);
void four(void);
void five(void);
void seven(void);
void six(void);
void eight(void);
void nine(void);
void ten(void);
void eleven(void);

int main()
{
	three();
	return 0;
}

/* sin(arcsin(u)+arcos(v)) */
void eleven(void)
{
	double u = 0.3;
	double v = 0.4;
	int n = 0;
	double a, b, b2, c, c2, d, d2;
	double pi = acos(-1);

	for (n = -11; n <= 10; n++) {
		a = pow(-1,n) * asin(u) + n * pi;
		b = acos(v) + 2 * n * pi;
		b2 = -acos(v) + 2 * n * pi;
		c = sin(a + b);
		c2 = sin(a + b2);
		d = u * v - sqrt((1 - pow(u, 2)) * (1 - pow(v, 2)));
		d2 = u * v + sqrt((1 - pow(u, 2)) * (1 - pow(v, 2)));
		printf("(%d)\t%g\t%g | %g\t%g\n", n, c, c2, d, d2);
	}
}

void ten(void)
{

	double x = (1.0 + sqrt(33.0)) / 8.0;
	//double x = 0.0;
	double y = 4 * pow(x, 3) - pow(x, 2) - 2 * x;
	double z = asin(x) + acos(1 - x);
	//printf("%g\n", y);
	printf("%g\n", z);
}

void nine(void)
{
	double x = 0.5;
	double y = 4.0 * pow(x, 2.0) + 2.0 * sqrt(4 * pow(x, 4.0) - 5.0 * pow(x, 2.0) + 1.0) - 1.0;
	double z = 4.0 * pow(x, 2.0) + 2.0 * sqrt(1.0 - pow(x, 2.0)) * sqrt(1.0 - 4.0 * pow(x, 2.0)) - 1.0;
	printf("y = %g\n z = %g\n", y, z);
}

void eight(void)
{
	double x = 0.2;
	printf("%g %g %g\n", cos(asin(x)), sin(acos(x)), sqrt(1.0 - pow(x, 2)));
	

}

void seven(void)
{
	double x = sqrt((3.0 + sqrt(17.0)) / 8.0);
	double pi = acos(-1);
	printf("%g = %g\n", atan(x) + atan(2.0 * x), pi / 6.0);
}

void six(void)
{
	double pi = acos(-1);
	printf("%g\n", tan((3.0 * pi / 4.0) - (2.0 * atan(1.0))));
}

/* Arccos(cos x) */
void five(void)
{
	int n;
	double x = 5.0;
	double y;
	double pi = acos(-1);

	for (n = -11; n <= 10; n++) {
		y = pow(-1, 2 - n) * x + pi * (0.5 + pow(-1, 1 - n) /2 + pow(-1, 1 - n) * n);
		if (0 <= y && y <= pi/2)
			printf("(%d) cos(%g) = %g\n", n, y, cos(y));
	}
	printf("\ncorrect: cos(%g) = %g\n", acos(cos(x)), cos(x));

}

/* prints all arccos(cos x) */
void four(void)
{
	double x = 1.0;
	double y;
	int n;
	double pi = acos(-1.0);
	printf("cos(%g) = %g\n", x, cos(x));
	for (n = -21; n <= 20; n++) {
		y  = (pi * (((1 + pow(-1, n + 1)) / 2) + n)) + x * pow(-1, n);
		printf("(%d) cos(%g) = %g\n", n, y, cos(y));
	}

	printf("\n");

	double d;
	for (n = -11; n <= 10; n++) {
		d =  (2 * n * pi) + x;
		y = (2 * n * pi) - x;
		printf("(%d) cos(%g) = %g & cos(%g) = %g\n", n, d, cos(d), y, cos(y));
	}
}


/* prints all arccos(sin x) */
void three(void)
{
	double x = 8.0;
	double pi = acos(-1);
	int n;
	for (n = -10; n <= 10; n++) {
		printf("(%d) %g\t%g\n", n, 2 * n * pi + (pi * 0.5 - x), 2 * n * pi - (pi * 0.5 - x));
		//printf("(%d) %g\t%g\n", n, pi * (2 * n - 0.5) + x, pi * (2 * n + 0.5) - x);
		//printf("(%d) %g\t%g\n", n, cos(pi * (2 * n - 0.5) + x), cos(pi * (2 * n + 0.5) - x));
	}

	printf("\n");
	for (n = -21; n <= 20; n++){
		printf("(%d) %g\n", n, pi * (n + 0.5) + pow(-1, n + 1) * x);
		//printf("(%d) %g\n", n, cos(pi * (n + 0.5) + pow(-1, n + 1) * x));
	}

}

/* [(-1) ^ x] / 2 + x */
void two(void)
{
	double x;
	for (x = 1.1; x < 10; x++)
		printf("%g\n", (pow(-1, x) / 2) + x);

}

void one(void)
{

	double x = 0.0;
	double pi = acos(-1.0);
	int n;
	for (n = -10; n <= 10; n++) {

	//printf("base1: %g\t", asin(cos(x)));

	//printf("base2: %g\t", pi - asin(cos(x)));
	printf("arc1: %g\t", (0.5 * pi) + x + (2 * n * pi));
	printf("arc2: %g\t", (0.5 * pi) - x + (2 * n * pi));

	printf("mine: %g\n", pi * (pow(-1.0, n) / 2.0  + n) + pow(-1.0, n) * x);
	}
}


