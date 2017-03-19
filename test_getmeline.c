#include<stdio.h>

int main()
{
	char s[1000];
	while(getmeline(s, 1000) > 0)
		printf("%s\n",s);
}
