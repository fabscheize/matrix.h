#include "../s21_matrix.h"

#include "s21_matrix_helpers.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int ret = k_ok;

  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * columns * sizeof(double) +
                                       rows * sizeof(double *));
    if (result->matrix != NULL) {
      double *pointer = (double *)(result->matrix + rows);
      for (int i = 0; i < rows; i++) result->matrix[i] = pointer + columns * i;
    } else {
      ret = k_calc_err;
    }
  } else {
    ret = k_calc_err;
  }

  return ret;
}

void s21_remove_matrix(matrix_t *A) { free(A->matrix); }

// int s21_eq_matrix(matrix_t *A, matrix_t *B) {}

// int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {}

// int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {}

// int s21_mult_number(matrix_t *A, double number, matrix_t *result) {}

// int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {}

// int s21_transpose(matrix_t *A, matrix_t *result) {}

// int s21_calc_complements(matrix_t *A, matrix_t *result) {}

// int s21_determinant(matrix_t *A, double *result) {}

// int s21_inverse_matrix(matrix_t *A, matrix_t *result) {}
