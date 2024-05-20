#include <stdio.h>
#include <stdlib.h>

struct matrix {
    size_t rows, cols;
    int *data;
};

struct matrix *matrix_product(const struct matrix *m1, const struct matrix *m2) {
    if (m1->cols != m2->rows) return NULL;
    struct matrix *m;
    m = malloc(sizeof(*m));
    m->rows = m1->rows;
    m->cols = m2->cols;
    m->data = malloc(m->rows * m->cols * sizeof(*(m->data)));
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            for (int h = 0; h < m1->cols; h++) {
                double n1 = m1->data[i * m1->cols + h];
                double n2 = m2->data[h * m2->cols + j];
                m->data[i * m->cols + j] += n1 * n2;
            }
        }
    }
    return m;
}

void show_matrix (const struct matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%3d", m->data[i*m->cols+j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main () {
    int values1[2*3] = {1,2,3,4,5,6};
    int values2[3*4] = {0,0,2,4,5,0,1,4,5,2,1,5};
    struct matrix mat1 = {
            .rows = 2,
            .cols = 3,
            .data = values1
    };
    struct matrix mat2 = {
            .rows = 3,
            .cols = 4,
            .data = values2
    };
    struct matrix *product;
    product = matrix_product(&mat1, &mat2);
    printf("prima matrice\n");
    show_matrix(&mat1);
    printf("seconda matrice\n");
    show_matrix(&mat2);
    printf("prodotto\n");
    show_matrix(product);
}
