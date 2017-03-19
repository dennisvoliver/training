#include <stdio.h>

#define EMPTY ' '
#define X 'X'
#define O 'O'

int table [3][3] = {
	{EMPTY, EMPTY, EMPTY},
	{EMPTY, EMPTY, EMPTY},
	{EMPTY, EMPTY, EMPTY}
};

int check(void);
void printable(void);

/* an AI that can play tic tac toe */
int main()
{

}

/* printable: prints the table */
void printable(void)
{
	int rw, col;
	for (rw = 0; rw < 3; rw++)
		for (col = 0; col < 3; col++) {
			printf(" %c ", table[rw][col]);
 			printf((col < 2) ? "|": "\n");
		}
}


/* check: checks the winner */
int check(void)
{
	int rw, col;

	/* horizontal */
	for (rw = 0; rw < 3; rw++)
		if (table[rw][0] == table[rw][1] && table[rw][1] == table[rw][2])
			if (table[rw][0] != EMPTY)
				return table[rw][0];
	/* vertical */
	for (col = 0; col < 3; col++)
		if (table[0][col] == table[1][col] && table[1][col] == table[2][col])
			if (table[0][col] != EMPTY)
				return table[0][col];
	/* diagonal */
	if (table[0][0] == table[1][1] && table[1][1] == table[2][2])
		if (table[0][0] != EMPTY)
			return table[0][0];
	if (table[0][2] == table[1][1] && table[1][1] == table[2][0])
		if (table[0][2] != EMPTY)
			return table[0][2];
	/* no winner yet */
	return EMPTY;
}

