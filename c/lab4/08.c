#include <stdio.h>
#include <stdlib.h>

struct matrix {
    size_t rows, cols;
    double *data;
};

struct matrix *matrix_swap_diagonals(const struct matrix *m) {
    struct matrix *dst;
    dst = malloc(sizeof(*dst));
    if (!dst) return NULL;
    dst->cols = m->cols;
    dst->rows = m->rows;
    dst->data = malloc(dst->rows*dst->cols*sizeof(*(dst->data)));
    if (!dst->data) return NULL;
    unsigned index = 0;
    for (int i = 0; i < dst->rows; i++) {
        for (int j = 0; j < dst->cols; j++) {
            dst->data[i*dst->cols+j] = m->data[i*dst->cols+j];
        }
        double tmp = dst->data[i*dst->cols+index];
        dst->data[i*dst->cols+index] = dst->data[(i+1)*dst->cols-(index+1)];
        dst->data[(i+1)*dst->cols-(index+1)] = tmp;
        index++;
    }
    return dst;
}

void show_matrix(const struct matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%5.1lf", m->data[i*m->cols+j]);
        }
        printf("\n");
    }
}

int main () {
    double values[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    struct matrix mat = {
            .rows = 4,
            .cols = 4,
            .data = values
    };
    struct matrix *dst;
    dst = matrix_swap_diagonals(&mat);
    show_matrix(&mat);
    printf("\n");
    show_matrix(dst);
    free(dst);
}