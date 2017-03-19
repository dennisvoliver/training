#include<math.h>
#include<stdlib.h>
#include "test.h"
#include "debug.h"
#include<stdarg.h>

void minprintf(char *fmt, ...);
int print(char *format, void *arg);

int main()
{
/*
	extern int print(char *format, void *arg);
	int d = 111;
	char s[] = "This is a string.";
	print("dec = %d\n", &d);
	print("oct = %o\n", &d);
	print("hex = %x\n", &d);
	print("str = %s\n", s);
*/
	char s[1000] = "as shole";
	int i = 100;
	minprintf("hello %s there %o mate %xeh", s, i, i);	
}

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
	va_list ap; /* points to each unnamed arg in turn */
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt); /* make ap point to 1st unnamed arg */

	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
		continue;
		}
		switch (*++p) {
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 'o':
				ival = va_arg(ap, int);
				print("%o", &ival);
				break;
			case 'x':
				ival = va_arg(ap, int);
				print("%x", &ival);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap); /* clean up when done */
}

/* print: This function can print a variable in four possible formats: hex, oct, dec, or string. */
int print(char *format, void *arg)
{
	extern char *itor(int d, int r, char *s);
	char *s = (char *)malloc(MAXLEN);

	while (*format != '\0')  {
		if (*format == '%') {
			switch (*++format) {
				case 'o':
					/* print arg as octal; */
					itor(*(int *)arg, 8, s);
					while (*s != '\0')
						putchar(*s++);
					break;
				case 'x':
					/* print arg as hex; */
					itor(*(int *)arg, 16, s);
					while (*s != '\0')
						putchar(*s++);
					break;
				case 'd':
					/* print arg as dec; */
					itor(*(int *)arg, 10, s);
					while (*s != '\0')
						putchar(*s++);
					break;
				case 's':
					while (*((char *)arg) != '\0') {
						putchar(*((char *)arg));
						arg++;
					}
					break;

			}
		} else
			putchar(*format);
		format++;
	}
}

