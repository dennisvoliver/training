#include<stdio.h>

/* test cases for qsort */
int main()
{
	extern void qsort(int v[], int left, int right);
	extern void dcopy(int from[], int to[], int count);

	int samp[] = { 10, 12, 3, 65, 3, 1, 0, 100, 34, 53, 84, 29, 19, 68};
	int n = 14;
	int buf[n];

	dcopy(samp, buf, n);	
	qsort(samp, 0, n - 1);

	int i;
	for(i = 0; i < n; i++)
		printf("%d\t%d\n", buf[i], samp[i]);

}

void dcopy(int from[], int to[], int count)
{
	int i = 0;
	while(i < count)
		to[i] = from[i++];
}

