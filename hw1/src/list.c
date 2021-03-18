#include "list.h"

int add(Node *node, Project *project) {

    if (!node || !project) {
        return 1;
    }

    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) {
        return 1;
    }
    new_node->data = project;
    new_node->next = NULL;

    Node *temp = node;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = new_node;

    return 0;
}

int del(Node *node) {

    if (!node) {
        return 1;
    }

    Node *temp;

    while (node) {
        temp = node->next;
        if (del_project(node->data)) {
            return 1;
        }
        free(node);
        node = temp;
    }

    return 0;
}

Node **create_mas_of_heads() {

    Node **mas_of_heads = (Node **) malloc(5 * sizeof(Node *));
    if (!mas_of_heads) {
        return NULL;
    }

    for (int i = 0; i < 5; i++) {

        mas_of_heads[i] = (Node *) malloc(sizeof(Node));

        if (!mas_of_heads[i]) {
            for (int j = 0; j < i; j++) {
                free(mas_of_heads[j]);
            }
            free(mas_of_heads);
            return NULL;
        }

        mas_of_heads[i]->next = NULL;
    }

    return mas_of_heads;
}

int add_project_to_mas(Node **mas_of_heads) {

    if (!mas_of_heads) {
        return 1;
    }
    Project *project = (Project *) malloc(sizeof(Project));

    if (put_project(project)) {
        return 1;
    }

    if (!mas_of_heads[project->priority - 1]) {
        return 1;
    }

    if (add(mas_of_heads[project->priority - 1], project)) {
        return 1;
    }

    return 0;
}

int print_projects(Node **mas_of_heads, Date *kvart, int i) {

    if (!mas_of_heads || !kvart || !mas_of_heads[i]) {
        return 1;
    }
    printf("%s%d%c%c", "Projects with priority level: ", i + 1, '\n', '\n');

    Node *temp = mas_of_heads[i]->next;

    while (temp) {
        if (compare_date(&temp->data->finish, kvart) == 2)
            if (get_project(temp->data)) {
                return 1;
            }

        temp = temp->next;
    }

    return 0;
}

int del_mas_of_heads(Node **mas_of_heads) {

    if (!mas_of_heads) {
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        if (!mas_of_heads[i]) {
            return 1;
        }
        del(mas_of_heads[i]->next);
        free(mas_of_heads[i]);
    }
    free(mas_of_heads);

    return 0;
}
