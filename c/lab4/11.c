#include <stdio.h>
#include <stdlib.h>

struct matrix {
    size_t rows, cols;
    int **data;
};

struct matrix *allocate_matrix(size_t rows, size_t cols) {
    struct matrix *dst;
    dst = malloc(sizeof(*dst));
    dst->rows = rows;
    dst->cols = cols;
    dst->data = malloc(rows * sizeof(*(dst->data)));
    if (!dst->data) return NULL;
    for (int i = 0; i < dst->rows; i++) {
        dst->data[i] = malloc(dst->cols * sizeof(**(dst->data)));
        if (!dst->data[i]) return NULL;
    }
    return dst;
}


void fill_matrix(const struct matrix *m) {
    int k = 1;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = k++;
        }
    }
}

void show_matrix(const struct matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%5d", m->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void free_matrix(struct matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

struct matrix *matrix_product(const struct matrix *m1, const struct matrix *m2) {
    struct matrix *m;
    m = allocate_matrix(m1->rows, m2->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = 0;
            for (int k = 0; k < m1->cols; k++) {
                m->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    return m;
}

int main () {
    struct matrix *m1, *m2, *m;
    m1 = allocate_matrix(2,3);
    m2 = allocate_matrix(3,4);
    fill_matrix(m1);
    show_matrix(m1);
    fill_matrix(m2);
    show_matrix(m2);
    m = matrix_product(m1,m2);
    show_matrix(m);
    free_matrix(m1);
    free_matrix(m2);
    free_matrix(m);
}