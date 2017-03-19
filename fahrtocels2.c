#include<stdio.h>

/* converts Fahrenheit to Celsius from 300F to 0F */

#define LOWER 0 	/* lower limit of temparature */
#define UPPER 300 	/* upper limit of temperature */
#define STEP 20 	/* increment */

main()
{

	int fahr;

	for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
		printf("%3d\t%6.1f\n",fahr,(5.0 / 9.0) * (fahr - 32)); 


}