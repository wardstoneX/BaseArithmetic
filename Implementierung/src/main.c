#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "calculations.h"
#include "conversion.h"

const char *usage_msg =
        "\n"
        "------------------------------------------------------------------------------------------------------\n"
        "Usage: %s [options] z1 z2   Performs \'+\', \'-\' or \'*\'-operation on the given numbers with any base.\n"
        "      ------------------------------------------------------------------------------------------\n"
        "Required arguments:\n"
        "  z1      [Positional] The first operand.\n"
        "  z2      [Positional] The second operand.\n"
        "      ------------------------------------------------------------------------------------------\n"
        "Optional arguments:\n"
        "  -o X    Operation to perform. One of the operands {\'+\', \'-\' or \'*\'} (default: X = \'+\').\n"
        "  -b X    The base of all values (default: X = 10).\n"
        "  -a X    Alphabet that is used (default for base <= 16: X = \"0,1,2,...,E,F)\".\n"
        "  -n X    For positive bases: Mask defining negative numbers (default: X = 0):\n"
        "          - X = 0: Both operands are positive.        - X = 2: Only second operand is negative.\n"
        "          - X = 1: Only first operand is negative.    - X = 3: Both operands are negative.\n"
        "  -V X    The implementation to run (default: X = 0).\n"
        "          - X = 0: Main implementation (no conversion to decimal numbers).\n"
        "          - X = 1: Reference implementation: For calculation, numbers are converted to decimal system\n"
        "                   by dividing number gradually into small pieces.\n"
        "  -B [X]  If set, measure the runtime of X repetitions (default: X = 1).\n"
        "  --help or -h    Show help message (this text) and exit\n"
        "------------------------------------------------------------------------------------------------------\n"
        "\n";

const char *help_msg =
        "\n"
        "%s"
        "\n"
        "For more information, use\n"
        "%s --help    or\n"
        "%s -h\n"
        "\n";

void print_usage(const char *progname) {
    fprintf(stderr, usage_msg, progname);
}

void print_help(char *individual_help_msg, const char *progname) {
    fprintf(stderr, help_msg, individual_help_msg, progname, progname);
}

int main(int argc, char **argv) {

    const char *progname = argv[0];

    // input parameter for the operation to be calculated
    int base = 10;
    char *alph;
    const char *z1;
    const char *z2;
    char op = '+';

    // parameter for the main program
    int mode = 0; // which implementation is run? 0 for main
    int B = 0; // measure runtime? > 0 if yes, then number of repetitions
    int alph_init = 0; // helper, 1 if alphabet has been initialized, 0 if not
    int negative_mask = 0; // helper, counts how many numbers were given via -n flag

    // Definition for --help
    static const struct option long_option[] =
            {
                    {"help", no_argument, 0, 'h'},
                    {0}
            };

    // getopt: parsing through arguments given by the user
    int opt;
    int option_index = 0;
    while ((opt = getopt_long(argc, argv, "V:B::b:a:o:hn:", long_option, &option_index)) != -1) {
        switch (opt) {
            case ('V'): // Which implementation should be run?
                if (optarg[0] == '0' && optarg[1] == 0) {
                    mode = 0;
                } else if (optarg[0] == '1' && optarg[1] == 0) {
                    mode = 1;
                } else { // Implementation cannot be resolved
                    print_help(
                            "Invalid argument for -V. Has to be either 0 (main implementation) or 1 (reference implementation)\n",
                            progname);
                    return 0;
                }
                break;
            case ('B'): // Landed here -> measure runtime. Run how often?
                if (optarg == NULL) { // No argument -> 1 time
                    B = 1;
                } else { // n times, but n > 0
                    B = atoi(optarg);
                    if (B <= 0) {
                        print_help("Invalid argument for -B. If set, needs to be larger or equal to 1.\n", progname);
                        return 0;
                    }
                }
                break;
            case ('b'): // What is specified base? (|base| > 1!!)
                base = atoi(optarg);
                if (abs(base) <= 1 || abs(base) >= 255) {
                    print_help(
                            "Invalid argument for -b. Base needs to be a a number between [-254, -2] or [2, 254] .\n",
                            progname);
                    return 0;
                }
                break;
            case ('a'): // Definition of  the alphabet
                alph = optarg;
                alph_init = 1;
                break;
            case ('o'): // Definition of the operand
                op = *optarg;
                if ((op != '+' && op != '-' && op != '*') || optarg[1] != 0) {
                    print_help("Invalid argument for -o (can only be \'+\', \'-\' or \'*\').\n", progname);
                    return 0;
                }
                break;
            case ('n'): // negative number
                negative_mask = atoi(optarg);
                if (negative_mask < 0 || negative_mask > 3) {
                    print_help("Value for -n is not defined.", progname);
                    return 0;
                }
                break;
            case ('h'): // print guide (also land here with --help)
                print_usage(progname);
                return 0;
            default:
                fprintf(stderr, "%c is no argument, but it is tried to continue.\n", opt);
                break;
        }
    }

    // Check if -n is set although the base is <0
    if (base < 0 && negative_mask > 0) {
        print_help("Numbers can not have \'-\' if base is negative.\n", progname);
        return 0;
    }
    // get the positive operands (positional arguments)
    if (optind >= argc - 1) {
        print_help("Less then two operands were found.\n", progname);
        return 0;
    }
    // if defined, add '-' to first operand
    char *newZ1;
    char *newZ2;
    if (negative_mask == 1 || negative_mask == 3) {
        newZ1 = malloc(strlen(argv[optind]) + 2);
        strcpy(newZ1, "-");
        strcat(newZ1, argv[optind]);
        newZ1[strlen(argv[optind]) + 1] = 0;
        z1 = newZ1;
    } else {
        z1 = argv[optind];
    }
    // if defined, add '-' to second operand
    if (negative_mask == 2 || negative_mask == 3) {
        newZ2 = malloc(strlen(argv[optind+1]) + 2);
        strcpy(newZ2, "-");
        strcat(newZ2, argv[optind+1]);
        newZ2[strlen(argv[optind+1]) + 1] = 0;
        z2 = newZ2;
    } else {
        z2 = argv[optind+1];
    }

    // allocate a buffer for the result;
    char *result;
    if (op == '*') {
        result = malloc(strlen(z1) + strlen(z2) + 1);
    } else {
        result = malloc((strlen(z1) > strlen(z2) ? strlen(z1) : strlen(z2)) + 2);
    }
    *result = 0;


    // Default alphabet initialization
    // Has to be made so complicated because it won't work otherwise with Compiler flags O1 and onwards
    if (!alph_init) {
        if (abs(base) <= 16) {
            alph = malloc(17);
            if (alph == NULL) {
                fprintf(stderr, "Buffer for the alphabet couldn't be created!");
                return 0;
            }
            char alphTemp[17];
            strcpy(alphTemp, "0123456789ABCDEF");
            alphTemp[abs(base)] = 0;
            strcpy(alph, alphTemp);
        } else {
            print_help("For a base < (-16) or > 16, the alphabet must explicitly be defined.\n", progname);
            return 0;
        }
    }
    clock_t start = 0;
    clock_t end = 0;
    if (B > 0) {
        start = clock(); // calculations start -> take time
    }
    // if B was specified, run implementation n times, 1 time else
    for (int i = (B > 0 ? B : 1); i > 0; i--) {
        if (mode == 0) // if mode == 0, call main implementation
        {
            arith_op_any_base(base, alph, z1, z2, op, result);
        } else {
            _V1arithmetic_op_any_base(base, alph, z1, z2, op, result);
        }
    }
    if (B > 0) {
        end = clock(); // calculations ended -> take time
    }

    // Frees alphabet if its being created
    if (!alph_init) {
        free(alph);
    }

    if (*result == 0) {
        free(result);
        return 0;
    }

    // print the result
    printf("Result: %s %c %s = %s\n", z1, op, z2, result);

    // if the runtime was to be measured, the time is printed
    if (B > 0) {
        double duration = (double) (end - start) / CLOCKS_PER_SEC;
        printf("The runtime for %i repetition/s was %f seconds.\n", B, duration);
    }

    free(result);

    return 0;
}
