#include "test_me.h"

START_TEST(sscanf_spec_pr_1) {
  char fstr[] = "%d%d%%%d%d";
  char str[] = "11111 22222% 333 33";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_pr_2) {
  char str1[] = "%d.%d %d%%";
  char str[] = "  12321.999  -111%   \n";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  int res1 = s21_sscanf(str, str1, &a1, &b1, &c1);
  int res2 = sscanf(str, str1, &a2, &b2, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_pr_3) {
  char str1[] = "%c%c%c%%%c";
  char str[] = "ABC%DEFGH";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int res1 = s21_sscanf(str, str1, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, str1, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

Suite *test_sscanf_pr(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_%=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_pr_1);
  tcase_add_test(tc, sscanf_spec_pr_2);
  tcase_add_test(tc, sscanf_spec_pr_3);

  suite_add_tcase(s, tc);
  return s;
}