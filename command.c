#include<stdio.h>
#include<math.h>
char commands[] = "1sin5cos9tan14asin20acos26atan32atan239sinh45cosh51tanh57exp62log67log1074pow79sqrt85ceil91floor98fabs105ldexp113fdexp121modf128fmod135neg141top147dup153swap160clear168pstack177printop\0";
void push(double);
double pop(void);
void ptop(void);	
void dup(void);
void swap(void);
void clear(void);
void command(char [], double);
void pstack(void);
void printop(void);
int strindex(char source[], char searchfor[]);

/* command: special commands for reversed polish notation calculator */
void command(char searchfor[], double buf)
{
	switch(strindex(commands, searchfor)){
		case 1:
			push(sin(pop()));
			break;
		case 5:
			push(cos(pop()));
			break;
		case 9:
			push(tan(pop()));
			break;
		case 14:
			push(asin(pop()));
			break;
		case 20:
			push(acos(pop()));
			break;
		case 26:
			push(atan(pop()));			
			break;
		case 32:
			buf = pop();
			push(atan2(pop(), buf));
			break;
		case 39:
			push(sinh(pop()));
			break;
		case 45:
			push(cosh(pop()));
			break;
		case 51:
			push(tanh(pop()));
			break;
		case 57:
			push(exp(pop()));
			break;
		case 62:
			push(log(pop()));
			break;
		case 67:
			push(log10(pop()));
			break;
		case 74:
			buf = pop();
			push(pow(pop(), buf));
			break;
		case 79:
			push(sqrt(pop()));
			break;
		case 85:
			push(ceil(pop()));
			break;
		case 91:
			push(floor(pop()));
			break;

		case 98:
			push(fabs(pop()));
			break;
		case 105:
			buf = pop();
			push(ldexp(pop(), (int)buf));
			break;
//		case 115:
//			return frexp(pop(), &buf);
//			break;	
//		case 121:
//			return modf(pop(), &buf);
//			break;
		case 128:
			buf = pop();
			push(fmod(pop(), buf));
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
		case 168:
			pstack();
			break;
		case 177:
			printop();
			break;
		default :
			printf("command:%s not a valid operator \n", searchfor);
			break;
		
	}
}



