#ifndef SRC_CAT_S21_MATH_H_
#define SRC_CAT_S21_MATH_H_

#define s21_PI 3.14159265358979323846
#define s21_NAN (0.0 / 0.0)
#define s21_E 2.71828182845904523536
#define s21_LOG2E 1.44269504088896340736
#define s21_LOG10E 0.434294481903251827651
#define s21_LN2 0.693147180559945309417
#define s21_LN10 2.30258509299404568402
#define s21_EPS 1e-17
#define s21_INF (1.0 / 0.0)
#define s21_ISNAN(x) ((x >= 0) == (x < 0))
#define s21_ISINF(x) ((x == s21_INF) || (x == -s21_INF))
#define s21_ACCURACY 0.0000000001
#define s21_NEW_ACCURACY 0.000000000000001

#define S21_NEGZERO -0.0

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_factorial(long long int x);
long double s21_pow_int(double base, long long int exp);

#endif
