#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t i = 0;
  s21_size_t src_ind = 0;
  if (str == S21_NULL || src == S21_NULL) return S21_NULL;
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);
  if (src_len < start_index) return S21_NULL;

  char *src_new = (char *)malloc(sizeof(char) * (src_len + str_len + 1));
  if (src_new == S21_NULL) return S21_NULL;
  while (i < start_index) {
    src_new[i] = src[i];
    i++;
    src_ind++;
  };
  while (*str != '\0') {
    src_new[i] = *str;
    str++;
    i++;
  };
  while (src[src_ind] != '\0') {
    src_new[i] = src[src_ind];
    i++;
    src_ind++;
  };
  src_new[i] = '\0';
  return (void *)src_new;
}