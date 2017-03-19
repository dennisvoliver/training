#include<stdio.h>

/* Exercise 2-11 of K&R */

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
	int n, m;
	n = 59;
	m = 17;
	int v[n], i;
	for(i = 0; i < n; i++)
		v[i] = i;
	printf("%d\n", binsearch2(m, v, n));
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch2(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low < high) {
		mid = (low+high)/2;
		if (x <= v[mid])
			high = mid;
		else 
			low = mid + 1;
	}

	if(x == v[low])		
		return low;
	else
		return -1;

}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		printf("%d %d %d\n", low,  mid, high);
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			/* found match */
		return mid;

	}
	return -1;
	/* no match */
}

