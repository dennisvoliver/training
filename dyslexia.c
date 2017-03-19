#include<stdio.h>
        /*      Program that reverses every word in every line  */

#define MAXCHARS 1000  /* maximum number of characters in a line */

int getline(char s[], int last); 
void copy (char to[], char from[]);   
void reverse(char s[]);

main()
{
        int len;
        char line[MAXCHARS];

        while((len = getline(line, MAXCHARS)) > 0) { /* while there is a line*/
              reverse(line);
              printf("%s\n", line);
        }
}

int getline (char s[], int last)  /* gets input from keyboard then dumps result to specified array */
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

void copy (char to[], char from[])      /* copies content of one char array to another */
{
        int i;
        i = 0;
        while('\0' != (to[i] = from[i])) 
                ++i;        
}

void reverse(char s[])     /* reverses the character string */
{
        int i, j;
        i = 0;

        while ('\0' != s[i]) /* find the null character */
                i++;

        char temp[i];         /* i is the number of elements in s[] */
        for (j = 0; j < i - 1; ++j)
                temp[j] = s[(i - 2 ) - j ];          /* staring from the second to the last character of s[] (excluding '\0' of course), plug its values to temp[] */

        temp[i - 1] = '\0';                         /* end string with null character*/
        for (i =  0; i <= j; ++i)
                s[i] = temp[i];                   /* plug the elements from buffer to the original array */

}
