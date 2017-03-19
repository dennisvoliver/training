#include "debug.h"

int main()
{
	extern void month_day(int year, int yearday, int *pmonth, int *pday);
	extern int day_of_year(int year, int month, int day);
	int mon, day, yr, dyr;
	mon = -1;
	day = 1645;
	yr = 20142;
	dyr = 0;

	printf("doy %d\n",day_of_year(yr, mon, day));
	month_day(yr, dyr, &mon, &day);
	printf("month %d day %d\n", mon, day);
}
