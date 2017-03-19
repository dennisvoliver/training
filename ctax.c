#include<stdio.h>
#define MAX 1000   /* max char input */     
#define OUT 0      /* outside a comment */
#define IN 1       /* inside a comment */
#define STALE -1   /* almost outside a comment */                 

int getlines(char s[], int last);  /* stores input to array */
long mod(long dividend, long divisor);	/* returns the remainder of a quotient */

main()         /* program that checks for
		* rudimentary syntax errors like unmatched parentheses, brackets and braces
		* this program was just hacked from nocomment.c so there are plenty of unnecessary 			* algorithms
		*/
{
        char arr[MAX];
        int i = 0, state = OUT;
        getlines(arr, MAX);
        int inquote = OUT, incons = OUT;
	int oparens, obraks, obracs;	/* opening parentheses, brackets and braces */
	int cparens, cbraks, cbracs;	/* closing parentheses, brackets and braces */
	int quots, dquots;		/* quotes and double quotes */
	int allgood;			/* syntax check result */

	/* initialize dem variables */
	oparens = obraks = obracs = cparens = cbraks = cbracs = quots = dquots = allgood = OUT;


        /* while there is a character */
        while('\0' != arr[i]){

                /* if we are outside a comment,
                   determine if char is inside a string
                   or character constant */

                if (OUT == state){

                        
                        if('\'' == arr[i] && OUT == incons)
                                incons = IN;
                        else if('\'' == arr[i] && IN == incons)
                                incons = OUT;

                        if('\"' == arr[i] && OUT == inquote)
                                inquote = IN;  
                        else if('\"' == arr[i] && IN == inquote)
                                inquote = OUT;
                }


                /* if we are outside a string
                   or character constant, determine
                   if we are inside a comment */

                if(OUT == inquote && OUT == incons){

                        /* determine if character is inside a comment */
                        if('/' == arr[i] && '*' == arr[(i + 1)])
                                state = IN;

                        /* determine if it's time to go out now */
                        if(IN == state && '*' == arr[i] && '/' == arr[(i + 1)])
                                state = STALE;
                }


                /* if we are outside a comment, count the parentheses, brackets and braces, single and 				double quotes */

                if(OUT == state){
			if('[' == arr[i]) ++obraks;
			else if('{' == arr[i]) ++obracs;
			else if('(' == arr[i]) ++oparens;

			else if(']' == arr[i]) ++cbraks;
			else if('}' == arr[i]) ++cbracs;
			else if(')' == arr[i]) ++cparens;

			else if('\'' == arr[i]) ++quots;
			else if('\"' == arr[i]) ++dquots;

		}

                /* if we are inside a comment and near the closure
                   of the comment, do nothing else but change the state */
                else if(STALE == state){
                        if('*' == arr[i])
                                ;
                        else{
                                ;
                                state = OUT;
                        }
                                
                }

                /* but if we are inside a comment, do nothing too */
                else ;


                i++;
        }

	/* check syntax */
	allgood = 1;
	if(obracs != cbracs)allgood = 0;
	if(obraks != cbraks)allgood = 0;
	if(oparens != cparens)allgood = 0;
	if(0 != mod(quots, 2) || quots < 2)allgood = 0;
	if(0 != mod(dquots, 2) || dquots < 2)allgood = 0;

        /* if everything is all good then output the entire program */
	if(1 == allgood)
        	printf("%s", arr);
	else printf("syntax error! you are a moron\n");

}

int getlines(char s[], int last)
{
        int i = 0, r = 0;

        /* while character is not the end of input,
           or has not reached the array limit,
           store character to array */
        while(EOF != (r = getchar()) && i < last - 1)
                s[i++] = r;

        /* mark the end of the string with null character */
        s[i++] = '\0';

        /* return the string length */
        return i;
}

long mod(long x, long y)	/* returns the remainder of x/y */
{
	long buf;
	if(x < y || 0 == y) return 0;
	else{
		buf = x/y;
		return x - (buf * y);
	}
}
