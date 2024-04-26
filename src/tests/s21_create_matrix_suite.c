#include "test_suitecases.h"

START_TEST(s21_create_matrix_1) {
  matrix_t A = {0, 0, 0};
  int result = s21_create_matrix(100, 100, &A);
  ck_assert_int_eq(result, k_ok);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t A = {0, 0, 0};
  int result = s21_create_matrix(0, 100, &A);
  ck_assert_int_eq(result, k_invalid_matrix);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t A = {0, 0, 0};
  int result = s21_create_matrix(100, 0, &A);
  ck_assert_int_eq(result, k_invalid_matrix);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t A = {0, 0, 0};
  int result = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(result, k_invalid_matrix);
}
END_TEST

Suite *s21_create_matrix_suite() {
  Suite *s = suite_create("s21_create_matrix");
  TCase *tc1_1 = tcase_create("s21_create_matrix");

  tcase_add_test(tc1_1, s21_create_matrix_1);
  tcase_add_test(tc1_1, s21_create_matrix_2);
  tcase_add_test(tc1_1, s21_create_matrix_3);
  tcase_add_test(tc1_1, s21_create_matrix_4);

  suite_add_tcase(s, tc1_1);
  return s;
}
