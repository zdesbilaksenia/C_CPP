#include "project.h"

int put_project(Project *project) {
    if (!project) {
        return 1;
    }
    char buf[128];

    printf("%s", "Project name: ");
    scanf("%127s", buf);
    project->name = (char *) malloc(strlen(buf) + 1);
    if (project->name == NULL) {
        return 1;
    }
    strcpy(project->name, buf);

    printf("%s", "System: ");
    scanf("%127s", buf);
    project->system = (char *) malloc(strlen(buf) + 1);
    if (project->system == NULL) {
        return 1;
    }
    strcpy(project->system, buf);

    printf("%s", "Team leader name: ");
    scanf("%127s", buf);
    project->leader_name = (char *) malloc(strlen(buf) + 1);
    if (project->leader_name == NULL) {
        return 1;
    }
    strcpy(project->leader_name, buf);


    printf("%s", "Priority from 1 to 5 (1 - high, 5 - low): ");
    scanf("%d", &project->priority);
    if (project->priority < 1 || project->priority > 5) {
        return 1;
    }

    printf("%s", "Enter start date:\n");
    if (put_date(&project->start)) {
        return 1;
    }

    printf("%s", "Enter finish date:\n");
    if (put_date(&project->finish)) {
        return 1;
    }

    if (compare_date(&project->start, &project->finish) == 1) {
        return 1;
    }

    return 0;
}

int get_project(Project *project) {

    if (!project) {
        return 1;
    }

    printf("%s", "Project info: \n");

    printf("%s%s%s%s%s%s%s%d%c", "Name: ", project->name, "\nSystem: ", project->system, "\nTeam leader name: ", project->leader_name, "\nPriority: ",
           project->priority, '\n');

    printf("%s", "Start date: ");
    if (get_date(&project->start)) {
        return 1;
    }

    printf("%s", "Finish date: ");
    if (get_date(&project->finish)) {
        return 1;
    }

    printf("%c", '\n');

    return 0;
}

int del_project(Project *project) {

    if (!project){
        return 1;
    }

    free(project->leader_name);
    free(project->name);
    free(project->system);
    free(project);

    return 0;
}
