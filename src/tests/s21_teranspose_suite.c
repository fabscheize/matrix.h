#include "test_suitecases.h"

START_TEST(s21_transpose_1) {
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  matrix_t C = {0, 0, 0};
  double data_1[] = {1, 4, 2, 5, 3, 6};
  double data_2[] = {1, 2, 3, 4, 5, 6};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &C);
  fill_matrix(&A, data_1);
  fill_matrix(&C, data_2);
  int result = s21_transpose(&A, &B);
  ck_assert_int_eq(result, k_ok);
  result = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(result, k_equal);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

Suite *s21_transpose_suite() {
  Suite *s = suite_create("s21_transpose");
  TCase *tc1_1 = tcase_create("s21_transpose");

  tcase_add_test(tc1_1, s21_transpose_1);

  suite_add_tcase(s, tc1_1);
  return s;
}
