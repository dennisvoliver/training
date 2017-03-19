

/* qsort: sorts an array of integers using quicksort method */
void qsort(int v[], int left, int right)
{
	if(left >= right)	/* if there is only one element left */
		return;		/* do nothing */

	extern void swap(int v[], int left, int right);
	swap(v, left, (left + right) / 2);	/* pick a wall and take the element out of the way */

	int last, i;
	last = left;	/* remember the new left edge */

	for( i = left + 1; i <= right ;i++)	/* for each element starting from the new edge */
		if(v[i] < v[left])		/* if its value is less than the wall element*/
			swap(v, ++last, i);	/* place it to the left side and move the edge again*/

	swap(v, left, last);	/* put the wall element back */
	qsort(v, left, last - 1);	/* do the same thing to the left side of the wall */
	qsort(v, last + 1, right);	/* and the right side */
}

/* swap: swaps two elements in an integer array */
void swap(int v[], int left, int right)
{
	int temp;

	temp = v[left], v[left] = v[right], v[right] = temp;

}
