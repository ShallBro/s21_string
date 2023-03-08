#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_

#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"
#include "specificators/sub_func.h"

#define SPACES " \t\n\v"

long long int s21_atoi(char *str);
int isNumber(char c);
int s21_sscanf(const char *str, const char *format, ...);
int s21_switch_scan_spec(Prototype *prot, const char *format, const char *str,
                         int *j, va_list args, int space_counter_for_n);
int s21_scanf_spec_d(Prototype *prot, const char *str, char *buff_str,
                     va_list args, int width_counter, int *j);
int s21_scanf_spec_c(Prototype *prot, const char *str, char *buff_str,
                     va_list args, int *j);
int s21_scanf_spec_s(Prototype *prot, const char *str, va_list args,
                     char *buff_str, int width_counter, int *j);
void s21_scanf_spec_n(va_list args, int *j, int space_counter_for_n);

int s21_read_format_scanf(Prototype *prot, const char *format, int i);
void s21_check_width_scanf(const char *format, int i, int *this_is_width,
                           Prototype *prot);
void s21_check_flags_scanf(const char *format, int i, Prototype *prot,
                           int *this_is_prec, int *this_is_width);
bool s21_check_number_scanf(const char *format, int i);
int s21_write_number_scanf(const char *format, int *i);

#endif  // SRC_S21_SSCANF_H_