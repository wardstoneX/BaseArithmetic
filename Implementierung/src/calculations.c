#include <stdbool.h>
#include <stdio.h>

#include "calculations.h"
#include "arithmetic_helper.h"

// Simple error message for usage of a undefined Operator
void print_error_message_undefined_Op(char op) {
    fprintf(stderr, "Illegal Input: Operation %c is undefined!", op);
}

// Simple error message for wrong usage of '-' - Operator in numbers z1 and z2
void print_error_message_minus_mismatch() {
    fprintf(stderr, "Illegal Input: Can't use negative Numbers for negative bases!");
}

/**
 * Main method for starting off the arithmetic operation that has to be calculated by the program;
 * Only handles what type of operation should be executed, other handling is done by the Helper-Methods
 * @param base The Base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param op Operator that should be used
 * @param result Result Buffer for the result of the operation
 */
void arith_op_any_base(int base, const char *alph, const char *z1, const char *z2, char op, char *result) {
    switch (op) {
        case '+':
            plus_op_any_base(base, alph, z1, z2, result);
            break;
        case '-':
            minus_op_any_base(base, alph, z1, z2, result);
            break;
        case '*':
            mul_op_any_base(base, alph, z1, z2, result);
            break;
        default:
            print_error_message_undefined_Op(op);
            break;
    }
    // fix for broken zeros
    if (result[0] == 0 || (result[0] == '-' && (result[1] == 0 || result[1] == alph[0]))) {
        result[0] = alph[0];
        result[1] = 0;
    }
}

/**
 * Method for executing '-' - Operation and store the result in the result pointer
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 */
void minus_op_any_base(int base, const char *alph, const char *z1, const char *z2, char *result) {
    // Depending on the minus prefix a different operation will be called
    if (base < -1) {
        if (*z1 != '-' && *z2 != '-') {
            // only subtraction possible
            minus_op_neg_base(base, alph, z1, z2, result);
        } else {
            // Minus illegal with negative bases
            print_error_message_minus_mismatch();
            return;
        }
    } else {
        if (*z1 == '-') {
            if (*z2 == '-') {
                // (-z1) - (-z2) = z2 - z1 -> subtraction
                minus_op_pos_base(base, alph, z2 + 1, z1 + 1, result);
            } else {
                // (-z1) - z2 = - (z1 + z2) -> addition with negative result
                plus_op_pos_base(base, alph, z1 + 1, z2, result, true);
            }
        } else {
            if (*z2 == '-') {
                // z1 - (-z2) = z1 + z2 -> addition with positive result
                plus_op_pos_base(base, alph, z1, z2 + 1, result, false);
            } else {
                // z1 - z2 = z1 - z2 -> subtraction
                minus_op_pos_base(base, alph, z1, z2, result);
            }
        }
    }
}

/**
 * Method for executing '+' - Operation and store the result in the result pointer
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 */
void plus_op_any_base(int base, const char *alph, const char *z1, const char *z2, char *result) {
    // Depending on the minus prefix a different operation will be called
    if (base < -1) {
        if (*z1 != '-' && *z2 != '-') {
            // only addition possible
            plus_op_neg_base(base, alph, z1, z2, result);
        } else {
            // Minus illegal with negative bases
            print_error_message_minus_mismatch();
            return;
        }
    } else {
        if (*z1 == '-') {
            if (*z2 == '-') {
                // (-z1) + (-z2) = - (z2 + z1) -> addition with negative result
                plus_op_pos_base(base, alph, z1 + 1, z2 + 1, result, true);
            } else {
                // (-z1) + z2 = z2 - z1 -> subtraction
                minus_op_pos_base(base, alph, z2, z1 + 1, result);
            }
        } else {
            if (*z2 == '-') {
                // z1 + (-z2) = z1 - z2 -> subtraction
                minus_op_pos_base(base, alph, z1, z2 + 1, result);
            } else {
                // z1 + z2 = z1 + z2 -> addition
                plus_op_pos_base(base, alph, z1, z2, result, false);
            }
        }
    }
}

/**
 * Method for executing '-' - Operation and store the result in the result pointer
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 */
void mul_op_any_base(int base, const char *alph, const char *z1, const char *z2, char *result) {
    // Depending on the minus prefix a different operation will be called
    if (base < -1) {
        if (*z1 != '-' && *z2 != '-') {
            // Multiplication works for numbers of all bases so we don't have to distinguish
            // between positive and negative bases
            mul_op_pos_base(base, alph, z1, z2, result, false);
        } else {
            // Minus illegal with negative bases
            print_error_message_minus_mismatch();
            return;
        }
    } else {
        if (*z1 == '-') {
            if (*z2 == '-') {
                // (-z1) * (-z2) = z1 * z2 -> multiplication with positive result
                mul_op_pos_base(base, alph, z1 + 1, z2 + 1, result, false);
            } else {
                // (-z1) * z2 = - (z1 * z2) -> multiplication with negative result
                mul_op_pos_base(base, alph, z1 + 1, z2, result, true);
            }
        } else {
            if (*z2 == '-') {
                // z1 * (-z2) = - (z1 * z2) -> multiplication with negative result
                mul_op_pos_base(base, alph, z1, z2 + 1, result, true);
            } else {
                // z1 * z2 = z1 * z2 -> multiplication with positive result
                mul_op_pos_base(base, alph, z1, z2, result, false);
            }
        }
    }
}
