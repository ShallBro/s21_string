#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *result = dest;

  if (n > 0) {
    while (*dest != '\0') {
      dest++;
    }
    while ((*(dest++) = *(src++)) != 0) {
      n--;
      if (n == 0) {
        *dest = '\0';
        break;
      }
    }
  }
  return result;
}