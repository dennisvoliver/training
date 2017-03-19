#include<stdio.h>
extern int mygetline(char *);
int myatoi(char *s);
extern test_myatoi(char *s);

int main()
{
	char *s;
	int c = test_myatoi(s);
}

int test_myatoi(char *s)
{
	if(!mygetline(s))
		return 0;
	printf("%d\n",myatoi(s));
	return 1 + test_myatoi(s);

}
