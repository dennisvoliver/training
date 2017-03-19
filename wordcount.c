#include<stdio.h>


                   /* counts the number of lines, words, and characters */

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

main()
{
        int c, nl, nc, nw, state;
        state = OUT;
        nl = nc = nw = 0;
        while((c = getchar()) != EOF) {
                ++nc;
                if ( '\n' == c)
                        ++nl;
                if ( '\n' == c || '\t' == c || ' ' == c)
                        state = OUT;
                else if (OUT == state) {
                        state = IN;
                        ++nw;
                 }
         }
         printf("%d %d %d\n", nl, nw, nc);
}
