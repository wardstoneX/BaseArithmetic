#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/calculations.h"
#include "minunit.h"

int tests_run = 0;

static char *simple_test() {
    char result[50];
    arith_op_any_base(8, "01234567", "25", "13", '-', result);
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

static char *testNegBase2Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(-2, "01", "1011", "1110", '-', result);
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

static char *testNegBase2Num3() {
    //Calculation
    char result[50];
    arith_op_any_base(-2, "01", "110100", "110101", '-', result);
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

static char *testNegBase2Num2() {
    //Calculation
    char result[50];
    arith_op_any_base(-2, "01", "101010", "101100", '-', result);
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

static char *testNegBase2Num4() {
    //Calculation
    char result[50];
    arith_op_any_base(-2, "01", "1001", "11011", '-', result);
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

static char *testNegBase2Num5() {
    //Calculation
    char result[50];
    arith_op_any_base(-2, "01", "11", "111111", '-', result);
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

static char *testNegBase2Num6() {
    //Calculation
    char result[50];
    arith_op_any_base(-2, "01", "0", "110100", '-', result);
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

static char *testNegBase10Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(-10, "0123456789", "29", "16", '-', result);
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

static char *testNegBase16Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(-16, "0123456789ABCDEF", "4E", "4E", '-', result);
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

static char *testNegBase30Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(-30, "0123456789ABCDEFGHIJKLMNOPQRST", "2CG", "37TF", '-', result);
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

static char *testNegBase13Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(-13, "0123456789ABC", "58157", "58157", '-', result);
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

static char *testPosBase2Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(2, "01", "1010101010101010101010101010", "1010101010101010101010101010", '-', result);
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

static char *testPosBase8Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(8, "01234567", "2452364", "472563152252", '-', result);
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

static char *testPosBase16Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(16, "0123456789ABCDEF", "-458952A25BD55C58235", "458A2FFF851", '-', result);
    //Create Error-Message
    char *s1 = "error: -458952A25BD55C58235 - 458A2FFF851 (base 16) != ";
    char *s2 = " it should be -458952A2A15F8C57A86";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "-458952A2A15F8C57A86"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testPosBase16Num2() {
    //Calculation
    char result[50];
    arith_op_any_base(16, "0123456789ABCDEF", "-534A25C22FF", "-545DDDD568", '-', result);
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

static char *testWithOnlyMinusSignNum1() {
    //Calculation
    char result[50];
    arith_op_any_base(2, "01", "-", "10", '-', result);
    //Create Error-Message
    char *s1 = "error: (-) - 10 (base 2) != ";
    char *s2 = " it should be (-10)";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "-10"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testWithOnlyMinusSignNum2() {
    //Calculation
    char result[50];
    arith_op_any_base(2, "01", "-", "-", '-', result);
    //Create Error-Message
    char *s1 = "error: (-) - (-) (base 2) != ";
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

//Test if -0 has weird behaviour
static char *testPosBaseWithMinus0Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(14, "0123456789ABCD", "-0", "DB", '-', result);
    //Create Error-Message
    char *s1 = "error: (-0) - DB (base 14) != ";
    char *s2 = " it should be (-DB)";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "-DB"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

//Test if 0 or -0 is computed
static char *testPosBaseWithMinus0Num2() {
    //Calculation
    char result[50];
    arith_op_any_base(2, "01", "-0", "-0", '-', result);
    //Create Error-Message
    char *s1 = "error: (-0) - (-0) (base 2) != ";
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
    expected[0] = '-';
    expected[1] = (unsigned char) 21;
    expected[2] = (unsigned char) 21;
    expected[3] = (unsigned char) 21;
    expected[4] = (unsigned char) 21;
    expected[5] = 0;
    // calculation
    arith_op_any_base(200, (char *) alphabet, (char *) z1, (char *) z2, '-', result);
    //Create Error-Message
    char *s1 = "error: efgh - yz{| (base 200) != ";
    char *s2 = " it should be {0xC9, 0xB5, 0xB5, 0xB5, 0xB6}";
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

static char *testNegBaseBigNumber() {
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
    expected[1] = (unsigned char) 183;
    expected[2] = (unsigned char) 183;
    expected[3] = (unsigned char) 183;
    expected[4] = (unsigned char) 182;
    expected[5] = 0;
    // calculation
    arith_op_any_base(-200, (char *) alphabet, (char *) z1, (char *) z2, '-', result);
    //Create Error-Message
    char *s1 = "error: efgh + yz{| (base -200) != ";
    char *s2 = " it should be {0x02, 0xB7, 0xB7, 0xB7, 0xB6}";
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

    //Negative bases
    mu_run_test(testNegBase2Num1);
    mu_run_test(testNegBase2Num2);
    mu_run_test(testNegBase2Num3);
    mu_run_test(testNegBase2Num4);
    mu_run_test(testNegBase2Num5);
    mu_run_test(testNegBase2Num6);
    mu_run_test(testNegBase16Num1);
    mu_run_test(testNegBase30Num1);
    mu_run_test(testNegBase10Num1);
    mu_run_test(testNegBase13Num1);
    //Positive bases
    mu_run_test(simple_test);
    mu_run_test(testPosBase2Num1);
    mu_run_test(testPosBase8Num1);
    mu_run_test(testPosBase16Num1);
    mu_run_test(testPosBase16Num2);

    //Special tests
    mu_run_test(testPosBaseWithMinus0Num1);
    mu_run_test(testPosBaseWithMinus0Num2);
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
