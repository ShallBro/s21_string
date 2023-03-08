#include "../s21_string.h"

size_t s21_strspn(const char *str1, const char *str2) {
  const char *p;
  for (p = str1; *p != '\0'; ++p) {
    if (!s21_strchr(str2, *p)) break;
  }
  return p - str1;
}
