/* same as dayconv.c but with pointers instead of array indices */
#include "debug.h"

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{

	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	/* error handlers */
	if(year <= 0 || month <= 0 || month > 12 || day <= 0)
		return -1;


	for (i = 1; i < month; i++)
		day += *(*(daytab+leap)+i);
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if(year <= 0 || yearday <= 0 || yearday > 365 || (leap && (yearday > 364))){
		*pmonth = -1;
		*pday = -1;
	}

	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= *(*(daytab+leap)+i);
	*pmonth = i;
	*pday = yearday;
}
