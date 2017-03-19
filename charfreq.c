
#include<stdio.h>

        /* counts frequencies of alpha-numeric characters */

#define   STOP  EOF    /* indicates when to stop reading input */
#define   FIRST  '0'         /* lowerbound of character set*/
#define   LAST  'z'          /* upperbound of character set*/


main()
{
         int others, index, c, total;
         others = LAST - FIRST + 1;      /* characters not included in our set */
         int arr[others + 1];          /* the array of frequencies that will appear in the output */

         for(c = 0; c <= others; ++c)
                arr[c] = 0;             /* initialize all elements in our array */

         c = 0;              /* where each character will be stored*/
         total = 0;          /* total number of characters*/
         while((c=getchar()) != STOP) {     /* read character input */
                 index = c - FIRST;        /* index of each character */
                 if (FIRST <= c && LAST >= c) {    /*  if character falls to our set  */
                       ++total;         
                       ++arr[index];     /* increment character frequency and total number of chars*/
                 }             
                 else if ('\t' != c && '\r' != c && '\n' != c && ' ' != c){       /* if character does not fall to our set but is not whitespace */
                         ++total;
                         ++arr[others];        /* increment others and total number of chars */
                 }
         }

         index = 0;
         for (index = 0; index < others; ++index) {   
                if(0 != arr[index]) {                         /* if char frequency is not 0 then */
                        putchar(index + FIRST);               /* output the character */
                        printf(" %d\t", arr[index]);          /* then its frequency */
                 }
         }
         printf("others: %d\ntotal: %d", arr[others], total);         /* output frequency of other characters and total*/
}
