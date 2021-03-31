#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/matrix.h"


Matrix *create_matrix(size_t rows, size_t cols) {
    Matrix *m = calloc(1, sizeof(Matrix));
    if (!m) {
        return 0;
    }
    m->ptr = calloc(cols * rows, sizeof(double));
    if (!m->ptr) {
        free(m);
        return 0;
    }
    m->cols = cols;
    m->rows = rows;

    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->cols; j++) {
            m->ptr[i * m->cols + j] = 1;
        }
    }
    return m;
}

int free_matrix(Matrix *matrix) {
    if (!matrix || !matrix->ptr) {
        return 1;
    }
    free(matrix->ptr);
    free(matrix);
    return 0;
}


Matrix *transp(const Matrix *matrix) {
    if (!matrix || !matrix->ptr) {
        return 0;
    }
    Matrix *matrix_transp = create_matrix(matrix->cols, matrix->rows);
    if (!matrix_transp) {
        return 0;
    }
    for (size_t i = 0; i < matrix_transp->rows; i++) {
        for (size_t j = 0; j < matrix_transp->cols; j++) {
            matrix_transp->ptr[i * matrix_transp->cols + j] = matrix->ptr[j * matrix->cols + i];
        }
    }
    return matrix_transp;
}


Matrix *create_matrix_from_file(const char *path_file) {

    int f = open(path_file, O_RDONLY);
    if (f < 0) {
        return 0;
    }

    struct stat size;
    stat(path_file, &size);
    char *file = mmap(NULL, size.st_size, PROT_READ, MAP_SHARED, f, 0);
    close(f);
    if (file == MAP_FAILED)
        return 0;

    if (file[0] == 0 || file[2] == 0) {
        munmap(file, size.st_size);
        return 0;
    }

    int rows, cols;
    sscanf(file, "%d %d", &rows, &cols);
    Matrix *m = create_matrix(rows, cols);
    file = strchr(file, '\n') + 1;
    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->cols; j++) {
            double number;
            sscanf(file, "%lf", &number);
            if (strchr(file, '\n') > strchr(file, ' ') ||
                (strchr(file, '\n') == NULL && strchr(file, ' ') != NULL)) {
                file = strchr(file, ' ') + 1;
            }
            m->ptr[i * m->cols + j] = number;
        }
        file = strchr(file, '\n') + 1;
    }

    return m;
}

int get_size(Matrix *m) {
    if (!m)
        return 0;
    return m->cols * m->rows;
}



