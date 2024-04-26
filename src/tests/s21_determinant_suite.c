#include "test_suitecases.h"

START_TEST(s21_determinant_1) {
  matrix_t A = {0, 0, 0};
  double data_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double det = 0.0;
  s21_create_matrix(3, 3, &A);
  fill_matrix(&A, data_1);
  int result = s21_determinant(&A, &det);
  ck_assert_int_eq(result, k_ok);
  ck_assert_int_eq(det == 0, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t A = {0, 0, 0};
  double data_1[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double det = 0.0;
  s21_create_matrix(3, 3, &A);
  fill_matrix(&A, data_1);
  int result = s21_determinant(&A, &det);
  ck_assert_int_eq(result, k_ok);
  ck_assert_int_eq(det == -40, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t A = {0, 0, 0};
  double det = 0.0;
  s21_create_matrix(3, 2, &A);
  int result = s21_determinant(&A, &det);
  ck_assert_int_eq(result, k_invalid_matrix);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_suite() {
  Suite *s = suite_create("s21_determinant");
  TCase *tc1_1 = tcase_create("s21_determinant");

  tcase_add_test(tc1_1, s21_determinant_1);
  tcase_add_test(tc1_1, s21_determinant_2);
  tcase_add_test(tc1_1, s21_determinant_3);

  suite_add_tcase(s, tc1_1);
  return s;
}
