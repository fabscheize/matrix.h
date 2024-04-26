#include "test_suitecases.h"

START_TEST(s21_inverse_matrix_1) {
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  double data_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_create_matrix(3, 3, &A);
  fill_matrix(&A, data_1);
  int result = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(result, k_calc_err);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  matrix_t C = {0, 0, 0};
  double data_1[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double data_2[] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  fill_matrix(&A, data_1);
  fill_matrix(&C, data_2);
  int result = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(result, k_ok);
  result = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(result, k_equal);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 4, &A);
  int result = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(result, k_invalid_matrix);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_inverse_matrix_suite() {
  Suite *s = suite_create("s21_inverse_matrix");
  TCase *tc1_1 = tcase_create("s21_inverse_matrix");

  tcase_add_test(tc1_1, s21_inverse_matrix_1);
  tcase_add_test(tc1_1, s21_inverse_matrix_2);
  tcase_add_test(tc1_1, s21_inverse_matrix_3);

  suite_add_tcase(s, tc1_1);
  return s;
}
