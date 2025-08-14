# Alright, let’s go step-by-step and build a clear mental model of your fixed-point system with 8 fractional bits.
I’ll explain:

    How the number is stored (int vs float)

    Why shifting is done

    *What happens for +, -, , and /

    How we go from 8 fractional bits to 16 fractional bits

    Bit-by-bit illustrations

1. Fixed-point storage format

You have:

int _fixedPoint;        // raw value (4 bytes = 32 bits)
static const int _fractionalBits = 8; // 8 bits for fractional part

📦 Storage layout (integer with 8 fractional bits):

| integer bits ... | fractional bits |
  <---- 24 bits ---><------ 8 bits --->

    Left part = integer value (can be negative in two’s complement)

    Right part = fractional value

Example: storing the integer 5

decimal:   5
binary:    00000000    00000000    00000101   .   00000000  (fraction is all zeros)
storage:   00000000    00000000    00000101       00000000
            \_________ integer 5 _________/  \__ fractional=0 __/

We shift left by 8 bits so the fractional bits (last 8 bits) are empty.
2. Why shifting is done

If _fractionalBits = 8, then the value in _fixedPoint is:

stored_value = real_value × 2^8

So:

    For integer → fixed-point:

this->_fixedPoint = intValue << 8; // multiply by 256

For float → fixed-point:

    this->_fixedPoint = roundf(floatValue * 256);

We multiply by 256 because each fractional bit represents 1/256.
Example: float 5.75

5.75 × 256 = 1472
binary: 00000000 00000101 . 11000000  (5.75 in fixed-point)
storage: 00000000 00000101 11000000

    0.75 × 256 = 192 → fractional bits = 11000000.

3. Operations
➕ Addition and ➖ Subtraction

If two numbers have the same scaling factor (2^8), you can add or subtract directly:

(a_raw + b_raw) → still scaled by 256

Example:

1.5  →  384   (1.5 × 256)
2.25 →  576   (2.25 × 256)
Sum  →  960   = 3.75 × 256

✖ Multiplication

Here’s the tricky part:
If each operand is scaled by 256, then multiplying them doubles the scaling to 256×256 = 65536 (2^16 fractional bits).

Example:

a = 1.5  →  384
b = 2.25 →  576

raw_mul = 384 × 576 = 221184   (scaled by 65536)

Now you have 16 fractional bits, but you want 8 fractional bits, so:

result_raw = raw_mul >> 8; // divide by 256

This discards the extra scaling factor.
➗ Division

When dividing, it’s the opposite:
If both are scaled by 256, doing a_raw / b_raw would remove the scale entirely.

So you first upscale the numerator:

result_raw = (a_raw << 8) / b_raw;

4. Bit visualizations

Let’s do 1.5 × 2.25 in binary with 8 fractional bits.
Step 1 — Store both values

1.5  = 00000001.10000000 (raw: 00000000 00000001 10000000)
2.25 = 00000010.01000000 (raw: 00000000 00000010 01000000)

Step 2 — Multiply raw values

00000000 00000001 10000000
× 00000000 00000010 01000000
--------------------------------
= 00000000 11011000 00000000 00000000  (scaled by 2^16)

Step 3 — Adjust scaling

Right shift by 8 bits:

00000000 11011000 00000000
= 3.375 in fixed point

5. Summary table
Operation	What happens with scaling (2^8)	Code fix
+ / -	scaling stays same	a_raw ± b_raw
*	scaling becomes 2^16	(a_raw * b_raw) >> 8
/	scaling lost without adjust	(a_raw << 8) / b_raw



# 1. What is ϵ such as 1 + ϵ > 1?

In math and floating/fixed-point arithmetic, ϵ (epsilon) means the smallest representable step you can add to a number before it changes.

In your fixed-point implementation with _fractionalBits = 8:

    One integer step in _fixedPoint corresponds to:
    epsilon=128=1256≈0.00390625
    epsilon=281​=2561​≈0.00390625

    So ++ or -- changes the number by exactly epsilon in floating-point terms.

Example:

a = 1.0         -> _fixedPoint = 256
++a             -> _fixedPoint = 257
a.toFloat()     -> 1.00390625  (1 + ε)

That’s why your increment/decrement operators are correct:

this->_fixedPoint++;

because increasing _fixedPoint by 1 increases the float value by exactly epsilon.


# 2. Prefix vs Postfix increment/decrement
Key difference:

    Prefix (++x) → more efficient, no copy, changes the object immediately.

    Postfix (x++) → less efficient, requires a copy to preserve the original value to return.

That’s why in performance-critical code, prefix is preferred unless you specifically need postfix semantics