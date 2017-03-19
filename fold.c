#include<stdio.h>
#define MAX 1000 /* maximum size of a char array */
#define TABS 8    /* number of spaces for each tabstop */


int detab(char para[], long last, int y);   /* turns tabs into spaces */
int getlines (char s[], int last); /* gets input and plug them in array */
void copy (char to[], char from[]);  /* copies elements of one array to the other*/



        /* program that folds long lines */
main()
{




                        
       /*       main algorithm not ready yet         */





}

int detab(char para[], long last, int y)  /* y is the number of spaces in a tab */
{
        int i, x, z, r;
        char buffer[last]; /* buffer array */

        r = z = 0;           /* array index */
        x = -1;         /* first char per line starts at 0 */

        /* while there is a character and before
           we reach the end of the array */
        while( (z < getlines(para[], last)){          


                /* keep counting the number of characters */
                ++x;


                /* if para[r] is just a normal character,
                   then plug its value in the buffer array */
                if('\t' != para[r] && '\n' != para[r])      
                      buffer[z] = para[r];             


                /* if we hit a newline, refresh the tab count */
                else if('\t' != para[r]){             
                        buffer[z] = para[r];             
                        x = -1;                  

                }

               /* if we hit a tab */
                else {

                        /* replace tab with spaces */
                        i = 0;
                        while(i < ((((x / y) + 1) * y) - x)){
                                buffer[z++] = ' ';                           
                                i++;
                        }


                        /* while keeping track of our char count */
                        x = x - 1 + ((((x / y) + 1) * y) - x);         
                        z--;
                }

               z++;
               r++;
        }

        /* the null character will mark the end of our string */
        buffer[z] = '\0';

        /* replace array with buffer content */
         copy(para[], buffer[]);

        /* this function returns the number of chars in the array */
        return (z - 1);
}

int getlines (char s[], long last)  
{   
        int c;
        long i;

        i = 0;

         /* while there is an input
            store the char in the array */
        while (EOF != (c = getchar()) && i < (last - 1))      
                s[i++] = c;   

        /* save the last spot for the null char */
        s[i++] = '\0';

        return i;
}


void copy (char to[], char from[])  
{
        int i;
        i = 0;
        while('\0' != (to[i] = from[i])) 
                ++i;        
}


