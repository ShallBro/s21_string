#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) return S21_NULL;
  s21_size_t n = s21_strlen(str);
  char *str_copy = (char *)malloc((n + 1) * sizeof(char));
  if (str_copy == S21_NULL) return S21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if ((str[i] > 64) && (str[i] < 91)) {
      str_copy[i] = str[i] + 32;
    } else {
      str_copy[i] = str[i];
    }
  }
  str_copy[n] = '\0';
  return (void *)str_copy;
}