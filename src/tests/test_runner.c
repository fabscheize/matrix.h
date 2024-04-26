#include "test_suitecases.h"

int main(void) {
  int ret = 0;

  Suite *cases[] = {s21_create_matrix_suite(),
                    s21_eq_matrix_suite(),
                    s21_sum_matrix_suite(),
                    s21_sub_matrix_suite(),
                    s21_mult_number_suite(),
                    s21_mult_matrix_suite(),
                    s21_transpose_suite(),
                    s21_determinant_suite(),
                    s21_calc_complements_suite(),
                    s21_inverse_matrix_suite(),
                    NULL};

  for (Suite **current_testcase = cases; *current_testcase != NULL;
       current_testcase++) {
    ret = run_testcase(*current_testcase);
  }
  return ret;
}

int run_testcase(Suite *testcase) {
  putchar('\n');
  
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
