
#include "../s21_string.h"
char *s21_strtok(char *str, const char *delim) {
  int str_ind = 0;
  static int ret_ind;
  static char *str_cash = NULL;
  static int first_time;
  if (str == S21_NULL && first_time == 0) {
    return S21_NULL;
  };
  if (str_cash == NULL && str == S21_NULL) {
    return S21_NULL;
  }
  first_time = 1;

  if (str != S21_NULL) {
    ret_ind = 0;
    str_cash = S21_NULL;
    str_cash = str;
  };
  if (str == S21_NULL) {
    str = str_cash;
  };

  while (str[str_ind] != '\0') {
    int delim_ind = 0;
    int match_count = 0;
    while (delim[delim_ind] != '\0') {
      if (str[str_ind] == delim[delim_ind]) {
        match_count++;
        break;
      };
      delim_ind++;
    };
    if (match_count == 0) break;
    str_ind++;
  };

  if ((int)s21_strlen(str) == str_ind) {
    str_cash = NULL;
    return S21_NULL;
  }
  ret_ind = str_ind;

  while (str[str_ind] != '\0') {
    int delim_ind = 0;
    int match = 0;
    while (delim_ind <= (int)s21_strlen(delim) && delim[delim_ind] != '\0') {
      if (str[str_ind] == delim[delim_ind]) {
        str[str_ind] = '\0';
        match++;
        break;
      };
      delim_ind++;
    }
    str_ind++;
    if (match == 1) break;
  }
  if (str[ret_ind] == '\0') return S21_NULL;
  str_cash = &str[str_ind];
  return &str[ret_ind];
}