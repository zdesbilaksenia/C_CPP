#include <unistd.h>
#include <aio.h>
#include <malloc.h>
#include <pthread.h>
#include "threads.h"

void *get_sum(void *args) {

    if (!args)
        return (void *) 1;

    thread_args *thr_args = (struct thread_args *) args;
    int num = thr_args->end - thr_args->start;

    for (size_t i = 0; i < num; i++) {
        thr_args->sum_of_row += thr_args->ptr[i];
    }

    pthread_exit(0);
}

int fill_args(Matrix *matrix,
              thread_args *thr_args,
              int num_of_threads,
              int num_of_elements_in_thread) {

    if (!matrix || !thr_args)
        return 1;

    for (size_t i = 0; i < num_of_threads; i++) {
        thr_args[i].start = i * num_of_elements_in_thread;
        thr_args[i].end = thr_args[i].start + num_of_elements_in_thread;
        thr_args[i].ptr = &matrix->ptr[i * num_of_elements_in_thread];
    }
    return 0;
}

int calculate_sum(Matrix *matrix, double *total_sum) {

    if (!matrix || !matrix->ptr || !total_sum)
        return 1;

    int num_of_threads = sysconf(_SC_NPROCESSORS_ONLN);
    if (!num_of_threads)
        return 1;

    pthread_t *threads = calloc(num_of_threads, sizeof(pthread_t));
    if (!threads)
        return 1;
    int num_of_elements_in_thread = get_size(matrix) / num_of_threads;

    thread_args *thr_args = calloc(num_of_threads, sizeof(thread_args));
    if (!thr_args)
        return 1;

    if (fill_args(matrix, thr_args, num_of_threads, num_of_elements_in_thread))
        return 1;

    for (size_t i = 0; i < num_of_threads; i++) {
        if (pthread_create(&threads[i], NULL, get_sum, (void *) &thr_args[i])) {
            return 1;
        }
    }

    int *status = NULL;
    for (int i = 0; i < num_of_threads; i++) {
        if (pthread_join(threads[i], (void **) &status))
            return 1;
    }

    free(threads);

    for (int i = 0; i < num_of_threads; i++) {
        *total_sum += thr_args[i].sum_of_row;
    }

    free(thr_args);
    return 0;
}
