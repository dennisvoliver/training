#include<stdio.h>

        /* outputs each word in newline while disregarding
                   double spaces*/
main()
{
        int c, d; c = d = 0; /* d is the previous character */
        while ((c = getchar()) != EOF) {
                if ('\n' != c && '\t' != c && ' ' != c)
                         putchar(c);
                else if ( d != c)
                         putchar('\n');
               d = c;
         }
}
