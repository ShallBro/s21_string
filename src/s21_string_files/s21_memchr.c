#include "../s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  char *ans = NULL;
  char *p = (char *)str;
  for (int i = 0; i < (int)n; ++i) {
    if (*p == c) {
      ans = p;
      break;
    }
    p++;
  }

  return (void *)ans;
}
