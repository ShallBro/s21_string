#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  int flag = 0;
  for (int i = 0; i < (int)n; ++i) {
    char *a = (char *)str1;
    char *b = (char *)str2;
    if (flag == 0 && a[i] != b[i]) {
      res = a[i] - b[i];
      flag = 1;
    }
  }
  if (flag == 0) {
    res = 0;
  }

  return res;
}