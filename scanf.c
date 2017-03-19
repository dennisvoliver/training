#include "test.h"
#include<stdarg.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>


extern void minscanf(char *fmt, ...);

int main()
{
	char s[MAXLEN];
	int ival = 999;
	minscanf("mate %s\n", s);
	printf("%s\n", s);
}

/* minscanf: minimal printf with variable argument list */
void minscanf(char *fmt, ...)
{
	va_list ap; /* points to each unnamed arg in turn */
	char *p, s[MAXLEN];
	int c, i; 

	va_start(ap, fmt); /* make ap point to 1st unnamed arg */

	for (p = fmt; *p; p++) {
		if (*p != '%') {
			c = getch();
		continue;
		}
		switch (*++p) {
			case 'd':
				for(i = 0; !isspace(s[i] = getch()); i++)
					;
				s[i] = '\0';
				*(va_arg(ap, int *)) = atof(s);
				break;
			case 'f':
				for(i = 0; !isspace(s[i] = getch()); i++)
					;
				s[i] = '\0';
				*(va_arg(ap, double *)) = atof(s);
				break;
			case 'o':
				for(i = 0; !isspace(s[i] = getch()); i++)
					;
				s[i] = '\0';
				*(va_arg(ap, int *)) = atof(s);
				break;
			case 'x':
				for(i = 0; !isspace(s[i] = getch()); i++)
					;
				s[i] = '\0';
				*(va_arg(ap, int *)) = atof(s);
				break;
			case 's':
				for(i = 0; !isspace(s[i] = getch()); i++)
					;
				s[i] = '\0';
				strcpy(va_arg(ap, char *), s);
				break;
			default:
				getch();
				break;
		}
	}
	va_end(ap); /* clean up when done */
}


