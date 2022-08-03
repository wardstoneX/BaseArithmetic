#ifndef TEAM285_ARITHMETIC_HELPER_H
#define TEAM285_ARITHMETIC_HELPER_H

#include <stdbool.h>

void minus_op_pos_base(int base, const char *alp, const char *z1, const char *z2, char *result);

void minus_op_neg_base(int base, const char *alp, const char *z1, const char *z2, char *result);

void plus_op_neg_base(int base, const char *alp, const char *z1, const char *z2, char *result);

void plus_op_pos_base(int base, const char *alp, const char *z1, const char *z2, char *result, bool isNeg);

void mul_op_pos_base(int base, const char *alp, const char *z1, const char *z2, char *result, bool isNeg);

#endif //TEAM285_ARITHMETIC_HELPER_H
