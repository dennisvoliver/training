#include<stdio.h>

	/* replicates getline function without using the && and || operators */
int mygetline(unsigned char string[], unsigned long lim);
int main()
{

	int i = 0;
	unsigned long lim = 100;	/* potential overflow */
	unsigned char string[lim];
	mygetline(&string[0], lim);
	printf("%s\n",string);
}

int mygetline(unsigned char string[], unsigned long lim)
{

	unsigned long i = 0; 
	int c = 0;
	while(i < lim-1){
		string[i] = (c=getchar());
		if('EOF' == c){		
			string[i] = '\0'; 
			return 0;	/* multiple exit points*/
		}
		else if('\n' == c){
			string[i] = '\0'; 
			return 0;	/* multiple exit points*/
		}
		i++;
	}
	string[i] = '\0';
	return 1;	/* tells when string[] is full */
}

