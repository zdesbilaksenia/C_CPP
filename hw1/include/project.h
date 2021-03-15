#ifndef HW1_PROJECT_H
#define HW1_PROJECT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "date.h"

typedef struct Project {
    char *name;
    char *leader_name;
    char *system;
    int priority;
    Date start;
    Date finish;
} Project;

int put_project(Project *project);

int get_project(Project *project);

int del_project(Project *project);

#endif //HW1_PROJECT_H
