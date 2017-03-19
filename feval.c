/* feval: evaluates single-variable polynomial f(x) = a[0]x^n+a[1]x^n-1+...+ a[n-1]x+a[n] using recursion method, a[] are the coefficients and n is the number of coefficients, caution required with irrational numbers */
double feval(double x, double a[], int n)
{
	return n <= 1 ? 1.0: x * feval(x, a, n - 1) + a[n - 1];
}
