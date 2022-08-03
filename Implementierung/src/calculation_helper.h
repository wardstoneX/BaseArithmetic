#ifndef TEAM285_CALCULATION_HELPER_H
#define TEAM285_CALCULATION_HELPER_H

#include <stdbool.h>
#include <stddef.h>

bool createLookUpTable(int base, size_t n, unsigned char *table, const char *alphabet);

const char **getLargerNumber(const unsigned char *table, const char *alph, const char *z1, const char *z2);

bool areNumbersLegal(const unsigned char *table, const char *alphabet, const char *z1, const char *z2);

bool check_Legality_of_Parameters(int base, unsigned char *table, const char *alph, const char *z1, const char *z2);

void print_error_message_allocation_problem();

#endif //TEAM285_CALCULATION_HELPER_H
