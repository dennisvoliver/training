#include<stdio.h>
          /* counts number of characters inputted */
main()
{
        long n;
        n = 0;
        while( getchar() != '\n' ) 
                ++n;
        printf("%ld\n", n);
        
        /* the EOF constant does not seem to work in this kind of program
                so I will replace it with '\n' to terminate the
                        program after pressing enter*/
}
