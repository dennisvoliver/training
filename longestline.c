/* program that outputs the longest line of characters from input */

#include<stdio.h>
#define STOP EOF        /* signal to stop reading input */
#define MAXLINE 1000    /* maximum number of chars in a line */

int getline(char[], int last);    /* returns the length of a line */
void copy(char to[], char from[]);  /* copy a line of characters */


                  
main()        
{
        int max, len;             /* current and longest length of chars in one line*/
        char line[MAXLINE], longest[MAXLINE]; /* current and longest array of chars*/

        max = 0;
        while((len = getline(line, MAXLINE)) > 0)   /* while there is a line*/
                if(len > max) {           /* if the current line is longer than the previous longest*/
                        max = len;        /* then save its length */
                        copy (longest, line);         /* and save that line */
                };

        if (max > 0 ) /* if there is a line */
                printf("%s", longest);        /* output the longest */
}

int getline (char s[], int last)  
{
        int i, c;

        for (i = 0; (c = getchar()) != STOP && i < (last - 1) && '\n' != c; ++i)       /* for each character that is not null and is at least 2 places away from the limit */
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

