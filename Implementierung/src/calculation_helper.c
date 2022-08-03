#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "calculation_helper.h"

/**
 * Method for creating a LookUpTable for the values in the alphabet
 * and also for checking if the alphabet is even legal
 * @param base base of the alphabet
 * @param n size of table (n should be 256)
 * @param table the table where the values should be stored in
 * @param alphabet the alphabet for the Lookup-table
 * @return bool that represents if the alphabet is legal (true) or illegal (false)
 */
bool createLookUpTable(int base, size_t n, unsigned char *table, const char *alphabet) {
    //null every value in the table
    for (size_t i = 0; i < n; i++) {
        table[i] = 0;
    }
    //Adds values for alphabet
    size_t i = 1; // first value is 0 anyway -> can be skipped
    for (; i < strlen(alphabet); ++i) {
        //if value is already set or is '-', alphabet is illegal
        if (table[(unsigned char) alphabet[i]] != 0 || alphabet[i] == alphabet[0] || alphabet[i] == '-') {
            return false;
        }
        table[(unsigned char) alphabet[i]] = (unsigned char) i;
    }
    //Check if size of alphabet is not equal to base
    if ((unsigned char) i != abs(base)) {
        return false;
    }
    return true;
}

/**
 * Method for checking if two positive numbers are legal or not
 * Important: Cant be called with '-' - Prefix
 * @param table Lookup-Table for the alphabet containing their numerical values
 * @param alphabet Alphabet of both numbers (needed because of the first char)
 * @param z1 Left operand
 * @param z2 Right operand
 * @return bool that represents if both numbers are legal (true) or if at least one of them is illegal (false)
 */
bool areNumbersLegal(const unsigned char *table, const char *alphabet, const char *z1, const char *z2) {
    // Go through each value and check, if entry of table is uninitialized (== 0). That might only be the case for first letter.
    for (size_t i = 0; i < strlen(z1); ++i) {
        if (table[(unsigned char) z1[i]] == 0 && z1[i] != alphabet[0]) {
            return false;
        }
    }
    for (size_t i = 0; i < strlen(z2); ++i) {
        if (table[(unsigned char) z2[i]] == 0 && z2[i] != alphabet[0]) {
            return false;
        }
    }
    return true;
}

/**
 * Method for comparing the size of two numbers and returning a
 * char pointer array containing the pointer of the numbers in a reversed order (larger -> smaller)
 * @param table Lookup-Table for the alphabet containing their numerical values
 * @param z1 Left operand
 * @param z2 Right operand
 * @return char** that contains the larger value on index 0 and the smaller value on index 1
 */
const char **getLargerNumber(const unsigned char *table, const char *alph, const char *z1, const char *z2) {
    const char **res = malloc(sizeof(z1) + sizeof(z2));
    if (res == NULL) {
        return res;
    }
    const char *tmp1 = z1;
    const char *tmp2 = z2;
    while (*tmp1 == alph[0]) {
        tmp1++;
    }
    while (*tmp2 == alph[0]) {
        tmp2++;
    }
    // First check size other the lengths of the strings
    if (strlen(tmp1) > strlen(tmp2)) {
        res[0] = z1;
        res[1] = z2;
        return res;
    } else if (strlen(tmp2) > strlen(tmp1)) {
        res[0] = z2;
        res[1] = z1;
        return res;
    } else {
        // If both strings have the same length, they will be compared for every digit
        while (*tmp1 != 0) {
            if (table[(unsigned char) *tmp1] > table[(unsigned char) *tmp2]) {
                res[0] = z1;
                res[1] = z2;
                return res;
            } else if (table[(unsigned char) *tmp2] > table[(unsigned char) *tmp1]) {
                res[0] = z2;
                res[1] = z1;
                return res;
            }
            tmp1++;
            tmp2++;
        }
        // If both numbers are the same they will be just returned normally
        res[0] = z1;
        res[1] = z2;
        return res;
    }
}

// Method check legality of parameters and if they are all legal it returns true
// Also creates LookUp-Table as side effect
bool check_Legality_of_Parameters(int base, unsigned char *table, const char *alph, const char *z1, const char *z2) {
    // Check for Legality of alphabet and of numbers; also creates LookUp-Table
    if (!createLookUpTable(base, 256, table, alph)) {
        fprintf(stderr,
                "Alphabet is illegal: Cant contain 0-9, the null-byte, the '-'-char, or multiple occurrences of the same letter!");
        return false;
    } else if (!areNumbersLegal(table, alph, z1, z2)) {
        fprintf(stderr,
                "Numbers are illegal: Can only contain the symbols of the alphabet as well as a '-' - Prefix!");
        return false;
    }
    return true;
}

// Simple error message when unable to allocate memory
void print_error_message_allocation_problem() {
    fprintf(stderr, "Buffer for either the table or the temporary register couldn't be created!");
}
