#include "../s21_string.h"
int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;
  int flag = 1;
  while (*str1 == *str2 && flag == 1) {
    if (*str1 == '\0' && *str2 == '\0') {
      flag = 0;
    } else {
      str1++;
      str2++;
    }
  }
  res = *str1 - *str2;
  if (flag == 0) {
    res = flag;
  }
  return res;
}
