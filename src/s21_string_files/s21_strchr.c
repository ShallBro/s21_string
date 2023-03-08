#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *p = str;
  char *result = NULL;

  while (*p != '\0') {
    if ((int)(*p) == c) {
      result = (char *)p;
      break;
    }
    p++;
  }
  if (c == '\0') {
    result = (char *)p;
  }
  return result;
}
