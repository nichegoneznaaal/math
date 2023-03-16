
#include <check.h>
#include <math.h>
#include <stdio.h>

#include "s21_math.h"

#define PI_6 S21_M_PI_2 / 3
#define PI_56 S21_M_PI_2 * 5
#define PI_3 S21_M_PI / 3
#define S21_M_PI 3.14159265358979323846264338327950288    /* pi             */
#define S21_M_PI_2 1.57079632679489661923132169163975144  /* pi/2           */
#define S21_M_PI_4 0.785398163397448309615660845819875721 /* pi/4           */

#define s21max_inf 1.0 / 0.0
#define s21min_inf -1.0 / 0.0
#define s21nan 0.0 / 0.0
#define s21min_exp 1e-8
#define e 2.7182818284590452353602874

#define S21_MAX_DOUBLE DBL_MAX

START_TEST(test_pow) {
  double x = S21_PI / 2;
  double y = S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-15);

  x = 0;
  y = S21_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 0;
  y = S21_MINF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 0;
  y = S21_NAN;
  ck_assert_ldouble_nan(s21_pow(x, y));

  x = 1;
  y = S21_INF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 1;
  y = S21_MINF;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
  x = 1;
  y = S21_NAN;
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-15);
}
END_TEST

START_TEST(test_fmod) {
  double x = S21_PI / 2;
  double y = S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-15);
  x = 3 * S21_PI / 2;
  y = 3 * S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-15);
  x = -3 * S21_PI / 2;
  y = 3 * S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-15);
  x = 3 * S21_PI / 2;
  y = S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-15);
}
END_TEST

START_TEST(sin_test) {
  ck_assert_ldouble_nan(s21_sin(s21max_inf));
  ck_assert_ldouble_nan(s21_sin(s21min_inf));
  ck_assert_ldouble_nan(s21_sin(s21nan));
  ck_assert_ldouble_eq_tol(s21_sin(S21_M_PI_2), sin(S21_M_PI_2), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(PI_6), sin(PI_6), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-PI_6), sin(-PI_6), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(PI_56), sin(PI_56), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-PI_56), sin(-PI_56), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(1.1), sin(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-2.1), sin(-2.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(5.123456789123), sin(5.123456789123), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(0.00000004564897), sin(0.00000004564897),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(17000000000.1), sin(17000000000.1), 1e-6);
}
END_TEST

START_TEST(cos_test) {
  ck_assert_ldouble_nan(s21_cos(s21max_inf));
  ck_assert_ldouble_nan(s21_cos(s21min_inf));
  ck_assert_ldouble_nan(s21_cos(s21nan));
  ck_assert_ldouble_eq_tol(s21_cos(S21_M_PI_2), cos(S21_M_PI_2), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_M_PI_2), cos(-S21_M_PI_2), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(PI_3), cos(PI_3), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-PI_3), cos(-PI_3), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-0.5), cos(-0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(1.1), cos(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-2.1), cos(-2.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(5.123456789123), cos(5.123456789123), 1e-7);
  ck_assert_ldouble_eq_tol(s21_cos(0.00000004564897), cos(0.00000004564897),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(17000000000.1), cos(17000000000.1), 1e-5);
}
END_TEST

START_TEST(tan_test) {
  ck_assert_ldouble_nan(s21_cos(s21max_inf));
  ck_assert_ldouble_nan(s21_cos(s21min_inf));
  ck_assert_ldouble_nan(s21_cos(s21nan));
  ck_assert_ldouble_eq_tol(s21_tan(S21_M_PI_4), tan(S21_M_PI_4), 1e-15);

  ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(-0.5), tan(-0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(1.1), tan(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(-2.1), tan(-2.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(-0), tan(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(5.123456789123), tan(5.123456789123), 1e-14);
  ck_assert_ldouble_eq_tol(s21_tan(0.00000004564897), tan(0.00000004564897),
                           1e-15);
}
END_TEST

START_TEST(asin_test) {
  ck_assert_ldouble_nan(s21_asin(s21max_inf));
  ck_assert_ldouble_nan(s21_asin(s21min_inf));
  ck_assert_ldouble_nan(s21_asin(s21nan));
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-15);
  ck_assert_ldouble_nan(s21_asin(1.1));
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_asin(-0), asin(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_asin(0.00000004564897), asin(0.00000004564897),
                           1e-8);
}
END_TEST

START_TEST(acos_test) {
  ck_assert_ldouble_nan(s21_acos(s21max_inf));
  ck_assert_ldouble_nan(s21_acos(s21min_inf));
  ck_assert_ldouble_nan(s21_acos(s21nan));
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-5);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-15);
  ck_assert_ldouble_nan(s21_acos(1.1));
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_acos(-0), acos(-0), 1e-15);
}
END_TEST

START_TEST(atan_test) {
  ck_assert_ldouble_nan(s21_atan(s21nan));

  ck_assert_ldouble_eq_tol(s21_atan(s21min_inf), atan(s21min_inf), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(s21max_inf), atan(s21max_inf), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(1.1), atan(1.1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_atan(-2.1), atan(-2.1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_atan(5.123456789123), atan(5.123456789123),
                           1e-7);
  ck_assert_ldouble_eq_tol(s21_atan(0.00000004564897), atan(0.00000004564897),
                           1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(12.456), atan(12.456), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(-13.4574), atan(-13.4574), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(-1367.78), atan(-1367.78), 1e-8);
}
END_TEST

START_TEST(exp_test) {
  ck_assert_ldouble_infinite(s21_exp(s21max_inf));
  ck_assert_ldouble_eq_tol(s21_exp(s21min_inf), exp(s21min_inf), 1e-8);
  ck_assert_ldouble_nan(s21_exp(s21nan));
  ck_assert_ldouble_eq_tol(s21_exp(0.5), exp(0.5), 1e-7);
  ck_assert_ldouble_eq_tol(s21_exp(-0.5), exp(-0.5), 1e-7);
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_exp(1.1), exp(1.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_exp(-2.1), exp(-2.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_exp(-0), exp(-0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_exp(5.123456789123), exp(5.123456789123), 1e-8);
  ck_assert_ldouble_eq_tol(s21_exp(0.00000004564897), exp(0.00000004564897),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_exp(20.1), exp(20.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-20.1), exp(-20.1), 1e-8);
}
END_TEST

START_TEST(log_test) {
  ck_assert_ldouble_eq_tol(s21_log(e), log(e), 0.0000001);

  ck_assert_ldouble_infinite(s21_log(s21max_inf));
  ck_assert_ldouble_nan(s21_log(s21min_inf));
  ck_assert_ldouble_nan(s21_log(s21nan));
  ck_assert_ldouble_eq_tol(s21_log(2.2250738585072014e-308),
                           log(2.2250738585072014e-308), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_log(0.0000056654154544338768),
                           log(0.0000056654154544338768), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_log(1548.56), log(1548.56), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_log(564684684546874684.48484544),
                           log(564684684546874684.48484544), 0.0000001);
  ck_assert_ldouble_eq_tol(
      s21_log(5468435435468743546878646847484845848458489498484.545548),
      log(5468435435468743546878646847484845848458489498484.545548), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_log(545456.5536555865445454),
                           log(545456.5536555865445454), 0.0000001);
  ck_assert_ldouble_nan(s21_log(-0.5));
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-8);
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(s21_log(-0));
  ck_assert_ldouble_eq_tol(s21_log(5.123456789123), log(5.123456789123), 1e-8);
}
END_TEST
/////

/////

START_TEST(sqrt_test) {
  ck_assert_ldouble_nan(s21_sqrt(s21min_inf));
  ck_assert_ldouble_infinite(s21_sqrt(s21max_inf));
  ck_assert_ldouble_nan(s21_sqrt(s21nan));
  ck_assert_ldouble_eq_tol(s21_sqrt(0.5), sqrt(0.5), 1e-15);
  ck_assert_ldouble_nan(s21_sqrt(-0.5));
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sqrt(1.1), sqrt(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sqrt(-0), sqrt(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sqrt(5.123456789123), sqrt(5.123456789123),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.00000004564897), sqrt(0.00000004564897),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_sqrt(170000000000000.1), sqrt(170000000000000.1),
                           1e-8);
}
END_TEST

START_TEST(pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(1, s21min_inf), pow(1, s21min_inf),
                           1e-8);  // todo
  ck_assert_ldouble_eq_tol(s21_pow(-1, s21min_inf), pow(-1, s21min_inf),
                           1e-8);  // todo

  ck_assert_ldouble_eq_tol(s21_pow(s21min_inf, s21min_inf),
                           pow(s21min_inf, s21min_inf), 1e-8);  // todo
  ck_assert_ldouble_eq_tol(s21_pow(s21max_inf, s21min_inf),
                           pow(s21max_inf, s21min_inf), 1e-8);

  ck_assert_ldouble_eq_tol(s21_pow(0.0, s21max_inf), pow(0.0, s21max_inf),
                           1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-0.0, s21max_inf), pow(-0.0, s21max_inf),
                           1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(1, s21max_inf), pow(1, s21max_inf),
                           1e-8);  // todo
  ck_assert_ldouble_eq_tol(s21_pow(-1, s21max_inf), pow(-1, s21max_inf),
                           1e-8);  // todo

  ck_assert_ldouble_eq_tol(s21_pow(0.0, 0), pow(0.0, 0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-0.0, 0), pow(-0.0, 0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(1, 0), pow(1, 0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-1, 0), pow(-1, 0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(s21nan, 0), pow(s21nan, 0), 1e-8);  //
  ck_assert_ldouble_eq_tol(s21_pow(s21min_inf, 0), pow(s21min_inf, 0),
                           1e-8);  // todo
  ck_assert_ldouble_eq_tol(s21_pow(s21max_inf, 0), pow(s21max_inf, 0), 1e-8);

  ck_assert_ldouble_eq_tol(s21_pow(0.0, -0), pow(0.0, -0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-0.0, -0), pow(-0.0, -0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(1, -0), pow(1, -0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-1, -0), pow(-1, -0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(s21nan, -0), pow(s21nan, -0), 1e-8);  //
  ck_assert_ldouble_eq_tol(s21_pow(s21min_inf, -0), pow(s21min_inf, -0),
                           1e-8);  // todo
  ck_assert_ldouble_eq_tol(s21_pow(s21max_inf, -0), pow(s21max_inf, -0), 1e-8);

  ck_assert_ldouble_eq_tol(s21_pow(0.0, 1), pow(0.0, 1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-0.0, 1), pow(-0.0, 1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(1, 1), pow(1, 1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-1, 1), pow(-1, 1), 1e-8);

  ck_assert_ldouble_eq_tol(s21_pow(1, -1), pow(1, -1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-1, -1), pow(-1, -1), 1e-8);

  ck_assert_ldouble_eq_tol(s21_pow(s21min_inf, -1), pow(s21min_inf, -1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(s21max_inf, -1), pow(s21max_inf, -1), 1e-8);

  ck_assert_ldouble_eq_tol(s21_pow(1, s21nan), pow(1, s21nan), 1e-8);

  ck_assert_ldouble_eq(s21_pow(s21max_inf, s21max_inf),
                       pow(s21max_inf, s21max_inf));
  ck_assert_ldouble_eq_tol(s21_pow(s21max_inf, s21min_inf),
                           pow(s21max_inf, s21min_inf), 1e-8);
  ck_assert_ldouble_nan(s21_pow(s21max_inf, s21nan));

  ck_assert_ldouble_nan(s21_pow(s21nan, s21max_inf));
  ck_assert_ldouble_nan(s21_pow(s21nan, s21min_inf));
  ck_assert_ldouble_nan(s21_pow(s21nan, s21nan));

  ck_assert_ldouble_infinite(s21_pow(s21max_inf, 2.4));
  ck_assert_ldouble_infinite(s21_pow(s21min_inf, 2.4));
  ck_assert_ldouble_nan(s21_pow(s21nan, 2.4));
  ck_assert_ldouble_infinite(s21_pow(2.4, s21max_inf));
  ck_assert_ldouble_eq_tol(s21_pow(2.4, s21min_inf), pow(2.4, s21min_inf),
                           1e-8);
  ck_assert_ldouble_nan(s21_pow(2.4, s21nan));

  ck_assert_ldouble_eq_tol(s21_pow(-0, 2.4), pow(-0, 2.4), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-0, 0.5), pow(-0, 0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(0, 2.4), pow(0, 2.4), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-0, 2.4), pow(-0, 2.4), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 0), pow(2.4, 0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, -0), pow(2.4, -0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 0.5), pow(2.4, 0.5), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, -0.5), pow(2.4, -0.5), 1e-8);
  ck_assert_ldouble_nan(s21_pow(-2.4, 0.5));
  ck_assert_ldouble_nan(s21_pow(-2.4, -0.5));
  ck_assert_ldouble_nan(s21_pow(-2.4, 2.1));
  ck_assert_ldouble_nan(s21_pow(-2.4, -2.1));
  ck_assert_ldouble_eq_tol(s21_pow(-2.4, 2), pow(-2.4, 2), 1e-5);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 2), pow(2.4, 2), 1e-5);
  ck_assert_ldouble_eq_tol(s21_pow(-2.4, -1), pow(-2.4, -1), 1e-8);
  ck_assert_ldouble_nan(s21_pow(-2.4, -1.2));
  ck_assert_ldouble_nan(s21_pow(-2.4, -0.4));
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 1), pow(2.4, 1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 3), pow(2.4, 3), 1e-5);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, -3), pow(2.4, -3), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(666666.4, -1.5), pow(666666.4, -1.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(3.3, -24.2), pow(3.3, -24.2), 1e-8);
  ck_assert_ldouble_nan(s21_pow(-3.3, -24.2));
  ck_assert_ldouble_eq_tol(s21_pow(0.0000000005543, 24.2),
                           pow(0.0000000005543, 24.2), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(0.0000000005543, 0.00000003),
                           pow(0.0000000005543, 0.00000003), 1e-7);
}
END_TEST

START_TEST(fmod_test) {
  ck_assert_ldouble_nan(s21_fmod(s21max_inf, s21max_inf));
  ck_assert_ldouble_nan(s21_fmod(s21max_inf, s21min_inf));
  ck_assert_ldouble_nan(s21_fmod(s21max_inf, s21nan));
  ck_assert_ldouble_nan(s21_fmod(s21min_inf, s21max_inf));
  ck_assert_ldouble_nan(s21_fmod(s21min_inf, s21min_inf));
  ck_assert_ldouble_nan(s21_fmod(s21min_inf, s21nan));
  ck_assert_ldouble_nan(s21_fmod(s21nan, s21max_inf));
  ck_assert_ldouble_nan(s21_fmod(s21nan, s21min_inf));
  ck_assert_ldouble_nan(s21_fmod(s21nan, s21nan));
  ck_assert_ldouble_nan(s21_fmod(s21nan, s21max_inf));
  ck_assert_ldouble_nan(s21_fmod(s21nan, s21min_inf));
  ck_assert_ldouble_nan(s21_fmod(s21nan, s21nan));
  ck_assert_ldouble_nan(s21_fmod(s21max_inf, 2.4));
  ck_assert_ldouble_nan(s21_fmod(s21min_inf, 2.4));
  ck_assert_ldouble_nan(s21_fmod(s21nan, 2.4));
  ck_assert_ldouble_eq_tol(s21_fmod(2.4, s21max_inf), fmod(2.4, s21max_inf),
                           1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(2.4, s21min_inf), fmod(2.4, s21min_inf),
                           1e-8);
  ck_assert_ldouble_nan(s21_fmod(2.4, s21nan));
  ck_assert_ldouble_nan(s21_fmod(2.4, s21nan));
  ck_assert_ldouble_eq_tol(s21_fmod(0, 2.4), fmod(0, 2.4), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fmod(-0, 2.4), fmod(-0, 2.4), 1e-15);
  ck_assert_ldouble_nan(s21_fmod(2.4, 0));
  ck_assert_ldouble_nan(s21_fmod(2.4, -0));
  ck_assert_ldouble_eq_tol(s21_fmod(2.4, 0.5), fmod(2.4, 0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fmod(2.4, -0.5), fmod(2.4, -0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fmod(-2.4, 0.5), fmod(-2.4, 0.5), 1e-16);
  ck_assert_ldouble_eq_tol(s21_fmod(-2.4, -0.5), fmod(-2.4, -0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fmod(666666.4, 1.5), fmod(666666.4, 1.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fmod(666666.4, -1.5), fmod(666666.4, -1.5),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_fmod(3.3, 24.2), fmod(3.3, 24.2), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fmod(3.3, -24.2), fmod(3.3, -24.2), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fmod(-3.3, -24.2), fmod(-3.3, -24.2), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fmod(0.0000000005543, 24.2),
                           fmod(0.0000000005543, 24.2), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fmod(0.0000000005543, 0.000003),
                           fmod(0.0000000005543, 0.000003), 1e-15);
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_ldouble_eq(s21_ceil(s21max_inf), ceil(s21max_inf));
  ck_assert_ldouble_eq(s21_ceil(s21min_inf), ceil(s21min_inf));
  ck_assert_ldouble_nan(s21_ceil(s21nan));
  ck_assert_ldouble_eq(s21_ceil(-876554310.23455), ceil(-876554310.23455));
  ck_assert_ldouble_eq(s21_ceil(876554310.23455), ceil(876554310.23455));
  ck_assert_ldouble_eq(s21_ceil(-0.45), ceil(-0.45));
  ck_assert_ldouble_eq(s21_ceil(0.45), ceil(0.45));
  ck_assert_ldouble_eq(s21_ceil(-0.00000000000000045),
                       ceil(-0.00000000000000045));
}
END_TEST

START_TEST(floor_test) {
  ck_assert_ldouble_infinite(s21_floor(s21max_inf));
  ck_assert_ldouble_infinite(s21_floor(s21min_inf));
  ck_assert_ldouble_eq(s21_floor(s21max_inf), floor(s21max_inf));
  ck_assert_ldouble_eq(s21_floor(s21min_inf), floor(s21min_inf));
  ck_assert_ldouble_eq(s21_floor(0), floor(0));
  ck_assert_ldouble_eq(s21_floor(-0), floor(-0));
  ck_assert_ldouble_eq(s21_floor(-876554310.23455), floor(-876554310.23455));
  ck_assert_ldouble_eq(s21_floor(876554310.23455), floor(876554310.23455));
  ck_assert_ldouble_eq(s21_floor(-0.45), floor(-0.45));
  ck_assert_ldouble_eq(s21_floor(0.45), floor(0.45));
  ck_assert_ldouble_eq(s21_floor(-0.0000000000000000000045),
                       floor(-0.0000000000000000000045));
}
END_TEST

START_TEST(abs_test) {
  int inf_max = 1.0 / 0.0;
  int inf_min = -1.0 / 0.0;
  int s21_nan = 0.0 / 0.0;

  ck_assert_int_eq(s21_abs(inf_max), abs(inf_max));
  ck_assert_int_eq(s21_abs(inf_min), abs(inf_min));
  ck_assert_int_eq(s21_abs(s21_nan), abs(s21_nan));
  ck_assert_int_eq(s21_abs(s21_nan), abs(s21_nan));
  ck_assert_int_eq(s21_abs(-10), abs(-10));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_ldouble_infinite(s21_fabs(s21min_inf));
  ck_assert_ldouble_infinite(s21_fabs(s21max_inf));
  ck_assert_ldouble_nan(s21_fabs(s21nan));
  ck_assert_ldouble_eq_tol(s21_fabs(0.5), fabs(0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.5), fabs(-0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.0), fabs(-1.0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(1.0), fabs(1.0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(1.1), fabs(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-2.1), fabs(-2.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.0), fabs(-0.0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(5.123456789123), fabs(5.123456789123),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(0.00000004564897), fabs(0.00000004564897),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(170000000000000.1), fabs(170000000000000.1),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-5.123456789123), fabs(-5.123456789123),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.00000004564897), fabs(-0.00000004564897),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-170000000000000.1),
                           fabs(-170000000000000.1), 1e-15);
}
END_TEST

#define CHK_EPS 1e-6

START_TEST(abs_basic) {
  int testcases[] = {-2147483648, -2147483647, -422112, -3458,
                     -2,          -1,          -0,      0,
                     1,           2,           481516,  2147483647};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_int_eq(s21_abs(testcases[i]), abs(testcases[i]));
}
END_TEST

START_TEST(fabs_basic) {
  double testcases[] = {-S21_MAX_DOUBLE,
                        -1e20,
                        -7.4143526437e3,
                        -3144.51e-4,
                        0.43,
                        -1e-10,
                        1e-4,
                        -4.2356e-2,
                        0.5,
                        -1.,
                        1.5,
                        -100.,
                        9.123123e6,
                        -1e4,
                        1e10,
                        S21_MAX_DOUBLE};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_fabs(testcases[i]), fabs(testcases[i]),
                             CHK_EPS);
}
END_TEST

START_TEST(fabs_inf) {
  double testcases[] = {S21_INF, -S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_infinite(s21_fabs(testcases[i]));
}
END_TEST

START_TEST(fabs_nan) { ck_assert_ldouble_nan(s21_fabs(S21_NAN)); }
END_TEST

START_TEST(fmod_inf) {
  double testcases[] = {-S21_MAX_DOUBLE,
                        -1e20,
                        -7.4143526437e3,
                        -3144.51e-4,
                        0.,
                        0.43,
                        1e-10,
                        1e-4,
                        4.2356e-2,
                        0.5,
                        1.,
                        1.5,
                        100.,
                        9.123123e6,
                        1e4,
                        1e10,
                        S21_MAX_DOUBLE};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_fmod(testcases[i], S21_INF),
                             fmod(testcases[i], S21_INF), CHK_EPS);
}
END_TEST

START_TEST(fmod_nan) {
  double testcases[] = {-S21_MAX_DOUBLE,
                        -1e20,
                        -7.4143526437e3,
                        -3144.51e-4,
                        0.,
                        0.43,
                        1e-10,
                        1e-4,
                        4.2356e-2,
                        0.5,
                        1.,
                        1.5,
                        100.,
                        9.123123e6,
                        1e4,
                        1e10,
                        S21_MAX_DOUBLE};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_fmod(testcases[i], 0));
    ck_assert_ldouble_nan(fmod(testcases[i], 0));
    ck_assert_ldouble_nan(s21_fmod(S21_NAN, testcases[i]));
    ck_assert_ldouble_nan(fmod(S21_NAN, testcases[i]));
  }
}
END_TEST

START_TEST(exp_inf) {
  double testcases[] = {1e4, 1e10, S21_MAX_DOUBLE};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_infinite(s21_exp(testcases[i]));
    ck_assert_ldouble_infinite(exp(testcases[i]));
  }
}
END_TEST

START_TEST(exp_nan) {
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_nan(exp(S21_NAN));
}
END_TEST

START_TEST(log_basic) {
  double testcases[] = {0.001,      1e-10,    1e-4, 4.2356e-2,     0.43,
                        0.5,        0.999999, 1.,   1.0000001,     1.001,
                        1.008888,   1.01,     1.1,  1.5,           100.,
                        9.123123e6, 1e4,      1e10, S21_MAX_DOUBLE};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_log(testcases[i]), log(testcases[i]), CHK_EPS);
}
END_TEST

START_TEST(log_inf) {
  double testcases[] = {0, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_infinite(s21_log(testcases[i]));
    ck_assert_ldouble_infinite(log(testcases[i]));
  }
}
END_TEST

START_TEST(log_nan) {
  double testcases[] = {-S21_MAX_DOUBLE, -1e4, -1., S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_log(testcases[i]));
    ck_assert_ldouble_nan(log(testcases[i]));
  }
}
END_TEST

START_TEST(sqrt_basic) {
  double testcases[] = {
      -0.,        1e-10, 1e-4,       4.2356e-2, 0.43,          0.5,
      0.999999,   1.,    1.0000001,  1.001,     1.008888,      1.01,
      1.1,        1.5,   11.67,      37.17,     49.000009,     100.,
      169.777777, 1e4,   9.123123e6, 1e10,      S21_MAX_DOUBLE};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    long double result = s21_sqrt(testcases[i]);
    double expected_result = sqrt(testcases[i]);
    if (result > 1e17) {
      int power = ceil(log10l(result));
      result *= powl(10, 17 - power);
      result = truncl(result);

      power = ceil(log10l(expected_result));
      expected_result *= pow(10, 17 - power);
      expected_result = trunc(expected_result);
    }
    ck_assert_ldouble_eq_tol(result, expected_result, CHK_EPS);
  }
}
END_TEST

START_TEST(sqrt_inf) {
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
  ck_assert_ldouble_infinite(sqrt(S21_INF));
}
END_TEST

START_TEST(sqrt_nan) {
  double testcases[] = {-S21_MAX_DOUBLE, -1e4, -1., -0.1, S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_sqrt(testcases[i]));
    ck_assert_ldouble_nan(sqrt(testcases[i]));
  }
}
END_TEST

START_TEST(sin_basic) {
  for (double i = -4.; i <= 4.; i += 0.0625)
    ck_assert_ldouble_eq_tol(s21_sin(i * S21_PI), sin(i * S21_PI), CHK_EPS);
}
END_TEST

START_TEST(sin_nan) {
  double testcases[] = {-S21_INF, S21_INF, S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_sin(testcases[i]));
    ck_assert_ldouble_nan(sin(testcases[i]));
  }
}
END_TEST

START_TEST(cos_basic) {
  for (double i = -4.; i <= 4.; i += 0.0625)
    ck_assert_ldouble_eq_tol(s21_cos(i * S21_PI), cos(i * S21_PI), CHK_EPS);
}
END_TEST

START_TEST(cos_nan) {
  double testcases[] = {-S21_INF, S21_INF, S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_cos(testcases[i]));
    ck_assert_ldouble_nan(cos(testcases[i]));
  }
}
END_TEST

START_TEST(tan_nan) {
  double testcases[] = {-S21_INF, S21_INF, S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_tan(testcases[i]));
    ck_assert_ldouble_nan(tan(testcases[i]));
  }
}
END_TEST

START_TEST(floor_basic) {
  double testcases[] = {-S21_MAX_DOUBLE,
                        -1e20,
                        -7.4143526437e3,
                        -3144.51e-4,
                        0.,
                        1e-10,
                        1e-4,
                        4.2356e-2,
                        0.43,
                        0.5,
                        0.999999,
                        1.,
                        1.0000001,
                        1.001,
                        1.008888,
                        1.01,
                        1.1,
                        1.5,
                        100.,
                        9.123123e6,
                        1e4,
                        1e10,
                        S21_MAX_DOUBLE};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_floor(testcases[i]), floor(testcases[i]),
                             CHK_EPS);
}
END_TEST

START_TEST(floor_inf) {
  double testcases[] = {-S21_INF, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_infinite(s21_floor(testcases[i]));
    ck_assert_ldouble_infinite(floor(testcases[i]));
  }
}
END_TEST

START_TEST(floor_nan) {
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
  ck_assert_ldouble_nan(floor(S21_NAN));
}
END_TEST

START_TEST(ceil_basic) {
  double testcases[] = {-S21_MAX_DOUBLE,
                        -1e20,
                        -7.4143526437e3,
                        -3144.51e-4,
                        0.,
                        1e-10,
                        1e-4,
                        4.2356e-2,
                        0.43,
                        0.5,
                        0.999999,
                        1.,
                        1.0000001,
                        1.001,
                        1.008888,
                        1.01,
                        1.1,
                        1.5,
                        100.,
                        9.123123e6,
                        1e4,
                        1e10,
                        S21_MAX_DOUBLE};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_ceil(testcases[i]), ceil(testcases[i]),
                             CHK_EPS);
}
END_TEST

START_TEST(ceil_inf) {
  double testcases[] = {-S21_INF, S21_INF};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_infinite(s21_ceil(testcases[i]));
    ck_assert_ldouble_infinite(ceil(testcases[i]));
  }
}
END_TEST

START_TEST(ceil_nan) {
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_nan(ceil(S21_NAN));
}
END_TEST

START_TEST(asin_basic) {
  double testcases[] = {-3144.51e-4, 0.,  1e-10,    1e-4, 4.2356e-2,
                        0.43,        0.5, 0.999999, 1.};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_asin(testcases[i]), asin(testcases[i]),
                             CHK_EPS);
}
END_TEST

START_TEST(asin_nan) {
  double testcases[] = {-S21_INF,   -S21_MAX_DOUBLE,
                        -1e20,      -7.4143526437e3,
                        1.5,        100.,
                        9.123123e6, 1e4,
                        1e10,       S21_MAX_DOUBLE,
                        S21_INF,    S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_asin(testcases[i]));
    ck_assert_ldouble_nan(asin(testcases[i]));
  }
}
END_TEST

START_TEST(acos_basic) {
  double testcases[] = {-3144.51e-4, 0.,  1e-10,    1e-4, 4.2356e-2,
                        0.43,        0.5, 0.999999, 1.};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_acos(testcases[i]), acos(testcases[i]),
                             CHK_EPS);
}
END_TEST

START_TEST(acos_nan) {
  double testcases[] = {-S21_INF,   -S21_MAX_DOUBLE,
                        -1e20,      -7.4143526437e3,
                        1.5,        100.,
                        9.123123e6, 1e4,
                        1e10,       S21_MAX_DOUBLE,
                        S21_INF,    S21_NAN};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_nan(s21_acos(testcases[i]));
    ck_assert_ldouble_nan(acos(testcases[i]));
  }
}
END_TEST

START_TEST(atan_basic) {
  double testcases[] = {-S21_INF,    -S21_MAX_DOUBLE,
                        -1e20,       -7.4143526437e3,
                        -3144.51e-4, 0.,
                        1e-10,       1e-4,
                        4.2356e-2,   0.43,
                        0.5,         0.999999,
                        1.,          1.0000001,
                        1.001,       1.008888,
                        1.01,        1.1,
                        1.5,         100.,
                        9.123123e6,  1e4,
                        1e10,        S21_MAX_DOUBLE,
                        S21_INF};

  size_t n = sizeof(testcases) / sizeof(testcases[0]);

  for (size_t i = 0; i < n; ++i)
    ck_assert_ldouble_eq_tol(s21_atan(testcases[i]), atan(testcases[i]),
                             CHK_EPS);
}
END_TEST

START_TEST(atan_nan) {
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_nan(atan(S21_NAN));
}
END_TEST

Suite *s21_math_suite(void) {
  Suite *suite = suite_create("s21_math");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("Core of s21_math");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, sin_test);
  tcase_add_test(tcase_core, cos_test);
  tcase_add_test(tcase_core, tan_test);
  tcase_add_test(tcase_core, asin_test);
  tcase_add_test(tcase_core, acos_test);
  tcase_add_test(tcase_core, atan_test);
  tcase_add_test(tcase_core, exp_test);
  tcase_add_test(tcase_core, log_test);
  tcase_add_test(tcase_core, sqrt_test);
  tcase_add_test(tcase_core, pow_test);
  tcase_add_test(tcase_core, fmod_test);
  tcase_add_test(tcase_core, ceil_test);
  tcase_add_test(tcase_core, floor_test);
  tcase_add_test(tcase_core, abs_test);
  tcase_add_test(tcase_core, fabs_test);

  tcase_add_test(tcase_core, test_pow);
  tcase_add_test(tcase_core, test_fmod);

  tcase_add_test(tcase_core, abs_basic);

  tcase_add_test(tcase_core, fabs_basic);
  tcase_add_test(tcase_core, fabs_inf);
  tcase_add_test(tcase_core, fabs_nan);

  tcase_add_test(tcase_core, fmod_inf);
  tcase_add_test(tcase_core, fmod_nan);

  tcase_add_test(tcase_core, exp_inf);
  tcase_add_test(tcase_core, exp_nan);

  tcase_add_test(tcase_core, log_basic);
  tcase_add_test(tcase_core, log_inf);
  tcase_add_test(tcase_core, log_nan);

  tcase_add_test(tcase_core, sqrt_basic);
  tcase_add_test(tcase_core, sqrt_inf);
  tcase_add_test(tcase_core, sqrt_nan);

  tcase_add_test(tcase_core, sin_basic);
  tcase_add_test(tcase_core, sin_nan);

  tcase_add_test(tcase_core, cos_basic);
  tcase_add_test(tcase_core, cos_nan);

  tcase_add_test(tcase_core, tan_nan);

  tcase_add_test(tcase_core, floor_basic);
  tcase_add_test(tcase_core, floor_inf);
  tcase_add_test(tcase_core, floor_nan);

  tcase_add_test(tcase_core, ceil_basic);
  tcase_add_test(tcase_core, ceil_inf);
  tcase_add_test(tcase_core, ceil_nan);

  tcase_add_test(tcase_core, asin_basic);
  tcase_add_test(tcase_core, asin_nan);

  tcase_add_test(tcase_core, acos_basic);
  tcase_add_test(tcase_core, acos_nan);

  tcase_add_test(tcase_core, atan_nan);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main() {
  int failed_count = 0;
  Suite *suite = s21_math_suite();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  // Получаем количество проваленных тестов.
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    // Сигнализируем о том, что тестирование прошло неудачно.
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}