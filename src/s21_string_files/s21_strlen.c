#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t size = 0;
  const char *p = str;
  while (*p != '\0') {
    size++;
    p++;
  };
  return size;
}
