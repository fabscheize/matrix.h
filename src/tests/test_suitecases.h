#ifndef TEST_SUITECASES_H_
#define TEST_SUITECASES_H_

#include <check.h>

#include "../s21_matrix/s21_matrix_helpers.h"

Suite *s21_create_matrix_suite(void);
Suite *s21_eq_matrix_suite(void);
Suite *s21_sum_matrix_suite(void);
Suite *s21_sub_matrix_suite(void);
Suite *s21_mult_number_suite(void);
Suite *s21_mult_matrix_suite(void);
Suite *s21_transpose_suite(void);
Suite *s21_determinant_suite(void);
Suite *s21_calc_complements_suite(void);
Suite *s21_inverse_matrix_suite(void);

int run_testcase(Suite *testcase);

#endif  // TEST_SUITECASES_H_
