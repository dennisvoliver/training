#include<stdio.h> 

                  /* a program converts Fahrenheit to Celsius
                        and vice versa */

#define STEP 10 /* gap between each temperature*/
#define LOWER 0        /* lowerbound of temp*/
#define UPPER 300 /* upperbound of temp*/
int cels (int fahr); /* function prototype*/
int fahr (int cels);

main()
{
        int f, c, i;
        c = f = LOWER;

        printf("\nFahr->Cels|Cels->Fahr\n");
        while(c <= UPPER && f <= UPPER){ /* print cels->fahr and fahr->cels table*/
                printf("%3d  %3d  | %3d  %3d \n", f, cels(f), c, fahr(c));
                c = f = f + STEP;
        }
        return 0;
}

int cels(int fahr)
{
        int c;
        c = 5*(fahr - 32) / 9;
        return c;
}        

int fahr(int cels)
{
        int f;
        f = ((cels*9)/5) + 32;
        return f;
}        

