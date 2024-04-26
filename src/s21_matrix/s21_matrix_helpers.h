#ifndef S21_MATRIX_HELPERS_H_
#define S21_MATRIX_HELPERS_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

enum retutn_values { k_ok, k_invalid_matrix, k_calc_err };
enum comparison { k_not_equal, k_equal };

void print_matrix(matrix_t A);
void fill_matrix(matrix_t* A, double* data);
void duplicate_matrix(matrix_t* A, matrix_t* result);
double calc_minor(matrix_t* A, int row, int column);
double gauss_metod(double** matrix, int n);

#endif  // S21_MATRIX_HELPERS_H_
