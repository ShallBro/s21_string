#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  char c;
  int records = 0;
  va_list args;
  va_start(args, format);
  int i = 0;
  int j = 0;

  while ((c = format[i]) != '\0') {
    if (c != '%') {
      if (s21_strchr(SPACES, c) != NULL) {
        while (s21_strchr(SPACES, str[j]) != NULL) {
          j++;
        }
      } else if (str[j] == format[i]) {
        j++;
      } else {
        exit(EXIT_FAILURE);
      };
      i++;
      continue;
    };

    if (format[i + 1] == '%') {
      i++;
      if (str[j] == '%') {
        i++;
        j++;
        continue;
      } else {
        exit(EXIT_FAILURE);
      }
    };

    Prototype prot = {'\0', 0, 0, 0, 0, 0, 0, 0, -1, -1, '\0'};
    i = s21_read_format_scanf(&prot, format, i);
    int space_counter_for_n = 0;
    if (prot.spec != 'c') {
      while (s21_strchr(SPACES, str[j]) != NULL) {
        space_counter_for_n++;
        j++;
      }
    };

    records +=
        s21_switch_scan_spec(&prot, format, str, &j, args, space_counter_for_n);

    i++;
  };
  va_end(args);
  return records;
}

int s21_switch_scan_spec(Prototype *prot, const char *format, const char *str,
                         int *j, va_list args, int space_counter_for_n) {
  int width_counter = 0;
  int write_count = 0;
  char buff_str[4096] = {'\0'};
  format++;
  if (prot->width_number > 0) {
    width_counter = prot->width_number;
  } else {
    width_counter = INT_MAX;
  }
  switch (prot->spec) {
    case 'd':
      write_count +=
          s21_scanf_spec_d(prot, str, buff_str, args, width_counter, j);
      *j += s21_strlen(buff_str);
      break;

    case 'c':
      write_count += s21_scanf_spec_c(prot, str, buff_str, args, j);
      *j += s21_strlen(buff_str);
      break;

    case 's':
      write_count +=
          s21_scanf_spec_s(prot, str, args, buff_str, width_counter, j);
      *j += s21_strlen(buff_str);

      break;

    case 'n':
      s21_scanf_spec_n(args, j, space_counter_for_n);
      break;
  };
  return write_count;
}

void s21_scanf_spec_n(va_list args, int *j, int space_counter_for_n) {
  int *p_args = NULL;
  p_args = va_arg(args, int *);
  *p_args = *j - space_counter_for_n;
}

int s21_scanf_spec_s(Prototype *prot, const char *str, va_list args,
                     char *buff_str, int width_counter, int *j) {
  char *p_args = NULL;
  int k = 0;
  int ret = 1;
  if (prot->width_star != '*') p_args = va_arg(args, char *);
  while (k < width_counter && s21_strchr(SPACES, str[*j + k]) == NULL) {
    buff_str[k] = str[*j + k];
    if (prot->width_star != '*') *(p_args + k) = str[*j + k];
    k++;
  };
  if (prot->width_star == '*') ret = 0;
  return ret;
}

int s21_scanf_spec_c(Prototype *prot, const char *str, char *buff_str,
                     va_list args, int *j) {
  char *p_args = NULL;
  int k = 0;

  if (prot->width_star != '*') p_args = va_arg(args, char *);
  if (prot->width_number <= 1) {
    buff_str[k] = str[*j + k];
    if (prot->width_star != '*') {
      *p_args = str[*j];
      k++;
    }
  } else {
    while (k < prot->width_number) {
      buff_str[k] = str[*j + k];
      if (prot->width_star != '*') {
        *(p_args + k) = str[*j + k];
      };
      k++;
    };
    k = 1;
  };
  return k;
}

int s21_scanf_spec_d(Prototype *prot, const char *str, char *buff_str,
                     va_list args, int width_counter, int *j) {
  void *p_args = NULL;
  int k = 0;
  int write_count = 0;
  long long int numb = 0;
  if (prot->width_star != '*') p_args = va_arg(args, int *);
  if (str[*j + k] == '-' || str[*j + k] == '+') {
    buff_str[k] = str[*j + k];
    k++;
  };
  while (k < width_counter && s21_strchr(SPACES, str[*j + k]) == NULL) {
    if (isNumber(str[*j + k])) {
      buff_str[k] = str[*j + k];
    } else {
      if (k == 0) return -1;
      break;
    };
    k++;
  }

  numb = s21_atoi(buff_str);
  if (prot->length == 'l' && numb > LONG_MAX) numb = LONG_MAX;
  if (prot->width_star != '*') {
    *(int *)p_args = numb;
    write_count = 1;
  };
  return write_count;
}

long long int s21_atoi(char *str) {
  long long int res = 0;
  int i = 0;
  int sign = 0;
  if (str[i] == 45) {
    i++;
    sign = 1;
  } else if (str[i] == '+') {
    i++;
  };
  for (int k = i; str[k] != '\0'; k++) {
    res = res * 10;
    res = res + str[k] - '0';
  };
  if (sign == 1) res = res * (-1);
  return res;
}

int isNumber(char c) {
  int res = 0;
  if (c > 47 && c < 58) res = 1;
  return res;
}

int s21_read_format_scanf(Prototype *prot, const char *format, int i) {
  int this_is_width = 0;
  int this_is_prec = 0;
  i++;
  while (format[i]) {
    s21_check_flags_scanf(format, i, prot, &this_is_prec, &this_is_width);
    s21_check_width_scanf(format, i, &this_is_width, prot);
    if (format[i] == 'h') {
      prot->length = format[i];
    } else if (format[i] == 'l') {
      prot->length = format[i];
    } else if (format[i] == 'L') {
      prot->length = format[i];
    }
    // Check spec
    if (format[i] == 'c' || format[i] == 'd' || format[i] == 'i' ||
        format[i] == 'o' || format[i] == 's' || format[i] == 'p' ||
        format[i] == 'n' || format[i] == '%')
      prot->spec = format[i];
    if (prot->spec == format[i])
      break;
    else
      i++;
  }
  return i;
}

void s21_check_width_scanf(const char *format, int i, int *this_is_width,
                           Prototype *prot) {
  if (s21_check_number_scanf(format, i) == true && *this_is_width == 0) {
    prot->width_number = s21_write_number_scanf(format, &i);
    *this_is_width = 1;
  } else if (prot->width_number == 0 && format[i] == '*' &&
             *this_is_width == 0) {
    prot->width_star = '*';
    *this_is_width = 1;
  }
}

void s21_check_flags_scanf(const char *format, int i, Prototype *prot,
                           int *this_is_prec, int *this_is_width) {
  if (format[i] == '+') {
    prot->plus_flag = 1;
  } else if (format[i] == '-') {
    prot->minus_flag = 1;
  } else if (format[i] == ' ') {
    prot->space_flag = 1;
  } else if (format[i] == '0' && *this_is_prec == 0 && *this_is_width == 0) {
    prot->zero_flag = 1;
  }
}

bool s21_check_number_scanf(const char *format, int i) {
  bool result = false;
  if (format[i] >= '0' && format[i] <= '9') result = true;
  return result;
}

int s21_write_number_scanf(const char *format, int *i) {
  int width = 0;
  width += format[*i] - '0';
  *i += 1;
  while (s21_check_number_scanf(format, *i) == true) {
    width *= 10;
    width += format[*i] - '0';
    *i += 1;
  }
  return width;
}
