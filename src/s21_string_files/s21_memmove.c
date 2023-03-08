#include "../s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *from = (char *)src;
  char *to = (char *)dest;
  for (int i = 0; i < (int)n; ++i) {
    to[i] = from[i];
  }

  return dest;
}