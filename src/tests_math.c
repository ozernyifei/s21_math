#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

#define TEST_EPS 1e-7

START_TEST(abs_tests_normal) {
  int val_1 = 3;
  int val_2 = -10000;
  int val_3 = 0;
  int val_4 = 34023;
  ck_assert_int_eq(abs(val_1), s21_abs(val_1));
  ck_assert_int_eq(abs(val_2), s21_abs(val_2));
  ck_assert_int_eq(abs(val_3), s21_abs(val_3));
  ck_assert_int_eq(abs(val_4), s21_abs(val_4));
}
END_TEST

START_TEST(abs_tests_specific) {
  int val_1 = s21_INF;
  int val_2 = -6744;
  int val_3 = 2016450318;
  int val_4 = -s21_INF;
  int val_5 = s21_NAN;
  ck_assert_int_eq(abs(val_1), s21_abs(val_1));
  ck_assert_int_eq(abs(val_2), s21_abs(val_2));
  ck_assert_int_eq(abs(val_3), s21_abs(val_3));
  ck_assert_int_eq(abs(val_4), s21_abs(val_4));
  ck_assert_int_eq(abs(val_5), s21_abs(val_5));
}
END_TEST

START_TEST(fabs_tests_normal) {
  double val_1 = -9.01;
  double val_2 = 67.033;
  double val_3 = -1.0;
  double val_4 = 0.000001;
  ck_assert_ldouble_eq(fabs(val_1), s21_fabs(val_1));
  ck_assert_ldouble_eq(fabs(val_2), s21_fabs(val_2));
  ck_assert_ldouble_eq(fabs(val_3), s21_fabs(val_3));
  ck_assert_ldouble_eq(fabs(val_4), s21_fabs(val_4));
}
END_TEST

START_TEST(fabs_tests_specific) {
  double val_1 = s21_NAN;
  double val_2 = s21_INF;
  double val_3 = -s21_INF;
  double val_4 = s21_EPS;
  ck_assert_double_nan(s21_fabs(val_1));
  ck_assert_ldouble_eq(fabs(val_2), s21_fabs(val_2));
  ck_assert_ldouble_eq(fabs(val_3), s21_fabs(val_3));
  ck_assert_ldouble_eq(fabs(val_4), s21_fabs(val_4));
}
END_TEST

START_TEST(ceil_tests_normal) {
  double val_1 = 3.05;
  double val_2 = -7.02;
  double val_3 = 0.0009999;
  double val_4 = 8.0;
  double val_5 = 0;
  ck_assert_ldouble_eq(ceil(val_1), s21_ceil(val_1));
  ck_assert_ldouble_eq(ceil(val_2), s21_ceil(val_2));
  ck_assert_ldouble_eq(ceil(val_3), s21_ceil(val_3));
  ck_assert_ldouble_eq(ceil(val_4), s21_ceil(val_4));
  ck_assert_ldouble_eq(ceil(val_5), s21_ceil(val_5));
}
END_TEST

START_TEST(ceil_tests_specific) {
  double val_1 = s21_INF;
  double val_2 = -s21_INF;
  double val_3 = s21_NAN;
  double val_4 = s21_EPS;
  double val_5 = -9876.54321;
  double val_6 = 0.37473256212831248141123;
  ck_assert_ldouble_eq(ceil(val_1), s21_ceil(val_1));
  ck_assert_ldouble_eq(ceil(val_2), s21_ceil(val_2));
  ck_assert_double_nan(s21_ceil(val_3));
  ck_assert_ldouble_eq(ceil(val_4), s21_ceil(val_4));
  ck_assert_ldouble_eq(ceil(val_5), s21_ceil(val_5));
  ck_assert_ldouble_eq(ceil(val_6), s21_ceil(val_6));
}
END_TEST

START_TEST(sqrt_tests_normal) {
  double val_1 = -231;
  double val_2 = 10000;
  double val_3 = 3.9392923;
  double val_4 = 1;
  double val_5 = 0.000001;
  ck_assert_double_nan(s21_sqrt(val_1));
  ck_assert_ldouble_eq_tol(sqrt(val_2), s21_sqrt(val_2), TEST_EPS);
  ck_assert_ldouble_eq_tol(sqrt(val_3), s21_sqrt(val_3), TEST_EPS);
  ck_assert_ldouble_eq_tol(sqrt(val_4), s21_sqrt(val_4), TEST_EPS);
  ck_assert_ldouble_eq_tol(sqrt(val_5), s21_sqrt(val_5), TEST_EPS);
}
END_TEST

START_TEST(sqrt_tests_specific) {
  double val_1 = s21_INF;
  double val_2 = s21_EPS;
  double val_3 = s21_NAN;
  double val_4 = 0;
  double val_5 = 123048584952052.293912390123;
  ck_assert_double_nan(s21_sqrt(val_1));
  ck_assert_double_eq(sqrt(val_2), s21_sqrt(val_2));
  ck_assert_double_nan(s21_sqrt(val_3));
  ck_assert_double_eq_tol(sqrt(val_4), s21_sqrt(val_4), TEST_EPS);
  ck_assert_double_eq_tol(sqrt(val_5), s21_sqrt(val_5), TEST_EPS);
}
END_TEST

START_TEST(floor_tests_normal) {
  double val_1 = 5.0231;
  double val_2 = 1100.0;
  double val_3 = 0.0003;
  double val_4 = 0;
  double val_5 = -123;
  ck_assert_ldouble_eq(floor(val_1), s21_floor(val_1));
  ck_assert_ldouble_eq(floor(val_2), s21_floor(val_2));
  ck_assert_ldouble_eq(floor(val_3), s21_floor(val_3));
  ck_assert_ldouble_eq(floor(val_4), s21_floor(val_4));
  ck_assert_ldouble_eq(floor(val_5), s21_floor(val_5));
}
END_TEST

START_TEST(floor_tests_specific) {
  double val_1 = s21_INF;
  double val_2 = -s21_INF;
  double val_3 = s21_NAN;
  double val_4 = s21_EPS;
  double val_5 = -999990.312312314;
  ck_assert_ldouble_eq(floor(val_1), s21_floor(val_1));
  ck_assert_ldouble_eq(floor(val_2), s21_floor(val_2));
  ck_assert_double_nan(s21_floor(val_3));
  ck_assert_ldouble_eq(floor(val_4), s21_floor(val_4));
  ck_assert_ldouble_eq(floor(val_5), s21_floor(val_5));
}
END_TEST

START_TEST(acos_tests_normal) {
  double val_1 = 0.0231;
  double val_2 = 1;
  double val_3 = -1;
  double val_4 = 0;
  ck_assert_ldouble_eq_tol(acos(val_1), s21_acos(val_1), TEST_EPS);
  ck_assert_ldouble_eq_tol(acos(val_2), s21_acos(val_2), TEST_EPS);
  ck_assert_ldouble_eq_tol(acos(val_3), s21_acos(val_3), TEST_EPS);
  ck_assert_ldouble_eq_tol(acos(val_4), s21_acos(val_4), TEST_EPS);
}
END_TEST

START_TEST(acos_tests_specific) {
  double val_1 = s21_NAN;
  double val_2 = s21_INF;
  double val_3 = -s21_INF;
  double val_4 = 1.2;
  ck_assert_double_nan(s21_acos(val_1));
  ck_assert_double_nan(s21_acos(val_2));
  ck_assert_double_nan(s21_acos(val_3));
  ck_assert_double_nan(s21_acos(val_4));
}
END_TEST

START_TEST(asin_tests_normal) {
  double val_1 = -0.00002;
  double val_2 = -1;
  double val_3 = 1;
  double val_4 = 0;
  ck_assert_double_eq_tol(asin(val_1), s21_asin(val_1), TEST_EPS);
  ck_assert_double_eq_tol(asin(val_2), s21_asin(val_2), TEST_EPS);
  ck_assert_double_eq_tol(asin(val_3), s21_asin(val_3), TEST_EPS);
  ck_assert_double_eq_tol(asin(val_4), s21_asin(val_4), TEST_EPS);
}
END_TEST

START_TEST(asin_tests_specific) {
  double val_1 = s21_NAN;
  double val_2 = -s21_INF;
  double val_3 = 5;
  double val_4 = -1000;
  ck_assert_double_nan(s21_asin(val_1));
  ck_assert_double_nan(s21_asin(val_2));
  ck_assert_double_nan(s21_asin(val_3));
  ck_assert_double_nan(s21_asin(val_4));
}
END_TEST

START_TEST(atan_tests_normal) {
  double val_1 = 0;
  double val_2 = -1;
  double val_3 = 0.3443234;
  double val_4 = 1;
  ck_assert_ldouble_eq_tol(atan(val_1), s21_atan(val_1), TEST_EPS);
  ck_assert_ldouble_eq_tol(atan(val_2), s21_atan(val_2), TEST_EPS);
  ck_assert_ldouble_eq_tol(atan(val_3), s21_atan(val_3), TEST_EPS);
  ck_assert_ldouble_eq_tol(atan(val_4), s21_atan(val_4), TEST_EPS);
}
END_TEST

START_TEST(atan_tests_specific) {
  double val_1 = s21_NAN;
  double val_2 = s21_INF;
  double val_3 = -9000.0002;
  double val_4 = 2;
  ck_assert_double_nan(s21_atan(val_1));
  ck_assert_ldouble_eq(atan(val_2), s21_atan(val_2));
  ck_assert_ldouble_eq_tol(atan(val_3), s21_atan(val_3), TEST_EPS);
  ck_assert_ldouble_eq_tol(atan(val_4), s21_atan(val_4), TEST_EPS);
}
END_TEST

START_TEST(cos_tests_normal) {
  double val_1 = 1200000;
  double val_2 = -14.96;
  double val_3 = s21_E;
  double val_4 = 0;
  double val_5 = s21_PI;
  ck_assert_ldouble_eq_tol(cos(val_1), s21_cos(val_1), TEST_EPS);
  ck_assert_ldouble_eq_tol(cos(val_2), s21_cos(val_2), TEST_EPS);
  ck_assert_ldouble_eq_tol(cos(val_3), s21_cos(val_3), TEST_EPS);
  ck_assert_ldouble_eq_tol(cos(val_4), s21_cos(val_4), TEST_EPS);
  ck_assert_ldouble_eq_tol(cos(val_5), s21_cos(val_5), TEST_EPS);
  for (double i = -s21_PI; i < s21_PI; i += 0.01) {
    ck_assert_ldouble_eq_tol(cos(i), s21_cos(i), TEST_EPS);
  }
}
END_TEST

START_TEST(cos_tests_specific) {
  double val_1 = s21_INF;
  double val_2 = -s21_INF;
  double val_3 = s21_NAN;
  double val_4 = s21_EPS;
  double val_5 = -999990.312312314;
  ck_assert_double_nan(s21_cos(val_1));
  ck_assert_double_nan(s21_cos(val_2));
  ck_assert_double_nan(s21_cos(val_3));
  ck_assert_ldouble_eq_tol(cos(val_4), s21_cos(val_4), TEST_EPS);
  ck_assert_ldouble_eq_tol(cos(val_5), s21_cos(val_5), TEST_EPS);
}
END_TEST

START_TEST(exp_tests_normal) {
  double val_1 = 18;
  double val_2 = -14.96;
  double val_3 = 1;
  double val_4 = 0;
  double val_5 = -1;
  ck_assert_double_eq_tol(exp(val_1), s21_exp(val_1), TEST_EPS);
  ck_assert_double_eq_tol(exp(val_2), s21_exp(val_2), TEST_EPS);
  ck_assert_double_eq_tol(exp(val_3), s21_exp(val_3), TEST_EPS);
  ck_assert_double_eq_tol(exp(val_4), s21_exp(val_4), TEST_EPS);
  ck_assert_double_eq_tol(exp(val_5), s21_exp(val_5), TEST_EPS);
}
END_TEST

START_TEST(exp_tests_specific) {
  double val_1 = s21_INF;
  double val_2 = -s21_INF;
  double val_3 = s21_NAN;
  double val_4 = s21_EPS;
  double val_5 = 25048.369;
  ck_assert_ldouble_eq(exp(val_1), s21_exp(val_1));
  ck_assert_ldouble_eq(exp(val_2), s21_exp(val_2));
  ck_assert_double_nan(s21_exp(val_3));
  ck_assert_ldouble_eq_tol(exp(val_4), s21_exp(val_4), TEST_EPS);
  ck_assert_ldouble_eq(exp(val_5), s21_exp(val_5));
}
END_TEST

START_TEST(fmod_tests_normal) {
  double val_a1 = 10.0, val_b1 = 3.0;
  double val_a2 = 9.6446, val_b2 = 0.42342;
  double val_a3 = 5.4, val_b3 = 765.3;
  ck_assert_ldouble_eq_tol(fmod(val_a1, val_b1), s21_fmod(val_a1, val_b1),
                           TEST_EPS);
  ck_assert_ldouble_eq_tol(fmod(val_a2, val_b2), s21_fmod(val_a2, val_b2),
                           TEST_EPS);
  ck_assert_ldouble_eq_tol(fmod(val_a3, val_b3), s21_fmod(val_a3, val_b3),
                           TEST_EPS);
  long double f_value[] = {4234, 20,      234,    -756,   435,    24.342, 345,
                           645,  2.24234, 53.534, 6456,   1,      0,      -1,
                           34,   64,      9786,   534.53, 756.56, 754};
  long double s_value[] = {8898.07,  6881.63, 1537.52, 5783.31, 2675.7,
                           5560.06,  1240.69, 9348.66, 103.02,  4153.9,
                           250,      29.3,    96.456,  86,      29.5,
                           302.0234, 1,       1947.38, 953,     42};
  for (int i = 0; i < 20; i++) {
    ck_assert_ldouble_eq_tol(fmod(f_value[i], s_value[i]),
                             s21_fmod(f_value[i], s_value[i]), TEST_EPS);
  }
}
END_TEST

START_TEST(fmod_tests_specific) {
  double val_1 = s21_INF;
  double val_2 = -s21_INF;
  double val_3 = s21_NAN;
  ck_assert_double_nan(s21_fmod(val_2, val_1));
  ck_assert_double_nan(s21_fmod(val_3, val_1));
  ck_assert_double_nan(s21_fmod(val_2, val_3));
  ck_assert_double_nan(s21_fmod(val_3, val_2));
  ck_assert_double_nan(s21_fmod(val_1, val_2));
  ck_assert_ldouble_eq(fmod(100, val_1), s21_fmod(100, val_1));
  ck_assert_ldouble_eq(fmod(100, val_2), s21_fmod(100, val_2));
  ck_assert_ldouble_eq(fmod(0, val_1), s21_fmod(0, val_1));
  ck_assert_ldouble_eq(fmod(0, val_2), s21_fmod(0, val_2));
  ck_assert_double_nan(s21_fmod(0, val_3));
  ck_assert_double_nan(s21_fmod(val_1, 0));
  ck_assert_double_nan(s21_fmod(val_2, 0));
  ck_assert_double_nan(s21_fmod(val_3, 0));
}
END_TEST

START_TEST(log_tests_normal) {
  double val_1 = 26941.289;
  double val_2 = -12.36;
  double val_3 = 1;
  double val_4 = 0;
  double val_5 = -1;
  ck_assert_ldouble_eq_tol(log(val_1), s21_log(val_1), TEST_EPS);
  ck_assert_double_nan(s21_log(val_2));
  ck_assert_ldouble_eq(log(val_3), s21_log(val_3));
  ck_assert_ldouble_eq(log(val_4), s21_log(val_4));
  ck_assert_double_nan(s21_log(val_5));
  for (double i = 0.1; i < 10; i += 0.1) {
    ck_assert_ldouble_eq_tol(log(i), s21_log(i), TEST_EPS);
  }
  for (double i = 0.1; i < 2; i += 0.01) {
    ck_assert_ldouble_eq_tol(log(i), s21_log(i), TEST_EPS);
  }
}
END_TEST

START_TEST(log_tests_specific) {
  double val_1 = s21_INF;
  double val_2 = -s21_INF;
  double val_3 = s21_NAN;
  double val_4 = s21_EPS;
  double val_5 = -999990.312312314;
  ck_assert_ldouble_eq(log(val_1), s21_log(val_1));
  ck_assert_double_nan(s21_log(val_2));
  ck_assert_double_nan(s21_log(val_3));
  ck_assert_ldouble_eq_tol(log(val_4), s21_log(val_4), TEST_EPS);
  ck_assert_double_nan(s21_log(val_5));
}
END_TEST

START_TEST(sin_tests_normal) {
  double val_1 = 1000000;
  double val_2 = -14.96;
  double val_3 = s21_PI;
  double val_4 = 0;
  double val_5 = s21_E;
  ck_assert_double_eq_tol(sin(val_1), s21_sin(val_1), TEST_EPS);
  ck_assert_double_eq_tol(sin(val_2), s21_sin(val_2), TEST_EPS);
  ck_assert_double_eq_tol(sin(val_3), s21_sin(val_3), TEST_EPS);
  ck_assert_double_eq_tol(sin(val_4), s21_sin(val_4), TEST_EPS);
  ck_assert_double_eq_tol(sin(val_5), s21_sin(val_5), TEST_EPS);
}
END_TEST

START_TEST(sin_tests_specific) {
  double val_1 = s21_INF;
  double val_2 = -s21_INF;
  double val_3 = s21_NAN;
  double val_4 = s21_EPS;
  double val_5 = -2345620.020003444222;
  ck_assert_double_nan(s21_sin(val_1));
  ck_assert_double_nan(s21_sin(val_2));
  ck_assert_double_nan(s21_sin(val_3));
  ck_assert_ldouble_eq_tol(sin(val_4), s21_sin(val_4), TEST_EPS);
  ck_assert_ldouble_eq_tol(sin(val_5), s21_sin(val_5), TEST_EPS);
}
END_TEST

START_TEST(tan_tests_normal) {
  double val_1 = 6987000;
  double val_2 = -15.962;
  double val_3 = s21_PI;
  ck_assert_ldouble_eq_tol(tan(val_1), s21_tan(val_1), TEST_EPS);
  ck_assert_ldouble_eq_tol(tan(val_2), s21_tan(val_2), TEST_EPS);
  ck_assert_ldouble_eq_tol(tan(val_3), s21_tan(val_3), TEST_EPS);
  for (double i = -100; i < 100; i += 2) {
    ck_assert_ldouble_eq_tol(tan(i), s21_tan(i), TEST_EPS);
  }
  for (double i = -1; i < 1; i += 0.02) {
    ck_assert_ldouble_eq_tol(tan(i), s21_tan(i), TEST_EPS);
  }
}
END_TEST

START_TEST(tan_tests_specific) {
  double val_1 = s21_INF;
  double val_2 = -s21_INF;
  double val_3 = s21_NAN;
  double val_4 = s21_EPS;
  double val_5 = -12230.3123123143334;
  ck_assert_double_nan(s21_tan(val_1));
  ck_assert_double_nan(s21_tan(val_2));
  ck_assert_double_nan(s21_tan(val_3));
  ck_assert_ldouble_eq_tol(tan(val_4), s21_tan(val_4), TEST_EPS);
  ck_assert_ldouble_eq_tol(tan(val_5), s21_tan(val_5), TEST_EPS);
}
END_TEST

START_TEST(pow_tests_normal) {
  double val_1 = 20;
  double val_2 = 0.4;
  double val_3 = -20;
  double val_4 = 0;
  double val_5 = 12.69;
  ck_assert_ldouble_eq_tol(pow(val_1, val_2), s21_pow(val_1, val_2), TEST_EPS);
  ck_assert_double_nan(s21_pow(val_3, val_2));
  ck_assert_ldouble_eq_tol(pow(val_5, val_4), s21_pow(val_5, val_4), TEST_EPS);
  ck_assert_ldouble_eq_tol(pow(val_4, val_4), s21_pow(val_4, val_4), TEST_EPS);
}
END_TEST

START_TEST(pow_tests_specific) {
  double val_1 = s21_INF;
  double val_2 = -s21_INF;
  double val_3 = s21_NAN;
  double val_4 = 0;
  ck_assert_ldouble_eq(pow(val_1, val_1), s21_pow(val_1, val_1));
  ck_assert_ldouble_eq(pow(val_2, val_2), s21_pow(val_2, val_2));
  ck_assert_double_nan(s21_pow(val_3, val_3));
  ck_assert_double_nan(s21_pow(val_1, val_3));
  ck_assert_double_nan(s21_pow(val_3, val_1));
  ck_assert_double_nan(s21_pow(val_2, val_3));
  ck_assert_double_nan(s21_pow(val_3, val_2));
  ck_assert_ldouble_eq(pow(val_2, val_1), s21_pow(val_2, val_1));
  ck_assert_ldouble_eq(pow(val_1, val_4), s21_pow(val_1, val_4));
  ck_assert_ldouble_eq(pow(val_2, val_4), s21_pow(val_2, val_4));
  ck_assert_ldouble_eq(pow(val_3, val_4), s21_pow(val_3, val_4));
  ck_assert_ldouble_eq(pow(val_4, val_1), s21_pow(val_4, val_1));
  ck_assert_ldouble_eq(pow(val_4, val_2), s21_pow(val_4, val_2));
  ck_assert_double_nan(s21_pow(val_4, val_3));
  ck_assert_ldouble_eq(pow(val_4, val_4), s21_pow(val_4, val_4));
}
END_TEST

Suite *s21_test_suite(void) {
  Suite *suite = suite_create("s21_tests");
  TCase *test_case = tcase_create("Core");

  tcase_add_test(test_case, abs_tests_normal);
  tcase_add_test(test_case, abs_tests_specific);

  tcase_add_test(test_case, fabs_tests_normal);
  tcase_add_test(test_case, fabs_tests_specific);

  tcase_add_test(test_case, ceil_tests_normal);
  tcase_add_test(test_case, ceil_tests_specific);

  tcase_add_test(test_case, sqrt_tests_normal);
  tcase_add_test(test_case, sqrt_tests_specific);

  tcase_add_test(test_case, floor_tests_normal);
  tcase_add_test(test_case, floor_tests_specific);

  tcase_add_test(test_case, acos_tests_normal);
  tcase_add_test(test_case, acos_tests_specific);

  tcase_add_test(test_case, asin_tests_normal);
  tcase_add_test(test_case, asin_tests_specific);

  tcase_add_test(test_case, atan_tests_normal);
  tcase_add_test(test_case, atan_tests_specific);

  tcase_add_test(test_case, cos_tests_normal);
  tcase_add_test(test_case, cos_tests_specific);

  tcase_add_test(test_case, sin_tests_normal);
  tcase_add_test(test_case, sin_tests_specific);

  tcase_add_test(test_case, tan_tests_normal);
  tcase_add_test(test_case, tan_tests_specific);

  tcase_add_test(test_case, exp_tests_normal);
  tcase_add_test(test_case, exp_tests_specific);

  tcase_add_test(test_case, fmod_tests_normal);
  tcase_add_test(test_case, fmod_tests_specific);

  tcase_add_test(test_case, log_tests_normal);
  tcase_add_test(test_case, log_tests_specific);

  tcase_add_test(test_case, pow_tests_normal);
  tcase_add_test(test_case, pow_tests_specific);

  suite_add_tcase(suite, test_case);

  return suite;
}

int main(void) {
  Suite *suite = s21_test_suite();
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_VERBOSE);

  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
