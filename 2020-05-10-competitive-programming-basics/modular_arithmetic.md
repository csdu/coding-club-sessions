# Modular Arithmetic


(_a_ +|-|* _b_) % _m_ = (_a_ % _m_ + _b_ % _m_) % _m_

Something extra for / (division).

Mostly in programming contests, _MOD_ = _10^9 + 7_ (_1000000007_), which is the smallest 10 digit prime number.


### Modular Inverse (/)

(1 / _a_) mod _M_; For this, gcd(_a_, _M_) = 1 is a mandatory condition, both _a_ and _M_ must be co primes;

Fermat's Little Theorem (Primes as MOD)

_a_^(-1) mod _M_ = _a_^(_M_ - 2) mod _M_ (_M_ is a prime here)

_a_ mod _M_ = _a_^_M_ mod _M_  
_a_^0 mod _M_ = _a_ ^ (_M_ - 1) mod _M_

-1 % 3 = 2

(_a_ % _m_ - _b_ % _m_ + _m_) % _m_

(5 mod 4 - 3 mod 4 + 3) mod 3 = 1 (negative image is -2)

-_x_ % _m_ = (-_x_ + _m_) % _m_

0 <= |_image_| <= _m_ - 1



_c(n, k) = c(n - 1, k) + c(n - 1, k - 1)_  
Dynamic Programming Approach

```cpp
int c[n][n];

// c[0][i] = 0; for all i
// c[i][0] = 1; for all i

// O(n^2)
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
}
```

We also know that  
_c(n, k) = n! / ((k!).(n - k)!)_

```
fact[n], inv[n]
fact[0] = fact[1] = 1
inv[0] = inv[1] = 1
for all i:
    fact[i] = fact[i - 1] * i
    inv[i] = inverse(fact[i])
// O(n.log(m)), log(m) factor because of computing modular inverse
// It takes O(log(m)) time to exponentiate fact[i] to (m - 2)
// using binary exponentiation (square and multiply technique)
```

_c(n, k) = fact[n] * inv[k] % m * inv[n - k] % m;_
