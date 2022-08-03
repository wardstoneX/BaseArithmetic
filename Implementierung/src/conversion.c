#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

#include "calculations.h"
#include "calculation_helper.h"
#include "conversion.h"

/**
 * Main method for starting off the arithmetic operation (doing conversion) that has to be calculated
 * by the program.
 * Only handles what type of operation should be executed, other handling regarding the signs of both
 * operands, is done by the Helper-Methods.
 * @param base The Base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param op Operator that should be used
 * @param result Result Buffer for the result of the operation
 */
void _V1arithmetic_op_any_base(int base, const char *alph, const char *z1, const char *z2, char op, char *result) {
    switch (op) {
        case '+':
            _V1plus_op_any_signs(base, alph, z1, z2, result);
            break;
        case '-':
            _V1minus_op_any_signs(base, alph, z1, z2, result);
            break;
        case '*':
            _V1mul_op_any_signs(base, alph, z1, z2, result);
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
 * Method for executing '+' - operation (doing conversion) and store the result in the result pointer.
 * Note that in the impl. of the conversion, other than in the main impl., the method called for the
 * operation does not depend on if the base is negative or positive.
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 */
void _V1plus_op_any_signs(int base, const char *alph, const char *z1, const char *z2, char *result) {
    // Depending on the minus prefix a different operation will be called
    if (*z1 != '-' && *z2 != '-') {
        _V1plus_op_any_base(base, alph, z1, z2, result, false);
    } else if (base < 0) {
        // Minus illegal with negative bases
        print_error_message_minus_mismatch();
        return;
    } else if (*z1 == '-') {
        if (*z2 == '-') {
            // (-z1) + (-z2) = - (z2 + z1) -> addition with negative result
            _V1plus_op_any_base(base, alph, z1 + 1, z2 + 1, result, true);
        } else {
            // (-z1) + z2 = z2 - z1 -> subtraction
            _V1minus_op_any_base(base, alph, z2, z1 + 1, result);
        }
    } else {
        // z1 + (-z2) = z1 - z2 -> subtraction
        _V1minus_op_any_base(base, alph, z1, z2 + 1, result);
    }
}

/**
 * Method for executing '-' - operation (doing conversion) and store the result in the result pointer.
 * Note that in the impl. of the conversion, other than in the main impl., the method called for the
 * operation does not depend on if the base is negative or positive.
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 */
void _V1minus_op_any_signs(int base, const char *alph, const char *z1, const char *z2, char *result) {
    // Depending on the minus prefix a different operation will be called
    if (*z1 != '-' && *z2 != '-') {
        _V1minus_op_any_base(base, alph, z1, z2, result);
    } else if (base < 0) {
        // Minus illegal with negative bases
        print_error_message_minus_mismatch();
        return;
    } else if (*z1 == '-') {
        if (*z2 == '-') {
            // (-z1) - (-z2) = z2 - z1 -> subtraction
            _V1minus_op_any_base(base, alph, z2 + 1, z1 + 1, result);
        } else {
            // (-z1) - z2 = - (z1 + z2) -> addition with negative result
            _V1plus_op_any_base(base, alph, z1 + 1, z2, result, true);
        }
    } else {
        // z1 - (-z2) = z1 + z2 -> addition with positive result
        _V1plus_op_any_base(base, alph, z1, z2 + 1, result, false);
    }
}

/**
 * Method for executing '*' - operation (doing conversion) and store the result in the result pointer.
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 */
void _V1mul_op_any_signs(int base, const char *alph, const char *z1, const char *z2, char *result) {
    // Depending on the minus prefix a different operation will be called
    if (*z1 != '-' && *z2 != '-') {
        // Multiplication works for numbers of all bases, so we don't have to distinguish between
        // positive and negative bases
        // z1 * z2 = z1 * z2 -> multiplication with positive result
        _V1mul_op_any_base(base, alph, z1, z2, result, false);
    } else if (base < -1) {
        // Minus illegal with negative bases
        print_error_message_minus_mismatch();
        return;
    } else if (*z1 == '-') {
        if (*z2 == '-') {
            // (-z1) * (-z2) = z1 * z2 -> multiplication with positive result
            _V1mul_op_any_base(base, alph, z1 + 1, z2 + 1, result, false);
        } else {
            // (-z1) * z2 = - (z1 * z2) -> multiplication with negative result
            _V1mul_op_any_base(base, alph, z1 + 1, z2, result, true);
        }
    } else {
        // z1 * (-z2) = - (z1 * z2) -> multiplication with negative result
        _V1mul_op_any_base(base, alph, z1, z2 + 1, result, true);
    }
}

/**
 * Method for calculating the maximum length of a (char*) representing a number with a given base,
 * that with, converted to base 10 (int64_t), an addition does not cause an overflow.
 * @param base The base of the given numbers
 * @return The maximum length of a (char*) that can be added with
 */
int max_length_int(int base) {
    int64_t tmp = LLONG_MAX;
    size_t result = 0;
    while (tmp >= abs(base)) {
        tmp /= abs(base);
        result++;
    }
    return result;
}

/**
 * Method that converts a String representing a number with a given base to an int64_t. Since the String
 * to be converted may only be a part of a longer number, the length has to be defined explicitly.
 * @param base The base of the given number
 * @param table The initialized look-up table
 * @param num The pointer to the String that is to be converted
 * @param numLength The length of the String
 * @return The converted number
 */
int64_t convert_String_to_int(int base, unsigned char *table, const char *num, int numLength) {
    int64_t result = 0;
    int64_t base_factor = 1;
    for (int i = numLength - 1; i >= 0; i--) {
        result += ((int64_t) table[(unsigned char) num[i]]) * base_factor;
        base_factor = base_factor * base;
    }
    return result;
}

/**
 * Method that converts an int64_t to a String representing a number with a given base. Since the
 * int64_t may be the result of a sub-calculation only, the conversion is only made for a certain
 * amount of digits, before the rest (carry) is returned.
 * @param base The base of the given number
 * @param alph The alphabet that the given number uses
 * @param num The pointer to the String where the converted number is placed
 * @param numLength The length of the String (amount of digits being converted)
 * @return The rest (carry) after numLength digits have been converted
 */
int64_t convert_int_to_String(int base, const char *alph, char *num, int numLength, int64_t result) {
    int64_t carry;
    for (int i = numLength - 1; i >= 0; i--) {
        int64_t tmp = result % base;
        if (tmp < 0) {
            carry = (base < 0 ? 1 : -1);
            tmp += abs(base);
        } else {
            carry = 0;
        }
        num[i] = alph[llabs(tmp)];
        result = result / base + carry;
    }
    return result;
}

/**
 * Method for executing the '+' - Operation (doing conversion) for positive numbers
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 * @param isNeg Signal if result is negative
 */
void _V1plus_op_any_base(int base, const char *alph, const char *z1, const char *z2, char *result, bool isNeg) {

    //Create Lookup-table in the beginning in order to make calculations easier
    //Also creates tmp for tmp save in which the result is stored
    unsigned char *table = (unsigned char *) malloc(256);
    int64_t length_result = (strlen(z1) > strlen(z2) ? strlen(z1) : strlen(z2)) + 2;
    char *tmp = (char *) malloc(length_result);
    if (table == NULL || tmp == NULL) {
        print_error_message_allocation_problem();
        // free memory
        free(table);
        free(tmp);
        return;
    }

    // Important check before starting the method
    if (!check_Legality_of_Parameters(base, table, alph, z1, z2)) {
        // free memory
        free(table);
        free(tmp);
        return;
    }

    //max amount of chars that are being handled at the same time
    int charsHandledAtOnce = max_length_int(base);

    const char *z1Pointer = z1 + strlen(z1);
    const char *z2Pointer = z2 + strlen(z2);

    //calculate number in tmp (set first two chars to 0 in case not used)
    tmp[0] = alph[0];
    tmp[1] = alph[0];
    tmp[length_result - 1] = 0;
    int64_t tmpOffset = length_result;
    int64_t carry = 0;
    while (z1Pointer >= z1 || z2Pointer >= z2 || carry) {
        //convert snippet of z1 to int64_t and put into x, update the z1Pointer
        int64_t x = 0;
        if (z1Pointer >= z1) {
            size_t xLength = z1Pointer - z1 > charsHandledAtOnce ? charsHandledAtOnce : z1Pointer - z1;
            x = convert_String_to_int(base, table, z1Pointer - xLength, xLength);
            z1Pointer -= charsHandledAtOnce;
        }
        //convert snippet of z2 to int64_t and put into y, update the z2Pointer
        int64_t y = 0;
        if (z2Pointer >= z2) {
            size_t yLength = z2Pointer - z2 > charsHandledAtOnce ? charsHandledAtOnce : z2Pointer - z2;
            y = convert_String_to_int(base, table, z2Pointer - yLength, yLength);
            z2Pointer -= charsHandledAtOnce;
        }

        //actual calculation
        int64_t r = x + y + carry;

        //convert r to String and put it in place in tmp
        int tmp_resultLength = tmpOffset < charsHandledAtOnce ? tmpOffset : charsHandledAtOnce;
        tmpOffset -= tmp_resultLength;
        if (tmpOffset < 0) {
            tmpOffset = 0;
        }
        carry = convert_int_to_String(base, alph, tmp + tmpOffset, tmp_resultLength, r);
    }

    //copy tmp to result
    int64_t resultOffset = 0;
    tmpOffset = 0;
    //put '-' in front if result must be negative
    if (isNeg) {
        result[resultOffset++] = '-';
    }
    //bool for removing leading 0s
    bool isLeading = true;
    while (tmpOffset < length_result) {
        if (isLeading && tmp[tmpOffset] == alph[0]) {
            tmpOffset++;
            continue;
        }
        isLeading = false;
        result[resultOffset++] = tmp[tmpOffset++];
    }

    //if the result is 0, put 0 in first char
    if (resultOffset == 0 || result[0] == 0) {
        result[0] = alph[0];
        resultOffset = 1;
    }

    //IMPORTANT: Again, don't forget null-byte for string
    result[resultOffset] = 0;

    //Free memory that was allocated
    free(table);
    free(tmp);
}

/**
 * Method for executing the '-' - Operation (doing conversion) for positive numbers
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 */
void _V1minus_op_any_base(int base, const char *alph, const char *z1, const char *z2, char *result) {

    //Create Lookup-table in the beginning in order to make calculations easier
    //Also creates tmp for tmp save in which the result is stored
    unsigned char *table = (unsigned char *) malloc(256);
    int64_t length_result = (strlen(z1) > strlen(z2) ? strlen(z1) : strlen(z2)) + 2;
    char *tmp = (char *) malloc(length_result);
    if (table == NULL || tmp == NULL) {
        print_error_message_allocation_problem();
        // free memory
        free(table);
        free(tmp);
        return;
    }

    // Important check before starting the method
    if (!check_Legality_of_Parameters(base, table, alph, z1, z2)) {
        // free memory
        free(table);
        free(tmp);
        return;
    }

    // Reorder numbers, so that: z1 >= z2 -> z1 - z2 >= 0
    bool isNeg = 0;
    if (base > 0) {
        const char **largerNumber = getLargerNumber(table, alph, z1, z2);
        if (largerNumber == NULL) {
            print_error_message_allocation_problem();
            // free memory
            free(table);
            free(tmp);
            return;
        }
        //if numbers are switched, origin. z2 > z1 and '-' must be added at the end
        isNeg = largerNumber[0] != z1;

        z1 = largerNumber[0];
        z2 = largerNumber[1];
    }

    //max amount of chars that are being handled at the same time
    int charsHandledAtOnce = max_length_int(base);

    const char *z1Pointer = z1 + strlen(z1);
    const char *z2Pointer = z2 + strlen(z2);

    //calculate number in tmp (set first two chars to 0 in case not used)
    tmp[0] = alph[0];
    tmp[1] = alph[0];
    int64_t tmpOffset = length_result;
    int64_t carry = 0;
    tmp[length_result - 1] = 0;
    while (z1Pointer >= z1 || z2Pointer >= z2 || carry) {
        //convert snippet of z1 to int64_t and put into x, update the z1Pointer
        int64_t x = 0;
        if (z1Pointer >= z1) {
            size_t xLength = z1Pointer - z1 > charsHandledAtOnce ? charsHandledAtOnce : z1Pointer - z1;
            x = convert_String_to_int(base, table, z1Pointer - xLength, xLength);
            z1Pointer -= charsHandledAtOnce;
        }
        //convert snippet of z2 to int64_t and put into y, update the z2Pointer
        int64_t y = 0;
        if (z2Pointer >= z2) {
            size_t yLength = z2Pointer - z2 > charsHandledAtOnce ? charsHandledAtOnce : z2Pointer - z2;
            y = convert_String_to_int(base, table, z2Pointer - yLength, yLength);
            z2Pointer -= charsHandledAtOnce;
        }

        //actual calculation
        int64_t r = x - y + carry;

        //convert r to String and put it in place in tmp
        int tmp_resultLength = tmpOffset < charsHandledAtOnce ? tmpOffset : charsHandledAtOnce;
        tmpOffset -= tmp_resultLength;
        if (tmpOffset < 0) {
            tmpOffset = 0;
        }
        carry = convert_int_to_String(base, alph, tmp + tmpOffset, tmp_resultLength, r);
    }

    //copy tmp to result
    int64_t resultOffset = 0;
    tmpOffset = 0;
    //put '-' in front if result must be negative
    if (isNeg && base > 0) {
        result[resultOffset++] = '-';
    }

    //bool for removing leading 0s
    bool isLeading = true;
    while (tmpOffset < length_result) {
        if (isLeading && tmp[tmpOffset] == alph[0]) {
            tmpOffset++;
            continue;
        }
        isLeading = false;
        result[resultOffset++] = tmp[tmpOffset++];
    }

    //if the result is "", put 0 in first char
    if (resultOffset == 0 || result[0] == 0) {
        result[0] = alph[0];
        resultOffset =
                1;
    }
    //IMPORTANT: Again, don't forget null-byte for string
    result[resultOffset] = 0;

    //Free memory that was allocated
    free(table);
    free(tmp);
}

/**
 * Method for executing the '+' - Operation (doing conversion) for positive numbers
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 * @param isNeg Signal if result is negative
 */
void _V1mul_op_any_base(int base, const char *alph, const char *z1, const char *z2, char *result, bool isNeg) {

    //Create Lookup-table in the beginning in order to make calculations easier
    //Also creates tmp for result of multiplication of whole line
    unsigned char *table = (unsigned char *) malloc(256);
    int64_t length_result = strlen(z1) + strlen(z2) + 3;
    char *tmp = (char *) malloc(length_result);
    if (table == NULL || tmp == NULL) {
        print_error_message_allocation_problem();
        // free memory
        free(table);
        free(tmp);
        return;
    }

    // Important check before starting the method
    if (!check_Legality_of_Parameters(base, table, alph, z1, z2)) {
        // free memory
        free(table);
        free(tmp);
        return;
    }

    //Result+resultOffset is our accumulator for line mul. (0 at the beginning)
    int64_t resultOffset = 0;
    if (isNeg) {
        result[resultOffset++] = '-';
    }
    result[resultOffset] = alph[0];
    result[resultOffset + 1] = 0;

    //In tmp each row is calculated
    tmp[length_result - 1] = 0;

    //Zeros at the back, grows with each line
    size_t zeroCounter = 0;

    //max amount of chars that are being handled at the same time
    int charsHandledAtOnce = max_length_int(base) / 2;

    //loop for multiplying part after part (x) of z1 with whole z2
    const char *z1Pointer = z1 + strlen(z1);
    while (z1Pointer >= z1) {
        //Result of line is created from right to left, start with zeros
        int64_t tmpOffset = length_result - 1;
        for (size_t i = 0; i < zeroCounter; i++) {
            tmp[--tmpOffset] = alph[0];
        }
        //convert snippet of z1 to int64_t and put into x, update the z1Pointer
        size_t xLength = z1Pointer - z1 > charsHandledAtOnce ? charsHandledAtOnce : z1Pointer - z1;
        int64_t x = convert_String_to_int(base, table, z1Pointer - xLength, xLength);
        z1Pointer -= charsHandledAtOnce;

        //loop for multiplying part after part (y) of z2 with part of z2 (x)
        const char *z2Pointer = z2 + strlen(z2);
        int64_t carry = 0;
        while (z2Pointer >= z2 || carry) {
            //convert snippet of z2 to int64_t and put into y, update the z2Pointer
            int64_t y = 0;
            size_t yLength = 1;
            if (z2Pointer >= z2) {
                yLength = z2Pointer - z2 > charsHandledAtOnce ? charsHandledAtOnce : z2Pointer - z2;
                y = convert_String_to_int(base, table, z2Pointer - yLength, yLength);
                z2Pointer -= charsHandledAtOnce;
            }

            //actual calculation
            int64_t r = x * y + carry;

            //convert r to String and put it in place in tmp
            int tmp_resultLength = yLength;
            tmpOffset -= tmp_resultLength;
            if (tmpOffset < 0) {
                tmpOffset = 0;
            }
            carry = convert_int_to_String(base, alph, tmp + tmpOffset, tmp_resultLength, r);
        }

        //Update zeroCounter
        zeroCounter += xLength;

        //Add tmp to result
        _V1plus_op_any_signs(base, alph, result + resultOffset, tmp + tmpOffset, result + resultOffset);
    }

    // if result = -0, set result = 0
    if (result[0] == '-' && result[1] == alph[0]) {
        result[0] = alph[0];
        result[1] = 0;
    }

    //Free memory
    free(table);
    free(tmp);
}
