#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/conversion.h"
#include "../src/calculations.h"
#include "minunit.h"

int tests_run = 0;

static char *testSimple2() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(16, "0123456789ABCDEF", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
                              "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB", '+', result);
    //Create Error-Message
    char *s1 = "error: AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA + BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB (base 16) != ";
    char *s2 = " it should be 166666666666666666666666666666666665";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "166666666666666666666666666666666665"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase2Num1() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-2, "01", "1011", "1110", '+', result);
    //Create Error-Message
    char *s1 = "error: 1011 + 1110 (base -2) != ";
    char *s2 = " it should be 110001";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "110001"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase2Num2() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-2, "01", "101010", "101100", '+', result);
    //Create Error-Message
    char *s1 = "error: 101010 + 101100 (base -2) != ";
    char *s2 = " it should be 11110110";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "11110110"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase2Num3() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-2, "01", "00101", "00111", '+', result);
    //Create Error-Message
    char *s1 = "error: 00101 + 00111 (base -2) != ";
    char *s2 = " it should be 11000";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "11000"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase8Num1() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-8, "01234567", "663562", "147547", '+', result);
    //Create Error-Message
    char *s1 = "error: 663562 + 147547 (base -8) != ";
    char *s2 = " it should be 611111";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "611111"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase10Num1() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-10, "0123456789", "50", "50", '+', result);
    //Create Error-Message
    char *s1 = "error: 50 + 50 (base -10) != ";
    char *s2 = " it should be 1900";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "1900"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase16Num1() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-16, "0123456789ABCDEF", "4E", "4E", '+', result);
    //Create Error-Message
    char *s1 = "error: 4E + 4E (base -16) != ";
    char *s2 = " it should be 7C";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "7C"));
    //Free memory for Error-Message
    free(message);
    return 0;
}


static char *testPosBase2Num1() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(2, "01", "0", "1", '+', result);
    //Create Error-Message
    char *s1 = "error: 0 + 1 (base 2) != ";
    char *s2 = " it should be 1";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "1"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase16Num1() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(16, "0123456789ABCDEF", "8AB", "B78", '+', result);
    //Create Error-Message
    char *s1 = "error: 8AB + B78 (base 16) != ";
    char *s2 = " it should be 1423";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "1423"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase16Num2() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(16, "0123456789ABCDEF", "DAD", "DAD", '+', result);
    //Create Error-Message
    char *s1 = "error: DAD + DAD (base 16) != ";
    char *s2 = " it should be 1B5A";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "1B5A"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase30Num1() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(30, "0123456789ABCDEFGHIJKLMNOPQRST", "2CG", "37TF", '+', result);
    //Create Error-Message
    char *s1 = "error: 2CG + 37TF (base 30) != ";
    char *s2 = " it should be 3AC1";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "3AC1"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase30Num2() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(30, "0123456789ABCDEFGHIJKLMNOPQRST", "3ABR", "38F", '+', result);
    //Create Error-Message
    char *s1 = "error: 3ABR + 38F (base 30) != ";
    char *s2 = " it should be 3DKC";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "3DKC"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase36Num1() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(36, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ZAB03", "93ZUH", '+', result);
    //Create Error-Message
    char *s1 = "error: ZAB03 + 93ZUH (base 36) != ";
    char *s2 = " it should be 18EAUK";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "18EAUK"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase10WithNegNumbersNum1() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(10, "0123456789", "-356", "-222", '+', result);
    //Create Error-Message
    char *s1 = "error: (-356) + (-222) (base 10) != ";
    char *s2 = " it should be (-578)";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "-578"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase14WithNegNumbersNum1() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(14, "0123456789ABCD", "-DA", "DB", '+', result);
    //Create Error-Message
    char *s1 = "error: (-DA) + DB (base 14) != ";
    char *s2 = " it should be 1";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "1"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *simple_test() {
    char result[50];
    _V1arithmetic_op_any_base(8, "01234567", "25", "13", '-', result);
    //Create Error-Message
    char *s1 = "error: 25 - 13 (base 8) != ";
    char *s2 = " it should be 12";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "12"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase2Num1m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-2, "01", "1011", "1110", '-', result);
    //Create Error-Message
    char *s1 = "error: 1011 - 1110 (base -2) != ";
    char *s2 = " it should be 1101";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "1101"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase2Num3m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-2, "01", "110100", "110101", '-', result);
    //Create Error-Message
    char *s1 = "error: 110100 - 110101 (base -2) != ";
    char *s2 = " it should be 11";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "11"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase2Num2m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-2, "01", "101010", "101100", '-', result);
    //Create Error-Message
    char *s1 = "error: 101010 - 101100 (base -2) != ";
    char *s2 = " it should be 1110";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "1110"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase2Num4m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-2, "01", "1001", "11011", '-', result);
    //Create Error-Message
    char *s1 = "error: 1001 - 11011 (base -2) != ";
    char *s2 = " it should be 110110";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "110110"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase2Num5m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-2, "01", "11", "111111", '-', result);
    //Create Error-Message
    char *s1 = "error: 11 - 111111 (base -2) != ";
    char *s2 = " it should be 10100";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "10100"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase2Num6m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-2, "01", "0", "110100", '-', result);
    //Create Error-Message
    char *s1 = "error: 0 - 110100 (base -2) != ";
    char *s2 = " it should be 11100";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "11100"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase10Num1m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-10, "0123456789", "29", "16", '-', result);
    //Create Error-Message
    char *s1 = "error: 29 - 16 (base -10) != ";
    char *s2 = " it should be 13";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "13"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase16Num1m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-16, "0123456789ABCDEF", "4E", "4E", '-', result);
    //Create Error-Message
    char *s1 = "error: 4E - 4E (base -16) != ";
    char *s2 = " it should be 0";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "0"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase30Num1m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-30, "0123456789ABCDEFGHIJKLMNOPQRST", "2CG", "37TF", '-', result);
    //Create Error-Message
    char *s1 = "error: 2CG - 37TF (base -30) != ";
    char *s2 = " it should be 1SQD1";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "1SQD1"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase13Num1m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-13, "0123456789ABC", "58157", "58157", '-', result);
    //Create Error-Message
    char *s1 = "error: 58157 - 58157 (base -13) != ";
    char *s2 = " it should be 0";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "0"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase2Num1m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(2, "01", "1010101010101010101010101010", "1010101010101010101010101010", '-', result);
    //Create Error-Message
    char *s1 = "error: 1010101010101010101010101010 - 1010101010101010101010101010 (base 2) != ";
    char *s2 = " it should be 0";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "0"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase8Num1m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(8, "01234567", "2452364", "472563152252", '-', result);
    //Create Error-Message
    char *s1 = "error: 2452364 - 472563152252 (base 8) != ";
    char *s2 = " it should be -472560477666";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "-472560477666"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase16Num2m() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(16, "0123456789ABCDEF", "-534A25C22FF", "-545DDDD568", '-', result);
    //Create Error-Message
    char *s1 = "error: -534A25C22FF - -545DDDD568 (base 16) != ";
    char *s2 = " it should be -4E0447E4D97";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "-4E0447E4D97"));
    //Free memory for Error-Message
    free(message);
    return 0;
}
//


static char *testPosBase10Num1k() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(10, "0123456789", "5", "10", '*', result);
    //Create Error-Message
    char *s1 = "error: 5 * 10 (base 10) != ";
    char *s2 = " it should be 50";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "50"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase10Num2k() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(10, "0123456789", "356", "300", '*', result);
    //Create Error-Message
    char *s1 = "error: 356 * 300 (base 10) != ";
    char *s2 = " it should be 106800";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "106800"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase10Num3k() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(10, "0123456789", "234654", "6576", '*', result);
    //Create Error-Message
    char *s1 = "error: 234654 * 6576 (base 10) != ";
    char *s2 = " it should be 1543084704";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "1543084704"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase10Num4k() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(10, "0123456789", "9999", "9999", '*', result);
    //Create Error-Message
    char *s1 = "error: 9999 * 9999 (base 10) != ";
    char *s2 = " it should be 99980001";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "99980001"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase10WithNegNumbersNum1k() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(10, "0123456789", "-356", "-222", '*', result);
    //Create Error-Message
    char *s1 = "error: (-356) * (-222) (base 10) != ";
    char *s2 = " it should be 79032";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "79032"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase14WithNegNumbersNum1k() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(14, "0123456789ABCD", "-DA", "DB", '*', result);
    //Create Error-Message
    char *s1 = "error: (-DA) * DB (base 14) != ";
    char *s2 = " it should be (-D70C)";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "-D70C"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase2Num1k() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-2, "01", "1011", "1110", '*', result);
    //Create Error-Message
    char *s1 = "error: 1011 * 1110 (base -2) != ";
    char *s2 = " it should be 1001010";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "1001010"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase2Num2k() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-2, "01", "101010", "101100", '*', result);
    //Create Error-Message
    char *s1 = "error: 101010 * 101100 (base -2) != ";
    char *s2 = " it should be 1101000111000";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "1101000111000"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase2Num3k() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-2, "01", "00101", "00111", '*', result);
    //Create Error-Message
    char *s1 = "error: 00101 * 00111 (base -2) != ";
    char *s2 = " it should be 10011";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "10011"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase8Num1k() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-8, "01234567", "663562", "147547", '*', result);
    //Create Error-Message
    char *s1 = "error: 663562 * 147547 (base -8) != ";
    char *s2 = " it should be 47476706716";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "47476706716"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase8Num2k() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-8, "01234567", "7727", "754", '*', result);
    //Create Error-Message
    char *s1 = "error: 7727 * 754 (base -8) != ";
    char *s2 = " it should be 13043204";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "13043204"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testNegBase10Num1k() {
    //Calculation
    char result[50];
    _V1arithmetic_op_any_base(-10, "0123456789", "50", "50", '*', result);
    //Create Error-Message
    char *s1 = "error: 50 * 50 (base -10) != ";
    char *s2 = " it should be 18500";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "18500"));
    //Free memory for Error-Message
    free(message);
    return 0;
}


static char *testPosBaseBigNumber() {
    //Calculation
    char result[50];
    // creation of alphabet
    unsigned char *alphabet = malloc(201);
    char offset = 1;
    for (unsigned char i = 0; i < 200; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        alphabet[i] = i + offset;
    }
    alphabet[200] = 0;
    // creation of first number
    unsigned char *z1 = malloc(5);
    offset = 1;
    for (unsigned char i = 0; i < 4; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z1[i] = i + offset + 100;
    }
    z1[4] = 0;
    // creation of second number
    unsigned char *z2 = malloc(5);
    offset = 1;
    for (unsigned char i = 0; i < 4; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z2[i] = i + offset + 120;
    }
    z2[4] = 0;
    // creation of expected result
    // IMPORTANT: Plus one everywhere because nullbyte not included, +2 for all chars grater than '-'
    unsigned char *expected = malloc(6);
    expected[0] = (unsigned char) 2;
    expected[1] = (unsigned char) 20;
    expected[2] = (unsigned char) 22;
    expected[3] = (unsigned char) 24;
    expected[4] = (unsigned char) 25;
    expected[5] = 0;
    // calculation
    _V1arithmetic_op_any_base(200, (char *) alphabet, (char *) z1, (char *) z2, '+', result);
    //Create Error-Message
    char *s1 = "error: efgh + yz{| (base 200) != ";
    char *s2 = " it should be {0x02, 0x14, 0x16, 0x18, 0x19}";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, (char *) expected));
    //Free memory for Error-Message
    free(message);
    free(alphabet);
    free(z1);
    free(z2);
    free(expected);
    return 0;
}

// Big test case for large numbers with positive base
static char *testPosBaseBigNumberMul() {
    //Calculation
    char result[50];
    // creation of alphabet
    unsigned char *alphabet = malloc(255);
    char offset = 1;
    for (unsigned char i = 0; i < 254; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        alphabet[i] = i + offset;
    }
    alphabet[254] = 0;
    // creation of first number
    unsigned char *z1 = malloc(5);
    offset = 1;
    for (unsigned char i = 0; i < 4; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z1[i] = i + offset + 20;
    }
    z1[4] = 0;
    // creation of second number
    unsigned char *z2 = malloc(5);
    offset = 1;
    for (unsigned char i = 0; i < 4; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z2[i] = i + offset + 30;
    }
    z2[4] = 0;
    // creation of expected result
    // IMPORTANT: Plus one everywhere because nullbyte not included, +2 for all chars grater than '-'
    unsigned char *expected = malloc(9);
    expected[0] = (unsigned char) 3;
    expected[1] = (unsigned char) 98;
    expected[2] = (unsigned char) 243;
    expected[3] = (unsigned char) 185;
    expected[4] = (unsigned char) 174;
    expected[5] = (unsigned char) 85;
    expected[6] = (unsigned char) 196;
    expected[7] = (unsigned char) 253;
    expected[8] = 0;
    // calculation
    _V1arithmetic_op_any_base(254, (char *) alphabet, (char *) z1, (char *) z2, '*', result);
    //Create Error-Message
    char *s1 = "error: {0x15, 0x16, 0x17, 0x18} * {0x1F, 0x20, 0x21, 0x22} (base 254) != ";
    char *s2 = " it should be {0x03, 0x62, 0xF3, 0xB9, 0xAE, 0x55, 0xC4, 0xFD}";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, (char *) expected));
    //Free memory for Error-Message
    free(message);
    free(alphabet);
    free(z1);
    free(z2);
    free(expected);
    return 0;
}

// Big test case for large numbers with negative base
static char *testNegBaseBigNumberMul() {
    //Calculation
    char result[50];
    // creation of alphabet
    unsigned char *alphabet = malloc(255);
    char offset = 1;
    for (unsigned char i = 0; i < 254; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        alphabet[i] = i + offset;
    }
    alphabet[254] = 0;
    // creation of first number
    unsigned char *z1 = malloc(5);
    offset = 1;
    for (unsigned char i = 0; i < 4; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z1[i] = i + offset + 20;
    }
    z1[4] = 0;
    // creation of second number
    unsigned char *z2 = malloc(5);
    offset = 1;
    for (unsigned char i = 0; i < 4; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z2[i] = i + offset + 30;
    }
    z2[4] = 0;
    // creation of expected result
    // IMPORTANT: Plus one everywhere because nullbyte not included, +2 for all chars grater than '-'
    unsigned char *expected = malloc(10);
    expected[0] = (unsigned char) 2;
    expected[1] = (unsigned char) 254;
    expected[2] = (unsigned char) 90;
    expected[3] = (unsigned char) 229;
    expected[4] = (unsigned char) 165;
    expected[5] = (unsigned char) 158;
    expected[6] = (unsigned char) 75;
    expected[7] = (unsigned char) 192;
    expected[8] = (unsigned char) 253;
    expected[9] = 0;
    // calculation
    _V1arithmetic_op_any_base(-254, (char *) alphabet, (char *) z2, (char *) z1, '*', result);
    //Create Error-Message
    char *s1 = "error: {0x15, 0x16, 0x17, 0x18} * {0x1F, 0x20, 0x21, 0x22} (base -254) != ";
    char *s2 = " it should be {0x02, 0xFF, 0x5A, 0xE5, 0xA5, 0x9E, 0x4B, 0xC0, 0xFD}";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, (char *) expected));
    //Free memory for Error-Message
    free(message);
    free(alphabet);
    free(z1);
    free(z2);
    free(expected);
    return 0;
}

static char *testWithMainImplementationNum1() {
    //Calculation
    char result[50];
    char expected[50];
    // creation of alphabet
    unsigned char *alphabet = malloc(201);
    char offset = 1;
    for (unsigned char i = 0; i < 200; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        alphabet[i] = i + offset;
    }
    alphabet[200] = 0;
    // creation of first number
    unsigned char *z1 = malloc(21);
    offset = 1;
    for (unsigned char i = 0; i < 20; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z1[i] = i + offset + 100;
    }
    z1[20] = 0;
    // creation of second number
    unsigned char *z2 = malloc(21);
    offset = 1;
    for (unsigned char i = 0; i < 20; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z2[i] = i + offset + 120;
    }
    z2[20] = 0;
    // creation of expected result
    // IMPORTANT: Plus one everywhere because nullbyte not included, +2 for all chars grater than '-'
    arith_op_any_base(200, (char *) alphabet, (char *) z1, (char *) z2, '+', expected);
    // calculation
    _V1arithmetic_op_any_base(200, (char *) alphabet, (char *) z1, (char *) z2, '+', result);
    //Create Error-Message
    char *s1 = "expected: ";
    char *s2 = "\nactual: ";
    char *s3 = "\n";
    char *message = malloc(strlen(s1) + strlen(expected) + strlen(s3) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, expected);
    strcat(message, s2);
    strcat(message, result);
    strcat(message, s3);
    //Assertion
    mu_assert(message, !strcmp(result, (char *) expected));
    //Free memory for Error-Message
    free(message);
    free(alphabet);
    free(z1);
    free(z2);
    return 0;
}

static char *testWithMainImplementationNum2() {
    //Calculation
    char result[150];
    char expected[150];
    // creation of alphabet
    unsigned char *alphabet = malloc(201);
    char offset = 1;
    for (unsigned char i = 0; i < 200; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        alphabet[i] = i + offset;
    }
    alphabet[200] = 0;
    // creation of first number
    unsigned char *z1 = malloc(51);
    offset = 1;
    for (unsigned char i = 0; i < 50; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z1[i] = i + offset + 100;
    }
    z1[50] = 0;
    // creation of second number
    unsigned char *z2 = malloc(51);
    offset = 1;
    for (unsigned char i = 0; i < 50; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z2[i] = i + offset + 120;
    }
    z2[50] = 0;
    // creation of expected result
    // IMPORTANT: Plus one everywhere because nullbyte not included, +2 for all chars grater than '-'
    arith_op_any_base(-200, (char *) alphabet, (char *) z1, (char *) z2, '+', expected);
    // calculation
    _V1arithmetic_op_any_base(-200, (char *) alphabet, (char *) z1, (char *) z2, '+', result);
    //Create Error-Message
    char *s1 = "expected: ";
    char *s2 = "\nactual: ";
    char *s3 = "\n";
    char *message = malloc(strlen(s1) + strlen(expected) + strlen(s3) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, expected);
    strcat(message, s2);
    strcat(message, result);
    strcat(message, s3);
    //Assertion
    mu_assert(message, !strcmp(result, (char *) expected));
    //Free memory for Error-Message
    free(message);
    free(alphabet);
    free(z1);
    free(z2);
    return 0;
}

static char *testWithMainImplementationNum3() {
    //Calculation
    char result[150];
    char expected[150];
    // creation of alphabet
    unsigned char *alphabet = malloc(201);
    char offset = 1;
    for (unsigned char i = 0; i < 200; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        alphabet[i] = i + offset;
    }
    alphabet[200] = 0;
    // creation of first number
    unsigned char *z1 = malloc(51);
    offset = 1;
    for (unsigned char i = 0; i < 50; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z1[i] = i + offset + 100;
    }
    z1[50] = 0;
    // creation of second number
    unsigned char *z2 = malloc(51);
    offset = 1;
    for (unsigned char i = 0; i < 50; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z2[i] = i + offset + 120;
    }
    z2[50] = 0;
    // creation of expected result
    // IMPORTANT: Plus one everywhere because nullbyte not included, +2 for all chars grater than '-'
    arith_op_any_base(-200, (char *) alphabet, (char *) z1, (char *) z2, '-', expected);
    // calculation
    _V1arithmetic_op_any_base(-200, (char *) alphabet, (char *) z1, (char *) z2, '-', result);
    //Create Error-Message
    char *s1 = "expected: ";
    char *s2 = "\nactual: ";
    char *s3 = "\n";
    char *message = malloc(strlen(s1) + strlen(expected) + strlen(s3) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, expected);
    strcat(message, s2);
    strcat(message, result);
    strcat(message, s3);
    //Assertion
    mu_assert(message, !strcmp(result, (char *) expected));
    //Free memory for Error-Message
    free(message);
    free(alphabet);
    free(z1);
    free(z2);
    return 0;
}

static char *testWithMainImplementationNum4() {
    //Calculation
    char result[150];
    char expected[150];
    // creation of alphabet
    unsigned char *alphabet = malloc(201);
    char offset = 1;
    for (unsigned char i = 0; i < 200; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        alphabet[i] = i + offset;
    }
    alphabet[200] = 0;
    // creation of first number
    unsigned char *z1 = malloc(51);
    offset = 1;
    for (unsigned char i = 0; i < 50; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z1[i] = i + offset + 100;
    }
    z1[50] = 0;
    // creation of second number
    unsigned char *z2 = malloc(51);
    offset = 1;
    for (unsigned char i = 0; i < 50; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z2[i] = i + offset + 120;
    }
    z2[50] = 0;
    // creation of expected result
    // IMPORTANT: Plus one everywhere because nullbyte not included, +2 for all chars grater than '-'
    arith_op_any_base(-200, (char *) alphabet, (char *) z1, (char *) z2, '*', expected);
    // calculation
    _V1arithmetic_op_any_base(-200, (char *) alphabet, (char *) z1, (char *) z2, '*', result);
    //Create Error-Message
    char *s1 = "expected: ";
    char *s2 = "\nactual: ";
    char *s3 = "\n";
    char *message = malloc(strlen(s1) + strlen(expected) + strlen(s3) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, expected);
    strcat(message, s2);
    strcat(message, result);
    strcat(message, s3);
    //Assertion
    mu_assert(message, !strcmp(result, (char *) expected));
    //Free memory for Error-Message
    free(message);
    free(alphabet);
    free(z1);
    free(z2);
    return 0;
}

static char *testWithMainImplementationNum5() {
    //Calculation
    char result[255];
    char expected[255];
    // creation of alphabet
    unsigned char *alphabet = malloc(255);
    char offset = 1;
    for (unsigned char i = 0; i < 254; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        alphabet[i] = i + offset;
    }
    alphabet[254] = 0;
    // creation of first number
    unsigned char *z1 = malloc(101);
    offset = 1;
    for (unsigned char i = 0; i < 100; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z1[i] = i + offset + 100;
    }
    z1[100] = 0;
    // creation of second number
    unsigned char *z2 = malloc(101);
    offset = 1;
    for (unsigned char i = 0; i < 100; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z2[i] = i + offset + 120;
    }
    z2[100] = 0;
    // creation of expected result
    // IMPORTANT: Plus one everywhere because nullbyte not included, +2 for all chars grater than '-'
    arith_op_any_base(254, (char *) alphabet, (char *) z1, (char *) z2, '*', expected);
    // calculation
    _V1arithmetic_op_any_base(254, (char *) alphabet, (char *) z1, (char *) z2, '*', result);
    //Create Error-Message
    char *s1 = "expected: ";
    char *s2 = "\nactual: ";
    char *s3 = "\n";
    char *message = malloc(strlen(s1) + strlen(expected) + strlen(s3) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, expected);
    strcat(message, s2);
    strcat(message, result);
    strcat(message, s3);
    //Assertion
    mu_assert(message, !strcmp(result, (char *) expected));
    //Free memory for Error-Message
    free(message);
    free(alphabet);
    free(z1);
    free(z2);
    return 0;
}

static char *testWithMainImplementationNum6() {
    //Calculation
    char result[255];
    char expected[255];
    // creation of alphabet
    unsigned char *alphabet = malloc(255);
    char offset = 1;
    for (unsigned char i = 0; i < 254; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        alphabet[i] = i + offset;
    }
    alphabet[254] = 0;
    // creation of first number
    unsigned char *z1 = malloc(101);
    offset = 1;
    for (unsigned char i = 0; i < 100; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z1[i] = i + offset + 100;
    }
    z1[100] = 0;
    // creation of second number
    unsigned char *z2 = malloc(101);
    offset = 1;
    for (unsigned char i = 0; i < 100; ++i) {
        if (i + offset == '-') {
            offset++;
        }
        z2[i] = i + offset + 120;
    }
    z2[100] = 0;
    // creation of expected result
    // IMPORTANT: Plus one everywhere because nullbyte not included, +2 for all chars grater than '-'
    arith_op_any_base(-254, (char *) alphabet, (char *) z1, (char *) z2, '*', expected);
    // calculation
    _V1arithmetic_op_any_base(-254, (char *) alphabet, (char *) z1, (char *) z2, '*', result);
    //Create Error-Message
    char *s1 = "expected: ";
    char *s2 = "\nactual: ";
    char *s3 = "\n";
    char *message = malloc(strlen(s1) + strlen(expected) + strlen(s3) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, expected);
    strcat(message, s2);
    strcat(message, result);
    strcat(message, s3);
    //Assertion
    mu_assert(message, !strcmp(result, (char *) expected));
    //Free memory for Error-Message
    free(message);
    free(alphabet);
    free(z1);
    free(z2);
    return 0;
}


static char *all_tests() {
    mu_run_test(testPosBase8Num1m);

    mu_run_test(testPosBase2Num1m);

    mu_run_test(testSimple2);

    //Negative bases
    mu_run_test(testPosBaseBigNumber);
    mu_run_test(testNegBase2Num1);

    mu_run_test(testNegBase2Num2);
    mu_run_test(testNegBase2Num3);
    mu_run_test(testNegBase8Num1);
    mu_run_test(testNegBase10Num1);
    mu_run_test(testNegBase16Num1);

    //Positive bases

    mu_run_test(testPosBase2Num1);
    mu_run_test(testPosBase16Num1);
    mu_run_test(testPosBase16Num2);
    mu_run_test(testPosBase30Num1);
    mu_run_test(testPosBase30Num2);
    mu_run_test(testPosBase36Num1);

    mu_run_test(testPosBase10WithNegNumbersNum1);
    mu_run_test(testPosBase14WithNegNumbersNum1);




    //subtraction

    //Negative bases
    mu_run_test(testNegBase2Num1m);
    mu_run_test(testNegBase2Num2m);
    mu_run_test(testNegBase2Num3m);
    mu_run_test(testNegBase2Num4m);
    mu_run_test(testNegBase2Num5m);
    mu_run_test(testNegBase2Num6m);
    mu_run_test(testNegBase16Num1m);
    mu_run_test(testNegBase30Num1m);
    mu_run_test(testNegBase10Num1m);
    mu_run_test(testNegBase13Num1m);

    //Positive bases

    mu_run_test(simple_test);

    mu_run_test(testPosBase16Num2m);

    // multiplication

    //Positive Base
    mu_run_test(testPosBase10Num1k);
    mu_run_test(testPosBase10Num2k);
    mu_run_test(testPosBase10Num3k);
    mu_run_test(testPosBase10Num4k);
    mu_run_test(testPosBase36Num1);
    mu_run_test(testPosBase10WithNegNumbersNum1k);
    mu_run_test(testPosBase14WithNegNumbersNum1k);

    //Negative bases
    mu_run_test(testNegBase2Num1k);
    mu_run_test(testNegBase2Num2k);
    mu_run_test(testNegBase2Num3k);
    mu_run_test(testNegBase8Num1k);
    mu_run_test(testNegBase8Num2k);
    mu_run_test(testNegBase10Num1k);

    //Big tests
    mu_run_test(testPosBaseBigNumberMul);
    mu_run_test(testNegBaseBigNumberMul);
    mu_run_test(testWithMainImplementationNum1);
    mu_run_test(testWithMainImplementationNum2);
    mu_run_test(testWithMainImplementationNum3);
    mu_run_test(testWithMainImplementationNum4);
    mu_run_test(testWithMainImplementationNum5);
    mu_run_test(testWithMainImplementationNum6);

    return 0;
}


int main(void) {

    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
