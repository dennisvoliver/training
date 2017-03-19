#include <stdio.h>
#include <math.h>

double PI = acos(-1);
double getmax(double x);

#define INTERVAL (PI/1080.0)
#define TRIG cos 
#define TARGET 0.6738

/* interpolates a circular function to the fourth decimal */
int main()
{
	double x = TARGET;
	double max = getmax(x);
	double min = max - INTERVAL;
	//printf("x= %g min= %g max= %g interval= %g\n", x, min, max, INTERVAL);
	double interp = TRIG(min) + (((x - min) / (max - min)) * (TRIG(max) - TRIG(min)));
	printf("func(%g) = %g\n", x, interp);
	printf("correct answer: %g\n", TRIG(x));
	return 0;
}


double getmax(double x)
{
	double temp = 0.0;
	while (temp < x)
		temp += INTERVAL;
	return temp;
}
