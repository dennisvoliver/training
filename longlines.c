/* program that outputs the arbitrarily long lines of characters from input */

#include<stdio.h>
#define MAXLINE 1000    /* maximum number of chars in a line */

int getline(char[], int last);    /* stores character strings in an array then outputs its length */
void copy(char to[], char from[]);  /* copies the elements of one character array to another */


                  
main()        
{
        int min, len;             /* current and longest length of chars in one line*/
        char line[MAXLINE], longest[MAXLINE]; /* current and longest array of chars*/

        min = 10;
        while((len = getline(line, MAXLINE)) > 0) {  /* while there is a line*/
                if(len > min) {           /* if the current line is longer than the specified minimum*/
                        copy (longest, line);         /* and save that line */
                        printf("%d %s",len, longest);
                }
       }
        

}

int getline (char s[], int last)  
{
        int i, c;

        for (i = 0; (c = getchar()) != EOF && i < (last - 1) && '\n' != c; ++i)       /* for each character that is not null and is at least 2 places away from the limit */
                s[i] = c;   /* dump the character to an array*/
        if ('\n' == c) {    /* when newline is encountered*/
                s[i] = c;
                ++i;        /* save that last spot*/
        }
        s[i] = '\0';         /* for the null character */
        return i;
}


void copy (char to[], char from[])  
{
        int i;
        i = 0;
        while('\0' != (to[i] = from[i])) 
                ++i;        
}

