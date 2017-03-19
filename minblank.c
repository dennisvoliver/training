#include<stdio.h>
        /*      Program that reduces the number of blanks in every line
                it transforms 8 consecutive spaces into one tab   */

#define MAXCHARS 1000  /* maximum number of characters in a line */

int getline(char s[], int last); /* gets input from keyboard then dumps result to specified array */
void copy (char to[], char from[]);   /* copies content of one char array to another */

main()
{
        int len, i;
        char line[MAXCHARS];

        i = 0;
        while((len = getline(line, MAXCHARS)) > 0) {  /* while there is a line*/
                /* WILL FINISH SOON */

        }

}

int getline (char s[], int last)
{
        int i, c;

        for (i = 0; (c = getchar()) != EOF && i < (last - 1) && '\n' != c; ++i)       /* for each character that is not null and is at least 2 places away from the limit */
                s[i] = c;   /* dump the character to an array */
        if ('\n' == c) {    /* when newline is encountered */
                s[i] = c;
                ++i;        /* save that last spot */
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

