#include<stdio.h>
#define MAX 1000
        /*      Program that outputs the longlines from input        */
main()
{
        int chars[MAX], newl[MAX], a, i;
        newl[a] = (i = (a = 0));

        while (EOF != (chars[i] = getchar())) {  /* read input */
                if ( '\n' == chars[i])           /* store each line-length to an array*/
                        newl[++a] = ++i;
                else
                        i++;
        }

        int ave, x, y;
        if ( i > 1 && a > 1) {  /* if there is more than one line*/
                ave = chars[i-1] / (a-1); /* get the average line-length */
                for ( x = 1; x <= a; ++x)
                        if (ave <= (newl[x] - newl[x-1]))       /* if the line-length is equal or greater than the average */
                                for (y = newl[x-1]; y <= newl[x]; ++y)
                                        printf("%c",chars[y]);      /* output that line*/

        }
        else if (0 == a) /* if there is only one line */
                for (y = 0; y < i; ++y)
                        putchar(chars[y]); /* just output that line */
}
