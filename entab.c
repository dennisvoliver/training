#include<stdio.h>          /* Program that reduces the number of spaces
                              by replacing consecutive spaces with tabs */

#define MAX 1000           /* maximum number of characters in an input   */

int detab(char temp[], long last, int ntab);       /* translates tabs to spaces  */

main()
{
        int len, t, x, n;
        char line[MAX];     /* where the input will be stored */
        n = 8;              /* width of tabstops */

        /* while there is a line */
        while(0 < (len = detab(line, MAX, n)) && '\0' != line[len - 1] ){

                /* for every tabstop */
                for(t = 0; t < len; t+= n){
                        x = 1;

                        /* replace spaces before the tabstop
                        with null character */
                        while(' ' == line[t - x] && x < n){
                                line[t - x] = '\0';
                                x++;
                        }

                        /* then replace the last null with a tab */
                        if('\0' == line[(t - x) + 1])
                                line[(t - x) + 1] = '\t';
                }

                /* for each character in the array */
                for(x = 0; x < len; ++x)

                        /* output the not null characters */
                        if('\0' != line[x])
                                printf("%c",line[x]);
        }

}



int detab(char temp[], long last, int ntab)
{
        int i, x, y, z;
        int p;          /* where the character will be stored */

        z = 0;           /* array index */
        x = -1;         /* number of characters, first char starts at 0 */
        y = ntab;          /* number of spaces per tab */
        i = 0;          /* loop counter */

        /* while there is a character and and before
           we reach the end of the array */
        while(EOF != (p = getchar()) && z < last){          


                /* keep counting the number of characters */
                ++x;


                /* if p is just a normal character,
                   then plug its value in the array */
                if('\t' != p && '\n' != p)      
                      temp[z] = p;             


                /* if we hit a newline, refresh the tab count */
                else if('\t' != p){             
                        temp[z] = p;             
                        x = -1;                  

                }

               /* if we hit a tab tab, replace tab with spaces */
                else {
                        for (i = 0; i < ((((x / y) + 1) * y) - x); ++i) 
                                temp[z++] = ' ';                           

                        /* while keeping track of our char count */
                        x = x - 1 + ((((x / y) + 1) * y) - x);         
                        z--;
                }

               z++;
        }

        /* the null character will mark the end of our string */
        temp[z] = '\0';

        /* this function returns the number of chars in the array */
        return (z - 1);
}

