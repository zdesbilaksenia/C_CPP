#include "gtest/gtest.h"

extern "C" {
#include "../src/date.c"
#include "../src/project.c"
#include "../src/list.c"
}

TEST(CompareDate, FirstIsBigger) {
    Date one = {19, 2, 2021};
    Date two = {1, 2, 2021};
    ASSERT_EQ(compare_date(&one, &two), FIRST_DATE);
}

TEST(CompareDate, SecondIsBigger) {
    Date one = {19, 2, 2021};
    Date two = {21, 2, 2021};
    ASSERT_EQ(compare_date(&one, &two), SECOND_DATE);
}

TEST(CompareDate, EqualDates) {
    Date one = {19, 2, 2021};
    Date two = {19, 2, 2021};
    ASSERT_EQ(compare_date(&one, &two), EQUAL);
}

TEST(CompareDate, InvalidCompare) {
    Date one = {19, 2, 2021};
    ASSERT_EQ(compare_date(&one, NULL), ERROR);
}

TEST(GetDate, InvalidDate) {
    ASSERT_EQ(get_date(NULL), 1);
}

TEST(PutDate, InvalidDate) {
    ASSERT_EQ(put_date(NULL), 1);
}

TEST(AddToList, InavlidNode) {
    Project project = {"Proj", "Ivan", "Linux", 1, {10, 02, 2021}, {12, 04, 2021}};
    ASSERT_EQ(add(NULL, &project), 1);
}

TEST(AddToList, CorrectAdd) {
    Project project = {"Proj", "Ivan", "Linux", 1, {10, 02, 2021}, {12, 04, 2021}};
    Node *node = (Node *) malloc(sizeof(Node));
    if (node) {
        node->next = NULL;
        ASSERT_EQ(add(node, &project), 0);
        free(node->next);
        free(node);
    }
}

TEST(AddProjectToMas, InvalidAdd) {
    ASSERT_EQ(add_project_to_mas(NULL), 1);
}

TEST(PrintProjectsFromMas, InvalidMas) {
    Date date = {1,1,1};
    ASSERT_EQ(print_projects(NULL, &date, 1) , 1);
}

TEST(PrintProjectsFromMas, InvalidDate) {
    Node **mas = create_mas_of_heads();
    ASSERT_EQ(print_projects(mas, NULL, 1) , 1);
    del_mas_of_heads(mas);
}

TEST(DelMas, CorrectDel){
    Node **mas = create_mas_of_heads();
    ASSERT_EQ(del_mas_of_heads(mas) , 0);
}

TEST(DelMas, InvalidDel){
    ASSERT_EQ(del_mas_of_heads(NULL) , 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}