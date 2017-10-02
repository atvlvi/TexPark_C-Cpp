//
// Created by views on 02.10.2017.
//

#ifndef LAB_2_MATRIX_H
#define LAB_2_MATRIX_H

typedef struct matrix{
    double** data;
    int rows;
    int cols;
} matrix;

double get_elem(matrix *matr, int row, int col);
void set_elem(matrix *matr, int row, int col, double elem);
matrix *new_matrix(int rows, int cols);
void free_matrix(matrix *matr);

#endif //LAB_2_MATRIX_H