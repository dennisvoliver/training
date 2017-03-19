#include<stdio.h>
             /* outputs number of chararacters in
                        each word inputted, ignores extra spaces */

#define EMPTY 0 /* no characters in word */
main()
{
        int nword;      /* number of words      */
        int* pword;     /* location of nwords   */
        int c;          /* the first character  */
        int nchar;      /* number of characters */
        int p;          /* previous character */

        c = nchar = 0;
        p = '\n';                     /* initialize variables */
        nword = 1;
        pword = &c;
        *(pword+nword) = EMPTY;

        while (( c = getchar()) != EOF) {      /* do the thing */
                if ( '\n' != c && '\t' != c && ' ' != c)
                        *(pword+nword) = ++nchar;
                else {
                        if('\n' != p && '\t' != p && ' ' != p) {
                                ++nword;
                                nchar = 0;
                         }
                      }
                p = c;
        }
        int j;
        printf("| nth word | n characters |\n___________________________");
        for ( j = 1; j < nword; j++) {
                if (*(pword+j) != EMPTY)
                printf("\n|%10d|%14d|\n___________________________", j, *(pword+j));   /* output results */
        }
}
