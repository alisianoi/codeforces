#!/usr/bin/env python3

import collections
import functools

class memoized:

    def __init__(self, func):
        self.func = func
        self.cache = {}

    def __call__(self, *args):

        # if args is not hashable, perform the computation
        if not isinstance(args, collections.Hashable):
            return self.func(*args)

        if args not in self.cache:
            self.cache[args] = self.func(*args)

        return self.cache[args]

    def __repr__(self):
        return self.func.__doc__

    def __get__(self, obj, objtype):
        return functools.partial(self.__call__, obj)

def xadd(a, b, mod):
    if a > mod:
        a = a % mod

    if b > mod:
        b = b % mod

    return (a + b) % mod

@memoized
def xmul(a, b, mod):
    if a > mod:
        a = a % mod

    if b > mod:
        b = b % mod

    return (a * b) % mod

@memoized
def xgcf(a, b):
    s1, s2 = 1, 0
    t1, t2 = 0, 1

    while b:
        q, r = divmod(a, b)

        a, b = b, r

        s2, s1 = s1 - q * s2, s2
        t2, t1 = t1 - q * t2, t2

    return a, s1, t1

def xdiv(a, b, mod):
    return xmul(a, xgcf(b, mod)[1], mod)

@memoized
def factorial(n, mod):
    if n == 0 or n == 1:
        return 1

    result = 1
    for i in range(n, 1, -1):
        result = xmul(result, i, mod)

    return result

@memoized
def choose_n_k(n, k, mod):
    if k > n:
        return 0

    if k == 0 or k == n:
        return 1

    result = 1
    for i in  range(0, min(k, n - k)):
        result = xdiv(xmul(result, (n - i), mod), (i + 1), mod)

    return result

# Read: compute for two, meaning compute for two islands
def compute_42(a, b, mod):
    total = 0;
    for k in range(min(a, b) + 1):
        ca = choose_n_k(a, k, mod)
        cb = choose_n_k(b, k, mod)

        total = xadd(total, xmul(xmul(ca, cb, mod), factorial(k, mod), mod), mod)

    return total

if __name__ == '__main__':
    a, b, c = list(map(int, input().split()))

    modulus = 998244353;

    total0 = compute_42(a, b, modulus);
    total1 = compute_42(a, c, modulus);
    total2 = compute_42(b, c, modulus);

    print(xmul(xmul(total0, total1, modulus), total2, modulus))
