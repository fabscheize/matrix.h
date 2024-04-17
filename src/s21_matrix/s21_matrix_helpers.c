#include "s21_matrix_helpers.h"

void print_matrix(matrix_t A) {
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      printf("%10lf ", A.matrix[i][j]);
    }
    putchar('\n');
  }
}

void fill_matrix(matrix_t* A, double* data) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = data[i * A->columns + j];
    }
  }
}

void duplicate_matrix(matrix_t* A, matrix_t* result) {
  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j];
    }
  }
}

double minor(matrix_t* A, int row_to_delete, int column_to_delete) {
  double det = 0.0;
  matrix_t M = {0, 0, 0};
  s21_create_matrix(A->rows - 1, A->columns - 1, &M);

  for (int i = 0, minor_i = 0; i < A->rows; i++) {
    if (i != row_to_delete) {
      for (int j = 0, minor_j = 0; j < A->columns; j++) {
        if (j != column_to_delete) {
          M.matrix[minor_i][minor_j] = A->matrix[i][j];
          minor_j++;
        }
      }
      minor_i++;
    }
  }

  s21_determinant(&M, &det);
  s21_remove_matrix(&M);

  return det;
}
