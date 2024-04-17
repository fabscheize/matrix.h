#ifndef S21_MATRIX_HELPERS_H_
#define S21_MATRIX_HELPERS_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_matrix.h"

void print_matrix(matrix_t A);
void fill_matrix(matrix_t* A, double* data);
void duplicate_matrix(matrix_t* A, matrix_t* result);
double minor(matrix_t* A, int row, int column);

#endif  // S21_MATRIX_HELPERS_H_
