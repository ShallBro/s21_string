#include "test_me.h"

START_TEST(sscanf_spec_c_1) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_2) {
  char format[] = "%c";
  char str[] = "\t\n\n   \n  \ta";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_3) {
  char format[] = "%c%c%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_4) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  1    2 3 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_5) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_6) {
  char format[] = "%c %*c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c21, c22;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12);
  int16_t res2 = sscanf(str, format, &c21, &c22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
}
END_TEST

START_TEST(sscanf_spec_c_7) {
  char str1[] = "%4c%2c";
  char str[] = "abcdefge";
  char a1[100] = "", a2[100] = "";
  char b1[100] = "", b2[100] = "";
  int res1 = s21_sscanf(str, str1, &a1, &b1);
  int res2 = sscanf(str, str1, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_spec_s_1) {
  char a1[100] = "", b1[100] = "", c1[100] = "", d1[100] = "";
  char a2[100] = "", b2[100] = "", c2[100] = "", d2[100] = "";
  const char str[] = "gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address";
  const char str1[] = "%s%s%s%s";
  int res1 = s21_sscanf(str, str1, a1, b1, c1, d1);
  int res2 = sscanf(str, str1, a2, b2, c2, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_s_2) {
  char a1[100] = "", b1[100] = "", c1[100] = "", d1[100] = "";
  char a2[100] = "", b2[100] = "", c2[100] = "", d2[100] = "";
  const char str[] = "gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address";
  const char str1[] = "%2s%3s%4s%5s";
  int res1 = s21_sscanf(str, str1, a1, b1, c1, d1);
  int res2 = sscanf(str, str1, a2, b2, c2, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_s_3) {
  char a1[100] = "", b1[100] = "", c1[100] = "", d1[100] = "";
  char a2[100] = "", b2[100] = "", c2[100] = "", d2[100] = "";
  const char str[] = "gcc \n-Wall \n-Wextra \n-Werror \n-std=c11";
  const char str1[] = "%5s%4s%3s%2s";
  int res1 = s21_sscanf(str, str1, a1, b1, c1, d1);
  int res2 = sscanf(str, str1, a2, b2, c2, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_s_4) {
  char a1[100] = "", b1[100] = "", c1[100] = "";
  char a2[100] = "", b2[100] = "", c2[100] = "";
  const char str[] = "gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address";
  const char str1[] = "%*s%*s%*s%s%s%s";
  int res1 = s21_sscanf(str, str1, a1, b1, c1);
  int res2 = sscanf(str, str1, a2, b2, c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_s_5) {
  char a1[100] = "", b1[100] = "", c1[100] = "", d1[100] = "";
  char a2[100] = "", b2[100] = "", c2[100] = "", d2[100] = "";
  const char str[] = "gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address";
  const char str1[] = "%*s%*s%*s%1s%1s%5s%5s";
  int res1 = s21_sscanf(str, str1, a1, b1, c1, d1);
  int res2 = sscanf(str, str1, a2, b2, c2, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
  ck_assert_str_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_s_6) {
  char str1[] = "%d%c%s%2d";
  char str[] = "-999 abcdef +22";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, e1 = 0, e2 = 0;
  char c1[100] = "", c2[100] = "";
  int res1 = s21_sscanf(str, str1, &a1, &b1, c1, &e1);
  int res2 = sscanf(str, str1, &a2, &b2, c2, &e2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_str_eq(c1, c2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(sscanf_spec_s_7) {
  char str1[] = "%5s%s";
  char str[] = "abcdef ge";
  char a1[100] = "", a2[100] = "";
  char b1[100] = "", b2[100] = "";
  int res1 = s21_sscanf(str, str1, &a1, &b1);
  int res2 = sscanf(str, str1, &a2, &b2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
}
END_TEST

Suite *test_sscanf_c(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_C=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_c_1);
  tcase_add_test(tc, sscanf_spec_c_2);
  tcase_add_test(tc, sscanf_spec_c_3);
  tcase_add_test(tc, sscanf_spec_c_4);
  tcase_add_test(tc, sscanf_spec_c_5);
  tcase_add_test(tc, sscanf_spec_c_6);
  tcase_add_test(tc, sscanf_spec_c_7);

  tcase_add_test(tc, sscanf_spec_s_1);
  tcase_add_test(tc, sscanf_spec_s_2);
  tcase_add_test(tc, sscanf_spec_s_3);
  tcase_add_test(tc, sscanf_spec_s_4);
  tcase_add_test(tc, sscanf_spec_s_5);
  tcase_add_test(tc, sscanf_spec_s_6);
  tcase_add_test(tc, sscanf_spec_s_7);

  suite_add_tcase(s, tc);
  return s;
}