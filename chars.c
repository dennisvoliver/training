#include<stdio.h>

                /* testing integer representations of characters */

main()
{
        int i;
        printf("char | int\n----------\n");
        for ( i = 0; i <= 999; ++i){
               putchar(i);
               printf("    | %d\n",i);
        }
}
