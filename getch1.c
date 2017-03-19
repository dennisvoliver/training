#include<stdio.h>
#include "calc.h"


/*getch1: returns a new character if c is EOF, else return the character inserted */
int getch1(int prev)
{
	static int buf = EOF; 
	static int back = FALSE;

	if (TRUE == back){  
		return buf;
	} (buf = getchar());

}

