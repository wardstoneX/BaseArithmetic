G-adic Arithmetic Operations
This project implements arithmetic operations on g-adic numbers, where g can be any positive integer. Two distinct approaches have been implemented for performing arithmetic operations:

Direct Calculation (Main Implementation):

Arithmetic operations are directly performed on g-adic numbers without conversion.
Simple algorithms based on handwritten addition, subtraction, and multiplication are employed.
Offers good performance for addition and subtraction.
Hybrid Implementation (Reference Implementation):

Numbers are partially converted before calculations for improved efficiency.
Utilizes a hybrid methodology, combining partial conversion and subsequent operation calculations.
Provides efficient multiplication.

Implementation Details
Direct Calculation (Main Implementation)
Addition and Subtraction: Algorithms leverage handwritten methods for base g.
Multiplication: Uses a parallel pointer approach for efficient multiplication.
Hybrid Implementation (Reference Implementation)
Conversion to Decimal System: Converts operands to decimals before calculations.
Arithmetic Operations: Leverages the processor for decimal calculations.

Performance Analysis
Addition and Subtraction
Both implementations exhibit linear runtime, with the main implementation being approximately 0.5 times faster.
Multiplication
Both implementations are in quadratic runtime classes.
The main implementation has a growth rate about three times faster than the reference implementation.
Conclusion
Both implementations provide good results, each excelling in specific operations.
For addition and subtraction, the main implementation is recommended.
If efficient multiplication is crucial, the reference implementation is preferred.
Authors
Jonas Nögel
Selim Mert Kas¸tan
Maxim Balajan
