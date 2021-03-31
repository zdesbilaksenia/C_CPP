#ifndef HW2_THREADS_H
#define HW2_THREADS_H

#include "../include/matrix.h"
#include <unistd.h>
#include <aio.h>
#include <malloc.h>
#include <pthread.h>

typedef struct thread_args {
    int start;
    int end;
    double *ptr;
    double sum_of_row;
} thread_args;

int calculate_sum(Matrix *matrix, double *total_sum);

int fill_args(Matrix *matrix,
              thread_args *thr_args,
              int num_of_threads,
              int num_of_elements_in_thread);

void *get_sum(void *args);

#endif
