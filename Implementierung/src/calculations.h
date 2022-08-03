
#ifndef TEAM285_CALCULATIONS_H
#define TEAM285_CALCULATIONS_H

#include <stdbool.h>

void print_error_message_undefined_Op(char op);

void print_error_message_minus_mismatch();

void arith_op_any_base(int base, const char *alph, const char *z1, const char *z2, char op, char *result);

void minus_op_any_base(int base, const char *alp, const char *z1, const char *z2, char *result);

void plus_op_any_base(int base, const char *alp, const char *z1, const char *z2, char *result);

void mul_op_any_base(int base, const char *alp, const char *z1, const char *z2, char *result);

#endif //TEAM285_CALCULATIONS_H
