#include "test_suitecases.h"

START_TEST(s21_eq_matrix_1) {
#line 4
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  double data_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9.0000001};
  double data_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9.00000009};
  fill_matrix(&A, data_1);
  fill_matrix(&B, data_2);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, k_equal);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
#line 18
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  double data_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double data_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9.00000009};
  fill_matrix(&A, data_1);
  fill_matrix(&B, data_2);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, k_not_equal);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
#line 32
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 4, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, k_not_equal);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
#line 42
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(4, 3, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, k_not_equal);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_eq_matrix_suite() {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc1_1 = tcase_create("s21_eq_matrix");

  tcase_add_test(tc1_1, s21_eq_matrix_1);
  tcase_add_test(tc1_1, s21_eq_matrix_2);
  tcase_add_test(tc1_1, s21_eq_matrix_3);
  tcase_add_test(tc1_1, s21_eq_matrix_4);

  suite_add_tcase(s, tc1_1);
  return s;
}
