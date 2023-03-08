#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL) return S21_NULL;
  char trim_chars_tmp[512];
  if (trim_chars != NULL && s21_strlen(trim_chars) != 0) {
    s21_strcpy(trim_chars_tmp, trim_chars);
  } else {
    s21_strcpy(trim_chars_tmp, "\t\n\v\r\f ");
  };
  s21_size_t src_len = s21_strlen(src);
  char *str_new = (char *)malloc(sizeof(char) * (src_len + 1));
  s21_size_t ind_bgn = s21_strspn(src, trim_chars_tmp);
  s21_size_t ind_end = src_len;

  char *src_tmp = (char *)src + ind_end;
  char *src_end = src_tmp;

  while (src_tmp == src_end) {
    src_tmp--;
    src_end = s21_strpbrk(src_tmp, trim_chars_tmp);
    if (src_end == NULL) src_end = src_tmp + 1;
    if (src_tmp != src_end) break;
  };

  if (ind_end != ind_bgn) ind_end = src_tmp - src;

  int i = 0;
  while (ind_bgn <= ind_end) {
    *(str_new + i) = src[ind_bgn];
    ind_bgn++;
    i++;
  };
  if (src_len > 1) {
    *(str_new + i) = '\0';
  } else {
    *str_new = '\0';
  }

  return (void *)str_new;
}