#include <check.h>

#include "smart_calc.h"

START_TEST(rpn_1) {
  char result[255] = {'\0'};
  in_rpn("1*2+3", result);
  ck_assert_str_eq(result, "1 2 * 3 + ");
}
END_TEST

START_TEST(rpn_2) {
  char result[255] = {'\0'};
  in_rpn("1+2*3", result);
  ck_assert_str_eq(result, "1 2 3 * + ");
}
END_TEST

START_TEST(rpn_3) {
  char result[255] = {'\0'};
  in_rpn("1+2*3/4-5", result);
  ck_assert_str_eq(result, "1 2 3 * 4 / + 5 - ");
}
END_TEST

START_TEST(rpn_4) {
  char result[255] = {'\0'};
  in_rpn("1+2*(3/4-5)", result);
  ck_assert_str_eq(result, "1 2 3 4 / 5 - * + ");
}
END_TEST

START_TEST(rpn_5) {
  char result[255] = {'\0'};
  in_rpn("(1+2)/44*(3/(4-5))", result);
  ck_assert_str_eq(result, "1 2 + 44 / 3 4 5 - / * ");
}
END_TEST

START_TEST(rpn_6) {
  char result[255] = {'\0'};
  in_rpn("(1+2)/(44*(3/(4-5)))", result);
  ck_assert_str_eq(result, "1 2 + 44 3 4 5 - / * / ");
}
END_TEST

START_TEST(rpn_7) {
  char result[255] = {'\0'};
  in_rpn("+3^(5-2)", result);
  ck_assert_str_eq(result, "3 5 2 - ^ ");
}
END_TEST

START_TEST(rpn_9) {
  char result[255] = {'\0'};
  in_rpn("2.34-43.123", result);
  ck_assert_str_eq(result, "2.34 43.123 - ");
}
END_TEST

START_TEST(rpn_10) {
  char result[255] = {'\0'};
  in_rpn("2.34-43.123/(456.312-654)*123.543-(42.123+534.432)", result);
  ck_assert_str_eq(
      result, "2.34 43.123 456.312 654 - / 123.543 * - 42.123 534.432 + - ");
}
END_TEST

START_TEST(rpn_18) {
  char result[255] = {'\0'};
  in_rpn("2^123.543", result);
  ck_assert_str_eq(result, "2 123.543 ^ ");
}
END_TEST

START_TEST(rpn_19) {
  char result[255] = {'\0'};
  in_rpn("(2+5/3)^123.543", result);
  ck_assert_str_eq(result, "2 5 3 / + 123.543 ^ ");
}
END_TEST

START_TEST(rpn_20) {
  char result[255] = {'\0'};
  in_rpn("-(-2)+3", result);
  ck_assert_str_eq(result, "--2 0 - 3 + 0 - ");
}
END_TEST

START_TEST(rpn_21) {
  char result[255] = {'\0'};
  in_rpn("10%3", result);
  ck_assert_str_eq(result, "10 3 % ");
}
END_TEST

START_TEST(rpn_22) {
  char result[255] = {'\0'};
  in_rpn("15%4", result);
  ck_assert_str_eq(result, "15 4 % ");
}
END_TEST

START_TEST(rpn_23) {
  char result[255] = {'\0'};
  in_rpn("5 - 2 / 2", result);
  ck_assert_str_eq(result, "5 2 2 / - ");
}
END_TEST

START_TEST(rpn_24) {
  char result[255] = {'\0'};
  in_rpn("0", result);
  ck_assert_str_eq(result, "0 ");
}
END_TEST

START_TEST(rpn_25) {
  char result[255] = {'\0'};
  in_rpn("acos(5)", result);
  ck_assert_str_eq(result, "5 C ");
}
END_TEST

START_TEST(rpn_26) {
  char result[255] = {'\0'};
  in_rpn("sin(cos(5))", result);
  ck_assert_str_eq(result, "5 c s ");
}
END_TEST

START_TEST(rpn_27) {
  char result[255] = {'\0'};
  in_rpn("sqrt(5)", result);
  ck_assert_str_eq(result, "5 Q ");
}
END_TEST

START_TEST(rpn_28) {
  char result[255] = {'\0'};
  in_rpn("", result);
  ck_assert_str_eq(result, "");
}
END_TEST

START_TEST(rpn_29) {
  char result[255] = {'\0'};
  in_rpn("-1/(-1)", result);
  ck_assert_str_eq(result, "-1 -1 0 - / 0 - ");
}
END_TEST

START_TEST(rpn_31) {
  char result[255] = {'\0'};
  in_rpn("(-1)/(-1)", result);
  ck_assert_str_eq(result, "-1 0 - -1 0 - / ");
}
END_TEST

START_TEST(rpn_32) {
  char result[255] = {'\0'};
  in_rpn("sin(45)", result);
  ck_assert_str_eq(result, "45 s ");
}
END_TEST

START_TEST(rpn_33) {
  char result[255] = {'\0'};
  in_rpn("cos(45)", result);
  ck_assert_str_eq(result, "45 c ");
}
END_TEST

START_TEST(rpn_34) {
  char result[255] = {'\0'};
  in_rpn("asin(45)", result);
  ck_assert_str_eq(result, "45 S ");
}
END_TEST

START_TEST(rpn_35) {
  char result[255] = {'\0'};
  in_rpn("tan(45)", result);
  ck_assert_str_eq(result, "45 t ");
}
END_TEST

START_TEST(rpn_36) {
  char result[255] = {'\0'};
  in_rpn("atan(45)", result);
  ck_assert_str_eq(result, "45 T ");
}
END_TEST

START_TEST(rpn_37) {
  char result[255] = {'\0'};
  in_rpn("sqrt(45)", result);
  ck_assert_str_eq(result, "45 Q ");
}
END_TEST

START_TEST(rpn_38) {
  char result[255] = {'\0'};
  in_rpn("ln(45)", result);
  ck_assert_str_eq(result, "45 l ");
}
END_TEST

START_TEST(rpn_39) {
  char result[255] = {'\0'};
  in_rpn("log(45)", result);
  ck_assert_str_eq(result, "45 L ");
}
END_TEST

START_TEST(calc_1) {
  double calc = 0.0;
  char result[255] = {'\0'};
  in_rpn("3 - 2 * 4", result);
  calc = calc_rpn(result);
  ck_assert_double_eq(calc, -5);
}
END_TEST

START_TEST(calc_2) {
  double calc = 0.0;
  char result[255] = {'\0'};
  in_rpn("25 % (5 + 3) / 2 ^ 3", result);
  calc = calc_rpn(result);
  ck_assert_double_eq(calc, 0.125);
}
END_TEST

START_TEST(calc_3) {
  double calc = 0.0;
  char result[255] = {'\0'};
  in_rpn("2 * sqrt(100)", result);
  calc = calc_rpn(result);
  ck_assert_double_eq(calc, 20);
}
END_TEST

START_TEST(calc_4) {
  double calc = 0.0;
  char result[255] = {'\0'};
  in_rpn("2 * log(100) * (-1)", result);
  calc = calc_rpn(result);
  double roundedCalc = round(calc * 10000000) / 10000000;
  ck_assert_double_eq(roundedCalc, -4);
}
END_TEST

START_TEST(calc_5) {
  double calc = 0.0;
  char result[255] = {'\0'};
  in_rpn("3 - 2 * sin(5) / atan(1)", result);
  calc = calc_rpn(result);
  double roundedCalc = round(calc * 10000000) / 10000000;
  ck_assert_double_eq(roundedCalc, 5.4418806);
}
END_TEST

START_TEST(calc_6) {
  double calc = 0.0;
  char result[255] = {'\0'};
  in_rpn("tan(1) - cos(5) + (asin(1) * acos(-1))", result);
  calc = calc_rpn(result);
  double roundedCalc = round(calc * 10000000) / 10000000;
  ck_assert_double_eq(roundedCalc, 6.2085477);
}
END_TEST

START_TEST(calc_7) {
  double calc = 0.0;
  char result[255] = {'\0'};
  in_rpn("ln(2)", result);
  calc = calc_rpn(result);
  double roundedCalc = round(calc * 10000000) / 10000000;
  ck_assert_double_eq(roundedCalc, 0.6931472);
}
END_TEST

START_TEST(error_1) {
  int result;
  char input[255] = "2^(2+8)";
  result = error_input(input);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(error_2) {
  int result;
  char input[255] = "2^(2+8";
  result = error_input(input);
  ck_assert_int_eq(result, 0);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, rpn_1);
  tcase_add_test(tc1_1, rpn_2);
  tcase_add_test(tc1_1, rpn_3);
  tcase_add_test(tc1_1, rpn_4);
  tcase_add_test(tc1_1, rpn_5);
  tcase_add_test(tc1_1, rpn_6);
  tcase_add_test(tc1_1, rpn_7);

  tcase_add_test(tc1_1, rpn_9);
  tcase_add_test(tc1_1, rpn_10);

  tcase_add_test(tc1_1, rpn_18);
  tcase_add_test(tc1_1, rpn_19);
  tcase_add_test(tc1_1, rpn_20);
  tcase_add_test(tc1_1, rpn_21);
  tcase_add_test(tc1_1, rpn_22);
  tcase_add_test(tc1_1, rpn_23);
  tcase_add_test(tc1_1, rpn_24);
  tcase_add_test(tc1_1, rpn_25);
  tcase_add_test(tc1_1, rpn_26);
  tcase_add_test(tc1_1, rpn_27);
  tcase_add_test(tc1_1, rpn_28);
  tcase_add_test(tc1_1, rpn_29);

  tcase_add_test(tc1_1, rpn_31);
  tcase_add_test(tc1_1, rpn_32);
  tcase_add_test(tc1_1, rpn_33);
  tcase_add_test(tc1_1, rpn_34);
  tcase_add_test(tc1_1, rpn_35);
  tcase_add_test(tc1_1, rpn_36);
  tcase_add_test(tc1_1, rpn_37);
  tcase_add_test(tc1_1, rpn_38);
  tcase_add_test(tc1_1, rpn_39);

  tcase_add_test(tc1_1, calc_1);
  tcase_add_test(tc1_1, calc_2);
  tcase_add_test(tc1_1, calc_3);
  tcase_add_test(tc1_1, calc_4);
  tcase_add_test(tc1_1, calc_5);
  tcase_add_test(tc1_1, calc_6);
  tcase_add_test(tc1_1, calc_7);

  tcase_add_test(tc1_1, error_1);
  tcase_add_test(tc1_1, error_2);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
