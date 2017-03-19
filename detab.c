#include<stdio.h>    
                     /* program that replaces tab with spaces */

main()
{
        int x, y, i;
        int p;          /* where the character will be stored */
        x = -1;         /* number of characters, first char starts at 0 */
        y = 8;          /* number of spaces per tab */
        i = 0;          /* loop counter */

        while(EOF != (p = getchar())){          /* while there is a line */

                ++x;                            /* keep counting the number of characters */


                if('\t' != p && '\n' != p)      /* if p is just normal */
                        putchar(p);             /* output p */

                else if('\t' != p){             /* if p is a newline */
                        putchar(p);             /* output newline */
                        x = -1;                   /* and refresh the character count */

                }
                else {                          /* if p is a tab */
                        for (i = 0; i < ((((x / y) + 1) * y) - x); ++i) 
                                putchar(' ');                           /* replace tab char with spaces */

                        x = x - 1 + ((((x / y) + 1) * y) - x);          /* and add those spaces to x */
                }
        }
}
