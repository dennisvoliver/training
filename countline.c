#include<stdio.h>

        /* counts lines */

main()
{
        int c, nl;
        nl = 0;
        c = 0;
        while ( (c=getchar()) != EOF )
                if (c == '\n')
                   ++nl;
        printf("%d\n",nl);
}
