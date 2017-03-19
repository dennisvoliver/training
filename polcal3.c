
/* cc polcal3.c parsop.c pushpop.c strindex.c command.c clrar.c ntov.c getmyline.c -lm */

#include<stdio.h> 
#include<stdlib.h>	/* for atof() */
#include<math.h>

#define MAXOP 100 /* maximum size of operand or operator */
#define MAXLINE 1000
#define NUMBER '0' /* signal that a number as found */
#define NEGATIVE '1' /*signal that number found is negative */
#define MAXCOM 1000 /* maximum size of command */
#define YES 1
#define NO 0

int getop(char []);
void push(double);
double pop(void);
void command(char [], double);
void clrar(char []);
void printop(void);
void ntov(double num, char letter);
double vton(char letter);
char line[MAXLINE];
char cp;

/* reverse polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];
	extern char line[];
	extern char cp;
	extern int getmyline(char [], int);

	/* for commands */
	int i, parse, assign;
	i = parse = assign = 0;

	char com[MAXCOM];

	/* initialize all single-letter variables */
	initv();

	/* while thereis a line */
	while(getmyline(line, MAXLINE) > 0){

		/* while chararacter being parsed is not the end of the line */
		while((type = parsop(s)) != '\0'){
			switch(type){
				case NUMBER:
					push(atof(s));
					break;
				case NEGATIVE:
					push(-atof(s));
					break;
				/* basic arithmetic */
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
				case '\n':
					printop();
					clrar(com);
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

				case '|':	/* start or stop parsing command */
					if(NO == parse)
						parse = YES;
					else{
						command(com, op2);
						clrar(com);
						i = 0;
						parse = NO;
					}
					break;
				case '=':	/* assign top stack value to variable after = */
					assign = YES;
					break;
	
				default :
					if(YES == parse){ 
						com[i++] = type;		
						com[i] = '\0';
					}else if(YES == assign){
						ntov(pop(), type);
						assign = NO;
					}else
						push(vton(type));
					break;
			}
		}
		cp = 0;
	}
	return 0;
}


