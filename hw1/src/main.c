#include "project.h"
#include "list.h"

int main() {

    int choice = 1;

    Node **mas_of_heads = create_mas_of_heads();
    if (!mas_of_heads) {
        return 1;
    }

    while (choice == 1) {
        add_project_to_mas(mas_of_heads);

        printf("\nEnter 1 to add project\n");
        scanf("%d", &choice);
    }

    Date kvart = {1, 4, 2021};

    for (int i = 0; i < 5; i++) {
        if (print_projects(mas_of_heads, &kvart, i)) {
            return 1;
        }
    }

    if (del_mas_of_heads(mas_of_heads)) {
        return 1;
    }

    return 0;
}
