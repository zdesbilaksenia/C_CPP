#ifndef HW2_THREADS_H
#define HW2_THREADS_H

#include "../include/matrix.h"
#include <unistd.h>
#include <aio.h>
#include <malloc.h>
#include <pthread.h>

int calculate_sum(Matrix *matrix, double *total_sum);

#endif
