#include<stdio.h> 
#include<math.h>
#include<ctype.h>
#include<string.h>

#define MAXLEN 1000

void push(double);
double pop(void);

/* reverse polish calculator */
int main()
{
	int type;
	double op2, op = 0.0;
	char s[MAXLEN];

	while (scanf("%s", s) != EOF) { 
		if (isdigit(*s)) {
			sscanf(s, "%lf", &op);
			push(op);
		} else if (strlen(s) == 1)
			switch(*s) {
				case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				case '/':
					if((op2 = pop()) != 0.0)
						push(pop() / op2);
					else
						printf("error: division by zero\n");
					break;
				case '%': /* mod */
					if(op2 = pop())
						push((double)((int)pop() % (int)op2));
					else
						printf("error: zero division\n");
					break;

				case '^': /* pow */
					op2 = pop();
					push(pow(pop(),op2));
					break;
				case '=':
					printf("\t%g\n", pop());
					break;
				default:
					printf("invalid:  %c\n", type);
					break;
			}
		else
			/* ignore */;
	}
	return 0;
}


