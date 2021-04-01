#ifndef HW2_MATRIX_H
#define HW2_MATRIX_H

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>

typedef struct Matrix {
    size_t rows;
    size_t cols;
    double *ptr;
} Matrix;

Matrix *create_matrix(size_t rows, size_t cols);

Matrix *create_matrix_from_file(const char *path_file);

Matrix *transp(const Matrix *matrix);

int get_size(Matrix *m);

int free_matrix(Matrix *matrix);

#endif //HW2_MATRIX_H
