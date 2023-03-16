#include "s21_math.h"

int s21_abs(int x) { return x < 0 ? ~x + 1 : x; }

long double s21_fabs(double x) {
  Bit bit = {x};
  bit.pat.sgn = 0;
  return bit.x;
}

long double s21_floor(double x) {
  if (s21_is_nan(x)) {
    x = S21_NAN;
  } else if (x >= LLONG_MAX || x <= LLONG_MIN) {
  } else if (x < 0) {
    x += s21_fabs(x - (int64_t)x) > S21_EPS ? -1 : 0;
    x = (int64_t)x;
  } else {
    x = (int64_t)x;
  }
  return x;
}

long double s21_ceil(double x) {
  if (s21_is_nan(x)) {
    x = S21_NAN;
  } else if (x >= LLONG_MAX || x <= LLONG_MIN) {
  } else if (x < 0) {
    x = (int64_t)x;
  } else {
    x += s21_fabs(x - (int64_t)x) > S21_EPS ? 1 : 0;
    x = (int64_t)x;
  }
  return x;
}

long double s21_fmod(double x, double y) {
  int was_nan = 0;
  long double res = 0;

  if (y < 0) y = s21_fabs(y);
  if (y == 0.0 || x == S21_INF || x == S21_MINF || x == S21_NAN ||
      y == S21_NAN) {
    was_nan = 1;
  } else if (y == S21_INF || y == S21_MINF) {
    res = x;
  } else if (x < 0) {
    x = s21_fabs(x);
    res = (-1) * ((long double)x - (long double)y * s21_floor(x / y));
  } else {
    res = (long double)x - (long double)y * s21_floor(x / y);
  }

  return was_nan ? S21_NAN : res;
}

long double s21_sin(double x) {
  int base = 0;
  long double res = 0, prev = 0, next = x;

  if (x == S21_INF || x == S21_MINF || s21_is_nan(x)) {
    res = S21_NAN;
    base = 1;
  }
  if (!base) {
    x = s21_fmod(x, 2. * S21_PI);
    res = x;
    prev = x;
    next = x;
  }
  if (s21_fabs(x - S21_PI / 2) < S21_EPS) {
    res = 1.;
    base = 1;
  } else if (s21_fabs(x - -S21_PI / 2) < S21_EPS) {
    res = -1.;
    base = 1;
  } else if (s21_fabs(x - 3 * S21_PI / 2) < S21_EPS) {
    res = -1.;
    base = 1;
  } else if (s21_fabs(x - -3 * S21_PI / 2) < S21_EPS) {
    res = 1.;
    base = 1;
  }

  for (size_t n = 0; !base; n++) {
    prev = res;
    next *= (-x * x) / (2 * n + 2) / (2 * n + 3);
    res += next;
    if (s21_fabs(res - prev) <= S21_EPS) break;
  }
  return res;
}

long double s21_cos(double x) {
  int base = 0;
  long double res = 1, prev = res, x_pow = 1, fact = 1;

  if (x == S21_INF || x == S21_MINF || s21_is_nan(x)) {
    res = S21_NAN;
    base = 1;
  }

  if (!base) x = s21_fmod(x, 2 * S21_PI);

  if (s21_fabs(x - S21_PI) < S21_EPS) {
    res = -1.;
    base = 1;
  } else if (s21_fabs(x - -S21_PI) < S21_EPS) {
    res = -1.;
    base = 1;
  } else if (s21_fabs(x - 2 * S21_PI) < S21_EPS) {
    res = 1.;
    base = 1;
  } else if (s21_fabs(x - -2 * S21_PI) < S21_EPS) {
    res = 1.;
    base = 1;
  }

  for (size_t n = 0; !base; n++) {
    fact *= (2 * n + 1) * (2 * n + 2);
    x_pow *= -1 * x * x;
    res += x_pow / fact;
    if (s21_fabs(res - prev) <= S21_EPS) break;
    prev = res;
  }
  return res;
}

long double s21_tan(double x) {
  long double res = S21_NAN;

  if (!s21_is_nan(x) && s21_fabs(x) != S21_INF) {
    if (s21_fabs(s21_cos(x)) <= S21_EPS)
      res = s21_sin(x) * S21_INF;
    else
      res = s21_sin(x) / s21_cos(x);
  }

  return res;
}

long double s21_exp(double x) {
  int base = 0;
  long double res = 1, prev = res, next = 1;

  if (x == S21_INF) {
    res = S21_INF;
    base = 1;
  } else if (x == S21_MINF) {
    res = 0.;
    base = 1;
  } else if (s21_is_nan(x)) {
    res = S21_NAN;
    base = 1;
  } else {
    int neg = 0;
    if (x < 0) {
      neg = 1;
      x = -x;
    }
    for (size_t n = 0; !base; n++) {
      if (res >= DBL_MAX) {
        res = S21_INF;
        break;
      }
      prev = res;
      next *= x / (n + 1);
      res += next;
      if (s21_fabs(res - prev) <= S21_EPS) break;
    }
    if (neg) res = 1.0 / res;
  }
  return res;
}

long double s21_sqrt(double x) {
  long double res = 1, prev = 2;
  int neg = 0;
  int inf = 0;
  Bit bit = {x};

  if (x == S21_INF) {
    res = S21_INF;
    inf = 1;
  } else if (bit.pat.sgn && x == -0.)
    res = -0.;
  else if (bit.pat.sgn)
    neg = 1;

  while (s21_fabs(res - prev) > S21_EPS && !neg && res != -0. && !inf) {
    prev = res;
    res = (prev + x / prev) / 2;
  }
  return neg ? S21_NAN : res;
}

long double s21_log(double x) {
  int ex = 0;
  long double res = 0, prev = 0;

  if (x == S21_INF) {
    res = S21_INF;
  } else if (s21_is_nan(x)) {
    res = S21_NAN;
  } else if (x == 0.0) {
    res = S21_MINF;
  } else if (x < 0.0) {
    res = S21_NAN;
  } else if (x > 0) {
    for (; x >= S21_EXP; ex++) x /= S21_EXP;
    do {
      prev = res;
      res = res + 2 * (x - s21_exp(res)) / (x + s21_exp(res));
    } while (s21_fabs(res - prev) >= 1e-9);
  }

  return res + ex;
}

long double s21_atan(double x) {
  long double res = 0, prev = 0, nom = x, den = 1;

  if (x == S21_INF) {
    res = S21_PI / 2;
  } else if (x == S21_MINF) {
    res = -S21_PI / 2;
  } else if (s21_fabs(x) > 1) {
    res = 1 / x;
    long double next = 1 / x;
    long double c = S21_PI * s21_sqrt(x * x) / (2 * x);
    for (size_t n = 1;; n++) {
      prev = res;
      next = next * (-1) * (2 * n - 1) / (x * x * (2 * n + 1));
      res += next;
      if (s21_fabs(res - prev) <= S21_EPS) break;
    }
    res = c - res;
  } else if (x == 1) {
    res = S21_PI / 4;
  } else if (x == -1) {
    res = -S21_PI / 4;
  } else if (s21_fabs(x) < 1) {
    res = x;
    for (size_t n = 1;; n++) {
      prev = res;
      nom *= -x * x;
      den = 2 * n + 1;
      res += nom / den;
      if (s21_fabs(res - prev) <= S21_EPS) break;
    }
  } else {
    res = S21_NAN;
  }

  return res;
}

long double s21_asin(double x) {
  long double res = 0;

  if (s21_fabs(x) < 1)
    res = s21_atan(x / s21_sqrt(1 - x * x));
  else if (x == 1)
    res = S21_PI / 2;
  else if (x == -1)
    res = -S21_PI / 2;
  else
    res = S21_NAN;

  return res;
}

long double s21_acos(double x) {
  long double res = 0;

  if (x > 0. && x < 1.)
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  else if (x > -1 && x < 0)
    res = s21_atan(s21_sqrt(1 - x * x) / x) + S21_PI;
  else if (x == -1)
    res = S21_PI;
  else if (x == 1)
    res = 0.;
  else if (x == 0)
    res = S21_PI / 2;
  else
    res = S21_NAN;

  return res;
}

int s21_is_nan(double x) {
  int nan = 0;
  Bit bit = {x};
  if (bit.pat.exp == 2047 && bit.pat.mnt != 0) nan = 1;
  return nan ? 1 : 0;
}

long double s21_pow(double base, double ex) {
  long double res = 0.0;
  int neg = 0;

  if (ex == 0.0) {
    res = 1.0;
  } else if (base == 1) {
    res = 1.0;
  } else if (s21_is_nan(ex) || s21_is_nan(base)) {
    res = S21_NAN;
  } else {
    if (base == -1 && s21_fabs(ex) == S21_INF) {
      res = 1.0;
    } else if (base == 0.0) {
      res = ex > 0.0 ? 0.0 : S21_INF;
    } else if (ex == S21_INF) {
      res = S21_INF;
    } else if (ex == S21_MINF) {
      res = 0.0;
    } else if (base == S21_INF) {
      res = ex > 0 ? S21_INF : 0.0;
    } else if (base == S21_MINF && ex < 0 && !s21_fmod(ex, 1)) {
      res = !s21_fmod(ex, 2) ? 0.0 : -0.0;
    } else if (base == S21_MINF && ex < 0) {
      res = 0.0;
    } else if (base == S21_MINF && ex > 0 && !s21_fmod(ex, 1)) {
      res = !s21_fmod(ex, 2) ? S21_INF : S21_MINF;
    } else if (base == S21_MINF && ex > 0) {
      res = S21_INF;
    } else if (base < 0.0 && s21_fmod(ex, s21_floor(ex)) &&
               s21_fabs(ex) != S21_INF) {
      res = S21_NAN;
    } else {
      if (base < 0.0) {
        base = s21_fabs(base);
        neg = 1;
      }
      res = s21_exp(ex * s21_log(base));
      if (neg) res = !s21_fmod(ex, 2) ? res : -res;
    }
  }

  return res;
}
