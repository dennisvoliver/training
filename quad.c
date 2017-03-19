#include<stdio.h>
#include<math.h>
double quad(double *x, double a, double b, double c);
extern double myatof(char *s);

/* quad: evaluates the quadratic equation */
int main(int argc, int *argv[])
{
	if(4 < argc){
		printf("format: quad a b c\n");
		return 0;
	}
	double x[2], a = myatof(argv[1]), b = myatof(argv[2]), c = myatof(argv[3]);
	quad(x, a, b, c);
	printf("x = %g or %g\n", x[0], x[1]);
}

double quad(double *x, double a, double b, double c)
{
	*x =(-b - sqrt(pow(b,2) - (4 * a * c)))/2;
	return *(x+1) = (-b + sqrt(pow(b,2) - (4 * a * c)))/2;

}
