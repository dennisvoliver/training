#include<stdio.h>
        /* Outputs each word in new line */

main()
{
        int c; c = 0;
        while((c = getchar      ()) != EOF) {
                if ('\n' == c || '\t' == c || ' ' == c)
                        putchar('\n');
                else putchar(c);
        }
}

