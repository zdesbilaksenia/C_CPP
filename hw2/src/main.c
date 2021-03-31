#include <stdio.h>
#include <bits/types/clock_t.h>
#include <pthread.h>
#include <math.h>
#include <../dynamic_lib/threads.h>
#include "../include/matrix.h"
#include "../static_lib/seq.h"

int main(int argc, char *argv[]) {

    Matrix *matrix;

    if (argc != 2) {
        size_t rows, cols;
        printf("No file path, create default matrix\nEnter number of rows: ");
        if (scanf("%zu", &rows) != 1)
            return 1;
        printf("Enter number of cols: ");
        if (scanf("%zu", &cols) != 1)
            return 1;
        matrix = create_matrix(rows, cols);
        if (!matrix)
            return 1;
    } else {
        matrix = create_matrix_from_file(argv[1]);
        if (!matrix)
            return 1;
    }

    double total_sum_seq = 0;
    double total_sum_parall = 0;

    struct timespec start_seq;
    clock_gettime(CLOCK_REALTIME, &start_seq);

    if (calculate_sum_easy(matrix, &total_sum_seq))
        return 1;

    struct timespec end_seq;
    clock_gettime(CLOCK_REALTIME, &end_seq);


    Matrix *transp_matrix = transp(matrix);
    if (!transp_matrix)
        return 1;

    struct timespec start_parall;
    clock_gettime(CLOCK_REALTIME, &start_parall);

    if (calculate_sum(transp_matrix, &total_sum_parall))
        return 1;

    struct timespec end_parall;
    clock_gettime(CLOCK_REALTIME, &end_parall);


    free_matrix(transp_matrix);
    free_matrix(matrix);


    if (fabs(total_sum_seq - total_sum_parall) > 1e-6)
        printf("%s%lf%s%lf\n\n", "Calculated sum is incorrect: ", total_sum_seq, " != ", total_sum_parall);
    else {
        printf("%s%lf%s%lf\n\n", "Calculated sum is correct: ", total_sum_seq, " = ", total_sum_parall);
        printf("Seq time: %f seconds\n",
               ((double) (end_seq.tv_sec - start_seq.tv_sec) +
                (double) (end_seq.tv_nsec - start_seq.tv_nsec) / 1000000000L));
        printf("Parall time: %f seconds\n",
               ((double) (end_parall.tv_sec - start_parall.tv_sec) +
                (double) (end_parall.tv_nsec - start_parall.tv_nsec) / 1000000000L));
    }

    return 0;
}
