# 17-Bit-Manipulation

## Topic Introduction
**Bit Manipulation** involves performing operations on binary representations of integers using bitwise operators (`&`, `|`, `^`, `~`, `<<`, `>>`). Bitwise operations are extremely fast because they are directly supported by processors.

---

## When to use
- When space optimization is crucial (storing states as bitmasks).
- Checking properties like parity, powers of two, or finding missing numbers.
- Fast multiplication or division by powers of two.

---

## Time Complexities
| Operation | Time Complexity | Notes |
| :--- | :---: | :--- |
| **Bitwise AND/OR/XOR** | $O(1)$ | Single CPU cycle operation |
| **Bit Shift** | $O(1)$ | Direct shift register operation |

---

## Common Patterns
1. **XOR Cancellation**: $x \oplus x = 0$ (e.g. Single Number).
2. **Power of Two check**: `(n & (n - 1)) == 0`.
3. **Get/Set/Clear Bit**:
   - Get: `(n & (1 << i)) != 0`
   - Set: `n | (1 << i)`
   - Clear: `n & ~(1 << i)`

---

## Interview Tips
- Understand the properties of **XOR** operator thoroughly (commutative, associative, identity element).
- Be mindful of operator precedence: bitwise operators have lower precedence than arithmetic operators in C++ and Python. Always use parenthesization: `if ((val & 1) == 0)`.

---

## Mistakes to Avoid
- **Integer overflow**: Shifting beyond register boundaries (e.g. shifting `1` by 32 positions in a standard 32-bit signed int). Use `1ULL << i` in C++.

---

## Solved Problems Checklist
- [ ] Single Number | **Easy**
- [ ] Number of 1 Bits | **Easy**
- [ ] Counting Bits | **Easy**
