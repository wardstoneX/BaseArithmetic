#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/calculations.h"
#include "minunit.h"

int tests_run = 0;

static char *testNegBase2Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(-2, "01", "1011", "1110", '+', result);
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
    arith_op_any_base(-2, "01", "101010", "101100", '+', result);
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
    arith_op_any_base(-2, "01", "00101", "00111", '+', result);
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
    arith_op_any_base(-8, "01234567", "663562", "147547", '+', result);
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
    arith_op_any_base(-10, "0123456789", "50", "50", '+', result);
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
    arith_op_any_base(-16, "0123456789ABCDEF", "4E", "4E", '+', result);
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
    arith_op_any_base(2, "01", "0", "1", '+', result);
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
    arith_op_any_base(16, "0123456789ABCDEF", "8AB", "B78", '+', result);
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
    arith_op_any_base(16, "0123456789ABCDEF", "DAD", "DAD", '+', result);
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
    arith_op_any_base(30, "0123456789ABCDEFGHIJKLMNOPQRST", "2CG", "37TF", '+', result);
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
    arith_op_any_base(30, "0123456789ABCDEFGHIJKLMNOPQRST", "3ABR", "38F", '+', result);
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
    arith_op_any_base(36, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ZAB03", "93ZUH", '+', result);
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
    arith_op_any_base(10, "0123456789", "-356", "-222", '+', result);
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
    arith_op_any_base(14, "0123456789ABCD", "-DA", "DB", '+', result);
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

static char *testWithOnlyMinusSignNum1() {
    //Calculation
    char result[50];
    arith_op_any_base(2, "01", "-", "10", '+', result);
    //Create Error-Message
    char *s1 = "error: (-) + 10 (base 2) != ";
    char *s2 = " it should be 10";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "10"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

static char *testWithOnlyMinusSignNum2() {
    //Calculation
    char result[50];
    arith_op_any_base(2, "01", "-", "-", '+', result);
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

//Test if -0 has weird behaviour
static char *testPosBaseWithMinus0Num1() {
    //Calculation
    char result[50];
    arith_op_any_base(14, "0123456789ABCD", "-0", "DB", '+', result);
    //Create Error-Message
    char *s1 = "error: (-0) + DB (base 14) != ";
    char *s2 = " it should be DB";
    char *message = malloc(strlen(s1) + strlen(result) + strlen(s2) + 1);
    strcpy(message, s1);
    strcat(message, result);
    strcat(message, s2);
    //Assertion
    mu_assert(message, !strcmp(result, "DB"));
    //Free memory for Error-Message
    free(message);
    return 0;
}

//Test if 0 or -0 is computed
static char *testPosBaseWithMinus0Num2() {
    //Calculation
    char result[50];
    arith_op_any_base(2, "01", "-0", "-0", '+', result);
    //Create Error-Message
    char *s1 = "error: (-0) + (-0) (base 2) != ";
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
    expected[0] = (unsigned char) 2;
    expected[1] = (unsigned char) 20;
    expected[2] = (unsigned char) 22;
    expected[3] = (unsigned char) 24;
    expected[4] = (unsigned char) 25;
    expected[5] = 0;
    // calculation
    arith_op_any_base(200, (char *) alphabet, (char *) z1, (char *) z2, '+', result);
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
    unsigned char *expected = malloc(7);
    expected[0] = (unsigned char) 2;
    expected[1] = (unsigned char) 201;
    expected[2] = (unsigned char) 18;
    expected[3] = (unsigned char) 20;
    expected[4] = (unsigned char) 22;
    expected[5] = (unsigned char) 25;
    expected[6] = 0;
    // calculation
    arith_op_any_base(-200, (char *) alphabet, (char *) z1, (char *) z2, '+', result);
    //Create Error-Message
    char *s1 = "error: efgh + yz{| (base -200) != ";
    char *s2 = " it should be {0x02, 0xC9, 0x12, 0x14, 0x16, 0x19}";
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
