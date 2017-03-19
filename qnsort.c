

/* qsort: sorts an array of pointers using quicksort method, based on fields */
void qsort(void *v[], int left, int right, int from, int to, int (*comp)(void *, void *, int))
{
	if(left >= right)	
		return;		

	extern void swap(void *v[], int i, int j);
	swap(v, left, (left + right) / 2);	

	int last, i;
	last = left;	

	for( i = left + 1; i <= right ;i++)	
		if((*comp)(v[i] + from - 1, v[left] + from - 1, to) < 0)		
			swap(v, ++last, i);	

	swap(v, left, last);	
	qsort(v, left, last - 1, from, to, comp);	
	qsort(v, last + 1, right, from, to, comp);	
}

