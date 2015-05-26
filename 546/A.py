k, n, w = map(int, input().split())
total = sum((i+1)*k for i in range(w))
to_borrow = total - n if total > n else 0
print(to_borrow)
