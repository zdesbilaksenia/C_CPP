#include <stdio.h>
#include "date.h"

int put_date(Date *date) {

    if (!date) {
        return 1;
    }

    printf("%s", "Day: ");
    scanf("%d", &date->day);
    if (date->day < 1 || date->day > 31) {
        return 1;
    }

    printf("%s", "Month: ");
    scanf("%d", &date->month);
    if (date->month < 1 || date->month > 12) {
        return 1;
    }

    printf("%s", "Year: ");
    scanf("%d", &date->year);

    return 0;
}

int get_date(Date *date) {

    if (!date) {
        return 1;
    }

    printf("%d%c%d%c%d%c", date->day, '.', date->month, '.', date->year, '\n');

    return 0;
}

int compare_date(Date *first, Date *second) {

    if (!first || !second){
        return ERROR;
    }

    if (first->year > second->year) {
        return FIRST_DATE;
    } else if (first->year < second->year) {
        return SECOND_DATE;
    }

    if (first->month > second->month) {
        return FIRST_DATE;
    } else if (first->month < second->month) {
        return SECOND_DATE;
    }

    if (first->day > second->day) {
        return FIRST_DATE;
    } else if (first->day < second->day) {
        return SECOND_DATE;
    }

    return EQUAL;
}

