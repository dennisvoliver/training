

/* qsort: sorts an array of pointers using quicksort method, based on multiple fields and comparisons */
void qsort(void *v[], int left, int right, int *from, int *to, int (**comp)(void *, void *, int))
{
	if(left >= right)	
		return;		

	extern void swap(void *v[], int i, int j);
	swap(v, left, (left + right) / 2);	

	int last, i;
	last = left;	

	int compare = 0, field = 0;
	for( i = left + 1; i <= right ;i++){

		while(0 < *(from + field) && (compare  = (**(comp+field))(v[i] + *(from + field) - 1, v[left] + *(from + field) - 1, *(to + field))) ==  0 )		{

//			printf("bug here: copare =  %d from = %d \n", compare, *(from + field));
			field++;
			}
			if(compare < 0)
				swap(v, ++last, i);	
			field = 0;
	}

	swap(v, left, last);	
	qsort(v, left, last - 1, from, to, comp);	
	qsort(v, last + 1, right, from, to, comp);	
}

