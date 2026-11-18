#include <stdio.h>

#define RANGEERROR(string) printf("error: argument `%s' is not in valid range.", string)

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

int main(void) {
    int year = 2003;
    int month = 8;
    int day = 4;
    int val = day_of_year(year, month, day);
    
    printf("%d\n", val);
    val -= 6;
    month_day(year, val, &month, &day);

    printf("%02d/%02d/%d\n", day, month, year);
    return 0;
}

int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (year < 0) {
        RANGEERROR("year");
        return -1;
    }
    if (month < 0 || month > 12) {
        RANGEERROR("month");
        return -1;
    }
    if (day < 0 || day > daytab[leap][month]) {
        RANGEERROR("day");
        return -1;
    }
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}


int month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (yearday < 0) {
        RANGEERROR("yearday");
        return -1;
    }
    if ((leap == 1 && yearday > 366) || (leap == 0 && yearday > 365)) {
        RANGEERROR("yearday");
        return -1;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
