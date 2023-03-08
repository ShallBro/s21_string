#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  size_t i = 0;
  while (i < n) {
    *(char *)(dest + i) = *(char *)(src + i);
    i++;
  }
  return dest;
}