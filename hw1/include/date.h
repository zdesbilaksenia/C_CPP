#ifndef HW1_DATE_H
#define HW1_DATE_H

typedef struct Date {
    int day, month, year;
} Date;

enum {
    EQUAL = 0,
    FIRST_DATE = 1,
    SECOND_DATE = 2,
    ERROR = 3
};

int put_date(Date *date);

int get_date(Date *date);

int compare_date(Date *first, Date *second);

#endif //HW1_DATE_H
