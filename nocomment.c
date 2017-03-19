#include<stdio.h>
#define MAX 1000   /* max char input */     
#define OUT 0      /* outside a comment */
#define IN 1       /* inside a comment */
#define STALE -1   /* almost outside a comment */                 

int getlines(char s[], int last);  /* stores input to array */

main()         /* program that removes comments on C programs
                  while considering strings and character constants */
{
        char arr[MAX];
        int i = 0, state = OUT;
        getlines(arr, MAX);
        int inquote = OUT, incons = OUT;


        /* while there is acharacter */
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


                /* if we are outside a comment, do nothing */
                if(OUT == state)
                        ;

                /* if we are inside a comment and near the closure
                   of the comment, remove the char and change the state */
                else if(STALE == state){
                        if('*' == arr[i])
                                arr[i] = ' ';
                        else{
                                arr[i] = ' ';
                                state = OUT;
                        }
                                
                }

                /* but if we are inside a comment and not near
                   the closure, remove the char */
                else
                        arr[i] = ' ';


                i++;
        }
        /* then output the entire program */
        printf("%s", arr);
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
