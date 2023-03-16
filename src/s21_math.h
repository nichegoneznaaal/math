#ifndef S21_MATH_H
#define S21_MATH_H

#include <limits.h>  // для LONG_MIN и LONG_MAX
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#define S21_EPS 1e-308
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_MINF -1.0 / 0.0
#define S21_PI 3.14159265358979323846
#define S21_EXP 2.7182818284590452353602874
#define DBL_MAX __DBL_MAX__

typedef struct BitPattern {
  uint64_t mnt : 52;
  uint64_t exp : 11;
  uint64_t sgn : 1;
} BitPattern;

typedef union Bit {
  double x;
  BitPattern pat;
} Bit;

//----------------------------------------------------------------------
int s21_is_nan(double x);
//----------------------------------------------------------------------

long double s21_floor(double x);
int s21_abs(int x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_exp(double x);
long double s21_log(double x);  // реализация через метод Галлея
long double s21_sqrt(double x);  // реализация через алгоритм Герона
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_pow(double base, double exp);
long double s21_ceil(double x);

#endif  // S21_MATH_H
