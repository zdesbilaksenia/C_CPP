#ifndef HW1_LIST_H
#define HW1_LIST_H

#include "project.h"

typedef struct Node {
    Project *data;
    struct Node *next;
} Node;

int add(Node *head, Project *project);

int del(Node *node);

Node **create_mas_of_heads();

int add_project_to_mas(Node **mas_of_heads);

int print_projects(Node **mas_of_heads, Date *kvart, int i);

int del_mas_of_heads(Node **mas_of_heads);

#endif //HW1_LIST_H
