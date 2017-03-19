#include <stdio.h>
#include <stdlib.h>

enum limits {MAXROW = 12, MAXCOL = 9};

/* possible tennis doubles match */
int main()
{
	int rw, col;
	int RW, COL;
	int count = 0;
	for (rw = 0; rw < MAXROW; rw++) {
		for (col = 0; col < MAXCOL; col++) {
			for (RW = rw+1; RW < MAXROW; RW++) {
				for (COL = 0; COL < MAXCOL; COL++) {
					if (col != COL) {
						printf("(%d, %d) vs (%d, %d)\n", rw, col, RW, COL);
						count++;
					}
				}
			}
		}
	}
	printf("total possible matches: %d\n", count);

	return 0;
}
