#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/calculations.h"
#include "minunit.h"

int tests_run = 0;

static char *testPosBase10Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(10, "0123456789", "5", "10", '*', result);
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

static char *testPosBase10Num2() {
    //Calculation
    char result[50];
    arith_op_any_base(10, "0123456789", "356", "300", '*', result);
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

static char *testPosBase10Num3() {
    //Calculation
    char result[50];
    arith_op_any_base(10, "0123456789", "234654", "6576", '*', result);
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

static char *testPosBase10Num4() {
    //Calculation
    char result[50];
    arith_op_any_base(10, "0123456789", "9999", "9999", '*', result);
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

static char *testPosBase36Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(36, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ZAB03", "93ZUH", '*', result);
    //Create Error-Message
    char *s1 = "error: ZAB03 * 93ZUH (base 36) != ";
    char *s2 = " it should be 8XHQTPD6JF";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "8XHQTPD6JF"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase10WithNegNumbersNum1() {
    //Calculation
    char result[50];
    arith_op_any_base(10, "0123456789", "-356", "-222", '*', result);
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

static char *testPosBase14WithNegNumbersNum1() {
    //Calculation
    char result[50];
    arith_op_any_base(14, "0123456789ABCD", "-DA", "DB", '*', result);
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

static char *testNegBase2Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(-2, "01", "1011", "1110", '*', result);
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

static char *testNegBase2Num2() {
    //Calculation
    char result[50];
    arith_op_any_base(-2, "01", "101010", "101100", '*', result);
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

static char *testNegBase2Num3() {
    //Calculation
    char result[50];
    arith_op_any_base(-2, "01", "00101", "00111", '*', result);
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

static char *testNegBase8Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(-8, "01234567", "663562", "147547", '*', result);
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

static char *testNegBase8Num2() {
    //Calculation
    char result[50];
    arith_op_any_base(-8, "01234567", "7727", "754", '*', result);
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

static char *testNegBase10Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(-10, "0123456789", "50", "50", '*', result);
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

//Test if -0 has weird behaviour
static char *testPosBaseWithMinus0Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(14, "0123456789ABCD", "-0", "2345", '*', result);
    //Create Error-Message
    char *s1 = "error: (-0) * 2345 (base 14) != ";
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

//Test if 0 or -0 is computed
static char *testPosBaseWithMinus0Num2() {
    //Calculation
    char result[50];
    arith_op_any_base(2, "01", "-0", "-0", '*', result);
    //Create Error-Message
    char *s1 = "error: (-0) * (-0) (base 2) != ";
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

//Test if 0 or -0 is computed
static char *testPosBaseWithMinus0Num3() {
    //Calculation
    char result[50];
    arith_op_any_base(2, "01", "0", "-0", '*', result);
    //Create Error-Message
    char *s1 = "error: 0 * (-0) (base 2) != ";
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

static char *testWithOnlyMinusSignNum1() {
    //Calculation
    char result[50];
    arith_op_any_base(2, "01", "-", "10", '*', result);
    //Create Error-Message
    char *s1 = "error: (-) * 10 (base 2) != ";
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

static char *testWithOnlyMinusSignNum2() {
    //Calculation
    char result[50];
    arith_op_any_base(2, "01", "-", "-", '*', result);
    //Create Error-Message
    char *s1 = "error: (-) * (-) (base 2) != ";
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

// Big test case for large numbers with positive base
static char *testPosBaseBigNumber() {
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
    arith_op_any_base(254, (char *) alphabet, (char *) z1, (char *) z2, '*', result);
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
static char *testNegBaseBigNumber() {
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
    arith_op_any_base(-254, (char *) alphabet, (char *) z2, (char *) z1, '*', result);
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

static char *all_tests() {

    //Positive Base
    mu_run_test(testPosBase10Num1);
    mu_run_test(testPosBase10Num2);
    mu_run_test(testPosBase10Num3);
    mu_run_test(testPosBase10Num4);
    mu_run_test(testPosBase36Num1);
    mu_run_test(testPosBase10WithNegNumbersNum1);
    mu_run_test(testPosBase14WithNegNumbersNum1);
    //Negative bases
    mu_run_test(testNegBase2Num1);
    mu_run_test(testNegBase2Num2);
    mu_run_test(testNegBase2Num3);
    mu_run_test(testNegBase8Num1);
    mu_run_test(testNegBase8Num2);
    mu_run_test(testNegBase10Num1);

    //Special tests
    mu_run_test(testPosBaseWithMinus0Num1);
    mu_run_test(testPosBaseWithMinus0Num2);
    mu_run_test(testPosBaseWithMinus0Num3);
    mu_run_test(testWithOnlyMinusSignNum1);
    mu_run_test(testWithOnlyMinusSignNum2);
    mu_run_test(testPosBaseBigNumber);
    mu_run_test(testNegBaseBigNumber);

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
