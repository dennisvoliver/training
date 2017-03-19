#include<stdio.h>
        /* copies input to output and replaces each string of one
                        or more spaces with just one space */
main()
{
        int c, d;
        c=0;
        d=0;

        while((c=getchar()) != EOF){
                if(' ' != c || ' ' != d)
                 putchar(c); d=c;
        }
}
