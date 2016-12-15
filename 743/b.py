n, k = list(map(int, input().split()))

while n:
    mid = (2 ** n) // 2

    if k == mid:
        print(n)
        break

    if k > mid:
        k -= mid

    n -= 1

