/* swap: swaps two pointers in an array */
void swap(void *v[], int i, int j)
{
	void *temp = v[i];
	v[i] = v[j], v[j] = temp;
}
