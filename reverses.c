/* reverses: reverses arrays; n is the number of elements; returns 0 */
int reverses(void *arr[], int n)
{
	return revo(arr, arr + n - 1);
}

/* revo: child process of reverses */
int revo(void *first[], void *last[])
{
	int *temp = *first;
	*first = *last;
	*last = temp;
	return (first < last) ? revo(first + 1, last - 1) : 0 ;

}
