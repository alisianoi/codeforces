n, n1, n2 = list(map(int, input().split()))

ns = list(map(int, input().split()))

ns = sorted(ns)

t1, t2 = 0, 0

if n2 > n1:
    n1, n2 = n2, n1

for i in ns[n - n1 - n2:n - n2]:
    t1 += i
for i in ns[n - n2:]:
    t2 += i

print(t1 / n1 + t2 / n2)
