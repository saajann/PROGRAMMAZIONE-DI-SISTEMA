#include <stdlib.h>
#include <stdio.h>

struct matrix {
    size_t rows, cols;
    double **data;
};

struct matrix *allocate_matrix(size_t n) {
    struct matrix *dst;
    dst = malloc(n * sizeof(*dst));
    dst->cols = n;
    dst->rows = n;
    dst->data = malloc(n * sizeof(*(dst->data)));
    for (int i = 0; i < n; i++) {
        dst->data[i] = malloc(n * sizeof(**(dst->data)));
    }
    return dst;
}

void fill_matrix(const struct matrix *m) {
    double k = 1;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = k++;
        }
    }
}

void show_matrix(const struct matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%5.2lf", m->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

struct matrix *matrix_swap_diagonals(const struct matrix *m) {
    struct matrix *dst;
    dst = allocate_matrix(m->cols);
    unsigned index = 0;
    for (int i = 0; i < dst->rows; i++) {
        for (int j = 0; j < dst->cols; j++) {
            dst->data[i][j] = m->data[i][j];
        }
        double tmp = dst->data[i][index];
        dst->data[i][index] = dst->data[i][dst->cols-index-1];
        dst->data[i][dst->cols-index-1] = tmp;
        index++;
    }
    return dst;
}

void free_matrix(struct matrix *m) {
    for (int i = 0; i < m->cols; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

int main() {
    struct matrix *src, *dst;
    src = allocate_matrix(3);
    fill_matrix(src);
    show_matrix(src);

    dst = matrix_swap_diagonals(src);
    show_matrix(dst);

    free_matrix(src);
    free_matrix(dst);
}