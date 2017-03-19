#include<stdio.h>
#include<math.h>
#include<ctype.h>

extern void push(double);
extern double pop(void);
extern double myatof(char *s);
int opswitch(char type, char *s);
int expr(int argc, int *argv[]);

/* expr1: evaluates basic reverse Polish expressions from the command line */
int main(int argc, int *argv[])
{
	if(!(expr(argc, argv)))
		printf("division by zero\n");
	else
		printf("%g\n", pop());

}

/* expr: evaluates  reverse Polish operators/operands from strings starting from argv[1], returns 0 if error */
int expr(int argc, int *argv[])
{
	if(argc > 1){
		int temp = expr(argc-1, argv);	/* order evaluation safeguard */
		return  temp * opswitch((char)(**(argv + argc-1)), (char *)*(argv + argc -1));
	}
	return 1; 
}

/* opswitch: returns 1 if operation successful, 0 if error */
int opswitch(char type, char *s)
{

	int op = 1;
	if(isdigit(type))
		push(myatof(s));
	else{

		double op2 = pop();
		switch(type){
			case '+':
				push(pop() + op2);
				break;
			case '-':
				push(pop() - op2);
				break;
			case 'x':	/* the terminal treats '*' as a wildcard operator */
				push(pop() * op2);
				break;
			case '^':
				push(pow(pop(), op2));
				break;
			case '/':
				if(0 == op2)
					op = 0;
				else
					push(pop() / op2);
				break;
			case'%':
				if(0 == op2)
					op = 0;
				break;
			default:
				push(op2);
				break;
		}
	}
	return op;
}

/* cc -o expr1 expr1.c pushpop.c myatof.c -lm */
