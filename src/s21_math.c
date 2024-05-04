#ifndef __S21_MATH__
#define __S21_MATH__

#include "s21_math.h"

int s21_abs(int x) { return x < 0 ? (-x) : x; }

long double s21_ceil(double x) {
  long double result = (int)x;
  if (s21_ISNAN(x) || s21_ISINF(x))
    result = x;
  else
    result = x > result ? result + 1 : result;

  return result;
}

long double s21_fabs(double x) {
  long double result = 0;
  if (s21_ISNAN(x)) {
    result = s21_NAN;
  } else if (x == 0.0 || x == S21_NEGZERO) {
    result = 0.0;
  } else if (s21_ISINF(x)) {
    result = s21_INF;
  } else {
    result = x > 0 ? (long double)x : (long double)(x *= -1);
  }
  return result;
}

long double s21_floor(double x) {
  long double result = (long long int)x;
  if (s21_ISNAN(x) || s21_ISINF(x)) result = x;
  return (x < 0 && x != result) ? result -= 1 : result;
}

long double s21_pow_int(double base, long long int exp) {
  long double result = 1;
  int sign = (exp > 0);
  exp *= sign ? 1 : -1;
  for (long long int i = 0; i < exp; i++)
    result = sign ? result * base : result / base;
  return result;
}

long double s21_pow(double base, double exp) {
  long double result = 0;
  if (!exp) {
    result = 1.0;
  } else if (base == -s21_INF && exp == -s21_INF) {
    result = 0.0;
  } else if (base == -s21_INF && exp == s21_INF) {
    result = s21_INF;
  } else if (base < 0 && exp != (long long int)exp) {
    result = s21_NAN;
  } else {
    int sign = base < 0 ? -1 : 1;
    result = s21_exp(exp * s21_log(base * sign));
    if (s21_fmod(exp, 2)) {
      result *= sign;
    }
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result = 1;
  for (int i = 1; i < 100; i++) {
    result -= (result * result - x) / (2 * result);
  }
  return x < 0 ? s21_NAN : result;
}

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (s21_ISNAN(x) || s21_ISINF(x) || s21_ISNAN(y) || y == 0) {
    result = s21_NAN;
  } else if (s21_ISINF(y)) {
    result = x;
  } else {
    result = x - (int)(x / y) * y;
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 1.0;
  long double pre_result = 1.0;
  if (x == s21_INF) {
    result = s21_INF;
  } else if (x != x) {
    result = s21_NAN;
  } else if (x == -s21_INF) {
    result = 0;
  } else {
    long double k = (long long int)(x / s21_LN2);
    long double mod = x - k * s21_LN2;
    for (int i = 1; s21_fabs(pre_result) > s21_NEW_ACCURACY; i++) {
      pre_result *= mod / i;
      result += pre_result;
    }
    result *= s21_pow_int(2, k);
  }
  return result;
}

long double s21_log(double x) {
  long double result = 0.0;
  long double pre_result = 1.0;

  if (x < 0.0 || x == -s21_INF || s21_ISNAN(x)) {
    result = s21_NAN;
  } else if (x == 0) {
    result = -s21_INF;
  } else if (x == s21_INF) {
    result = s21_INF;
  } else if (x == 1) {
    result = 0;
  } else {
    int e_repeat = 0;
    while (x >= s21_E) {
      x /= s21_E;
      e_repeat++;
    }
    for (int i = 0; i < 10000; i++) {
      pre_result = result;
      result = pre_result +
               2 * (x - s21_exp(pre_result)) / (x + s21_exp(pre_result));
    }
    result += e_repeat;
  }
  return result;
}

long double s21_cos(double x) {
  long double result = 1;
  long double pre_result = 1;
  if (s21_ISNAN(x) || s21_ISINF(x)) {
    result = s21_NAN;
  } else {
    x = s21_fmod(x, 2 * s21_PI);
    for (int i = 1; s21_fabs(pre_result) > s21_NEW_ACCURACY; i++) {
      pre_result =
          s21_pow(-1, i) * (s21_pow_int(x, 2 * i) / s21_factorial(2 * i));
      result += pre_result;
    }
  }
  return result;
}

long double s21_sin(double x) {
  long double result = 0;
  long double pre_result = 1;
  if (s21_ISNAN(x) || s21_ISINF(x)) {
    result = s21_NAN;
  } else {
    x = s21_fmod(x, 2 * s21_PI);
    for (int i = 1; s21_fabs(pre_result) > s21_NEW_ACCURACY; i++) {
      pre_result = s21_pow_int(-1, i + 1) *
                   (s21_pow_int(x, 2 * i - 1) / s21_factorial(2 * i - 1));
      result += pre_result;
    }
  }
  return result;
}

long double s21_tan(double x) {
  long double result = 0;
  if (s21_ISNAN(x) || s21_ISINF(x)) {
    result = s21_NAN;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0;
  long double pre_result = 1.0;
  if (s21_ISNAN(x)) {
    result = x;
  } else if (x == s21_INF) {
    result = s21_PI / 2;
  } else if (x == -s21_INF) {
    result = -s21_PI / 2;
  } else if (x == 0) {
    result = 0;
  } else if (x == 1) {
    result = 0.785398163;
  } else if (x == -1) {
    result = -0.785398163;
  } else {
    int is_in_range = (x > -1 && x < 1);
    result = is_in_range ? x : 1.0 / x;
    for (int i = 1; s21_fabs(pre_result) > s21_NEW_ACCURACY; i++) {
      pre_result =
          s21_pow_int(-1, i) *
          (s21_pow(x, (2 * i + 1) * (is_in_range ? 1 : -1)) / (2 * i + 1));
      result += pre_result;
    }
    if (!is_in_range) result = (s21_PI * s21_fabs(x) / (2 * x)) - result;
  }
  return result;
}

long double s21_asin(double x) {
  long double result = x;
  long double pre_result = 1.0;
  if (s21_ISNAN(x) || s21_ISINF(x)) {
    result = s21_NAN;
  } else if (x > 1.0 || x < -1.0) {
    result = s21_NAN;
  } else if (x == 1) {
    result = s21_PI / 2;
  } else if (x == -1) {
    result = -s21_PI / 2;
  } else if (x == 0) {
    result = 0;
  } else {
    for (int i = 1; s21_fabs(pre_result) > s21_NEW_ACCURACY; i++) {
      pre_result = (s21_factorial(s21_factorial(2 * i - 1)) *
                    s21_pow_int(x, 2 * i + 1)) /
                   (s21_factorial(s21_factorial(2 * i)) * (2 * i + i));
      result += pre_result;
    }
  }
  return result;
}

long double s21_acos(double x) {
  long double result = x;
  if (s21_ISNAN(x) || s21_ISINF(x)) {
    result = s21_NAN;
  } else if (x > 1.0 || x < -1.0) {
    result = s21_NAN;
  } else if (x == 1) {
    result = 0;
  } else if (x == -1) {
    result = s21_PI;
  } else if (x == 0) {
    result = s21_PI / 2;
  } else {
    result = s21_PI / 2 - s21_asin(x);
  }
  return result;
}

long double s21_factorial(long long int x) {
  if (x == 1 || x == 0) return 1;
  if (x < 0) return s21_INF;
  long double result = x * s21_factorial(x - 1);
  return result;
}

#endif