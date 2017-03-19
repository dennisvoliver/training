#include<stdio.h>
#include<ctype.h>

/* case: converts text stream to upper, lower case or none */
int main(int argc, char *argv[])
{
	int c;
	if (argc > 1 && **++argv == '-') {
		if (*++*argv == 'l') 
			while ((c = getchar()) != EOF)
				putchar(tolower(c));
		else if (**argv == 'u')
			while ((c = getchar()) != EOF)
				putchar(toupper(c));
	} else
		while ((c = getchar()) != EOF)
			putchar(c);
	return 0;
}

/*
if there is an argument {
	if argument is -l {
		while there is a char
			output lower case of char
	} else if argument is -u
		while there is a char
			output upper case of char
} else
	while there is a char
		output char
*/
