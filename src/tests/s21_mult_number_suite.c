#include "test_suitecases.h"

START_TEST(s21_mult_number_1) {
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  matrix_t C = {0, 0, 0};
  double data_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double data_2[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  fill_matrix(&A, data_1);
  fill_matrix(&C, data_2);
  int result = s21_mult_number(&A, 2, &B);
  ck_assert_int_eq(result, k_ok);
  result = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(result, k_equal);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

Suite *s21_mult_number_suite() {
  Suite *s = suite_create("s21_mult_number");
  TCase *tc1_1 = tcase_create("s21_mult_number");

  tcase_add_test(tc1_1, s21_mult_number_1);

  suite_add_tcase(s, tc1_1);
  return s;
}
