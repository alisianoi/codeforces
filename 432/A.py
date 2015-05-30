n, k = [int(i) for i in input().split()]
ns = [int(i) for i in input().split() if int(i) <= 5 - k]
print(len(ns) // 3)
