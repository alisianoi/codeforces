#!/usr/bin/env python

import math

n = int(input())

x, divs = n, {}

for i in range(2, math.ceil(math.sqrt(n))):
    if n % i == 0:
        t = 0

        while n % i == 0:
            n /= i
            t += 1

        divs[i] = {t}

print(f"{x} is divisible:")
for key, val in divs.items():
    print(f"by {key} exactly {val} times")
