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
  for (int i = 0; i < A->rows * A->columns; i++) {
    A->matrix[0][i] = data[i];
  }
}

void duplicate_matrix(matrix_t* A, matrix_t* result) {
  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows * A->columns; i++) {
    result->matrix[0][i] = A->matrix[0][i];
  }
}

double minor(matrix_t* A, int row_to_delete, int column_to_delete) {
  double result = 0.0;
  matrix_t M = {0, 0, 0};
  s21_create_matrix(A->rows - 1, A->columns - 1, &M);

  for (int i = 0, m = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (i != row_to_delete && j != column_to_delete) {
        M.matrix[0][m++] = A->matrix[i][j];
      }
    }
  }

  s21_determinant(&M, &result);
  s21_remove_matrix(&M);

  return result;
}

double gauss_metod(double** matrix, int n) {
  double result = 1.0;

  for (int i = 0; i < n; i++) {
    int m = i;
    for (int j = i + 1; j < n; j++) {
      if (fabs(matrix[j][i]) > fabs(matrix[m][i])) {
        m = j;
      }
    }

    if (fabs(matrix[m][i]) < 1e-7) {
      result = 0.0;
      break;
    }

    if (i != m) {
      result = -result;
      for (int l = 0; l < n; l++) {
        double temp = matrix[i][l];
        matrix[i][l] = matrix[m][l];
        matrix[m][l] = temp;
      }
    }

    result *= matrix[i][i];

    for (int j = i + 1; j < n; j++) {
      if (fabs(matrix[j][i]) > 1e-7) {
        for (int k = i + 1; k < n; k++) {
          matrix[j][k] -=
              matrix[i][k] / matrix[i][i] * matrix[j][i];
        }
      }
    }
  }

  return result;
}
