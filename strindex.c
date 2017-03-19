/* finds pattern in a string and returns the index of the first character */
int strindex(char source[], char searchfor[])
{
	int i, j, k;
	for(i = 0; source[i] != '\0'; i++){
		for(j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
			;
		if(k > 0 && searchfor[k] == '\0')
			return i;

	}
	return -1;

}
