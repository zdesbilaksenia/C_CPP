#include <pthread.h>
#include <argp.h>
#include "seq.h"

int calculate_sum_easy(Matrix* matrix, double* total_sum) {

    if (!matrix || !total_sum)
        return 1;

    for (int i = 0; i < matrix->cols; ++i) {
        for (int j = 0; j < matrix->rows; ++j) {
            *total_sum += matrix->ptr[j * matrix->cols + i];
        }
    }

    return 0;
}
