# 18-Math

## Topic Introduction
Mathematical questions in DSA involve properties of numbers, geometry, combinatorics, and probability. Standard topics include prime verification, Greatest Common Divisor (GCD), and Modular Exponentiation.

---

## When to use
- Prime verification or decomposition.
- Range operations involving GCD/LCM.
- Efficient calculations of permutations and combinations.

---

## Time Complexities
| Algorithm | Time Complexity | Notes |
| :--- | :---: | :--- |
| **Sieve of Eratosthenes** | $O(n \log \log n)$ | Precalculates primes up to $n$ |
| **Euclidean GCD** | $O(\log(\min(a,b)))$ | Fast GCD calculation |
| **Modular Exponentiation**| $O(\log n)$ | Binary exponentiation strategy |

---

## Common Patterns
1. **Sieve of Eratosthenes**: Generating all primes in range.
2. **Binary Exponentiation**: Computing $a^b \pmod m$ recursively by splitting the exponent in half.

---

## Interview Tips
- Clarify whether integer outcomes can overflow, requiring result modulo $10^9+7$ (which is a common prime number).
- Remember GCD properties: $\gcd(a, b) \times \text{lcm}(a, b) = a \times b$.

---

## Mistakes to Avoid
- **Division by zero**: Checking indices before running modulo or division.
- **Float representation issues**: Relying on floats for precise integer equality operations.

---

## Solved Problems Checklist
- [x] Factorials of Large Numbers | **Medium**
- [ ] Count Primes | **Medium**
- [ ] Pow(x, n) | **Medium**
- [ ] Happy Number | **Easy**
