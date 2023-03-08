#include "../s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  int p = (int)s21_strlen(dest);
  int i = 0;
  while (*src != '\0') {
    *(dest + p + i) = *src;
    i++;
    src++;
  };
  *(dest + p + i) = '\0';
  return dest;
}
