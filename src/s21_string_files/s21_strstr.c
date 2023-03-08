#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') return (char *)haystack;
  int i = 0;
  while (haystack[i] != '\0') {
    int j = 0;
    int k = i;
    while (needle[j] != '\0' || haystack[k] != '\0') {
      if (needle[j] != haystack[k]) break;
      k++;
      j++;
    }
    if (needle[j] == '\0') return (char *)haystack + i;
    i++;
  }
  return S21_NULL;
}