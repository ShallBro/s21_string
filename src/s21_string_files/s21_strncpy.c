#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  int save_i = 0;
  size_t i = 0;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  if (save_i == 0) save_i = i;
  if (src[i] == '\0') dest[i] = '\0';
  return dest;
}
