```plantext
in this line we convert the integer to fixed point value (rawBits):
this->_fixedPoint = intValue << this->_fractionalBits;
so the size of int is 4 bytes, (8bits * 4):
for example:
if integer = 5
in base 2 = 00000000 00000101
when i shift by 8 it become:
00000101 00000000 = 1280 as integer
so we shift by 8 to the left mean add 8 zero's to the right and move bits to the left, is right ?
same as * 256
so dividing by  256, or shifting by 8 to the right give me the original number (as int) = 1280 >> 8 = 5
in base 2 = 00000000 00000101
it become as origin placement before the left shift


in other hand if i have 
floatValue = 5.5
in base 2 = 00000101.10000000
multiply by 256 give me :
rawBits = 1408
but i need to round the result to get the integer part only, s right until now ?
if i want to get the float value:
i devide the fixedPoint by 256, so:
 1408 = 5.5

so this exercice consist to know how int and float numbers is stored,
and how to get a fixedPointNumber for both integers and float number using (* 256, because its 2power8, like sientifique notation 123*10power(-2), we shift bits like we control the placement of the first byte (8bits)), dont forgoting to round result from floatNumber to rawBits
or using << directly

also how to go from fixedpointnumber or rawBits to both int or float, by / 256
also not forgoting to cast the rawBits to float so the result keep the fraction part afetr divition, fron fixed o Float , this is right hhhh, too much explanation and details?
```


Fixed-Point Numbers in C++ (Exercise Explanation)

This document explains the concept of fixed-point numbers, how they are stored, and how to convert between integers, floats, and fixed-point representations using bit manipulation.
1️⃣ Converting an Integer to Fixed-Point

To convert an integer to a fixed-point raw value:

_rawBits = integer << _fractionalBits;

    _fractionalBits = 8 → we shift 8 bits to the left.

    Example: integer = 5

        Binary representation: 00000000 00000101

        Shift left 8 bits: 00000101 00000000

        Decimal value: 5 << 8 = 1280

✅ Note: Shifting left by 8 bits is exactly the same as multiplying by 256 (2^8).

To get back the original integer:

originalInt = _rawBits >> 8;  // 1280 >> 8 = 5

    Binary: 00000101 00000000 → 00000000 00000101

2️⃣ Converting a Float to Fixed-Point

To convert a floating-point number to fixed-point:

_rawBits = roundf(floatNumber * (1 << _fractionalBits));

    Example: floatNumber = 5.5

        Multiply by 256: 5.5 * 256 = 1408

        Binary representation: 00000101.10000000

            5 = integer part

            .5 = fractional part in 8-bit fractional

✅ Note: Rounding is needed because the multiplication may produce a non-integer value in binary.
3️⃣ Converting Fixed-Point Back to Integer

intNumber = _rawBits >> _fractionalBits;

    Example: _rawBits = 1280 → shift right 8 bits → 5

4️⃣ Converting Fixed-Point Back to Float

floatNumber = (float)_rawBits / (1 << _fractionalBits);

    Example: _rawBits = 1408 → divide by 256 → 5.5

✅ Tip: Casting to float is crucial so that the division preserves the fractional part.
5️⃣ Conceptual Understanding

    Fixed-point numbers are like scientific notation for binary.

        _rawBits stores the number as an integer.

        _fractionalBits determines the position of the binary "decimal point".

    Shifting left/right or multiplying/dividing by 2^_fractionalBits effectively moves this "decimal point".

    This method works for both integers and floats.

6️⃣ Summary

    Integer → Fixed-point: shift left (<<) or multiply by 2^fractionalBits.

    Float → Fixed-point: multiply by 2^fractionalBits and round to nearest integer.

    Fixed-point → Integer: shift right (>>) by fractional bits.

    Fixed-point → Float: divide by 2^fractionalBits and cast to float.

This explanation gives a step-by-step understanding of fixed-point representation, the raw bits storage, and the conversions between integer and floating-point numbers.

