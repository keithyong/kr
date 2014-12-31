/* Exercise 5-8 and 5-9 */
#include <stdio.h>

void printArr(char (*c)[13]);
int day_of_year(int, int, int);
void month_day(int, int, int*, int*);
char * month_name(int);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int main()
{
    printArr(daytab);
    int month, day;
    month_day(2014, 123, &month, &day);
    printf("Day 123 of 2014 is %s/%d/2014\n", month_name(month), day);
    printf("%s/%d/2014 is day %d", month_name(month), day, day_of_year(2014, month, day));
}

int day_of_year(int year, int month, int day)
{
    /* Error checking */
    if (month > 12 || day > 31)
        return 0;
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    /* Error checking */
    if (yearday > 365)
        return;
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; yearday > *(*(daytab + leap) + i); i++)
        yearday -= *(*(daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;
}

char * month_name(int n)
{
    static char *name[] = {
        "Illegal month", 
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return (n < 1 || n > 12) ? *name : *(name + n);
}

void printArr(char (*c)[13])
{
    int i, j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 13; j++)
            printf("%d ", (int)*(*(c + i) + j));
        putchar('\n');
    }

}
