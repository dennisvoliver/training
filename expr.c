
/* cc expr.c pushpop.c strindex.c command.c clrar.c ntov.c  -lm */
/* this program was derived from polcal3.c so it's very bloated */

#include<stdio.h> 
#include<stdlib.h>	/* for atof() */
#include<math.h>
#include "debug.h"

#define MAXOP 100 /* maximum size of operand or operator */
#define MAXLINE 1000
#define NUMBER '0' /* signal that a number as found */
#define NEGATIVE '1' /*signal that number found is negative */
#define MAXCOM 1000 /* maximum size of command */
#define YES 1
#define NO 0
#define MAXLEN 1000	/* max length of line excluding NULL */

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
int readop(char *oper, int *line);
char *writeop(char *s, int *argv[], int argc); 

/* expr: evaluates reverse Polish expression from command-line */
int main(int argc, int *argv[])
{
	int type;	/* char operator buffer */
	double op2;	/* double swapping buffer */
	char s[MAXOP];	/* char digits buffer  */

	/* for commands */
	int i;		/* command character index */
	int j;		/* pointer index */
	int  parse;	/* indicator: to parse or not to parse */
	int  assign;	/* assign number to a single-letter variable */
	
	i = j = parse = assign = 0;

	char com[MAXCOM];	/* command chars buffer */

	/* initialize all single-letter variables */
	initv();

	/* while there is an argument */
	while((argc-(++j)) > 1){

		/* while there is chararacter */
		while((type = readop(s, *(argv+j))) != '\0'){
			/* bug: readop will never return '\0' */ 
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
	}
	return 0;
}


/* readop: reads from line[] and dumps to oper[] */
int readop(char *oper, int *line)
{
	int cp;	/* index of array being read */
	int i;	/* index of array being written to */
	i = cp = 0;	

	/* skip spaces before operator/operand */
	while((' ' == line[cp] || '\t' == line[cp]) && cp < MAXLEN)
		cp++;

	/* if negative sign is followed immediately by a digit, then collect the sign for atof() to interpret instead of returning a minus operator */
	if('-' == line[cp] && isdigit(line[cp+1]))
		oper[i++] = line[cp++];

	/* if its not a number or an indication that it is a fraction that starts with '.', return the character and seal oper[] with NULL */
	if(!isdigit(line[cp]) && '.' != line[cp]){
		oper[0] = line[cp];
		oper[1] = '\0';
		return line[cp++];
	}

	/* collect the integers */
	if(isdigit(line[cp]))
		while(cp < MAXLEN && i < MAXOP && isdigit(line[cp]))
			oper[i++] = line[cp++];
	/* collect fraction part */
	if('.' == line[cp]){
		oper[i++] = line[cp++];
		while(cp < MAXLEN && i < MAXOP && isdigit(line[cp]))
			oper[i++] = line[cp++];
	}	
	oper[i] = '\0';


	/* tell caller we copied a number to oper[]) */
	return NUMBER;
}


