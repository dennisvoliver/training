#include<stdio.h>

        /* copies input to output and replaces each tab by \t and
                each backspace by \b and each backslash by \\ */

main()
{

         int c;
         char t;
         char b;
         c = 0;
         b = 'b';
         t = 't';
         while( (c = getchar()) != EOF ) {
                if ('\t' == c) 
                        printf("\\%c\0",t);
                else if ('\b' == c) 
                        printf("\\%c\0",b);
                else if('\\' == c) 
                        printf("\\\\\0");
                else
                        putchar(c);                                             
          }

          /* the backspace is not explicitly outputted because
                getchar cannot read backspaces from the keyboard
                        in the same manner that it can't read EOF */
}
