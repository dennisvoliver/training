#include<stdio.h>

/* test cases for reverse() function */
int main()
{
	char s[] = "This is so awesome are you kidding me?\nHahahah!\t";
	extern int reverse(char s[], int i);
	reverse(s, 0);
	printf("%s\n", s);

}
