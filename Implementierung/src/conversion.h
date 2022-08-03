#ifndef TEAM285_CONVERSION_H
#define TEAM285_CONVERSION_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void _V1arithmetic_op_any_base(int base, const char *alph, const char *z1, const char *z2, char op, char *result);

void _V1plus_op_any_signs(int base, const char *alph, const char *z1, const char *z2, char *result);

void _V1minus_op_any_signs(int base, const char *alph, const char *z1, const char *z2, char *result);

void _V1mul_op_any_signs(int base, const char *alph, const char *z1, const char *z2, char *result);

void _V1plus_op_any_base(int base, const char *alph, const char *z1, const char *z2, char *result, bool isNeg);

void _V1minus_op_any_base(int base, const char *alph, const char *z1, const char *z2, char *result);

void _V1mul_op_any_base(int base, const char *alph, const char *z1, const char *z2, char *result, bool isNeg);

//helper

int max_length_int(int base);

int64_t convert_String_to_int(int base, unsigned char *table, const char *num, int numLength);

int64_t convert_int_to_String(int base, const char *alph, char *num, int numLength, int64_t result);

#endif //TEAM285_CONVERSION_H
