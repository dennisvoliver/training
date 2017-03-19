

/* qsort: sorts an array of pointers using quicksort method */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	if(left >= right)	/* if there is only one element left */
		return;		/* do nothing */

	extern void swap(void *v[], int i, int j);
	swap(v, left, (left + right) / 2);	/* pick a wall and take the element out of the way */

	int last, i;
	last = left;	/* remember the new left edge */

	for( i = left + 1; i <= right ;i++)	/* for each element starting from the new edge */
		if((*comp)(v[i], v[left]) < 0)		/* if its value is less than the wall element*/
			swap(v, ++last, i);	/* place it to the left side and move the edge again*/

	swap(v, left, last);	/* put the wall element back */
	qsort(v, left, last - 1, comp);	/* do the same thing to the left side of the wall */
	qsort(v, last + 1, right, comp);	/* and the right side */
}

