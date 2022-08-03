#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "calculations.h"
#include "calculation_helper.h"
#include "arithmetic_helper.h"

/**
 * Method for executing the '-' - Operation for positive numbers with positive bases
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 */
void minus_op_pos_base(int base, const char *alph, const char *z1, const char *z2, char *result) {
    //Create Lookup-table in the beginning in order to make calculations easier
    //Also creates tmp for tmp save in which the result is stored in reverse order
    unsigned char *table = (unsigned char *) malloc(256);
    char *tmp = (char *) malloc(strlen(z1) > strlen(z2) ? strlen(z1) + 2 : strlen(z2) + 2);
    if (table == NULL || tmp == NULL) {
        print_error_message_allocation_problem();
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

    //IMPORTANT: Memory is allocated, so it has to be freed afterwards
    const char **largerNumber = getLargerNumber(table, alph, z1, z2);
    if (largerNumber == NULL) {
        print_error_message_allocation_problem();
        // free memory
        free(table);
        free(tmp);
        return;
    }

    bool isNeg = largerNumber[0] != z1;

    z1 = largerNumber[0];
    z2 = largerNumber[1];

    const char *z1Pointer = z1 + strlen(z1) - 1;
    const char *z2Pointer = z2 + strlen(z2) - 1;

    //calculate number in reverse order in tmp
    int64_t tmpOffset = 0;
    char carry = 0;
    while (z1Pointer >= z1 || z2Pointer >= z2 || carry) {
        int64_t x = 0;
        int64_t y = 0;
        if (z1Pointer >= z1) {
            x = (int64_t) table[(unsigned char) *z1Pointer];
            z1Pointer--;
        }
        if (z2Pointer >= z2) {
            y = (int64_t) table[(unsigned char) *z2Pointer];
            z2Pointer--;
        }
        int64_t r = x - y + carry;

        carry = r < 0 ? -1 : 0;

        r = r < 0 ? base + r : r;

        tmp[tmpOffset++] = alph[r];
    }

    //IMPORTANT: Don't forget null-byte for string
    tmp[tmpOffset--] = 0;

    //reverse string of tmp and store in result
    int64_t resultOffset = 0;
    if (isNeg) {
        result[resultOffset++] = '-';
    }
    //bool for removing leading 0s
    bool isLeading = true;
    while (tmpOffset >= 0) {
        if (isLeading && tmp[tmpOffset] == alph[0]) {
            tmpOffset--;
            continue;
        }
        isLeading = false;
        result[resultOffset++] = tmp[tmpOffset--];
    }
    //if we haven't written anything, write 0
    if (resultOffset == 0) {
        result[resultOffset++] = alph[0];
    }
    //IMPORTANT: Again, don't forget null-byte for string
    result[resultOffset] = 0;

    //Free memory that was allocated
    free(table);
    free(tmp);
    free(largerNumber);
}

/**
 * Method for executing the '-' - Operation for positive numbers with negative bases
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 */
void minus_op_neg_base(int base, const char *alph, const char *z1, const char *z2, char *result) {
    // Create Lookup-table in the beginning in order to make calculations easier
    // Also creates tmp for tmp save in which the result is stored in reverse order
    unsigned char *table = (unsigned char *) malloc(256);
    char *tmp = (char *) malloc(strlen(z1) > strlen(z2) ? strlen(z1) + 2 : strlen(z2) + 2);
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

    const char *z1Pointer = z1 + strlen(z1) - 1;
    const char *z2Pointer = z2 + strlen(z2) - 1;

    // calculate number in reverse order in tmp
    int64_t tmpOffset = 0;
    char carry = 0;
    while (z1Pointer >= z1 || z2Pointer >= z2 || carry) {
        int64_t x = 0;
        int64_t y = 0;
        if (z1Pointer >= z1) {
            x = (int64_t) table[(unsigned char) *z1Pointer];
            z1Pointer--;
        }
        if (z2Pointer >= z2) {
            y = (int64_t) table[(unsigned char) *z2Pointer];
            z2Pointer--;
        }
        int64_t r = x - y + carry;

        carry = r < 0 ? 1 : 0;

        r = r < 0 ? abs(base) + r : r;

        tmp[tmpOffset++] = alph[r];
    }

    // IMPORTANT: Don't forget null-byte for string
    tmp[tmpOffset--] = 0;

    // reverse string of tmp and store in result
    int64_t resultOffset = 0;
    // bool for removing leading 0s
    bool isLeading = true;
    while (tmpOffset >= 0) {
        if (isLeading && tmp[tmpOffset] == alph[0]) {
            tmpOffset--;
            continue;
        }
        isLeading = false;
        result[resultOffset++] = tmp[tmpOffset--];
    }
    if (resultOffset == 0) {
        result[resultOffset++] = alph[0];
    }
    // IMPORTANT: Again, don't forget null-byte for string
    result[resultOffset] = 0;

    // Free memory that was allocated
    free(table);
    free(tmp);
}

/**
 * Method for executing the '+' - Operation for positive numbers with negative bases
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 */
void plus_op_neg_base(int base, const char *alph, const char *z1, const char *z2, char *result) {

    //Create Lookup-table in the beginning in order to make calculations easier
    //Also creates tmp for tmp save in which the result is stored in reverse order
    unsigned char *table = (unsigned char *) malloc(256);
    char *tmp = (char *) malloc(strlen(z1) > strlen(z2) ? strlen(z1) + 3 : strlen(z2) + 3);
    if (table == NULL || tmp == NULL) {
        print_error_message_allocation_problem();
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

    const char *z1Pointer = z1 + strlen(z1) - 1;
    const char *z2Pointer = z2 + strlen(z2) - 1;

    //calculate number in reverse order in tmp
    int64_t tmpOffset = 0;
    char carry = 0;
    while (z1Pointer >= z1 || z2Pointer >= z2 || carry) {
        int64_t x = 0;
        int64_t y = 0;
        if (z1Pointer >= z1) {
            x = (int64_t) table[(unsigned char) *z1Pointer];
            z1Pointer--;
        }
        if (z2Pointer >= z2) {
            y = (int64_t) table[(unsigned char) *z2Pointer];
            z2Pointer--;
        }
        int64_t r = x + y + carry;
        if (r >= abs(base)) {
            carry = -1;
        } else if (r >= 0) {
            carry = 0;
        } else {
            carry = 1;
            //r has to be modified so that it creates the wrap around (if base=-10 then r=-1 should wrap to the symbol 9)
            r = abs(base) + r;
        }

        tmp[tmpOffset++] = alph[labs(r % base)];
    }

    //IMPORTANT: Don't forget null-byte for string
    tmp[tmpOffset--] = 0;

    //reverse string of tmp and store in result
    int64_t resultOffset = 0;
    // bool for removing leading 0s
    bool isLeading = true;
    while (tmpOffset >= 0) {
        if (isLeading && tmp[tmpOffset] == alph[0]) {
            tmpOffset--;
            continue;
        }
        isLeading = false;
        result[resultOffset++] = tmp[tmpOffset--];
    }
    if (resultOffset == 0) {
        result[resultOffset++] = alph[0];
    }
    //IMPORTANT: Again, don't forget null-byte for string
    result[resultOffset] = 0;

    //Free memory that was allocated
    free(table);
    free(tmp);
}

/**
 * Method for executing the '+' - Operation for positive numbers with positive bases
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 */
void plus_op_pos_base(int base, const char *alph, const char *z1, const char *z2, char *result, bool isNeg) {

    //Create Lookup-table in the beginning in order to make calculations easier
    //Also creates tmp for tmp save in which the result is stored in reverse order
    unsigned char *table = (unsigned char *) malloc(256);
    char *tmp = (char *) malloc(strlen(z1) > strlen(z2) ? strlen(z1) + 2 : strlen(z2) + 2);
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

    const char *z1Pointer = z1 + strlen(z1) - 1;
    const char *z2Pointer = z2 + strlen(z2) - 1;

    //calculate number in reverse order in tmp
    int64_t tmpOffset = 0;
    char carry = 0;
    while (z1Pointer >= z1 || z2Pointer >= z2 || carry) {
        int64_t x = 0;
        int64_t y = 0;
        if (z1Pointer >= z1) {
            x = (int64_t) table[(unsigned char) *z1Pointer];
            z1Pointer--;
        }
        if (z2Pointer >= z2) {
            y = (int64_t) table[(unsigned char) *z2Pointer];
            z2Pointer--;
        }
        int64_t r = x + y + carry;

        carry = r >= base ? 1 : 0;

        tmp[tmpOffset++] = alph[labs(r % base)];
    }

    //IMPORTANT: Don't forget null-byte for string
    tmp[tmpOffset--] = 0;

    //reverse string of tmp and store in result
    int64_t resultOffset = 0;
    if (isNeg) {
        result[resultOffset++] = '-';
    }
    //bool for removing leading 0s
    bool isLeading = true;
    while (tmpOffset >= 0) {
        if (isLeading && tmp[tmpOffset] == alph[0]) {
            tmpOffset--;
            continue;
        }
        isLeading = false;
        result[resultOffset++] = tmp[tmpOffset--];
    }
    //IMPORTANT: Again, don't forget null-byte for string
    result[resultOffset] = 0;

    //Free memory that was allocated
    free(table);
    free(tmp);
}

/**
 * Method for executing the '*' - Operation for positive numbers with any bases
 * @param base The base of the given numbers
 * @param alph The alphabet that the given numbers use
 * @param z1 Left operand
 * @param z2 Right operand
 * @param result Result Buffer for the result of the operation
 */
void mul_op_pos_base(int base, const char *alph, const char *z1, const char *z2, char *result, bool isNeg) {

    //Create Lookup-table in the beginning in order to make calculations easier
    //Also creates tmp for tmp save
    //rev later stores tmp in reverse order and also adds 0s
    unsigned char *table = (unsigned char *) malloc(256);
    char *tmp = (char *) malloc(strlen(z1) + strlen(z2) + 3);
    char *rev = (char *) malloc(strlen(z1) + strlen(z2) + 3);

    if (table == NULL || tmp == NULL || rev == NULL) {
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

    const char *z1Pointer = z1 + strlen(z1) - 1;
    const char *z2Pointer = z2 + strlen(z2) - 1;
    //Tmp is our accumulator for our calculations
    result[0] = alph[0];
    result[1] = 0;

    size_t zeroCounter = 0;
    while (z1Pointer >= z1) {
        int64_t tmpOffset = 0;
        int64_t carry = 0;
        int64_t x = (int64_t) table[(unsigned char) *z1Pointer];
        //While loop for calculating the multiplication between last char in z1 and number z2
        while (z2Pointer >= z2 || carry) {
            int64_t y = 0;
            if (z2Pointer >= z2) {
                y = (int64_t) table[(unsigned char) *z2Pointer];
                z2Pointer--;
            }
            int64_t r = x * y + carry;
            //Carry can be negative and because of that r can be negative as well
            //If negative, carry has to be +1 because negative r can only occur with neg. bases
            //and when lending -1 from neg. base your calculate - -1 = +1
            carry = r < 0 ? 1 : r / base;
            //Result has to be modified accordingly
            r = r < 0 ? abs(base) + r : labs(r % base);

            tmp[tmpOffset++] = alph[r];
        }

        //IMPORTANT: Don't forget null-byte for string
        tmp[tmpOffset--] = 0;

        int64_t resOffset = 0;

        //bool for removing leading 0s
        bool isLeading = true;
        while (tmpOffset >= 0) {
            if (isLeading && tmp[tmpOffset] == alph[0]) {
                tmpOffset--;
                continue;
            }
            isLeading = false;
            rev[resOffset++] = tmp[tmpOffset--];
        }
        //Adding zeros
        for (size_t i = 0; i < zeroCounter; i++) {
            rev[resOffset++] = alph[0];
        }
        //IMPORTANT: Dont forget null-byte
        rev[resOffset] = 0;

        //ALSO IMPORTANT: Update zeroCounter
        zeroCounter++;

        //Add value in rev to result
        if (base < 0) {
            plus_op_neg_base(base, alph, rev, result, result);
        } else {
            plus_op_pos_base(base, alph, rev, result, result, false);
        }
        //update
        z1Pointer--;
        z2Pointer = z2 + strlen(z2) - 1;
    }

    if (isNeg) {
        //Add value in rev to result
        char zero[2];
        zero[0] = alph[0];
        zero[1] = 0;
        plus_op_pos_base(base, alph, zero, result, result, true);
    }

    //Free memory
    free(table);
    free(tmp);
    free(rev);
}
