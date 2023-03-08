#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *from = (char *)str;
  for (int i = 0; i < (int)n; ++i) {
    from[i] = (char)c;
  }
  return str;
}