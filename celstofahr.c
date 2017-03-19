#include<stdio.h>

/* converts celsius to Fahrenheit from 0 to 300 celsius */

main()
{

	float celsius, fahr;
	float step, lower, upper;

	lower = 0.0;		/* lower limit of the scale */
	upper = 300.0;  	/* upper limit of the scale */
	step = 20.0;		/* increments */
	
	celsius = lower;
	
	printf("%7s\t%10s\n", "Celsius", "Fahrenheit");	/* prints headings */
	
	while (celsius <= upper) {				/* outputs cels to fahr conversion table */
		fahr = ((9.0 / 5.0) * celsius) + 32.0;
		printf("%7.1f\t%10.1f\n", celsius, fahr);	
		celsius = celsius + step;	
	}

}