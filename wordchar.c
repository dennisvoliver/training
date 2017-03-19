#include<stdio.h>

        /* outputs number of characters per word without
                using pointers and while ignoring
                        double spaces */

#define IN 1          /* inside a word */
#define OUT 0         /* outside a word */

main()
{
        int c, nchar, nword, state;
        c = nchar = nword = 0;
        state = OUT;

        while((c = getchar()) != EOF) {
                if ('\t' != c && '\n' != c && ' ' != c){  /* if c is not white space */
                        ++nchar;                         /* then we are inside a word, so count the characters */
                        state = IN;                      
                }
                else if(state == IN) {           /* if whispace is found, then we are no longer inside the word */
                        ++nword;                 /* so call it the nth word and stop counting */
                        printf("\n%d %d\0", nword, nchar);        /* then output the number of characters we counted */
                        nchar = 0;
                        state = OUT;
                }
        }
}
