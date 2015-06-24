import sys

s, k = input(), int(input())
n = len(s)

if n % k:
    print("NO")
    sys.exit()

for i in range(0, n, n // k):
    j = i + n // k - 1
    while i < j and s[i] == s[j]:
        i, j = i + 1, j - 1
    if i < j:
        print("NO")
        sys.exit()

print("YES")
