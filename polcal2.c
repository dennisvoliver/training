#include<stdio.h> 
#include<stdlib.h>	/* for atof() */
#include<math.h>

#define MAXOP 100 /* maximum size of operand or operator */
#define NUMBER '0' /* signal that a number as found */
#define MAXCOM 1000 /* maximum size of command */
#define BUFSIZE 100
#define MAXVAL 100

int getop(char []);
void push(double);
double pop(void);
void ptop(void);	
void dup(void);
void swap(void);
void clear(void);
double command(char [], double);
void clrar(char []);
int strindex(char source[], char searchfor[]);


/* reverse polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	int i = 0;
	char com[MAXCOM];

	while((type = getop(s)) != EOF){
		switch(type){
			case NUMBER:
				push(atof(s));
				break;
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
				printf("\t%.8g\n", pop());
				break;
			case '%':
				if(op2 = pop())
					push((double)((int)pop() % (int)op2));
				else
					printf("error: zero division\n");
				break;

//			case 'n':	/* postfix n for negative numbers */
//				push(-1.0*pop());
//				break;
//			case 'p':	/* print top elements in stak*/
//				ptop();
//				break;
//			case 's':	/* swap top two elements in stack*/
//				swap();
//				break;
//			case 'd':	/* duplicates top elements in stack */
//				dup();
//				break;
//			case 'c':	/* clears stack */
//				clear();
//				break;
			case ':':
				command(com, op2);
				clrar(com);
				break;
			default :
				com[i++] = type;		
				break;
		}
	}
	return 0;
}

char commands[] = "1sin5cos9tan14asin20acos26atan32atan239sinh45cosh51tanh57exp62log67log1074pow79sqrt85ceil91floor98fabs105ldexp113fdexp121modf128fmod135neg141top147dup153swap160clear\0";

/* command: special commands for reversed polish notation calculator */
double command(char searchfor[], double buf)
{
	switch(strindex(commands, searchfor)){
		case 1:
			return sin(pop());
			break;
		case 5:
			return cos(pop());
			break;
		case 9:
			return tan(pop());
			break;
		case 14:
			return asin(pop());
			break;
		case 20:
			return acos(pop());
			break;
		case 26:
			return atan(pop());			
			break;
		case 32:
			buf = pop();
			return atan2(pop(), buf);
			break;
		case 39:
			return sinh(pop());
			break;
		case 45:
			return cosh(pop());
			break;
		case 51:
			return tanh(pop());
			break;
		case 57:
			return exp(pop());
			break;
		case 62:
			return log(pop());
			break;
		case 67:
			return log10(pop());
			break;
		case 74:
			buf = pop();
			pow(pop(), buf);
			break;
		case 79:
			return sqrt(pop());
			break;
		case 85:
			return ceil(pop());
			break;
		case 91:
			return floor(pop());
			break;

		case 98:
			return fabs(pop());
			break;
		case 105:
			buf = pop();
			return ldexp(pop(), (int)buf);
			break;
//		case 115:
//			return frexp(pop(), &buf);
//			break;	
//		case 121:
//			return modf(pop(), &buf);
//			break;
		case 128:
			buf = pop();
			return fmod(pop(), buf);
			break;
		case 135: /* negative postfix */
			push(-1.0*pop());
			break;
		case 141:
			ptop();
			break;
		case 147:
			dup();
			break;
		case 153:
			swap();
			break;
		case 160:
			clear();
			break;
		default :
			printf("command: not a valid operator \n");
			break;
		
	}
}
void clrar(char s[])	/* clears array */
{
	int i;
	for(i = 0; s[i] != '\0'; i++)
		s[i] = '\0';
}

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position */

int getch(void)	/* get a possibly pushed back character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();

}

void ungetch(int c)	/* push character back on inpu */
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters \n");
	else
		buf[bufp++] = c;
}



/* getop: get next character or numeric operand */

int getop(char s[])
{
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c;	/* not a number */
	i = 0;
	if(isdigit(c))		/* collect integer part */
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')	/* collect fraction part */
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

int sp = 0;		/* stack index */
double val[MAXVAL];	/* the stack itself */

double peak(int i)
{
	if(0 <= i && i <= sp)
		return val[i];
	else
		printf("peak: invalid stack index\n");
}
/* clear: clears stack */
void clear(void)
{
	while(0 <= --sp)
		val[sp] = '\0';
}

/* swap: swaps the top two elements of the stack */
void swap(void)
{
	double buf;
	if(1 < sp){
		buf = val[sp-2];
		val[sp-2] = val[sp-1];
		val[sp-1] = buf;
	}
	else
		printf("swap: not enough elements in stack \n");
}

/* dup: duplicates the top two elements in a stack */
void dup(void)
{
	if(1 < sp){
		val[sp] = val[-2+sp++];
		val[sp] = val[-2+sp++];
	}else if(0 < sp)
		val[sp] = val[-1+sp++];
	else
		printf("dup: stack empty\n");


}
/* prints the top 2 elements of the stack */
void ptop(void)
{
	if(1 < sp)
		printf("ptop: %g %g\n",val[sp-2], val[sp-1]);
	else if(0 < sp)
		printf("ptop: %g\n",val[sp-1]);
	else
		printf("ptop: stack empty\n");

}

/* push: push f onto value stack */
void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack is full, can't push %g\n", f);
}

/* pop: pop and return the top value from  stack */
double pop(void)
{
	if(sp >= 0)
		return val[--sp];
	else{
		printf("pop: stack empty\n");
		return 0.0;
	}
}



/* getmyline: get input from keyboard then dump result to s[] */
int getmyline (char s[], int last)  /* 1 */
{
        int i, c;

        for (i = 0; (c = getchar()) != EOF && i < (last - 1) && '\n' != c; ++i)
                s[i] = c;   
        if ('\n' == c) {    
                s[i] = c;
                ++i;        
        }
        s[i] = '\0';         
        return i;
}

/* finds pattern in a string and returns the index of the first character */
int strindex(char source[], char searchfor[])
{
	int i, j, k;
	for(i = 0; source[i] != '\0'; i++){
		for(j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
			;
		if(k > 0 && searchfor[k] == '\0')
			return i;

	}
	return -1;

}

