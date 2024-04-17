#include "../s21_matrix.h"

#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix_helpers.h"

enum retutn_values { k_ok, k_invalid_matrix, k_calc_err };
enum comparison { k_not_equal, k_equal };

// static int is_valid_matrix(matrix_t *A) {
//   return (A->rows > 0 && A->columns > 0 && A->matrix != NULL);
// }
// if (!is_valid_matrix(&A) || !is_valid_matrix(&B)) return k_invalid_matrix;

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

void s21_remove_matrix(matrix_t *A) {
  // if (is_valid_matrix(&A))
  free(A->matrix);
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ret = k_equal;

  if (A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows && ret == k_equal; i++) {
      for (int j = 0; j < A->columns && ret == k_equal; j++) {
        ret = A->matrix[i][j] == B->matrix[i][j];
      }
    }
  } else {
    ret = k_not_equal;
  }

  return ret;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = k_ok;

  if (A->rows == B->rows && A->columns == B->columns) {
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  } else {
    ret = k_calc_err;
  }

  return ret;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = k_ok;

  if (A->rows == B->rows && A->columns == B->columns) {
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  } else {
    ret = k_calc_err;
  }

  return ret;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int ret = k_ok;
  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return ret;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = k_ok;

  if (A->columns == B->rows) {
    int m = A->rows;
    int l = A->columns;
    int n = B->columns;
    s21_create_matrix(m, n, result);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < l; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  } else {
    ret = k_calc_err;
  }

  return ret;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int ret = k_ok;
  s21_create_matrix(A->columns, A->rows, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return ret;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int ret = k_ok;

  if (A->rows == A->columns) {
    s21_create_matrix(A->columns, A->rows, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = minor(A, i, j) * pow(-1, i + j);
      }
    }
  } else {
    ret = k_invalid_matrix;
  }
  return ret;
}

int s21_determinant(matrix_t *A, double *result) {
  if (A->rows != A->columns) return k_invalid_matrix;

  int n = A->rows;
  matrix_t A_copy = {0, 0, 0};
  duplicate_matrix(A, &A_copy);
  *result = 1.0;

  for (int i = 0; i < n; i++) {
    int m = i;
    for (int j = i + 1; j < n; j++) {
      if (fabs(A_copy.matrix[j][i]) > fabs(A_copy.matrix[m][i])) {
        m = j;
      }
    }

    if (fabs(A_copy.matrix[m][i]) < 1e-7) {
      *result = 0.0;
      break;
    }

    if (i != m) {
      *result = -*result;
      for (int l = 0; l < n; l++) {
        double temp = A_copy.matrix[i][l];
        A_copy.matrix[i][l] = A_copy.matrix[m][l];
        A_copy.matrix[m][l] = temp;
      }
    }

    *result *= A_copy.matrix[i][i];

    for (int j = i + 1; j < n; j++) {
      if (fabs(A_copy.matrix[j][i]) > 1e-7) {
        for (int k = i + 1; k < n; k++) {
          A_copy.matrix[j][k] -=
              A_copy.matrix[i][k] / A_copy.matrix[i][i] * A_copy.matrix[j][i];
        }
      }
    }
  }

  s21_remove_matrix(&A_copy);
  return *result;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A->rows != A->columns) return k_invalid_matrix;

  int ret = k_ok;
  double det = 0.0;
  s21_determinant(A, &det);

  if (fabs(det) > 1e-7) {
    matrix_t M = {0, 0, 0};
    matrix_t M_T = {0, 0, 0};
    s21_create_matrix(A->rows, A->columns, result);
    s21_calc_complements(A, &M);
    s21_transpose(&M, &M_T);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = M_T.matrix[i][j] / det;
      }
    }
    s21_remove_matrix(&M_T);
    s21_remove_matrix(&M);
  } else {
    ret = k_calc_err;
  }

  return ret;
}
