#include "../s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t count = 0;
  int flag = 0;
  while (*str1 != '\0' && flag == 0) {
    const char *str_tmp = str2;
    while (*str_tmp != '\0') {
      if (*str1 != *str_tmp) {
        flag = 0;
        str_tmp++;
      } else {
        flag = 1;
        break;
      }
    }
    str1++;
    if (flag == 1) break;
    count++;
  }
  return count;
}
