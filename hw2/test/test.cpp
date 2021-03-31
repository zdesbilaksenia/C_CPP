#include <cmath>
#include "gtest/gtest.h"


extern "C" {
#include "matrix.h"
#include "../dynamic_lib/threads.h"
#include "../static_lib/seq.h"
};

TEST(GetMatrixSize, InvalidSize) {
    ASSERT_EQ(get_size(NULL), 0);
}

TEST(GetMatrixSize, CorrectSize) {
    Matrix *m = create_matrix(2, 2);
    ASSERT_EQ(get_size(m), 4);
    free_matrix(m);
}

TEST(FreeMatrix, InvalidMatrix) {
    ASSERT_EQ(free_matrix(NULL), 1);
}

TEST(FreeMatrix, CorrectFree) {
    Matrix *m = create_matrix(2, 2);
    ASSERT_EQ(free_matrix(m), 0);
}

TEST(CalculateSum, InvalidArgs) {
    ASSERT_EQ(calculate_sum(NULL, NULL), 1);
}

TEST(CalculateSum, CorrectArgs) {
    Matrix *m = create_matrix(2, 2);
    double total_sum = 0;
    ASSERT_EQ(calculate_sum(m, &total_sum), 0);
    free_matrix(m);
}

TEST(CalculateSum, CorrectSum1) {
    Matrix *m = create_matrix_from_file("hw2/in");
    if (!m)
        printf("ERROR");
    double total_sum = 0;
    calculate_sum(m, &total_sum);
    ASSERT_NEAR(total_sum, 57.19, 1e-6);
    free_matrix(m);
}

TEST(CalculateSum, CorrectSum2) {
    Matrix *m = create_matrix_from_file("hw2/in2");
    double total_sum = 0;
    calculate_sum(m, &total_sum);
    ASSERT_NEAR(total_sum, 8, 1e-6);
    free_matrix(m);
}

TEST(FillArgs, CorrectFill) {

    thread_args thr_args = {0, 0, 0, 0};
    Matrix *m = create_matrix(2, 2);
    fill_args(m, &thr_args, 1, 4);
    ASSERT_EQ(thr_args.start, 0);
    ASSERT_EQ(thr_args.end, 4);
    ASSERT_EQ(thr_args.ptr, m->ptr);
    free_matrix(m);
}

TEST(CalculateSumEasy, InvalidArgs){
    ASSERT_EQ(calculate_sum_easy(NULL,NULL), 1);
}

TEST(CalculateSumEasy, CorrectSum1){
    Matrix *m = create_matrix_from_file("hw2/in");
    double total_sum = 0;
    calculate_sum_easy(m, &total_sum);
    ASSERT_NEAR(total_sum, 57.19, 1e-6);
    free_matrix(m);
}

TEST(CalculateSumEasy, CorrectSum2) {
    Matrix *m = create_matrix_from_file("hw2/in2");
    double total_sum = 0;
    calculate_sum_easy(m, &total_sum);
    ASSERT_NEAR(total_sum, 8, 1e-6);
    free_matrix(m);
}

