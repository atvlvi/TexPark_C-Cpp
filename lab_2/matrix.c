//
// Created by views on 02.10.2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

double get_elem(matrix *matr, int row, int col) {
    if (col < matr->cols && row < matr->rows)
        return matr->data[row][col];
    return 0;
}

void set_elem(matrix *matr, int row, int col, double elem) {
    if (col < matr->cols && row < matr->rows)
        matr->data[row][col] = elem;
}

static void _free_matrix(matrix *matr, int i) {
    for (; i >= 0; i--) {
        free(matr->data[i]);
    }
    free(matr->data);
    free(matr);
}

matrix *new_matrix(int rows, int cols) {
    matrix *out = malloc(sizeof(matrix));
    if (out == NULL)
        return NULL;
    out->rows = rows;
    out->cols = cols;
    out->data = calloc((size_t)rows, sizeof(double *));
    if (out->data == NULL) {
        free(out);
        return  NULL;
    }
    int i = 0;
    for (; i < rows; i++) {
        out->data[i] = calloc((size_t)cols, sizeof(double));
        if (out->data[i] == NULL)
            break;
    }
    if (i < rows) {
        _free_matrix(out, i);
        return NULL;
    }
    return out;
}

void free_matrix(matrix *matr) {
    _free_matrix(matr, matr->rows-1);
}