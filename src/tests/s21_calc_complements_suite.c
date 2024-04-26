#include "test_suitecases.h"

START_TEST(s21_calc_complements_1) {
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  matrix_t C = {0, 0, 0};
  double data_1[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double data_2[] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  fill_matrix(&A, data_1);
  fill_matrix(&C, data_2);
  int result = s21_calc_complements(&A, &B);
  ck_assert_int_eq(result, k_ok);
  result = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(result, k_equal);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t A = {0, 0, 0};
  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 2, &A);
  int result = s21_calc_complements(&A, &B);
  ck_assert_int_eq(result, k_invalid_matrix);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_calc_complements_suite() {
  Suite *s = suite_create("s21_calc_complements");
  TCase *tc1_1 = tcase_create("s21_calc_complements");

  tcase_add_test(tc1_1, s21_calc_complements_1);
  tcase_add_test(tc1_1, s21_calc_complements_2);

  suite_add_tcase(s, tc1_1);
  return s;
}
