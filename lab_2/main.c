#include <stdio.h>
#include "matrix.h"

int read_file(FILE *fin, matrix *matr, char *arg);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "there must be at least one argument\n");
        return -1;
    }
    int rows = 0;
    int cols = 0;
    for (int k = 1; k < argc; k++) {
        FILE *fin = fopen(argv[k], "r");
        if (fin == NULL) {
            fprintf(stderr, "error opening file: %s\n", argv[k]);
            fclose(fin);
            continue;
        }
        if (fscanf(fin, "%i", &rows) < 1 || fscanf(fin, "%i", &cols) < 1 ) {
            fprintf(stderr, "error reading file: %s\n", argv[k]);
            fclose(fin);
            continue;
        }
        matrix *matr = new_matrix(rows, cols);
        if (matr == NULL) {
            fprintf(stderr, "memory allocation error\n");
            return -1;
        }
        if (!read_file(fin, matr, argv[k])) {
            fprintf(stderr, "error reading file: %s\n", argv[k]);
            fclose(fin);
            free_matrix(matr);
            continue;
        }

        fclose(fin);
        double max = get_elem(matr, 0, 0);
        double sum = 0;
        for (int i = 0; i < rows; i++) {
            sum = 0;
            for (int j = 0; j < cols; j++) {
                sum += get_elem(matr, i, j);
            }
            if (max < sum)
                max = sum;
        }
        printf("%s: %f\n", argv[k], max);
        free_matrix(matr);
    }
}

int read_file(FILE *fin, matrix *matr, char *arg) {
    double num = 0;
    for (int i = 0; i < matr->rows; i++) {
        for (int j = 0; j < matr->cols; j++) {
            if (fscanf(fin, "%lg", &num) < 1) {
                fprintf(stderr, "error reading file: %s\n", arg);
                return 0;
            }
            set_elem(matr, i, j, num);
        }
    }
    return 1;
}