#include "test_suitecases.h"

START_TEST(s21_mult_matrix_1) {
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  matrix_t C = {0, 0, 0};
  matrix_t D = {0, 0, 0};
  double data_1[] = {1, 4, 2, 5, 3, 6};
  double data_2[] = {1, -1, 1, 2, 3, 4};
  double data_3[] = {9, 11, 17, 12, 13, 22, 15, 15, 27};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &D);
  fill_matrix(&A, data_1);
  fill_matrix(&B, data_2);
  fill_matrix(&D, data_3);
  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, k_ok);
  result = s21_eq_matrix(&C, &D);
  ck_assert_int_eq(result, k_equal);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  matrix_t C = {0, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 3, &B);
  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, k_calc_err);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_mult_matrix_suite() {
  Suite *s = suite_create("s21_mult_matrix");
  TCase *tc1_1 = tcase_create("s21_mult_matrix");

  tcase_add_test(tc1_1, s21_mult_matrix_1);
  tcase_add_test(tc1_1, s21_mult_matrix_2);

  suite_add_tcase(s, tc1_1);
  return s;
}
