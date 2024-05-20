#include <stdio.h>
#include <stdlib.h>

struct matrix {
    size_t rows, cols;
    int **data;
};

int matrix_compare(const struct matrix *m1, const struct matrix *m2) {
    if ((m1->rows != m2->rows) || (m1->cols != m2->cols)) return 1;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            if (m1->data[i][j] != m2->data[i][j]) return 1;
        }
    }
    return 0;
}

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



int main () {
    struct matrix *m1, *m2;
    m1 = allocate_matrix(2,2);
    m2 = allocate_matrix(2,2);
    fill_matrix(m1);
    show_matrix(m1);
    fill_matrix(m2);
    show_matrix(m2);
    printf("%d", matrix_compare(m1,m2));
}